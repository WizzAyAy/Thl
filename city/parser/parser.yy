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
    #include "touroriente.hh"

    class Scanner;
    class Driver;
}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code{
    #include <iostream>
    #include <string>
    #include <memory>
    #include <vector>
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
%token                  HORRAIRE
%token                  TOURNER

%type <std::shared_ptr<construction>>             construction
%type <coordonnee>                coord
%type <std::shared_ptr<maison>>   maison
%type <std::shared_ptr<route>>    route
%type <int>                       operation
%type <std::vector<std::shared_ptr<instruction>>>  element
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
        $$= std::make_shared<construction>($3);

        driver.setInstructions($7);
        driver.setVille ($$);
        YYACCEPT;
    }
    | CONSTRUIRE '{' NL element  {
       $$= std::make_shared<construction>(5);

        driver.setInstructions($4);
        driver.setVille ($$);
        YYACCEPT;
    }



/*partie maison okies*/
element:

        MAISON NL element  {
           std::shared_ptr<maison> tmp = std::make_shared<maison>();
           $$ =$3;
           $$.push_back(tmp);

          }
        |MAISON coord NL element {
            std::shared_ptr<maison> tmp = std::make_unique<maison>($2);
            $$ =$4;
            $$.push_back(tmp);
        }
         |ROUTE coord '-''>' coord NL element {

             std::shared_ptr<maison> M1 = std::make_shared<maison>($2);
             std::shared_ptr<maison> M2 = std::make_shared<maison>($5);
             std::shared_ptr<route> tmp = std::make_shared<route>(M1,M2);
             $$=$7;
             $$.push_back(tmp);

         }
        | TOURNER NUMBER  HORRAIRE NL element {

            std::shared_ptr<tourOriente> t = std::make_shared<tourOriente>();
        }
         | '}' NL



%%


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
