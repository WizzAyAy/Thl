#include "maison.hh"
#include "construction.hh"


#include <iostream>
#include <cstdlib>



maison::maison(coordonnee A):instruction(),_coordMaison(A), _estAlea(false){}

maison::maison(): instruction(),_coordMaison({0,0,0}), _estAlea(true){}

std::shared_ptr<instruction> maison::clone() const{
    return std::make_shared<maison>(*this);
}

//std::unique_ptr<maison> maison::copie() const{
//    return std::make_unique<maison>(*this);
//}

