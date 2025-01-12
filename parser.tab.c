/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <math.h>
    #include "symbolTable.h"
    #include "quadruplet.h"
    #include "pile.h"
    #include  <ctype.h>


    //declarations 

    typedef struct {
    int baseType;      // ENTIER, FLOTTANT, STRING, etc.
    bool isArray;      // Whether it's an array
    bool isConst;      // Whether it's a constant
    int arraySize;     // Size if it's an array
    char* structName;  // Name if it's a struct
} TypeInfo;
    TableSymbole *TS;
    qTable *TQ;
    qPile *P;

    qNoeud* quad;
    Symbole* node;

    int sauvLabel;
    int sauvDebut;
    int sauvFin;

    int qC = 0;

    extern int colnum ;
    extern int lignenum ;

    extern FILE *yyin;
    int yylex();
    void yyerror(const char *s);
    int line = 1;        // Numéro de ligne courant
    int linecol = 0;         // Numéro de colonne courant
    char *yyin_filename = NULL;
    int sauv = 0;
    int sauvline = 1;

    #define TYPE_ENTIER "ENTIER"
    #define TYPE_FLOTTANT "FLOTTANT"
    #define TYPE_CHAR "CHAR"
    #define TYPE_STRING "STRING"
    #define TYPE_BOOLEAN "BOOLEAN"

// Modified type checking function to work with your symbol table
bool areTypesCompatible(const char* type1, const char* type2) {
    if (strcmp(type1, type2) == 0) {
        return true;
    }
    
    // Allow implicit conversion from int to float
    if (strcmp(type1, TYPE_FLOTTANT) == 0 && strcmp(type2, TYPE_ENTIER) == 0) {
        return true;
    }
    
    return false;
}

// Modified function to check if an identifier is declared
bool isDeclared(const char* id) {
    Symbole* found;
    return rechercherSymbole(TS, id, &found);
}

// Function to get type of an identifier
char* getIdentifierType(const char* id) {
    Symbole* found;
    if (rechercherSymbole(TS, id, &found)) {
        return found->type;
    }
    return NULL;
}

// Function to determine if a literal is valid for a given type
bool isValidLiteralForType(const char* literal, const char* type) {
    if (strcmp(type, TYPE_ENTIER) == 0) {
        // Check if string contains only digits
        for (int i = 0; literal[i] != '\0'; i++) {
            if (!isdigit(literal[i])) return false;
        }
        return true;
    }
    else if (strcmp(type, TYPE_FLOTTANT) == 0) {
        // Check if string is a valid float
        char* endptr;
        strtof(literal, &endptr);
        return *endptr == '\0';
    }
    // Add more type checks as needed
    return false;
}
TypeInfo currentType; 
    char currentFunction[256]; 
    bool inLoop = false; 
    int loopNestingLevel = 0;
void semanticError(const char* message, int line) { 
    fprintf(stderr, "Semantic error at line %d: %s\n", line, message); 
    exit(1);
}

#line 180 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DEBUT = 3,                      /* DEBUT  */
  YYSYMBOL_FIN = 4,                        /* FIN  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_FOR = 6,                        /* FOR  */
  YYSYMBOL_PRINT = 7,                      /* PRINT  */
  YYSYMBOL_INPUT = 8,                      /* INPUT  */
  YYSYMBOL_FONCTION = 9,                   /* FONCTION  */
  YYSYMBOL_VIDE = 10,                      /* VIDE  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_COMMENT = 12,                   /* COMMENT  */
  YYSYMBOL_COMMENT_PLUS = 13,              /* COMMENT_PLUS  */
  YYSYMBOL_OR = 14,                        /* OR  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_NOT = 16,                       /* NOT  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_ELIF = 19,                      /* ELIF  */
  YYSYMBOL_DEB_CORPS = 20,                 /* DEB_CORPS  */
  YYSYMBOL_FIN_CORPS = 21,                 /* FIN_CORPS  */
  YYSYMBOL_TRUE = 22,                      /* TRUE  */
  YYSYMBOL_FALSE = 23,                     /* FALSE  */
  YYSYMBOL_PAR_OUV = 24,                   /* PAR_OUV  */
  YYSYMBOL_PAR_FERM = 25,                  /* PAR_FERM  */
  YYSYMBOL_CARACTERE = 26,                 /* CARACTERE  */
  YYSYMBOL_CHAINE = 27,                    /* CHAINE  */
  YYSYMBOL_INT = 28,                       /* INT  */
  YYSYMBOL_FLOAT = 29,                     /* FLOAT  */
  YYSYMBOL_DEB_TABLEAU = 30,               /* DEB_TABLEAU  */
  YYSYMBOL_FIN_TABLEAU = 31,               /* FIN_TABLEAU  */
  YYSYMBOL_TABLE = 32,                     /* TABLE  */
  YYSYMBOL_ENREGISTREMENT = 33,            /* ENREGISTREMENT  */
  YYSYMBOL_POINTEUR = 34,                  /* POINTEUR  */
  YYSYMBOL_CONST = 35,                     /* CONST  */
  YYSYMBOL_ENTIER = 36,                    /* ENTIER  */
  YYSYMBOL_FLOTTANT = 37,                  /* FLOTTANT  */
  YYSYMBOL_STRING = 38,                    /* STRING  */
  YYSYMBOL_CHAR = 39,                      /* CHAR  */
  YYSYMBOL_BOOLEAN = 40,                   /* BOOLEAN  */
  YYSYMBOL_ID = 41,                        /* ID  */
  YYSYMBOL_INCREM = 42,                    /* INCREM  */
  YYSYMBOL_DECREM = 43,                    /* DECREM  */
  YYSYMBOL_PLUS = 44,                      /* PLUS  */
  YYSYMBOL_DIV = 45,                       /* DIV  */
  YYSYMBOL_MOINS = 46,                     /* MOINS  */
  YYSYMBOL_MULT = 47,                      /* MULT  */
  YYSYMBOL_MOD = 48,                       /* MOD  */
  YYSYMBOL_PUISS = 49,                     /* PUISS  */
  YYSYMBOL_ASSIGN = 50,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 51,                 /* SEMICOLON  */
  YYSYMBOL_INF = 52,                       /* INF  */
  YYSYMBOL_INF_EGAL = 53,                  /* INF_EGAL  */
  YYSYMBOL_SUP = 54,                       /* SUP  */
  YYSYMBOL_SUPP_EGAL = 55,                 /* SUPP_EGAL  */
  YYSYMBOL_EQUAL = 56,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 57,                 /* NOT_EQUAL  */
  YYSYMBOL_FROM = 58,                      /* FROM  */
  YYSYMBOL_TO = 59,                        /* TO  */
  YYSYMBOL_VIRGULE = 60,                   /* VIRGULE  */
  YYSYMBOL_SUPP = 61,                      /* SUPP  */
  YYSYMBOL_EGALE = 62,                     /* EGALE  */
  YYSYMBOL_PASEGALE = 63,                  /* PASEGALE  */
  YYSYMBOL_MUL = 64,                       /* MUL  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_programme = 66,                 /* programme  */
  YYSYMBOL_67_1 = 67,                      /* $@1  */
  YYSYMBOL_type = 68,                      /* type  */
  YYSYMBOL_tableau = 69,                   /* tableau  */
  YYSYMBOL_type_Struct = 70,               /* type_Struct  */
  YYSYMBOL_valeur = 71,                    /* valeur  */
  YYSYMBOL_variable = 72,                  /* variable  */
  YYSYMBOL_expression = 73,                /* expression  */
  YYSYMBOL_incrementation = 74,            /* incrementation  */
  YYSYMBOL_declarations = 75,              /* declarations  */
  YYSYMBOL_declaration = 76,               /* declaration  */
  YYSYMBOL_77_2 = 77,                      /* $@2  */
  YYSYMBOL_functions = 78,                 /* functions  */
  YYSYMBOL_fonction = 79,                  /* fonction  */
  YYSYMBOL_parametres = 80,                /* parametres  */
  YYSYMBOL_parametre = 81,                 /* parametre  */
  YYSYMBOL_instructions = 82,              /* instructions  */
  YYSYMBOL_instruction = 83,               /* instruction  */
  YYSYMBOL_read = 84,                      /* read  */
  YYSYMBOL_write = 85,                     /* write  */
  YYSYMBOL_retourner = 86,                 /* retourner  */
  YYSYMBOL_assignment = 87,                /* assignment  */
  YYSYMBOL_88_3 = 88,                      /* $@3  */
  YYSYMBOL_condition = 89,                 /* condition  */
  YYSYMBOL_loop = 90,                      /* loop  */
  YYSYMBOL_while_partie_une = 91,          /* while_partie_une  */
  YYSYMBOL_while_partie_deux = 92,         /* while_partie_deux  */
  YYSYMBOL_while_partie_trois = 93,        /* while_partie_trois  */
  YYSYMBOL_for_partie_une = 94,            /* for_partie_une  */
  YYSYMBOL_for_partie_deux = 95,           /* for_partie_deux  */
  YYSYMBOL_for_partie_trois = 96,          /* for_partie_trois  */
  YYSYMBOL_corps = 97,                     /* corps  */
  YYSYMBOL_elsebloc = 98,                  /* elsebloc  */
  YYSYMBOL_call = 99,                      /* call  */
  YYSYMBOL_parametresCall = 100,           /* parametresCall  */
  YYSYMBOL_parametreCall = 101             /* parametreCall  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   422

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  212

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   177,   177,   177,   194,   200,   206,   212,   218,   224,
     232,   236,   239,   245,   251,   257,   261,   265,   271,   275,
     279,   299,   300,   301,   353,   405,   406,   407,   408,   409,
     410,   412,   469,   527,   584,   642,   705,   766,   812,   861,
     862,   865,   867,   871,   871,   900,   901,   903,   905,   908,
     909,   912,   914,   915,   919,   920,   921,   923,   925,   928,
     929,   930,   931,   932,   933,   934,   935,   936,   937,   938,
     941,   945,   946,   947,   951,   955,   956,   956,   997,   998,
    1002,  1006,  1007,  1011,  1021,  1036,  1054,  1064,  1091,  1108,
    1109,  1111,  1113,  1114,  1119,  1124,  1126,  1127,  1132,  1133
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DEBUT", "FIN",
  "WHILE", "FOR", "PRINT", "INPUT", "FONCTION", "VIDE", "RETURN",
  "COMMENT", "COMMENT_PLUS", "OR", "AND", "NOT", "IF", "ELSE", "ELIF",
  "DEB_CORPS", "FIN_CORPS", "TRUE", "FALSE", "PAR_OUV", "PAR_FERM",
  "CARACTERE", "CHAINE", "INT", "FLOAT", "DEB_TABLEAU", "FIN_TABLEAU",
  "TABLE", "ENREGISTREMENT", "POINTEUR", "CONST", "ENTIER", "FLOTTANT",
  "STRING", "CHAR", "BOOLEAN", "ID", "INCREM", "DECREM", "PLUS", "DIV",
  "MOINS", "MULT", "MOD", "PUISS", "ASSIGN", "SEMICOLON", "INF",
  "INF_EGAL", "SUP", "SUPP_EGAL", "EQUAL", "NOT_EQUAL", "FROM", "TO",
  "VIRGULE", "SUPP", "EGALE", "PASEGALE", "MUL", "$accept", "programme",
  "$@1", "type", "tableau", "type_Struct", "valeur", "variable",
  "expression", "incrementation", "declarations", "declaration", "$@2",
  "functions", "fonction", "parametres", "parametre", "instructions",
  "instruction", "read", "write", "retourner", "assignment", "$@3",
  "condition", "loop", "while_partie_une", "while_partie_deux",
  "while_partie_trois", "for_partie_une", "for_partie_deux",
  "for_partie_trois", "corps", "elsebloc", "call", "parametresCall",
  "parametreCall", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-97)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -97,    12,   -97,   -97,     0,     8,   -10,   201,   -97,   -97,
     -97,   -97,   -97,    25,   -97,   -97,    30,   -97,    16,   373,
     382,    46,    38,    39,    41,    20,    35,   -97,   296,    65,
      67,    71,    78,    56,   382,   100,   120,   -97,   -97,   -97,
      91,   119,   122,   123,   124,    37,   -97,   -97,   125,   109,
     111,    -1,   115,    95,   106,   -97,   108,   -97,   -97,   -97,
     114,   -97,   -97,   -97,    37,   118,   116,   -97,   -97,   -97,
     310,   382,   135,   138,   -97,   117,   150,   -97,   -97,   -17,
     129,    37,   -97,   -97,    37,   -97,   -97,   -97,   -97,    18,
     -97,   -97,   218,    37,   100,   120,   348,   145,   139,    98,
     134,   -97,   -97,   -97,    98,   -97,   218,   165,   151,   310,
     -97,   -97,   -97,   -97,   -97,   310,   161,    96,   -97,   -97,
     -14,   178,   182,   346,   130,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,   174,
     -97,   -97,   183,   152,   180,   -97,    -8,   218,   164,   149,
     166,   310,   -97,   188,   -97,   -97,   373,   -97,   -97,   -97,
     177,   184,   191,   198,   -97,   218,   238,    28,    62,    28,
     218,    62,    -6,   346,   346,   346,   218,   218,   346,   310,
     -97,   348,   -97,   206,   -97,   -97,   -97,   -97,   175,   347,
     -97,   225,   -97,   -97,    -4,   -97,   -97,   230,   -97,   208,
     310,   237,   -97,   243,   -97,   -97,    37,   -97,   199,   310,
      -4,   -97
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,    47,     1,     0,     0,     0,     0,     4,     5,
       6,     7,     8,     0,    48,    41,     0,     9,     0,    57,
      51,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,     0,     0,    53,    51,     0,     0,    43,    45,    46,
       0,     0,     0,     0,     0,     0,    61,    62,     0,     0,
       0,    20,     0,     0,     0,    59,     0,    58,    65,    66,
       0,    60,    63,    64,     0,     0,     0,    55,    56,    54,
       0,    51,     0,     0,    41,     0,     0,    83,    86,     0,
       0,     0,    16,    17,     0,    14,    15,    12,    13,    20,
      21,    22,    74,     0,    55,    56,    95,     0,     0,     0,
      43,    39,    40,    67,     0,    68,    84,     0,     0,     0,
      69,    41,    90,    50,    52,     0,     0,     0,    44,     3,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    99,     0,    97,     0,    19,    20,    76,     0,     0,
       0,     0,    81,     0,    82,    88,    57,    49,    10,    11,
       0,     0,     0,     0,    30,    38,    37,    23,    26,    24,
      25,    27,    28,    31,    32,    34,    35,    36,    33,     0,
      94,    95,    18,     0,    79,    75,    78,    85,     0,     0,
      73,     0,    72,    70,    91,    96,    77,     0,    89,     0,
       0,     0,    80,     0,    71,    92,     0,    87,     0,     0,
      91,    93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -97,   -97,   -97,    -2,   -97,   -97,   -76,   -28,   -37,   -97,
     -68,   -15,   -97,   -97,   -97,   -26,   -13,   113,   -27,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -96,    66,   -74,    97,   -97
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    52,    25,    26,    90,    91,    92,    54,
      19,    55,    75,     4,    14,    32,    56,    28,   112,    58,
      59,    60,    61,   183,    62,    63,    64,   107,   152,    65,
     109,   154,   113,   202,    66,   142,   143
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    57,    13,     5,    27,    17,   117,    33,    72,     6,
     120,   160,     3,   155,   200,   201,    96,    24,    31,   157,
     140,    33,    97,    96,   121,   148,    98,   106,    15,    97,
     150,    16,    31,    98,    18,     7,     8,     9,    10,    11,
      12,   130,    53,   156,   123,   114,   161,   124,    97,    99,
     136,   137,    98,    81,    20,   187,   139,    21,    33,    82,
      83,    84,   147,    85,    86,    87,    88,   149,   141,    31,
      34,    38,   127,   128,   129,   130,   131,   132,    89,    35,
      36,    53,    37,   194,   136,   137,    39,    53,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,    27,    70,   205,   140,    67,   128,    68,   130,
     131,   132,    69,   210,    81,    24,    71,   159,   136,   137,
      82,    83,    84,    53,    85,    86,    87,    88,    22,    23,
      73,     7,     8,     9,    10,    11,    12,   101,   102,   146,
      74,    27,    76,    77,   125,   126,    78,    79,    80,    93,
      94,    53,    95,   141,    24,   164,   100,   103,   104,   108,
     115,    53,    57,   125,   126,   105,   116,   110,   118,   208,
     122,   119,    53,   144,   127,   128,   129,   130,   131,   132,
     145,    53,   133,   134,   -54,   135,   136,   137,   125,   126,
     151,   138,   158,   127,   128,   129,   130,   131,   132,   179,
     185,   133,   134,   162,   135,   136,   137,   163,   180,   153,
     138,   182,   181,   125,   126,   184,   188,   186,   127,   128,
     129,   130,   131,   132,   209,   191,   133,   134,   190,   135,
     136,   137,   125,   126,   197,   138,     7,     8,     9,    10,
      11,    12,   192,   127,   128,   129,   130,   131,   132,   193,
     199,   133,   134,   126,   135,   136,   137,   196,   203,   204,
     138,   206,   127,   128,   129,   130,   131,   132,   207,   189,
     133,   134,     0,   135,   136,   137,   211,     0,   195,   138,
       0,     0,   127,   128,   129,   130,   131,   132,     0,     0,
     133,   134,     0,   135,   136,   137,     0,     0,     0,   138,
      40,    41,    42,    43,    44,     0,     0,    45,    46,    47,
       0,     0,     0,    48,     0,    41,    42,    43,    44,     0,
       0,    45,    46,    47,     0,     0,     0,    48,    49,    50,
     111,     7,     8,     9,    10,    11,    12,    51,     0,     0,
       0,     0,    49,    50,     0,     7,     8,     9,    10,    11,
      12,    51,    41,    42,    43,    44,     0,     0,    45,    46,
      47,     0,     0,     0,    48,     0,     0,     0,   198,     0,
      82,    83,     0,     0,    85,    86,    87,    88,     0,    49,
      50,     0,     7,     8,     9,    10,    11,    12,    51,    89,
     127,   128,   129,   130,   131,   132,     0,     0,   133,   134,
       0,   135,   136,   137,     0,    22,    23,   138,     7,     8,
       9,    10,    11,    12,    29,    30,     0,     7,     8,     9,
      10,    11,    12
};

static const yytype_int16 yycheck[] =
{
      28,    28,     4,     3,    19,     7,    74,    20,    34,     9,
      27,    25,     0,   109,    18,    19,    24,    19,    20,   115,
      96,    34,    30,    24,    41,    99,    34,    64,    20,    30,
     104,    41,    34,    34,     9,    35,    36,    37,    38,    39,
      40,    47,    70,   111,    81,    71,    60,    84,    30,    50,
      56,    57,    34,    16,    24,   151,    93,    41,    71,    22,
      23,    24,    99,    26,    27,    28,    29,   104,    96,    71,
      24,    51,    44,    45,    46,    47,    48,    49,    41,    41,
      41,   109,    41,   179,    56,    57,    51,   115,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   117,    25,   200,   181,    41,    45,    41,    47,
      48,    49,    41,   209,    16,   117,    60,    21,    56,    57,
      22,    23,    24,   151,    26,    27,    28,    29,    32,    33,
      30,    35,    36,    37,    38,    39,    40,    42,    43,    41,
      20,   156,    51,    24,    14,    15,    24,    24,    24,    24,
      41,   179,    41,   181,   156,    25,    41,    51,    50,    41,
      25,   189,   189,    14,    15,    51,    28,    51,    51,   206,
      41,    21,   200,    28,    44,    45,    46,    47,    48,    49,
      41,   209,    52,    53,    50,    55,    56,    57,    14,    15,
      25,    61,    31,    44,    45,    46,    47,    48,    49,    25,
      51,    52,    53,    25,    55,    56,    57,    25,    25,    58,
      61,    31,    60,    14,    15,    51,    28,    51,    44,    45,
      46,    47,    48,    49,    25,    41,    52,    53,    51,    55,
      56,    57,    14,    15,    59,    61,    35,    36,    37,    38,
      39,    40,    51,    44,    45,    46,    47,    48,    49,    51,
      25,    52,    53,    15,    55,    56,    57,    51,    28,    51,
      61,    24,    44,    45,    46,    47,    48,    49,    25,   156,
      52,    53,    -1,    55,    56,    57,   210,    -1,   181,    61,
      -1,    -1,    44,    45,    46,    47,    48,    49,    -1,    -1,
      52,    53,    -1,    55,    56,    57,    -1,    -1,    -1,    61,
       4,     5,     6,     7,     8,    -1,    -1,    11,    12,    13,
      -1,    -1,    -1,    17,    -1,     5,     6,     7,     8,    -1,
      -1,    11,    12,    13,    -1,    -1,    -1,    17,    32,    33,
      20,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    32,    33,    -1,    35,    36,    37,    38,    39,
      40,    41,     5,     6,     7,     8,    -1,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    -1,    -1,    -1,    21,    -1,
      22,    23,    -1,    -1,    26,    27,    28,    29,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    41,
      44,    45,    46,    47,    48,    49,    -1,    -1,    52,    53,
      -1,    55,    56,    57,    -1,    32,    33,    61,    35,    36,
      37,    38,    39,    40,    32,    33,    -1,    35,    36,    37,
      38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    66,    67,     0,    78,     3,     9,    35,    36,    37,
      38,    39,    40,    68,    79,    20,    41,    68,     9,    75,
      24,    41,    32,    33,    68,    69,    70,    76,    82,    32,
      33,    68,    80,    81,    24,    41,    41,    41,    51,    51,
       4,     5,     6,     7,     8,    11,    12,    13,    17,    32,
      33,    41,    68,    72,    74,    76,    81,    83,    84,    85,
      86,    87,    89,    90,    91,    94,    99,    41,    41,    41,
      25,    60,    80,    30,    20,    77,    51,    24,    24,    24,
      24,    16,    22,    23,    24,    26,    27,    28,    29,    41,
      71,    72,    73,    24,    41,    41,    24,    30,    34,    50,
      41,    42,    43,    51,    50,    51,    73,    92,    41,    95,
      51,    20,    83,    97,    80,    25,    28,    75,    51,    21,
      27,    41,    41,    73,    73,    14,    15,    44,    45,    46,
      47,    48,    49,    52,    53,    55,    56,    57,    61,    73,
      71,    72,   100,   101,    28,    41,    41,    73,    99,    73,
      99,    25,    93,    58,    96,    97,    75,    97,    31,    21,
      25,    60,    25,    25,    25,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    25,
      25,    60,    31,    88,    51,    51,    51,    97,    28,    82,
      51,    41,    51,    51,    97,   100,    51,    59,    21,    25,
      18,    19,    98,    28,    51,    97,    24,    25,    73,    25,
      97,    98
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    67,    66,    68,    68,    68,    68,    68,    68,
      69,    70,    71,    71,    71,    71,    71,    71,    72,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    74,
      74,    75,    75,    77,    76,    76,    76,    78,    78,    79,
      79,    80,    80,    80,    81,    81,    81,    82,    82,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      84,    85,    85,    85,    86,    87,    88,    87,    87,    87,
      89,    90,    90,    91,    92,    93,    94,    95,    96,    97,
      97,    98,    98,    98,    99,   100,   100,   100,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     9,     1,     1,     1,     1,     1,     2,
       5,     5,     1,     1,     1,     1,     1,     1,     4,     3,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     0,     2,     0,     4,     2,     2,     0,     2,     7,
       6,     0,     3,     1,     2,     2,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       5,     7,     5,     5,     2,     4,     0,     5,     4,     4,
       6,     3,     3,     2,     1,     2,     2,     6,     1,     4,
       1,     0,     2,     6,     4,     0,     3,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 177 "parser.y"
    {
        TS = creerTableSymbole();  
        TQ = initialiserTQ() ;
        P = initialiserP();
    }
#line 1460 "parser.tab.c"
    break;

  case 3: /* programme: $@1 functions DEBUT DEB_CORPS declarations instructions FIN SEMICOLON FIN_CORPS  */
#line 182 "parser.y"
                                                                                {
        qC++;
        quad = creer_Q("fin", "", "", "", qC);
        inserer_TQ(TQ, quad); 
        afficherTableSymbole(TS); // afficher TS pour confirmer
        afficherTQ(TQ);  // afficher TQ pour confirmer
        afficherTQDansFichier(TQ, "output.txt");
        printf("\nProgramme accepte.");
    }
#line 1474 "parser.tab.c"
    break;

  case 4: /* type: ENTIER  */
#line 194 "parser.y"
           {
        currentType.baseType = ENTIER;
        currentType.isArray = false;
        currentType.isConst = false;
        (yyval.type) = ENTIER;
    }
#line 1485 "parser.tab.c"
    break;

  case 5: /* type: FLOTTANT  */
#line 200 "parser.y"
               {
        currentType.baseType = FLOTTANT;
        currentType.isArray = false;
        currentType.isConst = false;
        (yyval.type) = FLOTTANT;
    }
#line 1496 "parser.tab.c"
    break;

  case 6: /* type: STRING  */
#line 206 "parser.y"
             {
        currentType.baseType = STRING;
        currentType.isArray = false;
        currentType.isConst = false;
        (yyval.type) = STRING;
    }
#line 1507 "parser.tab.c"
    break;

  case 7: /* type: CHAR  */
#line 212 "parser.y"
           {
        currentType.baseType = CHAR;
        currentType.isArray = false;
        currentType.isConst = false;
        (yyval.type) = CHAR;
    }
#line 1518 "parser.tab.c"
    break;

  case 8: /* type: BOOLEAN  */
#line 218 "parser.y"
              {
        currentType.baseType = BOOLEAN;
        currentType.isArray = false;
        currentType.isConst = false;
        (yyval.type) = BOOLEAN;
    }
#line 1529 "parser.tab.c"
    break;

  case 9: /* type: CONST type  */
#line 224 "parser.y"
                 {
        currentType.isConst = true;
        (yyval.type) = (yyvsp[0].type);
    }
#line 1538 "parser.tab.c"
    break;

  case 12: /* valeur: INT  */
#line 239 "parser.y"
        { 
        (yyval.structure).type = ENTIER;
        char buffer[256];
        sprintf(buffer, "%d", (yyvsp[0].intv));
        (yyval.structure).valeur = strdup(buffer);
    }
#line 1549 "parser.tab.c"
    break;

  case 13: /* valeur: FLOAT  */
#line 245 "parser.y"
            {
        (yyval.structure).type = FLOTTANT;
        char buffer[256];
        sprintf(buffer, "%f", (yyvsp[0].flt));
        (yyval.structure).valeur = strdup(buffer);
    }
#line 1560 "parser.tab.c"
    break;

  case 14: /* valeur: CARACTERE  */
#line 251 "parser.y"
                {
        (yyval.structure).type = CHAR;
        char buffer[256];
        sprintf(buffer, "%c", (yyvsp[0].charv));
        (yyval.structure).valeur = strdup(buffer);
    }
#line 1571 "parser.tab.c"
    break;

  case 15: /* valeur: CHAINE  */
#line 257 "parser.y"
             {
        (yyval.structure).type = STRING;
        (yyval.structure).valeur = strdup((yyvsp[0].str));
    }
#line 1580 "parser.tab.c"
    break;

  case 16: /* valeur: TRUE  */
#line 261 "parser.y"
           {
        (yyval.structure).type = BOOLEAN;
        (yyval.structure).valeur = strdup("true");
    }
#line 1589 "parser.tab.c"
    break;

  case 17: /* valeur: FALSE  */
#line 265 "parser.y"
            {
        (yyval.structure).type = BOOLEAN;
        (yyval.structure).valeur = strdup("false");
    }
#line 1598 "parser.tab.c"
    break;

  case 18: /* variable: ID DEB_TABLEAU INT FIN_TABLEAU  */
#line 271 "parser.y"
                                   {
        (yyval.structure).nom = (yyvsp[-3].str);
        (yyval.structure).type = ENTIER;  // assuming array of integers
    }
#line 1607 "parser.tab.c"
    break;

  case 19: /* variable: ID POINTEUR ID  */
#line 275 "parser.y"
                     {
        (yyval.structure).nom = (yyvsp[-2].str);
        (yyval.structure).type = ENTIER;  // modify based on your needs
    }
#line 1616 "parser.tab.c"
    break;

  case 20: /* variable: ID  */
#line 279 "parser.y"
         {
        (yyval.structure).nom = strdup((yyvsp[0].str));
        Symbole* found;
        if (rechercherSymbole(TS, (yyvsp[0].str), &found)) {
            switch(found->type[0]) {
                case 'E': (yyval.structure).type = ENTIER; break;
                case 'F': (yyval.structure).type = FLOTTANT; break;
                case 'S': (yyval.structure).type = STRING; break;
                case 'C': (yyval.structure).type = CHAR; break;
                case 'B': (yyval.structure).type = BOOLEAN; break;
                default: (yyval.structure).type = ENTIER;
            }
            (yyval.structure).valeur = strdup(found->valeur);
            }
            else{
                semanticError("Variable non declaree", line);
            }
        }
#line 1639 "parser.tab.c"
    break;

  case 23: /* expression: expression PLUS expression  */
#line 301 "parser.y"
                                 {
        printf("i am inside addition\n");
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        (yyval.structure).nom = NULL;
        (yyval.structure).valeur = malloc(255);
        if ((yyval.structure).valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = (yyvsp[-2].structure).valeur;
        val2 = (yyvsp[0].structure).valeur;            
        // Perform addition based on types
        if ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == ENTIER) {
            printf("i am inside addition\n");
            int result = atoi(val1) + atoi(val2);
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = ENTIER;
        } else if ((yyvsp[-2].structure).type == FLOTTANT || (yyvsp[0].structure).type == FLOTTANT) {
            float result = atof(val1) + atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = FLOTTANT;
        } else if (((yyvsp[-2].structure).type == FLOTTANT && (yyvsp[0].structure).type == ENTIER) || ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == FLOTTANT)) {
            float result = atof(val1) + atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = FLOTTANT;
        } else {
            semanticError("Invalid types for addition", line);
        }

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        (yyval.structure).nom=resultVarName;
        quad = creer_Q("+", 
                      (yyvsp[-2].structure).nom ? (yyvsp[-2].structure).nom : (yyvsp[-2].structure).valeur,
                      (yyvsp[0].structure).nom ? (yyvsp[0].structure).nom : (yyvsp[0].structure).valeur,
                      (yyval.structure).nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
#line 1696 "parser.tab.c"
    break;

  case 24: /* expression: expression MOINS expression  */
#line 353 "parser.y"
                                  {
        printf("i am inside subtraction\n");
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        (yyval.structure).nom = NULL;
        (yyval.structure).valeur = malloc(255);
        if ((yyval.structure).valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = (yyvsp[-2].structure).valeur;
        val2 = (yyvsp[0].structure).valeur;            
        // Perform subtraction based on types
        if ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == ENTIER) {
            printf("i am inside subtraction\n");
            int result = atoi(val1) - atoi(val2);
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = ENTIER;
        } else if ((yyvsp[-2].structure).type == FLOTTANT || (yyvsp[0].structure).type == FLOTTANT) {
            float result = atof(val1) - atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = FLOTTANT;
        } else if (((yyvsp[-2].structure).type == FLOTTANT && (yyvsp[0].structure).type == ENTIER) || ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == FLOTTANT)) {
            float result = atof(val1) - atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = FLOTTANT;
        } else {
            semanticError("Invalid types for subtraction", line);
        }

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        (yyval.structure).nom=resultVarName;
        quad = creer_Q("-", 
                      (yyvsp[-2].structure).nom ? (yyvsp[-2].structure).nom : (yyvsp[-2].structure).valeur,
                      (yyvsp[0].structure).nom ? (yyvsp[0].structure).nom : (yyvsp[0].structure).valeur,
                      (yyval.structure).nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
#line 1753 "parser.tab.c"
    break;

  case 31: /* expression: expression INF expression  */
#line 412 "parser.y"
                                {

        printf("i am inside comparaison\n");
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        (yyval.structure).nom = NULL;
        (yyval.structure).valeur = malloc(255);
        if ((yyval.structure).valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = (yyvsp[-2].structure).valeur;
        val2 = (yyvsp[0].structure).valeur;   

        // Perform subtraction based on types
        if ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == ENTIER) {
            int result = atoi(val1) < atoi(val2);
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = BOOLEAN;
        } else if ((yyvsp[-2].structure).type == FLOTTANT && (yyvsp[0].structure).type == FLOTTANT) {
            float result = atof(val1) < atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = BOOLEAN;
        } else if (((yyvsp[-2].structure).type == FLOTTANT && (yyvsp[0].structure).type == ENTIER) || ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == FLOTTANT)) {
            float result = atof(val1) < atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = BOOLEAN;
        } else if (((yyvsp[-2].structure).type == STRING && (yyvsp[0].structure).type == STRING) || ((yyvsp[-2].structure).type == CHAR && (yyvsp[0].structure).type == CHAR)) {
            int result = strcmp(val1, val2) < 0;
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = BOOLEAN;
        } else {
            semanticError("Invalid types for comparaison", line);
        } 

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        (yyval.structure).nom=resultVarName;
        quad = creer_Q("-", 
                      (yyvsp[-2].structure).nom ? (yyvsp[-2].structure).nom : (yyvsp[-2].structure).valeur,
                      (yyvsp[0].structure).nom ? (yyvsp[0].structure).nom : (yyvsp[0].structure).valeur,
                      (yyval.structure).nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
#line 1815 "parser.tab.c"
    break;

  case 32: /* expression: expression INF_EGAL expression  */
#line 469 "parser.y"
                                     {

        printf("i am inside comparaison\n");
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        (yyval.structure).nom = NULL;
        (yyval.structure).valeur = malloc(255);
        if ((yyval.structure).valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = (yyvsp[-2].structure).valeur;
        val2 = (yyvsp[0].structure).valeur;   

        // Perform subtraction based on types
        if ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == ENTIER) {
            int result = atoi(val1) <= atoi(val2);
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = BOOLEAN;
        } else if ((yyvsp[-2].structure).type == FLOTTANT && (yyvsp[0].structure).type == FLOTTANT) {
            float result = atof(val1) <= atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = BOOLEAN;
        } else if (((yyvsp[-2].structure).type == FLOTTANT && (yyvsp[0].structure).type == ENTIER) || ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == FLOTTANT)) {
            float result = atof(val1) <= atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = BOOLEAN;
        } else if (((yyvsp[-2].structure).type == STRING && (yyvsp[0].structure).type == STRING) || ((yyvsp[-2].structure).type == CHAR && (yyvsp[0].structure).type == CHAR)) {
            int result = strcmp(val1, val2) <= 0;
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = BOOLEAN;
        } else {
            semanticError("Invalid types for comparaison", line);
        } 

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        (yyval.structure).nom=resultVarName;
        quad = creer_Q("-", 
                      (yyvsp[-2].structure).nom ? (yyvsp[-2].structure).nom : (yyvsp[-2].structure).valeur,
                      (yyvsp[0].structure).nom ? (yyvsp[0].structure).nom : (yyvsp[0].structure).valeur,
                      (yyval.structure).nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");

    }
#line 1878 "parser.tab.c"
    break;

  case 33: /* expression: expression SUPP expression  */
#line 527 "parser.y"
                                 {

        printf("i am inside comparaison\n");
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        (yyval.structure).nom = NULL;
        (yyval.structure).valeur = malloc(255);
        if ((yyval.structure).valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = (yyvsp[-2].structure).valeur;
        val2 = (yyvsp[0].structure).valeur;   

        // Perform subtraction based on types
        if ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == ENTIER) {
            int result = atoi(val1) > atoi(val2);
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = BOOLEAN;
        } else if ((yyvsp[-2].structure).type == FLOTTANT && (yyvsp[0].structure).type == FLOTTANT) {
            float result = atof(val1) > atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = BOOLEAN;
        } else if (((yyvsp[-2].structure).type == FLOTTANT && (yyvsp[0].structure).type == ENTIER) || ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == FLOTTANT)) {
            float result = atof(val1) > atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = BOOLEAN;
        } else if (((yyvsp[-2].structure).type == STRING && (yyvsp[0].structure).type == STRING) || ((yyvsp[-2].structure).type == CHAR && (yyvsp[0].structure).type == CHAR)) {
            int result = strcmp(val1, val2) > 0;
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = BOOLEAN;
        } else {
            semanticError("Invalid types for comparaison", line);
        } 

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        (yyval.structure).nom=resultVarName;
        quad = creer_Q("-", 
                      (yyvsp[-2].structure).nom ? (yyvsp[-2].structure).nom : (yyvsp[-2].structure).valeur,
                      (yyvsp[0].structure).nom ? (yyvsp[0].structure).nom : (yyvsp[0].structure).valeur,
                      (yyval.structure).nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
#line 1940 "parser.tab.c"
    break;

  case 34: /* expression: expression SUPP_EGAL expression  */
#line 584 "parser.y"
                                      {

        printf("i am inside comparaison\n");
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        (yyval.structure).nom = NULL;
        (yyval.structure).valeur = malloc(255);
        if ((yyval.structure).valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = (yyvsp[-2].structure).valeur;
        val2 = (yyvsp[0].structure).valeur;   

        // Perform subtraction based on types
        if ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == ENTIER) {
            int result = atoi(val1) >= atoi(val2);
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = BOOLEAN;
        } else if ((yyvsp[-2].structure).type == FLOTTANT && (yyvsp[0].structure).type == FLOTTANT) {
            float result = atof(val1) >= atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = BOOLEAN;
        } else if (((yyvsp[-2].structure).type == FLOTTANT && (yyvsp[0].structure).type == ENTIER) || ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == FLOTTANT)) {
            float result = atof(val1) >= atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = BOOLEAN;
        } else if (((yyvsp[-2].structure).type == STRING && (yyvsp[0].structure).type == STRING) || ((yyvsp[-2].structure).type == CHAR && (yyvsp[0].structure).type == CHAR)) {
            int result = strcmp(val1, val2) >= 0;
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = BOOLEAN;
        } else {
            semanticError("Invalid types for comparaison", line);
        } 

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        (yyval.structure).nom=resultVarName;
        quad = creer_Q("-", 
                      (yyvsp[-2].structure).nom ? (yyvsp[-2].structure).nom : (yyvsp[-2].structure).valeur,
                      (yyvsp[0].structure).nom ? (yyvsp[0].structure).nom : (yyvsp[0].structure).valeur,
                      (yyval.structure).nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
#line 2002 "parser.tab.c"
    break;

  case 35: /* expression: expression EQUAL expression  */
#line 642 "parser.y"
                                  {

        printf("i am inside comparaison\n");
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        (yyval.structure).nom = NULL;
        (yyval.structure).valeur = malloc(255);
        if ((yyval.structure).valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = (yyvsp[-2].structure).valeur;
        val2 = (yyvsp[0].structure).valeur;   

        // Perform subtraction based on types
        if ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == ENTIER) {
            int result = atoi(val1) == atoi(val2);
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = BOOLEAN;
        } else if ((yyvsp[-2].structure).type == FLOTTANT && (yyvsp[0].structure).type == FLOTTANT) {
            float result = atof(val1) == atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = BOOLEAN;
        } else if (((yyvsp[-2].structure).type == FLOTTANT && (yyvsp[0].structure).type == ENTIER) || ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == FLOTTANT)) {
            float result = atof(val1) == atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = BOOLEAN;
        } else if (((yyvsp[-2].structure).type == STRING && (yyvsp[0].structure).type == STRING) || ((yyvsp[-2].structure).type == CHAR && (yyvsp[0].structure).type == CHAR)) {
            int result = strcmp(val1, val2) == 0;
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = BOOLEAN;
        }
        else if((yyvsp[-2].structure).type == BOOLEAN && (yyvsp[0].structure).type == BOOLEAN){
            int result = atoi(val1) == atoi(val2);
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = BOOLEAN;
        } else {
            semanticError("Invalid types for comparaison", line);
        } 

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        (yyval.structure).nom=resultVarName;
        quad = creer_Q("-", 
                      (yyvsp[-2].structure).nom ? (yyvsp[-2].structure).nom : (yyvsp[-2].structure).valeur,
                      (yyvsp[0].structure).nom ? (yyvsp[0].structure).nom : (yyvsp[0].structure).valeur,
                      (yyval.structure).nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
#line 2069 "parser.tab.c"
    break;

  case 36: /* expression: expression NOT_EQUAL expression  */
#line 705 "parser.y"
                                      {

        printf("i am inside comparaison\n");
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        (yyval.structure).nom = NULL;
        (yyval.structure).valeur = malloc(255);
        if ((yyval.structure).valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = (yyvsp[-2].structure).valeur;
        val2 = (yyvsp[0].structure).valeur;   

        // Perform subtraction based on types
        if ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == ENTIER) {
            int result = atoi(val1) != atoi(val2);
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = BOOLEAN;
        } else if ((yyvsp[-2].structure).type == FLOTTANT && (yyvsp[0].structure).type == FLOTTANT) {
            float result = atof(val1) != atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = BOOLEAN;
        } else if (((yyvsp[-2].structure).type == FLOTTANT && (yyvsp[0].structure).type == ENTIER) || ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == FLOTTANT)) {
            float result = atof(val1) != atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = BOOLEAN;
        } else if (((yyvsp[-2].structure).type == STRING && (yyvsp[0].structure).type == STRING) || ((yyvsp[-2].structure).type == CHAR && (yyvsp[0].structure).type == CHAR)) {
            int result = strcmp(val1, val2) != 0;
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = BOOLEAN;
        } else if((yyvsp[-2].structure).type == BOOLEAN && (yyvsp[0].structure).type == BOOLEAN){
            int result = atoi(val1) != atoi(val2);
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = BOOLEAN;
        } else {
            semanticError("Invalid types for comparaison", line);
        } 

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        (yyval.structure).nom=resultVarName;
        quad = creer_Q("-", 
                      (yyvsp[-2].structure).nom ? (yyvsp[-2].structure).nom : (yyvsp[-2].structure).valeur,
                      (yyvsp[0].structure).nom ? (yyvsp[0].structure).nom : (yyvsp[0].structure).valeur,
                      (yyval.structure).nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
#line 2135 "parser.tab.c"
    break;

  case 37: /* expression: expression AND expression  */
#line 766 "parser.y"
                                {

        printf("i am inside comparaison\n");
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        (yyval.structure).nom = NULL;
        (yyval.structure).valeur = malloc(255);
        if ((yyval.structure).valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = (yyvsp[-2].structure).valeur;
        val2 = (yyvsp[0].structure).valeur;   

        // Perform subtraction based on types
        if ((yyvsp[-2].structure).type == BOOLEAN && (yyvsp[0].structure).type == BOOLEAN) {
            int result = atoi(val1) && atoi(val2);
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = BOOLEAN;
        } else {
            semanticError("Invalid types for comparaison", line);
        } 

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        (yyval.structure).nom=resultVarName;
        quad = creer_Q("-", 
                      (yyvsp[-2].structure).nom ? (yyvsp[-2].structure).nom : (yyvsp[-2].structure).valeur,
                      (yyvsp[0].structure).nom ? (yyvsp[0].structure).nom : (yyvsp[0].structure).valeur,
                      (yyval.structure).nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");

    }
#line 2186 "parser.tab.c"
    break;

  case 38: /* expression: expression OR expression  */
#line 812 "parser.y"
                               {

        printf("i am inside comparaison\n");
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        (yyval.structure).nom = NULL;
        (yyval.structure).valeur = malloc(255);
        if ((yyval.structure).valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = (yyvsp[-2].structure).valeur;
        val2 = (yyvsp[0].structure).valeur;   

        // Perform subtraction based on types
        if ((yyvsp[-2].structure).type == BOOLEAN && (yyvsp[0].structure).type == BOOLEAN) {
            int result = atoi(val1) || atoi(val2);
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = BOOLEAN;
        } else {
            semanticError("Invalid types for comparaison", line);
        } 

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        (yyval.structure).nom=resultVarName;
        quad = creer_Q("-", 
                      (yyvsp[-2].structure).nom ? (yyvsp[-2].structure).nom : (yyvsp[-2].structure).valeur,
                      (yyvsp[0].structure).nom ? (yyvsp[0].structure).nom : (yyvsp[0].structure).valeur,
                      (yyval.structure).nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");

    }
#line 2237 "parser.tab.c"
    break;

  case 43: /* $@2: %empty  */
#line 871 "parser.y"
             {
        Symbole* found;
        if (rechercherSymbole(TS, (yyvsp[0].str), &found)) {
            semanticError("Variable already declared", line);
        }
        
        // Convert the type token to string
        char* typeStr;
        switch((yyvsp[-1].type)) {
            case ENTIER: typeStr = TYPE_ENTIER; break;
            case FLOTTANT: typeStr = TYPE_FLOTTANT; break;
            case CHAR: typeStr = TYPE_CHAR; break;
            case STRING: typeStr = TYPE_STRING; break;
            case BOOLEAN: typeStr = TYPE_BOOLEAN; break;
            default: typeStr = TYPE_ENTIER; // default case
        }
        
        Symbole* sym = creerSymbole(
            VARIABLE,    // category
            (yyvsp[0].str),         // name
            typeStr,    // type
            "",         // initial value
            line,       // line number
            0          // memory address
        );
        insererSymbole(TS, sym);
        afficherTableSymbole(TS); // afficher TS pour confirmer
        afficherTQ(TQ);
    }
#line 2271 "parser.tab.c"
    break;

  case 45: /* declaration: tableau SEMICOLON  */
#line 900 "parser.y"
                        {printf("declaration correcte syntaxiquement\n");}
#line 2277 "parser.tab.c"
    break;

  case 46: /* declaration: type_Struct SEMICOLON  */
#line 901 "parser.y"
                            {printf("declaration correcte syntaxiquement\n");}
#line 2283 "parser.tab.c"
    break;

  case 49: /* fonction: type FONCTION ID PAR_OUV parametres PAR_FERM corps  */
#line 908 "parser.y"
                                                       {printf("fonction correcte syntaxiquement\n");}
#line 2289 "parser.tab.c"
    break;

  case 50: /* fonction: FONCTION ID PAR_OUV parametres PAR_FERM corps  */
#line 909 "parser.y"
                                                    {printf("fonction correcte syntaxiquement\n");}
#line 2295 "parser.tab.c"
    break;

  case 52: /* parametres: parametre VIRGULE parametres  */
#line 914 "parser.y"
                                   {printf("parametres correcte syntaxiquement\n");}
#line 2301 "parser.tab.c"
    break;

  case 56: /* parametre: ENREGISTREMENT ID  */
#line 921 "parser.y"
                        {printf("parametre correcte syntaxiquement\n");}
#line 2307 "parser.tab.c"
    break;

  case 70: /* read: INPUT PAR_OUV ID PAR_FERM SEMICOLON  */
#line 941 "parser.y"
                                        {printf("read correcte syntaxiquement\n");}
#line 2313 "parser.tab.c"
    break;

  case 73: /* write: PRINT PAR_OUV CHAINE PAR_FERM SEMICOLON  */
#line 947 "parser.y"
                                            {printf("write correcte syntaxiquement\n");}
#line 2319 "parser.tab.c"
    break;

  case 74: /* retourner: RETURN expression  */
#line 951 "parser.y"
                      {printf("retourner correcte syntaxiquement\n");}
#line 2325 "parser.tab.c"
    break;

  case 76: /* $@3: %empty  */
#line 956 "parser.y"
                           {
        Symbole* found;
        if (rechercherSymbole(TS, (yyvsp[-2].str), &found)) { // is declared
            if (found->categorie == VARIABLE) {  
                qC++;
                
                // Create a buffer for the value
                char buffer[256];
                sprintf(buffer, "%s", (yyvsp[0].structure).valeur ? (yyvsp[0].structure).valeur : "");
                
                // Update the symbol's value

                SetValueSymbol(found, buffer);
                
                // Create quadruplet
                quad = creer_Q(":=", (yyvsp[-2].str), " ", buffer, qC);
                inserer_TQ(TQ, quad);
                 afficherTQ(TQ);
                
                // Convert expression type to string for comparison
                char* exprType = NULL;
                printf("Type de l'expression: %d\n", (yyvsp[0].structure).type);
                switch((yyvsp[0].structure).type) {
                    case ENTIER: exprType = TYPE_ENTIER; break;
                    case FLOTTANT: exprType = TYPE_FLOTTANT; break;
                    case CHAR: exprType = TYPE_CHAR; break;
                    case STRING: exprType = TYPE_STRING; break;
                    case BOOLEAN: exprType = TYPE_BOOLEAN; break;
                }
                printf("Type de l'expression: %s\n", exprType);
                printf("Type de la variable: %s\n", found->type);
                if (!areTypesCompatible(found->type, exprType)) {
                    semanticError("Type incompatible dans l'affectation.", line);
                }
            } else {
                semanticError("Identifier is not a variable", line);
            }
        } else {
            semanticError("Variable non declaree", line);
        }
    }
#line 2371 "parser.tab.c"
    break;

  case 80: /* condition: IF PAR_OUV expression PAR_FERM corps elsebloc  */
#line 1002 "parser.y"
                                                   {printf("condition correcte syntaxiquement\n");}
#line 2377 "parser.tab.c"
    break;

  case 83: /* while_partie_une: WHILE PAR_OUV  */
#line 1011 "parser.y"
                  {

        printf("I'm inside while\n");

        qC++;
        
        sauvDebut = qC;
    }
#line 2390 "parser.tab.c"
    break;

  case 84: /* while_partie_deux: expression  */
#line 1021 "parser.y"
              {

        printf("I'm inside while\n");

        if((yyvsp[0].structure).type != BOOLEAN) {
            semanticError("Condition de boucle invalide", line);
        }
        // Branchement vers fin si condition n'est pas vrai
        quad = creer_Q("BZ", "fin", " ", (yyvsp[0].structure).valeur, qC);
        inserer_TQ(TQ, quad);
        push(P, quad);
        afficherTQ(TQ);
    }
#line 2408 "parser.tab.c"
    break;

  case 85: /* while_partie_trois: PAR_FERM corps  */
#line 1036 "parser.y"
                   {

        printf("I'm inside while\n");

        qC++;
        quad = pop(P); 
        updateLabel(quad, qC+1);
        // Branchement inconditionnel vers Debut
        
        char etiq[255];
        sprintf(etiq, "%d", sauvDebut);
        quad = creer_Q("BR", etiq, "", "", qC);
        inserer_TQ(TQ, quad);
        afficherTQ(TQ);

    }
#line 2429 "parser.tab.c"
    break;

  case 86: /* for_partie_une: FOR PAR_OUV  */
#line 1054 "parser.y"
                {

        printf("I'm inside for\n");
       
        qC++;
        sauvDebut = qC;
    }
#line 2441 "parser.tab.c"
    break;

  case 87: /* for_partie_deux: ID FROM INT TO INT PAR_FERM  */
#line 1064 "parser.y"
                                {

        printf("Entrée dans for_partie_deux\n");

        char temp[20]; 
        int tempCounter = 0; 

        sprintf(temp, "T%d", tempCounter++); 

        // Utilisation dans creer_Q
        char str5[20], str3[20];
        sprintf(str5, "%d", (yyvsp[-1].intv));
        sprintf(str3, "%d", (yyvsp[-3].intv));
        quad = creer_Q("-", str5, str3, temp, qC);

        inserer_TQ(TQ, quad);
        afficherTQ(TQ);

        // Vérifier si le résultat est inférieur à 0
        qC++;
        quad = creer_Q("BZ", "fin", " ", temp, qC); // Sauter si la condition est fausse
        inserer_TQ(TQ, quad);
        push(P, quad);
        afficherTQ(TQ);
    }
#line 2471 "parser.tab.c"
    break;

  case 88: /* for_partie_trois: corps  */
#line 1091 "parser.y"
          {

        printf("Entrée dans for_partie_trois\n");

        qC++;
        quad = pop(P); 
        updateLabel(quad, qC+1);

        // Branchement inconditionnel vers Debut
        char etiq[255];
        sprintf(etiq, "%d", sauvDebut);
        quad = creer_Q("BR", etiq, "", "", qC);
        inserer_TQ(TQ, quad);
        afficherTQ(TQ);
    }
#line 2491 "parser.tab.c"
    break;

  case 97: /* parametresCall: parametreCall  */
#line 1128 "parser.y"
    {printf("parametres de l'appel du fonction correcte syntaxiquement\n");}
#line 2497 "parser.tab.c"
    break;

  case 99: /* parametreCall: variable  */
#line 1133 "parser.y"
               {printf("parametre correcte syntaxiquement\n");}
#line 2503 "parser.tab.c"
    break;


#line 2507 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1136 "parser.y"


void yyerror(const char *s) {
    if (sauvline == line){
        line = line -1 ;
    }
    fprintf(stderr, "File \"%s\", line %d, character %d: %s\n", 
            yyin_filename, line,sauv - linecol, s);
    exit(EXIT_FAILURE);
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <nom_fichier>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    yyin_filename = argv[1];
    FILE *file = fopen(yyin_filename, "r");
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    yyin = file;
    yyparse();
    fclose(yyin);

    return 0;
}

