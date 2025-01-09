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
    extern FILE *yyin;
    int yylex();
    void yyerror(const char *s);
    int line = 1;        // Numéro de ligne courant
int linecol = 0;         // Numéro de colonne courant
char *yyin_filename = NULL;
int sauv = 0;
int sauvline = 1;


#line 85 "parser.tab.c"

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
  YYSYMBOL_type = 69,                      /* type  */
  YYSYMBOL_tableau = 70,                   /* tableau  */
  YYSYMBOL_type_Struct = 71,               /* type_Struct  */
  YYSYMBOL_valeur = 72,                    /* valeur  */
  YYSYMBOL_variable = 73,                  /* variable  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_incrementation = 75,            /* incrementation  */
  YYSYMBOL_declarations = 76,              /* declarations  */
  YYSYMBOL_declaration = 77,               /* declaration  */
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
  YYSYMBOL_condition = 88,                 /* condition  */
  YYSYMBOL_loop = 89,                      /* loop  */
  YYSYMBOL_corps = 90,                     /* corps  */
  YYSYMBOL_elsebloc = 91,                  /* elsebloc  */
  YYSYMBOL_call = 92,                      /* call  */
  YYSYMBOL_parametresCall = 93,            /* parametresCall  */
  YYSYMBOL_parametreCall = 94              /* parametreCall  */
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
#define YYLAST   442

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

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
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    61,    62,    63,    64,    65,    66,    70,
      74,    77,    78,    79,    80,    81,    82,    85,    86,    87,
      88,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   112,
     113,   116,   118,   122,   123,   124,   126,   128,   131,   132,
     135,   137,   138,   142,   143,   144,   146,   148,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   163,
     167,   168,   172,   176,   177,   178,   179,   183,   187,   188,
     194,   195,   197,   199,   200,   205,   210,   212,   213,   218,
     219
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
  "programme", "type", "tableau", "type_Struct", "valeur", "variable",
  "expression", "incrementation", "declarations", "declaration",
  "functions", "fonction", "parametres", "parametre", "instructions",
  "instruction", "read", "write", "retourner", "assignment", "condition",
  "loop", "corps", "elsebloc", "call", "parametresCall", "parametreCall", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -80,    11,     3,   -80,    -7,    -4,   -80,   -80,   -80,   -80,
     -80,   -80,    24,   -80,   -80,    36,    22,   120,   399,    44,
      31,    33,    14,    27,   -80,   231,    39,    42,    43,    66,
      32,   399,    80,   -21,   -80,   -80,    54,    83,    85,    86,
      89,    96,   -80,   -80,    91,    45,   -18,    55,    67,   -80,
     -80,   -80,    65,   -80,   -80,   -80,    81,   -80,   -80,   -80,
     245,   399,   115,   -80,   113,   -80,   141,    96,   101,   136,
     131,    96,   -80,   -80,    96,   -80,   -80,   -80,   -80,   -16,
     -80,   -80,   323,    96,   401,   -20,   134,   284,   -80,   -80,
     -80,   284,   -80,   -80,   -80,   -80,   -80,   -80,   245,   112,
     148,   -80,    41,   122,     4,   156,   363,   121,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,   146,   -80,   -80,   160,   126,   157,   158,   -80,
      -8,   283,   149,   303,   153,   120,   -80,   -80,   -80,   245,
     159,   154,   170,   155,   -80,    82,   165,    82,   323,   165,
      20,   363,   363,   363,   323,   323,   323,   343,   363,   245,
     -80,   401,   -80,   -80,   -80,   -80,   -80,   -80,   282,   -80,
     138,   -80,   200,   -80,    52,   -80,   -80,   201,   179,   245,
     207,   -80,   215,   -80,   -80,    96,   245,   171,   -80,   245,
      52,   -80
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      46,     0,     0,     1,     0,     0,     7,     3,     4,     5,
       6,     8,     0,    47,    41,     0,     0,    56,    50,     0,
       0,     0,     0,     0,    42,     0,     0,     0,     0,     0,
      52,    50,     0,     0,    44,    45,     0,     0,     0,     0,
       0,     0,    60,    61,     0,    20,     0,     0,     0,    57,
      64,    65,     0,    59,    62,    63,     0,    54,    55,    53,
      58,    50,     0,    41,     0,    43,     0,     0,     0,     0,
       0,     0,    15,    16,     0,    13,    14,    11,    12,    20,
      21,    22,    72,     0,    86,     0,     0,     0,    39,    40,
      66,     0,    67,    68,    41,    81,    49,    51,    58,     0,
       0,     2,     0,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90,     0,    88,     0,     0,    19,
      20,     0,     0,     0,     0,    56,    48,    10,     9,    58,
       0,     0,     0,     0,    30,    23,    26,    24,    25,    27,
      28,    31,    32,    34,    35,    36,    38,    37,    33,    58,
      85,    86,    17,    18,    74,    76,    73,    75,     0,    78,
       0,    71,     0,    69,    82,    87,    80,     0,     0,    58,
       0,    77,     0,    70,    83,     0,    58,     0,    79,    58,
      82,    84
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   -80,     0,   -80,   -80,   -79,   -25,   -64,   -80,   -32,
     -80,   -80,   -80,   -27,    -3,   106,   -24,   -80,   -80,   -80,
     -80,   -80,   -80,   -78,    56,   -55,    84,   -80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    28,    22,    23,    80,    81,    82,    47,    17,
      24,     2,    13,    29,    48,    25,    95,    50,    51,    52,
      53,    54,    55,    96,   181,    56,   125,   126
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,    49,    12,   102,    62,   123,     4,   106,   127,    64,
     107,     3,     5,    14,    85,    30,    84,    21,    86,   122,
     136,   128,    85,   131,    88,    89,    86,   133,    30,   141,
      65,    99,   132,    16,    97,    46,   134,    15,     6,     7,
       8,     9,    10,    11,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    30,   124,
      18,   169,   135,    19,   142,    34,   139,   111,    31,    84,
     179,   180,    32,    46,    33,    85,   117,   118,    35,    86,
      57,   174,   123,    58,    59,   108,   109,   110,   111,   112,
     113,    60,    61,   114,   115,    87,   116,   117,   118,    21,
      63,   184,   119,   120,   121,    66,    90,    67,   188,    68,
      69,   190,    71,    70,    46,    83,    92,    91,    72,    73,
      74,   187,    75,    76,    77,    78,   108,   109,   110,   111,
     112,   113,    93,   137,    46,    21,   124,    79,   117,   118,
      98,   100,   103,    46,    49,    20,   144,     6,     7,     8,
       9,    10,    11,    20,    46,     6,     7,     8,     9,    10,
      11,    46,   101,   104,    46,   108,   109,   110,   111,   112,
     113,   159,   105,   114,   115,   129,   116,   117,   118,   138,
     140,   143,   119,   120,   121,   160,   161,   170,   162,   163,
     108,   109,   110,   111,   112,   113,   189,   177,   114,   115,
     165,   116,   117,   118,   167,   171,   173,   119,   120,   121,
     109,   172,   111,   112,   113,   108,   109,   110,   111,   112,
     113,   117,   118,   114,   115,   178,   116,   117,   118,   182,
     183,   185,   119,   120,   121,    36,    37,    38,    39,    40,
     186,   168,    41,    42,    43,   175,   191,     0,    44,     0,
      37,    38,    39,    40,     0,     0,    41,    42,    43,     0,
       0,     0,    44,    26,    27,    94,     6,     7,     8,     9,
      10,    11,    45,     0,     0,     0,     0,    26,    27,     0,
       6,     7,     8,     9,    10,    11,    45,    37,    38,    39,
      40,     0,     0,    41,    42,    43,     0,     0,     0,    44,
      71,     0,     0,   176,     0,     0,    72,    73,    74,     0,
      75,    76,    77,    78,    26,    27,     0,     6,     7,     8,
       9,    10,    11,    45,     0,   130,     0,   108,   109,   110,
     111,   112,   113,     0,   164,   114,   115,     0,   116,   117,
     118,     0,     0,     0,   119,   120,   121,   108,   109,   110,
     111,   112,   113,     0,   166,   114,   115,     0,   116,   117,
     118,     0,     0,     0,   119,   120,   121,   108,   109,   110,
     111,   112,   113,     0,     0,   114,   115,     0,   116,   117,
     118,     0,     0,     0,   119,   120,   121,   108,   109,   110,
     111,   112,   113,     0,     0,   114,   115,     0,   116,   117,
     118,     0,     0,     0,     0,   120,   121,   108,   109,   110,
     111,   112,   113,     0,     0,   114,   115,     0,   116,   117,
     118,     0,     0,    72,    73,     0,   121,    75,    76,    77,
      78,    26,    27,     0,     6,     7,     8,     9,    10,    11,
       0,     0,    79
};

static const yytype_int16 yycheck[] =
{
      25,    25,     2,    67,    31,    84,     3,    71,    28,    30,
      74,     0,     9,    20,    30,    18,    24,    17,    34,    83,
      98,    41,    30,    87,    42,    43,    34,    91,    31,    25,
      51,    63,    87,     9,    61,    60,    91,    41,    35,    36,
      37,    38,    39,    40,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    61,    84,
      24,   139,    94,    41,    60,    51,    25,    47,    24,    24,
      18,    19,    41,    98,    41,    30,    56,    57,    51,    34,
      41,   159,   161,    41,    41,    44,    45,    46,    47,    48,
      49,    25,    60,    52,    53,    50,    55,    56,    57,    99,
      20,   179,    61,    62,    63,    51,    51,    24,   186,    24,
      24,   189,    16,    24,   139,    24,    51,    50,    22,    23,
      24,   185,    26,    27,    28,    29,    44,    45,    46,    47,
      48,    49,    51,    21,   159,   135,   161,    41,    56,    57,
      25,    28,    41,   168,   168,    33,    25,    35,    36,    37,
      38,    39,    40,    33,   179,    35,    36,    37,    38,    39,
      40,   186,    21,    27,   189,    44,    45,    46,    47,    48,
      49,    25,    41,    52,    53,    41,    55,    56,    57,    31,
      58,    25,    61,    62,    63,    25,    60,    28,    31,    31,
      44,    45,    46,    47,    48,    49,    25,    59,    52,    53,
      51,    55,    56,    57,    51,    51,    51,    61,    62,    63,
      45,    41,    47,    48,    49,    44,    45,    46,    47,    48,
      49,    56,    57,    52,    53,    25,    55,    56,    57,    28,
      51,    24,    61,    62,    63,     4,     5,     6,     7,     8,
      25,   135,    11,    12,    13,   161,   190,    -1,    17,    -1,
       5,     6,     7,     8,    -1,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    32,    33,    20,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,     5,     6,     7,
       8,    -1,    -1,    11,    12,    13,    -1,    -1,    -1,    17,
      16,    -1,    -1,    21,    -1,    -1,    22,    23,    24,    -1,
      26,    27,    28,    29,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    -1,    41,    -1,    44,    45,    46,
      47,    48,    49,    -1,    51,    52,    53,    -1,    55,    56,
      57,    -1,    -1,    -1,    61,    62,    63,    44,    45,    46,
      47,    48,    49,    -1,    51,    52,    53,    -1,    55,    56,
      57,    -1,    -1,    -1,    61,    62,    63,    44,    45,    46,
      47,    48,    49,    -1,    -1,    52,    53,    -1,    55,    56,
      57,    -1,    -1,    -1,    61,    62,    63,    44,    45,    46,
      47,    48,    49,    -1,    -1,    52,    53,    -1,    55,    56,
      57,    -1,    -1,    -1,    -1,    62,    63,    44,    45,    46,
      47,    48,    49,    -1,    -1,    52,    53,    -1,    55,    56,
      57,    -1,    -1,    22,    23,    -1,    63,    26,    27,    28,
      29,    32,    33,    -1,    35,    36,    37,    38,    39,    40,
      -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    68,    78,     0,     3,     9,    35,    36,    37,    38,
      39,    40,    69,    79,    20,    41,     9,    76,    24,    41,
      33,    69,    70,    71,    77,    82,    32,    33,    69,    80,
      81,    24,    41,    41,    51,    51,     4,     5,     6,     7,
       8,    11,    12,    13,    17,    41,    73,    75,    81,    83,
      84,    85,    86,    87,    88,    89,    92,    41,    41,    41,
      25,    60,    80,    20,    30,    51,    51,    24,    24,    24,
      24,    16,    22,    23,    24,    26,    27,    28,    29,    41,
      72,    73,    74,    24,    24,    30,    34,    50,    42,    43,
      51,    50,    51,    51,    20,    83,    90,    80,    25,    76,
      28,    21,    74,    41,    27,    41,    74,    74,    44,    45,
      46,    47,    48,    49,    52,    53,    55,    56,    57,    61,
      62,    63,    74,    72,    73,    93,    94,    28,    41,    41,
      41,    74,    92,    74,    92,    76,    90,    21,    31,    25,
      58,    25,    60,    25,    25,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    25,
      25,    60,    31,    31,    51,    51,    51,    51,    82,    90,
      28,    51,    41,    51,    90,    93,    21,    59,    25,    18,
      19,    91,    28,    51,    90,    24,    25,    74,    90,    25,
      90,    91
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    68,    69,    69,    69,    69,    69,    69,    70,
      71,    72,    72,    72,    72,    72,    72,    73,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    76,    76,    77,    77,    77,    78,    78,    79,    79,
      80,    80,    80,    81,    81,    81,    82,    82,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    84,
      85,    85,    86,    87,    87,    87,    87,    88,    89,    89,
      90,    90,    91,    91,    91,    92,    93,    93,    93,    94,
      94
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     1,     1,     1,     1,     1,     1,     5,
       5,     1,     1,     1,     1,     1,     1,     4,     4,     3,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     0,     2,     3,     2,     2,     0,     2,     7,     6,
       0,     3,     1,     2,     2,     2,     0,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     5,
       7,     5,     2,     4,     4,     4,     4,     6,     5,     9,
       4,     1,     0,     2,     6,     4,     0,     3,     1,     1,
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
  case 2: /* programme: functions DEBUT DEB_CORPS declarations instructions FIN SEMICOLON FIN_CORPS  */
#line 57 "parser.y"
                                                                                {printf("programme correcte syntaxiquement\n");}
#line 1348 "parser.tab.c"
    break;

  case 43: /* declaration: type ID SEMICOLON  */
#line 122 "parser.y"
                      {printf("declaration correcte syntaxiquement\n");}
#line 1354 "parser.tab.c"
    break;

  case 44: /* declaration: tableau SEMICOLON  */
#line 123 "parser.y"
                        {printf("declaration correcte syntaxiquement\n");}
#line 1360 "parser.tab.c"
    break;

  case 45: /* declaration: type_Struct SEMICOLON  */
#line 124 "parser.y"
                            {printf("declaration correcte syntaxiquement\n");}
#line 1366 "parser.tab.c"
    break;

  case 48: /* fonction: type FONCTION ID PAR_OUV parametres PAR_FERM corps  */
#line 131 "parser.y"
                                                       {printf("fonction correcte syntaxiquement\n");}
#line 1372 "parser.tab.c"
    break;

  case 49: /* fonction: FONCTION ID PAR_OUV parametres PAR_FERM corps  */
#line 132 "parser.y"
                                                    {printf("fonction correcte syntaxiquement\n");}
#line 1378 "parser.tab.c"
    break;

  case 51: /* parametres: parametre VIRGULE parametres  */
#line 137 "parser.y"
                                   {printf("parametres correcte syntaxiquement\n");}
#line 1384 "parser.tab.c"
    break;

  case 55: /* parametre: ENREGISTREMENT ID  */
#line 144 "parser.y"
                        {printf("parametre correcte syntaxiquement\n");}
#line 1390 "parser.tab.c"
    break;

  case 69: /* read: INPUT PAR_OUV ID PAR_FERM SEMICOLON  */
#line 163 "parser.y"
                                        {printf("read correcte syntaxiquement\n");}
#line 1396 "parser.tab.c"
    break;

  case 71: /* write: PRINT PAR_OUV CHAINE PAR_FERM SEMICOLON  */
#line 168 "parser.y"
                                             {printf("write correcte syntaxiquement\n");}
#line 1402 "parser.tab.c"
    break;

  case 72: /* retourner: RETURN expression  */
#line 172 "parser.y"
                      {printf("retourner correcte syntaxiquement\n");}
#line 1408 "parser.tab.c"
    break;

  case 77: /* condition: IF PAR_OUV expression PAR_FERM corps elsebloc  */
#line 183 "parser.y"
                                                   {printf("condition correcte syntaxiquement\n");}
#line 1414 "parser.tab.c"
    break;

  case 78: /* loop: WHILE PAR_OUV expression PAR_FERM corps  */
#line 187 "parser.y"
                                              {printf("condition correcte syntaxiquement\n");}
#line 1420 "parser.tab.c"
    break;

  case 79: /* loop: FOR PAR_OUV ID FROM INT TO INT PAR_FERM corps  */
#line 189 "parser.y"
    {
        printf("For loop recognized\n");
    }
#line 1428 "parser.tab.c"
    break;

  case 88: /* parametresCall: parametreCall  */
#line 214 "parser.y"
    {printf("parametres de l'appel du fonction correcte syntaxiquement\n");}
#line 1434 "parser.tab.c"
    break;

  case 90: /* parametreCall: variable  */
#line 219 "parser.y"
               {printf("parametre correcte syntaxiquement\n");}
#line 1440 "parser.tab.c"
    break;


#line 1444 "parser.tab.c"

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

#line 222 "parser.y"


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
