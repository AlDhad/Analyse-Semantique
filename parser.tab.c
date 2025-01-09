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
    #include <stdbool.h>
    #include <math.h>
    #include "symbolTable.h"
    #include "quadruplet.h"
    #include "pile.h"

    //declarations 
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


#line 106 "parser.tab.c"

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
  YYSYMBOL_functions = 79,                 /* functions  */
  YYSYMBOL_fonction = 80,                  /* fonction  */
  YYSYMBOL_parametres = 81,                /* parametres  */
  YYSYMBOL_parametre = 82,                 /* parametre  */
  YYSYMBOL_instructions = 83,              /* instructions  */
  YYSYMBOL_instruction = 84,               /* instruction  */
  YYSYMBOL_read = 85,                      /* read  */
  YYSYMBOL_write = 86,                     /* write  */
  YYSYMBOL_retourner = 87,                 /* retourner  */
  YYSYMBOL_assignment = 88,                /* assignment  */
  YYSYMBOL_condition = 89,                 /* condition  */
  YYSYMBOL_loop = 90,                      /* loop  */
  YYSYMBOL_corps = 91,                     /* corps  */
  YYSYMBOL_elsebloc = 92,                  /* elsebloc  */
  YYSYMBOL_call = 93,                      /* call  */
  YYSYMBOL_parametresCall = 94,            /* parametresCall  */
  YYSYMBOL_parametreCall = 95              /* parametreCall  */
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
#define YYLAST   462

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

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
       0,   102,   102,   102,   119,   120,   121,   122,   123,   124,
     128,   132,   135,   136,   137,   138,   139,   140,   143,   144,
     145,   146,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     170,   171,   174,   176,   180,   181,   182,   184,   186,   189,
     190,   193,   195,   196,   200,   201,   202,   204,   206,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     221,   225,   226,   227,   231,   235,   236,   237,   238,   242,
     246,   247,   253,   254,   256,   258,   259,   264,   269,   271,
     272,   277,   278
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
  "declaration", "functions", "fonction", "parametres", "parametre",
  "instructions", "instruction", "read", "write", "retourner",
  "assignment", "condition", "loop", "corps", "elsebloc", "call",
  "parametresCall", "parametreCall", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-86)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -86,    20,   -86,   -86,     2,     7,   -12,   -86,   -86,   -86,
     -86,   -86,   -86,    57,   -86,   -86,    44,    30,   413,   422,
      48,    32,    34,    36,    27,    31,   -86,   235,    40,    43,
      51,    60,    33,   422,    71,    91,    55,   -86,   -86,    66,
      95,    96,    97,    98,   102,   -86,   -86,   108,    46,   -30,
      82,    84,   -86,   -86,   -86,    85,   -86,   -86,   -86,    89,
     -86,   -86,   -86,   249,   422,   110,   113,   -86,   -86,   121,
     102,   103,   -20,   107,   102,   -86,   -86,   102,   -86,   -86,
     -86,   -86,   -15,   -86,   -86,   327,   102,    86,   -18,   111,
     288,   -86,   -86,   -86,   288,   -86,   -86,   -86,   -86,   -86,
     -86,   249,   118,   124,   -86,    42,    93,   -17,   128,   129,
     367,   125,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   150,   -86,   -86,   130,
     106,   136,   145,   -86,     1,   287,   132,   307,   133,   413,
     -86,   -86,   -86,   249,   151,   134,   148,   139,   140,   -86,
     387,   169,   387,   327,   169,   -23,   367,   367,   367,   327,
     327,   327,   347,   367,   249,   -86,    86,   -86,   -86,   -86,
     -86,   -86,   -86,   286,   -86,   142,   -86,   167,   -86,   -86,
      45,   -86,   -86,   165,   153,   249,   184,   -86,   185,   -86,
     -86,   102,   249,   175,   -86,   249,    45,   -86
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,    47,     1,     0,     0,     0,     8,     4,     5,
       6,     7,     9,     0,    48,    42,     0,     0,    57,    51,
       0,     0,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,    53,    51,     0,     0,     0,    45,    46,     0,
       0,     0,     0,     0,     0,    61,    62,     0,    21,     0,
       0,     0,    58,    65,    66,     0,    60,    63,    64,     0,
      55,    56,    54,    59,    51,     0,     0,    42,    44,     0,
       0,     0,     0,     0,     0,    16,    17,     0,    14,    15,
      12,    13,    21,    22,    23,    74,     0,    88,     0,     0,
       0,    40,    41,    67,     0,    68,    69,    42,    83,    50,
      52,    59,     0,     0,     3,     0,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,     0,
      90,     0,     0,    20,    21,     0,     0,     0,     0,    57,
      49,    10,    11,    59,     0,     0,     0,     0,     0,    31,
      24,    27,    25,    26,    28,    29,    32,    33,    35,    36,
      37,    39,    38,    34,    59,    87,    88,    18,    19,    76,
      78,    75,    77,     0,    80,     0,    73,     0,    72,    70,
      84,    89,    82,     0,     0,    59,     0,    79,     0,    71,
      85,     0,    59,     0,    81,    59,    84,    86
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -86,   -86,   -86,    -1,   -86,   -86,   -83,   -27,   -68,   -86,
     -35,   -86,   -86,   -86,    -3,    -5,    70,   -26,   -86,   -86,
     -86,   -86,   -86,   -86,   -85,    19,   -25,    63,   -86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    30,    24,    25,    83,    84,    85,    50,
      18,    26,     4,    14,    31,    51,    27,    98,    53,    54,
      55,    56,    57,    58,    99,   187,    59,   129,   130
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      49,    52,   105,    13,   127,     5,   110,   107,   145,   111,
     131,     6,    91,    92,    32,    88,   140,    23,   126,    89,
       3,   108,   135,   132,   115,    87,   137,    15,    32,    16,
      65,    88,   103,   121,   122,    89,    49,     7,     8,     9,
      10,    11,    12,   146,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   174,    32,
     128,   100,   139,   185,   186,   136,    17,   143,    19,   138,
      87,    20,    33,    34,    49,    35,    88,    36,    37,   180,
      89,    60,    38,   127,    61,    63,   112,   113,   114,   115,
     116,   117,    62,    64,   118,   119,    90,   120,   121,   122,
     190,    66,    23,   123,   124,   125,    68,   194,    75,    76,
     196,    67,    78,    79,    80,    81,    49,    69,    74,    70,
      71,    72,    73,   193,    75,    76,    77,    82,    78,    79,
      80,    81,    86,    93,    94,   101,    95,    49,    23,   128,
      96,   102,   104,    82,   106,   142,    49,    52,   109,   141,
     149,   144,   133,   147,   148,   165,    21,    22,    49,     7,
       8,     9,    10,    11,    12,    49,   166,   167,    49,   112,
     113,   114,   115,   116,   117,   164,   168,   118,   119,   175,
     120,   121,   122,   170,   172,   176,   123,   124,   125,   177,
     178,   179,   184,   188,   112,   113,   114,   115,   116,   117,
     195,   183,   118,   119,   189,   120,   121,   122,   191,   173,
     192,   123,   124,   125,   113,   197,   115,   116,   117,   112,
     113,   114,   115,   116,   117,   121,   122,   118,   119,   181,
     120,   121,   122,     0,     0,     0,   123,   124,   125,    39,
      40,    41,    42,    43,     0,     0,    44,    45,    46,     0,
       0,     0,    47,     0,    40,    41,    42,    43,     0,     0,
      44,    45,    46,     0,     0,     0,    47,    28,    29,    97,
       7,     8,     9,    10,    11,    12,    48,     0,     0,     0,
       0,    28,    29,     0,     7,     8,     9,    10,    11,    12,
      48,    40,    41,    42,    43,     0,     0,    44,    45,    46,
       0,     0,     0,    47,    74,     0,     0,   182,     0,     0,
      75,    76,    77,     0,    78,    79,    80,    81,    28,    29,
       0,     7,     8,     9,    10,    11,    12,    48,     0,   134,
       0,   112,   113,   114,   115,   116,   117,     0,   169,   118,
     119,     0,   120,   121,   122,     0,     0,     0,   123,   124,
     125,   112,   113,   114,   115,   116,   117,     0,   171,   118,
     119,     0,   120,   121,   122,     0,     0,     0,   123,   124,
     125,   112,   113,   114,   115,   116,   117,     0,     0,   118,
     119,     0,   120,   121,   122,     0,     0,     0,   123,   124,
     125,   112,   113,   114,   115,   116,   117,     0,     0,   118,
     119,     0,   120,   121,   122,     0,     0,     0,     0,   124,
     125,   112,   113,   114,   115,   116,   117,     0,     0,   118,
     119,     0,   120,   121,   122,     0,     0,     0,     0,     0,
     125,   112,   113,   114,   115,   116,   117,     0,     0,     0,
       0,     0,     0,   121,   122,    21,    22,     0,     7,     8,
       9,    10,    11,    12,    28,    29,     0,     7,     8,     9,
      10,    11,    12
};

static const yytype_int16 yycheck[] =
{
      27,    27,    70,     4,    87,     3,    74,    27,    25,    77,
      28,     9,    42,    43,    19,    30,   101,    18,    86,    34,
       0,    41,    90,    41,    47,    24,    94,    20,    33,    41,
      33,    30,    67,    56,    57,    34,    63,    35,    36,    37,
      38,    39,    40,    60,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   143,    64,
      87,    64,    97,    18,    19,    90,     9,    25,    24,    94,
      24,    41,    24,    41,   101,    41,    30,    41,    51,   164,
      34,    41,    51,   166,    41,    25,    44,    45,    46,    47,
      48,    49,    41,    60,    52,    53,    50,    55,    56,    57,
     185,    30,   103,    61,    62,    63,    51,   192,    22,    23,
     195,    20,    26,    27,    28,    29,   143,    51,    16,    24,
      24,    24,    24,   191,    22,    23,    24,    41,    26,    27,
      28,    29,    24,    51,    50,    25,    51,   164,   139,   166,
      51,    28,    21,    41,    41,    21,   173,   173,    41,    31,
      25,    58,    41,    25,    25,    25,    32,    33,   185,    35,
      36,    37,    38,    39,    40,   192,    60,    31,   195,    44,
      45,    46,    47,    48,    49,    25,    31,    52,    53,    28,
      55,    56,    57,    51,    51,    51,    61,    62,    63,    41,
      51,    51,    25,    28,    44,    45,    46,    47,    48,    49,
      25,    59,    52,    53,    51,    55,    56,    57,    24,   139,
      25,    61,    62,    63,    45,   196,    47,    48,    49,    44,
      45,    46,    47,    48,    49,    56,    57,    52,    53,   166,
      55,    56,    57,    -1,    -1,    -1,    61,    62,    63,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    -1,     5,     6,     7,     8,    -1,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    32,    33,    20,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    32,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,     5,     6,     7,     8,    -1,    -1,    11,    12,    13,
      -1,    -1,    -1,    17,    16,    -1,    -1,    21,    -1,    -1,
      22,    23,    24,    -1,    26,    27,    28,    29,    32,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    -1,    41,
      -1,    44,    45,    46,    47,    48,    49,    -1,    51,    52,
      53,    -1,    55,    56,    57,    -1,    -1,    -1,    61,    62,
      63,    44,    45,    46,    47,    48,    49,    -1,    51,    52,
      53,    -1,    55,    56,    57,    -1,    -1,    -1,    61,    62,
      63,    44,    45,    46,    47,    48,    49,    -1,    -1,    52,
      53,    -1,    55,    56,    57,    -1,    -1,    -1,    61,    62,
      63,    44,    45,    46,    47,    48,    49,    -1,    -1,    52,
      53,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    44,    45,    46,    47,    48,    49,    -1,    -1,    52,
      53,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,
      63,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    32,    33,    -1,    35,    36,    37,
      38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    68,    69,     0,    79,     3,     9,    35,    36,    37,
      38,    39,    40,    70,    80,    20,    41,     9,    77,    24,
      41,    32,    33,    70,    71,    72,    78,    83,    32,    33,
      70,    81,    82,    24,    41,    41,    41,    51,    51,     4,
       5,     6,     7,     8,    11,    12,    13,    17,    41,    74,
      76,    82,    84,    85,    86,    87,    88,    89,    90,    93,
      41,    41,    41,    25,    60,    81,    30,    20,    51,    51,
      24,    24,    24,    24,    16,    22,    23,    24,    26,    27,
      28,    29,    41,    73,    74,    75,    24,    24,    30,    34,
      50,    42,    43,    51,    50,    51,    51,    20,    84,    91,
      81,    25,    28,    77,    21,    75,    41,    27,    41,    41,
      75,    75,    44,    45,    46,    47,    48,    49,    52,    53,
      55,    56,    57,    61,    62,    63,    75,    73,    74,    94,
      95,    28,    41,    41,    41,    75,    93,    75,    93,    77,
      91,    31,    21,    25,    58,    25,    60,    25,    25,    25,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    25,    25,    60,    31,    31,    51,
      51,    51,    51,    83,    91,    28,    51,    41,    51,    51,
      91,    94,    21,    59,    25,    18,    19,    92,    28,    51,
      91,    24,    25,    75,    91,    25,    91,    92
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    69,    68,    70,    70,    70,    70,    70,    70,
      71,    72,    73,    73,    73,    73,    73,    73,    74,    74,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      76,    76,    77,    77,    78,    78,    78,    79,    79,    80,
      80,    81,    81,    81,    82,    82,    82,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      85,    86,    86,    86,    87,    88,    88,    88,    88,    89,
      90,    90,    91,    91,    92,    92,    92,    93,    94,    94,
      94,    95,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     9,     1,     1,     1,     1,     1,     1,
       5,     5,     1,     1,     1,     1,     1,     1,     4,     4,
       3,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     0,     2,     3,     2,     2,     0,     2,     7,
       6,     0,     3,     1,     2,     2,     2,     0,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       5,     7,     5,     5,     2,     4,     4,     4,     4,     6,
       5,     9,     4,     1,     0,     2,     6,     4,     0,     3,
       1,     1,     1
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
#line 102 "parser.y"
    {
        TS = creerTableSymbole();  
        TQ = initialiserTQ() ;
        P = initialiserP();
    }
#line 1379 "parser.tab.c"
    break;

  case 3: /* programme: $@1 functions DEBUT DEB_CORPS declarations instructions FIN SEMICOLON FIN_CORPS  */
#line 107 "parser.y"
                                                                                {
        qC++;
        quad = creer_Q("fin", "", "", "", qC);
        inserer_TQ(TQ, quad); 
        afficherTableSymbole(TS); // afficher TS pour confirmer
        afficherTQ(TQ);  // afficher TQ pour confirmer
        afficherTQDansFichier(TQ, "output.txt");
        printf("\nProgramme accepte.");
    }
#line 1393 "parser.tab.c"
    break;

  case 44: /* declaration: type ID SEMICOLON  */
#line 180 "parser.y"
                      {printf("declaration correcte syntaxiquement\n");}
#line 1399 "parser.tab.c"
    break;

  case 45: /* declaration: tableau SEMICOLON  */
#line 181 "parser.y"
                        {printf("declaration correcte syntaxiquement\n");}
#line 1405 "parser.tab.c"
    break;

  case 46: /* declaration: type_Struct SEMICOLON  */
#line 182 "parser.y"
                            {printf("declaration correcte syntaxiquement\n");}
#line 1411 "parser.tab.c"
    break;

  case 49: /* fonction: type FONCTION ID PAR_OUV parametres PAR_FERM corps  */
#line 189 "parser.y"
                                                       {printf("fonction correcte syntaxiquement\n");}
#line 1417 "parser.tab.c"
    break;

  case 50: /* fonction: FONCTION ID PAR_OUV parametres PAR_FERM corps  */
#line 190 "parser.y"
                                                    {printf("fonction correcte syntaxiquement\n");}
#line 1423 "parser.tab.c"
    break;

  case 52: /* parametres: parametre VIRGULE parametres  */
#line 195 "parser.y"
                                   {printf("parametres correcte syntaxiquement\n");}
#line 1429 "parser.tab.c"
    break;

  case 56: /* parametre: ENREGISTREMENT ID  */
#line 202 "parser.y"
                        {printf("parametre correcte syntaxiquement\n");}
#line 1435 "parser.tab.c"
    break;

  case 70: /* read: INPUT PAR_OUV ID PAR_FERM SEMICOLON  */
#line 221 "parser.y"
                                        {printf("read correcte syntaxiquement\n");}
#line 1441 "parser.tab.c"
    break;

  case 73: /* write: PRINT PAR_OUV CHAINE PAR_FERM SEMICOLON  */
#line 227 "parser.y"
                                            {printf("write correcte syntaxiquement\n");}
#line 1447 "parser.tab.c"
    break;

  case 74: /* retourner: RETURN expression  */
#line 231 "parser.y"
                      {printf("retourner correcte syntaxiquement\n");}
#line 1453 "parser.tab.c"
    break;

  case 79: /* condition: IF PAR_OUV expression PAR_FERM corps elsebloc  */
#line 242 "parser.y"
                                                   {printf("condition correcte syntaxiquement\n");}
#line 1459 "parser.tab.c"
    break;

  case 80: /* loop: WHILE PAR_OUV expression PAR_FERM corps  */
#line 246 "parser.y"
                                              {printf("condition correcte syntaxiquement\n");}
#line 1465 "parser.tab.c"
    break;

  case 81: /* loop: FOR PAR_OUV ID FROM INT TO INT PAR_FERM corps  */
#line 248 "parser.y"
    {
        printf("For loop recognized\n");
    }
#line 1473 "parser.tab.c"
    break;

  case 90: /* parametresCall: parametreCall  */
#line 273 "parser.y"
    {printf("parametres de l'appel du fonction correcte syntaxiquement\n");}
#line 1479 "parser.tab.c"
    break;

  case 92: /* parametreCall: variable  */
#line 278 "parser.y"
               {printf("parametre correcte syntaxiquement\n");}
#line 1485 "parser.tab.c"
    break;


#line 1489 "parser.tab.c"

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

#line 281 "parser.y"


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

