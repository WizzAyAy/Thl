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
    #include "route.hh"
    #include "instruction.hh"

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
%type <std::vector<instruction*>>               element
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
    |construction {
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
/*partie construction c'est bon*/
construction:
    CONSTRUIRE '(' NUMBER ')' '{' NL element   {
        $$= new construction($3,$7);

        driver.ajoutInst($7);
        driver.seTville ($$);
        YYACCEPT;
    }
    | CONSTRUIRE '{' NL element  {
       $$= new construction(5,$4);
        driver.ajoutInst($4);
        driver.seTville ($$);
        YYACCEPT;
    }



/*partie maison okies*/
element:

        MAISON NL element  {
           maison * tmp = new maison();
           $$ =$3;
           $$.push_back(tmp);

          }
        |MAISON coord NL element {
            maison * tmp = new maison($2);
            $$ =$4;
            $$.push_back(tmp);
        }
         |ROUTE coord '-''>' coord NL element {

             maison* M1= new maison($2);
             maison* M2= new maison($5);
             route * tmp = new route(M1,M2);
             $$=$7;
             $$.push_back(tmp);

         }
         | '}' NL   {

         }



%%


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
