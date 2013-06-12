/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TK_PR_INTEIRO = 258,
     TK_PR_FLUTUANTE = 259,
     TK_PR_BOOLEANO = 260,
     TK_PR_CARACTERE = 261,
     TK_PR_CADEIA = 262,
     TK_PR_SE = 263,
     TK_PR_ENTAO = 264,
     TK_PR_SENAO = 265,
     TK_PR_ENQUANTO = 266,
     TK_PR_REALIZA = 267,
     TK_PR_ENTRADA = 268,
     TK_PR_SAIDA = 269,
     TK_PR_RETORNA = 270,
     TK_OC_LE = 271,
     TK_OC_GE = 272,
     TK_OC_EQ = 273,
     TK_OC_NE = 274,
     TK_OC_AND = 275,
     TK_OC_OR = 276,
     TK_LIT_INTEIRO = 277,
     TK_LIT_FLUTUANTE = 278,
     TK_LIT_FALSO = 279,
     TK_LIT_VERDADEIRO = 280,
     TK_LIT_CARACTERE = 281,
     TK_LIT_CADEIA = 282,
     TK_IDENTIFICADOR = 283,
     TOKEN_ERRO = 284
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 38 "/home/cuca/Downloads/compiladores/etapa5/src/parser/parser.y"

  Node* node;
  std::vector<Node*>* nodes;
  Common::DataType dataType;
  Symbol* symbol;



/* Line 2068 of yacc.c  */
#line 88 "/home/cuca/Downloads/compiladores/etapa5/src/parser/parser.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


