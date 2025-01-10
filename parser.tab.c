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

#line 178 "parser.tab.c"

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
  YYSYMBOL_OU = 61,                        /* OU  */
  YYSYMBOL_ET = 62,                        /* ET  */
  YYSYMBOL_SUPP = 63,                      /* SUPP  */
  YYSYMBOL_EGALE = 64,                     /* EGALE  */
  YYSYMBOL_PASEGALE = 65,                  /* PASEGALE  */
  YYSYMBOL_MUL = 66,                       /* MUL  */
  YYSYMBOL_YYACCEPT = 67,                  /* $accept  */
  YYSYMBOL_programme = 68,                 /* programme  */
  YYSYMBOL_69_1 = 69,                      /* $@1  */
  YYSYMBOL_type = 70,                      /* type  */
  YYSYMBOL_tableau = 71,                   /* tableau  */
  YYSYMBOL_type_Struct = 72,               /* type_Struct  */
  YYSYMBOL_valeur = 73,                    /* valeur  */
  YYSYMBOL_variable = 74,                  /* variable  */
  YYSYMBOL_expression = 75,                /* expression  */
  YYSYMBOL_incrementation = 76,            /* incrementation  */
  YYSYMBOL_declarations = 77,              /* declarations  */
  YYSYMBOL_declaration = 78,               /* declaration  */
  YYSYMBOL_79_2 = 79,                      /* $@2  */
  YYSYMBOL_functions = 80,                 /* functions  */
  YYSYMBOL_fonction = 81,                  /* fonction  */
  YYSYMBOL_parametres = 82,                /* parametres  */
  YYSYMBOL_parametre = 83,                 /* parametre  */
  YYSYMBOL_instructions = 84,              /* instructions  */
  YYSYMBOL_instruction = 85,               /* instruction  */
  YYSYMBOL_read = 86,                      /* read  */
  YYSYMBOL_write = 87,                     /* write  */
  YYSYMBOL_retourner = 88,                 /* retourner  */
  YYSYMBOL_assignment = 89,                /* assignment  */
  YYSYMBOL_90_3 = 90,                      /* $@3  */
  YYSYMBOL_condition = 91,                 /* condition  */
  YYSYMBOL_loop = 92,                      /* loop  */
  YYSYMBOL_corps = 93,                     /* corps  */
  YYSYMBOL_elsebloc = 94,                  /* elsebloc  */
  YYSYMBOL_call = 95,                      /* call  */
  YYSYMBOL_parametresCall = 96,            /* parametresCall  */
  YYSYMBOL_parametreCall = 97              /* parametreCall  */
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
#define YYLAST   446

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   321


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   175,   175,   175,   192,   198,   204,   210,   216,   222,
     230,   234,   237,   243,   249,   255,   259,   263,   269,   273,
     277,   297,   298,   299,   351,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   420,
     421,   424,   426,   430,   430,   459,   460,   462,   464,   467,
     468,   471,   473,   474,   478,   479,   480,   482,   484,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     500,   504,   505,   506,   510,   514,   515,   515,   554,   555,
     559,   563,   564,   570,   571,   573,   575,   576,   581,   586,
     588,   589,   594,   595
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
  "VIRGULE", "OU", "ET", "SUPP", "EGALE", "PASEGALE", "MUL", "$accept",
  "programme", "$@1", "type", "tableau", "type_Struct", "valeur",
  "variable", "expression", "incrementation", "declarations",
  "declaration", "$@2", "functions", "fonction", "parametres", "parametre",
  "instructions", "instruction", "read", "write", "retourner",
  "assignment", "$@3", "condition", "loop", "corps", "elsebloc", "call",
  "parametresCall", "parametreCall", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-104)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -104,    13,  -104,  -104,     7,     5,   -13,   395,  -104,  -104,
    -104,  -104,  -104,    27,  -104,  -104,    15,  -104,     0,   131,
     406,    51,    36,    38,    47,    40,    41,  -104,   242,    48,
      57,    60,    53,    39,   406,    78,    92,  -104,  -104,  -104,
      65,    93,    94,    98,   100,   110,  -104,  -104,   101,    86,
      88,    46,    89,    29,    84,  -104,    90,  -104,  -104,  -104,
      91,  -104,  -104,  -104,    96,  -104,  -104,  -104,   256,   406,
     116,   115,  -104,    97,   128,   110,   109,   -18,   113,   110,
    -104,  -104,   110,  -104,  -104,  -104,  -104,     4,  -104,  -104,
     314,   110,    78,    92,   133,   130,   142,   295,   123,  -104,
    -104,  -104,   295,  -104,  -104,  -104,  -104,  -104,  -104,   256,
     155,   383,  -104,  -104,    58,   134,   -11,   165,   166,   354,
     132,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   157,  -104,  -104,   171,   137,
     167,  -104,     3,   314,   148,   294,   149,   131,  -104,  -104,
    -104,   256,   180,   160,   174,   170,   172,  -104,   380,    37,
     380,   314,    37,   -35,   354,   354,   354,   314,   314,   314,
     334,   354,   256,  -104,   133,  -104,   173,  -104,  -104,  -104,
     293,  -104,   158,  -104,   191,  -104,  -104,    55,  -104,  -104,
    -104,   194,   181,   256,   201,  -104,   208,  -104,  -104,   110,
     256,   182,  -104,   256,    55,  -104
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
       0,    60,    63,    64,     0,    55,    56,    54,     0,    51,
       0,     0,    41,     0,     0,     0,     0,     0,     0,     0,
      16,    17,     0,    14,    15,    12,    13,    20,    21,    22,
      74,     0,    55,    56,    89,     0,     0,     0,    43,    39,
      40,    67,     0,    68,    69,    41,    84,    50,    52,     0,
       0,     0,    44,     3,     0,     0,     0,     0,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,    93,     0,    91,
       0,    19,    20,    76,     0,     0,     0,    57,    49,    10,
      11,     0,     0,     0,     0,     0,     0,    30,    23,    26,
      24,    25,    27,    28,    31,    32,    34,    35,    36,    38,
      37,    33,     0,    88,    89,    18,     0,    79,    75,    78,
       0,    81,     0,    73,     0,    72,    70,    85,    90,    77,
      83,     0,     0,     0,     0,    80,     0,    71,    86,     0,
       0,     0,    82,     0,    85,    87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -104,  -104,  -104,    -2,  -104,  -104,   -87,   -28,   -71,  -104,
     -37,   -16,  -104,  -104,  -104,    -4,    -5,    95,   -27,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,  -103,    32,   -78,    66,
    -104
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    52,    25,    26,    88,    89,    90,    54,
      19,    55,    73,     4,    14,    32,    56,    28,   106,    58,
      59,    60,    61,   176,    62,    63,   107,   195,    64,   138,
     139
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    57,    13,    27,   114,    17,   148,   136,   119,   116,
       5,   120,   124,     3,   153,    33,     6,    24,    31,   144,
     135,   130,   131,   117,   146,    15,   143,    94,    16,    33,
      70,   145,    31,    95,    95,   111,    18,    96,    96,    20,
      53,    21,     7,     8,     9,    10,    11,    12,   181,   154,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    33,   108,   137,    31,   147,   187,
      94,    99,   100,   193,   194,    34,    95,    35,    68,    36,
      96,    53,   122,   151,   124,   125,   126,   136,    37,    65,
     198,    38,    39,   130,   131,    27,    97,   202,    66,    69,
     204,    67,   121,   122,   123,   124,   125,   126,    71,    24,
     127,   128,    72,   129,   130,   131,    74,    75,    76,   132,
     133,   134,    77,    53,    78,    91,    79,    92,   201,    93,
      98,    27,    80,    81,    82,   101,    83,    84,    85,    86,
     102,   109,   103,   110,    53,    24,   137,   104,   112,   113,
     115,    87,    53,    57,   118,    80,    81,   157,   140,    83,
      84,    85,    86,    22,    23,    53,     7,     8,     9,    10,
      11,    12,    53,   -54,    87,    53,   121,   122,   123,   124,
     125,   126,   172,   141,   127,   128,   149,   129,   130,   131,
     155,   156,   152,   132,   133,   134,   173,   174,   175,   177,
     179,   121,   122,   123,   124,   125,   126,   203,   182,   127,
     128,   183,   129,   130,   131,   184,   192,   191,   132,   133,
     134,   185,   196,   186,   189,   199,   121,   122,   123,   124,
     125,   126,   197,   200,   127,   128,   205,   129,   130,   131,
     188,     0,   180,   132,   133,   134,    40,    41,    42,    43,
      44,     0,     0,    45,    46,    47,     0,     0,     0,    48,
       0,    41,    42,    43,    44,     0,     0,    45,    46,    47,
       0,     0,     0,    48,    49,    50,   105,     7,     8,     9,
      10,    11,    12,    51,     0,     0,     0,     0,    49,    50,
       0,     7,     8,     9,    10,    11,    12,    51,    41,    42,
      43,    44,     0,     0,    45,    46,    47,     0,     0,     0,
      48,    79,     0,     0,   190,     0,     0,    80,    81,    82,
       0,    83,    84,    85,    86,    49,    50,     0,     7,     8,
       9,    10,    11,    12,    51,     0,   142,     0,   121,   122,
     123,   124,   125,   126,     0,   178,   127,   128,     0,   129,
     130,   131,     0,     0,     0,   132,   133,   134,   121,   122,
     123,   124,   125,   126,     0,     0,   127,   128,     0,   129,
     130,   131,     0,     0,     0,   132,   133,   134,   121,   122,
     123,   124,   125,   126,     0,     0,   127,   128,     0,   129,
     130,   131,     0,     0,     0,     0,   133,   134,   121,   122,
     123,   124,   125,   126,   150,     0,   127,   128,     0,   129,
     130,   131,     0,     0,     0,    22,    23,   134,     7,     8,
       9,    10,    11,    12,   121,   122,   123,   124,   125,   126,
       7,     8,     9,    10,    11,    12,   130,   131,    29,    30,
       0,     7,     8,     9,    10,    11,    12
};

static const yytype_int16 yycheck[] =
{
      28,    28,     4,    19,    75,     7,   109,    94,    79,    27,
       3,    82,    47,     0,    25,    20,     9,    19,    20,    97,
      91,    56,    57,    41,   102,    20,    97,    24,    41,    34,
      34,   102,    34,    30,    30,    72,     9,    34,    34,    24,
      68,    41,    35,    36,    37,    38,    39,    40,   151,    60,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    69,    69,    94,    69,   105,   172,
      24,    42,    43,    18,    19,    24,    30,    41,    25,    41,
      34,   109,    45,    25,    47,    48,    49,   174,    41,    41,
     193,    51,    51,    56,    57,   111,    50,   200,    41,    60,
     203,    41,    44,    45,    46,    47,    48,    49,    30,   111,
      52,    53,    20,    55,    56,    57,    51,    24,    24,    61,
      62,    63,    24,   151,    24,    24,    16,    41,   199,    41,
      41,   147,    22,    23,    24,    51,    26,    27,    28,    29,
      50,    25,    51,    28,   172,   147,   174,    51,    51,    21,
      41,    41,   180,   180,    41,    22,    23,    25,    28,    26,
      27,    28,    29,    32,    33,   193,    35,    36,    37,    38,
      39,    40,   200,    50,    41,   203,    44,    45,    46,    47,
      48,    49,    25,    41,    52,    53,    31,    55,    56,    57,
      25,    25,    58,    61,    62,    63,    25,    60,    31,    51,
      51,    44,    45,    46,    47,    48,    49,    25,    28,    52,
      53,    51,    55,    56,    57,    41,    25,    59,    61,    62,
      63,    51,    28,    51,    51,    24,    44,    45,    46,    47,
      48,    49,    51,    25,    52,    53,   204,    55,    56,    57,
     174,    -1,   147,    61,    62,    63,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    13,    -1,    -1,    -1,    17,
      -1,     5,     6,     7,     8,    -1,    -1,    11,    12,    13,
      -1,    -1,    -1,    17,    32,    33,    20,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    32,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,     5,     6,
       7,     8,    -1,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    16,    -1,    -1,    21,    -1,    -1,    22,    23,    24,
      -1,    26,    27,    28,    29,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    -1,    41,    -1,    44,    45,
      46,    47,    48,    49,    -1,    51,    52,    53,    -1,    55,
      56,    57,    -1,    -1,    -1,    61,    62,    63,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,    53,    -1,    55,
      56,    57,    -1,    -1,    -1,    61,    62,    63,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,    53,    -1,    55,
      56,    57,    -1,    -1,    -1,    -1,    62,    63,    44,    45,
      46,    47,    48,    49,    21,    -1,    52,    53,    -1,    55,
      56,    57,    -1,    -1,    -1,    32,    33,    63,    35,    36,
      37,    38,    39,    40,    44,    45,    46,    47,    48,    49,
      35,    36,    37,    38,    39,    40,    56,    57,    32,    33,
      -1,    35,    36,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    68,    69,     0,    80,     3,     9,    35,    36,    37,
      38,    39,    40,    70,    81,    20,    41,    70,     9,    77,
      24,    41,    32,    33,    70,    71,    72,    78,    84,    32,
      33,    70,    82,    83,    24,    41,    41,    41,    51,    51,
       4,     5,     6,     7,     8,    11,    12,    13,    17,    32,
      33,    41,    70,    74,    76,    78,    83,    85,    86,    87,
      88,    89,    91,    92,    95,    41,    41,    41,    25,    60,
      82,    30,    20,    79,    51,    24,    24,    24,    24,    16,
      22,    23,    24,    26,    27,    28,    29,    41,    73,    74,
      75,    24,    41,    41,    24,    30,    34,    50,    41,    42,
      43,    51,    50,    51,    51,    20,    85,    93,    82,    25,
      28,    77,    51,    21,    75,    41,    27,    41,    41,    75,
      75,    44,    45,    46,    47,    48,    49,    52,    53,    55,
      56,    57,    61,    62,    63,    75,    73,    74,    96,    97,
      28,    41,    41,    75,    95,    75,    95,    77,    93,    31,
      21,    25,    58,    25,    60,    25,    25,    25,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    25,    25,    60,    31,    90,    51,    51,    51,
      84,    93,    28,    51,    41,    51,    51,    93,    96,    51,
      21,    59,    25,    18,    19,    94,    28,    51,    93,    24,
      25,    75,    93,    25,    93,    94
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    69,    68,    70,    70,    70,    70,    70,    70,
      71,    72,    73,    73,    73,    73,    73,    73,    74,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    76,
      76,    77,    77,    79,    78,    78,    78,    80,    80,    81,
      81,    82,    82,    82,    83,    83,    83,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      86,    87,    87,    87,    88,    89,    90,    89,    89,    89,
      91,    92,    92,    93,    93,    94,    94,    94,    95,    96,
      96,    96,    97,    97
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
       6,     5,     9,     4,     1,     0,     2,     6,     4,     0,
       3,     1,     1,     1
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
#line 175 "parser.y"
    {
        TS = creerTableSymbole();  
        TQ = initialiserTQ() ;
        P = initialiserP();
    }
#line 1454 "parser.tab.c"
    break;

  case 3: /* programme: $@1 functions DEBUT DEB_CORPS declarations instructions FIN SEMICOLON FIN_CORPS  */
#line 180 "parser.y"
                                                                                {
        qC++;
        quad = creer_Q("fin", "", "", "", qC);
        inserer_TQ(TQ, quad); 
        afficherTableSymbole(TS); // afficher TS pour confirmer
        afficherTQ(TQ);  // afficher TQ pour confirmer
        afficherTQDansFichier(TQ, "output.txt");
        printf("\nProgramme accepte.");
    }
#line 1468 "parser.tab.c"
    break;

  case 4: /* type: ENTIER  */
#line 192 "parser.y"
           {
        currentType.baseType = ENTIER;
        currentType.isArray = false;
        currentType.isConst = false;
        (yyval.type) = ENTIER;
    }
#line 1479 "parser.tab.c"
    break;

  case 5: /* type: FLOTTANT  */
#line 198 "parser.y"
               {
        currentType.baseType = FLOTTANT;
        currentType.isArray = false;
        currentType.isConst = false;
        (yyval.type) = FLOTTANT;
    }
#line 1490 "parser.tab.c"
    break;

  case 6: /* type: STRING  */
#line 204 "parser.y"
             {
        currentType.baseType = STRING;
        currentType.isArray = false;
        currentType.isConst = false;
        (yyval.type) = STRING;
    }
#line 1501 "parser.tab.c"
    break;

  case 7: /* type: CHAR  */
#line 210 "parser.y"
           {
        currentType.baseType = CHAR;
        currentType.isArray = false;
        currentType.isConst = false;
        (yyval.type) = CHAR;
    }
#line 1512 "parser.tab.c"
    break;

  case 8: /* type: BOOLEAN  */
#line 216 "parser.y"
              {
        currentType.baseType = BOOLEAN;
        currentType.isArray = false;
        currentType.isConst = false;
        (yyval.type) = BOOLEAN;
    }
#line 1523 "parser.tab.c"
    break;

  case 9: /* type: CONST type  */
#line 222 "parser.y"
                 {
        currentType.isConst = true;
        (yyval.type) = (yyvsp[0].type);
    }
#line 1532 "parser.tab.c"
    break;

  case 12: /* valeur: INT  */
#line 237 "parser.y"
        { 
        (yyval.structure).type = ENTIER;
        char buffer[256];
        sprintf(buffer, "%d", (yyvsp[0].intv));
        (yyval.structure).valeur = strdup(buffer);
    }
#line 1543 "parser.tab.c"
    break;

  case 13: /* valeur: FLOAT  */
#line 243 "parser.y"
            {
        (yyval.structure).type = FLOTTANT;
        char buffer[256];
        sprintf(buffer, "%f", (yyvsp[0].flt));
        (yyval.structure).valeur = strdup(buffer);
    }
#line 1554 "parser.tab.c"
    break;

  case 14: /* valeur: CARACTERE  */
#line 249 "parser.y"
                {
        (yyval.structure).type = CHAR;
        char buffer[256];
        sprintf(buffer, "%c", (yyvsp[0].charv));
        (yyval.structure).valeur = strdup(buffer);
    }
#line 1565 "parser.tab.c"
    break;

  case 15: /* valeur: CHAINE  */
#line 255 "parser.y"
             {
        (yyval.structure).type = STRING;
        (yyval.structure).valeur = strdup((yyvsp[0].str));
    }
#line 1574 "parser.tab.c"
    break;

  case 16: /* valeur: TRUE  */
#line 259 "parser.y"
           {
        (yyval.structure).type = BOOLEAN;
        (yyval.structure).valeur = strdup("true");
    }
#line 1583 "parser.tab.c"
    break;

  case 17: /* valeur: FALSE  */
#line 263 "parser.y"
            {
        (yyval.structure).type = BOOLEAN;
        (yyval.structure).valeur = strdup("false");
    }
#line 1592 "parser.tab.c"
    break;

  case 18: /* variable: ID DEB_TABLEAU INT FIN_TABLEAU  */
#line 269 "parser.y"
                                   {
        (yyval.structure).nom = (yyvsp[-3].str);
        (yyval.structure).type = ENTIER;  // assuming array of integers
    }
#line 1601 "parser.tab.c"
    break;

  case 19: /* variable: ID POINTEUR ID  */
#line 273 "parser.y"
                     {
        (yyval.structure).nom = (yyvsp[-2].str);
        (yyval.structure).type = ENTIER;  // modify based on your needs
    }
#line 1610 "parser.tab.c"
    break;

  case 20: /* variable: ID  */
#line 277 "parser.y"
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
#line 1633 "parser.tab.c"
    break;

  case 23: /* expression: expression PLUS expression  */
#line 299 "parser.y"
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
#line 1690 "parser.tab.c"
    break;

  case 24: /* expression: expression MOINS expression  */
#line 351 "parser.y"
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
#line 1747 "parser.tab.c"
    break;

  case 43: /* $@2: %empty  */
#line 430 "parser.y"
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
#line 1781 "parser.tab.c"
    break;

  case 45: /* declaration: tableau SEMICOLON  */
#line 459 "parser.y"
                        {printf("declaration correcte syntaxiquement\n");}
#line 1787 "parser.tab.c"
    break;

  case 46: /* declaration: type_Struct SEMICOLON  */
#line 460 "parser.y"
                            {printf("declaration correcte syntaxiquement\n");}
#line 1793 "parser.tab.c"
    break;

  case 49: /* fonction: type FONCTION ID PAR_OUV parametres PAR_FERM corps  */
#line 467 "parser.y"
                                                       {printf("fonction correcte syntaxiquement\n");}
#line 1799 "parser.tab.c"
    break;

  case 50: /* fonction: FONCTION ID PAR_OUV parametres PAR_FERM corps  */
#line 468 "parser.y"
                                                    {printf("fonction correcte syntaxiquement\n");}
#line 1805 "parser.tab.c"
    break;

  case 52: /* parametres: parametre VIRGULE parametres  */
#line 473 "parser.y"
                                   {printf("parametres correcte syntaxiquement\n");}
#line 1811 "parser.tab.c"
    break;

  case 56: /* parametre: ENREGISTREMENT ID  */
#line 480 "parser.y"
                        {printf("parametre correcte syntaxiquement\n");}
#line 1817 "parser.tab.c"
    break;

  case 70: /* read: INPUT PAR_OUV ID PAR_FERM SEMICOLON  */
#line 500 "parser.y"
                                        {printf("read correcte syntaxiquement\n");}
#line 1823 "parser.tab.c"
    break;

  case 73: /* write: PRINT PAR_OUV CHAINE PAR_FERM SEMICOLON  */
#line 506 "parser.y"
                                            {printf("write correcte syntaxiquement\n");}
#line 1829 "parser.tab.c"
    break;

  case 74: /* retourner: RETURN expression  */
#line 510 "parser.y"
                      {printf("retourner correcte syntaxiquement\n");}
#line 1835 "parser.tab.c"
    break;

  case 76: /* $@3: %empty  */
#line 515 "parser.y"
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
                switch((yyvsp[0].structure).type) {
                    case ENTIER: exprType = TYPE_ENTIER; break;
                    case FLOTTANT: exprType = TYPE_FLOTTANT; break;
                    case CHAR: exprType = TYPE_CHAR; break;
                    case STRING: exprType = TYPE_STRING; break;
                    case BOOLEAN: exprType = TYPE_BOOLEAN; break;
                    default: exprType = TYPE_ENTIER;
                }
                
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
#line 1879 "parser.tab.c"
    break;

  case 80: /* condition: IF PAR_OUV expression PAR_FERM corps elsebloc  */
#line 559 "parser.y"
                                                   {printf("condition correcte syntaxiquement\n");}
#line 1885 "parser.tab.c"
    break;

  case 81: /* loop: WHILE PAR_OUV expression PAR_FERM corps  */
#line 563 "parser.y"
                                              {printf("condition correcte syntaxiquement\n");}
#line 1891 "parser.tab.c"
    break;

  case 82: /* loop: FOR PAR_OUV ID FROM INT TO INT PAR_FERM corps  */
#line 565 "parser.y"
    {
        printf("For loop recognized\n");
    }
#line 1899 "parser.tab.c"
    break;

  case 91: /* parametresCall: parametreCall  */
#line 590 "parser.y"
    {printf("parametres de l'appel du fonction correcte syntaxiquement\n");}
#line 1905 "parser.tab.c"
    break;

  case 93: /* parametreCall: variable  */
#line 595 "parser.y"
               {printf("parametre correcte syntaxiquement\n");}
#line 1911 "parser.tab.c"
    break;


#line 1915 "parser.tab.c"

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

#line 598 "parser.y"


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

