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
    char* currentFunctionCalled=NULL;
    ParametresList* currentParametresList;
    int sauvLabel;
    char* saveFunctionDec=NULL;
    bool itReturn=false;

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
ParametresList* creerParametresList() {
    ParametresList* list = (ParametresList*)malloc(sizeof(ParametresList));
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

bool ajouterParametreUnion(ParametresList* list, const char* nom, const char* type) {
    // Check if the parameter already exists
    ParametreNode* current = list->head;
    while (current) {
        if (strcmp(current->parametre.nom, nom) == 0) {
            return false; // Parameter already exists
        }
        current = current->next;
    }

    // Add the new parameter
    ParametreNode* newNode = (ParametreNode*)malloc(sizeof(ParametreNode));
    newNode->parametre.nom = strdup(nom);
    newNode->parametre.type = strdup(type);
    newNode->next = NULL;

    if (list->tail) {
        list->tail->next = newNode;
    } else {
        list->head = newNode;
    }
    list->tail = newNode;
    list->count++;
    return true;
}

void libererParametresList(ParametresList* list) {
    ParametreNode* current = list->head;
    while (current) {
        ParametreNode* next = current->next;
        free(current->parametre.nom);
        free(current->parametre.type);
        free(current);
        current = next;
    }
    free(list);
}



#line 231 "parser.tab.c"

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
  YYSYMBOL_82_3 = 82,                      /* $@3  */
  YYSYMBOL_declarationfonction = 83,       /* declarationfonction  */
  YYSYMBOL_parametres = 84,                /* parametres  */
  YYSYMBOL_parametre = 85,                 /* parametre  */
  YYSYMBOL_instructions = 86,              /* instructions  */
  YYSYMBOL_instruction = 87,               /* instruction  */
  YYSYMBOL_read = 88,                      /* read  */
  YYSYMBOL_write = 89,                     /* write  */
  YYSYMBOL_retourner = 90,                 /* retourner  */
  YYSYMBOL_assignment = 91,                /* assignment  */
  YYSYMBOL_92_4 = 92,                      /* $@4  */
  YYSYMBOL_93_5 = 93,                      /* $@5  */
  YYSYMBOL_condition = 94,                 /* condition  */
  YYSYMBOL_ifstatement = 95,               /* ifstatement  */
  YYSYMBOL_loop = 96,                      /* loop  */
  YYSYMBOL_corps = 97,                     /* corps  */
  YYSYMBOL_elsebloc = 98,                  /* elsebloc  */
  YYSYMBOL_elsestatement = 99,             /* elsestatement  */
  YYSYMBOL_elifstatement = 100,            /* elifstatement  */
  YYSYMBOL_elifkey = 101,                  /* elifkey  */
  YYSYMBOL_call = 102,                     /* call  */
  YYSYMBOL_103_6 = 103,                    /* $@6  */
  YYSYMBOL_parametresCall = 104,           /* parametresCall  */
  YYSYMBOL_parametreCall = 105             /* parametreCall  */
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
#define YYLAST   416

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

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
       0,   238,   238,   238,   255,   261,   267,   273,   279,   285,
     293,   297,   300,   306,   312,   318,   322,   326,   332,   336,
     340,   360,   361,   362,   412,   462,   512,   571,   616,   662,
     663,   664,   665,   666,   667,   668,   722,   723,   724,   728,
     773,   820,   822,   826,   826,   855,   856,   857,   893,   895,
     898,   898,   933,   966,   990,   993,  1001,  1013,  1028,  1029,
    1031,  1033,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,
    1044,  1045,  1046,  1049,  1053,  1054,  1055,  1059,  1089,  1089,
    1152,  1152,  1210,  1223,  1239,  1240,  1246,  1247,  1250,  1257,
    1265,  1269,  1282,  1296,  1312,  1311,  1374,  1376,  1390,  1405,
    1406
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
  "declaration", "$@2", "functions", "fonction", "$@3",
  "declarationfonction", "parametres", "parametre", "instructions",
  "instruction", "read", "write", "retourner", "assignment", "$@4", "$@5",
  "condition", "ifstatement", "loop", "corps", "elsebloc", "elsestatement",
  "elifstatement", "elifkey", "call", "$@6", "parametresCall",
  "parametreCall", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-127)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-95)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -127,    17,  -127,  -127,     3,     2,    -5,   356,  -127,  -127,
    -127,  -127,  -127,    38,  -127,    41,  -127,  -127,  -127,    28,
     367,   376,  -127,    30,    31,    34,   -16,  -127,    37,    47,
      50,    55,    63,  -127,   211,  -127,  -127,  -127,  -127,   367,
      51,    69,    18,  -127,  -127,    64,    75,    92,    93,    94,
     264,  -127,  -127,   106,    40,    -8,    84,  -127,  -127,  -127,
    -127,    85,  -127,  -127,   225,  -127,    89,   225,  -127,   113,
    -127,   264,   108,   123,   264,   111,   -22,   119,   264,  -127,
    -127,   264,  -127,  -127,  -127,  -127,   -10,  -127,  -127,   275,
     264,   133,   125,   288,   143,  -127,  -127,  -127,  -127,  -127,
    -127,    27,  -127,  -127,   137,   344,    76,  -127,  -127,    48,
     122,     6,   144,   152,   315,   101,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     126,   153,  -127,    -9,   275,  -127,    57,   376,  -127,  -127,
    -127,   225,   225,   161,  -127,  -127,  -127,   225,   158,   140,
     164,   159,   160,  -127,   341,   145,   341,   275,   145,   -29,
     315,   315,   315,   275,   275,   275,   295,   315,  -127,  -127,
     169,   170,  -127,  -127,     7,  -127,   262,  -127,    27,   264,
    -127,   150,  -127,   200,  -127,  -127,  -127,  -127,  -127,    57,
    -127,  -127,   151,   198,   176,  -127,  -127,   204,  -127,   225,
    -127
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,    48,     1,     0,     0,     0,     0,     4,     5,
       6,     7,     8,     0,    49,     0,    41,    53,     9,     0,
      54,    60,    52,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,    42,     0,    58,    59,    57,    50,     0,
       0,     0,    43,    45,    46,     0,     0,     0,     0,     0,
       0,    64,    65,     0,    20,     0,     0,    62,    61,    68,
      69,     0,    63,    66,     0,    67,     0,     0,    55,     0,
      41,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,     0,    14,    15,    12,    13,    20,    21,    22,    77,
       0,     0,     0,     0,     0,    39,    40,    70,    71,    41,
      87,    88,    72,    51,     0,     0,     0,    44,     3,     0,
       0,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    20,    78,    80,    96,    60,    91,    93,
      82,     0,     0,     0,    10,    11,    47,     0,     0,     0,
       0,     0,     0,    30,    23,    26,    24,    25,    27,    28,
      31,    32,    34,    35,    36,    38,    37,    33,    83,    18,
       0,     0,    99,   100,     0,    98,     0,    89,    88,     0,
      84,     0,    76,     0,    75,    73,    79,    81,    95,     0,
      86,    90,     0,     0,     0,    97,    92,     0,    74,     0,
      85
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,     9,  -127,  -127,  -126,   -34,   -67,  -127,
     -62,   -18,  -127,  -127,  -127,  -127,  -127,  -127,   195,    98,
     -33,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
     -65,    61,  -127,  -127,  -127,   147,  -127,  -127,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    30,    31,    32,    87,    88,    89,    56,
      21,    57,    72,     4,    14,    67,    15,    26,    27,    34,
     100,    59,    60,    61,    62,   170,   171,    63,    64,    65,
     101,   140,   141,   142,   143,    66,    94,   174,   175
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    58,   103,    33,   106,   111,     5,   109,   105,    38,
     172,   114,     6,    13,   115,   -94,    18,     3,   119,   112,
      91,    91,    16,   130,    92,    92,   134,   125,   126,    25,
      55,   149,   188,    55,    95,    96,    17,   137,     7,     8,
       9,    10,    11,    12,    39,   138,   139,    19,    25,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   172,   -94,    20,   150,   189,    71,    22,
      91,    35,    36,   147,    92,    37,   177,   178,    40,    79,
      80,    69,   180,    82,    83,    84,    85,    33,    41,    70,
      93,    42,   116,   117,   118,   119,   120,   121,    86,    74,
     122,   123,   173,   124,   125,   126,    43,    55,    55,   127,
     128,   129,   192,    55,    44,    73,    75,    76,    77,    33,
     116,   117,   118,   119,   120,   121,   153,   146,   122,   123,
      90,   124,   125,   126,   200,    97,    98,   127,   128,   129,
     102,   104,    55,    58,   108,   116,   117,   118,   119,   120,
     121,   168,   110,   122,   123,   173,   124,   125,   126,   107,
     113,   131,   127,   128,   129,    55,   132,   136,   144,   151,
     116,   117,   118,   119,   120,   121,   196,   152,   122,   123,
     148,   124,   125,   126,   169,   179,   181,   127,   128,   129,
     117,   182,   119,   120,   121,   116,   117,   118,   119,   120,
     121,   125,   126,   122,   123,   183,   124,   125,   126,   193,
     184,   185,   127,   128,   129,    45,    46,    47,    48,    49,
     186,   187,    50,    51,    52,   194,   197,   198,    53,   199,
      46,    47,    48,    49,    68,   176,    50,    51,    52,   191,
     135,   195,    53,    28,    29,    99,     7,     8,     9,    10,
      11,    12,    54,     0,     0,     0,     0,    28,    29,     0,
       7,     8,     9,    10,    11,    12,    54,    46,    47,    48,
      49,     0,     0,    50,    51,    52,     0,     0,     0,    53,
      78,     0,     0,   190,     0,     0,    79,    80,    81,     0,
      82,    83,    84,    85,    28,    29,     0,     7,     8,     9,
      10,    11,    12,    54,    78,    86,     0,     0,     0,     0,
      79,    80,    81,     0,    82,    83,    84,    85,     0,   116,
     117,   118,   119,   120,   121,     0,     0,   122,   123,   133,
     124,   125,   126,     0,     0,     0,   127,   128,   129,   116,
     117,   118,   119,   120,   121,     0,     0,   122,   123,     0,
     124,   125,   126,     0,     0,     0,     0,   128,   129,   116,
     117,   118,   119,   120,   121,   145,     0,   122,   123,     0,
     124,   125,   126,     0,     0,     0,    28,    29,   129,     7,
       8,     9,    10,    11,    12,   116,   117,   118,   119,   120,
     121,     7,     8,     9,    10,    11,    12,   125,   126,    23,
      24,     0,     7,     8,     9,    10,    11,    12,    28,    29,
       0,     7,     8,     9,    10,    11,    12
};

static const yytype_int16 yycheck[] =
{
      34,    34,    67,    21,    71,    27,     3,    74,    70,    25,
     136,    78,     9,     4,    81,    24,     7,     0,    47,    41,
      30,    30,    20,    90,    34,    34,    93,    56,    57,    20,
      64,    25,    25,    67,    42,    43,    41,    99,    35,    36,
      37,    38,    39,    40,    60,    18,    19,     9,    39,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   189,    24,    24,    60,    60,    50,    41,
      30,    41,    41,    25,    34,    41,   141,   142,    41,    22,
      23,    30,   147,    26,    27,    28,    29,   105,    41,    20,
      50,    41,    44,    45,    46,    47,    48,    49,    41,    24,
      52,    53,   136,    55,    56,    57,    51,   141,   142,    61,
      62,    63,   179,   147,    51,    51,    24,    24,    24,   137,
      44,    45,    46,    47,    48,    49,    25,    51,    52,    53,
      24,    55,    56,    57,   199,    51,    51,    61,    62,    63,
      51,    28,   176,   176,    21,    44,    45,    46,    47,    48,
      49,    25,    41,    52,    53,   189,    55,    56,    57,    51,
      41,    28,    61,    62,    63,   199,    41,    24,    31,    25,
      44,    45,    46,    47,    48,    49,    25,    25,    52,    53,
      58,    55,    56,    57,    31,    24,    28,    61,    62,    63,
      45,    51,    47,    48,    49,    44,    45,    46,    47,    48,
      49,    56,    57,    52,    53,    41,    55,    56,    57,    59,
      51,    51,    61,    62,    63,     4,     5,     6,     7,     8,
      51,    51,    11,    12,    13,    25,    28,    51,    17,    25,
       5,     6,     7,     8,    39,   137,    11,    12,    13,   178,
      93,   189,    17,    32,    33,    20,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,     5,     6,     7,
       8,    -1,    -1,    11,    12,    13,    -1,    -1,    -1,    17,
      16,    -1,    -1,    21,    -1,    -1,    22,    23,    24,    -1,
      26,    27,    28,    29,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    16,    41,    -1,    -1,    -1,    -1,
      22,    23,    24,    -1,    26,    27,    28,    29,    -1,    44,
      45,    46,    47,    48,    49,    -1,    -1,    52,    53,    41,
      55,    56,    57,    -1,    -1,    -1,    61,    62,    63,    44,
      45,    46,    47,    48,    49,    -1,    -1,    52,    53,    -1,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,    44,
      45,    46,    47,    48,    49,    21,    -1,    52,    53,    -1,
      55,    56,    57,    -1,    -1,    -1,    32,    33,    63,    35,
      36,    37,    38,    39,    40,    44,    45,    46,    47,    48,
      49,    35,    36,    37,    38,    39,    40,    56,    57,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    32,    33,
      -1,    35,    36,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    68,    69,     0,    80,     3,     9,    35,    36,    37,
      38,    39,    40,    70,    81,    83,    20,    41,    70,     9,
      24,    77,    41,    32,    33,    70,    84,    85,    32,    33,
      70,    71,    72,    78,    86,    41,    41,    41,    25,    60,
      41,    41,    41,    51,    51,     4,     5,     6,     7,     8,
      11,    12,    13,    17,    41,    74,    76,    78,    87,    88,
      89,    90,    91,    94,    95,    96,   102,    82,    85,    30,
      20,    50,    79,    51,    24,    24,    24,    24,    16,    22,
      23,    24,    26,    27,    28,    29,    41,    73,    74,    75,
      24,    30,    34,    50,   103,    42,    43,    51,    51,    20,
      87,    97,    51,    97,    28,    77,    75,    51,    21,    75,
      41,    27,    41,    41,    75,    75,    44,    45,    46,    47,
      48,    49,    52,    53,    55,    56,    57,    61,    62,    63,
      75,    28,    41,    41,    75,   102,    24,    77,    18,    19,
      98,    99,   100,   101,    31,    21,    51,    25,    58,    25,
      60,    25,    25,    25,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    25,    31,
      92,    93,    73,    74,   104,   105,    86,    97,    97,    24,
      97,    28,    51,    41,    51,    51,    51,    51,    25,    60,
      21,    98,    75,    59,    25,   105,    25,    28,    51,    25,
      97
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    69,    68,    70,    70,    70,    70,    70,    70,
      71,    72,    73,    73,    73,    73,    73,    73,    74,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    76,
      76,    77,    77,    79,    78,    78,    78,    78,    80,    80,
      82,    81,    83,    83,    84,    84,    84,    85,    85,    85,
      86,    86,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    88,    89,    89,    89,    90,    92,    91,
      93,    91,    94,    95,    96,    96,    97,    97,    98,    98,
      98,    99,   100,   101,   103,   102,   104,   104,   104,   105,
     105
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     9,     1,     1,     1,     1,     1,     2,
       5,     5,     1,     1,     1,     1,     1,     1,     4,     3,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     0,     2,     0,     4,     2,     2,     5,     0,     2,
       0,     6,     3,     2,     0,     3,     1,     2,     2,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     5,     7,     5,     5,     2,     0,     5,
       0,     5,     3,     4,     5,     9,     4,     1,     0,     2,
       3,     1,     4,     1,     0,     5,     0,     3,     1,     1,
       1
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
#line 238 "parser.y"
    {
        TS = creerTableSymbole();  
        TQ = initialiserTQ() ;
        P = initialiserP();

    }
#line 1515 "parser.tab.c"
    break;

  case 3: /* programme: $@1 functions DEBUT DEB_CORPS declarations instructions FIN SEMICOLON FIN_CORPS  */
#line 244 "parser.y"
                                                                                {
        quad = creer_Q("fin", "", "", "", qC);
        inserer_TQ(TQ, quad); 
        afficherTableSymbole(TS); // afficher TS pour confirmer
        afficherTQ(TQ);  // afficher TQ pour confirmer
        afficherTQDansFichier(TQ, "output.txt");
        printf("\nProgramme accepte.");
    }
#line 1528 "parser.tab.c"
    break;

  case 4: /* type: ENTIER  */
#line 255 "parser.y"
           {
        currentType.baseType = ENTIER;
        currentType.isArray = false;
        currentType.isConst = false;
        (yyval.type) = ENTIER;
    }
#line 1539 "parser.tab.c"
    break;

  case 5: /* type: FLOTTANT  */
#line 261 "parser.y"
               {
        currentType.baseType = FLOTTANT;
        currentType.isArray = false;
        currentType.isConst = false;
        (yyval.type) = FLOTTANT;
    }
#line 1550 "parser.tab.c"
    break;

  case 6: /* type: STRING  */
#line 267 "parser.y"
             {
        currentType.baseType = STRING;
        currentType.isArray = false;
        currentType.isConst = false;
        (yyval.type) = STRING;
    }
#line 1561 "parser.tab.c"
    break;

  case 7: /* type: CHAR  */
#line 273 "parser.y"
           {
        currentType.baseType = CHAR;
        currentType.isArray = false;
        currentType.isConst = false;
        (yyval.type) = CHAR;
    }
#line 1572 "parser.tab.c"
    break;

  case 8: /* type: BOOLEAN  */
#line 279 "parser.y"
              {
        currentType.baseType = BOOLEAN;
        currentType.isArray = false;
        currentType.isConst = false;
        (yyval.type) = BOOLEAN;
    }
#line 1583 "parser.tab.c"
    break;

  case 9: /* type: CONST type  */
#line 285 "parser.y"
                 {
        currentType.isConst = true;
        (yyval.type) = (yyvsp[0].type);
    }
#line 1592 "parser.tab.c"
    break;

  case 12: /* valeur: INT  */
#line 300 "parser.y"
        { 
        (yyval.structure).type = ENTIER;
        char buffer[256];
        sprintf(buffer, "%d", (yyvsp[0].intv));
        (yyval.structure).valeur = strdup(buffer);
    }
#line 1603 "parser.tab.c"
    break;

  case 13: /* valeur: FLOAT  */
#line 306 "parser.y"
            {
        (yyval.structure).type = FLOTTANT;
        char buffer[256];
        sprintf(buffer, "%f", (yyvsp[0].flt));
        (yyval.structure).valeur = strdup(buffer);
    }
#line 1614 "parser.tab.c"
    break;

  case 14: /* valeur: CARACTERE  */
#line 312 "parser.y"
                {
        (yyval.structure).type = CHAR;
        char buffer[256];
        sprintf(buffer, "%c", (yyvsp[0].charv));
        (yyval.structure).valeur = strdup(buffer);
    }
#line 1625 "parser.tab.c"
    break;

  case 15: /* valeur: CHAINE  */
#line 318 "parser.y"
             {
        (yyval.structure).type = STRING;
        (yyval.structure).valeur = strdup((yyvsp[0].str));
    }
#line 1634 "parser.tab.c"
    break;

  case 16: /* valeur: TRUE  */
#line 322 "parser.y"
           {
        (yyval.structure).type = BOOLEAN;
        (yyval.structure).valeur = strdup("true");
    }
#line 1643 "parser.tab.c"
    break;

  case 17: /* valeur: FALSE  */
#line 326 "parser.y"
            {
        (yyval.structure).type = BOOLEAN;
        (yyval.structure).valeur = strdup("false");
    }
#line 1652 "parser.tab.c"
    break;

  case 18: /* variable: ID DEB_TABLEAU INT FIN_TABLEAU  */
#line 332 "parser.y"
                                   {
        (yyval.structure).nom = (yyvsp[-3].str);
        (yyval.structure).type = ENTIER;  // assuming array of integers
    }
#line 1661 "parser.tab.c"
    break;

  case 19: /* variable: ID POINTEUR ID  */
#line 336 "parser.y"
                     {
        (yyval.structure).nom = (yyvsp[-2].str);
        (yyval.structure).type = ENTIER;  // modify based on your needs
    }
#line 1670 "parser.tab.c"
    break;

  case 20: /* variable: ID  */
#line 340 "parser.y"
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
#line 1693 "parser.tab.c"
    break;

  case 23: /* expression: expression PLUS expression  */
#line 362 "parser.y"
                                 {
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
#line 1748 "parser.tab.c"
    break;

  case 24: /* expression: expression MOINS expression  */
#line 412 "parser.y"
                                  {
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
#line 1803 "parser.tab.c"
    break;

  case 25: /* expression: expression MULT expression  */
#line 462 "parser.y"
                                 {
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
        // Perform multiplication based on types
        if ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == ENTIER) {
            int result = atoi(val1) * atoi(val2);
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = ENTIER;
        } else if ((yyvsp[-2].structure).type == FLOTTANT || (yyvsp[0].structure).type == FLOTTANT) {
            float result = atof(val1) * atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = FLOTTANT;
        } else if (((yyvsp[-2].structure).type == FLOTTANT && (yyvsp[0].structure).type == ENTIER) || ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == FLOTTANT)) {
            float result = atof(val1) * atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = FLOTTANT;
        } else {
            semanticError("Invalid types for multiplication", line);
        }

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        (yyval.structure).nom=resultVarName;
        quad = creer_Q("*", 
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
#line 1858 "parser.tab.c"
    break;

  case 26: /* expression: expression DIV expression  */
#line 512 "parser.y"
                                {
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
        // Perform division based on types
        if ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == ENTIER) {
            if (atoi(val2) == 0) {
                semanticError("Division by zero", line);
            }
            int result = atoi(val1) / atoi(val2);
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = ENTIER;
        } else if ((yyvsp[-2].structure).type == FLOTTANT || (yyvsp[0].structure).type == FLOTTANT) {
            if (atof(val2) == 0.0) {
                semanticError("Division by zero", line);
            }
            float result = atof(val1) / atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = FLOTTANT;
        } else if (((yyvsp[-2].structure).type == FLOTTANT && (yyvsp[0].structure).type == ENTIER) || ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == FLOTTANT)) {
            if (atof(val2) == 0.0) {
                semanticError("Division by zero", line);
            }
            float result = atof(val1) / atof(val2);
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = FLOTTANT;
        } else {
            semanticError("Invalid types for division", line);
        }

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        (yyval.structure).nom=resultVarName;
        quad = creer_Q("/", 
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
#line 1922 "parser.tab.c"
    break;

  case 27: /* expression: expression MOD expression  */
#line 571 "parser.y"
                                {
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
        // Perform modulo based on types
        if ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == ENTIER) {
            if (atoi(val2) == 0) {
                semanticError("Modulo by zero", line);
            }
            int result = atoi(val1) % atoi(val2);
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = ENTIER;
        } else {
            semanticError("Invalid types for modulo", line);
        }

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        (yyval.structure).nom=resultVarName;
        quad = creer_Q("%", 
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
#line 1972 "parser.tab.c"
    break;

  case 28: /* expression: expression PUISS expression  */
#line 616 "parser.y"
                                  {
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
        // Perform power based on types
        if ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == ENTIER) {
            int result = pow(atoi(val1), atoi(val2));
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = ENTIER;
        } else if ((yyvsp[-2].structure).type == FLOTTANT || (yyvsp[0].structure).type == FLOTTANT) {
            float result = pow(atof(val1), atof(val2));
            sprintf((yyval.structure).valeur, "%f", result);
            (yyval.structure).type = FLOTTANT;
        } else {
            semanticError("Invalid types for power", line);
        }

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        (yyval.structure).nom=resultVarName;
        quad = creer_Q("^", 
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
#line 2023 "parser.tab.c"
    break;

  case 35: /* expression: expression EQUAL expression  */
#line 668 "parser.y"
                                  {
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
        // Perform equality check based on types
        if ((yyvsp[-2].structure).type == ENTIER && (yyvsp[0].structure).type == ENTIER) {
            bool result = atoi(val1) == atoi(val2);
            sprintf((yyval.structure).valeur, "%s", result ? "true" : "false");
            (yyval.structure).type = BOOLEAN;
        } else if ((yyvsp[-2].structure).type == FLOTTANT || (yyvsp[0].structure).type == FLOTTANT) {
            bool result = atof(val1) == atof(val2);
            sprintf((yyval.structure).valeur, "%s", result ? "true" : "false");
            (yyval.structure).type = BOOLEAN;
        } else if ((yyvsp[-2].structure).type == CHAR && (yyvsp[0].structure).type == CHAR) {
            bool result = val1[0] == val2[0];
            sprintf((yyval.structure).valeur, "%s", result ? "true" : "false");
            (yyval.structure).type = BOOLEAN;
        } else if ((yyvsp[-2].structure).type == STRING && (yyvsp[0].structure).type == STRING) {
            bool result = strcmp(val1, val2) == 0;
            sprintf((yyval.structure).valeur, "%s", result ? "true" : "false");
            (yyval.structure).type = BOOLEAN;
        } else {
            semanticError("Invalid types for equality check", line);
        }

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R", qC);
        (yyval.structure).nom = resultVarName;
        quad = creer_Q("==", 
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
#line 2082 "parser.tab.c"
    break;

  case 39: /* incrementation: variable INCREM  */
#line 728 "parser.y"
                    {

        char bff[255]; 
        Symbole* found1;
        
        // Initialize result structure
        (yyval.structure).nom = NULL;
        (yyval.structure).valeur = malloc(255);
        if ((yyval.structure).valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get value for operand
        char *val1;
        val1 = (yyvsp[-1].structure).valeur;        
        // Perform addition based on types
        if ((yyvsp[-1].structure).type == ENTIER ) {
            int result = atoi(val1) + 1;
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = ENTIER;
        } else if ((yyvsp[-1].structure).type == FLOTTANT ) {
            float result = atof(val1) + 1;
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
        quad = creer_Q("++", 
                      (yyvsp[-1].structure).nom ? (yyvsp[-1].structure).nom : (yyvsp[-1].structure).valeur,
                      "",
                      (yyval.structure).nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
#line 2132 "parser.tab.c"
    break;

  case 40: /* incrementation: variable DECREM  */
#line 774 "parser.y"
    {
        char bff[255]; 
        Symbole* found1;
        
        // Initialize result structure
        (yyval.structure).nom = NULL;
        (yyval.structure).valeur = malloc(255);
        if ((yyval.structure).valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get value for operand
        char *val1;
        val1 = (yyvsp[-1].structure).valeur;        
        // Perform subtraction based on types
        if ((yyvsp[-1].structure).type == ENTIER ) {
            int result = atoi(val1) - 1;
            sprintf((yyval.structure).valeur, "%d", result);
            (yyval.structure).type = ENTIER;
        } else if ((yyvsp[-1].structure).type == FLOTTANT ) {
            float result = atof(val1) - 1;
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
        quad = creer_Q("--", 
                      (yyvsp[-1].structure).nom ? (yyvsp[-1].structure).nom : (yyvsp[-1].structure).valeur,
                      "",
                      (yyval.structure).nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
#line 2181 "parser.tab.c"
    break;

  case 43: /* $@2: %empty  */
#line 826 "parser.y"
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
#line 2215 "parser.tab.c"
    break;

  case 45: /* declaration: tableau SEMICOLON  */
#line 855 "parser.y"
                        {printf("declaration correcte syntaxiquement\n");}
#line 2221 "parser.tab.c"
    break;

  case 46: /* declaration: type_Struct SEMICOLON  */
#line 856 "parser.y"
                            {printf("declaration correcte syntaxiquement\n");}
#line 2227 "parser.tab.c"
    break;

  case 47: /* declaration: type ID ASSIGN expression SEMICOLON  */
#line 857 "parser.y"
                                          {
        Symbole* found;
        if (rechercherSymbole(TS, (yyvsp[-3].str), &found)) {
            semanticError("Variable already declared", line);
        }
        
        // Convert the type token to string
        char* typeStr;
        switch((yyvsp[-4].type)) {
            case ENTIER: typeStr = TYPE_ENTIER; break;
            case FLOTTANT: typeStr = TYPE_FLOTTANT; break;
            case CHAR: typeStr = TYPE_CHAR; break;
            case STRING: typeStr = TYPE_STRING; break;
            case BOOLEAN: typeStr = TYPE_BOOLEAN; break;
            default: typeStr = TYPE_ENTIER; // default case
        }
        
        // Check if the expression is valid for the type
        if (!isValidLiteralForType((yyvsp[-1].structure).valeur, typeStr)) {
            semanticError("Invalid literal for type", line);
        }
        
        Symbole* sym = creerSymbole(
            VARIABLE,    // category
            (yyvsp[-3].str),         // name
            typeStr,    // type
            (yyvsp[-1].structure).valeur,  // initial value
            line,       // line number
            0          // memory address
        );
        insererSymbole(TS, sym);
        afficherTableSymbole(TS); // afficher TS pour confirmer
        afficherTQ(TQ);
    }
#line 2266 "parser.tab.c"
    break;

  case 50: /* $@3: %empty  */
#line 898 "parser.y"
                                                    {
        printf("je suis dans fonction1\n");
        printf("Function parameters:\n");
        if ((yyvsp[-1].parametresList)->head != NULL) {
            ParametreNode* current = (yyvsp[-1].parametresList)->head;
            printf("hilllo");
            Symbole* found;
            //ajouter les parametres de la fonction à la table des symboles
            printf("Parametre: %s %s\n", current->parametre.nom, current->parametre.type);
            printf("le nom de la fonction est : %s\n", (yyvsp[-3].parametreUnion).nom);
            if(rechercherSymbole(TS, (yyvsp[-3].parametreUnion).nom, &found)){
            }

            while (current) {            
            ajouterParametre(found, current->parametre.nom, current->parametre.type);
            current = current->next;
            }
            printf("\naffichage des infos de la fonction \n"); 
         afficherInfoFonction(found);
         

        }
        saveFunctionDec=strdup((yyvsp[-3].parametreUnion).nom);
         
    }
#line 2296 "parser.tab.c"
    break;

  case 51: /* fonction: declarationfonction PAR_OUV parametres PAR_FERM $@3 corps  */
#line 922 "parser.y"
            {
        
        //on check si c'est une fonction (a un type != void ) et ne retourne pas de valeur
        if((yyvsp[-5].parametreUnion).type[0] != 'V' && !itReturn){
            semanticError("La fonction ne retourne pas de valeur", line);
        }
        printf("fonction correcte syntaxiquement\n"); afficherTableSymbole(TS);   
        saveFunctionDec=NULL;
        }
#line 2310 "parser.tab.c"
    break;

  case 52: /* declarationfonction: type FONCTION ID  */
#line 933 "parser.y"
                     {        
        Symbole* found;
        if (rechercherSymbole(TS, (yyvsp[0].str), &found)) {
            semanticError("Function already declared", line);
        }
        
        // Convert the type token to string
        char* typeStr;
        switch((yyvsp[-2].type)) {
            case ENTIER: typeStr = TYPE_ENTIER; break;
            case FLOTTANT: typeStr = TYPE_FLOTTANT; break;
            case CHAR: typeStr = TYPE_CHAR; break;
            case STRING: typeStr = TYPE_STRING; break;
            case BOOLEAN: typeStr = TYPE_BOOLEAN; break;
            default: typeStr = TYPE_ENTIER; // default case
        }
        //création du symbole de la fonction
        Symbole* sym = creerSymbole(
            FUNCTION,    // category
            (yyvsp[0].str),         // name
            typeStr,    // type
            "",         // initial value
            line,       // line number
            0          // memory address
        );
        (yyval.parametreUnion).nom = strdup((yyvsp[0].str));
        (yyval.parametreUnion).type = strdup(typeStr);
        
        insererSymbole(TS, sym);
        afficherTableSymbole(TS); // afficher TS pour confirmer
        afficherTQ(TQ);

    }
#line 2348 "parser.tab.c"
    break;

  case 53: /* declarationfonction: FONCTION ID  */
#line 966 "parser.y"
                 {
        Symbole* found;
        if (rechercherSymbole(TS, (yyvsp[0].str), &found)) {
            semanticError("Function already declared", line);
        }
        //création du symbole de la fonction
        Symbole* sym = creerSymbole(
            FUNCTION,    // category
            (yyvsp[0].str),         // name
            "VOID",    // type
            "",         // initial value
            line,       // line number
            0          // memory address
        );
        (yyval.parametreUnion).nom = strdup((yyvsp[0].str));
        (yyval.parametreUnion).type = strdup("VOID");
        
        insererSymbole(TS, sym);
        afficherTableSymbole(TS); // afficher TS pour confirmer
        afficherTQ(TQ);
    }
#line 2374 "parser.tab.c"
    break;

  case 54: /* parametres: %empty  */
#line 990 "parser.y"
                {
        (yyval.parametresList) = creerParametresList();  // Always create a new list for empty case
    }
#line 2382 "parser.tab.c"
    break;

  case 55: /* parametres: parametres VIRGULE parametre  */
#line 993 "parser.y"
                                   {
        // Use the existing list from $1
        (yyval.parametresList) = (yyvsp[-2].parametresList);  
        // Add the new parameter to the list
        if (!ajouterParametreUnion((yyval.parametresList), (yyvsp[0].parametreUnion).nom, (yyvsp[0].parametreUnion).type)) {
            semanticError("Parametre deja declare", line);
        }
    }
#line 2395 "parser.tab.c"
    break;

  case 56: /* parametres: parametre  */
#line 1001 "parser.y"
                {
        // Create new list for single parameter
        (yyval.parametresList) = creerParametresList();
        // Add the parameter to the new list
        if (!ajouterParametreUnion((yyval.parametresList), (yyvsp[0].parametreUnion).nom, (yyvsp[0].parametreUnion).type)) {
            semanticError("Parametre deja declare", line);
        }
    }
#line 2408 "parser.tab.c"
    break;

  case 57: /* parametre: type ID  */
#line 1013 "parser.y"
            {
        //remplissage des champs du parametre 
        (yyval.parametreUnion).nom = strdup((yyvsp[0].str));
        char* typeStr;
        switch((yyvsp[-1].type)) {
            case ENTIER: typeStr = TYPE_ENTIER; break;
            case FLOTTANT: typeStr = TYPE_FLOTTANT; break;
            case CHAR: typeStr = TYPE_CHAR; break;
            case STRING: typeStr = TYPE_STRING; break;
            case BOOLEAN: typeStr = TYPE_BOOLEAN; break;
            default: typeStr = TYPE_ENTIER; // default case
        }
        (yyval.parametreUnion).type = strdup(typeStr);

    }
#line 2428 "parser.tab.c"
    break;

  case 59: /* parametre: ENREGISTREMENT ID  */
#line 1029 "parser.y"
                        {printf("parametre correcte syntaxiquement\n");}
#line 2434 "parser.tab.c"
    break;

  case 73: /* read: INPUT PAR_OUV ID PAR_FERM SEMICOLON  */
#line 1049 "parser.y"
                                        {printf("read correcte syntaxiquement\n");}
#line 2440 "parser.tab.c"
    break;

  case 76: /* write: PRINT PAR_OUV CHAINE PAR_FERM SEMICOLON  */
#line 1055 "parser.y"
                                            {printf("write correcte syntaxiquement\n");}
#line 2446 "parser.tab.c"
    break;

  case 77: /* retourner: RETURN expression  */
#line 1059 "parser.y"
                      {
        //on check si le type de retour est compatible avec le type de la fonction
        
        Symbole* found;
        printf("voici le nom de la fonction %s\n", saveFunctionDec);
        if (rechercherSymbole(TS, saveFunctionDec, &found)) {
            printf("je suis dans retourner\n");
            if(found->type[0] == 'V'){
                semanticError("La fonction ne retourne pas de valeur", line);
            }
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
                semanticError("Type de retour incompatible avec la fonction", line);
            }
            itReturn = true;
        } else {
          semanticError("Fonction non declaree", line);
        }
        }
#line 2478 "parser.tab.c"
    break;

  case 78: /* $@4: %empty  */
#line 1089 "parser.y"
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
            //on check dabord si il ya une fonction en cours de traitement 
            if (saveFunctionDec != NULL) {
                //on check si la variable est un parametre de la fonction
                Parametre *param;
                Symbole* found;
                rechercherSymbole(TS, saveFunctionDec, &found);
                if (rechercherParametre(found, (yyvsp[-2].str), &param)) {
                    //on check si le type de retour est compatible avec le type de la variable
                    char* exprType = NULL;
                    switch((yyvsp[0].structure).type) {
                        case ENTIER: exprType = TYPE_ENTIER; break;
                        case FLOTTANT: exprType = TYPE_FLOTTANT; break;
                        case CHAR: exprType = TYPE_CHAR; break;
                        case STRING: exprType = TYPE_STRING; break;
                        case BOOLEAN: exprType = TYPE_BOOLEAN; break;
                        default: exprType = TYPE_ENTIER;
                    }
                    if (!areTypesCompatible(exprType, found->type)) {
                        semanticError("Type incompatible dans l'affectation.", line);
                    }
                } else {
                    semanticError("Variable non declaree", line);
                }
            } else {
            semanticError("Variable non declaree", line);
        }
    } }
#line 2546 "parser.tab.c"
    break;

  case 80: /* $@5: %empty  */
#line 1152 "parser.y"
                    {
        Symbole* found;
        if (rechercherSymbole(TS, (yyvsp[-2].str), &found)) { // is declared
        //on check si le type de retour est compatible avec le type de la variable
        char* typeStr;
        switch((yyvsp[0].structure).type) {
            case ENTIER: typeStr = TYPE_ENTIER; break;
            case FLOTTANT: typeStr = TYPE_FLOTTANT; break;
            case CHAR: typeStr = TYPE_CHAR; break;
            case STRING: typeStr = TYPE_STRING; break;
            case BOOLEAN: typeStr = TYPE_BOOLEAN; break;
            default: typeStr = TYPE_ENTIER; // default case
        }
        if (!areTypesCompatible(found->type, typeStr)) {
            semanticError("Type incompatible dans l'affectation.", line);
        }
        qC++;        
        // Create a buffer for the value
        char buffer[256];
        sprintf(buffer, "%s", (yyvsp[0].structure).valeur ? (yyvsp[0].structure).valeur : "");
        // Update the symbol's value
        SetValueSymbol(found, buffer);        
        // Create quadruplet
        quad = creer_Q(":=", (yyvsp[-2].str), " ", buffer, qC);
        inserer_TQ(TQ, quad);
        afficherTQ(TQ);}
        else {
             //on check dabord si il ya une fonction en cours de traitement 
            if (saveFunctionDec != NULL) {
                Symbole* found;
                Parametre *param;
                rechercherSymbole(TS, saveFunctionDec, &found);
                //on check si la variable est un parametre de la fonction
                if (rechercherParametre(found, (yyvsp[-2].str), &param)) {
                    //on check si le type de retour est compatible avec le type de la variable
                    char* exprType = NULL;
                    switch((yyvsp[0].structure).type) {
                        case ENTIER: exprType = TYPE_ENTIER; break;
                        case FLOTTANT: exprType = TYPE_FLOTTANT; break;
                        case CHAR: exprType = TYPE_CHAR; break;
                        case STRING: exprType = TYPE_STRING; break;
                        case BOOLEAN: exprType = TYPE_BOOLEAN; break;
                        default: exprType = TYPE_ENTIER;
                    }
                    if (!areTypesCompatible(exprType, found->type)) {
                        semanticError("Type incompatible dans l'affectation.", line);
                    }
                } else {
                    semanticError("Variable non declaree", line);
                }
            } else {
            semanticError("Variable non declaree", line);
        }
        }
    }
#line 2606 "parser.tab.c"
    break;

  case 82: /* condition: ifstatement corps elsebloc  */
#line 1211 "parser.y"
        {
        while (!Pempty(P)) {
            quad = pop(P);
            updateLabel(quad, qC);
        }
        
        quad = creer_Q("finIf","", " ", "", qC);
        inserer_TQ(TQ, quad);
        qC++;
    }
#line 2621 "parser.tab.c"
    break;

  case 83: /* ifstatement: IF PAR_OUV expression PAR_FERM  */
#line 1223 "parser.y"
                                  {
        //vérifier si le resultat de l'expression est un boolean
        if((yyvsp[-1].structure).type != BOOLEAN){
            semanticError("L'expression doit être un boolean", line);
        }else{
            qC++;
            //branchement en cas de faux
            quad = creer_Q("BZ","temp", " ", (yyvsp[-1].structure).valeur, qC);
            inserer_TQ(TQ, quad);
            //sauvegarder qC pour la mise a jour de l'adresse de branchement dans la pile des adresses
            push(P, quad);
            
        }
    }
#line 2640 "parser.tab.c"
    break;

  case 84: /* loop: WHILE PAR_OUV expression PAR_FERM corps  */
#line 1239 "parser.y"
                                              {printf("condition correcte syntaxiquement\n");}
#line 2646 "parser.tab.c"
    break;

  case 85: /* loop: FOR PAR_OUV ID FROM INT TO INT PAR_FERM corps  */
#line 1241 "parser.y"
    {
        printf("For loop recognized\n");
    }
#line 2654 "parser.tab.c"
    break;

  case 88: /* elsebloc: %empty  */
#line 1250 "parser.y"
                {
        //maj de l'adresse de branchement dans la pile des adresses
        qC++;
        quad = pop(P);
        updateLabel(quad, qC);
        printf("\nelsebloc correcte syntaxiquement qc = %d\n", qC);
    }
#line 2666 "parser.tab.c"
    break;

  case 89: /* elsebloc: elsestatement corps  */
#line 1257 "parser.y"
                          {
        qC++;
        //maj de l'adresse de branchement dans la pile des adresses
        quad = pop(P);
        updateLabel(quad, qC);
        //maj de l'adresse de branchement dans la pile des adresses
       
    }
#line 2679 "parser.tab.c"
    break;

  case 91: /* elsestatement: ELSE  */
#line 1269 "parser.y"
         {
        //maj de l'adresse de branchement dans la pile des adresses
        qC++;
        quad = pop(P);
        updateLabel(quad, qC+1);
        //branchement vers la fin
        
        quad = creer_Q("BR","temp", " ", "", qC);
        inserer_TQ(TQ, quad);
        push(P, quad);
        
    }
#line 2696 "parser.tab.c"
    break;

  case 92: /* elifstatement: elifkey PAR_OUV expression PAR_FERM  */
#line 1282 "parser.y"
                                        {
        if((yyvsp[-1].structure).type != BOOLEAN){
            semanticError("L'expression doit être un boolean", line);
        }else{
            qC++;
            //branchement en cas de faux
            quad = creer_Q("BZ","temp", " ", (yyvsp[-1].structure).valeur, qC);
            inserer_TQ(TQ, quad);
            //sauvegarder qC pour la mise a jour de l'adresse de branchement dans la pile des adresses
            push(P, quad);
            
        }
    }
#line 2714 "parser.tab.c"
    break;

  case 93: /* elifkey: ELIF  */
#line 1296 "parser.y"
        {
        //maj de l'adresse de branchement dans la pile des adresses
        qC++;
        quad = pop(P);
        updateLabel(quad, qC+1);
        //branchement vers la fin
        
        quad = creer_Q("BR","temp", " ", "", qC);
        inserer_TQ(TQ, quad);
        push(P, quad);
    }
#line 2730 "parser.tab.c"
    break;

  case 94: /* $@6: %empty  */
#line 1312 "parser.y"
    {
        //affectation du nom de la fonction courrante 

        currentFunctionCalled = strdup((yyvsp[0].str));
        //initialisation de la liste des parametres
        currentParametresList = creerParametresList();
        
    }
#line 2743 "parser.tab.c"
    break;

  case 95: /* call: ID $@6 PAR_OUV parametresCall PAR_FERM  */
#line 1320 "parser.y"
                                        {
        (yyval.structure).nom = strdup((yyvsp[-4].str));
        //on check si la fonction existe déja dans la table des symboles
        Symbole* found;
        if (rechercherSymbole(TS, (yyvsp[-4].str), &found)) {
            if (found->categorie == FUNCTION) {                
                if (strcmp(found->type, TYPE_ENTIER) == 0) {
                    (yyval.structure).type = ENTIER;
                } else if (strcmp(found->type, TYPE_FLOTTANT) == 0) {
                    (yyval.structure).type = FLOTTANT;
                } else if (strcmp(found->type, TYPE_CHAR) == 0) {
                    (yyval.structure).type = CHAR;
                } else if (strcmp(found->type, TYPE_STRING) == 0) {
                    (yyval.structure).type = STRING;
                } else if (strcmp(found->type, TYPE_BOOLEAN) == 0) {
                    (yyval.structure).type = BOOLEAN;
                }
                (yyval.structure).valeur = strdup(found->valeur);
                //on vérifie le nombre de parametres est le meme 
                if (found->infoFonction->nbParametres != currentParametresList->count) {
                    semanticError("Nombre de parametres incorrect", line);
                }else
                {
                    //on check pour chaque parametre la compatibilité de type 
                    ParametreNode* current = currentParametresList->head;
                    Parametre* currentFonction = found->infoFonction->parametres;
                    while (current) {
                        if (!areTypesCompatible(current->parametre.type, currentFonction->type)) {
                            semanticError("Type incompatible dans l'appel de fonction", line);
                        }
                        current = current->next;
                        currentFonction = currentFonction->suivant;
                    }
                    // on crée le quadruplet pour l'appel de fonction
                    
                    //on fin , on rend la fonction courante et les parametres à NULL
                    currentFunctionCalled = NULL;
                    currentParametresList = NULL;
                    //on push la ligne suivante dans la pile des adresses
                }
            }
            else{
                semanticError("Identifier is not a function", line);
            }
        } else {
            semanticError("Function not declared", line);
        }
        
    }
#line 2797 "parser.tab.c"
    break;

  case 97: /* parametresCall: parametresCall VIRGULE parametreCall  */
#line 1376 "parser.y"
                                          {
        char* typeStr;
        switch((yyvsp[0].structure).type) {
            case ENTIER: typeStr = TYPE_ENTIER; break;
            case FLOTTANT: typeStr = TYPE_FLOTTANT; break;
            case CHAR: typeStr = TYPE_CHAR; break;
            case STRING: typeStr = TYPE_STRING; break;
            case BOOLEAN: typeStr = TYPE_BOOLEAN; break;
            default: typeStr = TYPE_ENTIER; // default case
        }
        //ajouter le nouveau parametre à la liste des parametres
        ajouterParametreUnion(currentParametresList, (yyvsp[0].structure).nom ? (yyvsp[0].structure).nom : (char*)(yyvsp[0].structure).valeur, typeStr);
            
    }
#line 2816 "parser.tab.c"
    break;

  case 98: /* parametresCall: parametreCall  */
#line 1390 "parser.y"
                   {
        char* typeStr;
        switch((yyvsp[0].structure).type) {
            case ENTIER: typeStr = TYPE_ENTIER; break;
            case FLOTTANT: typeStr = TYPE_FLOTTANT; break;
            case CHAR: typeStr = TYPE_CHAR; break;
            case STRING: typeStr = TYPE_STRING; break;
            case BOOLEAN: typeStr = TYPE_BOOLEAN; break;
            default: typeStr = TYPE_ENTIER; // default case
        }
        ajouterParametreUnion(currentParametresList, (yyvsp[0].structure).nom ? (yyvsp[0].structure).nom : (char*)(yyvsp[0].structure).valeur, typeStr) ;
    }
#line 2833 "parser.tab.c"
    break;

  case 100: /* parametreCall: variable  */
#line 1406 "parser.y"
               {printf("parametre correcte syntaxiquement\n");}
#line 2839 "parser.tab.c"
    break;


#line 2843 "parser.tab.c"

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

#line 1409 "parser.y"


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

