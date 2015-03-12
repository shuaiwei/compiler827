%{
#include <iostream>
#include <map>

extern int yylex();
extern int numberOfLines;
  void yyerror(const char * msg);
%}

%token CR
%token ASSIGN
%token PRINT
%token IDENT 
%token NUMBER
%token FLOAT
%token LPAREN
%token RPAREN
%token DEF
%token COLON
%token COMMA
%token IF
%token END
%token ELSE
%token RETURN

%left  LESS LESSEQ GREAT GREATEQ EQ NOTEQ
%left  PLUS MINUS
%left  MULT DIV MOD
%left  EXPON

%%

start   : start funcdef {$$ = 0;}
        | {$$ = 0;}
        ;

funcdef : DEF IDENT LPAREN opt_id_list RPAREN COLON stmt END{$$ = 0;}
        | CR {$$ = 0;}
        ;

opt_id_list : id_list{$$ = 0;}
            |{$$ = 0;}
            ;

id_list : IDENT COMMA id_list{$$ = 0;}
        | IDENT {$$ = 0;}
        ;

opt_parm_list : parm_list {$$ = 0;}
              ;

parm_list 
        : expr COMMA parm_list {$$ = 0;}
        | expr {$$ = 0;}
        |{$$ = 0;}
        ;

stmt    : line CR stmt {$$ = 0;}
        | selection CR stmt {$$ = 0;}
        | CR stmt {$$ = 0;}
        |{$$ = 0;}
        ;

selection 
        : IF expr COLON stmt ELSE END {$$ = 0;}
        | IF expr COLON stmt ELSE COLON stmt END {$$ = 0;}
        ;

line    : IDENT ASSIGN expr {$$ = 0;}
        | IDENT LPAREN opt_parm_list RPAREN {$$ = 0;}
        | PRINT expr {$$ = 0;}
        | RETURN expr{$$ = 0;}
        ;

expr    : expr PLUS expr {$$ = 0;}
        | expr MINUS expr{$$ = 0;}
        | expr MULT expr{$$ = 0;}
        | expr EXPON expr{$$ = 0;}
        | expr DIV expr{$$ = 0;}
        | expr MOD expr{$$ = 0;}
        | expr LESS expr{$$ = 0;}
        | expr LESSEQ expr{$$ = 0;}
        | expr GREAT expr{$$ = 0;}
        | expr GREATEQ expr{$$ = 0;}
        | expr NOTEQ expr{$$ = 0;}
        | expr EQ expr{$$ = 0;}
        | MINUS expr{$$ = 0;}
        | NUMBER{$$ = 0;}
        | FLOAT{$$ = 0;}
        | IDENT{$$ = 0;}
        | IDENT LPAREN opt_parm_list RPAREN{$$ = 0;}
        | LPAREN expr RPAREN{$$ = 0;}
        ;

%%
void yyerror(const char * msg) { 
  std::cout << msg << " at line " << numberOfLines << std::endl; 
}