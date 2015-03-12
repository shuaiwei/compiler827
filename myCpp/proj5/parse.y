%{
#include <iostream>
#include "ast.h"
#include <map>
    int id = 0; 
    extern int yylex();
    extern int numberOfLines;
    void yyerror(const char * msg);
%}



%union {
  Ast* ast;
  double d;
}

%type <ast> expr 

%token <d> NUMBER

%token CR
%token ASSIGN
%token PRINT
%token IDENT 
%token LPAREN
%token RPAREN
%token DEF
%token COLON
%token COMMA
%token IF
%token END
%token ELSE
%token RETURN
%token MAIN

%left  LESS LESSEQ GREAT GREATEQ EQ NOTEQ
%left  PLUS MINUS
%left  MULT DIV MOD
%left  EXPON

%nonassoc UMINUS

%%

start   : start funcdef {;}
        | {;}
        ;

funcdef : DEF MAIN LPAREN RPAREN COLON stmt END {;}
        | CR {;}
        ;

stmt    : line CR stmt {;}
        | selection CR stmt {;}
        | CR stmt {;}
        |{;}
        ;

selection 
        : IF expr COLON stmt ELSE END {;}
        | IF expr COLON stmt ELSE COLON stmt END {;}
        ;

line    : IDENT ASSIGN expr
        | IDENT LPAREN RPAREN {;}
        | PRINT expr { std::cout << eval($2) << std::endl;}
        | RETURN expr{;}
        ;

expr    : expr PLUS expr 
            {$$ = new AstNode('+', ++id, $1,$3);}
        | expr MINUS expr
            {$$ = new AstNode('-', ++id, $1,$3);}
        | expr MULT expr
            {$$ = new AstNode('*', ++id, $1,$3);}
        | expr EXPON expr
            {$$ = new AstNode('^', ++id, $1,$3);}
        | expr DIV expr
            {$$ = new AstNode('/', ++id, $1,$3);}
        | expr MOD expr
            {$$ = new AstNode('%', ++id, $1,$3);}
        | expr LESS expr
            {$$ = new AstNode('1', ++id, $1,$3);}
        | expr LESSEQ expr
            {$$ = new AstNode('2', ++id, $1,$3);}
        | expr GREAT expr
            {$$ = new AstNode('3', ++id, $1,$3);}
        | expr GREATEQ expr
            {$$ = new AstNode('4', ++id, $1,$3);}
        | expr NOTEQ expr
            {$$ = new AstNode('5', ++id, $1,$3);}
        | expr EQ expr
            {$$ = new AstNode('6', ++id, $1,$3);}
        | MINUS expr %prec UMINUS   
            { $$ = new AstNode('M', ++id, $2, NULL); }
        | NUMBER
            { $$ = new AstNumber('K', ++id, $1); }
        | IDENT{;}
        | LPAREN expr RPAREN
            { $$ = $2; }
        ;

%%
void yyerror(const char * msg) { 
  std::cout << msg << " at line " << numberOfLines << std::endl; 
}