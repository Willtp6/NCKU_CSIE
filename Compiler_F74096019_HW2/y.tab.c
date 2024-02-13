/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "compiler_hw2.y"

    #include "compiler_hw_common.h" //Extern variables that communicate with lex
    #define YYDEBUG 1
    //int yydebug = 1;
    #include <string.h>
    typedef struct symbol {
		int Index;
        char *Name;
		char *Type;
		int Addr;
		int Lineno;
		char *Fs;
    }Symbol;    

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol();
    static void insert_symbol();
    static struct symbol lookup_symbol();
    static void dump_symbol();
	static char *top();
	static void pop_op();
	static void print_operator();
	static void error_check();

    /* Global variables */
    bool HAS_ERROR = false;
    int num_of_symbol[10] = {0};
	struct symbol symbol_table[10][10];
    int scope_level = -1;
	int address = 0;
	char func_sig[10][10];
	char *tmp_type;
	char *func_name;
	char *operation;
	char *tmp_str;
	int top_op = -1;
	char *op_stack[100];
	int precedence_stack[100];
	char *type_stack[100];
	int type_top = -1;

#line 127 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    VAR = 258,
    NEWLINE = 259,
    INT = 260,
    FLOAT = 261,
    BOOL = 262,
    STRING = 263,
    TRUE = 264,
    FALSE = 265,
    INC = 266,
    DEC = 267,
    GEQ = 268,
    LOR = 269,
    LAND = 270,
    LEQ = 271,
    EQL = 272,
    NEQ = 273,
    ADD_ASSIGN = 274,
    SUB_ASSIGN = 275,
    MUL_ASSIGN = 276,
    QUO_ASSIGN = 277,
    REM_ASSIGN = 278,
    IF = 279,
    ELSE = 280,
    FOR = 281,
    SWITCH = 282,
    CASE = 283,
    DEFAULT = 284,
    PRINT = 285,
    PRINTLN = 286,
    PACKAGE = 287,
    FUNC = 288,
    RETURN = 289,
    INT_LIT = 290,
    FLOAT_LIT = 291,
    STRING_LIT = 292,
    BOOL_LIT = 293,
    IDENT = 294
  };
#endif
/* Tokens.  */
#define VAR 258
#define NEWLINE 259
#define INT 260
#define FLOAT 261
#define BOOL 262
#define STRING 263
#define TRUE 264
#define FALSE 265
#define INC 266
#define DEC 267
#define GEQ 268
#define LOR 269
#define LAND 270
#define LEQ 271
#define EQL 272
#define NEQ 273
#define ADD_ASSIGN 274
#define SUB_ASSIGN 275
#define MUL_ASSIGN 276
#define QUO_ASSIGN 277
#define REM_ASSIGN 278
#define IF 279
#define ELSE 280
#define FOR 281
#define SWITCH 282
#define CASE 283
#define DEFAULT 284
#define PRINT 285
#define PRINTLN 286
#define PACKAGE 287
#define FUNC 288
#define RETURN 289
#define INT_LIT 290
#define FLOAT_LIT 291
#define STRING_LIT 292
#define BOOL_LIT 293
#define IDENT 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 67 "compiler_hw2.y"

    int i_val;
    float f_val;
    char *s_val;
    bool b_val;

#line 264 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   391

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  194

#define YYUNDEFTOK  2
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,    48,     2,     2,    55,     2,     2,
      40,    41,    53,    51,    42,    52,     2,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    46,
      49,    45,    50,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   100,   100,   104,   105,   109,   110,   111,   116,   116,
     120,   120,   121,   120,   126,   130,   130,   131,   132,   136,
     137,   138,   139,   143,   144,   145,   146,   147,   151,   155,
     159,   160,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   178,   182,   183,   184,   188,   189,   190,
     194,   198,   199,   203,   204,   205,   209,   213,   214,   215,
     216,   217,   218,   222,   226,   230,   231,   235,   235,   239,
     240,   244,   244,   248,   249,   253,   254,   258,   262,   262,
     263,   267,   271,   275,   279,   283,   283,   284,   288,   289,
     293,   294,   295,   296,   300,   301,   302,   303,   307,   308,
     312,   313,   314,   315,   316,   320,   321,   322,   323,   324,
     325,   329,   330,   334,   335,   336,   340,   341,   342,   342,
     346,   346,   347,   351,   353,   357,   358,   359,   359,   364,
     365,   366,   367,   371
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "NEWLINE", "INT", "FLOAT", "BOOL",
  "STRING", "TRUE", "FALSE", "INC", "DEC", "GEQ", "LOR", "LAND", "LEQ",
  "EQL", "NEQ", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN",
  "REM_ASSIGN", "IF", "ELSE", "FOR", "SWITCH", "CASE", "DEFAULT", "PRINT",
  "PRINTLN", "PACKAGE", "FUNC", "RETURN", "INT_LIT", "FLOAT_LIT",
  "STRING_LIT", "BOOL_LIT", "IDENT", "'('", "')'", "','", "'{'", "'}'",
  "'='", "';'", "':'", "'\"'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'!'", "$accept", "Program", "GlobalStatementList",
  "GlobalStatement", "PackageStmt", "$@1", "FunctionDeclStmt", "$@2",
  "$@3", "$@4", "FuncOpen", "ParameterList", "$@5", "ParamType",
  "ReturnType", "FuncBlock", "ReturnStmt", "HaveReturn", "Statement",
  "call_func", "input_list", "input", "DeclarationStmt", "Assign_ornot",
  "SimpleStmt", "AssignmentStmt", "assign_op", "ExpressionStmt",
  "IncDecStmt", "INC_DEC", "Block", "$@6", "StatementList", "IfStmt",
  "$@7", "If_Else", "If_Block", "Condition", "ForStmt", "$@8", "ForClause",
  "InitStmt", "PostStmt", "SwitchStmt", "CaseStmt", "$@9", "PrintStmt",
  "Type", "Expression", "UnaryExpr", "binary_op", "cmp_op", "add_op",
  "mul_op", "unary_op", "$@10", "Dup_Not", "$@11", "PrimaryExpr",
  "Operand", "$@12", "Literal", "ConversionExpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      40,    41,    44,   123,   125,    61,    59,    58,    34,    60,
      62,    43,    45,    42,    47,    37,    33
};
# endif

#define YYPACT_NINF (-133)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-119)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,  -133,   -22,   -19,    31,     5,  -133,    24,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,     8,  -133,   -23,    18,   -23,
       9,  -133,  -133,  -133,  -133,  -133,  -133,  -133,   -23,    34,
    -133,  -133,  -133,  -133,  -133,  -133,     6,   108,  -133,    12,
    -133,  -133,  -133,  -133,  -133,   147,   147,   147,    17,     7,
      13,    19,    28,  -133,  -133,  -133,  -133,    29,  -133,  -133,
      20,  -133,  -133,    54,   108,    67,    68,    70,  -133,  -133,
    -133,  -133,    33,  -133,  -133,  -133,  -133,    71,    41,   220,
    -133,   165,    22,  -133,  -133,  -133,  -133,    38,  -133,  -133,
     336,  -133,  -133,    39,    37,   207,   263,  -133,    39,   147,
     147,  -133,   336,   -21,   147,   108,    42,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,   147,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,   147,  -133,   147,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,    40,    39,    39,  -133,
     147,  -133,    44,  -133,   270,   285,  -133,  -133,  -133,   -21,
      45,   -21,   314,    43,  -133,   329,   336,   336,    22,   147,
    -133,    64,  -133,    47,    39,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,   336,   -13,  -133,   147,  -133,  -133,
    -133,  -133,  -133,  -133
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     0,     0,     0,     2,     4,     0,     6,    10,
       8,    14,     1,     3,     5,     0,     9,    18,     0,    18,
       0,    19,    20,    22,    21,    15,    17,    11,    18,    27,
      16,    23,    24,    26,    25,    12,     0,    70,    13,     0,
      41,    90,    91,    93,    92,   118,   118,   118,     0,     0,
       0,     0,    31,   129,   130,   132,   131,   126,   127,    67,
       0,   116,   117,     0,    70,    97,     0,     0,    53,    54,
      55,    34,     0,    35,    36,    37,    38,     0,     0,    63,
      94,   118,   122,    98,   123,   125,   124,     0,    97,    71,
      77,    82,    78,     0,     0,    63,     0,    85,     0,   118,
     118,    29,    30,    46,   118,    70,     0,    40,    69,    42,
      32,    33,    28,    39,   118,    65,    66,   110,   100,   101,
     108,   105,   106,    58,    59,    60,    61,    62,    57,   107,
     109,   111,   112,   113,   114,   115,   118,    64,   118,   102,
     103,   104,   126,    99,   120,   119,    52,     0,     0,    80,
     118,    84,     0,    87,     0,     0,    48,    49,    47,    46,
       0,    46,     0,     0,    96,     0,    56,    95,   122,   118,
      50,    74,    79,     0,     0,    88,    89,    45,    43,    44,
     128,    68,   133,   121,    51,     0,    72,   118,    86,    76,
      75,    73,    83,    81
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,    90,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,    -6,  -133,  -133,  -133,  -133,  -133,  -133,  -133,   -32,
    -132,  -133,  -133,  -133,   -46,  -133,  -133,  -133,  -133,  -133,
     -86,  -133,   -58,   -89,  -133,  -133,  -133,   -42,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,    10,   -44,    21,
    -133,  -133,  -133,  -133,  -133,  -133,   -70,  -133,  -133,  -133,
    -133,  -133,  -133
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    16,     8,    15,    29,    36,
       9,    20,    28,    25,    35,    38,    63,   101,    64,    88,
     160,   161,    66,   170,    67,    68,   136,    69,    70,   137,
      71,   105,    72,    73,   147,   186,   191,    89,    74,   148,
      93,    94,   193,    75,    76,   152,    77,    78,    79,    80,
     138,   139,   140,   141,    81,    82,   145,   168,    83,    84,
     104,    85,    86
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,    90,    95,    96,    92,    65,   108,   149,   102,     1,
     151,    45,   153,    26,   156,   157,    18,    10,   158,    19,
      11,   159,    30,    21,    22,    23,    24,   177,    14,   179,
      59,    12,    65,    41,    42,    43,    44,     2,     3,    31,
      32,    33,    34,    41,    42,    43,    44,   163,    17,    37,
      27,    87,    97,    99,    98,   154,   155,   106,   107,   100,
     162,   171,   172,    53,    54,    55,    56,    57,    58,   103,
     165,   109,   110,    65,   111,   113,    60,   112,   144,    61,
      62,   114,    59,   150,  -118,   169,   178,   181,   188,   185,
     164,   174,   166,   187,   167,    13,   190,   146,   183,   189,
       0,     0,   143,     0,     0,     0,    90,     0,   173,     0,
       0,    39,    40,    41,    42,    43,    44,     0,     0,     0,
       0,     0,     0,     0,     0,   184,     0,     0,     0,     0,
       0,     0,    45,     0,    46,    47,    48,    49,    50,    51,
       0,   192,    52,    53,    54,    55,    56,    57,    58,     0,
       0,    59,    41,    42,    43,    44,    60,     0,     0,    61,
      62,     0,     0,     0,  -118,     0,     0,     0,     0,     0,
      41,    42,    43,    44,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,     0,     0,
       0,     0,     0,     0,     0,    60,     0,     0,    61,    62,
      53,    54,    55,    56,   142,    58,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    62,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,     0,     0,     0,     0,     0,     0,
     -77,     0,   128,     0,     0,     0,   129,   130,   131,   132,
     133,   134,   135,     0,     0,   128,     0,     0,     0,   129,
     130,   131,   132,   133,   134,   135,   117,   118,   119,   120,
     121,   122,     0,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,     0,     0,    59,     0,     0,     0,
       0,   175,   129,   130,   131,   132,   133,   134,   135,   129,
     130,   131,   132,   133,   134,   135,   176,   117,   118,   119,
     120,   121,   122,     0,   129,   130,   131,   132,   133,   134,
     135,     0,   117,   118,   119,   120,   121,   122,     0,   117,
     118,   119,   120,   121,   122,   180,     0,     0,     0,     0,
       0,     0,     0,   129,   130,   131,   132,   133,   134,   135,
     182,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     131,   132,   133,   134,   135,   129,   130,   131,   132,   133,
     134,   135
};

static const yytype_int16 yycheck[] =
{
      46,    45,    46,    47,    46,    37,    64,    93,    52,     4,
      96,    24,    98,    19,    35,    36,    39,    39,    39,    42,
      39,    42,    28,     5,     6,     7,     8,   159,     4,   161,
      43,     0,    64,     5,     6,     7,     8,    32,    33,     5,
       6,     7,     8,     5,     6,     7,     8,   105,    40,    43,
      41,    39,    35,    40,    47,    99,   100,    37,     4,    40,
     104,   147,   148,    35,    36,    37,    38,    39,    40,    40,
     114,     4,     4,   105,     4,     4,    48,    44,    56,    51,
      52,    40,    43,    46,    56,    45,    41,    44,   174,    25,
      48,    47,   136,    46,   138,     5,   185,    87,   168,   185,
      -1,    -1,    81,    -1,    -1,    -1,   150,    -1,   150,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    26,    27,    28,    29,    30,    31,
      -1,   187,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    43,     5,     6,     7,     8,    48,    -1,    -1,    51,
      52,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    45,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    45,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    13,    14,    15,    16,
      17,    18,    -1,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    41,    49,    50,    51,    52,    53,    54,    55,    49,
      50,    51,    52,    53,    54,    55,    41,    13,    14,    15,
      16,    17,    18,    -1,    49,    50,    51,    52,    53,    54,
      55,    -1,    13,    14,    15,    16,    17,    18,    -1,    13,
      14,    15,    16,    17,    18,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    49,    50,    51,    52,    53,
      54,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    32,    33,    58,    59,    60,    61,    63,    67,
      39,    39,     0,    60,     4,    64,    62,    40,    39,    42,
      68,     5,     6,     7,     8,    70,    68,    41,    69,    65,
      68,     5,     6,     7,     8,    71,    66,    43,    72,     3,
       4,     5,     6,     7,     8,    24,    26,    27,    28,    29,
      30,    31,    34,    35,    36,    37,    38,    39,    40,    43,
      48,    51,    52,    73,    75,    76,    79,    81,    82,    84,
      85,    87,    89,    90,    95,   100,   101,   103,   104,   105,
     106,   111,   112,   115,   116,   118,   119,    39,    76,    94,
     105,    81,    94,    97,    98,   105,   105,    35,    47,    40,
      40,    74,   105,    40,   117,    88,    37,     4,    89,     4,
       4,     4,    44,     4,    40,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    45,    49,
      50,    51,    52,    53,    54,    55,    83,    86,   107,   108,
     109,   110,    39,   106,    56,   113,   104,    91,    96,    87,
      46,    87,   102,    87,   105,   105,    35,    36,    39,    42,
      77,    78,   105,    89,    48,   105,   105,   105,   114,    45,
      80,    87,    87,    94,    47,    41,    41,    77,    41,    77,
      41,    44,    41,   113,   105,    25,    92,    46,    87,    87,
      90,    93,    81,    99
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    60,    62,    61,
      64,    65,    66,    63,    67,    69,    68,    68,    68,    70,
      70,    70,    70,    71,    71,    71,    71,    71,    72,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    76,    77,    77,    77,    78,    78,    78,
      79,    80,    80,    81,    81,    81,    82,    83,    83,    83,
      83,    83,    83,    84,    85,    86,    86,    88,    87,    89,
      89,    91,    90,    92,    92,    93,    93,    94,    96,    95,
      95,    97,    98,    99,   100,   102,   101,   101,   103,   103,
     104,   104,   104,   104,   105,   105,   105,   105,   106,   106,
     107,   107,   107,   107,   107,   108,   108,   108,   108,   108,
     108,   109,   109,   110,   110,   110,   111,   111,   112,   111,
     114,   113,   113,   115,   115,   116,   116,   117,   116,   118,
     118,   118,   118,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     0,     3,
       0,     0,     0,     9,     2,     0,     4,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     2,
       1,     0,     2,     2,     1,     1,     1,     1,     1,     2,
       2,     1,     2,     4,     2,     2,     0,     1,     1,     1,
       4,     2,     0,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     0,     4,     2,
       0,     0,     5,     2,     0,     1,     1,     1,     0,     4,
       3,     5,     1,     1,     3,     0,     5,     3,     4,     4,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     2,
       0,     3,     0,     1,     1,     1,     1,     0,     4,     1,
       1,     1,     1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 100 "compiler_hw2.y"
                          { dump_symbol(scope_level--); }
#line 1638 "y.tab.c"
    break;

  case 8:
#line 116 "compiler_hw2.y"
                    { create_symbol(++scope_level); }
#line 1644 "y.tab.c"
    break;

  case 9:
#line 116 "compiler_hw2.y"
                                                      { printf("package: %s\n", (yyvsp[-1].s_val)); }
#line 1650 "y.tab.c"
    break;

  case 10:
#line 120 "compiler_hw2.y"
               { create_symbol(++scope_level); strcpy(func_sig[num_of_symbol[scope_level-1]],"("); }
#line 1656 "y.tab.c"
    break;

  case 11:
#line 120 "compiler_hw2.y"
                                                                                                                          {type_top = -1; strcat(func_sig[num_of_symbol[scope_level-1]], ")"); }
#line 1662 "y.tab.c"
    break;

  case 12:
#line 121 "compiler_hw2.y"
                     { printf("func_signature: %s\n", func_sig[num_of_symbol[scope_level-1]]); insert_symbol(func_name, "func", -1, yylineno+1, func_sig[num_of_symbol[scope_level-1]], scope_level-1); }
#line 1668 "y.tab.c"
    break;

  case 13:
#line 122 "compiler_hw2.y"
                    { dump_symbol(scope_level); scope_level--; }
#line 1674 "y.tab.c"
    break;

  case 14:
#line 126 "compiler_hw2.y"
                     { printf("func: %s\n", (yyvsp[0].s_val)); func_name = (yyvsp[0].s_val); }
#line 1680 "y.tab.c"
    break;

  case 15:
#line 130 "compiler_hw2.y"
                          { printf("param %s, type: %c\n", (yyvsp[-1].s_val), func_sig[num_of_symbol[scope_level-1]][strlen(func_sig[num_of_symbol[scope_level-1]])-1]); insert_symbol((yyvsp[-1].s_val), type_stack[type_top--], address++, yylineno+1, "-", scope_level); }
#line 1686 "y.tab.c"
    break;

  case 19:
#line 136 "compiler_hw2.y"
                 { strcat(func_sig[num_of_symbol[scope_level-1]],"I"); type_stack[++type_top] = "int32"; }
#line 1692 "y.tab.c"
    break;

  case 20:
#line 137 "compiler_hw2.y"
             { strcat(func_sig[num_of_symbol[scope_level-1]],"F"); type_stack[++type_top] = "float32"; }
#line 1698 "y.tab.c"
    break;

  case 21:
#line 138 "compiler_hw2.y"
             { strcat(func_sig[num_of_symbol[scope_level-1]],"S"); type_stack[++type_top] = "string"; }
#line 1704 "y.tab.c"
    break;

  case 22:
#line 139 "compiler_hw2.y"
             { strcat(func_sig[num_of_symbol[scope_level-1]],"B"); type_stack[++type_top] = "bool"; }
#line 1710 "y.tab.c"
    break;

  case 23:
#line 143 "compiler_hw2.y"
                 { strcat(func_sig[num_of_symbol[scope_level-1]],"I"); }
#line 1716 "y.tab.c"
    break;

  case 24:
#line 144 "compiler_hw2.y"
             { strcat(func_sig[num_of_symbol[scope_level-1]],"F"); }
#line 1722 "y.tab.c"
    break;

  case 25:
#line 145 "compiler_hw2.y"
             { strcat(func_sig[num_of_symbol[scope_level-1]],"S"); }
#line 1728 "y.tab.c"
    break;

  case 26:
#line 146 "compiler_hw2.y"
             { strcat(func_sig[num_of_symbol[scope_level-1]],"B"); }
#line 1734 "y.tab.c"
    break;

  case 27:
#line 147 "compiler_hw2.y"
          { strcat(func_sig[num_of_symbol[scope_level-1]],"V"); }
#line 1740 "y.tab.c"
    break;

  case 30:
#line 159 "compiler_hw2.y"
                     { print_operator(7); if(strcmp(type_stack[type_top--], "int32") == 0){ printf("ireturn\n"); } if(strcmp(type_stack[type_top--], "float32") == 0){ printf("freturn\n"); } }
#line 1746 "y.tab.c"
    break;

  case 31:
#line 160 "compiler_hw2.y"
          { printf("return\n"); }
#line 1752 "y.tab.c"
    break;

  case 43:
#line 178 "compiler_hw2.y"
                                   { Symbol target = lookup_symbol((yyvsp[-3].s_val), 0); printf("call: %s%s\n", (yyvsp[-3].s_val), target.Fs); }
#line 1758 "y.tab.c"
    break;

  case 47:
#line 188 "compiler_hw2.y"
                { Symbol target = lookup_symbol((yyvsp[0].s_val)); printf("IDENT (name=%s, address=%d)\n", target.Name, target.Addr); }
#line 1764 "y.tab.c"
    break;

  case 48:
#line 189 "compiler_hw2.y"
                  { printf("INT_LIT %d\n", (yyvsp[0].i_val)); }
#line 1770 "y.tab.c"
    break;

  case 49:
#line 190 "compiler_hw2.y"
                    { printf("FLOAT_LIT %f\n", (yyvsp[0].f_val)); }
#line 1776 "y.tab.c"
    break;

  case 50:
#line 194 "compiler_hw2.y"
                                      { print_operator(7); Symbol target = lookup_symbol((yyvsp[-2].s_val), 1); if(strcmp(target.Name, (yyvsp[-2].s_val)) == 0){ printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", yylineno, (yyvsp[-2].s_val), target.Lineno); } insert_symbol((yyvsp[-2].s_val), type_stack[type_top--], address++, yylineno, "-", scope_level); }
#line 1782 "y.tab.c"
    break;

  case 53:
#line 203 "compiler_hw2.y"
                         {print_operator(7); type_top = -1; }
#line 1788 "y.tab.c"
    break;

  case 54:
#line 204 "compiler_hw2.y"
                         {print_operator(7); type_top = -1; }
#line 1794 "y.tab.c"
    break;

  case 57:
#line 213 "compiler_hw2.y"
                     { tmp_str = "ASSIGN"; op_stack[++top_op] = "ASSIGN"; precedence_stack[top_op] = 7; }
#line 1800 "y.tab.c"
    break;

  case 58:
#line 214 "compiler_hw2.y"
                     { tmp_str = "ADD"; op_stack[++top_op] = "ADD"; precedence_stack[top_op] = 7; }
#line 1806 "y.tab.c"
    break;

  case 59:
#line 215 "compiler_hw2.y"
                     { tmp_str = "SUB"; op_stack[++top_op] = "SUB"; precedence_stack[top_op] = 7; }
#line 1812 "y.tab.c"
    break;

  case 60:
#line 216 "compiler_hw2.y"
                     { tmp_str = "MUL"; op_stack[++top_op] = "MUL"; precedence_stack[top_op] = 7; }
#line 1818 "y.tab.c"
    break;

  case 61:
#line 217 "compiler_hw2.y"
                     { tmp_str = "QUO"; op_stack[++top_op] = "QUO"; precedence_stack[top_op] = 7; }
#line 1824 "y.tab.c"
    break;

  case 62:
#line 218 "compiler_hw2.y"
                     { tmp_str = "REM"; op_stack[++top_op] = "REM"; precedence_stack[top_op] = 7; }
#line 1830 "y.tab.c"
    break;

  case 65:
#line 230 "compiler_hw2.y"
              { printf("INC\n"); }
#line 1836 "y.tab.c"
    break;

  case 66:
#line 231 "compiler_hw2.y"
              { printf("DEC\n"); }
#line 1842 "y.tab.c"
    break;

  case 67:
#line 235 "compiler_hw2.y"
              { create_symbol(++scope_level); }
#line 1848 "y.tab.c"
    break;

  case 68:
#line 235 "compiler_hw2.y"
                                                                   { dump_symbol(scope_level--); }
#line 1854 "y.tab.c"
    break;

  case 71:
#line 244 "compiler_hw2.y"
                       { if(strcmp(type_stack[type_top], "bool") != 0){ printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, type_stack[type_top--]); } }
#line 1860 "y.tab.c"
    break;

  case 77:
#line 258 "compiler_hw2.y"
                     { print_operator(7); }
#line 1866 "y.tab.c"
    break;

  case 78:
#line 262 "compiler_hw2.y"
                         { if(strcmp(type_stack[type_top], "bool") != 0){ printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, type_stack[type_top--]); } }
#line 1872 "y.tab.c"
    break;

  case 85:
#line 283 "compiler_hw2.y"
                       { printf("case %d\n", (yyvsp[0].i_val)); }
#line 1878 "y.tab.c"
    break;

  case 88:
#line 288 "compiler_hw2.y"
                                     { print_operator(7); printf("PRINT %s\n", type_stack[type_top--]); }
#line 1884 "y.tab.c"
    break;

  case 89:
#line 289 "compiler_hw2.y"
                                     { print_operator(7); printf("PRINTLN %s\n", type_stack[type_top--]); }
#line 1890 "y.tab.c"
    break;

  case 90:
#line 293 "compiler_hw2.y"
                 { type_stack[++type_top] = "int32"; }
#line 1896 "y.tab.c"
    break;

  case 91:
#line 294 "compiler_hw2.y"
                 { type_stack[++type_top] = "float32"; }
#line 1902 "y.tab.c"
    break;

  case 92:
#line 295 "compiler_hw2.y"
                 { type_stack[++type_top] = "string"; }
#line 1908 "y.tab.c"
    break;

  case 93:
#line 296 "compiler_hw2.y"
                 { type_stack[++type_top] = "bool"; }
#line 1914 "y.tab.c"
    break;

  case 96:
#line 302 "compiler_hw2.y"
                              { printf("STRING_LIT %s\n", (yyvsp[-1].s_val)); type_stack[++type_top] = "string"; }
#line 1920 "y.tab.c"
    break;

  case 100:
#line 312 "compiler_hw2.y"
               { print_operator(6); op_stack[++top_op] = "LOR"; precedence_stack[top_op] = 6; }
#line 1926 "y.tab.c"
    break;

  case 101:
#line 313 "compiler_hw2.y"
               { print_operator(5); op_stack[++top_op] = "LAND"; precedence_stack[top_op] = 5; }
#line 1932 "y.tab.c"
    break;

  case 105:
#line 320 "compiler_hw2.y"
              {	print_operator(4); op_stack[++top_op] = "EQL"; precedence_stack[top_op] = 4; }
#line 1938 "y.tab.c"
    break;

  case 106:
#line 321 "compiler_hw2.y"
              { print_operator(4); op_stack[++top_op] = "NEQ"; precedence_stack[top_op] = 4; }
#line 1944 "y.tab.c"
    break;

  case 107:
#line 322 "compiler_hw2.y"
              { print_operator(4); op_stack[++top_op] = "SLR"; precedence_stack[top_op] = 4; }
#line 1950 "y.tab.c"
    break;

  case 108:
#line 323 "compiler_hw2.y"
              { print_operator(4); op_stack[++top_op] = "LEQ"; precedence_stack[top_op] = 4; }
#line 1956 "y.tab.c"
    break;

  case 109:
#line 324 "compiler_hw2.y"
              { print_operator(4); op_stack[++top_op] = "GTR"; precedence_stack[top_op] = 4; }
#line 1962 "y.tab.c"
    break;

  case 110:
#line 325 "compiler_hw2.y"
              { print_operator(4); op_stack[++top_op] = "GEQ"; precedence_stack[top_op] = 4; }
#line 1968 "y.tab.c"
    break;

  case 111:
#line 329 "compiler_hw2.y"
              { print_operator(3); op_stack[++top_op] = "ADD"; precedence_stack[top_op] = 3; }
#line 1974 "y.tab.c"
    break;

  case 112:
#line 330 "compiler_hw2.y"
              { print_operator(3); op_stack[++top_op] = "SUB"; precedence_stack[top_op] = 3; }
#line 1980 "y.tab.c"
    break;

  case 113:
#line 334 "compiler_hw2.y"
              { print_operator(2); op_stack[++top_op] = "MUL"; precedence_stack[top_op] = 2; }
#line 1986 "y.tab.c"
    break;

  case 114:
#line 335 "compiler_hw2.y"
              { print_operator(2); op_stack[++top_op] = "QUO"; precedence_stack[top_op] = 2; }
#line 1992 "y.tab.c"
    break;

  case 115:
#line 336 "compiler_hw2.y"
              { print_operator(2); op_stack[++top_op] = "REM"; precedence_stack[top_op] = 2; }
#line 1998 "y.tab.c"
    break;

  case 116:
#line 340 "compiler_hw2.y"
              { print_operator(1); op_stack[++top_op] = "POS"; precedence_stack[top_op] = 1; }
#line 2004 "y.tab.c"
    break;

  case 117:
#line 341 "compiler_hw2.y"
              { print_operator(1); op_stack[++top_op] = "NEG"; precedence_stack[top_op] = 1; }
#line 2010 "y.tab.c"
    break;

  case 118:
#line 342 "compiler_hw2.y"
          { print_operator(1); }
#line 2016 "y.tab.c"
    break;

  case 120:
#line 346 "compiler_hw2.y"
              { op_stack[++top_op] = "NOT"; precedence_stack[top_op] = 1; }
#line 2022 "y.tab.c"
    break;

  case 126:
#line 358 "compiler_hw2.y"
                { Symbol target = lookup_symbol((yyvsp[0].s_val), 0);if(strcmp(target.Name, "NOT_FOUND") != 0){ type_stack[++type_top] = target.Type; printf("IDENT (name=%s, address=%d)\n", target.Name, target.Addr);} else{ type_stack[++type_top] = "ERROR"; printf("error:%d: undefined: %s\n", yylineno+1, (yyvsp[0].s_val));} }
#line 2028 "y.tab.c"
    break;

  case 127:
#line 359 "compiler_hw2.y"
             { op_stack[++top_op] = "L_Bracket"; precedence_stack[top_op] = 7; }
#line 2034 "y.tab.c"
    break;

  case 128:
#line 360 "compiler_hw2.y"
                         { while(strcmp(op_stack[top_op], "L_Bracket") != 0){ printf("%s\n", top()); pop_op(); } pop_op(); }
#line 2040 "y.tab.c"
    break;

  case 129:
#line 364 "compiler_hw2.y"
                    { printf("INT_LIT %d\n", (yyvsp[0].i_val)); type_stack[++type_top] = "int32"; }
#line 2046 "y.tab.c"
    break;

  case 130:
#line 365 "compiler_hw2.y"
                    { printf("FLOAT_LIT %f\n", (yyvsp[0].f_val)); type_stack[++type_top] = "float32"; }
#line 2052 "y.tab.c"
    break;

  case 131:
#line 366 "compiler_hw2.y"
                    { printf("%s %d\n", yylval.b_val ? "TRUE":"FALSE", yylval.b_val); type_stack[++type_top] = "bool"; }
#line 2058 "y.tab.c"
    break;

  case 133:
#line 371 "compiler_hw2.y"
                                  { if(strcmp(type_stack[type_top--], "int32") == 0){ printf("i2f\n"); type_stack[++type_top] = "float32"; } else{ printf("f2i\n"); type_stack[++type_top] = "int32"; } }
#line 2064 "y.tab.c"
    break;


#line 2068 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 375 "compiler_hw2.y"


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yylineno = 0;
    yyparse();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void create_symbol(int level) {
    printf("> Create symbol table (scope level %d)\n", level);
}

static void insert_symbol(char *name, char*type, int addr, int line_num, char *fs, int level) {
	printf("> Insert `%s` (addr: %d) to scope level %d\n", name, addr, level);
	struct symbol newsymbol = { num_of_symbol[level], name, type, addr, line_num, fs};
	symbol_table[level][num_of_symbol[level]] = newsymbol;
	num_of_symbol[level]++;
}

static Symbol lookup_symbol(char *target_name, int only_this_scope) {
	struct symbol to_return = {-1, "NOT_FOUND", "NULL", -1, -1, "-"} ;
	bool isfound = false;
	int level = scope_level;
	for(;!isfound && level >= 0; level--){
		for(int i = 0; i < num_of_symbol[level]; ++i){
        	if(strcmp(target_name, symbol_table[level][i].Name) == 0){
            	to_return = symbol_table[level][i];
				isfound = true;	
			}
    	}
		if(only_this_scope)
			break;
	}
	return to_return;
}

static void dump_symbol(int level) {
    printf("\n> Dump symbol table (scope level: %d)\n", level);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s\n",
           "Index", "Name", "Type", "Addr", "Lineno", "Func_sig");
    for(int i = 0; i < num_of_symbol[level]; ++i){
		struct symbol st = symbol_table[level][i];
        printf("%-10d%-10s%-10s%-10d%-10d%-10s\n", st.Index, st.Name, st.Type, st.Addr, st.Lineno, st.Fs);
    }
	num_of_symbol[level] = 0;
	printf("\n");
}

static char *top(){
	if(top_op >= 0)
		return op_stack[top_op];
	else
		return "";
}

static void pop_op(){
	if(top_op >= 0)
		top_op--;
}

static void print_operator(int now_precedence){
	while(precedence_stack[top_op] <= now_precedence && top_op >= 0){
		if(type_top >= 1)
			error_check();
		printf("%s\n", top());
		pop_op();
	}
}
static void error_check(){
	char *operand2 = type_stack[type_top--], *operand1 = type_stack[type_top--], *op = top();
	char *result = operand1;
	//printf("%s %s %s\n", operand1, operand2, op);
	switch(precedence_stack[top_op]){
		case 1: type_stack[++type_top] = operand1;
				if(strcmp(op, "NOT") == 0){
					result = "bool";
				}
				else{
					if(strcmp(operand2, "int32") == 0)
						result = "int32";
					else
						result = "float32";
				}
				break;
		case 2: if(strcmp(op, "REM") == 0 && strcmp(operand2, "float32") == 0){
					printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno);
				}
				break;
		case 3: if(strcmp(operand1, operand2) != 0){
                    printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno, top(), operand1, operand2);
                }
				break;
		case 4: if(strcmp(operand1, "ERROR") == 0 || strcmp(operand2, "ERROR") == 0)
					printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno+1, top(), operand1, operand2);
				result = "bool"; 
				break;
		case 5: if(strcmp(operand1, "bool") != 0){
                	printf("error:%d: invalid operation: (operator LAND not defined on %s)\n", yylineno, operand1);
                }   
                else if(strcmp(operand2, "bool") != 0){
                	printf("error:%d: invalid operation: (operator LAND not defined on %s)\n", yylineno, operand2);
                }
				result = "bool";
                break;
		case 6: if(strcmp(operand1, "bool") != 0){
					printf("error:%d: invalid operation: (operator LOR not defined on %s)\n", yylineno, operand1);
				}
				else if(strcmp(operand2, "bool") != 0){
					printf("error:%d: invalid operation: (operator LOR not defined on %s)\n", yylineno, operand2);
				}
				result = "bool";
				break;
		case 7: if(strcmp(operand1, operand2) != 0){
                    printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno, top(), operand1, operand2);
                }
				break;
		default: break;
	}
	type_stack[++type_top] = result;
}



