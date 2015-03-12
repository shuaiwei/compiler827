/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     CR = 259,
     ASSIGN = 260,
     PRINT = 261,
     IDENT = 262,
     LPAREN = 263,
     RPAREN = 264,
     DEF = 265,
     COLON = 266,
     COMMA = 267,
     IF = 268,
     END = 269,
     ELSE = 270,
     RETURN = 271,
     MAIN = 272,
     NOTEQ = 273,
     EQ = 274,
     GREATEQ = 275,
     GREAT = 276,
     LESSEQ = 277,
     LESS = 278,
     MINUS = 279,
     PLUS = 280,
     MOD = 281,
     DIV = 282,
     MULT = 283,
     EXPON = 284,
     UMINUS = 285
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define CR 259
#define ASSIGN 260
#define PRINT 261
#define IDENT 262
#define LPAREN 263
#define RPAREN 264
#define DEF 265
#define COLON 266
#define COMMA 267
#define IF 268
#define END 269
#define ELSE 270
#define RETURN 271
#define MAIN 272
#define NOTEQ 273
#define EQ 274
#define GREATEQ 275
#define GREAT 276
#define LESSEQ 277
#define LESS 278
#define MINUS 279
#define PLUS 280
#define MOD 281
#define DIV 282
#define MULT 283
#define EXPON 284
#define UMINUS 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "parse.y"
{
  Ast* ast;
  double d;
}
/* Line 1529 of yacc.c.  */
#line 114 "parse.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

