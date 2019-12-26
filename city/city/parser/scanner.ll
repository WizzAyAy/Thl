%{

#include "scanner.hh"
#include <cstdlib>

#define YY_NO_UNISTD_H

using token = yy::Parser::token;

#undef  YY_DECL
#define YY_DECL int Scanner::yylex( yy::Parser::semantic_type * const lval, yy::Parser::location_type *loc )

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option c++
%option yyclass="Scanner"
%option noyywrap

%%
%{
    yylval = lval;
%}
fin return token::END;

"+" return '+';
"*" return '*';
"-" return '-';
"/" return '/';
"(" return '(';
")" return ')';
"=" return '=';
"{" return '{';
"}" return '}';
"," return ',';
"-" return '-';
">" return '>';
"!" return '!';
[0-9]+      {
    yylval->build<int>(std::atoi(YYText()));
    return token::NUMBER;
}
    "construire"   {
        return token::CONSTRUIRE;
    }
    "co"   {
        return token::CONSTRUIRE;
    }
    "maison"    {
        return token::MAISON;
    }
    "m" {
        return token::MAISON;
    }
    "route"    {
        return token::ROUTE;
    }
    "horaire" {
        return token::HORAIRE;
    }
    "tourner" {
        return token::TOURNER;
    }
    "orienter"  {
    return token::ORIENTER;
    }
    "detruire"  {
    return token::DEPLACER;
    }
    "\n"          {
    loc->lines();
    return token::NL;
}

%%
