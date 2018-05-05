/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 4 "parser.y" /* yacc.c:1909  */

#include <stdbool.h>

#line 48 "parser.h" /* yacc.c:1909  */

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
#line 33 "parser.y" /* yacc.c:1909  */

    bool bval;
    int ival;
    double fval;
    char *str;

#line 150 "parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
