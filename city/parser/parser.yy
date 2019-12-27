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
    #include "detruiredeplace.hh"
    #include "tourner.h"

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
%token                  HORAIRE
%token                  TOURNER
%token                  DEPLACER
%token                  ORIENTER

%type <std::shared_ptr<construction>>             construction
%type <coordonnee>                coord
%type <std::shared_ptr<maison>>   maison
%type <std::shared_ptr<route>>    route
%type <int>                       operation
%type <std::vector<std::shared_ptr<instruction>>>  element
%type <bool>                      horaire
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
    CONSTRUIRE '(' NUMBER ')' '{' NL element {
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

/*horaire*/
horaire:
    HORAIRE {
        $$ =true;
    }
    | '!' HORAIRE {
        $$= false;
    }
/*partie maison okies*/
element:

        MAISON NL element  {
           std::shared_ptr<maison> tmp = std::make_unique<maison>();
           $$=$3;
           $$.push_back(tmp);

          }
        |MAISON coord NL element {
            std::shared_ptr<maison> tmp = std::make_shared<maison>($2);
            $$ =$4;
            $$.push_back(tmp);
        }
         |ROUTE coord '-''>' coord NL element {

             std::shared_ptr<route> tmp = std::make_shared<route>($2,$5);
             $$=$7;
             $$.push_back(tmp);

         }
        | TOURNER NUMBER horaire NL element {
               $$ = $5;
              if ($3 == true){
               coordonnee B={0,0,0};
               std::shared_ptr<tourner> tmp = std::make_shared<tourner>($2,B,90);
               $$.push_back(tmp);
              }
              else{
                  coordonnee B={0,0,0};
                  std::shared_ptr<tourner> tmp = std::make_shared<tourner>($2,B,-90);
                  $$.push_back(tmp);
              }
        }
        | TOURNER coord horaire NL element {
               $$ = $5;
              if ($3 == true){

               std::shared_ptr<tourner> tmp = std::make_shared<tourner>(0,$2,90);
               $$.push_back(tmp);
              }
              else{

                  std::shared_ptr<tourner> tmp = std::make_shared<tourner>(0,$2,-90);
                  $$.push_back(tmp);
              }
        }

        | ORIENTER NUMBER NUMBER element{
            $$ = $4;
            std::shared_ptr<tourOriente> tmp = std::make_shared<tourOriente>($2,$3,false);
            $$.push_back(tmp);
        }

        | ORIENTER coord NUMBER element{
            $$ = $4;
            std::shared_ptr<tourOriente> tmp = std::make_shared<tourOriente>(0,$3,true); //0 donc l'indice n'a pas ete donne
            tmp->setCoordonnee($2);
            $$.push_back(tmp);
        }
        /* deplacement */
        | DEPLACER NUMBER '-''>' coord element{
                $$ = $6;
               coordonnee tmpCoord = {0,0,0};//si c'est l'indice qui est donne, on initialise l'ancienne coordonene a 0,0,0
               std::shared_ptr<Deplace> tmp = std::make_shared<Deplace>($2,tmpCoord,$5);
               $$.push_back(tmp);

        }
        | DEPLACER coord '-''>' coord element{
                $$ = $6;
                 std::shared_ptr<Deplace> tmp = std::make_shared<Deplace>(0,$2,$5);
                 $$.push_back(tmp);
        }
        | '}' NL



%%


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
