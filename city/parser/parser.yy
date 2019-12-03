%skeleton "lalr1.cc"
%require "3.0"

%defines
%define parser_class_name { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
    #include "contexte.hh"
    #include "expressionBinaire.hh"
    #include "expressionUnaire.hh"
    #include "constante.hh"
    #include "variable.hh"
    #include "construction.hh"
    #include "maison.hh"

    class Scanner;
    class Driver;
}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code{
    #include <iostream>
    #include <string>
    
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex
}

%token                  NL
%token                  END
%token                  CONSTRUIRE
%token                  MAISON
%token <int>            NUMBER
%token                  ROUTE


%type <construction*>             construction
%type <coordonnee>                coord
%type <maison*>                   maison
%type <maison*>                   element
%type <int>             operation
%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:
    instruction NL programme
    | END NL  {
        YYACCEPT;

    }

instruction:
    operation  {
        std::cout << "#-> " << $1 << std::endl;
    }
    |maison {

    }

    |route{

    }

    |coord {
         std::cout<<"je trouve des coord"<<std::endl;
    }

    |ville {
    }instruction



operation:
    NUMBER {
        $$ = $1;
    }
    | '(' operation ')' {
        $$ = $2;
    }
    | operation '+' operation {
        $$ = $1 + $3;
    }
    | operation '-' operation {
        $$ = $1 - $3;
    }
    | operation '*' operation {
        $$ = $1 * $3;
    }
    | operation '/' operation {
        $$ = $1 / $3;
    }
    | '-' operation %prec NEG {
        $$ = - $2;
    }

/*coordonne*/
 coord:
    '(' operation ',' operation ',' operation ')'   {
           coordonnee B={$2,$4,$6};
           $$ = B;
    }

/*partie construction c'est bon*/
construction:
    CONSTRUIRE '(' NUMBER ')'   {
        $$= new construction($3);

    }
    | CONSTRUIRE  {
       $$= new construction;
       }

/*ville */
ville:
    construction '{' NL element {
     $1->ajouteMaison($4);
    }

element:
    maison NL element {
        $$=$1;
    }
    | route NL element
    | '}' NL

route:
    ROUTE coord '-''>' coord NL {
        maison* m = new maison($2);
        maison* m2 = new maison($5);
        m->ajouteRoute(m2);
        m2->ajouteRoute(m);
    }

maison:
    MAISON {
        $$=new  maison ();
    }
    |MAISON coord {
        $$ =new maison ($2);
    }

%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
