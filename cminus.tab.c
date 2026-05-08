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
#line 1 "cminus.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern int line_num;
extern int error_count;
extern FILE *yyin;

int syntax_error = 0;

void print_error(char *type, char *msg) {
    printf("Error type %s at Line %d: %s\n", type, line_num, msg);
    error_count++;
    syntax_error = 1;
}

#define INDENT(n) for(int i=0; i<n; i++) printf("  ")

Node* create_node(char *name, char *value, int line) {
    Node *node = (Node*)malloc(sizeof(Node));
    strncpy(node->name, name, sizeof(node->name)-1);
    node->name[sizeof(node->name)-1] = '\0';
    strncpy(node->value, value, sizeof(node->value)-1);
    node->value[sizeof(node->value)-1] = '\0';
    node->line = line;
    node->child_count = 0;
    return node;
}

void add_child(Node *parent, Node *child) {
    if (parent->child_count < 10) {
        parent->children[parent->child_count++] = child;
    }
}

void print_tree(Node *node, int indent) {
    if (!node) return;
    
    INDENT(indent);
    
    if (strcmp(node->name, "TYPE") == 0) {
        printf("%s: %s\n", node->name, node->value);
    } else if (strcmp(node->name, "ID") == 0) {
        printf("%s: %s\n", node->name, node->value);
    } else if (strcmp(node->name, "INT") == 0) {
        printf("%s: %s\n", node->name, node->value);
    } else if (strcmp(node->name, "FLOAT") == 0) {
        printf("%s: %s\n", node->name, node->value);
    } else {
        printf("%s (%d)\n", node->name, node->line);
    }
    
    for (int i = 0; i < node->child_count; i++) {
        print_tree(node->children[i], indent + 1);
    }
}

void free_tree(Node *node) {
    if (!node) return;
    for (int i = 0; i < node->child_count; i++) {
        free_tree(node->children[i]);
    }
    free(node);
}


#line 140 "cminus.tab.c"

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

#include "cminus.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TYPE_INT = 3,                   /* TYPE_INT  */
  YYSYMBOL_TYPE_FLOAT = 4,                 /* TYPE_FLOAT  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_PLUS = 9,                       /* PLUS  */
  YYSYMBOL_MINUS = 10,                     /* MINUS  */
  YYSYMBOL_STAR = 11,                      /* STAR  */
  YYSYMBOL_DIV = 12,                       /* DIV  */
  YYSYMBOL_LT = 13,                        /* LT  */
  YYSYMBOL_LE = 14,                        /* LE  */
  YYSYMBOL_GT = 15,                        /* GT  */
  YYSYMBOL_GE = 16,                        /* GE  */
  YYSYMBOL_EQ = 17,                        /* EQ  */
  YYSYMBOL_NE = 18,                        /* NE  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_ASSIGNOP = 22,                  /* ASSIGNOP  */
  YYSYMBOL_SEMI = 23,                      /* SEMI  */
  YYSYMBOL_COMMA = 24,                     /* COMMA  */
  YYSYMBOL_LP = 25,                        /* LP  */
  YYSYMBOL_RP = 26,                        /* RP  */
  YYSYMBOL_LB = 27,                        /* LB  */
  YYSYMBOL_RB = 28,                        /* RB  */
  YYSYMBOL_LC = 29,                        /* LC  */
  YYSYMBOL_RC = 30,                        /* RC  */
  YYSYMBOL_ID = 31,                        /* ID  */
  YYSYMBOL_INT = 32,                       /* INT  */
  YYSYMBOL_FLOAT = 33,                     /* FLOAT  */
  YYSYMBOL_LOWER_THAN_ELSE = 34,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_Program = 36,                   /* Program  */
  YYSYMBOL_ExtDefList = 37,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 38,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 39,                /* ExtDecList  */
  YYSYMBOL_Specifier = 40,                 /* Specifier  */
  YYSYMBOL_VarDec = 41,                    /* VarDec  */
  YYSYMBOL_FunDec = 42,                    /* FunDec  */
  YYSYMBOL_VarList = 43,                   /* VarList  */
  YYSYMBOL_ParamDec = 44,                  /* ParamDec  */
  YYSYMBOL_CompSt = 45,                    /* CompSt  */
  YYSYMBOL_DefList = 46,                   /* DefList  */
  YYSYMBOL_Def = 47,                       /* Def  */
  YYSYMBOL_DecList = 48,                   /* DecList  */
  YYSYMBOL_Dec = 49,                       /* Dec  */
  YYSYMBOL_StmtList = 50,                  /* StmtList  */
  YYSYMBOL_Stmt = 51,                      /* Stmt  */
  YYSYMBOL_Exp = 52,                       /* Exp  */
  YYSYMBOL_Args = 53                       /* Args  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   382

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    95,    95,   103,   113,   116,   124,   131,   137,   138,
     148,   154,   162,   168,   181,   187,   198,   208,   214,   222,
     225,   233,   243,   249,   255,   258,   266,   272,   273,   283,
     284,   294,   304,   307,   314,   315,   324,   336,   351,   355,
     367,   370,   374,   380,   388,   396,   404,   412,   420,   428,
     436,   444,   452,   460,   468,   476,   484,   493,   500,   507,
     518,   528,   538,   542,   546,   550,   556,   564,   574,   582
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
  "\"end of file\"", "error", "\"invalid token\"", "TYPE_INT",
  "TYPE_FLOAT", "IF", "ELSE", "WHILE", "RETURN", "PLUS", "MINUS", "STAR",
  "DIV", "LT", "LE", "GT", "GE", "EQ", "NE", "AND", "OR", "NOT",
  "ASSIGNOP", "SEMI", "COMMA", "LP", "RP", "LB", "RB", "LC", "RC", "ID",
  "INT", "FLOAT", "LOWER_THAN_ELSE", "$accept", "Program", "ExtDefList",
  "ExtDef", "ExtDecList", "Specifier", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "DefList", "Def", "DecList", "Dec", "StmtList",
  "Stmt", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-33)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      91,   -10,  -111,  -111,    15,  -111,    91,    11,  -111,  -111,
    -111,    33,    36,    27,    31,    19,  -111,    32,     8,    45,
    -111,    38,  -111,    32,    41,    44,  -111,  -111,  -111,    43,
     -13,    32,   111,    78,  -111,    46,  -111,    22,  -111,  -111,
    -111,   -11,    57,    60,    64,    65,    71,   174,   174,   174,
     174,    72,  -111,  -111,  -111,    59,   111,   241,    75,  -111,
    -111,   174,  -111,    32,  -111,    92,   125,   260,   355,   355,
     279,   161,  -111,  -111,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,  -111,   158,   355,
    -111,    74,   298,    79,   317,  -111,  -111,  -111,   336,    80,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,    34,   221,   144,   144,   144,   144,   174,
    -111,  -111,  -111,  -111,  -111,  -111,    95,   202,  -111,  -111,
    -111,   144,  -111,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    10,    11,     0,     2,     0,     0,     7,     1,
       3,    12,     0,     8,     0,     0,     5,     0,     0,     0,
       6,     0,    16,     0,     0,    19,    12,     9,    14,     0,
       0,     0,     0,     0,    17,    20,    15,     0,    13,    26,
      22,    29,     0,    27,     0,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    34,     0,     0,     0,     0,    23,
      18,     0,    25,     0,    40,     0,     0,     0,    57,    58,
       0,     0,    21,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,    30,
      28,     0,     0,     0,     0,    35,    56,    60,    69,     0,
      52,    53,    54,    55,    46,    47,    48,    49,    50,    51,
      44,    45,    43,     0,     0,     0,     0,     0,     0,     0,
      59,    64,    63,    62,    61,    41,    36,     0,    42,    39,
      68,     0,    38,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -111,  -111,    98,  -111,    97,    28,   -19,  -111,    83,  -111,
     101,    89,  -111,    66,  -111,    77,  -110,   -47,     9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    12,     7,    13,    14,    24,    25,
      54,    32,    33,    42,    43,    55,    56,    57,    99
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    68,    69,    70,    35,   125,   126,   128,   129,    28,
      39,    61,    41,     8,    89,     9,    18,    40,    92,    94,
      21,   133,     2,     3,    98,     2,     3,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      29,   114,    11,    23,    41,    22,    30,    31,     2,     3,
     -24,    17,   -24,   -24,    18,   -24,   121,   122,    15,    16,
      19,    31,   123,    26,    34,    23,   -24,    36,    37,   127,
     -24,    38,    98,    18,   -24,   -24,   -24,   -24,   -24,    58,
      62,     2,     3,   -24,    63,   -24,   -24,    64,   -24,    72,
      65,    -4,     1,    91,     2,     3,    66,    71,    39,   -24,
     115,   131,    48,   -24,    10,   117,   120,   -24,   -24,   -24,
     -24,   -24,    44,    49,    27,    20,    45,    50,    46,    47,
      60,    48,    59,    51,    52,    53,    93,     0,   130,    90,
       0,     0,    49,    73,     0,    48,    50,     0,     0,     0,
      19,   -32,    51,    52,    53,    44,    49,     0,     0,    45,
      50,    46,    47,     0,    48,     0,    51,    52,    53,   113,
       0,     0,     0,     0,     0,    49,     0,     0,    48,    50,
       0,    48,     0,    19,     0,    51,    52,    53,     0,    49,
       0,     0,    49,    50,    48,     0,    50,    97,     0,    51,
      52,    53,    51,    52,    53,    49,     0,     0,     0,    50,
       0,     0,     0,     0,     0,    51,    52,    53,   132,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     0,    86,    87,     0,     0,     0,    88,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,    86,     0,     0,     0,     0,    88,   124,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,    86,    87,     0,     0,     0,    88,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,    86,    95,     0,     0,     0,    88,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       0,    86,     0,     0,     0,    96,    88,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
      86,     0,     0,     0,   116,    88,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,    86,
       0,     0,     0,   118,    88,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,    86,     0,
     119,     0,     0,    88,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,    86,     0,     0,
       0,     0,    88
};

static const yytype_int16 yycheck[] =
{
      47,    48,    49,    50,    23,   115,   116,   117,   118,     1,
      23,    22,    31,    23,    61,     0,    27,    30,    65,    66,
       1,   131,     3,     4,    71,     3,     4,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      32,    88,    31,    15,    63,    26,     1,    19,     3,     4,
       5,    24,     7,     8,    27,    10,    22,    23,    25,    23,
      29,    33,    28,    31,    26,    37,    21,    26,    24,   116,
      25,    28,   119,    27,    29,    30,    31,    32,    33,     1,
      23,     3,     4,     5,    24,     7,     8,    23,    10,    30,
      25,     0,     1,     1,     3,     4,    25,    25,    23,    21,
      26,     6,    10,    25,     6,    26,    26,    29,    30,    31,
      32,    33,     1,    21,    17,    14,     5,    25,     7,     8,
      37,    10,    33,    31,    32,    33,     1,    -1,   119,    63,
      -1,    -1,    21,    56,    -1,    10,    25,    -1,    -1,    -1,
      29,    30,    31,    32,    33,     1,    21,    -1,    -1,     5,
      25,     7,     8,    -1,    10,    -1,    31,    32,    33,     1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    10,    25,
      -1,    10,    -1,    29,    -1,    31,    32,    33,    -1,    21,
      -1,    -1,    21,    25,    10,    -1,    25,    26,    -1,    31,
      32,    33,    31,    32,    33,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,     6,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    -1,    -1,    -1,    27,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    -1,    -1,    -1,    -1,    27,    28,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    -1,    -1,    -1,    27,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    -1,    -1,    -1,    27,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    -1,    -1,    -1,    26,    27,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    -1,    -1,    -1,    26,    27,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      -1,    -1,    -1,    26,    27,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    22,    -1,
      24,    -1,    -1,    27,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    -1,    -1,
      -1,    -1,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,    36,    37,    38,    40,    23,     0,
      37,    31,    39,    41,    42,    25,    23,    24,    27,    29,
      45,     1,    26,    40,    43,    44,    31,    39,     1,    32,
       1,    40,    46,    47,    26,    41,    26,    24,    28,    23,
      30,    41,    48,    49,     1,     5,     7,     8,    10,    21,
      25,    31,    32,    33,    45,    50,    51,    52,     1,    46,
      43,    22,    23,    24,    23,    25,    25,    52,    52,    52,
      52,    25,    30,    50,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    22,    23,    27,    52,
      48,     1,    52,     1,    52,    23,    26,    26,    52,    53,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,     1,    52,    26,    26,    26,    26,    24,
      26,    22,    23,    28,    28,    51,    51,    52,    51,    51,
      53,     6,     6,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    39,    39,
      40,    40,    41,    41,    41,    42,    42,    42,    43,    43,
      44,    45,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    50,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     2,     1,     3,
       1,     1,     1,     4,     3,     4,     3,     4,     3,     1,
       2,     4,     3,     2,     0,     3,     2,     1,     3,     1,
       3,     2,     0,     2,     1,     3,     5,     7,     6,     5,
       2,     5,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     4,
       3,     4,     4,     4,     4,     1,     1,     1,     3,     1
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
  case 2: /* Program: ExtDefList  */
#line 95 "cminus.y"
                     { 
            Node *node = create_node("Program", "", 1);
            add_child(node, (yyvsp[0].node));
            if (!syntax_error) print_tree(node, 0);
            free_tree(node);
        }
#line 1315 "cminus.tab.c"
    break;

  case 3: /* ExtDefList: ExtDef ExtDefList  */
#line 103 "cminus.y"
                               {
            if ((yyvsp[-1].node) == NULL) {
                (yyval.node) = (yyvsp[0].node);
            } else {
                Node *node = create_node("ExtDefList", "", (yyvsp[-1].node)->line);
                add_child(node, (yyvsp[-1].node));
                add_child(node, (yyvsp[0].node));
                (yyval.node) = node;
            }
        }
#line 1330 "cminus.tab.c"
    break;

  case 4: /* ExtDefList: %empty  */
#line 113 "cminus.y"
          { (yyval.node) = NULL; }
#line 1336 "cminus.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 116 "cminus.y"
                                   {
            Node *node = create_node("ExtDef", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            if ((yyvsp[-1].node)) add_child(node, (yyvsp[-1].node));
            Node *semi = create_node("SEMI", "", line_num);
            add_child(node, semi);
            (yyval.node) = node;
        }
#line 1349 "cminus.tab.c"
    break;

  case 6: /* ExtDef: Specifier FunDec CompSt  */
#line 124 "cminus.y"
                                  {
            Node *node = create_node("ExtDef", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            add_child(node, (yyvsp[-1].node));
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1361 "cminus.tab.c"
    break;

  case 7: /* ExtDef: error SEMI  */
#line 131 "cminus.y"
                     { 
            print_error("B", "Invalid external definition");
            (yyval.node) = NULL;
        }
#line 1370 "cminus.tab.c"
    break;

  case 8: /* ExtDecList: VarDec  */
#line 137 "cminus.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1376 "cminus.tab.c"
    break;

  case 9: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 138 "cminus.y"
                                     {
            Node *node = create_node("ExtDecList", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *comma = create_node("COMMA", "", line_num);
            add_child(node, comma);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1389 "cminus.tab.c"
    break;

  case 10: /* Specifier: TYPE_INT  */
#line 148 "cminus.y"
                     {
            Node *node = create_node("Specifier", "", line_num);
            Node *type = create_node("TYPE", "int", line_num);
            add_child(node, type);
            (yyval.node) = node;
        }
#line 1400 "cminus.tab.c"
    break;

  case 11: /* Specifier: TYPE_FLOAT  */
#line 154 "cminus.y"
                       {
            Node *node = create_node("Specifier", "", line_num);
            Node *type = create_node("TYPE", "float", line_num);
            add_child(node, type);
            (yyval.node) = node;
        }
#line 1411 "cminus.tab.c"
    break;

  case 12: /* VarDec: ID  */
#line 162 "cminus.y"
            {
            Node *node = create_node("VarDec", "", line_num);
            Node *id = create_node("ID", (yyvsp[0].sval), line_num);
            add_child(node, id);
            (yyval.node) = node;
        }
#line 1422 "cminus.tab.c"
    break;

  case 13: /* VarDec: VarDec LB INT RB  */
#line 168 "cminus.y"
                          {
            Node *node = create_node("VarDec", "", (yyvsp[-3].node)->line);
            add_child(node, (yyvsp[-3].node));
            Node *lb = create_node("LB", "", line_num);
            add_child(node, lb);
            char buf[20];
            sprintf(buf, "%d", (yyvsp[-1].ival));
            Node *int_node = create_node("INT", buf, line_num);
            add_child(node, int_node);
            Node *rb = create_node("RB", "", line_num);
            add_child(node, rb);
            (yyval.node) = node;
        }
#line 1440 "cminus.tab.c"
    break;

  case 14: /* VarDec: VarDec LB error  */
#line 181 "cminus.y"
                         {
            print_error("B", "Missing ']'");
            (yyval.node) = (yyvsp[-2].node);
        }
#line 1449 "cminus.tab.c"
    break;

  case 15: /* FunDec: ID LP VarList RP  */
#line 187 "cminus.y"
                          {
            Node *node = create_node("FunDec", "", line_num);
            Node *id = create_node("ID", (yyvsp[-3].sval), line_num);
            add_child(node, id);
            Node *lp = create_node("LP", "", line_num);
            add_child(node, lp);
            if ((yyvsp[-1].node)) add_child(node, (yyvsp[-1].node));
            Node *rp = create_node("RP", "", line_num);
            add_child(node, rp);
            (yyval.node) = node;
        }
#line 1465 "cminus.tab.c"
    break;

  case 16: /* FunDec: ID LP RP  */
#line 198 "cminus.y"
                  {
            Node *node = create_node("FunDec", "", line_num);
            Node *id = create_node("ID", (yyvsp[-2].sval), line_num);
            add_child(node, id);
            Node *lp = create_node("LP", "", line_num);
            add_child(node, lp);
            Node *rp = create_node("RP", "", line_num);
            add_child(node, rp);
            (yyval.node) = node;
        }
#line 1480 "cminus.tab.c"
    break;

  case 17: /* FunDec: ID LP error RP  */
#line 208 "cminus.y"
                        {
            print_error("B", "Invalid parameter list");
            (yyval.node) = NULL;
        }
#line 1489 "cminus.tab.c"
    break;

  case 18: /* VarList: ParamDec COMMA VarList  */
#line 214 "cminus.y"
                                 {
            Node *node = create_node("VarList", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *comma = create_node("COMMA", "", line_num);
            add_child(node, comma);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1502 "cminus.tab.c"
    break;

  case 19: /* VarList: ParamDec  */
#line 222 "cminus.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1508 "cminus.tab.c"
    break;

  case 20: /* ParamDec: Specifier VarDec  */
#line 225 "cminus.y"
                            {
            Node *node = create_node("ParamDec", "", (yyvsp[-1].node)->line);
            add_child(node, (yyvsp[-1].node));
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1519 "cminus.tab.c"
    break;

  case 21: /* CompSt: LC DefList StmtList RC  */
#line 233 "cminus.y"
                                {
            Node *node = create_node("CompSt", "", line_num);
            Node *lc = create_node("LC", "", line_num);
            add_child(node, lc);
            if ((yyvsp[-2].node)) add_child(node, (yyvsp[-2].node));
            if ((yyvsp[-1].node)) add_child(node, (yyvsp[-1].node));
            Node *rc = create_node("RC", "", line_num);
            add_child(node, rc);
            (yyval.node) = node;
        }
#line 1534 "cminus.tab.c"
    break;

  case 22: /* CompSt: LC error RC  */
#line 243 "cminus.y"
                     {
            print_error("B", "Invalid compound statement");
            (yyval.node) = NULL;
        }
#line 1543 "cminus.tab.c"
    break;

  case 23: /* DefList: Def DefList  */
#line 249 "cminus.y"
                      {
            Node *node = create_node("DefList", "", (yyvsp[-1].node)->line);
            add_child(node, (yyvsp[-1].node));
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1554 "cminus.tab.c"
    break;

  case 24: /* DefList: %empty  */
#line 255 "cminus.y"
          { (yyval.node) = NULL; }
#line 1560 "cminus.tab.c"
    break;

  case 25: /* Def: Specifier DecList SEMI  */
#line 258 "cminus.y"
                             {
            Node *node = create_node("Def", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            if ((yyvsp[-1].node)) add_child(node, (yyvsp[-1].node));
            Node *semi = create_node("SEMI", "", line_num);
            add_child(node, semi);
            (yyval.node) = node;
        }
#line 1573 "cminus.tab.c"
    break;

  case 26: /* Def: error SEMI  */
#line 266 "cminus.y"
                  {
            print_error("B", "Invalid definition");
            (yyval.node) = NULL;
        }
#line 1582 "cminus.tab.c"
    break;

  case 27: /* DecList: Dec  */
#line 272 "cminus.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1588 "cminus.tab.c"
    break;

  case 28: /* DecList: Dec COMMA DecList  */
#line 273 "cminus.y"
                            {
            Node *node = create_node("DecList", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *comma = create_node("COMMA", "", line_num);
            add_child(node, comma);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1601 "cminus.tab.c"
    break;

  case 29: /* Dec: VarDec  */
#line 283 "cminus.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1607 "cminus.tab.c"
    break;

  case 30: /* Dec: VarDec ASSIGNOP Exp  */
#line 284 "cminus.y"
                          {
            Node *node = create_node("Dec", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *assign = create_node("ASSIGNOP", "", line_num);
            add_child(node, assign);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1620 "cminus.tab.c"
    break;

  case 31: /* StmtList: Stmt StmtList  */
#line 294 "cminus.y"
                         {
            if ((yyvsp[-1].node) == NULL) {
                (yyval.node) = (yyvsp[0].node);
            } else {
                Node *node = create_node("StmtList", "", (yyvsp[-1].node)->line);
                add_child(node, (yyvsp[-1].node));
                add_child(node, (yyvsp[0].node));
                (yyval.node) = node;
            }
        }
#line 1635 "cminus.tab.c"
    break;

  case 32: /* StmtList: %empty  */
#line 304 "cminus.y"
           { (yyval.node) = NULL; }
#line 1641 "cminus.tab.c"
    break;

  case 33: /* Stmt: Exp SEMI  */
#line 307 "cminus.y"
                {
            Node *node = create_node("Stmt", "", (yyvsp[-1].node)->line);
            add_child(node, (yyvsp[-1].node));
            Node *semi = create_node("SEMI", "", line_num);
            add_child(node, semi);
            (yyval.node) = node;
        }
#line 1653 "cminus.tab.c"
    break;

  case 34: /* Stmt: CompSt  */
#line 314 "cminus.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1659 "cminus.tab.c"
    break;

  case 35: /* Stmt: RETURN Exp SEMI  */
#line 315 "cminus.y"
                       {
            Node *node = create_node("Stmt", "", line_num);
            Node *ret = create_node("RETURN", "", line_num);
            add_child(node, ret);
            add_child(node, (yyvsp[-1].node));
            Node *semi = create_node("SEMI", "", line_num);
            add_child(node, semi);
            (yyval.node) = node;
        }
#line 1673 "cminus.tab.c"
    break;

  case 36: /* Stmt: IF LP Exp RP Stmt  */
#line 324 "cminus.y"
                                               {
            Node *node = create_node("Stmt", "", line_num);
            Node *if_node = create_node("IF", "", line_num);
            add_child(node, if_node);
            Node *lp = create_node("LP", "", line_num);
            add_child(node, lp);
            add_child(node, (yyvsp[-2].node));
            Node *rp = create_node("RP", "", line_num);
            add_child(node, rp);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1690 "cminus.tab.c"
    break;

  case 37: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 336 "cminus.y"
                                   {
            Node *node = create_node("Stmt", "", line_num);
            Node *if_node = create_node("IF", "", line_num);
            add_child(node, if_node);
            Node *lp = create_node("LP", "", line_num);
            add_child(node, lp);
            add_child(node, (yyvsp[-4].node));
            Node *rp = create_node("RP", "", line_num);
            add_child(node, rp);
            add_child(node, (yyvsp[-2].node));
            Node *else_node = create_node("ELSE", "", line_num);
            add_child(node, else_node);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1710 "cminus.tab.c"
    break;

  case 38: /* Stmt: IF LP Exp RP Exp ELSE  */
#line 351 "cminus.y"
                             {
            print_error("B", "Missing ';'");
            (yyval.node) = NULL;
        }
#line 1719 "cminus.tab.c"
    break;

  case 39: /* Stmt: WHILE LP Exp RP Stmt  */
#line 355 "cminus.y"
                            {
            Node *node = create_node("Stmt", "", line_num);
            Node *while_node = create_node("WHILE", "", line_num);
            add_child(node, while_node);
            Node *lp = create_node("LP", "", line_num);
            add_child(node, lp);
            add_child(node, (yyvsp[-2].node));
            Node *rp = create_node("RP", "", line_num);
            add_child(node, rp);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1736 "cminus.tab.c"
    break;

  case 40: /* Stmt: error SEMI  */
#line 367 "cminus.y"
                  {
            (yyval.node) = NULL;
        }
#line 1744 "cminus.tab.c"
    break;

  case 41: /* Stmt: IF LP error RP Stmt  */
#line 370 "cminus.y"
                           {
            print_error("B", "Invalid expression in if");
            (yyval.node) = NULL;
        }
#line 1753 "cminus.tab.c"
    break;

  case 42: /* Stmt: WHILE LP error RP Stmt  */
#line 374 "cminus.y"
                              {
            print_error("B", "Invalid expression in while");
            (yyval.node) = NULL;
        }
#line 1762 "cminus.tab.c"
    break;

  case 43: /* Exp: Exp ASSIGNOP Exp  */
#line 380 "cminus.y"
                       {
            Node *node = create_node("Exp", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *assign = create_node("ASSIGNOP", "", line_num);
            add_child(node, assign);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1775 "cminus.tab.c"
    break;

  case 44: /* Exp: Exp AND Exp  */
#line 388 "cminus.y"
                  {
            Node *node = create_node("Exp", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *and_node = create_node("AND", "", line_num);
            add_child(node, and_node);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1788 "cminus.tab.c"
    break;

  case 45: /* Exp: Exp OR Exp  */
#line 396 "cminus.y"
                 {
            Node *node = create_node("Exp", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *or_node = create_node("OR", "", line_num);
            add_child(node, or_node);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1801 "cminus.tab.c"
    break;

  case 46: /* Exp: Exp LT Exp  */
#line 404 "cminus.y"
                 {
            Node *node = create_node("Exp", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *lt = create_node("LT", "", line_num);
            add_child(node, lt);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1814 "cminus.tab.c"
    break;

  case 47: /* Exp: Exp LE Exp  */
#line 412 "cminus.y"
                 {
            Node *node = create_node("Exp", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *le = create_node("LE", "", line_num);
            add_child(node, le);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1827 "cminus.tab.c"
    break;

  case 48: /* Exp: Exp GT Exp  */
#line 420 "cminus.y"
                 {
            Node *node = create_node("Exp", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *gt = create_node("GT", "", line_num);
            add_child(node, gt);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1840 "cminus.tab.c"
    break;

  case 49: /* Exp: Exp GE Exp  */
#line 428 "cminus.y"
                 {
            Node *node = create_node("Exp", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *ge = create_node("GE", "", line_num);
            add_child(node, ge);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1853 "cminus.tab.c"
    break;

  case 50: /* Exp: Exp EQ Exp  */
#line 436 "cminus.y"
                 {
            Node *node = create_node("Exp", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *eq = create_node("EQ", "", line_num);
            add_child(node, eq);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1866 "cminus.tab.c"
    break;

  case 51: /* Exp: Exp NE Exp  */
#line 444 "cminus.y"
                 {
            Node *node = create_node("Exp", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *ne = create_node("NE", "", line_num);
            add_child(node, ne);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1879 "cminus.tab.c"
    break;

  case 52: /* Exp: Exp PLUS Exp  */
#line 452 "cminus.y"
                   {
            Node *node = create_node("Exp", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *plus = create_node("PLUS", "", line_num);
            add_child(node, plus);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1892 "cminus.tab.c"
    break;

  case 53: /* Exp: Exp MINUS Exp  */
#line 460 "cminus.y"
                    {
            Node *node = create_node("Exp", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *minus = create_node("MINUS", "", line_num);
            add_child(node, minus);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1905 "cminus.tab.c"
    break;

  case 54: /* Exp: Exp STAR Exp  */
#line 468 "cminus.y"
                   {
            Node *node = create_node("Exp", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *star = create_node("STAR", "", line_num);
            add_child(node, star);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1918 "cminus.tab.c"
    break;

  case 55: /* Exp: Exp DIV Exp  */
#line 476 "cminus.y"
                  {
            Node *node = create_node("Exp", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *div = create_node("DIV", "", line_num);
            add_child(node, div);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1931 "cminus.tab.c"
    break;

  case 56: /* Exp: LP Exp RP  */
#line 484 "cminus.y"
                {
            Node *node = create_node("Exp", "", line_num);
            Node *lp = create_node("LP", "", line_num);
            add_child(node, lp);
            add_child(node, (yyvsp[-1].node));
            Node *rp = create_node("RP", "", line_num);
            add_child(node, rp);
            (yyval.node) = node;
        }
#line 1945 "cminus.tab.c"
    break;

  case 57: /* Exp: MINUS Exp  */
#line 493 "cminus.y"
                {
            Node *node = create_node("Exp", "", line_num);
            Node *minus = create_node("MINUS", "", line_num);
            add_child(node, minus);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1957 "cminus.tab.c"
    break;

  case 58: /* Exp: NOT Exp  */
#line 500 "cminus.y"
              {
            Node *node = create_node("Exp", "", line_num);
            Node *not_node = create_node("NOT", "", line_num);
            add_child(node, not_node);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 1969 "cminus.tab.c"
    break;

  case 59: /* Exp: ID LP Args RP  */
#line 507 "cminus.y"
                    {
            Node *node = create_node("Exp", "", line_num);
            Node *id = create_node("ID", (yyvsp[-3].sval), line_num);
            add_child(node, id);
            Node *lp = create_node("LP", "", line_num);
            add_child(node, lp);
            if ((yyvsp[-1].node)) add_child(node, (yyvsp[-1].node));
            Node *rp = create_node("RP", "", line_num);
            add_child(node, rp);
            (yyval.node) = node;
        }
#line 1985 "cminus.tab.c"
    break;

  case 60: /* Exp: ID LP RP  */
#line 518 "cminus.y"
               {
            Node *node = create_node("Exp", "", line_num);
            Node *id = create_node("ID", (yyvsp[-2].sval), line_num);
            add_child(node, id);
            Node *lp = create_node("LP", "", line_num);
            add_child(node, lp);
            Node *rp = create_node("RP", "", line_num);
            add_child(node, rp);
            (yyval.node) = node;
        }
#line 2000 "cminus.tab.c"
    break;

  case 61: /* Exp: Exp LB Exp RB  */
#line 528 "cminus.y"
                    {
            Node *node = create_node("Exp", "", (yyvsp[-3].node)->line);
            add_child(node, (yyvsp[-3].node));
            Node *lb = create_node("LB", "", line_num);
            add_child(node, lb);
            add_child(node, (yyvsp[-1].node));
            Node *rb = create_node("RB", "", line_num);
            add_child(node, rb);
            (yyval.node) = node;
        }
#line 2015 "cminus.tab.c"
    break;

  case 62: /* Exp: Exp LB error RB  */
#line 538 "cminus.y"
                      {
            print_error("B", "Missing \"]\"");
            (yyval.node) = (yyvsp[-3].node);
        }
#line 2024 "cminus.tab.c"
    break;

  case 63: /* Exp: Exp LB error SEMI  */
#line 542 "cminus.y"
                        {
            print_error("B", "Missing \"]\"");
            (yyval.node) = (yyvsp[-3].node);
        }
#line 2033 "cminus.tab.c"
    break;

  case 64: /* Exp: Exp LB error ASSIGNOP  */
#line 546 "cminus.y"
                            {
            print_error("B", "Missing \"]\"");
            (yyval.node) = (yyvsp[-3].node);
        }
#line 2042 "cminus.tab.c"
    break;

  case 65: /* Exp: ID  */
#line 550 "cminus.y"
         {
            Node *node = create_node("Exp", "", line_num);
            Node *id = create_node("ID", (yyvsp[0].sval), line_num);
            add_child(node, id);
            (yyval.node) = node;
        }
#line 2053 "cminus.tab.c"
    break;

  case 66: /* Exp: INT  */
#line 556 "cminus.y"
          {
            Node *node = create_node("Exp", "", line_num);
            char buf[20];
            sprintf(buf, "%d", (yyvsp[0].ival));
            Node *int_node = create_node("INT", buf, line_num);
            add_child(node, int_node);
            (yyval.node) = node;
        }
#line 2066 "cminus.tab.c"
    break;

  case 67: /* Exp: FLOAT  */
#line 564 "cminus.y"
            {
            Node *node = create_node("Exp", "", line_num);
            char buf[30];
            sprintf(buf, "%f", (yyvsp[0].fval));
            Node *float_node = create_node("FLOAT", buf, line_num);
            add_child(node, float_node);
            (yyval.node) = node;
        }
#line 2079 "cminus.tab.c"
    break;

  case 68: /* Args: Exp COMMA Args  */
#line 574 "cminus.y"
                      {
            Node *node = create_node("Args", "", (yyvsp[-2].node)->line);
            add_child(node, (yyvsp[-2].node));
            Node *comma = create_node("COMMA", "", line_num);
            add_child(node, comma);
            add_child(node, (yyvsp[0].node));
            (yyval.node) = node;
        }
#line 2092 "cminus.tab.c"
    break;

  case 69: /* Args: Exp  */
#line 582 "cminus.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 2098 "cminus.tab.c"
    break;


#line 2102 "cminus.tab.c"

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

#line 585 "cminus.y"


void yyerror(const char *msg) {
    // 禁用默认的语法错误消息，我们在语法规则中处理错误
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Cannot open file: %s\n", argv[1]);
        return 1;
    }
    
    yyparse();
    
    fclose(yyin);
    return 0;
}
