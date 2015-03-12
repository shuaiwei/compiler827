%{
#include <iostream>
#include <cstring>
#include <stdlib.h>     /* atof */

#include "ast.h"
#include "parse.tab.h"

int numberOfLines = 1;
%}
letter      [a-zA-Z]
ident       {letter}({letter}|{digit})*
digit       [0-9]
digits      [0-9]+

%%

"**"       { return EXPON; }
"="        { return ASSIGN; }
"+"        { return PLUS; }
"-"        { return MINUS; }
"*"        { return MULT; }
"/"        { return DIV; }
"%"        { return MOD; }
"("        { return LPAREN; }
")"        { return RPAREN; }
":"        { return COLON; }
","        { return COMMA; }
"<"        { return LESS; }
">"        { return GREAT; }
"<="       { return LESSEQ; }
">="       { return GREATEQ; }
"=="       { return EQ; }
"!="       { return NOTEQ; }
"if"       { return IF; }
"else"     { return ELSE; }
"def"      { return DEF; }
"print"    { return PRINT; }
"end"      { return END; }
"return"   { return RETURN; }
"main"     { return MAIN; }

{ident}    { return IDENT; }


{digits}   { 
			 yylval.d = atoi(yytext); //needed
             return NUMBER; 
           }
"#"[^\n]*  { ; }
"\n"       {  
			  ++numberOfLines; 
			  return CR; 
		   }
.          { ; }

%% //LCOV_EXCL_LINE
//LCOV_EXCL_LINE
int yywrap() {
  yylex_destroy();
  return 1;
}
