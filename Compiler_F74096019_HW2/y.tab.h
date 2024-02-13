/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 142 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
