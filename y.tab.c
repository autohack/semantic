/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "backup.y" /* yacc.c:339  */

#include "my.h"
int level ;
int active_func_num;
struct symboltable *call_name_ptr;
struct symboltable st[50];
struct for_struct fs[10];
char result_type[20];
int param_count = 0;
int limit=-1;
int total_struct=-1;
int struct_flag = 0;
int e_type = 0;		// simple = 1 ; array = 2 ; pointer = 3 ; struct - 4 ; struct array - 5 ; struct pointer - 6;
int for_array[10]; // storing array indexes locally 
// intermediate starts
char quadcode[100];
quadraple global_table[100000];
int nextquad = 0;
int varcount = 1;
// ends here

extern int yylex();
extern int yyparse();
extern int yyerror();

void yyerror (const char *str)
{
	fprintf(stderr, "error: %s\n", str);		// error function
}


// main function 
int main() 
{
	yyparse(); // calling parse funtion 
	print_table();
	icprint();
	
}


#line 108 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    CHAR = 260,
    VOID = 261,
    MAIN = 262,
    WHILE = 263,
    STRING = 264,
    IF = 265,
    ELSE = 266,
    STRUCT = 267,
    IDENTIFIER = 268,
    NUMBER = 269
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define CHAR 260
#define VOID 261
#define MAIN 262
#define WHILE 263
#define STRING 264
#define IF 265
#define ELSE 266
#define STRUCT 267
#define IDENTIFIER 268
#define NUMBER 269

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 43 "backup.y" /* yacc.c:355  */

	int num;
	char *st;
	char fixstr[100];
	expression * expr;
	vector<int> *vec;
	while_ex *wex;
	

#line 186 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 203 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   269

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,     2,     2,     2,    22,     2,
      18,    19,    23,    30,    20,    31,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    17,
      29,    21,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    24,     2,    25,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    15,    26,    16,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    63,    63,    63,    63,    63,    67,    67,
      67,    80,    80,    88,    96,    99,   114,   115,   116,   118,
     118,   120,   121,   124,   140,   146,   162,   162,   163,   164,
     164,   166,   167,   168,   168,   168,   169,   172,   174,   195,
     195,   197,   197,   199,   243,   250,   260,   269,   277,   282,
     292,   303,   309,   323,   351,   370,   393,   393,   396,   397,
     398,   399,   418,   419,   421,   422,   423,   432,   437,   442,
     477,   506,   533,   533,   535,   539,   547,   556,   559,   568,
     571,   578,   594,   610,   626,   642,   660,   676,   688,   695,
     712,   730,   741,   749,   770,   794,   800,   823
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "VOID", "MAIN",
  "WHILE", "STRING", "IF", "ELSE", "STRUCT", "IDENTIFIER", "NUMBER", "'{'",
  "'}'", "';'", "'('", "')'", "','", "'='", "'&'", "'*'", "'['", "']'",
  "'|'", "'>'", "'!'", "'<'", "'+'", "'-'", "'/'", "$accept", "start",
  "struct_decl", "$@1", "$@2", "struct_block", "func_decl", "func_head",
  "red_id", "result", "decl_plist", "decl_pl", "decl_param", "startdash",
  "void_main", "block", "$@3", "$@4", "$@5", "$@6", "func_call",
  "func_func_call", "param_list", "plist", "e", "ifblock", "ifexp",
  "n_var", "m_var", "whileblock", "whileexp", "define", "vars_id", "lhs",
  "declaration", "$@7", "datatype", "vars", "array_id", "idd", "idd2",
  "idd3", "numlist", "br_dimlist", "exp", "or_exp", "d_exp", "pm_exp",
  "factor", "term", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   123,   125,    59,    40,    41,
      44,    61,    38,    42,    91,    93,   124,    62,    33,    60,
      43,    45,    47
};
# endif

#define YYPACT_NINF -101

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-101)))

#define YYTABLE_NINF -71

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     103,  -101,  -101,    -2,    -3,    85,  -101,  -101,    -8,    -1,
       7,  -101,    22,  -101,    31,  -101,  -101,  -101,  -101,    90,
     107,  -101,    30,  -101,  -101,  -101,  -101,  -101,    39,    46,
      15,  -101,    54,    90,    64,  -101,    61,  -101,    67,    90,
    -101,    63,    90,  -101,    68,    81,  -101,    91,    93,   107,
      95,    40,  -101,    40,   100,  -101,    90,  -101,  -101,  -101,
      90,    90,    90,    90,  -101,    38,  -101,   -10,  -101,   107,
    -101,    90,  -101,   107,    40,  -101,  -101,    40,    98,    23,
      99,    94,   102,    34,   -11,  -101,   106,  -101,    97,  -101,
      96,   110,  -101,   111,  -101,   112,   109,   113,   108,   118,
     116,   114,   115,   117,  -101,   121,   122,  -101,   120,   123,
      40,   -11,  -101,   119,   124,   126,    59,   127,    65,    23,
      23,    23,    23,  -101,    40,   117,  -101,   129,  -101,   132,
    -101,  -101,  -101,  -101,   -10,    40,   130,  -101,   133,  -101,
    -101,   125,    40,    40,     1,     1,    -6,     1,     1,    -6,
     -11,   -11,  -101,  -101,  -101,  -101,    90,   141,  -101,  -101,
    -101,   138,  -101,  -101,  -101,  -101,    -6,    -6,    -6,    -6,
    -101,  -101,    40,   139,   140,   135,    90,  -101,    40,   142,
    -101,  -101
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    17,    18,     0,     0,     5,     4,     0,     0,
       0,     3,     0,    25,     0,     1,     7,     6,     2,    36,
      20,    15,     0,     8,    58,    59,    60,    48,     0,     0,
      54,    33,     0,    36,     0,    29,     0,    26,     0,    36,
      51,     0,    36,    56,     0,    19,    22,     0,     0,    12,
       0,     0,    61,    40,     0,    55,    36,    13,    31,    37,
      36,    36,    36,    36,    32,     0,    28,     0,    14,     0,
      23,    36,     9,    12,     0,    96,    95,     0,     0,     0,
       0,    77,    79,    80,    88,    92,     0,    39,    41,    43,
       0,     0,    30,     0,    27,     0,     0,     0,    69,     0,
       0,    62,    64,     0,    21,     0,     0,    11,     0,     0,
       0,    91,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,    74,    34,    44,    49,     0,
      52,    71,    68,    57,     0,     0,    66,    24,     0,    50,
      97,     0,     0,     0,     0,     0,    81,     0,     0,    84,
      89,    90,    93,    94,    42,    75,    36,     0,    53,    63,
      65,     0,    10,    87,    76,    78,    83,    86,    82,    85,
      35,    48,     0,     0,     0,    72,    36,    67,     0,     0,
      73,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,   152,  -101,  -101,    86,   155,  -101,  -101,  -101,
    -101,  -101,    92,   157,  -101,   -33,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,    41,  -101,  -101,  -101,  -101,    -7,  -101,
    -101,  -101,  -101,  -101,   -38,  -101,   -19,    29,  -101,  -101,
    -101,  -101,   -12,   -99,   -43,    24,  -101,  -100,   -77,   -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    49,   106,    72,     7,     8,     9,    10,
      44,    45,    46,    11,    12,    32,    62,    60,    56,   156,
      33,    34,    86,    87,    88,    35,    36,   157,    50,    37,
      38,    39,    40,    41,    42,    67,    43,   100,   101,   102,
     103,   132,   174,    55,    89,    81,    82,    83,    84,    85
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    47,   111,    98,   136,    13,    64,    19,    80,    66,
      14,    73,   121,    99,    75,    76,   146,    20,   149,    77,
      21,   122,    97,    91,   119,   120,   155,    92,    93,    94,
      95,   108,    79,    53,   109,    73,    75,    76,   105,    54,
      22,    77,   150,   151,   166,   167,    23,   168,   169,    48,
      47,    75,    76,    75,    76,   115,    77,    51,    77,    52,
      96,   116,   117,   118,   119,   120,    78,   141,    78,    79,
      57,    79,    75,    76,   152,   153,    61,    77,    75,    76,
     145,    59,    63,    77,    65,    15,   148,    68,     1,     2,
      79,     3,   160,    24,    25,    26,    79,     4,    27,   164,
      28,    69,    29,    30,    70,    31,     1,     2,    71,     3,
      24,    25,    26,    74,    90,     4,   110,   124,   112,    29,
     113,   125,   129,   170,   114,   123,   126,   127,   128,   175,
     130,   131,   -70,   133,   134,   175,   135,   137,   138,   139,
     -47,    54,   140,   179,   163,   142,   143,   144,   147,   158,
     162,   161,   171,   172,   176,   178,   177,    16,   181,   107,
      17,   104,    18,   159,   173,   154,   180,   165
};

static const yytype_uint8 yycheck[] =
{
      33,    20,    79,    13,   103,     7,    39,    15,    51,    42,
      13,    49,    23,    23,    13,    14,   116,    18,   118,    18,
      13,    32,    65,    56,    30,    31,   125,    60,    61,    62,
      63,    74,    31,    18,    77,    73,    13,    14,    71,    24,
      18,    18,   119,   120,   144,   145,    15,   147,   148,    19,
      69,    13,    14,    13,    14,    21,    18,    18,    18,    13,
      22,    27,    28,    29,    30,    31,    28,   110,    28,    31,
      16,    31,    13,    14,   121,   122,    15,    18,    13,    14,
      21,    17,    15,    18,    21,     0,    21,    19,     3,     4,
      31,     6,   135,     3,     4,     5,    31,    12,     8,   142,
      10,    20,    12,    13,    13,    15,     3,     4,    15,     6,
       3,     4,     5,    18,    14,    12,    18,    20,    19,    12,
      26,    25,    13,   156,    22,    19,    16,    16,    16,   172,
      17,    13,    24,    17,    20,   178,    21,    16,    16,    19,
      11,    24,    19,   176,    19,    26,    22,    21,    21,    17,
      17,    21,    11,    15,    15,    20,    16,     5,    16,    73,
       5,    69,     5,   134,   171,   124,   178,   143
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,    12,    34,    35,    39,    40,    41,
      42,    46,    47,     7,    13,     0,    35,    39,    46,    15,
      18,    13,    18,    15,     3,     4,     5,     8,    10,    12,
      13,    15,    48,    53,    54,    58,    59,    62,    63,    64,
      65,    66,    67,    69,    43,    44,    45,    69,    19,    36,
      61,    18,    13,    18,    24,    76,    51,    16,    48,    17,
      50,    15,    49,    15,    48,    21,    48,    68,    19,    20,
      13,    15,    38,    67,    18,    13,    14,    18,    28,    31,
      77,    78,    79,    80,    81,    82,    55,    56,    57,    77,
      14,    48,    48,    48,    48,    48,    22,    77,    13,    23,
      70,    71,    72,    73,    45,    48,    37,    38,    77,    77,
      18,    81,    19,    26,    22,    21,    27,    28,    29,    30,
      31,    23,    32,    19,    20,    25,    16,    16,    16,    13,
      17,    13,    74,    17,    20,    21,    76,    16,    16,    19,
      19,    77,    26,    22,    21,    21,    80,    21,    21,    80,
      81,    81,    82,    82,    56,    76,    52,    60,    17,    70,
      77,    21,    17,    19,    77,    78,    80,    80,    80,    80,
      48,    11,    15,    61,    75,    77,    15,    16,    20,    48,
      75,    16
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    34,    34,    34,    34,    34,    36,    37,
      35,    38,    38,    39,    40,    41,    42,    42,    42,    43,
      43,    44,    44,    45,    46,    47,    49,    48,    48,    50,
      48,    48,    48,    51,    52,    48,    48,    53,    54,    55,
      55,    56,    56,    57,    58,    58,    59,    60,    61,    62,
      63,    64,    65,    65,    66,    66,    68,    67,    69,    69,
      69,    69,    70,    70,    71,    71,    71,    71,    71,    72,
      73,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      79,    79,    79,    79,    79,    79,    79,    79,    80,    80,
      80,    80,    81,    81,    81,    82,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     2,     2,     0,     0,
       8,     2,     0,     4,     4,     2,     1,     1,     1,     1,
       0,     3,     1,     2,     6,     2,     0,     3,     2,     0,
       3,     2,     2,     0,     0,     6,     0,     2,     4,     1,
       0,     1,     3,     1,     4,    10,     4,     0,     0,     4,
       5,     1,     4,     5,     1,     2,     0,     4,     1,     1,
       1,     2,     1,     3,     1,     3,     2,     6,     2,     1,
       1,     1,     1,     3,     3,     4,     4,     1,     4,     1,
       1,     3,     4,     4,     3,     4,     4,     4,     1,     3,
       3,     2,     1,     3,     3,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 8:
#line 67 "backup.y" /* yacc.c:1646  */
    {struct_flag=1;}
#line 1403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 67 "backup.y" /* yacc.c:1646  */
    {struct_flag=0;}
#line 1409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 67 "backup.y" /* yacc.c:1646  */
    {

																	if(search_struct((yyvsp[-6].fixstr)))
																		printf("%s struct declared before\n",(yyvsp[-6].fixstr) );
																	else
																	{
																		total_struct++;
																		strcpy(fs[total_struct].name,(yyvsp[-6].fixstr));
																		
																	}
																}
#line 1425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 88 "backup.y" /* yacc.c:1646  */
    {
												
												level = 0;
												char buffer[100];
												sprintf(buffer,"func end");
												generate(buffer);
											}
#line 1437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 96 "backup.y" /* yacc.c:1646  */
    {level = 2;
												st[limit].num_params = param_count;}
#line 1444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 99 "backup.y" /* yacc.c:1646  */
    {	

										if(search_func((yyvsp[0].fixstr))) printf("error : same function %s declared \n",(yyvsp[0].fixstr));
										else 
											{
												enter_func((yyvsp[0].fixstr),(yyvsp[-1].fixstr));
												char buffer[100];
												sprintf(buffer,"func begin %s",(yyvsp[0].fixstr));
												generate(buffer);
											}
										
										level = 1;
										param_count =0;
									}
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 114 "backup.y" /* yacc.c:1646  */
    {strcpy((yyval.fixstr),(yyvsp[0].fixstr));}
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 115 "backup.y" /* yacc.c:1646  */
    {strcpy((yyval.fixstr),(yyvsp[0].fixstr));}
#line 1475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 116 "backup.y" /* yacc.c:1646  */
    {strcpy((yyval.fixstr),(yyvsp[0].fixstr));}
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 124 "backup.y" /* yacc.c:1646  */
    {
										e_type = 1;
										if(search_param((yyvsp[0].fixstr)))
											printf("error: parameter, %s already declared\n",(yyvsp[0].fixstr));
										else
											enter_param((yyvsp[0].fixstr),(yyvsp[-1].fixstr));
									
										}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 140 "backup.y" /* yacc.c:1646  */
    { 	char buffer[100];
														sprintf(buffer,"func end");
														generate(buffer);
														printf("\nSyntax is correct\n");
													}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 146 "backup.y" /* yacc.c:1646  */
    {
								if(search_func((yyvsp[0].fixstr))) 
									printf("error : same %s function declared before \n",(yyvsp[0].fixstr));
								else
								{
									enter_func((yyvsp[0].fixstr),(yyvsp[-1].fixstr));
									char buffer[100];
									sprintf(buffer,"func begin main");
									generate(buffer);
									
								}
									// active_func_ptr = st[limit]; 
									level = 2;
							}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 162 "backup.y" /* yacc.c:1646  */
    {backpatch((*(yyvsp[0].vec)),nextquad);}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 162 "backup.y" /* yacc.c:1646  */
    {(yyval.vec) = new vector<int>;}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 163 "backup.y" /* yacc.c:1646  */
    {(yyval.vec) = new vector<int>;}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 164 "backup.y" /* yacc.c:1646  */
    {backpatch((*(yyvsp[0].vec)),nextquad);}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 164 "backup.y" /* yacc.c:1646  */
    {(yyval.vec) = new vector<int>;}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 166 "backup.y" /* yacc.c:1646  */
    {(yyval.vec) = new vector<int>;}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 167 "backup.y" /* yacc.c:1646  */
    {(yyval.vec) = new vector<int>;}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 168 "backup.y" /* yacc.c:1646  */
    {level++; }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 168 "backup.y" /* yacc.c:1646  */
    {level--;}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 168 "backup.y" /* yacc.c:1646  */
    {(yyval.vec) = new vector<int>;}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 169 "backup.y" /* yacc.c:1646  */
    {(yyval.vec) = new vector<int>;}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 174 "backup.y" /* yacc.c:1646  */
    {	
													if(!search_func((yyvsp[-3].fixstr)))
													{
														printf("%s function not declared\n",(yyvsp[-3].fixstr));
													}
													else
													{
														// printf("%d\n",$3 );
														if(st[active_func_num].num_params != (yyvsp[-1].num))
															printf("mismatch in number of parameters in call and declaration in %s function\n",(yyvsp[-3].fixstr));
														else{
															char *var = nextvar();
															char buffer[100];
															// sprintf(buffer,"refparam  %s",var);
															sprintf(buffer,"call %s %d",(yyvsp[-3].fixstr),(yyvsp[-1].num)+1);
															generate(buffer);
														}
													}

												}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 195 "backup.y" /* yacc.c:1646  */
    {(yyval.num) = (yyvsp[0].num);}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 195 "backup.y" /* yacc.c:1646  */
    {(yyval.num) = 0;}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 197 "backup.y" /* yacc.c:1646  */
    {(yyval.num) =  1;}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 197 "backup.y" /* yacc.c:1646  */
    {(yyval.num) = (yyvsp[0].num) + 1;}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 199 "backup.y" /* yacc.c:1646  */
    {	
							char buffer[100];
							sprintf(buffer,"param  %s",(yyvsp[0].expr)->value);
							generate(buffer);


						}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 243 "backup.y" /* yacc.c:1646  */
    {
											(yyval.vec) = new vector<int>;
											(*(yyval.vec)).push_back((yyvsp[-3].num));
											merger((*(yyval.vec)),(*(yyvsp[-1].vec)));	
											// backpatch((*$$),nextquad);
										}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 250 "backup.y" /* yacc.c:1646  */
    {
																			(yyval.vec)  = new vector<int>;
																			global_table[(yyvsp[-9].num)].gotonum = (yyvsp[-3].num);
																			merger((*(yyval.vec)),(*(yyvsp[-7].vec)));
																			merger((*(yyval.vec)),(*(yyvsp[-5].vec)));
																			merger((*(yyval.vec)),(*(yyvsp[-1].vec)));
																			}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 261 "backup.y" /* yacc.c:1646  */
    {
									
									(yyval.num) = nextquad;
									char buffer[100];
									sprintf(buffer,"if %s <=0 ",(yyvsp[-1].expr)->value);
									generate(buffer);
								}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 269 "backup.y" /* yacc.c:1646  */
    {
			(yyval.vec) = new vector<int>;
			(*(yyval.vec)).push_back(nextquad);
			char buffer[100];
			sprintf(buffer," ");
			generate(buffer);
		}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 277 "backup.y" /* yacc.c:1646  */
    {
			(yyval.num) = nextquad;

		}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 282 "backup.y" /* yacc.c:1646  */
    {	
												strcpy(global_table[nextquad].s, " ");
												global_table[nextquad].gotonum = (yyvsp[-3].wex)->begin;
												nextquad = nextquad + 1;
												backpatch((*(yyvsp[-1].vec)),(yyvsp[-3].wex)->begin);
												(yyval.vec) = new vector<int>;
												(*(yyval.vec)) = ((yyvsp[-3].wex)->false_list);
												}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 292 "backup.y" /* yacc.c:1646  */
    {	
											(yyval.wex) = new while_ex;
											((yyval.wex)->false_list).push_back(nextquad);
											char buffer[50];
											sprintf(buffer,"if %s <= 0", (yyvsp[-1].expr)->value);
											generate(buffer);
											(yyval.wex)->begin = (yyvsp[-3].num);

											}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 303 "backup.y" /* yacc.c:1646  */
    {//$1 = new vector<int> ;
						//(*$$) = (*$1);
						}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 309 "backup.y" /* yacc.c:1646  */
    { 	
									if((yyvsp[-3].expr)->type !=1 || (yyvsp[-1].expr)->type != 1)
										printf("error : type mismatch of operands in assigment statement\n");
									else
									{

										char buffer[50];
										sprintf(buffer,"%s := %s ",(yyvsp[-3].expr)->value , (yyvsp[-1].expr)->value);
										
										generate(buffer);
									}
									(yyval.vec) = new vector<int>;
								}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 323 "backup.y" /* yacc.c:1646  */
    {	
												(yyval.vec) = new vector<int>;
												int f = search_vars((yyvsp[-1].fixstr));
												if(f==0)
												{
													f = search_param((yyvsp[-1].fixstr));
													if(!(level==2 && f!=0))
													{
														printf("error: %s is not defined earlier\n",(yyvsp[-1].fixstr) );
														f = -1;
													}
												}
												else
												{
													if((yyvsp[-4].expr)->type ==3 && f == 1)
													{
														char buffer[50];
														sprintf(buffer,"%s :=  &%s ",(yyvsp[-4].expr)->value , (yyvsp[-1].fixstr));
														
														generate(buffer);
													}
													else{
														printf("error : type mismatch of operands in assigment statement\n");	
													}
												}

											}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 351 "backup.y" /* yacc.c:1646  */
    {	(yyval.expr) = new expression;
								int f = search_vars((yyvsp[0].fixstr));
								if(f==0)
								{
									f = search_param((yyvsp[0].fixstr));
									if(!(level==2 && f!=0))
									{
										printf("error: %s is not defined earlier\n",(yyvsp[0].fixstr) );
										(yyval.expr)->type = -1;
									}
								}
								else
								{
									(yyval.expr)->type = f;
									strcpy((yyval.expr)->value,(yyvsp[0].fixstr));
								}

								}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 370 "backup.y" /* yacc.c:1646  */
    {	(yyval.expr) = new expression;
												int f = array_valid((yyvsp[-1].fixstr),(yyvsp[0].num));
												// int i;
												// for(i=0;i<$2;i++)
												// printf("%d\n",for_array[i] );
												if(f==0)
												{
													f = search_param((yyvsp[-1].fixstr));
													if(!(level==2 && f!=0))
													{
														printf("error: %s is not defined earlier\n",(yyvsp[-1].fixstr) );
														(yyval.expr)->type = -1;
													}
												}
												else
												{
													(yyval.expr)->type = f;
													strcpy((yyval.expr)->value,(yyvsp[-1].fixstr));
												}
												}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 393 "backup.y" /* yacc.c:1646  */
    {strcpy(result_type,(yyvsp[0].fixstr));}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 399 "backup.y" /* yacc.c:1646  */
    {

										if(search_struct((yyvsp[0].fixstr)))
										{
											e_type = 4;
											strcat((yyvsp[-1].fixstr),"_");
											strcat((yyvsp[-1].fixstr),(yyvsp[0].fixstr));
											strcpy((yyval.fixstr),(yyvsp[-1].fixstr));
										}
										else
										{
											printf("error: struct name %s is undeclared  \n",(yyvsp[0].fixstr) );
										}
								
								
					}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 423 "backup.y" /* yacc.c:1646  */
    {
											// printf("%s\n",$1 );
											int i;
											// printf(" num_b = %d\n", $2 );
											// for(i=0;i<$2;i++)
											// 	printf("%d\n",for_array[i] );
											enter_num_b((yyvsp[-1].fixstr), (yyvsp[0].num));

										}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 432 "backup.y" /* yacc.c:1646  */
    {
											enter_num_b((yyvsp[-5].fixstr), (yyvsp[-4].num));
											
											
										}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 442 "backup.y" /* yacc.c:1646  */
    {	strcpy((yyval.fixstr),(yyvsp[0].fixstr));
								if(e_type==4)
									e_type = 4;
								else
									e_type = 1;

								if(struct_flag==0)
								{
									int f = search_vars((yyvsp[0].fixstr)); int f2 = search_param((yyvsp[0].fixstr));
									if(f != 0)
									{
										printf("found same name var : %s\n",(yyvsp[0].fixstr));
									}

									
									else if(level == 2 && f2 !=0 )
									{
										printf("found same parameter :%s  in  function\n",(yyvsp[0].fixstr));
									}
									else
									{
										enter_vars((yyvsp[0].fixstr));
									}
								}
								else
								{
									if(search_in_struct_var((yyvsp[0].fixstr)))
										printf("found same name var in struct  : %s\n",(yyvsp[0].fixstr));
									else
										enter_in_struct((yyvsp[0].fixstr));

								}

							}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 477 "backup.y" /* yacc.c:1646  */
    {	strcpy((yyval.fixstr),(yyvsp[0].fixstr));
								if(e_type==4)
									e_type = 5;
								else
									e_type = 2;
								
								if(struct_flag==0)
								{
									int f = search_vars((yyvsp[0].fixstr)); int f2 = search_param((yyvsp[0].fixstr));
									if(f != 0)
										printf("found same name var : %s\n",(yyvsp[0].fixstr));
									
									else if(level == 2 && f2 !=0 )
										printf("found same parameter :%s  in  function\n",(yyvsp[0].fixstr));
									else
										enter_vars((yyvsp[0].fixstr));
								}
								else
								{
									if(search_in_struct_var((yyvsp[0].fixstr)))
										printf("found same name var in struct  : %s\n",(yyvsp[0].fixstr));
									else
										enter_in_struct((yyvsp[0].fixstr));

								}

							}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 506 "backup.y" /* yacc.c:1646  */
    {	if(e_type==4)
									e_type = 6;
								else
									e_type = 3;
								strcpy((yyval.fixstr),(yyvsp[0].fixstr));
								if(struct_flag==0)
								{
									int f = search_vars((yyvsp[0].fixstr)); int f2 = search_param((yyvsp[0].fixstr));
									if(f != 0)
										printf("found same name var : %s\n",(yyvsp[0].fixstr));
									
									else if(level == 2 && f2 !=0 )
										printf("found same parameter :%s  in  function\n",(yyvsp[0].fixstr));
									else
										enter_vars((yyvsp[0].fixstr));
								}
								else
								{
									if(search_in_struct_var((yyvsp[0].fixstr)))
										printf("found same name var in struct  : %s\n",(yyvsp[0].fixstr));
									else
										enter_in_struct((yyvsp[0].fixstr));

								}

							}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 535 "backup.y" /* yacc.c:1646  */
    {(yyval.num) = 1;

									for_array[0] = sti((yyvsp[-1].fixstr));
									}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 539 "backup.y" /* yacc.c:1646  */
    {(yyval.num) = (yyvsp[0].num) + 1;
										for_array[(yyval.num)-1] = sti((yyvsp[-2].fixstr));
									}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 547 "backup.y" /* yacc.c:1646  */
    { (yyval.expr) = new expression;
											if((yyvsp[-3].expr)->type !=1 || (yyvsp[0].expr)->type != 1)
											{
												printf("error : type mismatch in expersion\n");
												(yyval.expr)->type = -1;
											}
											else
												(yyval.expr)->type = 1;
											}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 559 "backup.y" /* yacc.c:1646  */
    {(yyval.expr) = new expression;
											 if((yyvsp[-3].expr)->type !=1 || (yyvsp[0].expr)->type != 1)
											{
												printf("error : type mismatch in expersion\n");
												(yyval.expr)->type = -1;
											}
											else
												(yyval.expr)->type = 1;
											}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 571 "backup.y" /* yacc.c:1646  */
    {
							
							(yyval.expr) = new expression;
							(*(yyval.expr)) = (*(yyvsp[0].expr));
							
							
						}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 578 "backup.y" /* yacc.c:1646  */
    {(yyval.expr) = new expression;
											 if((yyvsp[-2].expr)->type !=1 || (yyvsp[0].expr)->type != 1)
											{
												printf("error : type mismatch in expersion\n");
												(yyval.expr)->type = -1;
											}
											else
											{
												(yyval.expr)->type = 1;
												char *var = nextvar();
												char buffer[50];
												sprintf(buffer,"%s := %s > %s",var , (yyvsp[-2].expr)->value , (yyvsp[0].expr)->value);
												strcpy((yyval.expr)->value,var);
												generate(buffer);
											}
										}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 594 "backup.y" /* yacc.c:1646  */
    { (yyval.expr) = new expression;
											if((yyvsp[-3].expr)->type !=1 || (yyvsp[0].expr)->type != 1)
											{
												printf("error : type mismatch in expersion\n");
												(yyval.expr)->type = -1;
											}
											else
											{
												(yyval.expr)->type = 1;
												char *var = nextvar();
												char buffer[50];
												sprintf(buffer,"%s := %s != %s",var , (yyvsp[-3].expr)->value , (yyvsp[0].expr)->value);
												strcpy((yyval.expr)->value,var);
												generate(buffer);
											}
											}
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 610 "backup.y" /* yacc.c:1646  */
    { (yyval.expr) = new expression;
											if((yyvsp[-3].expr)->type !=1 || (yyvsp[0].expr)->type != 1)
											{
												printf("error : type mismatch in expersion\n");
												(yyval.expr)->type = -1;
											}
											else
											{
												(yyval.expr)->type = 1;
												char *var = nextvar();
												char buffer[50];
												sprintf(buffer,"%s := %s == %s",var , (yyvsp[-3].expr)->value , (yyvsp[0].expr)->value);
												strcpy((yyval.expr)->value,var);
												generate(buffer);
											}
											}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 626 "backup.y" /* yacc.c:1646  */
    { (yyval.expr) = new expression;
										if((yyvsp[-2].expr)->type !=1 || (yyvsp[0].expr)->type != 1)
										{
											printf("error : type mismatch in expersion\n");
											(yyval.expr)->type = -1;
										}
										else
										{
											(yyval.expr)->type = 1;
											char *var = nextvar();
											char buffer[50];
											sprintf(buffer,"%s := %s < %s",var , (yyvsp[-2].expr)->value , (yyvsp[0].expr)->value);
											strcpy((yyval.expr)->value,var);
											generate(buffer);
										}
									}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 642 "backup.y" /* yacc.c:1646  */
    { (yyval.expr) = new expression;
											if((yyvsp[-3].expr)->type !=1 || (yyvsp[0].expr)->type != 1)
											{
												printf("error : type mismatch in expersion\n");
												(yyval.expr)->type = -1;
											}
											else
											{

												(yyval.expr)->type = 1;
												char *var = nextvar();
											char buffer[50];
											sprintf(buffer,"%s := %s <= %s",var , (yyvsp[-3].expr)->value , (yyvsp[0].expr)->value);
											strcpy((yyval.expr)->value,var);
											generate(buffer);
											}
											}
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 660 "backup.y" /* yacc.c:1646  */
    { (yyval.expr) = new expression;
											if((yyvsp[-3].expr)->type !=1 || (yyvsp[0].expr)->type != 1)
											{
												printf("error : type mismatch in expersion\n");
												(yyval.expr)->type = -1;
											}
											else
											{
												(yyval.expr)->type = 1;
												char *var = nextvar();
												char buffer[50];
												sprintf(buffer,"%s := %s >= %s",var , (yyvsp[-3].expr)->value , (yyvsp[0].expr)->value);
												strcpy((yyval.expr)->value,var);
												generate(buffer);
											}
											}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 676 "backup.y" /* yacc.c:1646  */
    {(yyval.expr) = new expression;
										(yyval.expr)->type = (yyvsp[-1].expr)->type;
										char *var = nextvar();
										char buffer[50];
										sprintf(buffer,"%s := !%s",var, (yyvsp[-1].expr)->value);
										strcpy((yyval.expr)->value,var);
										generate(buffer);
									}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 688 "backup.y" /* yacc.c:1646  */
    {
							
							(yyval.expr) = new expression;
							(*(yyval.expr)) = (*(yyvsp[0].expr));
							
							
						}
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 695 "backup.y" /* yacc.c:1646  */
    { (yyval.expr) = new expression;
										if((yyvsp[-2].expr)->type !=1 || (yyvsp[0].expr)->type != 1)
										{
											printf("error : type mismatch in expersion\n");
											(yyval.expr)->type = -1;
										}
										else
										{
											(yyval.expr)->type = 1;
											char *var = nextvar();
											char buffer[50];
											sprintf(buffer,"%s := %s + %s",var , (yyvsp[-2].expr)->value , (yyvsp[0].expr)->value);
											strcpy((yyval.expr)->value,var);
											generate(buffer);
											
										}
										}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 712 "backup.y" /* yacc.c:1646  */
    { (yyval.expr) = new expression;
											if((yyvsp[-2].expr)->type !=1 || (yyvsp[0].expr)->type != 1)
										{
											printf("error : type mismatch in expersion\n");
											(yyval.expr)->type = -1;
										}
										else
										{
											(yyval.expr)->type = 1;
											char *var = nextvar();
											char buffer[50];
											sprintf(buffer,"%s := %s - %s",var , (yyvsp[-2].expr)->value , (yyvsp[0].expr)->value);
											strcpy((yyval.expr)->value,var);
											generate(buffer);
											
											
										}
										}
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 730 "backup.y" /* yacc.c:1646  */
    {

									(yyval.expr) = new expression;
									(yyval.expr)->type = (yyvsp[0].expr)->type; 
									// $$->value = '-';
									char p[80] = "-";
									strcat(p,(yyvsp[0].expr)->value);
									strcpy((yyval.expr)->value,p);
								}
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 742 "backup.y" /* yacc.c:1646  */
    {
							
							(yyval.expr) = new expression;
							(*(yyval.expr)) = (*(yyvsp[0].expr));
							
							
						}
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 749 "backup.y" /* yacc.c:1646  */
    { 	
										(yyval.expr) = new expression;
										
										if((yyvsp[-2].expr)->type !=1 || (yyvsp[0].expr)->type != 1)
										{
											printf("error : type mismatch in expersion\n");
											(yyval.expr)->type = -1;
										}
										else
										{
											(yyval.expr)->type = 1;

											char *var = nextvar();
											char buffer[50];
											sprintf(buffer,"%s := %s * %s",var , (yyvsp[-2].expr)->value , (yyvsp[0].expr)->value);
											strcpy((yyval.expr)->value,var);
											generate(buffer);
											
											
										}
									}
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 770 "backup.y" /* yacc.c:1646  */
    { 
										(yyval.expr) = new expression;
										if((yyvsp[-2].expr)->type !=1 || (yyvsp[0].expr)->type != 1)
										{
											(yyval.expr)->type = -1;
											printf("error : type mismatch in expersion\n");
										}
										else
										{
											// printf("%s==%s\n", $1->value , $3->value);
											(yyval.expr)->type = 1;
											char *var = nextvar();
											char buffer[50];
											sprintf(buffer,"%s := %s / %s",var , (yyvsp[-2].expr)->value , (yyvsp[0].expr)->value);
											
											generate(buffer);
											strcpy((yyval.expr)->value,var);

											
										}
											
									}
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 794 "backup.y" /* yacc.c:1646  */
    {	
							(yyval.expr) = new expression;
							strcpy((yyval.expr)->value,(yyvsp[0].fixstr));
							(*(yyval.expr)).type = 1;
							// printf("ffff %s\n",$1 );
						}
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 800 "backup.y" /* yacc.c:1646  */
    {	
									(yyval.expr) = new expression;
									// $$->value = (char * )malloc(1000*sizeof(char));
									int f = search_vars((yyvsp[0].fixstr));
									strcpy((yyval.expr)->value,(yyvsp[0].fixstr));
									// (*$$).value = $1;
									// printf("ffff %s\n",$$->value );

									if(f==0)
									{
										f = search_param((yyvsp[0].fixstr));
										if(!(level==2 && f!=0))
										{
											printf("error: %s is not defined earlier\n",(yyvsp[0].fixstr) );
											(yyval.expr)->type = -1;
										}
									}
									else
										(yyval.expr)->type = f;

								}
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 823 "backup.y" /* yacc.c:1646  */
    { (yyval.expr) = new expression;(yyval.expr)->type = (yyvsp[-1].expr)->type; strcpy((yyval.expr)->value,(yyvsp[-1].expr)->value);}
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2372 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 859 "backup.y" /* yacc.c:1906  */


void enter_func(char name[] , char type[] )
{

	limit += 1;
	// printf("i m gonna insert in %d %s\n", limit,name);
	strcpy(st[limit].name,name);
	strcpy(st[limit].type,type);
	st[limit].param = NULL;
	st[limit].local = NULL;
}

void generate(char str[])
{
	quadraple q;
	// printf("%s\n",str );
	strcpy(q.s,str);	
	q.gotonum = -1;
	global_table[nextquad] = q;
	nextquad = nextquad + 1;
}

void enter_param(char id[],char type[])
{
	param_count++;
	struct varlist *new_node,*temp;

	new_node= (struct varlist *)malloc(sizeof(struct varlist));


 	strcpy(new_node->var_name,id);
 	strcpy(new_node->type,type);
 	new_node->level = 1;
 	new_node->next=NULL;
 	new_node->e_type = e_type;

	if(st[limit].param==NULL)
	{
	   st[limit].param=new_node;
	}
 	else
 	{
	   	temp = st[limit].param;
	    while(temp->next!=NULL)
	    {
	    	temp = temp->next;
	    }
	   temp->next = new_node;
 	}
}
void enter_vars(char id[])
{
	// printf("%s --- %d\n", id,level);
	struct varlist *new_node,*temp;

	new_node= (struct varlist *)malloc(sizeof(struct varlist));

	
 	strcpy(new_node->var_name,id);
 	strcpy(new_node->type,result_type);
 	new_node->level = level;
 	new_node->next=NULL;
 	new_node->e_type = e_type;
	if(st[limit].local==NULL)
	{
	   st[limit].local=new_node;
	}
 	else
 	{
	   	temp = st[limit].local;
	    while(temp->next!=NULL)
	    {
	    	temp = temp->next;
	    }
	   temp->next = new_node;
 	}
 	// printf("%s done\n",st[limit].local->var_name);
}


void print_table()
{
	int i;
	struct varlist *temp;
	printf("Symbol table\n");
	printf("--------------------------------\n");
	printf("name\ttype\tparam_count\n");
	printf("--------------------------------\n");
	for (i = 0;i<=limit;i++)
	{
		printf("%s\t",st[i].name );
		printf("%s\t",st[i].type );
		printf("%d\t",st[i].num_params);
		temp = st[i].param;
		printf("parmas:");
		while(temp!=NULL)
		{
			printf("%s-%s-%d-%d\t",temp->var_name,temp->type,temp->level,temp->e_type);
			temp = temp->next;
		}
		temp = st[i].local;
		printf("local:");
		while(temp!=NULL)
		{
			printf("%s-%s-%d-%d\t",temp->var_name,temp->type,temp->level , temp->e_type);
			temp = temp->next;
		}
		printf("\n");
	}
}
int search_param(char id[])
{
    struct varlist *current = st[limit].param;  // Initialize current
    while (current != NULL)
    {
        if(!strcmp(current->var_name,id))
            return (current->e_type);
        current = current->next;
    }
    return 0;
}

int search_vars(char id[])
{
    struct varlist *current = st[limit].local;  // Initialize current
    struct varlist *temp = st[limit].param;
    int f;
    while (current != NULL)
    {
        if(!strcmp(current->var_name,id) && current->level <= level)
        {
            return (current->e_type);
        }
        current = current->next;
    }


    return 0;
}

int array_valid(char id[] , int num_b)
{
	struct varlist *current = st[limit].local;  // Initialize current
    struct varlist *temp = st[limit].param;
    int f;
    while (current != NULL)
    {
        if(!strcmp(current->var_name,id) && current->level <= level)
        {
        	f = current->e_type;
        	if(f==2 && current->num_b == num_b)
        	{
        		int count = 0;
        		struct array_index *t;
        		t = current->array;
        		while(t != NULL)
        		{
        			if(!(for_array[count++] < t->a))
        				return -1;
        			t = t->next;
        		}
        		return 1;
        	}
            return (f);
        }
        current = current->next;
    }


    return 0;
}
int enter_num_b(char id[] , int num_b)
{
    struct varlist *current = st[limit].local;  // Initialize current
    struct varlist *temp = st[limit].param;
    int i;
    while (current != NULL)
    {
        if(!strcmp(current->var_name,id) && current->level <= level)
        {
        	current->num_b = num_b;
        	struct array_index *t , *t2 , *temp2;
        	t= (struct array_index*)malloc(sizeof(struct array_index));
        	t->a = for_array[0];
        	// printf("%d\n",for_array[0]);
        	t->next = NULL;
        	current->array = t;
        	t2 = t;
        	for(i=1;i<num_b;i++)
        	{
        		temp2 = (struct array_index*)malloc(sizeof(struct array_index));
        		temp2->a = for_array[i];
        		temp2->next = NULL;
        		t2->next = temp2;
        		t2 = temp2;
        		// printf("%d\n",for_array[i] );
        	}
   //      	struct array_index *pre;
   //      	pre = current->array;
			// while(pre != NULL)
			// {
			// 	printf("%d---",pre->a );
			// 	pre = pre->next;
			// }
            return (current->e_type);
        }
        current = current->next;
    }


    return 0;
}

int search_func(char name[])
{

	int i = 0;
	for(i=0;i<=limit;i++)
	{
		if(!strcmp(st[i].name,name))
		{
			active_func_num = i;		// for function call
			return 1;
		}
	}
	return 0;
}

int search_struct(char name[])
{

	int i = 0;
	for(i=0;i<=total_struct;i++)
	{
		if(!strcmp(fs[i].name,name))
		{		
			return 1;
		}
	}
	return 0;
}

void enter_in_struct(char id[])
{
	// printf("%s --- %d\n", id,level);
	struct varlist *new_node,*temp;
	new_node= (struct varlist *)malloc(sizeof(struct varlist));


	
 	strcpy(new_node->var_name,id);
 	strcpy(new_node->type,result_type);
 	new_node->level = 0;
 	new_node->next=NULL;

	if(fs[total_struct].local==NULL)
	{
	   fs[total_struct].local=new_node;
	}
 	else
 	{
	   	temp = fs[total_struct].local;
	    while(temp->next!=NULL)
	    {
	    	temp = temp->next;
	    }
	   temp->next = new_node;
 	}
 	// printf("%s done\n",st[limit].local->var_name);
}
int search_in_struct_var(char id[])
{
	struct varlist *current = fs[total_struct].local;  // Initialize current

    while (current != NULL)
    {
        if(!strcmp(current->var_name,id))
            return 1;
        current = current->next;
    }


    return 0;
}

void icprint()
{
	int i;
	printf("printing Three Address Code \n");
	for(i=0;i<nextquad;i++)
	{
		if(global_table[i].gotonum == -1)
		{
			printf("%d\t %s\n",i,global_table[i].s );
		}
		else
		{
			printf("%d\t %s goto  %d\n",i,global_table[i].s , global_table[i].gotonum);
		}
	}
}

char* nextvar(){
    char b[20];
    sprintf(b,"T_%d",varcount++);
    // addSymbolToQueue(buffer, ST_INT, 0);
    return strdup(b);
}

int sti(char *s)
{
	int r=0;
	for(int i=0;i<strlen(s);i++)
	{
		r= r*10  + (s[i]-48);
	}
	return r;
}

void merger(vector<int> &a,vector<int> &b)
{
	for(int i=0;i<b.size();i++)
	{
		a.push_back(b[i]);
	}
}

void backpatch(vector<int> &a,int b)
{
	for(int i=0;i<a.size();i++)
	{
		// printf("%d\n",a[i] );
		global_table[a[i]].gotonum = b;
	}
}
