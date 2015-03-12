//  Source code for "flex & bison", by John Levine
//  Declarations for an AST calculator fb3-1
//  Adapted by Brian Malloy
%{
#include <iostream>
#include "ast.h"
  int id = 0; 
  extern int yylex();
  void yyerror(const char *s) { std::cout << s << std::endl; }
  void yyerror(const char *s, const char ch) {
    std::cout << s << ch << std::endl;
  }
%}

%union {
  Ast* ast;
  double d;
}


%left '+' '-'
%left '*' '/'
%left POW
%nonassoc UMINUS

%token <d> NUMBER
%token EOL
%type <ast> exp 

%%

calclist 
       : calclist exp EOL {
           std::cout << "= " << eval($2) << std::endl;
           makeGraph($2);
           treeFree($2);
           std::cout << "> ";
         }
       | calclist EOL // blank line or a comment
       | // empty
       ;

exp    : exp '+' exp { $$ = new AstNode('+', ++id, $1,$3); }
       | exp '-' exp { $$ = new AstNode('-', ++id, $1,$3); }
       | exp '*' exp { $$ = new AstNode('*', ++id, $1,$3); }
       | exp '/' exp { $$ = new AstNode('/', ++id, $1,$3); }
       | exp POW exp { $$ = new AstNode('^', ++id, $1,$3); }
       | '(' exp ')' { $$ = $2; }
       | '-' exp %prec UMINUS   { $$ = new AstNode('M', ++id, $2, NULL); }
       | NUMBER   { $$ = new AstNumber('K', ++id, $1); }
       ;
%%
