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
    #include <memory>

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
%type <route*>                    route
%type <int>                       operation
%type <instruction*>               element
%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:
    instructions NL programme
    | END NL  {
        YYACCEPT;

    }

instructions:
    operation  {
        std::cout << "#-> " << $1 << std::endl;
    }
    |ville {
    }instructions



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
/*partie maison okies*/
maison:
    MAISON {
        $$= new maison();
    }
    |MAISON coord {
        $$ =new maison($2);
    }
/*partie construction c'est bon*/
construction:
    CONSTRUIRE '(' NUMBER ')'   {
        $$= new construction($3);

    }
    | CONSTRUIRE  {
       $$= new construction();
       }

/*route*/
route:
    ROUTE coord '-''>' coord {

        maison M1($2);
        maison M2($5);
        $$ = new route(M1,M2);

    }
element:
     maison NL element {
         $$=$1;
      }
     | route NL element{
        $$=$1;
     }
     | '}' NL

/*ville */
ville:
    construction '{' NL element {
       $1->ajouteInstruction($4);
    }
%%


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
