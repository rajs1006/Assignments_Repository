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

#line 67 "parser.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 4 "parser.y" /* yacc.c:355  */

#include <stdbool.h>

#line 101 "parser.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BOOL = 258,
    INT = 259,
    FLOAT = 260,
    TYPE = 261,
    STATE = 262,
    IDENTIFIER = 263,
    ERROR = 264,
    BREAK = 265,
    CONTINUE = 266,
    DO = 267,
    FOR = 268,
    WHILE = 269,
    SWITCH = 270,
    CASE = 271,
    DEFAULT = 272,
    IF = 273,
    ELSE = 274,
    RETURN = 275,
    STRUCT = 276,
    ATTRIBUTE = 277,
    CONST = 278,
    UNIFORM = 279,
    VARYING = 280,
    BUFFER = 281,
    SHARED = 282,
    COHERENT = 283,
    VOLATILE = 284,
    RESTRICT = 285,
    READONLY = 286,
    WRITEONLY = 287,
    LAYOUT = 288,
    CENTROID = 289,
    FLAT = 290,
    SMOOTH = 291,
    NOPERSPECTIVE = 292,
    PATCH = 293,
    SAMPLE = 294,
    SUBROUTINE = 295,
    IN = 296,
    OUT = 297,
    INOUT = 298,
    INVARIANT = 299,
    PRECISE = 300,
    DISCARD = 301,
    LOWP = 302,
    MEDIUMP = 303,
    HIGHP = 304,
    PRECISION = 305,
    CLASS = 306,
    ILLUMINANCE = 307,
    AMBIENT = 308,
    PUBLIC = 309,
    PRIVATE = 310,
    SCRATCH = 311,
    RT_PRIMITIVE = 312,
    RT_CAMERA = 313,
    RT_MATERIAL = 314,
    RT_TEXTURE = 315,
    RT_LIGHT = 316,
    LEFT_OP = 317,
    RIGHT_OP = 318,
    INC_OP = 319,
    DEC_OP = 320,
    LE_OP = 321,
    GE_OP = 322,
    EQ_OP = 323,
    NE_OP = 324,
    AND_OP = 325,
    OR_OP = 326,
    XOR_OP = 327,
    MUL_ASSIGN = 328,
    DIV_ASSIGN = 329,
    ADD_ASSIGN = 330,
    MOD_ASSIGN = 331,
    LEFT_ASSIGN = 332,
    RIGHT_ASSIGN = 333,
    AND_ASSIGN = 334,
    XOR_ASSIGN = 335,
    OR_ASSIGN = 336,
    SUB_ASSIGN = 337
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "parser.y" /* yacc.c:355  */

    bool bval;
    int ival;
    double fval;
    char *str;

#line 203 "parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 220 "parser.c" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 9 "parser.y" /* yacc.c:359  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int line_number;
extern FILE *yyin;
extern int yylex();
static void checkStateMethod(char *methodName, char *stateName, int stateOrder);
static void checkStateVariable(char *stateVarName, char *stateName, int stateOrder);
static void yyerror(const char *s);

char *identName;
char *funcName;
char *typeName;
char *stateVarName;
char *stateName;
int stateOrder;

#line 242 "parser.c" /* yacc.c:359  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1467

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  244
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  387

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   337

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    91,     2,     2,     2,    95,    98,     2,
      85,    86,    93,    89,    88,    90,    87,    94,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    83,    84,
      96,   102,    97,   101,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   105,     2,   106,    99,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   103,   100,   104,    92,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    73,    77,    78,    79,    80,    81,    85,
      85,    85,    89,    93,   100,   101,   102,   103,   104,   105,
     109,   110,   111,   112,   113,   114,   118,   122,   126,   127,
     131,   135,   136,   140,   144,   149,   150,   151,   152,   156,
     157,   158,   159,   163,   164,   165,   166,   171,   172,   173,
     177,   178,   179,   183,   184,   185,   186,   187,   191,   192,
     193,   197,   198,   202,   203,   207,   208,   212,   213,   217,
     218,   222,   223,   227,   228,   232,   233,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   252,   253,
     257,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     274,   275,   279,   283,   284,   285,   289,   290,   294,   298,
     298,   302,   303,   304,   305,   309,   310,   311,   312,   316,
     320,   321,   322,   323,   324,   328,   329,   330,   331,   332,
     332,   336,   337,   341,   345,   346,   350,   354,   355,   359,
     361,   365,   369,   370,   374,   375,   377,   378,   379,   380,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   404,   405,   409,
     410,   414,   415,   416,   417,   421,   424,   425,   429,   430,
     435,   436,   440,   441,   445,   446,   450,   451,   455,   456,
     460,   461,   462,   466,   467,   471,   475,   476,   480,   481,
     482,   483,   484,   485,   486,   490,   491,   495,   496,   500,
     501,   505,   506,   510,   511,   515,   519,   520,   524,   525,
     529,   532,   534,   538,   539,   543,   544,   545,   549,   550,
     554,   555,   559,   560,   564,   565,   566,   567,   567,   568,
     572,   573,   577,   578,   582
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL", "INT", "FLOAT", "TYPE", "STATE",
  "IDENTIFIER", "ERROR", "BREAK", "CONTINUE", "DO", "FOR", "WHILE",
  "SWITCH", "CASE", "DEFAULT", "IF", "ELSE", "RETURN", "STRUCT",
  "ATTRIBUTE", "CONST", "UNIFORM", "VARYING", "BUFFER", "SHARED",
  "COHERENT", "VOLATILE", "RESTRICT", "READONLY", "WRITEONLY", "LAYOUT",
  "CENTROID", "FLAT", "SMOOTH", "NOPERSPECTIVE", "PATCH", "SAMPLE",
  "SUBROUTINE", "IN", "OUT", "INOUT", "INVARIANT", "PRECISE", "DISCARD",
  "LOWP", "MEDIUMP", "HIGHP", "PRECISION", "CLASS", "ILLUMINANCE",
  "AMBIENT", "PUBLIC", "PRIVATE", "SCRATCH", "RT_PRIMITIVE", "RT_CAMERA",
  "RT_MATERIAL", "RT_TEXTURE", "RT_LIGHT", "LEFT_OP", "RIGHT_OP", "INC_OP",
  "DEC_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "XOR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "ADD_ASSIGN", "MOD_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "SUB_ASSIGN", "':'", "';'", "'('", "')'", "'.'", "','", "'+'", "'-'",
  "'!'", "'~'", "'*'", "'/'", "'%'", "'<'", "'>'", "'&'", "'^'", "'|'",
  "'?'", "'='", "'{'", "'}'", "'['", "']'", "$accept", "class_identifier",
  "state_variable", "state_definition", "$@1", "$@2",
  "variable_identifier", "state_var_identifier", "primary_expression",
  "postfix_expression", "function_call", "function_call_or_method",
  "function_call_generic", "function_call_header_no_parameters",
  "function_call_header_with_parameters", "function_call_header",
  "function_identifier", "unary_expression", "unary_operator",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_xor_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "identifier_list",
  "function_prototype", "function_declarator",
  "function_header_with_parameters", "function_header_with_no_parameters",
  "function_header", "$@3", "parameter_declarator",
  "parameter_declaration", "parameter_type_specifier",
  "init_declarator_list", "single_declaration", "$@4",
  "fully_specified_type", "invariant_qualifier", "interpolation_qualifier",
  "layout_qualifier", "layout_qualifier_id_list", "layout_qualifier_id",
  "precise_qualifier", "type_qualifier", "single_type_qualifier",
  "storage_qualifier", "type_name_list", "type_specifier",
  "array_specifier", "type_identifier", "type_specifier_nonarray",
  "access_modifiers", "struct_specifier", "struct_declaration_list",
  "struct_declaration", "struct_declarator_list", "struct_declarator",
  "initializer", "initializer_list", "declaration_statement", "statement",
  "simple_statement", "compound_statement", "statement_no_new_scope",
  "compound_statement_no_new_scope", "statement_list",
  "expression_statement", "selection_statement",
  "selection_rest_statement", "condition", "switch_statement",
  "switch_statement_list", "case_label", "iteration_statement",
  "for_init_statement", "conditionopt", "for_rest_statement",
  "jump_statement", "$@5", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,    58,    59,    40,    41,    46,    44,    43,
      45,    33,   126,    42,    47,    37,    60,    62,    38,    94,
     124,    63,    61,   123,   125,    91,    93
};
# endif

#define YYPACT_NINF -255

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-255)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,  -255,    31,  1372,    61,  -255,  -255,     1,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,   -11,  -255,  -255,
    -255,  -255,  -255,    29,  -255,  -255,  -255,  -255,  -255,    40,
    -255,  -255,  -255,    -1,  -255,  1412,  -255,  1285,   -51,  -255,
     114,  -255,  -255,  -255,  -255,  1325,  -255,  -255,  -255,  -255,
      35,  -255,  -255,  1372,  -255,  -255,  -255,  -255,    75,  1412,
      58,   150,    66,   424,  -255,  -255,  -255,  -255,  1412,   182,
    -255,  -255,  -255,   185,    35,   -14,    -8,  -255,  -255,  -255,
     318,   105,  -255,   123,  1412,  1412,   204,  1016,  -255,   209,
    -255,    25,  -255,    33,  -255,   138,  -255,  -255,  -255,  -255,
     139,   141,   885,   143,   144,   145,   514,   149,   148,   151,
     152,   514,   514,  -255,   514,  -255,  -255,  -255,  -255,   526,
    -255,  -255,  -255,  -255,   -12,  -255,  -255,  -255,   153,    83,
     514,   155,    52,   514,    90,    97,   142,   -19,   140,   126,
     127,   137,   157,   166,   -50,  -255,  -255,   -59,  -255,   146,
     156,  -255,  -255,  -255,  -255,   628,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,   -62,    65,    71,   159,   154,  -255,
     234,  1412,     9,  -255,  -255,  -255,   158,  -255,   327,   101,
    1056,   204,    35,    36,  -255,  -255,  -255,   160,  -255,    58,
    -255,   150,  -255,  -255,  -255,    53,   232,  1141,  1213,   514,
     -53,  -255,   514,  -255,   514,  -255,  -255,  -255,    86,  -255,
     730,  -255,  -255,   514,   240,  -255,  -255,   514,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,   514,  -255,   514,   514,   514,   514,   514,   514,   514,
     514,   514,   514,   514,   514,   514,   514,   514,   514,   514,
     514,   514,   514,  -255,   514,  -255,   514,  -255,  -255,  -255,
    -255,   -48,   938,    77,   938,  -255,   938,  -255,  1098,  -255,
     246,  -255,  -255,   161,  -255,  -255,  -255,  -255,  -255,   171,
    -255,    62,   105,  -255,   204,   514,  -255,  -255,   172,  -255,
    -255,  1213,   170,   251,  1412,   174,   103,  -255,   111,    67,
    -255,  -255,   112,  -255,  -255,  -255,  -255,  -255,  -255,    90,
      90,    97,    97,   142,   142,   142,   142,   -19,   -19,   140,
     126,   127,   137,   157,   166,    13,  -255,   -65,  -255,  -255,
     938,  -255,  -255,   938,  -255,  -255,     5,  -255,  -255,  -255,
    -255,  -255,  -255,   514,  -255,   177,   180,   167,   885,   168,
     885,  -255,  -255,   514,  -255,   -25,  -255,   -56,  -255,   115,
     514,   885,   938,  -255,  -255,  -255,   885,   244,  -255,  -255,
     783,  -255,  -255,   -43,   186,   170,  -255,  -255,   885,   169,
     885,  -255,  -255,  -255,  -255,  -255,  -255
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,     0,     3,     0,     1,   175,     0,   150,   157,
     158,   159,   160,   161,   162,   163,   164,     0,   154,   135,
     134,   155,   156,   165,   152,   153,   151,   133,   141,     0,
     178,   179,   243,     0,   102,   104,   105,   103,     0,   120,
     125,   147,   146,   145,   148,     0,   142,   144,   131,   177,
     169,   149,   176,     2,   240,   242,    12,    10,     0,     0,
       0,     0,     0,     0,   244,   116,   107,   118,     0,   119,
     108,   106,    92,     0,    12,   126,     0,    97,   143,   132,
       0,   170,   241,     0,     0,     0,     0,     0,   182,     0,
     140,     0,   137,     0,   167,     0,    18,    16,    17,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
       0,     0,     0,   213,     0,    39,    40,    41,    42,     0,
     209,    14,    15,    20,    35,    22,    26,    27,     0,     0,
      30,     0,    43,     0,    47,    50,    53,    58,    61,    63,
      65,    67,    69,    71,    73,    75,    88,     0,   195,     0,
     131,   198,   211,   197,   196,     0,   199,   200,   201,   202,
     203,   204,   115,   117,     0,   121,   127,     0,     0,    98,
       0,     0,     0,   171,    43,    90,     0,    34,     0,     0,
       0,     0,   188,     0,   186,   181,   183,     0,   136,     0,
     166,     0,    93,   235,   234,     0,     0,     0,     0,     0,
       0,   224,     0,   236,     0,   239,    36,    37,     0,   205,
       0,    24,    25,     0,     0,    29,    28,     0,    31,    33,
      78,    79,    81,    80,    83,    84,    85,    86,    87,    82,
      77,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   214,     0,    91,     0,   210,   212,   111,
     112,     0,     0,   122,     0,   110,     0,   100,     0,    99,
       0,   172,   173,     0,     4,     5,     6,     7,     8,     0,
     180,     0,   189,   184,     0,     0,   138,   168,     0,   229,
     228,   231,   218,     0,     0,     0,     0,   223,     0,     0,
      19,   206,     0,    23,    32,    76,    44,    45,    46,    48,
      49,    51,    52,    56,    57,    54,    55,    59,    60,    62,
      64,    66,    68,    70,    72,     0,    89,     0,   113,   114,
       0,   190,   124,     0,   128,   130,     0,   101,   174,    11,
     185,   187,   139,     0,   230,     0,     0,     0,     0,     0,
       0,   238,    21,     0,   193,     0,   123,     0,    94,     0,
     232,     0,     0,   208,   207,   225,   221,   216,   215,    74,
       0,   191,    95,     0,     0,   233,   227,   219,   222,     0,
       0,   192,   194,    96,   226,   220,   217
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -255,  -255,  -255,  -255,  -255,  -255,    18,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,    69,  -255,   -21,
     -20,   -77,   -24,    26,    27,    28,    30,    32,    24,  -255,
     -72,  -119,  -255,   -60,  -168,    15,  -255,    17,  -255,  -255,
    -255,  -255,  -255,   213,   248,   218,  -255,  -255,  -255,  -183,
    -255,  -255,  -255,  -255,    88,  -255,   -23,   -41,  -255,  -255,
      -3,   -73,   -55,  -255,  -255,  -255,   -68,   -80,   106,     6,
    -247,  -255,    92,  -100,  -254,  -243,   -69,  -255,  -114,    96,
    -255,  -255,     3,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,   242,  -255
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   279,     3,     4,    83,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   231,   195,   176,   148,   172,   149,    34,    35,
      36,    37,   167,    65,    66,    67,    38,    39,   168,    40,
      41,    42,    43,    91,    92,    44,    45,    46,    47,    93,
     177,    81,    49,    50,    51,    52,    87,    88,   183,   184,
     332,   355,   151,   152,   153,   154,   365,    64,   155,   156,
     157,   368,   295,   158,   379,   159,   160,   291,   345,   346,
     161,   204,    53,    54,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,   166,   196,   147,    78,   210,    94,   186,   175,    58,
     273,   218,    68,   357,    68,   293,   180,   334,    32,   335,
      33,   251,    57,   254,   259,   253,   260,    78,   372,   254,
     297,     5,    69,    72,    69,   254,    85,    73,   328,   255,
     329,   383,    79,    80,    78,   255,   200,   240,   241,    80,
      48,   252,   211,   212,   208,   258,    86,   178,    75,    95,
     150,    85,   178,   370,    85,    69,    89,     1,    32,    56,
      33,  -109,     6,   213,    60,   214,   169,   242,   243,   371,
     170,    86,   181,   354,    86,    90,   356,     7,  -129,   358,
      62,   261,   263,   269,   363,   171,   353,   270,   304,   150,
     186,   254,    63,   268,    59,   364,   175,   363,   293,   282,
     258,   188,   305,   189,    61,   377,   150,   342,   364,   190,
     283,   191,    74,   382,   284,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   326,   287,   253,   292,   296,
      80,   254,   298,   331,   299,   331,   340,   331,    85,   174,
     284,   351,   150,   302,   230,   254,     6,    85,   274,   275,
     276,   277,   278,   313,   314,   315,   316,   262,    86,   216,
      80,   217,   300,   264,   254,   294,   178,    86,    84,   333,
     206,   207,   178,   233,   234,   235,   236,   237,   186,   349,
     164,   254,   325,   165,   150,   150,   327,   350,   352,   254,
     254,   374,   232,   254,   238,   239,   179,   150,   244,   245,
     178,   331,   182,   175,   331,   309,   310,   187,   311,   312,
     317,   318,   192,   193,   246,   194,   247,   249,   197,   198,
     199,   292,   201,   202,   369,   203,   205,   248,   250,   215,
     219,   -34,   267,   331,   265,    85,   288,   174,   303,   256,
     367,   331,   378,    78,   337,   339,   266,   343,   254,   347,
     348,   360,   285,   380,   271,    86,   361,   338,   294,   362,
     384,   366,   319,   385,   320,   324,   321,   286,   258,   322,
     386,   162,   323,   359,   373,    71,   163,   281,   150,   289,
     341,    79,   376,   290,   344,    82,     0,     0,     0,     0,
     375,     0,   306,   307,   308,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,    96,    97,    98,     6,    99,    56,     0,     0,     0,
      96,    97,    98,     6,    99,    56,     0,     0,     0,     7,
       0,     0,     0,     0,     0,   150,     0,   150,     7,     0,
       0,     0,     0,     0,   174,     0,     0,     0,   150,     0,
       0,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,     0,   150,     0,     0,
       0,     0,   111,   112,     0,     0,     0,     0,     0,     0,
       0,   111,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,     0,     0,     0,   115,   116,   117,
     118,     0,   114,     0,     0,     0,   115,   116,   117,   118,
       0,     0,     0,     0,   173,     0,     0,    96,    97,    98,
       6,    99,    56,   272,   100,   101,   102,   103,   104,   105,
     106,   107,   108,     0,   109,     7,     0,     8,     9,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,    21,    22,    23,    24,    25,    26,    27,    28,
     110,     0,     0,     0,    29,     0,     0,     0,    30,    31,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,   115,   116,   117,   118,    96,    97,    98,
       6,    99,    56,     0,     0,     0,     0,   119,   120,    96,
      97,    98,     6,    99,    56,     7,   100,   101,   102,   103,
     104,   105,   106,   107,   108,     0,   109,     7,     0,     8,
       9,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,    21,    22,    23,    24,    25,    26,
      27,    28,   110,     0,     0,     0,    29,     0,   111,   112,
      30,    31,     0,     0,     0,     0,     0,     0,     0,     0,
     111,   112,     0,     0,     0,     0,     0,     0,     0,   114,
       0,     0,     0,   115,   116,   117,   118,     0,     0,     0,
     113,   114,     0,     0,     0,   115,   116,   117,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
     209,    96,    97,    98,     6,    99,    56,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,     0,   109,     7,
       0,     8,     9,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,    21,    22,    23,    24,
      25,    26,    27,    28,   110,     0,     0,     0,    29,     0,
       0,     0,    30,    31,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,   115,   116,   117,
     118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,   257,    96,    97,    98,     6,    99,    56,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,     0,
     109,     7,     0,     8,     9,     0,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,    21,    22,
      23,    24,    25,    26,    27,    28,   110,     0,     0,     0,
      29,     0,     0,     0,    30,    31,    96,    97,    98,     6,
      99,    56,     0,     0,   111,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,   115,
     116,   117,   118,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,   301,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   111,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,     0,
       0,     0,   115,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   330,   381,    96,    97,
      98,     6,    99,    56,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,     0,   109,     7,     0,     8,     9,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,    21,    22,    23,    24,    25,    26,    27,
      28,   110,     0,     0,     0,    29,     0,     0,     0,    30,
      31,    96,    97,    98,     6,    99,    56,     0,     0,   111,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,     0,   115,   116,   117,   118,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,   114,     0,     0,     0,   115,   116,   117,
     118,     0,     0,     0,     0,     0,     0,     7,     0,     8,
       9,   330,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,    21,    22,    23,    24,    25,    26,
      27,    28,     6,     0,     0,     0,     0,     0,     0,     0,
      30,    31,     0,     0,     0,     0,     0,     7,     0,     8,
       9,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     6,     0,     0,     0,     0,     0,
      30,    31,     0,     0,     0,     0,     0,     0,     0,     7,
     185,     8,     9,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,    21,    22,    23,    24,
      25,    26,    27,    28,    96,    97,    98,     6,    99,    56,
       0,     0,    30,    31,     0,     0,     0,     0,     0,     0,
     280,     0,     7,     0,     8,     9,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
       0,    29,     0,     0,     0,    30,    31,     0,     0,     0,
       0,     0,   336,     0,     0,   111,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     6,
      99,    56,     0,     0,     0,   113,   114,     0,     0,     0,
     115,   116,   117,   118,     7,     0,     8,     9,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    31,     0,
       0,     0,     0,     0,     0,     0,     0,   111,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     0,     0,     0,     0,     0,     0,   114,     0,
       0,     0,   115,   116,   117,   118,     7,     0,     8,     9,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,    21,    22,    23,    24,    25,    26,    27,
      28,     6,     0,    76,     0,     0,     0,     0,     0,    30,
      31,     0,     0,     0,     0,     0,     7,     0,     8,     9,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    70,     0,     0,     0,     0,     0,     0,     6,    30,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     0,     8,     9,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    77,
      21,    22,    23,    24,    25,    26,    27,    28,     6,     0,
       0,     0,    29,     0,     0,     0,    30,    31,     0,     0,
       0,     0,     0,     7,     0,     8,     9,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
      21,    22,    23,    24,    25,    26,    27,    28,     0,     0,
       0,     0,     0,     0,     0,     0,    30,    31
};

static const yytype_int16 yycheck[] =
{
       3,    74,   102,    63,    45,   119,    61,    87,    80,     8,
     178,   130,    35,     8,    37,   198,    84,   264,     3,   266,
       3,    71,     4,    88,    86,    84,    88,    68,    84,    88,
      83,     0,    35,    84,    37,    88,    59,    88,    86,   104,
      88,    84,    45,   105,    85,   104,   106,    66,    67,   105,
      53,   101,    64,    65,   114,   155,    59,   105,    40,    62,
      63,    84,   105,    88,    87,    68,     8,    51,    53,     8,
      53,    85,     6,    85,    85,    87,    84,    96,    97,   104,
      88,    84,    85,   330,    87,    27,   333,    21,   102,    84,
      50,   164,   165,    84,   348,   103,    83,    88,   217,   102,
     180,    88,   103,   171,   103,   348,   178,   361,   291,   182,
     210,    86,   231,    88,    85,   362,   119,   285,   361,    86,
      84,    88,     8,   370,    88,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,   254,   191,    84,   198,   199,
     105,    88,   202,   262,   204,   264,    84,   266,   171,    80,
      88,    84,   155,   213,   102,    88,     6,   180,    57,    58,
      59,    60,    61,   240,   241,   242,   243,   102,   171,    86,
     105,    88,    86,   102,    88,   198,   105,   180,   103,   102,
     111,   112,   105,    93,    94,    95,    89,    90,   268,    86,
       8,    88,   252,     8,   197,   198,   256,    86,    86,    88,
      88,    86,   133,    88,    62,    63,    83,   210,    68,    69,
     105,   330,     8,   285,   333,   236,   237,     8,   238,   239,
     244,   245,    84,    84,    98,    84,    99,    70,    85,    85,
      85,   291,    83,    85,   353,    84,    84,   100,    72,    86,
      85,    85,     8,   362,    85,   268,    14,   178,     8,   103,
     350,   370,   366,   294,     8,    84,   102,    85,    88,     8,
      86,    84,   102,    19,   106,   268,    86,   106,   291,   102,
      84,   103,   246,   104,   247,   251,   248,   189,   378,   249,
     380,    68,   250,   343,   357,    37,    68,   181,   291,   197,
     284,   294,   361,   197,   291,    53,    -1,    -1,    -1,    -1,
     360,    -1,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    -1,   348,    -1,   350,    21,    -1,
      -1,    -1,    -1,    -1,   285,    -1,    -1,    -1,   361,    -1,
      -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   378,    -1,   380,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    89,    90,    91,
      92,    -1,    85,    -1,    -1,    -1,    89,    90,    91,    92,
      -1,    -1,    -1,    -1,   106,    -1,    -1,     3,     4,     5,
       6,     7,     8,   106,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    20,    21,    -1,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      -1,    -1,    -1,    89,    90,    91,    92,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,   103,   104,     3,
       4,     5,     6,     7,     8,    21,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    20,    21,    -1,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    50,    -1,    64,    65,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    89,    90,    91,    92,    -1,    -1,    -1,
      84,    85,    -1,    -1,    -1,    89,    90,    91,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,
     104,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    20,    21,
      -1,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    -1,    -1,    89,    90,    91,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      20,    21,    -1,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    54,    55,     3,     4,     5,     6,
       7,     8,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    -1,    -1,    -1,    89,
      90,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    89,    90,    91,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   104,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    20,    21,    -1,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,
      55,     3,     4,     5,     6,     7,     8,    -1,    -1,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    -1,    -1,    -1,    89,    90,    91,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    85,    -1,    -1,    -1,    89,    90,    91,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    23,
      24,   103,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    21,    -1,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
     104,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,     3,     4,     5,     6,     7,     8,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    21,    -1,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    64,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    84,    85,    -1,    -1,    -1,
      89,    90,    91,    92,    21,    -1,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    89,    90,    91,    92,    21,    -1,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    21,    -1,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    86,    -1,    -1,    -1,    -1,    -1,    -1,     6,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    84,
      38,    39,    40,    41,    42,    43,    44,    45,     6,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,   108,   110,   111,     0,     6,    21,    23,    24,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    38,    39,    40,    41,    42,    43,    44,    45,    50,
      54,    55,   142,   144,   145,   146,   147,   148,   153,   154,
     156,   157,   158,   159,   162,   163,   164,   165,   167,   169,
     170,   171,   172,   199,   200,   201,     8,   113,     8,   103,
      85,    85,    50,   103,   184,   150,   151,   152,   163,   167,
      86,   151,    84,    88,     8,   113,     8,    84,   164,   167,
     105,   168,   200,   112,   103,   163,   167,   173,   174,     8,
      27,   160,   161,   166,   169,   167,     3,     4,     5,     7,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    20,
      46,    64,    65,    84,    85,    89,    90,    91,    92,   103,
     104,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   140,   142,   144,
     167,   179,   180,   181,   182,   185,   186,   187,   190,   192,
     193,   197,   150,   152,     8,     8,   168,   149,   155,    84,
      88,   103,   143,   106,   124,   137,   141,   167,   105,    83,
     173,   167,     8,   175,   176,   104,   174,     8,    86,    88,
      86,    88,    84,    84,    84,   140,   180,    85,    85,    85,
     140,    83,    85,    84,   198,    84,   124,   124,   140,   104,
     185,    64,    65,    85,    87,    86,    86,    88,   138,    85,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
     102,   139,   124,    93,    94,    95,    89,    90,    62,    63,
      66,    67,    96,    97,    68,    69,    98,    99,   100,    70,
      72,    71,   101,    84,    88,   104,   103,   104,   180,    86,
      88,   168,   102,   168,   102,    85,   102,     8,   173,    84,
      88,   106,   106,   141,    57,    58,    59,    60,    61,   109,
     104,   175,   168,    84,    88,   102,   161,   169,    14,   179,
     186,   194,   140,   156,   163,   189,   140,    83,   140,   140,
      86,   104,   140,     8,   138,   138,   124,   124,   124,   126,
     126,   127,   127,   128,   128,   128,   128,   129,   129,   130,
     131,   132,   133,   134,   135,   140,   138,   140,    86,    88,
     103,   138,   177,   102,   177,   177,   104,     8,   106,    84,
      84,   176,   141,    85,   189,   195,   196,     8,    86,    86,
      86,    84,    86,    83,   177,   178,   177,     8,    84,   140,
      84,    86,   102,   181,   182,   183,   103,   180,   188,   138,
      88,   104,    84,   168,    86,   140,   183,   177,   185,   191,
      19,   104,   177,    84,    84,   104,   180
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   107,   108,   108,   109,   109,   109,   109,   109,   111,
     112,   110,   113,   114,   115,   115,   115,   115,   115,   115,
     116,   116,   116,   116,   116,   116,   117,   118,   119,   119,
     120,   121,   121,   122,   123,   124,   124,   124,   124,   125,
     125,   125,   125,   126,   126,   126,   126,   127,   127,   127,
     128,   128,   128,   129,   129,   129,   129,   129,   130,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   136,   136,   137,   137,   138,   138,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   140,   140,
     141,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     143,   143,   144,   145,   145,   145,   146,   146,   147,   149,
     148,   150,   150,   150,   150,   151,   151,   151,   151,   152,
     153,   153,   153,   153,   153,   154,   154,   154,   154,   155,
     154,   156,   156,   157,   158,   158,   159,   160,   160,   161,
     161,   162,   163,   163,   164,   164,   164,   164,   164,   164,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   166,   166,   167,
     167,   168,   168,   168,   168,   169,   170,   170,   171,   171,
     172,   172,   173,   173,   174,   174,   175,   175,   176,   176,
     177,   177,   177,   178,   178,   179,   180,   180,   181,   181,
     181,   181,   181,   181,   181,   182,   182,   183,   183,   184,
     184,   185,   185,   186,   186,   187,   188,   188,   189,   189,
     190,   191,   191,   192,   192,   193,   193,   193,   194,   194,
     195,   195,   196,   196,   197,   197,   197,   198,   197,   197,
     199,   199,   200,   200,   201
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     0,
       0,     7,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     1,     3,     2,     2,     1,     1,     2,     2,
       1,     2,     3,     2,     1,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     2,     4,     6,     7,     8,     2,     3,     4,
       2,     3,     1,     1,     1,     1,     2,     2,     2,     0,
       4,     3,     3,     4,     4,     2,     1,     2,     1,     1,
       1,     3,     4,     6,     5,     1,     2,     3,     5,     0,
       5,     1,     2,     1,     1,     1,     4,     1,     3,     4,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     3,     1,
       2,     2,     3,     3,     4,     1,     1,     1,     1,     1,
       5,     4,     1,     2,     3,     4,     1,     3,     1,     2,
       1,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     1,     2,
       3,     1,     2,     1,     2,     5,     1,     3,     1,     4,
       7,     0,     1,     3,     2,     5,     7,     6,     1,     1,
       1,     0,     2,     3,     2,     2,     2,     0,     4,     2,
       1,     2,     1,     1,     2
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
        case 4:
#line 77 "parser.y" /* yacc.c:1646  */
    { stateName = "primitive";stateOrder=0; printf ( "of type RT_PRIMITIVE \n ");}
#line 1869 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 78 "parser.y" /* yacc.c:1646  */
    { stateName = "camera";stateOrder=1; printf ( "of type RT_CAMERA \n ");}
#line 1875 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 79 "parser.y" /* yacc.c:1646  */
    { stateName = "material"; stateOrder=2; printf ( "of type RT_MATERIAL \n ");}
#line 1881 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 80 "parser.y" /* yacc.c:1646  */
    { stateName = "texture";stateOrder=3; printf ( "of type RT_TEXTURE \n ");}
#line 1887 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 81 "parser.y" /* yacc.c:1646  */
    { stateName = "light"; stateOrder=4; printf ( "of type RT_LIGHT \n ");}
#line 1893 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 85 "parser.y" /* yacc.c:1646  */
    { printf ( " CLASS ");}
#line 1899 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 85 "parser.y" /* yacc.c:1646  */
    {printf ( "%s ", identName);}
#line 1905 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 89 "parser.y" /* yacc.c:1646  */
    {identName = (yyvsp[0].str); }
#line 1911 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 93 "parser.y" /* yacc.c:1646  */
    {
				stateVarName = (yyvsp[0].str); 
				checkStateVariable(stateVarName, stateName, stateOrder);
			}
#line 1920 "parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 298 "parser.y" /* yacc.c:1646  */
    {funcName = identName; }
#line 1926 "parser.c" /* yacc.c:1646  */
    break;

  case 126:
#line 329 "parser.y" /* yacc.c:1646  */
    {printf ("DECLARATION %s of type %s \n ", identName, typeName);}
#line 1932 "parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 332 "parser.y" /* yacc.c:1646  */
    {printf ("DECLARATION %s of type %s with initializer \n ", identName, typeName);}
#line 1938 "parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 421 "parser.y" /* yacc.c:1646  */
    {typeName = (yyvsp[0].str); }
#line 1944 "parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 491 "parser.y" /* yacc.c:1646  */
    { printf ( "COMPOUND_STATEMENT \n ");}
#line 1950 "parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 511 "parser.y" /* yacc.c:1646  */
    { printf ( "EXPRESSION_STATEMENT \n ");}
#line 1956 "parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 519 "parser.y" /* yacc.c:1646  */
    { printf ( "IF_STATEMENT \n ");}
#line 1962 "parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 520 "parser.y" /* yacc.c:1646  */
    { printf ( "IF_ELSE_STATEMENT \n ");}
#line 1968 "parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 543 "parser.y" /* yacc.c:1646  */
    { printf ( "WHILE_STATEMENT \n ");}
#line 1974 "parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 544 "parser.y" /* yacc.c:1646  */
    { printf ( "DO_WHILE_STATEMENT \n ");}
#line 1980 "parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 545 "parser.y" /* yacc.c:1646  */
    { printf ( "FOR_STATEMENT \n ");}
#line 1986 "parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 564 "parser.y" /* yacc.c:1646  */
    { printf ( "CONTINUE \n ");}
#line 1992 "parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 565 "parser.y" /* yacc.c:1646  */
    { printf ( "BREAK \n ");}
#line 1998 "parser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 566 "parser.y" /* yacc.c:1646  */
    { printf ( "RETURN_STATEMENT \n ");}
#line 2004 "parser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 567 "parser.y" /* yacc.c:1646  */
    { printf ( "RETURN_STATEMENT \n ");}
#line 2010 "parser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 568 "parser.y" /* yacc.c:1646  */
    { printf ( "DISCARD \n ");}
#line 2016 "parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 583 "parser.y" /* yacc.c:1646  */
    { 
			printf ( "FUNCTION_DEF %s \n ", funcName); 
			checkStateMethod(funcName, stateName, stateOrder);
		}
#line 2025 "parser.c" /* yacc.c:1646  */
    break;


#line 2029 "parser.c" /* yacc.c:1646  */
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
#line 589 "parser.y" /* yacc.c:1906  */

/* DaRT_LIGHT;ta tables for interface methods and states, so you don't have to extract them yourself.
 * Note: The paper contains a number of errors regarding the allowed state variables. These
 * errors are already corrected here and marked with a comment. */

static const char *camera_methods[] = {
    "constructor",
    "generateRay",
    NULL
};

static const char *primitive_methods[] = {
    "constructor",
    "intersect",
    "computeBounds",
    "computeNormal",
    "computeTextureCoordinates",
    "computeDerivatives",
    "generateSample",
    "samplePDF",
    NULL
};

static const char *texture_methods[] = {
    "constructor",
    "lookup",
    NULL
};

static const char *material_methods[] = {
    "constructor",
    "shade",
    "BSDF",
    "sampleBSDF",
    "evaluatePDF",
    "emission",
    NULL
};

static const char *light_methods[] = {
    "constructor",
    "illumination",
    NULL
};

static const char **interface_methods[] = {
    primitive_methods, camera_methods, material_methods, texture_methods, light_methods, NULL
};

static const char *camera_states[] = {
    "RayOrigin",
    "RayDirection",
    "InverseRayDirection",
    "Epsilon",
    "HitDistance",
    "ScreenCoord",
    "LensCoord",
    "du",
    "dv",
    "TimeSeed",
    NULL 
};

static const char *primitive_states[] = {
    "RayOrigin",
    "RayDirection",
    "InverseRayDirection",
    "Epsilon",
    "HitDistance",
    "BoundMin",
    "BoundMax",
    "GeometricNormal",
    "dPdu",
    "dPdv",
    "ShadingNormal",
    "TextureUV",
    "TextureUVW",
    "dsdu",
    "dsdv",
    "PDF",
    "TimeSeed",
    "HitPoint", // missing in paper
    NULL
};

static const char *texture_states[] = {
    "TextureUV",
    "TextureUVW",
    "TextureColor",
    "FloatTextureValue",
    "du",
    "dv",
    "dsdu",
    "dtdu",
    "dsdv",
    "dtdv",
    "dPdu",
    "dPdv",
    "TimeSeed",
    NULL
};

static const char *material_states[] = {
    "RayOrigin",
    "RayDirection",
    "InverseRayDirection",
    "HitPoint",
    "dPdu",
    "dPdv",
    "LightDirection",
    "LightDistance",
    "LightColor",
    "EmissionColor",
    "BSDFSeed",
    "TimeSeed",
    "PDF",
    "SampleColor",
    "BSDFValue",
    "du",
    "dv",
    "ShadingNormal", // missing in paper
    "HitDistance", // missing in paper
    NULL
};

static const char *light_states[] = {
    "HitPoint",
    "GeometricNormal",
    "ShadingNormal",
    "LightDirection",
    "TimeSeed",
    NULL
};

static const char **interface_states[] = {
    primitive_states, camera_states, material_states, texture_states, light_states
};

/* additional functions to implement the semantic checks here. */
 
static void checkStateMethod(char *methodName, char *stateName, int stateOrder){ 
	int i;
	bool isMethodAvailable = false;
	bool isMethodMatched = false;
	for(i=0; i < sizeof(interface_methods)/sizeof(interface_methods[0]) - 1; i++){
		int j = 0;
		while(((interface_methods)[i])[j] != NULL){
			const char *method = ((interface_methods)[i])[j++];
			if( strcmp(method, methodName) == 0) {
				isMethodAvailable = true;
				if(i == stateOrder){
					isMethodMatched = true;
					break;
				}
			}
		}
		if(isMethodMatched){
			break;
		}
	}
	if(isMethodAvailable && !isMethodMatched ){
		fprintf(stderr,"Interface method %s() not allowed in %s \n", methodName, stateName);
	}
}

static void checkStateVariable(char *stateVarName, char *stateName, int stateOrder){ 
	int i;
	bool isVarAvailable = false;
	bool isVarMatched = false;
	// Split STATE Var.
	char *token = strtok(stateVarName,"_");
	while( token != NULL ) {
	  stateVarName = token;
	  token = strtok(NULL,"_");
    } 
	for(i=0; i < sizeof(interface_states)/sizeof(interface_states[0]) - 1; i++){
		int j = 0;
		while(((interface_states)[i])[j] != NULL){
			const char *var = ((interface_states)[i])[j++];
			if( strcmp(var, strtok(stateVarName,"_")) == 0){ 
				isVarAvailable = true; 
				if(i == stateOrder){
					isVarMatched = true;
					break;
				}
			}
		}
		if(isVarMatched){
			break;
		}
	}
	if(isVarAvailable && !isVarMatched){
		fprintf(stderr,"State variable %s not allowed in %s \n", stateVarName, stateName);
	}
}
 
static void yyerror(const char *s) {
    fprintf(stderr, "%s on line %d\n", s, line_number);
    exit(-1);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            printf("File %s not found.\n", argv[1]);
            return 1;
        }
    } else {
        yyin = stdin;
    }
    
    do {
        yyparse();
    } while (!feof(yyin));
    return 1;
}
