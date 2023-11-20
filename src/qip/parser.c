/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "src/parser.y"

    #include "stdbool.h"
    #include "stdio.h"
    #include "parser.h"
    #include "lexer.h"
    #include "dbg.h"
    qip_ast_node *root;
    extern int yylex();
    void yyerror(YYLTYPE *loc, void *scanner, qip_parser *parser, const char *s) {
        bstring msg = bfromcstr(s);
        qip_parser_add_error(parser, loc->first_line, msg);
        bdestroy(msg);
    }


/* Line 268 of yacc.c  */
#line 87 "src/parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 288 of yacc.c  */
#line 24 "src/parser.y"

    #include "node.h"
    #include "array.h"
    #include "error.h"



/* Line 288 of yacc.c  */
#line 119 "src/parser.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TIDENTIFIER = 258,
     TSTRING = 259,
     TINT = 260,
     TFLOAT = 261,
     TTRUE = 262,
     TFALSE = 263,
     TCLASS = 264,
     TPUBLIC = 265,
     TPRIVATE = 266,
     TRETURN = 267,
     TIF = 268,
     TELSE = 269,
     TFOR = 270,
     TEACH = 271,
     TIN = 272,
     TLPAREN = 273,
     TRPAREN = 274,
     TLBRACE = 275,
     TRBRACE = 276,
     TLBRACKET = 277,
     TRBRACKET = 278,
     TLANGLE = 279,
     TRANGLE = 280,
     TQUOTE = 281,
     TDBLQUOTE = 282,
     TSEMICOLON = 283,
     TCOLON = 284,
     TCOMMA = 285,
     TPLUS = 286,
     TMINUS = 287,
     TMUL = 288,
     TDIV = 289,
     TASSIGN = 290,
     TEQUALS = 291,
     TDOT = 292,
     TSIZEOF = 293,
     TOFFSETOF = 294,
     TNULL = 295,
     TFUNCTION = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 301 of yacc.c  */
#line 47 "src/parser.y"

    bstring string;
    int64_t int_value;
    double float_value;
    bool boolean_value;
    qip_ast_access_e access;
    qip_ast_node *node;
    qip_array *array;
    struct {
        qip_ast_node *condition;
        qip_ast_node *block;
    } if_block;
    struct {
        qip_array *conditions;
        qip_array *blocks;
    } if_blocks;
    int token;



/* Line 301 of yacc.c  */
#line 198 "src/parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

/* "%code provides" blocks.  */

/* Line 340 of yacc.c  */
#line 30 "src/parser.y"

    #ifndef _qip_parser_typedef
    #define _qip_parser_typedef
    typedef struct qip_parser {
        uint32_t error_count;
        qip_error **errors;
    } qip_parser;
    #endif

    qip_parser *qip_parser_create();
    void qip_parser_free(qip_parser *parser);
    int qip_parser_parse(qip_parser *parser, bstring name, bstring text, qip_ast_node **module);
    int qip_parser_add_error(qip_parser *parser, int32_t line_no, bstring message);
    int qip_parser_free_errors(qip_parser *parser);
    int qip_set_pos(qip_ast_node *node, YYLTYPE *loc);



/* Line 340 of yacc.c  */
#line 241 "src/parser.c"

/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 247 "src/parser.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   263

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNRULES -- Number of states.  */
#define YYNSTATES  210

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    11,    13,    15,    18,
      21,    24,    28,    31,    34,    36,    38,    42,    46,    50,
      54,    58,    60,    62,    64,    66,    68,    70,    72,    76,
      78,    83,    87,    94,    96,    98,   101,   106,   111,   115,
     119,   120,   122,   126,   128,   130,   135,   143,   149,   150,
     152,   156,   159,   160,   162,   164,   166,   168,   170,   172,
     174,   176,   178,   180,   182,   184,   185,   187,   191,   200,
     207,   208,   210,   214,   216,   225,   226,   228,   232,   235,
     237,   238,   241,   244,   249,   251,   255,   263,   264,   267,
     270,   271,   276,   287,   289,   291,   299,   301,   303,   304,
     308,   310,   314,   316,   317,   320,   323,   327,   332,   333,
     336,   340,   347,   348,   350,   354,   358,   360,   365,   370
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    -1,    43,    84,    -1,    43,    46,    -1,
      -1,    45,    -1,    46,    -1,    45,    46,    -1,    47,    28,
      -1,    49,    28,    -1,    12,    47,    28,    -1,    12,    28,
      -1,    52,    28,    -1,    77,    -1,    82,    -1,    47,    31,
      47,    -1,    47,    32,    47,    -1,    47,    33,    47,    -1,
      47,    34,    47,    -1,    47,    36,    47,    -1,    98,    -1,
      61,    -1,    48,    -1,    96,    -1,    97,    -1,    71,    -1,
      75,    -1,    18,    47,    19,    -1,     3,    -1,     3,    18,
      67,    19,    -1,    48,    37,     3,    -1,    48,    37,     3,
      18,    67,    19,    -1,    51,    -1,    50,    -1,    56,     3,
      -1,    56,     3,    35,    47,    -1,    56,     3,    35,    53,
      -1,    48,    35,    47,    -1,    22,    54,    23,    -1,    -1,
      55,    -1,    54,    30,    55,    -1,    47,    -1,     3,    -1,
       3,    24,    57,    25,    -1,     3,    24,    57,    30,    29,
      56,    25,    -1,     3,    24,    29,    56,    25,    -1,    -1,
      58,    -1,    57,    30,    58,    -1,    56,    59,    -1,    -1,
       3,    -1,     4,    -1,    65,    -1,    66,    -1,    62,    -1,
      64,    -1,    63,    -1,     5,    -1,     6,    -1,     7,    -1,
       8,    -1,     4,    -1,    -1,    47,    -1,    67,    30,    47,
      -1,    56,     3,    18,    69,    19,    20,    44,    21,    -1,
      56,     3,    18,    69,    19,    28,    -1,    -1,    70,    -1,
      69,    30,    70,    -1,    50,    -1,    41,    18,    72,    19,
      74,    20,    44,    21,    -1,    -1,    73,    -1,    72,    30,
      73,    -1,    56,     3,    -1,     3,    -1,    -1,    29,    56,
      -1,    29,    76,    -1,    29,    20,    44,    21,    -1,    52,
      -1,    78,    79,    81,    -1,    13,    18,    47,    19,    20,
      44,    21,    -1,    -1,    79,    80,    -1,    14,    78,    -1,
      -1,    14,    20,    44,    21,    -1,    15,    16,    18,    50,
      17,    47,    19,    20,    44,    21,    -1,    10,    -1,    11,
      -1,    92,     9,    85,    86,    20,    89,    21,    -1,     3,
      -1,     4,    -1,    -1,    24,    87,    25,    -1,    88,    -1,
      87,    30,    88,    -1,     3,    -1,    -1,    89,    90,    -1,
      89,    91,    -1,    92,    83,    68,    -1,    92,    83,    50,
      28,    -1,    -1,    92,    93,    -1,    22,     3,    23,    -1,
      22,     3,    18,    94,    19,    23,    -1,    -1,    95,    -1,
      94,    30,    95,    -1,     3,    35,    60,    -1,    60,    -1,
      38,    18,    56,    19,    -1,    39,    18,    48,    19,    -1,
      40,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   113,   113,   114,   115,   118,   119,   121,   122,   124,
     125,   126,   127,   128,   129,   130,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   148,
     154,   161,   169,   180,   181,   184,   192,   198,   206,   208,
     217,   218,   219,   222,   225,   230,   237,   245,   253,   254,
     255,   258,   265,   266,   269,   271,   272,   273,   276,   277,
     280,   282,   284,   285,   288,   290,   291,   292,   295,   303,
     312,   313,   314,   317,   319,   327,   328,   329,   332,   340,
     350,   351,   354,   364,   372,   375,   387,   389,   390,   393,
     395,   396,   399,   406,   407,   410,   423,   423,   425,   426,
     429,   430,   433,   435,   436,   437,   440,   448,   456,   457,
     460,   461,   464,   465,   466,   469,   470,   472,   474,   476
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENTIFIER", "TSTRING", "TINT",
  "TFLOAT", "TTRUE", "TFALSE", "TCLASS", "TPUBLIC", "TPRIVATE", "TRETURN",
  "TIF", "TELSE", "TFOR", "TEACH", "TIN", "TLPAREN", "TRPAREN", "TLBRACE",
  "TRBRACE", "TLBRACKET", "TRBRACKET", "TLANGLE", "TRANGLE", "TQUOTE",
  "TDBLQUOTE", "TSEMICOLON", "TCOLON", "TCOMMA", "TPLUS", "TMINUS", "TMUL",
  "TDIV", "TASSIGN", "TEQUALS", "TDOT", "TSIZEOF", "TOFFSETOF", "TNULL",
  "TFUNCTION", "$accept", "module", "block", "stmts", "stmt", "expr",
  "var_ref", "var_decl", "uninitialized_var_decl", "initialized_var_decl",
  "var_assign", "array_literal", "array_items", "array_item", "type_ref",
  "type_ref_items", "type_ref_item", "type_ref_arg_name", "string",
  "literal", "number", "int_literal", "float_literal", "boolean_literal",
  "string_literal", "call_args", "function", "fargs", "farg",
  "anon_function", "anon_fargs", "anon_farg",
  "anon_function_return_type_ref", "terse_function", "terse_expr",
  "if_stmt", "if_block", "else_if_blocks", "else_if_block", "else_block",
  "for_each_stmt", "access", "class", "class_name", "template_vars",
  "template_var_items", "template_var", "class_members", "method",
  "property", "metadatas", "metadata", "metadata_items", "metadata_item",
  "sizeof", "offsetof", "null_literal", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    44,    44,    45,    45,    46,
      46,    46,    46,    46,    46,    46,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    48,
      48,    48,    48,    49,    49,    50,    51,    51,    52,    53,
      54,    54,    54,    55,    56,    56,    56,    56,    57,    57,
      57,    58,    59,    59,    60,    61,    61,    61,    62,    62,
      63,    64,    65,    65,    66,    67,    67,    67,    68,    68,
      69,    69,    69,    70,    71,    72,    72,    72,    73,    73,
      74,    74,    75,    75,    76,    77,    78,    79,    79,    80,
      81,    81,    82,    83,    83,    84,    85,    85,    86,    86,
      87,    87,    88,    89,    89,    89,    90,    91,    92,    92,
      93,    93,    94,    94,    94,    95,    95,    96,    97,    98
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     0,     1,     1,     2,     2,
       2,     3,     2,     2,     1,     1,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       4,     3,     6,     1,     1,     2,     4,     4,     3,     3,
       0,     1,     3,     1,     1,     4,     7,     5,     0,     1,
       3,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     3,     8,     6,
       0,     1,     3,     1,     8,     0,     1,     3,     2,     1,
       0,     2,     2,     4,     1,     3,     7,     0,     2,     2,
       0,     4,    10,     1,     1,     7,     1,     1,     0,     3,
       1,     3,     1,     0,     2,     2,     3,     4,     0,     2,
       3,     6,     0,     1,     3,     3,     1,     4,     4,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,   108,     1,    29,    64,    60,    61,    62,    63,     0,
       0,     0,     0,     0,     0,     0,   119,     0,     4,     0,
      23,     0,    34,    33,     0,     0,    22,    57,    59,    58,
      55,    56,    26,    27,    14,    87,    15,     3,     0,    24,
      25,    21,    65,    48,    29,    12,     0,    23,     0,     0,
       0,     5,     0,    84,    82,     0,     0,    75,     9,     0,
       0,     0,     0,     0,     0,     0,    10,    13,    35,    90,
       0,     0,   109,    66,     0,    44,     0,    52,     0,    49,
      11,     0,     0,    28,     0,     6,     7,     0,     0,    79,
       0,     0,    76,    16,    17,    18,    19,    20,    38,    31,
       0,     0,    88,    85,    96,    97,    98,     0,    30,     0,
       0,    53,    51,    45,     0,     0,     0,     0,    83,     8,
     117,   118,    78,    80,     0,    65,    40,    36,    37,     5,
      89,     0,     0,   112,   110,    67,    47,     0,    50,     5,
       0,    35,     0,     0,    77,     0,    43,     0,    41,     0,
     102,     0,   100,   103,     0,    54,   116,     0,   113,     0,
       0,     0,    81,     5,    32,    39,     0,    91,    99,     0,
     108,     0,     0,     0,    46,    86,     0,     0,    42,   101,
      95,   104,   105,     0,   115,   111,   114,     5,    74,    93,
      94,     0,     0,     0,     0,   106,    92,   107,    35,    70,
      73,     0,    71,     0,     0,     5,    69,    72,     0,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    84,    85,    86,    19,    47,    21,    22,    23,
      24,   128,   147,   148,    25,    78,    79,   112,   156,    26,
      27,    28,    29,    30,    31,    74,   195,   201,   202,    32,
      91,    92,   143,    33,    54,    34,    35,    69,   102,   103,
      36,   191,    37,   106,   132,   151,   152,   170,   181,   182,
      38,    72,   157,   158,    39,    40,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -117
static const yytype_int16 yypact[] =
{
    -117,   136,  -117,    18,  -117,  -117,  -117,  -117,  -117,   177,
     -13,    23,   184,    14,    25,    40,  -117,    57,  -117,   198,
      37,    64,  -117,  -117,    70,   106,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,    15,  -117,
    -117,  -117,   184,     3,   109,  -117,   205,    92,   184,   112,
      88,    73,    37,  -117,  -117,   130,   131,   132,  -117,   184,
     184,   184,   184,   184,   184,   134,  -117,  -117,   110,   133,
     101,   149,  -117,   167,    19,   129,   130,   152,    69,  -117,
    -117,   137,   130,  -117,   138,    73,  -117,   141,   -15,     7,
     154,    26,  -117,    83,    83,  -117,  -117,   211,   167,   143,
      22,    39,  -117,  -117,  -117,  -117,   140,    77,  -117,   184,
     142,  -117,  -117,  -117,     4,   146,   161,   176,  -117,  -117,
    -117,  -117,  -117,   164,   132,   184,   184,   167,  -117,    73,
    -117,   191,   187,   122,  -117,   167,  -117,   130,  -117,    73,
     184,  -117,   130,   188,  -117,    27,   167,    67,  -117,   175,
    -117,    78,  -117,  -117,   185,  -117,  -117,    34,  -117,   194,
     200,   178,  -117,    73,  -117,  -117,   184,  -117,  -117,   191,
     206,   224,   212,   122,  -117,  -117,   220,   225,  -117,  -117,
    -117,  -117,  -117,    -2,  -117,  -117,  -117,    73,  -117,  -117,
    -117,   130,   226,   221,   245,  -117,  -117,  -117,   232,   130,
    -117,    63,  -117,    -9,   130,    73,  -117,  -117,   230,  -117
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,  -116,  -117,     2,     6,    -1,  -117,   -81,  -117,
     239,  -117,  -117,    87,   -41,  -117,   144,  -117,    84,  -117,
    -117,  -117,  -117,  -117,  -117,   135,  -117,  -117,    50,  -117,
    -117,   139,  -117,  -117,  -117,  -117,   155,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,    90,  -117,  -117,  -117,
      91,  -117,  -117,    89,  -117,  -117,  -117
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -45
static const yytype_int16 yytable[] =
{
      20,   116,    77,    18,   121,    48,    75,    75,   189,   190,
     -44,   205,    52,   149,    87,    46,    90,    44,    50,   206,
      71,   -44,    65,   160,    70,    44,     4,     5,     6,     7,
       8,    43,    76,   137,    51,   110,    42,    71,   108,    49,
      12,   117,    43,    55,   126,   123,   164,   177,    73,   109,
      20,    13,    10,   172,    81,    88,   124,   109,    56,   129,
      14,    15,    16,    17,   173,    93,    94,    95,    96,    97,
      98,   192,    64,    77,    65,    57,     3,     4,     5,     6,
       7,     8,   203,    90,    20,     9,    10,   119,    11,   208,
     165,    12,    66,   204,   113,   133,   159,   166,    67,   114,
     134,   162,    13,   168,   104,   105,   127,    83,   169,    68,
     193,    14,    15,    16,    17,   135,    61,    62,   200,    59,
      60,    61,    62,   200,    63,   154,   155,    42,    20,    65,
      82,    73,   146,    75,    44,    89,     2,    99,    20,     3,
       4,     5,     6,     7,     8,   100,   161,   101,     9,    10,
     194,    11,   107,    43,    12,   111,   115,   122,   117,   118,
     120,   125,    20,   117,   131,    13,   139,   136,    59,    60,
      61,    62,   146,    63,    14,    15,    16,    17,   140,   141,
      44,     4,     5,     6,     7,     8,    20,    44,     4,     5,
       6,     7,     8,   142,   150,    12,   167,   176,    59,    60,
      61,    62,    12,    63,    20,    45,    13,   153,   163,    59,
      60,    61,    62,    13,    63,    14,    15,    16,    17,   174,
     171,   175,    14,    15,    16,    17,    58,   180,   155,    59,
      60,    61,    62,    80,    63,   185,    59,    60,    61,    62,
     187,    63,    59,    60,    61,    62,   188,   196,   198,   197,
     199,   209,    53,   178,   207,   184,   130,     0,   138,   179,
     145,   183,   186,   144
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-117))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       1,    82,    43,     1,    19,    18,     3,     3,    10,    11,
       3,    20,    13,   129,    55,     9,    57,     3,    12,    28,
      22,     3,    37,   139,     9,     3,     4,     5,     6,     7,
       8,    24,    29,    29,    20,    76,    18,    22,    19,    16,
      18,    82,    24,    18,    22,    19,    19,   163,    42,    30,
      51,    29,    13,    19,    48,    56,    30,    30,    18,    20,
      38,    39,    40,    41,    30,    59,    60,    61,    62,    63,
      64,   187,    35,   114,    37,    18,     3,     4,     5,     6,
       7,     8,    19,   124,    85,    12,    13,    85,    15,   205,
      23,    18,    28,    30,    25,    18,   137,    30,    28,    30,
      23,   142,    29,    25,     3,     4,   100,    19,    30,     3,
     191,    38,    39,    40,    41,   109,    33,    34,   199,    31,
      32,    33,    34,   204,    36,     3,     4,    18,   129,    37,
      18,   125,   126,     3,     3,     3,     0,     3,   139,     3,
       4,     5,     6,     7,     8,    35,   140,    14,    12,    13,
     191,    15,     3,    24,    18,     3,    19,     3,   199,    21,
      19,    18,   163,   204,    24,    29,    20,    25,    31,    32,
      33,    34,   166,    36,    38,    39,    40,    41,    17,     3,
       3,     4,     5,     6,     7,     8,   187,     3,     4,     5,
       6,     7,     8,    29,     3,    18,    21,    19,    31,    32,
      33,    34,    18,    36,   205,    28,    29,    20,    20,    31,
      32,    33,    34,    29,    36,    38,    39,    40,    41,    25,
      35,    21,    38,    39,    40,    41,    28,    21,     4,    31,
      32,    33,    34,    28,    36,    23,    31,    32,    33,    34,
      20,    36,    31,    32,    33,    34,    21,    21,     3,    28,
      18,    21,    13,   166,   204,   171,   101,    -1,   114,   169,
     125,   170,   173,   124
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,     0,     3,     4,     5,     6,     7,     8,    12,
      13,    15,    18,    29,    38,    39,    40,    41,    46,    47,
      48,    49,    50,    51,    52,    56,    61,    62,    63,    64,
      65,    66,    71,    75,    77,    78,    82,    84,    92,    96,
      97,    98,    18,    24,     3,    28,    47,    48,    18,    16,
      47,    20,    48,    52,    76,    18,    18,    18,    28,    31,
      32,    33,    34,    36,    35,    37,    28,    28,     3,    79,
       9,    22,    93,    47,    67,     3,    29,    56,    57,    58,
      28,    47,    18,    19,    44,    45,    46,    56,    48,     3,
      56,    72,    73,    47,    47,    47,    47,    47,    47,     3,
      35,    14,    80,    81,     3,     4,    85,     3,    19,    30,
      56,     3,    59,    25,    30,    19,    50,    56,    21,    46,
      19,    19,     3,    19,    30,    18,    22,    47,    53,    20,
      78,    24,    86,    18,    23,    47,    25,    29,    58,    20,
      17,     3,    29,    74,    73,    67,    47,    54,    55,    44,
       3,    87,    88,    20,     3,     4,    60,    94,    95,    56,
      44,    47,    56,    20,    19,    23,    30,    21,    25,    30,
      89,    35,    19,    30,    25,    21,    19,    44,    55,    88,
      21,    90,    91,    92,    60,    23,    95,    20,    21,    10,
      11,    83,    44,    50,    56,    68,    21,    28,     3,    18,
      50,    69,    70,    19,    30,    20,    28,    70,    44,    21
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (&yylloc, scanner, parser, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc, scanner)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location, scanner, parser); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *scanner, qip_parser *parser)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, scanner, parser)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    void *scanner;
    qip_parser *parser;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (parser);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *scanner, qip_parser *parser)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, scanner, parser)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    void *scanner;
    qip_parser *parser;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, scanner, parser);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, void *scanner, qip_parser *parser)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, scanner, parser)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    void *scanner;
    qip_parser *parser;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , scanner, parser);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, scanner, parser); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void *scanner, qip_parser *parser)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, scanner, parser)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    void *scanner;
    qip_parser *parser;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (parser);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void *scanner, qip_parser *parser);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *scanner, qip_parser *parser)
#else
int
yyparse (scanner, parser)
    void *scanner;
    qip_parser *parser;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1821 of yacc.c  */
#line 114 "src/parser.y"
    { qip_ast_module_add_class(root, (yyvsp[(2) - (2)].node)); }
    break;

  case 4:

/* Line 1821 of yacc.c  */
#line 115 "src/parser.y"
    { qip_ast_block_add_expr(root->module.main_function->function.body, (yyvsp[(2) - (2)].node)); }
    break;

  case 5:

/* Line 1821 of yacc.c  */
#line 118 "src/parser.y"
    { (yyval.node) = NULL; }
    break;

  case 6:

/* Line 1821 of yacc.c  */
#line 119 "src/parser.y"
    { (yyval.node) = qip_ast_block_create(NULL, (qip_ast_node**)(yyvsp[(1) - (1)].array)->elements, (yyvsp[(1) - (1)].array)->length); qip_set_pos((yyval.node), &(yyloc)); qip_array_free((yyvsp[(1) - (1)].array)); }
    break;

  case 7:

/* Line 1821 of yacc.c  */
#line 121 "src/parser.y"
    { (yyval.array) = qip_array_create(); qip_array_push((yyval.array), (yyvsp[(1) - (1)].node)); }
    break;

  case 8:

/* Line 1821 of yacc.c  */
#line 122 "src/parser.y"
    { qip_array_push((yyvsp[(1) - (2)].array), (yyvsp[(2) - (2)].node)); }
    break;

  case 11:

/* Line 1821 of yacc.c  */
#line 126 "src/parser.y"
    { (yyval.node) = qip_ast_freturn_create((yyvsp[(2) - (3)].node)); qip_set_pos((yyval.node), &(yyloc)); }
    break;

  case 12:

/* Line 1821 of yacc.c  */
#line 127 "src/parser.y"
    { (yyval.node) = qip_ast_freturn_create(NULL); qip_set_pos((yyval.node), &(yyloc)); }
    break;

  case 16:

/* Line 1821 of yacc.c  */
#line 133 "src/parser.y"
    { (yyval.node) = qip_ast_binary_expr_create(QIP_BINOP_PLUS, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); qip_set_pos((yyval.node), &(yyloc)); }
    break;

  case 17:

/* Line 1821 of yacc.c  */
#line 134 "src/parser.y"
    { (yyval.node) = qip_ast_binary_expr_create(QIP_BINOP_MINUS, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); qip_set_pos((yyval.node), &(yyloc)); }
    break;

  case 18:

/* Line 1821 of yacc.c  */
#line 135 "src/parser.y"
    { (yyval.node) = qip_ast_binary_expr_create(QIP_BINOP_MUL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); qip_set_pos((yyval.node), &(yyloc)); }
    break;

  case 19:

/* Line 1821 of yacc.c  */
#line 136 "src/parser.y"
    { (yyval.node) = qip_ast_binary_expr_create(QIP_BINOP_DIV, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); qip_set_pos((yyval.node), &(yyloc)); }
    break;

  case 20:

/* Line 1821 of yacc.c  */
#line 137 "src/parser.y"
    { (yyval.node) = qip_ast_binary_expr_create(QIP_BINOP_EQUALS, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); qip_set_pos((yyval.node), &(yyloc)); }
    break;

  case 28:

/* Line 1821 of yacc.c  */
#line 145 "src/parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 29:

/* Line 1821 of yacc.c  */
#line 149 "src/parser.y"
    {
              (yyval.node) = qip_ast_var_ref_create_value((yyvsp[(1) - (1)].string));
              qip_set_pos((yyval.node), &(yyloc));
              bdestroy((yyvsp[(1) - (1)].string));
          }
    break;

  case 30:

/* Line 1821 of yacc.c  */
#line 155 "src/parser.y"
    {
            (yyval.node) = qip_ast_var_ref_create_invoke((yyvsp[(1) - (4)].string), (qip_ast_node**)(yyvsp[(3) - (4)].array)->elements, (yyvsp[(3) - (4)].array)->length);
            qip_set_pos((yyval.node), &(yyloc));
            bdestroy((yyvsp[(1) - (4)].string));
            free((yyvsp[(3) - (4)].array));
        }
    break;

  case 31:

/* Line 1821 of yacc.c  */
#line 162 "src/parser.y"
    {
              (yyval.node) = (yyvsp[(1) - (3)].node);
              qip_ast_node *node = qip_ast_var_ref_create_value((yyvsp[(3) - (3)].string));
              qip_set_pos(node, &(yyloc));
              qip_ast_var_ref_set_member((yyvsp[(1) - (3)].node), node);
              bdestroy((yyvsp[(3) - (3)].string));
          }
    break;

  case 32:

/* Line 1821 of yacc.c  */
#line 170 "src/parser.y"
    {
              (yyval.node) = (yyvsp[(1) - (6)].node);
              qip_ast_node *node = qip_ast_var_ref_create_invoke((yyvsp[(3) - (6)].string), (qip_ast_node**)(yyvsp[(5) - (6)].array)->elements, (yyvsp[(5) - (6)].array)->length);
              qip_set_pos(node, &(yyloc));
              qip_ast_var_ref_set_member((yyvsp[(1) - (6)].node), node);
              bdestroy((yyvsp[(3) - (6)].string)); 
              free((yyvsp[(5) - (6)].array));
          }
    break;

  case 35:

/* Line 1821 of yacc.c  */
#line 185 "src/parser.y"
    {
                            (yyval.node) = qip_ast_var_decl_create((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].string), NULL);
                            qip_set_pos((yyval.node), &(yyloc));
                            bdestroy((yyvsp[(2) - (2)].string));
                         }
    break;

  case 36:

/* Line 1821 of yacc.c  */
#line 193 "src/parser.y"
    {
                           (yyval.node) = qip_ast_var_decl_create((yyvsp[(1) - (4)].node), (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].node));
                           qip_set_pos((yyval.node), &(yyloc));
                           bdestroy((yyvsp[(2) - (4)].string));
                       }
    break;

  case 37:

/* Line 1821 of yacc.c  */
#line 199 "src/parser.y"
    {
                           (yyval.node) = qip_ast_var_decl_create((yyvsp[(1) - (4)].node), (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].node));
                           qip_set_pos((yyval.node), &(yyloc));
                           bdestroy((yyvsp[(2) - (4)].string));
                       }
    break;

  case 38:

/* Line 1821 of yacc.c  */
#line 206 "src/parser.y"
    { (yyval.node) = qip_ast_var_assign_create((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); qip_set_pos((yyval.node), &(yyloc)); }
    break;

  case 39:

/* Line 1821 of yacc.c  */
#line 209 "src/parser.y"
    {
                    (yyval.node) = qip_ast_array_literal_create();
                    qip_ast_array_literal_add_items((yyval.node), (qip_ast_node **)(yyvsp[(2) - (3)].array)->elements, (yyvsp[(2) - (3)].array)->length);
                    qip_set_pos((yyval.node), &(yyloc));
                    qip_array_free((yyvsp[(2) - (3)].array));
                }
    break;

  case 40:

/* Line 1821 of yacc.c  */
#line 217 "src/parser.y"
    { (yyval.array) = qip_array_create(); }
    break;

  case 41:

/* Line 1821 of yacc.c  */
#line 218 "src/parser.y"
    { (yyval.array) = qip_array_create(); qip_array_push((yyval.array), (yyvsp[(1) - (1)].node)); }
    break;

  case 42:

/* Line 1821 of yacc.c  */
#line 219 "src/parser.y"
    { qip_array_push((yyvsp[(1) - (3)].array), (yyvsp[(3) - (3)].node)); }
    break;

  case 44:

/* Line 1821 of yacc.c  */
#line 226 "src/parser.y"
    {
               (yyval.node) = qip_ast_type_ref_create((yyvsp[(1) - (1)].string));
               qip_set_pos((yyval.node), &(yyloc));
           }
    break;

  case 45:

/* Line 1821 of yacc.c  */
#line 231 "src/parser.y"
    {
               (yyval.node) = qip_ast_type_ref_create((yyvsp[(1) - (4)].string));
               qip_ast_type_ref_add_subtypes((yyval.node), (qip_ast_node**)(yyvsp[(3) - (4)].array)->elements, (yyvsp[(3) - (4)].array)->length);
               qip_set_pos((yyval.node), &(yyloc));
               free((yyvsp[(3) - (4)].array));
           }
    break;

  case 46:

/* Line 1821 of yacc.c  */
#line 238 "src/parser.y"
    {
               (yyval.node) = qip_ast_type_ref_create((yyvsp[(1) - (7)].string));
               qip_ast_type_ref_add_subtypes((yyval.node), (qip_ast_node**)(yyvsp[(3) - (7)].array)->elements, (yyvsp[(3) - (7)].array)->length);
               qip_ast_type_ref_set_return_type((yyval.node), (yyvsp[(6) - (7)].node));
               qip_set_pos((yyval.node), &(yyloc));
               free((yyvsp[(3) - (7)].array));
           }
    break;

  case 47:

/* Line 1821 of yacc.c  */
#line 246 "src/parser.y"
    {
               (yyval.node) = qip_ast_type_ref_create((yyvsp[(1) - (5)].string));
               qip_ast_type_ref_set_return_type((yyval.node), (yyvsp[(4) - (5)].node));
               qip_set_pos((yyval.node), &(yyloc));
           }
    break;

  case 48:

/* Line 1821 of yacc.c  */
#line 253 "src/parser.y"
    { (yyval.array) = qip_array_create(); }
    break;

  case 49:

/* Line 1821 of yacc.c  */
#line 254 "src/parser.y"
    { (yyval.array) = qip_array_create(); qip_array_push((yyval.array), (yyvsp[(1) - (1)].node)); }
    break;

  case 50:

/* Line 1821 of yacc.c  */
#line 255 "src/parser.y"
    { qip_array_push((yyvsp[(1) - (3)].array), (yyvsp[(3) - (3)].node)); }
    break;

  case 51:

/* Line 1821 of yacc.c  */
#line 259 "src/parser.y"
    {
                      (yyval.node) = (yyvsp[(1) - (2)].node);
                      qip_ast_type_ref_set_arg_name((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].string));
                  }
    break;

  case 52:

/* Line 1821 of yacc.c  */
#line 265 "src/parser.y"
    { (yyval.string) = NULL; }
    break;

  case 60:

/* Line 1821 of yacc.c  */
#line 280 "src/parser.y"
    { (yyval.node) = qip_ast_int_literal_create((yyvsp[(1) - (1)].int_value)); qip_set_pos((yyval.node), &(yyloc)); }
    break;

  case 61:

/* Line 1821 of yacc.c  */
#line 282 "src/parser.y"
    { (yyval.node) = qip_ast_float_literal_create((yyvsp[(1) - (1)].float_value)); qip_set_pos((yyval.node), &(yyloc)); }
    break;

  case 62:

/* Line 1821 of yacc.c  */
#line 284 "src/parser.y"
    { (yyval.node) = qip_ast_boolean_literal_create(true); qip_set_pos((yyval.node), &(yyloc)); }
    break;

  case 63:

/* Line 1821 of yacc.c  */
#line 285 "src/parser.y"
    { (yyval.node) = qip_ast_boolean_literal_create(false); qip_set_pos((yyval.node), &(yyloc)); }
    break;

  case 64:

/* Line 1821 of yacc.c  */
#line 288 "src/parser.y"
    { (yyval.node) = qip_ast_string_literal_create((yyvsp[(1) - (1)].string)); qip_set_pos((yyval.node), &(yyloc)); }
    break;

  case 65:

/* Line 1821 of yacc.c  */
#line 290 "src/parser.y"
    { (yyval.array) = qip_array_create(); }
    break;

  case 66:

/* Line 1821 of yacc.c  */
#line 291 "src/parser.y"
    { (yyval.array) = qip_array_create(); qip_array_push((yyval.array), (yyvsp[(1) - (1)].node)); }
    break;

  case 67:

/* Line 1821 of yacc.c  */
#line 292 "src/parser.y"
    { qip_array_push((yyvsp[(1) - (3)].array), (yyvsp[(3) - (3)].node)); }
    break;

  case 68:

/* Line 1821 of yacc.c  */
#line 296 "src/parser.y"
    {
               (yyval.node) = qip_ast_function_create((yyvsp[(2) - (8)].string), (yyvsp[(1) - (8)].node), (qip_ast_node **)(yyvsp[(4) - (8)].array)->elements, (yyvsp[(4) - (8)].array)->length, (yyvsp[(7) - (8)].node));
               qip_set_pos((yyval.node), &(yyloc));
               bdestroy((yyvsp[(2) - (8)].string));
               qip_array_free((yyvsp[(4) - (8)].array));
           }
    break;

  case 69:

/* Line 1821 of yacc.c  */
#line 304 "src/parser.y"
    {
               (yyval.node) = qip_ast_function_create((yyvsp[(2) - (6)].string), (yyvsp[(1) - (6)].node), (qip_ast_node **)(yyvsp[(4) - (6)].array)->elements, (yyvsp[(4) - (6)].array)->length, NULL);
               qip_set_pos((yyval.node), &(yyloc));
               bdestroy((yyvsp[(2) - (6)].string));
               qip_array_free((yyvsp[(4) - (6)].array));
           }
    break;

  case 70:

/* Line 1821 of yacc.c  */
#line 312 "src/parser.y"
    { (yyval.array) = qip_array_create(); }
    break;

  case 71:

/* Line 1821 of yacc.c  */
#line 313 "src/parser.y"
    { (yyval.array) = qip_array_create(); qip_array_push((yyval.array), (yyvsp[(1) - (1)].node)); }
    break;

  case 72:

/* Line 1821 of yacc.c  */
#line 314 "src/parser.y"
    { qip_array_push((yyvsp[(1) - (3)].array), (yyvsp[(3) - (3)].node)); }
    break;

  case 73:

/* Line 1821 of yacc.c  */
#line 317 "src/parser.y"
    { (yyval.node) = qip_ast_farg_create((yyvsp[(1) - (1)].node)); qip_set_pos((yyval.node), &(yyloc)); }
    break;

  case 74:

/* Line 1821 of yacc.c  */
#line 320 "src/parser.y"
    {
                    (yyval.node) = qip_ast_function_create(NULL, (yyvsp[(5) - (8)].node), (qip_ast_node **)(yyvsp[(3) - (8)].array)->elements, (yyvsp[(3) - (8)].array)->length, (yyvsp[(7) - (8)].node));
                    qip_set_pos((yyval.node), &(yyloc));
                    qip_array_free((yyvsp[(3) - (8)].array));
                }
    break;

  case 75:

/* Line 1821 of yacc.c  */
#line 327 "src/parser.y"
    { (yyval.array) = qip_array_create(); }
    break;

  case 76:

/* Line 1821 of yacc.c  */
#line 328 "src/parser.y"
    { (yyval.array) = qip_array_create(); qip_array_push((yyval.array), (yyvsp[(1) - (1)].node)); }
    break;

  case 77:

/* Line 1821 of yacc.c  */
#line 329 "src/parser.y"
    { qip_array_push((yyvsp[(1) - (3)].array), (yyvsp[(3) - (3)].node)); }
    break;

  case 78:

/* Line 1821 of yacc.c  */
#line 333 "src/parser.y"
    {
                  qip_ast_node *var_decl = qip_ast_var_decl_create((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].string), NULL);
                  qip_set_pos(var_decl, &(yyloc));
                  (yyval.node) = qip_ast_farg_create(var_decl);
                  qip_set_pos((yyval.node), &(yyloc));
                  bdestroy((yyvsp[(2) - (2)].string));
              }
    break;

  case 79:

/* Line 1821 of yacc.c  */
#line 341 "src/parser.y"
    {
                  qip_ast_node *var_decl = qip_ast_var_decl_create(NULL, (yyvsp[(1) - (1)].string), NULL);
                  qip_set_pos(var_decl, &(yyloc));
                  (yyval.node) = qip_ast_farg_create(var_decl);
                  qip_set_pos((yyval.node), &(yyloc));
                  bdestroy((yyvsp[(1) - (1)].string));
              }
    break;

  case 80:

/* Line 1821 of yacc.c  */
#line 350 "src/parser.y"
    { (yyval.node) = NULL; }
    break;

  case 81:

/* Line 1821 of yacc.c  */
#line 351 "src/parser.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 82:

/* Line 1821 of yacc.c  */
#line 355 "src/parser.y"
    {
                     qip_ast_node *exprs[1];
                     exprs[0] = (yyvsp[(2) - (2)].node);
                     qip_ast_node *block = qip_ast_block_create(NULL, exprs, 1);
                     qip_set_pos(block, &(yyloc));
                     (yyval.node) = qip_ast_function_create(NULL, NULL, NULL, 0, block);
                     (yyval.node)->function.bound = false;
                     qip_set_pos((yyval.node), &(yyloc));
                 }
    break;

  case 83:

/* Line 1821 of yacc.c  */
#line 365 "src/parser.y"
    {
                     (yyval.node) = qip_ast_function_create(NULL, NULL, NULL, 0, (yyvsp[(3) - (4)].node));
                     (yyval.node)->function.bound = false;
                     qip_set_pos((yyval.node), &(yyloc));
                 }
    break;

  case 85:

/* Line 1821 of yacc.c  */
#line 376 "src/parser.y"
    {
              (yyval.node) = qip_ast_if_stmt_create();
              qip_set_pos((yyval.node), &(yyloc));
              qip_ast_if_stmt_add_block((yyval.node), (yyvsp[(1) - (3)].if_block).condition, (yyvsp[(1) - (3)].if_block).block);
              qip_ast_if_stmt_add_blocks((yyval.node), (qip_ast_node**)(yyvsp[(2) - (3)].if_blocks).conditions->elements, (qip_ast_node**)(yyvsp[(2) - (3)].if_blocks).blocks->elements, (yyvsp[(2) - (3)].if_blocks).blocks->length);
              qip_ast_if_stmt_set_else_block((yyval.node), (yyvsp[(3) - (3)].node));
              qip_array_free((yyvsp[(2) - (3)].if_blocks).conditions);
              qip_array_free((yyvsp[(2) - (3)].if_blocks).blocks);
          }
    break;

  case 86:

/* Line 1821 of yacc.c  */
#line 387 "src/parser.y"
    { (yyval.if_block).condition = (yyvsp[(3) - (7)].node); (yyval.if_block).block = (yyvsp[(6) - (7)].node); }
    break;

  case 87:

/* Line 1821 of yacc.c  */
#line 389 "src/parser.y"
    { (yyval.if_blocks).conditions = qip_array_create(); (yyval.if_blocks).blocks = qip_array_create(); }
    break;

  case 88:

/* Line 1821 of yacc.c  */
#line 390 "src/parser.y"
    { qip_array_push((yyvsp[(1) - (2)].if_blocks).conditions, (yyvsp[(2) - (2)].if_block).condition); qip_array_push((yyvsp[(1) - (2)].if_blocks).blocks, (yyvsp[(2) - (2)].if_block).block); }
    break;

  case 89:

/* Line 1821 of yacc.c  */
#line 393 "src/parser.y"
    { (yyval.if_block) = (yyvsp[(2) - (2)].if_block); }
    break;

  case 90:

/* Line 1821 of yacc.c  */
#line 395 "src/parser.y"
    { (yyval.node) = NULL; }
    break;

  case 91:

/* Line 1821 of yacc.c  */
#line 396 "src/parser.y"
    { (yyval.node) = (yyvsp[(3) - (4)].node); }
    break;

  case 92:

/* Line 1821 of yacc.c  */
#line 400 "src/parser.y"
    {
                    (yyval.node) = qip_ast_for_each_stmt_create((yyvsp[(4) - (10)].node), (yyvsp[(6) - (10)].node), (yyvsp[(9) - (10)].node));
                    qip_set_pos((yyval.node), &(yyloc));
                }
    break;

  case 93:

/* Line 1821 of yacc.c  */
#line 406 "src/parser.y"
    { (yyval.access) = QIP_ACCESS_PUBLIC; }
    break;

  case 94:

/* Line 1821 of yacc.c  */
#line 407 "src/parser.y"
    { (yyval.access) = QIP_ACCESS_PRIVATE; }
    break;

  case 95:

/* Line 1821 of yacc.c  */
#line 411 "src/parser.y"
    {
            (yyval.node) = qip_ast_class_create((yyvsp[(3) - (7)].string), NULL, 0, NULL, 0);
            qip_ast_class_add_template_vars((yyval.node), (qip_ast_node**)(yyvsp[(4) - (7)].array)->elements, (yyvsp[(4) - (7)].array)->length);
            qip_ast_class_add_members((yyval.node), (qip_ast_node**)(yyvsp[(6) - (7)].array)->elements, (yyvsp[(6) - (7)].array)->length);
            qip_ast_class_add_metadatas((yyval.node), (qip_ast_node**)(yyvsp[(1) - (7)].array)->elements, (yyvsp[(1) - (7)].array)->length);
            bdestroy((yyvsp[(3) - (7)].string));
            free((yyvsp[(1) - (7)].array));
            free((yyvsp[(4) - (7)].array));
            free((yyvsp[(6) - (7)].array));
        }
    break;

  case 98:

/* Line 1821 of yacc.c  */
#line 425 "src/parser.y"
    { (yyval.array) = qip_array_create(); }
    break;

  case 99:

/* Line 1821 of yacc.c  */
#line 426 "src/parser.y"
    { (yyval.array) = (yyvsp[(2) - (3)].array); }
    break;

  case 100:

/* Line 1821 of yacc.c  */
#line 429 "src/parser.y"
    { (yyval.array) = qip_array_create(); qip_array_push((yyval.array), (yyvsp[(1) - (1)].node)); }
    break;

  case 101:

/* Line 1821 of yacc.c  */
#line 430 "src/parser.y"
    { qip_array_push((yyvsp[(1) - (3)].array), (yyvsp[(3) - (3)].node)); }
    break;

  case 102:

/* Line 1821 of yacc.c  */
#line 433 "src/parser.y"
    { (yyval.node) = qip_ast_template_var_create((yyvsp[(1) - (1)].string)); qip_set_pos((yyval.node), &(yyloc)); }
    break;

  case 103:

/* Line 1821 of yacc.c  */
#line 435 "src/parser.y"
    { (yyval.array) = qip_array_create(); }
    break;

  case 104:

/* Line 1821 of yacc.c  */
#line 436 "src/parser.y"
    { qip_array_push((yyval.array), (yyvsp[(2) - (2)].node)); }
    break;

  case 105:

/* Line 1821 of yacc.c  */
#line 437 "src/parser.y"
    { qip_array_push((yyval.array), (yyvsp[(2) - (2)].node)); }
    break;

  case 106:

/* Line 1821 of yacc.c  */
#line 441 "src/parser.y"
    {
              (yyval.node) = qip_ast_method_create((yyvsp[(2) - (3)].access), (yyvsp[(3) - (3)].node));
              qip_ast_method_add_metadatas((yyval.node), (qip_ast_node**)(yyvsp[(1) - (3)].array)->elements, (yyvsp[(1) - (3)].array)->length);
              qip_set_pos((yyval.node), &(yyloc));
              free((yyvsp[(1) - (3)].array));
          }
    break;

  case 107:

/* Line 1821 of yacc.c  */
#line 449 "src/parser.y"
    {
                (yyval.node) = qip_ast_property_create((yyvsp[(2) - (4)].access), (yyvsp[(3) - (4)].node));
                qip_ast_property_add_metadatas((yyval.node), (qip_ast_node**)(yyvsp[(1) - (4)].array)->elements, (yyvsp[(1) - (4)].array)->length);
                qip_set_pos((yyval.node), &(yylsp[(2) - (4)]));
                free((yyvsp[(1) - (4)].array));
            }
    break;

  case 108:

/* Line 1821 of yacc.c  */
#line 456 "src/parser.y"
    { (yyval.array) = qip_array_create(); }
    break;

  case 109:

/* Line 1821 of yacc.c  */
#line 457 "src/parser.y"
    { qip_array_push((yyval.array), (yyvsp[(2) - (2)].node)); }
    break;

  case 110:

/* Line 1821 of yacc.c  */
#line 460 "src/parser.y"
    { (yyval.node) = qip_ast_metadata_create((yyvsp[(2) - (3)].string), NULL, 0); qip_set_pos((yyval.node), &(yyloc)); bdestroy((yyvsp[(2) - (3)].string)); }
    break;

  case 111:

/* Line 1821 of yacc.c  */
#line 461 "src/parser.y"
    { (yyval.node) = qip_ast_metadata_create((yyvsp[(2) - (6)].string), (qip_ast_node**)(yyvsp[(4) - (6)].array)->elements, (yyvsp[(4) - (6)].array)->length); qip_set_pos((yyval.node), &(yyloc)); bdestroy((yyvsp[(2) - (6)].string)); free((yyvsp[(4) - (6)].array)); }
    break;

  case 112:

/* Line 1821 of yacc.c  */
#line 464 "src/parser.y"
    { (yyval.array) = qip_array_create(); }
    break;

  case 113:

/* Line 1821 of yacc.c  */
#line 465 "src/parser.y"
    { (yyval.array) = qip_array_create(); qip_array_push((yyval.array), (yyvsp[(1) - (1)].node)); }
    break;

  case 114:

/* Line 1821 of yacc.c  */
#line 466 "src/parser.y"
    { qip_array_push((yyvsp[(1) - (3)].array), (yyvsp[(3) - (3)].node)); }
    break;

  case 115:

/* Line 1821 of yacc.c  */
#line 469 "src/parser.y"
    { (yyval.node) = qip_ast_metadata_item_create((yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string)); qip_set_pos((yyval.node), &(yyloc)); bdestroy((yyvsp[(1) - (3)].string)); bdestroy((yyvsp[(3) - (3)].string)); }
    break;

  case 116:

/* Line 1821 of yacc.c  */
#line 470 "src/parser.y"
    { (yyval.node) = qip_ast_metadata_item_create(NULL, (yyvsp[(1) - (1)].string)); qip_set_pos((yyval.node), &(yyloc)); bdestroy((yyvsp[(1) - (1)].string)); }
    break;

  case 117:

/* Line 1821 of yacc.c  */
#line 472 "src/parser.y"
    { (yyval.node) = qip_ast_sizeof_create((yyvsp[(3) - (4)].node)); }
    break;

  case 118:

/* Line 1821 of yacc.c  */
#line 474 "src/parser.y"
    { (yyval.node) = qip_ast_offsetof_create((yyvsp[(3) - (4)].node)); }
    break;

  case 119:

/* Line 1821 of yacc.c  */
#line 476 "src/parser.y"
    { (yyval.node) = qip_ast_null_literal_create(); }
    break;



/* Line 1821 of yacc.c  */
#line 2514 "src/parser.c"
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
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, scanner, parser, YY_("syntax error"));
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
        yyerror (&yylloc, scanner, parser, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc, scanner, parser);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, scanner, parser);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, scanner, parser, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, scanner, parser);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, scanner, parser);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 478 "src/parser.y"



//==============================================================================
//
// Functions
//
//==============================================================================

//--------------------------------------
// Lifecycle
//--------------------------------------

// Creates a parser.
qip_parser *qip_parser_create()
{
    qip_parser *parser = calloc(sizeof(qip_parser), 1);
    check_mem(parser);
    return parser;
    
error:
    qip_parser_free(parser);
    return NULL;
}

// Frees a parser.
//
// parser - The parser to free.
void qip_parser_free(qip_parser *parser)
{
    if(parser) {
        qip_parser_free_errors(parser);
        free(parser);
    }
}


//--------------------------------------
// Parsing
//--------------------------------------

// Parses a string that contains QIP program text.
//
// name   - The name of the module.
// text   - The text for the QIP module.
// module - The pointer where the module AST should be returned.
//
// Returns 0 if successful, otherwise returns -1.
int qip_parser_parse(qip_parser *parser, bstring name, bstring text, qip_ast_node **module)
{
    int rc;
    check(parser != NULL, "Parser required");
    
    struct tagbstring mainFunctionName = bsStatic("main");
    //yydebug = 1;
    
    // Setup module.
    root = qip_ast_module_create(name, NULL, 0, NULL); check_mem(root);
    root->line_no = 0;
    
    // Setup main function.
    qip_ast_node *main_block = qip_ast_block_create(NULL, NULL, 0);
    check_mem(main_block);
    main_block->line_no = 0;

    root->module.main_function = qip_ast_function_create(&mainFunctionName, NULL, NULL, 0, main_block);
    check_mem(root->module.main_function);
    root->module.main_function->line_no = 0;
    
    // Parse using Bison.
    yyscan_t scanner;
    yylex_init(&scanner);
    YY_BUFFER_STATE buffer = yy_scan_string(bdata(text), scanner);
    rc = yyparse(scanner, parser);
    yy_delete_buffer(buffer, scanner);
    yylex_destroy(scanner);

    // If we have an error code but no errors then add an unknown error.
    if(rc != 0 && parser->error_count == 0) {
        struct tagbstring unknown_error_msg = bsStatic("Unknown error");
        rc = qip_parser_add_error(parser, 0, &unknown_error_msg);
        check(rc == 0, "Unable to add unknown error");
    }

    // If the main function is empty then remove it.
    if(root->module.main_function->function.body == NULL || root->module.main_function->function.body->block.expr_count == 0) {
        qip_ast_node_free(root->module.main_function);
        root->module.main_function = NULL;
    }

    // Return module to caller.
    *module = root;

    return 0;

error:
    return -1;
}


//--------------------------------------
// Error Management
//--------------------------------------

// Appends a parse error for a line onto the parser.
//
// parser  - The parser to add the error to.
// line_no - The line number that the error occurred.
// message - The error message.
//
// Returns 0 if successful, otherwise returns -1.
int qip_parser_add_error(qip_parser *parser, int32_t line_no, bstring message)
{
    check(parser != NULL, "Parser required");
    check(message != NULL, "Message required");

    // Create error.
    qip_error *err = qip_error_create(); check_mem(err);
    err->line_no = line_no;
    err->message = bstrcpy(message); check_mem(err->message);

    // Append to errors.
    parser->error_count++;
    parser->errors = realloc(parser->errors, sizeof(*parser->errors) * parser->error_count);
    check_mem(parser->errors);
    parser->errors[parser->error_count-1] = err;

    return 0;

error:
    qip_error_free(err);
    return -1;
}

// Clears all errors on the parser.
//
// parser  - The parser.
//
// Returns 0 if successful, otherwise returns -1.
int qip_parser_free_errors(qip_parser *parser)
{
    check(parser != NULL, "Parser required");
    
    uint32_t i;
    for(i=0; i<parser->error_count; i++) {
        qip_error *err = parser->errors[i];
        qip_error_free(err);
        parser->errors[i] = NULL;
    }
    free(parser->errors);
    parser->errors = NULL;
    parser->error_count = 0;
    
    return 0;

error:
    return -1;
}


//--------------------------------------
// Position
//--------------------------------------

// Assigns a Bison location to an AST node.
//
// node - The AST node.
// loc  - The Bison location object.
//
// Returns 0 if successful, otherwise returns -1.
int qip_set_pos(qip_ast_node *node, YYLTYPE *loc)
{
    node->line_no = (loc->first_line > 0 ? loc->first_line : 0);
    return 0;
}
