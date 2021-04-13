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
#line 1 "parser.y"

	int yylex(void);
	void yyerror(char *);
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "parser.h"
	
	extern int yylineno;
	int number_of_args = 1;
	int counter = 0;
	char *mother_function;
	char *current_identifier;
	int current_value;
	int arg_temp;
	char *if_operator;

#line 88 "parser.tab.c"

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
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    NUMBER = 258,
    IDENTIFIER = 259,
    LPAR = 260,
    RPAR = 261,
    INT = 262,
    FUNC = 263,
    SC = 264,
    COMMA = 265,
    ASSIGNMENT = 266,
    EQUAL = 267,
    INEQUAL = 268,
    GREATER = 269,
    LESS = 270,
    GREATEREQUAL = 271,
    LESSEQUAL = 272,
    ANDS = 273,
    ORS = 274,
    NOTS = 275,
    RETURN = 276,
    IF = 277,
    ELSE = 278,
    MAIN = 279,
    VOID = 280,
    ARG = 281,
    COMMENT = 282,
    PLUS = 283,
    MINUS = 284,
    MULTIPLICATION = 285,
    DIVISION = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "parser.y"

	char *identifier_name;
	int value; 
	struct dst_node *dst_ptr;

#line 178 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    67,    67,    74,    75,    77,    83,   102,   103,   104,
     108,   117,   130,   139,   140,   141,   142,   143,   144,   145,
     146,   149,   160,   174,   175,   176,   177,   179,   180,   181,
     182,   183,   184,   187,   199,   200,   201,   202,   203,   204,
     207,   208,   211,   218,   219,   220,   223,   224,   225
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENTIFIER", "LPAR", "RPAR",
  "INT", "FUNC", "SC", "COMMA", "ASSIGNMENT", "EQUAL", "INEQUAL",
  "GREATER", "LESS", "GREATEREQUAL", "LESSEQUAL", "ANDS", "ORS", "NOTS",
  "RETURN", "IF", "ELSE", "MAIN", "VOID", "ARG", "COMMENT", "PLUS",
  "MINUS", "MULTIPLICATION", "DIVISION", "$accept", "program",
  "function_list", "function", "function_header", "function_args",
  "variable_declaration", "variable_assignment", "expr", "if_statement",
  "if_conditions", "if_condition", "else_statement", "statement",
  "statement_list", "function_call", "params", "function_ret", YY_NULLPTR
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
     285,   286
};
# endif

#define YYPACT_NINF (-54)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -3,    11,    26,   -54,    -3,    28,    50,   -54,   -54,    66,
     -18,    -2,    52,    15,    53,    55,   -54,   -54,   -54,   -54,
      66,    51,   -54,   -54,   -54,    61,    65,     0,    45,    72,
      23,    67,    45,    33,   -54,    39,    66,   -54,   -54,    73,
     -54,    75,   -54,    76,   -54,    45,    38,   -54,     6,   -54,
      45,    45,    45,    45,    63,    39,    81,    84,   -54,    85,
     -18,     0,    83,    10,   -54,    86,   -17,   -17,   -54,   -54,
      90,    91,    93,    94,    95,    96,    97,    39,    99,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,     3,   100,    66,   102,   103,   -54,   104,    39,    39,
      77,   105,   106,   -54,   -54,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     0,     1,     3,    41,
       0,     0,     0,     0,     0,     0,    34,    35,    36,    37,
      41,     0,    38,    39,     9,     0,     0,     0,     0,     0,
      48,    14,     0,     0,    20,     0,    41,    40,     5,     8,
       6,    44,    45,     0,    13,     0,    12,    10,     0,    47,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,    11,    19,    15,    16,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       7,    43,    42,    19,    46,    27,    28,    29,    30,    31,
      32,     0,     0,    41,     0,     0,    26,     0,     0,     0,
      21,     0,     0,    22,    24,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,    98,   -54,   -54,    41,   -54,   -54,   -22,   -54,
     -53,   -54,     5,   -54,   -19,    -9,    48,   -54
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    26,    16,    17,    33,    18,
      57,    58,    19,    20,    21,    34,    43,    23
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      22,    37,    76,    27,    41,     1,    46,    24,    25,    28,
      48,    22,    65,    52,    53,     6,    83,    59,    30,    31,
      32,    94,    95,    63,    92,    42,     7,    22,    66,    67,
      68,    69,   -13,     9,    50,    51,    52,    53,    50,    51,
      52,    53,    49,    54,    55,   101,   102,    64,    44,    31,
      45,   -13,   -13,   -13,   -13,    10,    29,    38,    35,    56,
      36,    50,    51,    52,    53,    39,    50,    51,    52,    53,
      11,    40,    27,    12,    97,    70,    71,    72,    73,    74,
      75,    47,    62,    60,    22,    61,    77,    13,    14,    15,
      78,    79,    82,    85,    86,    84,    87,    88,    89,    90,
      15,    80,     8,    91,    93,   103,    96,    98,    99,    81,
     100,   104,   105
};

static const yytype_int8 yycheck[] =
{
       9,    20,    55,     5,     4,     8,    28,    25,    26,    11,
      32,    20,     6,    30,    31,     4,     6,    36,     3,     4,
       5,    18,    19,    45,    77,    25,     0,    36,    50,    51,
      52,    53,     9,     5,    28,    29,    30,    31,    28,    29,
      30,    31,     9,     4,     5,    98,    99,     9,     3,     4,
       5,    28,    29,    30,    31,     5,     4,     6,     5,    20,
       5,    28,    29,    30,    31,     4,    28,    29,    30,    31,
       4,     6,     5,     7,    93,    12,    13,    14,    15,    16,
      17,     9,     6,    10,    93,    10,     5,    21,    22,    23,
       6,     6,     9,     3,     3,     9,     3,     3,     3,     3,
      23,    60,     4,     6,     5,   100,     6,     5,     5,    61,
       6,     6,     6
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    33,    34,    35,    36,     4,     0,    34,     5,
       5,     4,     7,    21,    22,    23,    38,    39,    41,    44,
      45,    46,    47,    49,    25,    26,    37,     5,    11,     4,
       3,     4,     5,    40,    47,     5,     5,    46,     6,     4,
       6,     4,    25,    48,     3,     5,    40,     9,    40,     9,
      28,    29,    30,    31,     4,     5,    20,    42,    43,    46,
      10,    10,     6,    40,     9,     6,    40,    40,    40,    40,
      12,    13,    14,    15,    16,    17,    42,     5,     6,     6,
      37,    48,     9,     6,     9,     3,     3,     3,     3,     3,
       3,     6,    42,     5,    18,    19,     6,    46,     5,     5,
       6,    42,    42,    44,     6,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    36,    37,    37,    37,
      38,    39,    39,    40,    40,    40,    40,    40,    40,    40,
      40,    41,    41,    42,    42,    42,    42,    43,    43,    43,
      43,    43,    43,    44,    45,    45,    45,    45,    45,    45,
      46,    46,    47,    48,    48,    48,    49,    49,    49
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     4,     5,     4,     2,     1,
       3,     4,     3,     1,     1,     3,     3,     3,     3,     3,
       1,     7,     8,     1,     7,     7,     4,     3,     3,     3,
       3,     3,     3,     4,     1,     1,     1,     1,     1,     1,
       2,     0,     5,     3,     1,     1,     5,     3,     2
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
#line 68 "parser.y"
        {
		dst = new_program_dstnode();
		dst->down = (yyvsp[0].dst_ptr);
	}
#line 1422 "parser.tab.c"
    break;

  case 3:
#line 74 "parser.y"
                                       {(yyvsp[-1].dst_ptr)->side = (yyvsp[0].dst_ptr); (yyval.dst_ptr) = (yyvsp[-1].dst_ptr); }
#line 1428 "parser.tab.c"
    break;

  case 4:
#line 75 "parser.y"
                           {(yyval.dst_ptr) = (yyvsp[0].dst_ptr);}
#line 1434 "parser.tab.c"
    break;

  case 5:
#line 78 "parser.y"
{
	(yyval.dst_ptr) = new_dstnode_functiondeclaration((yyvsp[-3].dst_ptr));
	(yyval.dst_ptr)->down = (yyvsp[-1].dst_ptr); 
}
#line 1443 "parser.tab.c"
    break;

  case 6:
#line 84 "parser.y"
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->name = (yyvsp[-3].identifier_name);
	node->value = number_of_args;
	node->type = FUNCTION_HEADER;
	node->down = NULL;
	node->side = NULL;
	arg_temp = number_of_args;
	number_of_args = 1; //make this 0 to see what will happen!!!!!!!!!!!!!!!!!!!!!!!!!! , (tested) result-> it seems it should be 1
	counter = 0;
	(yyval.dst_ptr) = node;
	
	mother_function = (yyvsp[-3].identifier_name); // This is used for variable scope //this is also for return (updated!)
	//printf("\nmother function is: %s\n", mother_function);
	//add_to_symtable(&symtable, $2, number_of_args, 0, "null");

}
#line 1465 "parser.tab.c"
    break;

  case 7:
#line 102 "parser.y"
                                                  { number_of_args = number_of_args + counter;}
#line 1471 "parser.tab.c"
    break;

  case 8:
#line 103 "parser.y"
                               { counter = 1; }
#line 1477 "parser.tab.c"
    break;

  case 9:
#line 104 "parser.y"
                    {number_of_args = 0;}
#line 1483 "parser.tab.c"
    break;

  case 10:
#line 109 "parser.y"
{
	printf("\nvariable declaration detected\n");
	(yyval.dst_ptr) = new_dstnode_variabledeclaration((yyvsp[-1].identifier_name));
	//printf("\n I want to see what is the name of identifier here %s\n", $$->name);
	//add_to_symtable(&symtable, $2, 0, 1, mother_function);
}
#line 1494 "parser.tab.c"
    break;

  case 11:
#line 118 "parser.y"
{
	printf("\nvariable assignment detected\n");
	current_identifier = (yyvsp[-3].identifier_name);
	(yyval.dst_ptr) = new_dstnode_variableassignment((yyvsp[-3].identifier_name));
	(yyval.dst_ptr)->down = (yyvsp[-1].dst_ptr);
	(yyval.dst_ptr)->value = (yyval.dst_ptr)->down->value;
	print_expr_nested((yyvsp[-1].dst_ptr));
	
	//printf("\ncurrent identifier is: %s\n", current_identifier);
	//printf("valueeee: %d\n",current_value);
	//add_to_symtable(symtable, $1, $3);
	 	
}
#line 1512 "parser.tab.c"
    break;

  case 12:
#line 131 "parser.y"
{ 
	current_identifier = (yyvsp[-2].identifier_name);
	(yyval.dst_ptr) = new_dstnode_variableassignment((yyvsp[-2].identifier_name));
	(yyval.dst_ptr)->down = (yyvsp[0].dst_ptr);
	(yyval.dst_ptr)->value = (yyval.dst_ptr)->down->value;
}
#line 1523 "parser.tab.c"
    break;

  case 13:
#line 139 "parser.y"
              {(yyval.dst_ptr) = new_dstnode_expr_number((yyvsp[0].value)); }
#line 1529 "parser.tab.c"
    break;

  case 14:
#line 140 "parser.y"
                 {(yyval.dst_ptr) = new_dstnode_expr_identifier((yyvsp[0].identifier_name));}
#line 1535 "parser.tab.c"
    break;

  case 15:
#line 141 "parser.y"
                     {(yyval.dst_ptr) = new_dstnode_expr((yyvsp[-2].dst_ptr), (yyvsp[-1].identifier_name), (yyvsp[0].dst_ptr));}
#line 1541 "parser.tab.c"
    break;

  case 16:
#line 142 "parser.y"
                      {(yyval.dst_ptr) = new_dstnode_expr((yyvsp[-2].dst_ptr), (yyvsp[-1].identifier_name), (yyvsp[0].dst_ptr));}
#line 1547 "parser.tab.c"
    break;

  case 17:
#line 143 "parser.y"
                               {(yyval.dst_ptr) = new_dstnode_expr((yyvsp[-2].dst_ptr), (yyvsp[-1].identifier_name), (yyvsp[0].dst_ptr)); }
#line 1553 "parser.tab.c"
    break;

  case 18:
#line 144 "parser.y"
                         {(yyval.dst_ptr) = new_dstnode_expr((yyvsp[-2].dst_ptr), (yyvsp[-1].identifier_name), (yyvsp[0].dst_ptr)); }
#line 1559 "parser.tab.c"
    break;

  case 19:
#line 145 "parser.y"
                      {(yyval.dst_ptr) = new_dstnode_expr_paranthesis((yyvsp[-1].dst_ptr)); }
#line 1565 "parser.tab.c"
    break;

  case 20:
#line 146 "parser.y"
                    {(yyval.dst_ptr) = new_dstnode_expr_functioncall((yyvsp[0].dst_ptr)->name, (yyvsp[0].dst_ptr)->value); }
#line 1571 "parser.tab.c"
    break;

  case 21:
#line 150 "parser.y"
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->name = "if";
	node->value = 0;
	node->type = IF_STATEMENT;
	node->down = (yyvsp[-4].dst_ptr);
	(node->down)->side = (yyvsp[-1].dst_ptr);
	((node->down)->side)->down = NULL;
	(yyval.dst_ptr) = node;

}
#line 1587 "parser.tab.c"
    break;

  case 22:
#line 162 "parser.y"
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->name = "if_else";
	node->value = 0;
	node->type = IF_STATEMENT;
	node->down = (yyvsp[-5].dst_ptr);
	(node->down)->side = (yyvsp[-2].dst_ptr);
	((node->down)->side)->down =(yyvsp[0].dst_ptr);
	(yyval.dst_ptr) = node;

}
#line 1603 "parser.tab.c"
    break;

  case 23:
#line 174 "parser.y"
                            {(yyval.dst_ptr)->down = new_dstnode_if_condition(current_identifier, if_operator, current_value);}
#line 1609 "parser.tab.c"
    break;

  case 24:
#line 175 "parser.y"
                                                                    { (yyval.dst_ptr) = new_dstnode_if_condition_multiple((yyvsp[-5].dst_ptr), (yyvsp[-3].identifier_name), (yyvsp[-1].dst_ptr));}
#line 1615 "parser.tab.c"
    break;

  case 25:
#line 176 "parser.y"
                                                                   { (yyval.dst_ptr) = new_dstnode_if_condition_multiple((yyvsp[-5].dst_ptr), (yyvsp[-3].identifier_name), (yyvsp[-1].dst_ptr));}
#line 1621 "parser.tab.c"
    break;

  case 26:
#line 177 "parser.y"
                                            { (yyval.dst_ptr) = new_dstnode_if_condition_multiple_not((yyvsp[-1].dst_ptr), (yyvsp[-3].identifier_name));}
#line 1627 "parser.tab.c"
    break;

  case 27:
#line 179 "parser.y"
                                      {(yyval.dst_ptr) = new_dstnode_if_condition((yyvsp[-2].identifier_name), (yyvsp[-1].identifier_name), (yyvsp[0].value)); current_identifier=(yyvsp[-2].identifier_name); if_operator=(yyvsp[-1].identifier_name); current_value = (yyvsp[0].value);}
#line 1633 "parser.tab.c"
    break;

  case 28:
#line 180 "parser.y"
                                      {(yyval.dst_ptr) = new_dstnode_if_condition((yyvsp[-2].identifier_name), (yyvsp[-1].identifier_name), (yyvsp[0].value)); current_identifier=(yyvsp[-2].identifier_name); if_operator=(yyvsp[-1].identifier_name); current_value =(yyvsp[0].value);}
#line 1639 "parser.tab.c"
    break;

  case 29:
#line 181 "parser.y"
                                      {(yyval.dst_ptr) = new_dstnode_if_condition((yyvsp[-2].identifier_name), (yyvsp[-1].identifier_name), (yyvsp[0].value)); current_identifier=(yyvsp[-2].identifier_name); if_operator=(yyvsp[-1].identifier_name); current_value =(yyvsp[0].value);}
#line 1645 "parser.tab.c"
    break;

  case 30:
#line 182 "parser.y"
                                   {(yyval.dst_ptr) = new_dstnode_if_condition((yyvsp[-2].identifier_name), (yyvsp[-1].identifier_name), (yyvsp[0].value));  current_identifier=(yyvsp[-2].identifier_name); if_operator = (yyvsp[-1].identifier_name); current_value = (yyvsp[0].value); }
#line 1651 "parser.tab.c"
    break;

  case 31:
#line 183 "parser.y"
                                           {(yyval.dst_ptr) = new_dstnode_if_condition((yyvsp[-2].identifier_name), (yyvsp[-1].identifier_name), (yyvsp[0].value)); current_identifier=(yyvsp[-2].identifier_name); if_operator=(yyvsp[-1].identifier_name); current_value =(yyvsp[0].value);}
#line 1657 "parser.tab.c"
    break;

  case 32:
#line 184 "parser.y"
                                        {(yyval.dst_ptr) = new_dstnode_if_condition((yyvsp[-2].identifier_name), (yyvsp[-1].identifier_name), (yyvsp[0].value)); current_identifier=(yyvsp[-2].identifier_name); if_operator=(yyvsp[-1].identifier_name); current_value = (yyvsp[0].value);}
#line 1663 "parser.tab.c"
    break;

  case 33:
#line 188 "parser.y"
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->name = "else";
	node->value = 0;
	node->type = ELSE_STATEMENT;
	node->down = (yyvsp[-1].dst_ptr); //I was wondering why here it is ok that else does not have a statement_list. For if statement that is not true.
	node->side = NULL;
	(yyval.dst_ptr) = node;
}
#line 1677 "parser.tab.c"
    break;

  case 34:
#line 199 "parser.y"
                                {(yyval.dst_ptr) = (yyvsp[0].dst_ptr); printf("\n [VD] name: %s\n",(yyval.dst_ptr)->name);}
#line 1683 "parser.tab.c"
    break;

  case 35:
#line 200 "parser.y"
                               {(yyval.dst_ptr) = (yyvsp[0].dst_ptr); printf("\n [VA] name: %s\n",(yyval.dst_ptr)->name);}
#line 1689 "parser.tab.c"
    break;

  case 36:
#line 201 "parser.y"
                        {(yyval.dst_ptr) = (yyvsp[0].dst_ptr); printf("\n [IF] name: %s\n",(yyval.dst_ptr)->name);}
#line 1695 "parser.tab.c"
    break;

  case 37:
#line 202 "parser.y"
                          {(yyval.dst_ptr) = (yyvsp[0].dst_ptr); printf("\n [EL] name: %s\n",(yyval.dst_ptr)->name);}
#line 1701 "parser.tab.c"
    break;

  case 38:
#line 203 "parser.y"
                         {(yyval.dst_ptr) = (yyvsp[0].dst_ptr); printf("\n [FU] name: %s\n",(yyval.dst_ptr)->name);}
#line 1707 "parser.tab.c"
    break;

  case 39:
#line 204 "parser.y"
                        {(yyval.dst_ptr) = (yyvsp[0].dst_ptr); printf("\n [RE] name: %s\n",(yyval.dst_ptr)->name);}
#line 1713 "parser.tab.c"
    break;

  case 40:
#line 207 "parser.y"
                                         { (yyvsp[-1].dst_ptr)->side = (yyvsp[0].dst_ptr); (yyval.dst_ptr) = (yyvsp[-1].dst_ptr); }
#line 1719 "parser.tab.c"
    break;

  case 41:
#line 208 "parser.y"
                  { (yyval.dst_ptr) = NULL;}
#line 1725 "parser.tab.c"
    break;

  case 42:
#line 211 "parser.y"
                                              {
			printf("\ndetecting function call\n");
			(yyval.dst_ptr) = new_dstnode_functioncall((yyvsp[-4].identifier_name), number_of_args);
			number_of_args = 1; 
			counter = 0;
		}
#line 1736 "parser.tab.c"
    break;

  case 43:
#line 218 "parser.y"
                                { number_of_args = number_of_args + counter;}
#line 1742 "parser.tab.c"
    break;

  case 44:
#line 219 "parser.y"
                      { counter = 1; }
#line 1748 "parser.tab.c"
    break;

  case 45:
#line 220 "parser.y"
               {number_of_args = 0;}
#line 1754 "parser.tab.c"
    break;

  case 46:
#line 223 "parser.y"
                                       { (yyval.dst_ptr) = new_dstnode_functionret(mother_function, arg_temp /*$3->value*/); }
#line 1760 "parser.tab.c"
    break;

  case 47:
#line 224 "parser.y"
                              { (yyval.dst_ptr) = new_dstnode_functionret(mother_function, arg_temp);}
#line 1766 "parser.tab.c"
    break;

  case 48:
#line 225 "parser.y"
                             { (yyval.dst_ptr) = new_dstnode_functionret(mother_function, arg_temp);}
#line 1772 "parser.tab.c"
    break;


#line 1776 "parser.tab.c"

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
#line 228 "parser.y"


struct dst_node* new_dstnode_variabledeclaration(char *n)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = VARIABLE_DECLARATION;
	node->name = (char *) malloc(strlen(n)+1);
	strcpy(node->name,n);
	node->value = 0;
	node->down = NULL;
	node->side = NULL;
	return node;
}

struct dst_node* new_dstnode_variableassignment(char *n)
{	
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = VARIABLE_ASSIGNMENT; 
	node->value = 0;
	node->name = (char *) malloc(strlen(n)+1);
	strcpy(node->name,n);
	node->down = NULL;
	node->side = NULL;
	return node;
}


struct dst_node* new_dstnode_functiondeclaration(struct dst_node *dst_ptr)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = FUNCTION;
	node->name = (char *) malloc(strlen(dst_ptr->name)+1);
	strcpy(node->name,dst_ptr->name);
	node->value = dst_ptr->value;
	node->down = NULL;
	node->side = NULL;
	//printf("\n name: %s\n",node->name);
	//printf("value: %d\n",node->value);
	return node;

}

struct dst_node* new_program_dstnode()
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->name = "main"; // I changed form "program" to "main" for IR generation purpose
	node->value = 0;
	node->type = PROGRAM;
	node->down = NULL;
	node->side = NULL;
	return node;
}


struct dst_node* new_dstnode_expr_number(int val)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = EXPRESSION_NUMBER;
	node->name = NULL;
	node->operator_name = NULL; //This will be used later for detecting end of nested expr
	node->value = val;
	node->down = NULL;
	node->side = NULL;
	return node;

}

struct dst_node* new_dstnode_expr_identifier(char *n)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = EXPRESSION_IDENTIFIER;
	node->name = (char *) malloc(strlen(n)+1);
	strcpy(node->name,n);
	node->operator_name = NULL;
	node->value = 0;
	node->down = NULL;
	node->side = NULL;
	return node;

}


struct dst_node* new_dstnode_expr(struct dst_node* first, char *n, struct dst_node* second)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = EXPRESSION;
	node->operator_name = (char *) malloc(strlen(n)+1);
	strcpy(node->operator_name,n);
	node->value = 0;
	node->side = first;
	node->side->side = second;
	return node;

}

struct dst_node* new_dstnode_expr_paranthesis(struct dst_node* first)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = EXPRESSION_PARANTHESIS;
	node->name = NULL;
	node->operator_name = (char *) malloc(strlen(first->operator_name)+1);
	strcpy(node->operator_name, first->operator_name);
	node->value = 0;
	node->side = first;
	return node;

}


struct dst_node* new_dstnode_expr_functioncall(char *n, int val)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = EXPRESSION_FUNCTIONCALL;
	node->name = (char *) malloc(strlen(n)+1);
	strcpy(node->name,n);
	node->value = val;
	node->down = NULL;
	node->side = NULL;
	return node;

}


struct dst_node* new_dstnode_functioncall(char *n, int val)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = FUNCTION_CALL;
	node->name = (char *) malloc(strlen(n)+1);
	strcpy(node->name,n);
	node->value = val;
	node->down = NULL;
	node->side = NULL;
	return node;

}

struct dst_node* new_dstnode_functionret(char *n, int val)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = FUNCTION_RET;
	node->name = (char *) malloc(strlen(n)+1);
	strcpy(node->name,n);
	node->value = val;
	node->down = NULL;
	node->side = NULL;
	return node;

}

struct dst_node* new_dstnode_if_condition(char *n, char *operator ,int val)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = IF_CONDITION;
	node->value = val;
	node->name = (char *) malloc(strlen(n)+1);
	strcpy(node->name,n);
	node->operator_name = (char *) malloc(strlen(operator)+1);
	strcpy(node->operator_name,operator);
	node->down = NULL;
	node->side = NULL;
	return node;

}

struct dst_node* new_dstnode_if_condition_multiple(struct dst_node* first, char *operator, struct dst_node* second)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->type = IF_CONDITION_MULTIPLE;
	node->name = "if_condition_multiple";
	node->operator_name = (char *) malloc(strlen(operator)+1);
	strcpy(node->operator_name,operator);
	node->down = first;
	//printf("\n1. in dst: type of dst node is %s\n", getType(node->side->type));
	(node->down)->side = second;
	//printf("2. in dst: type of dst node is %s\n", getType(node->side->side->type));
	return node;

}

struct dst_node* new_dstnode_if_condition_multiple_not(struct dst_node* first, char *operator)
{
	struct dst_node *node = (struct dst_node *) malloc(sizeof(struct dst_node));
	node->down = first;
	node->type = IF_CONDITION_MULTIPLE_NOT;
	node->operator_name = (char *) malloc(strlen(operator)+1);
	strcpy(node->operator_name,operator);
	return node;

}


//--------------------------------------------------------------------------------------------------------------------------

void add_to_symtable(struct symbol_node **symtable, char *n, int val, int type, char *scope){



	struct symbol_node * new_node = (struct symbol_node *) malloc(sizeof(struct symbol_node)); 
	  
	struct symbol_node  *last = *symtable;  
	  
	new_node->value = val;
	new_node->name = (char *) malloc(strlen(n)+1);
	strcpy(new_node->name,n);
	new_node->type = type;
	new_node->scope = (char *) malloc(strlen(scope)+1);
	strcpy(new_node->scope,scope);
	new_node->next = NULL; 
	  

	if (*symtable == NULL) 
	{ 
	   *symtable = new_node; 
	   return; 
	} 
	  
	while (last->next != NULL) 
		last = last->next; 
	  
	last->next = new_node; 
	return; 


}


int get(struct symbol_node *head, char *n){
	int value;
	struct symbol_node *current;
	current = head;
	
	while(current->next != NULL){
		if(strcmp(current->name,n) == 0){
			return current->value;
		}
		current = current->next;
	}
	
	return -1000000; //error value for not funding a variable or function 
	//return error!
}



int check_semantics(struct dst_node *dst){
	
	//error types -> 0 = duplicate function
	int error = 0;
	
	//-----------------------------------------1.function declaration------------------------------------
	struct dst_node *func_ptr;
	func_ptr = dst->down;
	while(func_ptr != NULL){
		//printf("name: %s\n", func_ptr->name);
		char * func_name = func_ptr->name;
		//printf("name: vatiable %s\n", func_name);
		bool result = is_function_exists(symtable, func_name);
		//printf("bool: %d\n", result);
		if(result == true){
			error += 1; //duplicate function
			printf("-A function is declered before!\n");
			//return error;
		}else{
			add_to_symtable(&symtable, func_name, func_ptr->value, 0, "null");
		}
		func_ptr = func_ptr->side;
	}
	
	
	//--------------------------------------2.variable declaration----------------------------------------
	struct dst_node *statement_ptr;
	struct dst_node *if_statement_ptr;
	
	func_ptr = dst->down;
	
	while(func_ptr != NULL){
		
		if(func_ptr->down != NULL){
			
			if(func_ptr->down->type == VARIABLE_DECLARATION){
				char * variable_name = func_ptr->down->name;
				char * scope = func_ptr->name;
				
				bool result = is_variable_exists(symtable, variable_name, scope);
				
				if(result == true){
					error += 1; //duplicate variable in matching scope
					printf("- Variable %s is declered before!\n", variable_name);
				} else{
					add_to_symtable(&symtable, variable_name, 0, 1, scope);
				}
			}
			
			if(func_ptr->down->type == IF_STATEMENT){
				if_statement_ptr = ((func_ptr->down)->down)->side;
				if(if_statement_ptr->type == VARIABLE_DECLARATION){
					char * variable_name = if_statement_ptr->name;
					char * scope = func_ptr->down->name;
					
					bool result = is_variable_exists(symtable, variable_name, scope);
					
					if(result == true){
						error += 1; //duplicate variable in matching scope
						printf("- Variable %s is declered before!\n", variable_name);
						//return error;
					} else{
						add_to_symtable(&symtable, variable_name, 0, 1, scope);
					}
				}
			}
			
			//going through all other nodes
			statement_ptr = func_ptr->down;
			while(statement_ptr->side != NULL){
				if(statement_ptr->side->type == VARIABLE_DECLARATION){
					char * variable_name = statement_ptr->side->name;
					char * scope = func_ptr->name;
					bool result = is_variable_exists(symtable, variable_name, scope);
					if(result == true){
						error += 1; //duplicate variable in matching scope
						printf("- Variable %s is declered before!\n", variable_name);
					}else{
						add_to_symtable(&symtable, variable_name, 0, 1, scope);
					}
				}
				
				
				if(statement_ptr->side->type == IF_STATEMENT){
				
					if_statement_ptr = ((statement_ptr->side)->down)->side;
					if(if_statement_ptr->type == VARIABLE_DECLARATION){
						char * variable_name = if_statement_ptr->name;
						char * scope = statement_ptr->side->name;
						
						bool result = is_variable_exists(symtable, variable_name, scope);
						
						if(result == true){
							error += 1; //duplicate variable in matching scope
							printf("- Variable %s is declered before!\n", variable_name);
							//return error;
						} else{
							add_to_symtable(&symtable, variable_name, 0, 1, scope);
						}
					}
					
					while(if_statement_ptr->side != NULL){
					
						if(if_statement_ptr->side->type == VARIABLE_DECLARATION){
							char * variable_name = if_statement_ptr->side->name;
							char * scope = statement_ptr->side->name;
							
							bool result = is_variable_exists(symtable, variable_name, scope);
							
							if(result == true){
								error += 1; //duplicate variable in matching scope
								printf("- Variable %s is declered before!\n", variable_name);
								//return error;
							} else{
								add_to_symtable(&symtable, variable_name, 0, 1, scope);
							}
						}
						
						if_statement_ptr = if_statement_ptr->side;
					}
				
				}
				
				statement_ptr = statement_ptr->side;
			}
			
		}
		
		func_ptr = func_ptr->side;
	} 
	

	
	//----------------------------------3.function use--------------------------------------------------------
	func_ptr = dst->down;
	
	while(func_ptr != NULL){
		
		if(func_ptr->down != NULL){
		
			//FUNCTION CALL	
			if((func_ptr->down)->type == FUNCTION_CALL ) { 
			
				char * variable_name = (func_ptr->down)->name;
				int arg = (func_ptr->down)->value;
				
				if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){ //first is for arg_number incompatibility and the second one is for not existance 
					error += 1; //function call is not allowed. 
					if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
						printf("- Funcion ' %s 'is not declered\n", variable_name);
					} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
						printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
					}
				}
			
			}
			
			//FUNCTION CALL IN VARIABLE ASSIGNMENT
			if((func_ptr->down)->type == VARIABLE_ASSIGNMENT){
				if(((func_ptr->down)->down)->type == EXPRESSION_FUNCTIONCALL){
					char * variable_name = ((func_ptr->down)->down)->name;
					int arg = ((func_ptr->down)->down)->value;
					if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){  
						error += 1; //function call is not allowed. 
						if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
							printf("- Funcion ' %s 'is not declered\n", variable_name);
						} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
							printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
						}
					}
				}
			}
			
			//FUNCTION CALL IN IF STATEMENT
			if((func_ptr->down)->type == IF_STATEMENT){
			
				if_statement_ptr = ((func_ptr->down)->down)->side;
				
				if(if_statement_ptr->type ==  FUNCTION_CALL){
				
					char * variable_name = if_statement_ptr->name;
					int arg = if_statement_ptr->value;
				
					if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){   
						error += 1; //function call is not allowed. 
						if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
							printf("- Funcion ' %s 'is not declered\n", variable_name);
						} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
							printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
						}
					}	
				
				} //end of function call 
				
				if(if_statement_ptr->type == VARIABLE_ASSIGNMENT){
					if( (if_statement_ptr->down)->type == EXPRESSION_FUNCTIONCALL){
					
						char * variable_name = ((if_statement_ptr)->down)->name;
						int arg = ((if_statement_ptr)->down)->value;
						if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){  
							error += 1; //function call is not allowed. 
							if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
								printf("- Funcion ' %s 'is not declered\n", variable_name);
							} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
								printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
							}
						}
					}	
				} //end of variable assignment
				
				while(if_statement_ptr->side != NULL){
				
					if((if_statement_ptr->side)->type ==  FUNCTION_CALL){
				
						char * variable_name = ((if_statement_ptr->side))->name;
						int arg = ((if_statement_ptr->side))->value;
					
						if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){   
							error += 1; //function call is not allowed. 
							if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
								printf("- Funcion ' %s 'is not declered\n", variable_name);
							} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
								printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
							}
						}	
				
					} //end of function call 
				
					if((if_statement_ptr->side)->type == VARIABLE_ASSIGNMENT){
						if( ((if_statement_ptr->side)->down)->type == EXPRESSION_FUNCTIONCALL){
						
							char * variable_name = ((if_statement_ptr->side)->down)->name;
							int arg = (((if_statement_ptr->side))->down)->value;
							if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){  
								error += 1; //function call is not allowed. 
								if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
									printf("- Funcion ' %s 'is not declered\n", variable_name);
								} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
									printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
								}
							}
						}	
					} //end of variable assignment
					
					if_statement_ptr = if_statement_ptr->side;
				}
			
			}
		
			
			//------------------Going through other statements in function---------------------
			statement_ptr = func_ptr->down;
			while(statement_ptr->side != NULL){
			
				if((statement_ptr->side)->type == FUNCTION_CALL) {
			
					char * variable_name = (statement_ptr->side)->name;
					int arg = (statement_ptr->side)->value;
				
					if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){ 
						error += 1; //function call is not allowed. 
						if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
							printf("- Funcion ' %s 'is not declered\n", variable_name);
						} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
							printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
						}
					}
			
				}
				
				
				if((statement_ptr->side)->type == VARIABLE_ASSIGNMENT){
					if(((statement_ptr->side)->down)->type == EXPRESSION_FUNCTIONCALL){
						char * variable_name = ((statement_ptr->side)->down)->name;
						int arg = ((statement_ptr->side)->down)->value;
						if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){  
							error += 1; //function call is not allowed. 
							if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
								printf("- Funcion ' %s 'is not declered\n", variable_name);
							} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
								printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
							}
						}
					}
				}

				
				if((statement_ptr->side)->type == IF_STATEMENT){
			
					if_statement_ptr = ((statement_ptr->side)->down)->side;
					
					if(if_statement_ptr->type ==  FUNCTION_CALL){
					
						char * variable_name = if_statement_ptr->name;
						int arg = if_statement_ptr->value;
					
						if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){   
							error += 1; //function call is not allowed. 
							if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
								printf("- Funcion ' %s 'is not declered\n", variable_name);
							} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
								printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
							}
						}	
					
					} //end of function call 
					
					if(if_statement_ptr->type == VARIABLE_ASSIGNMENT){
						if( (if_statement_ptr->down)->type == EXPRESSION_FUNCTIONCALL){
						
							char * variable_name = (if_statement_ptr->down)->name;
							int arg = ((if_statement_ptr)->down)->value;
							if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){  
								error += 1; //function call is not allowed. 
								if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
									printf("- Funcion ' %s 'is not declered\n", variable_name);
								} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
									printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
								}
							}
						}	
					} //end of variable assignment
				
					while(if_statement_ptr->side != NULL){
					
						if((if_statement_ptr->side)->type ==  FUNCTION_CALL){
					
							char * variable_name = ((if_statement_ptr->side))->name;
							int arg = ((if_statement_ptr->side))->value;
						
							if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){   
								error += 1; //function call is not allowed. 
								if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
									printf("- Funcion ' %s 'is not declered\n", variable_name);
								} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
									printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
								}
							}	
					
						} //end of function call 
					
						if((if_statement_ptr->side)->type == VARIABLE_ASSIGNMENT){
							if( ((if_statement_ptr->side)->down)->type == EXPRESSION_FUNCTIONCALL){
							
								char * variable_name = ((if_statement_ptr->side)->down)->name;
								int arg = (((if_statement_ptr->side))->down)->value;
								if(get(symtable,variable_name) != arg || get(symtable,variable_name) == -1000000 ){  
									error += 1; //function call is not allowed. 
									if(get(symtable,variable_name) == -1000000){ // func is not declered, therefore can't be used
										printf("- Funcion ' %s 'is not declered\n", variable_name);
									} else if(get(symtable,variable_name) != arg){ // function arguments is not matched
										printf("- Funcion ' %s ' 's arguments is not compatible with function decleration\n", variable_name);
									}
								}
							}	
						} //end of variable assignment
						
						if_statement_ptr = if_statement_ptr->side;
					}
			
				}

				
				statement_ptr = statement_ptr->side;
			}
			
		}
		
		func_ptr = func_ptr->side;
		
	} 
	
		
	//----------------------------------4.variable use--------------------------------------------------------
	
	func_ptr = dst->down;
	struct dst_node *expr_ptr;
	
	while(func_ptr != NULL){
		
		if(func_ptr->down != NULL){
		
			//VARIABLE ASSIGNMENT	
			if((func_ptr->down)->type == VARIABLE_ASSIGNMENT ) { 
			
				char * variable_name = (func_ptr->down)->name;
				char * scope = func_ptr->name;
				
				bool result = is_variable_exists(symtable, variable_name, scope);
				
				if(result == false){
					error += 1; //variable is not declared!
					printf("- Variable %s is not declared before!\n", variable_name);
				} 
				
				expr_ptr = (func_ptr->down)->down;
				if( expr_ptr->type == EXPRESSION_IDENTIFIER ){
						char * variable_name = expr_ptr->name;
						char * scope = func_ptr->name;
						
						bool result = is_variable_exists(symtable, variable_name, scope);
						
						if(result == false){
							error += 1; 
							printf("- Variable %s is not declared before!\n", variable_name);
						} 
				}
				
				while(expr_ptr->side != NULL){
					if( (expr_ptr->side)->type == EXPRESSION_IDENTIFIER ){
						char * variable_name = (expr_ptr->side)->name;
						char * scope = func_ptr->name;
						
						bool result = is_variable_exists(symtable, variable_name, scope);
						
						if(result == false){
							error += 1; 
							printf("- Variable %s is not declared before!\n", variable_name);
						} 
					}
					
					expr_ptr = expr_ptr->side;
				}
			
			}
			
			//IF STATEMENT
			if(func_ptr->down->type == IF_STATEMENT){
			
				if_statement_ptr = ((func_ptr->down)->down)->side;
				
				if(if_statement_ptr->type == VARIABLE_ASSIGNMENT){
					char * variable_name = if_statement_ptr->name;
					char * scope = func_ptr->down->name; //it should changeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee. maybe there are so many if else
					
					bool result = is_variable_exists(symtable, variable_name, scope);
					
					if(result == false){
						error += 1;
						printf("- Variable %s is not declared before!\n", variable_name);
					} 
					
					expr_ptr = if_statement_ptr->down;
					if( expr_ptr->type == EXPRESSION_IDENTIFIER ){
							char * variable_name = expr_ptr->name;
							char * scope = func_ptr->down->name;
							
							bool result = is_variable_exists(symtable, variable_name, scope);
							
							if(result == false){
								error += 1; 
								printf("- Variable %s is not declared before!\n", variable_name);
							} 
					}
					
					while(expr_ptr->side != NULL){
						if( (expr_ptr->side)->type == EXPRESSION_IDENTIFIER ){
							char * variable_name = (expr_ptr->side)->name;
							char * scope = func_ptr->down->name;
							
							bool result = is_variable_exists(symtable, variable_name, scope);
							
							if(result == false){
								error += 1; 
								printf("- Variable %s is not declared before!\n", variable_name);
							} 
						}
						
						expr_ptr = expr_ptr->side;
					}
			
						
				}
				
				while(if_statement_ptr->side != NULL){
					if(if_statement_ptr->side->type == VARIABLE_ASSIGNMENT){
						char * variable_name = if_statement_ptr->side->name;
						char * scope = func_ptr->down->name;
						
						bool result = is_variable_exists(symtable, variable_name, scope);
						
						if(result == false){
							error += 1;
							printf("- Variable %s is not declared before!\n", variable_name);
						}
						
						expr_ptr = if_statement_ptr->side->down;
						if( expr_ptr->type == EXPRESSION_IDENTIFIER ){
								char * variable_name = expr_ptr->name;
								char * scope = func_ptr->down->name;
								
								bool result = is_variable_exists(symtable, variable_name, scope);
								
								if(result == false){
									error += 1; 
									printf("- Variable %s is not declared before!\n", variable_name);
								} 
						}
						
						while(expr_ptr->side != NULL){
							if( (expr_ptr->side)->type == EXPRESSION_IDENTIFIER ){
								char * variable_name = (expr_ptr->side)->name;
								char * scope = func_ptr->down->name;
								
								bool result = is_variable_exists(symtable, variable_name, scope);
								
								if(result == false){
									error += 1; 
									printf("- Variable %s is not declared before!\n", variable_name);
								} 
							}
							
							expr_ptr = expr_ptr->side;
						}
					}
					
					if_statement_ptr = if_statement_ptr->side;
				}
					
			}//end of if statement case
			
			
			
			//going through all other nodes
			statement_ptr = func_ptr->down;
			while(statement_ptr->side != NULL){
				
				//VARIABLE ASSIGNMENT	
				if(statement_ptr->side->type == VARIABLE_ASSIGNMENT ) { 
					
					char * variable_name = statement_ptr->side->name;
					char * scope = func_ptr->name;
						
					bool result = is_variable_exists(symtable, variable_name, scope);
						
					if(result == false){
						error += 1; //variable is not declared!
						printf("- Variable %s is not declared before!\n", variable_name);
					} 
						
					expr_ptr = statement_ptr->side->down;
					if( expr_ptr->type == EXPRESSION_IDENTIFIER ){
						char * variable_name = expr_ptr->name;
						char * scope = func_ptr->name;
						
						bool result = is_variable_exists(symtable, variable_name, scope);
						
						if(result == false){
							error += 1; 
							printf("- Variable %s is not declared before!\n", variable_name);
						} 
					}
						
					while(expr_ptr->side != NULL){
						if( (expr_ptr->side)->type == EXPRESSION_IDENTIFIER ){
							char * variable_name = (expr_ptr->side)->name;
							char * scope = func_ptr->name;
							
							bool result = is_variable_exists(symtable, variable_name, scope);
							
							if(result == false){
								error += 1; 
								printf("- Variable %s is not declared before!\n", variable_name);
							} 
						}
							
						expr_ptr = expr_ptr->side;
					}
				
				}
				
				//IF STATEMENT
				if(statement_ptr->side->type == IF_STATEMENT){
				
					if_statement_ptr = ((statement_ptr->side)->down)->side;
					
					if(if_statement_ptr->type == VARIABLE_ASSIGNMENT){
						char * variable_name = if_statement_ptr->name;
						char * scope = statement_ptr->side->name; //it should changeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee. maybe there are so many if else
						
						bool result = is_variable_exists(symtable, variable_name, scope);
						
						if(result == false){
							error += 1;
							printf("- Variable %s is not declared before!\n", variable_name);
						} 
						
						expr_ptr = if_statement_ptr->down;
						if( expr_ptr->type == EXPRESSION_IDENTIFIER ){
							char * variable_name = expr_ptr->name;
							char * scope = func_ptr->down->name;
							
							bool result = is_variable_exists(symtable, variable_name, scope);
							
							if(result == false){
								error += 1; 
								printf("- Variable %s is not declared before!\n", variable_name);
							} 
						}
						
						while(expr_ptr->side != NULL){
							if( (expr_ptr->side)->type == EXPRESSION_IDENTIFIER ){
								char * variable_name = (expr_ptr->side)->name;
								char * scope = statement_ptr->side->name;
								
								bool result = is_variable_exists(symtable, variable_name, scope);
								
								if(result == false){
									error += 1; 
									printf("- Variable %s is not declared before!\n", variable_name);
								} 
							}
							
							expr_ptr = expr_ptr->side;
						}
				
							
					}
					
					while(if_statement_ptr->side != NULL){
						if(if_statement_ptr->side->type == VARIABLE_ASSIGNMENT){
							char * variable_name = if_statement_ptr->side->name;
							char * scope = statement_ptr->side->name;
							
							bool result = is_variable_exists(symtable, variable_name, scope);
							
							if(result == false){
								error += 1;
								printf("- Variable %s is not declared before!\n", variable_name);
							}
							
							expr_ptr = if_statement_ptr->side->down;
							if( expr_ptr->type == EXPRESSION_IDENTIFIER ){
								char * variable_name = expr_ptr->name;
								char * scope = statement_ptr->side->name;
								
								bool result = is_variable_exists(symtable, variable_name, scope);
								
								if(result == false){
									error += 1; 
									printf("- Variable %s is not declared before!\n", variable_name);
								} 
							}
							
							while(expr_ptr->side != NULL){
								if( (expr_ptr->side)->type == EXPRESSION_IDENTIFIER ){
									char * variable_name = (expr_ptr->side)->name;
									char * scope = statement_ptr->side->name;
									
									bool result = is_variable_exists(symtable, variable_name, scope);
									
									if(result == false){
										error += 1; 
										printf("- Variable %s is not declared before!\n", variable_name);
									} 
								}
								
								expr_ptr = expr_ptr->side;
							}
						}
						
						if_statement_ptr = if_statement_ptr->side;
					}
						
				}//end of if statement case
			
			
				statement_ptr = statement_ptr->side;
			}
			
			
			
				
		
		}
		
		
		func_ptr = func_ptr->side;
		
	} 	
	
	
	return error;
	
	
} //end of check_semantics

void print_dst(struct dst_node *dst){

	struct dst_node *temp;
	struct dst_node *func_ptr;
	struct dst_node *statement_ptr;
	struct dst_node *if_ptr;
	struct dst_node *if_cond;
	struct dst_node *else_ptr;
	temp = dst;
	
	if(temp == NULL){
		printf("The node could not be empty!");
		return;
	}
	
	printf("\nname: %s\n", temp->name);
	printf("|\n");
	printf("∨\n");
	func_ptr = temp->down;
	
	while(func_ptr != NULL){
			
		printf("name: %s", func_ptr->name);
		printf(", type: %s", getType(func_ptr->type));
		printf(", value or arg: %d", func_ptr->value);
		
		if(func_ptr->down != NULL){
			printf("\n->\n");
			printf("\tname: %s", func_ptr->down->name);
			printf(", type: %s", getType(func_ptr->down->type));
			printf(", value or arg: %d", func_ptr->down->value);
			
			statement_ptr = func_ptr->down;
			while(statement_ptr->side != NULL){
				printf("\n->\n");
				printf("\tname: %s", statement_ptr->side->name);
				printf(", type: %s", getType(statement_ptr->side->type));
				printf(", value or arg: %d", statement_ptr->side->value);
				
				//printing if statement and statements in if body
				if(statement_ptr->side->type == IF_STATEMENT){
					if_ptr = ((statement_ptr->side)->down)->side;
					if_cond = ((statement_ptr->side)->down)->down;
					else_ptr = if_ptr->down;
					
					if(if_cond != NULL){
						printf("\n->\n");
						printf("\t\tname: %s", if_cond->name);
						printf(", type: %s", getType(if_cond->type));
						printf(", value or arg: %d", if_cond->value);
					}
	
					while(if_cond->side != NULL){
					
						printf("\t\n->\n");
						printf("\t\tname: %s", if_cond->side->name);
						printf(", type: %s", getType(if_cond->side->type));
						printf(", value or arg: %d", if_cond->side->value);
						if_cond = if_cond->side;
					}
					
					if(if_ptr != NULL){
						printf("\n->\n");
						printf("\t\t-------------------------if---------------------------\n\n");
						printf("\t\tname: %s", if_ptr->name);
						printf(", type: %s", getType(if_ptr->type));
						printf(", value or arg: %d", if_ptr->value);
					}
	
					while(if_ptr->side != NULL){
					
						printf("\t\n->\n");
						printf("\t\tname: %s", if_ptr->side->name);
						printf(", type: %s", getType(if_ptr->side->type));
						printf(", value or arg: %d", if_ptr->side->value);
						if_ptr = if_ptr->side;
					}
					
					//printing else statements if available
					
					if( else_ptr != NULL){
						
						else_ptr = else_ptr->down;
						printf("\n->\n");
						printf("\t\t-------------------------else-------------------------\n\n");
						printf("\t\tname: %s", else_ptr->name);
						printf(", type: %s", getType(else_ptr->type));
						printf(", value or arg: %d", else_ptr->value);
						while(else_ptr->side != NULL){
							printf("\n->\n");
							printf("\t\tname: %s", else_ptr->side->name);
							printf(", type: %s", getType(else_ptr->side->type));
							printf(", value or arg: %d", else_ptr->side->value);
							else_ptr = else_ptr->side;
						} 
					}
					
				}
				
				statement_ptr = statement_ptr->side;
			}
		}
		
		func_ptr = func_ptr->side;
		printf("\n---------------------------------------------------------------\n");
	
	}

}


void print_expr_nested(struct dst_node *dst){

	printf("\n------------------------------------------------------------------------------------\n");
	printf("\t\tname: %s", dst->name);
	printf(", type: %s", getType(dst->type));
	printf(", value or arg: %d", dst->value);
	printf(", operator: %s", dst->operator_name);

	while(dst->side != NULL){
		printf("\n------------------------------------------------------------------------------------\n");
		printf("\t\tname: %s", dst->side->name);
		printf(", type: %s", getType(dst->side->type));
		printf(", value or arg: %d", dst->side->value);
		printf(", operator: %s", dst->side->operator_name);
		
		dst = dst->side;
	}
}

char* getType(int i){

	char * name;
	switch(i){
	
	case 0: 
		name = "PROGRAM";
		break;
	case 1: 
		name = "FUNCTION_HEADER";
		break;
	case 2: 
		name = "FUNCTION";
		break;
	case 3: 
		name = "FUNCTION_CALL";
		break;
	case 4:
		name = "FUNCTION_RET";
		break;
	case 5:
		name = "VARIABLE_DECLARATION";
		break;
	case 6: 
		name = "VARIABLE_ASSIGNMENT";
		break;
	case 7: 
		name = "IF_STATEMENT";
		break;
	case 8: 
		name = "IF_CONDITION";
		break;
	case 9:
		name = "IF_CONDITION_MULTIPLE";
		break;
	case 10: 
		name = "IF_CONDITION_MULTIPLE_NOT";
		break;
	case 11:
		name = "ELSE_STATEMENT";
		break;	
	case 12: 
		name = "EXPRESSION";
		break;	
	case 13: 
		name = "EXPRESSION_NUMBER";
		break;	
	case 14: 
		name = "EXPRESSION_IDENTIFIER";
		break;	
	case 15:
		name = "EXPRESSION_FUNCTIONCALL";
		break;
	case 16: 
		name = "EXPRESSION_PARANTHESIS";
		break;					
	default: 
		break;	
		
	}
	
	return name;
}		


//*****************************print symbol table********************************

void print_symboltable(struct symbol_node *symtable){
	
	struct symbol_node *current;
	current = symtable;

	
	while(current != NULL){
		
		printf("Type: %s", getType_symtbale(current->type));
		printf(", Name: %s", current->name);
		printf(", Value: %d", current->value);
		printf(", Scope: %s\n", current->scope);
		
		current = current->next;
		
	}

}

char* getType_symtbale(int i){

	char * name;
	switch(i){
	
	case 0: 
		name = "FUNCTION";
		break;
	case 1: 
		name = "VARIABLE";
		break;					
	default: 
		break;	
		
	}
	
	return name;
}		

bool is_function_exists(struct symbol_node *symtable, char *n){
	
	bool exist = false;
	while(symtable != NULL){
		if(strcmp(symtable->name, n) == 0){
			if(symtable->type == 0){
				exist = true;
				return exist;
			}
		}
		symtable = symtable->next;
	}
	
}

bool is_variable_exists(struct symbol_node *symtable, char *n, char *scope){
	
	bool exist = false;
	while(symtable != NULL){
		if(strcmp(symtable->name, n) == 0){
			if(symtable->type == 1){
				if(strcmp(symtable->scope, scope) == 0){
					exist = true;
					return exist;
				}
			}
		}
		symtable = symtable->next;
	}
	
}


struct IR_node *generate_IR(struct dst_node *dst){
	

	if(dst == NULL){
		return NULL;
	}

	if(dst->type == PROGRAM){
		printf("in program case.\n");
		struct IR_node *new_prog_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node)); 
		new_prog_IR_node->instruction = CALL;
		new_prog_IR_node->operand_type = IDENTIFIERS;
		new_prog_IR_node->p_code_operand.identifier = dst->name;
		new_prog_IR_node->next = (struct IR_node *) malloc(sizeof(struct IR_node));
		char *label_here = gen_label();
		new_prog_IR_node->next->label = label_here;
		new_prog_IR_node->next->instruction = JMP;
		new_prog_IR_node->next->operand_type = IDENTIFIERS;
		new_prog_IR_node->next->p_code_operand.identifier = label_here;
		new_prog_IR_node->next->next = generate_IR(dst->down);
		return new_prog_IR_node;
	}
	
	
	//should have a switch-case for every type of dst node
	switch(dst->type)
	{
	
		case FUNCTION_CALL: ;//this should be changed to function call later
			printf("in function call case.\n");
			struct IR_node *new_func_call_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node)); 
			new_func_call_IR_node->instruction = CALL;
			new_func_call_IR_node->operand_type = IDENTIFIERS;
			new_func_call_IR_node->p_code_operand.identifier = dst->name;
			new_func_call_IR_node->address = dst->value; //my design decison is to put number of function arguments in IR address
			//new_func_call_IR_node->next = generate_IR(dst->side);
			return new_func_call_IR_node;
			break;
		
		case FUNCTION_RET: ;//this should be added and definitely be changed.
			printf("in function return case.\n");
			struct IR_node *new_func_ret_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node)); 
			new_func_ret_IR_node->instruction = RET;
			new_func_ret_IR_node->operand_type = CONSTANT;
			new_func_ret_IR_node->p_code_operand.constant = dst->value;
			return new_func_ret_IR_node;
			break;
		
		case FUNCTION: ;
			printf("in function case.");
			char *label_function_begin = gen_label();
			char *label_function_end = gen_label();
			printf("  function begin label : %s , function end label %s\n", label_function_begin, label_function_end);
			struct IR_node *new_func_IR_node = generate_IR(dst->down); //p-code for the first statement in function body
			new_func_IR_node->label = label_function_begin;
			struct IR_node *last_node_func = new_func_IR_node;
			while(last_node_func->next != NULL)
				last_node_func = last_node_func->next;
			last_node_func->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_func->next = generate_IR(dst->side);
			last_node_func->label = label_function_end;
			return new_func_IR_node;
			break;
					
		case VARIABLE_ASSIGNMENT: ;
			printf("in variable assignment case.\n");
			struct IR_node *new_IR_node = generate_IR(dst->down);
			struct IR_node *last_node = new_IR_node;
			while(last_node->next != NULL)
				last_node = last_node->next;
			last_node->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node = last_node->next;
			last_node->instruction = POP;
			last_node->operand_type = IDENTIFIERS;
			last_node->p_code_operand.identifier = strdup(dst->name);
			last_node->next = generate_IR(dst->side);
			return new_IR_node;
			break;
			
		case VARIABLE_DECLARATION: ;
			printf("in variable declaration case.\n");
			
			return generate_IR(dst->side);
			break;
			
		case IF_STATEMENT: ;
			printf("in if statement case.\n");
			char *label_if_begin = gen_label();
			char *label_if_end = gen_label();
			struct IR_node *new_IF_condition_IR_node = generate_IR(dst->down); //p-code for if condition
			new_IF_condition_IR_node->label = label_if_begin;
			struct IR_node *last_node_IF = new_IF_condition_IR_node;
			while(last_node_IF->next != NULL)
				last_node_IF = last_node_IF->next;
			last_node_IF->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_IF = last_node_IF->next;
			last_node_IF->instruction = BRCF;
			last_node_IF->operand_type = IDENTIFIERS;
			last_node_IF->p_code_operand.identifier = label_if_end;
			last_node_IF->next = generate_IR(dst->down->side); //p-code for if body
			struct IR_node *last_node_IF_body = last_node_IF->next;
			while(last_node_IF_body->next != NULL)
				last_node_IF_body = last_node_IF_body->next;
			last_node_IF_body->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_IF_body = last_node_IF_body->next;

			if(((dst->down)->side)->down != NULL){
				last_node_IF_body = generate_IR(((dst->down)->side)->down); //p-code for else
				last_node_IF_body->label = label_if_end; //if_end_label should be assigned to either begining of the else statement or anything after if body finishes
				last_node_IF_body->next = generate_IR(dst->side);
			}else{
				last_node_IF_body = generate_IR(dst->side);
				last_node_IF_body->label = label_if_end; //if_end_label should be assigned to either begining of the else statement or anything after if body finishes
			}

			return new_IF_condition_IR_node;
			break;
		
		case IF_CONDITION: ;
			printf("in if condition case.\n");
			struct IR_node *new_IF_condition_single_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node));
			new_IF_condition_single_IR_node->instruction = PUSH; 
			new_IF_condition_single_IR_node->operand_type = CONSTANT;
			new_IF_condition_single_IR_node->p_code_operand.constant = dst->value;
			new_IF_condition_single_IR_node->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			new_IF_condition_single_IR_node->next->instruction = PUSH; 
			new_IF_condition_single_IR_node->next->operand_type = IDENTIFIERS;
			new_IF_condition_single_IR_node->next->p_code_operand.identifier = dst->name;
			new_IF_condition_single_IR_node->next->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			
			if(strcmp(dst->operator_name,"==") == 0){
				new_IF_condition_single_IR_node->next->next->instruction = EQUALS;
			} else if(strcmp(dst->operator_name,"!=") == 0){
				new_IF_condition_single_IR_node->next->next->instruction = NOTEQUALS;
			} else if(strcmp(dst->operator_name,">") == 0){
				new_IF_condition_single_IR_node->next->next->instruction = GREATER_THAN;
			} else if(strcmp(dst->operator_name,"<") == 0){
				new_IF_condition_single_IR_node->next->next->instruction = LESS_THAN;
			} else if(strcmp(dst->operator_name,">=") == 0){
				new_IF_condition_single_IR_node->next->next->instruction = GREATER_EQUAL;
			} else if(strcmp(dst->operator_name,"<=") == 0){
				new_IF_condition_single_IR_node->next->next->instruction = LESS_EQUAL;
			} 
			
			return new_IF_condition_single_IR_node;
			break;
		
		case IF_CONDITION_MULTIPLE: ;
			printf("in if condition multiple case.\n");
			struct IR_node *new_IF_condition_multiple_first_IR_node = generate_IR(dst->down); //p-code for first if condition result
			struct IR_node *last_node_fisrt_if_cond = new_IF_condition_multiple_first_IR_node;
			while(last_node_fisrt_if_cond->next != NULL)
				last_node_fisrt_if_cond = last_node_fisrt_if_cond->next;
			last_node_fisrt_if_cond->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_fisrt_if_cond = last_node_fisrt_if_cond->next;
			last_node_fisrt_if_cond->instruction = PUSH; 
			last_node_fisrt_if_cond->operand_type = CONSTANT;
			last_node_fisrt_if_cond->p_code_operand.constant = dst->side->value;
			
			
			struct IR_node *new_IF_condition_multiple_second_IR_node = generate_IR(dst->down->side); //p-code for second if condition result
			struct IR_node *last_node_second_if_cond = new_IF_condition_multiple_second_IR_node;
			while(last_node_second_if_cond->next != NULL)
				last_node_second_if_cond = last_node_second_if_cond->next;
			last_node_second_if_cond->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_second_if_cond = last_node_second_if_cond->next;
			last_node_second_if_cond->instruction = PUSH; 
			last_node_second_if_cond->operand_type = CONSTANT;
			last_node_second_if_cond->p_code_operand.constant = dst->side->side->value;
			
			last_node_fisrt_if_cond->next = last_node_second_if_cond;
			struct IR_node *new_operation_cond_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_second_if_cond->next = new_operation_cond_IR_node;
			
			if(strcmp(dst->operator_name,"&&") == 0){
				new_operation_cond_IR_node->instruction = AND;
			} else if(strcmp(dst->operator_name,"||") == 0){
				new_operation_cond_IR_node->instruction = OR;
			} 
			
			return new_IF_condition_multiple_first_IR_node;
			break;
			
			
		case IF_CONDITION_MULTIPLE_NOT: ;
			printf("in if condition not case.\n");
			struct IR_node *new_IF_condition_multiple_not_IR_node = generate_IR(dst->side); //p-code for (not) if condition result
			struct IR_node *last_node_not_if_cond = new_IF_condition_multiple_not_IR_node;
			while(last_node_not_if_cond->next != NULL)
				last_node_not_if_cond = last_node_not_if_cond->next;
			last_node_not_if_cond->next = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_not_if_cond = last_node_not_if_cond->next;
			last_node_not_if_cond->instruction = PUSH; 
			last_node_not_if_cond->operand_type = CONSTANT;
			last_node_not_if_cond->p_code_operand.constant = dst->side->value;
			
			struct IR_node *new_operation_not_cond_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node));
			last_node_not_if_cond->next = new_operation_not_cond_IR_node;
			new_operation_not_cond_IR_node->instruction = NOT;
			
			return new_IF_condition_multiple_not_IR_node;
			break;	
		
			
		case ELSE_STATEMENT: ;
			printf("in else statement case.\n");
			struct IR_node *new_else_IR_node = generate_IR(dst->down); //p-code for else body
			new_else_IR_node->next = generate_IR(dst->side);
			return new_else_IR_node;
			break;
			
			
		case EXPRESSION: ;
			printf("in expression case.\n");
			
			struct IR_node *new_first_expr_IR_node = generate_IR(dst->side); //p-code for first expression result
		
			struct IR_node *new_second_expr_IR_node = generate_IR(dst->side->side); //p-code for second expression result
			

			struct IR_node *new_operation_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node));			
			new_first_expr_IR_node->next = new_second_expr_IR_node;
			new_second_expr_IR_node->next = new_operation_IR_node;

			if(strcmp(dst->operator_name,"+") == 0){
				new_operation_IR_node->instruction = ADD;
			} else if(strcmp(dst->operator_name,"-") == 0){
				new_operation_IR_node->instruction = SUB;
			} else if(strcmp(dst->operator_name,"*") == 0){
				new_operation_IR_node->instruction = MUL;
			} else if(strcmp(dst->operator_name,"/") == 0){
				new_operation_IR_node->instruction = DIV;
			}
			
			return new_first_expr_IR_node;
			
			break;
			
			
		case EXPRESSION_PARANTHESIS: ;
			printf("in expression paranthesis case.\n");
			
			struct IR_node *new_first_expr_par_IR_node = generate_IR(dst->side); //p-code for first expression result
		
			struct IR_node *new_operation_par_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node));
			new_first_expr_par_IR_node->next = new_operation_par_IR_node;
			
			
			if(strcmp(dst->operator_name,"+") == 0){
				new_operation_par_IR_node->instruction = ADD;
			} else if(strcmp(dst->operator_name,"-") == 0){
				new_operation_par_IR_node->instruction = SUB;
			} else if(strcmp(dst->operator_name,"*") == 0){
				new_operation_par_IR_node->instruction = MUL;
			} else if(strcmp(dst->operator_name,"/") == 0){
				new_operation_par_IR_node->instruction = DIV;
			}
			
			return new_first_expr_par_IR_node;
			
			break;
			
		case EXPRESSION_NUMBER: ;
			printf("in expression number case.\n");
			struct IR_node *new_number_expr_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node));
			new_number_expr_IR_node->instruction = PUSH;
			new_number_expr_IR_node->operand_type = CONSTANT;
			new_number_expr_IR_node->p_code_operand.constant = dst->value;
			return new_number_expr_IR_node;
			break;
			
		case EXPRESSION_IDENTIFIER: ;
			printf("in expression identifier case.\n");
			struct IR_node *new_identifier_expr_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node));
			new_identifier_expr_IR_node->instruction = PUSH;
			new_identifier_expr_IR_node->operand_type = IDENTIFIERS;
			new_identifier_expr_IR_node->p_code_operand.identifier = dst->name;
			return new_identifier_expr_IR_node;
			break;
			
		case EXPRESSION_FUNCTIONCALL:
			printf("in expression function call case.\n");
			struct IR_node *new_expr_func_call_IR_node = (struct IR_node *) malloc(sizeof(struct IR_node)); 
			new_expr_func_call_IR_node->instruction = CALL;
			new_expr_func_call_IR_node->operand_type = IDENTIFIERS;
			new_expr_func_call_IR_node->p_code_operand.identifier = dst->name;
			new_expr_func_call_IR_node->address = dst->value; //my design decison is to put number of function arguments in IR address
			//new_func_call_IR_node->next = generate_IR(dst->side);
			return new_expr_func_call_IR_node;
		
		case FUNCTION_HEADER: // should never happens
			printf("in function header case.\n");
			break;
		
		default:
			printf("in default case.\n");
			printf("type of dst node is %d\n", dst->type);
			break;	
	
			
					
	}

}


//label generation function
char *gen_label()
{
	static int label_counter = 0;
	//asssuming here we just need up to 999 labels
	char *new_label = (char *) malloc(5);
	sprintf(new_label, "L%d", label_counter);
	label_counter++;
	return new_label;

}


//print IR 

void print_IR(struct IR_node *IR){
	
	
	struct IR_node *current;
	current = IR;
	
	while(current != NULL){
	
		if(current->label != NULL){
			printf(" %s\t", current->label);
		}
		
		printf(" %s\t", getInstructionName(current->instruction));
		
		
		if(current->operand_type == IDENTIFIERS){
			printf(" %s\n", current->p_code_operand.identifier);
		} else if(current->operand_type == CONSTANT){
			printf(" %d\n", current->p_code_operand.constant);
		} else if(current->operand_type == REGISTER){
			printf(" %s\n", getRegisterName(current->p_code_operand.p_register));
		} else {
			printf("\n");
		}
				
		current = current->next;
	}

}

const char* getInstructionName(enum p_code_inst inst) 
{
   switch (inst) 
   {
      case 0: return "PUSH"; break;
      case 1: return "POP"; break;
      case 2: return "ADD"; break;
      case 3: return "SUB"; break;
      case 4: return "MUL"; break;
      case 5: return "DIV"; break;
      case 6: return "NOP"; break;
      case 7: return "JMP"; break;
      case 8: return "BRCT"; break;
      case 9: return "BRCF"; break;
      case 10: return "AND"; break;
      case 11: return "OR"; break;
      case 12: return "NOT"; break;
      case 13: return "EQUALS"; break;
      case 14: return "NOTEQUALS"; break;
      case 15: return "LESS_EQUAL"; break;
      case 16: return "GREATER_EQUAL"; break;
      case 17: return "LESS_THAN"; break;
      case 18: return "GREATER_THAN"; break;
      case 19: return "CALL"; break;
      case 20: return "RET"; break;
      default: break;

   }
}

const char* getOperandType(enum p_code_operand_type type){

	switch (type) 
	   {
	      case REGISTER: return "REGISTER";
	      case CONSTANT: return "CONSTANT";
	      case IDENTIFIERS: return "IDENTIFIERS";
	      
	   }
} 

const char* getRegisterName(enum p_code_register reg){

	switch (reg) 
	   {
	      case PC: return "PC";
	      case SP: return "SP";
	      case BP: return "BP";
	      
	   }
} 



void yyerror(char *s){ fprintf(stderr, " %s\n", s); }


