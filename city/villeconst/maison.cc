#include "maison.hh"
#include "construction.hh"


#include <iostream>
#include <cstdlib>



maison::maison(coordonnee A):instruction(),_coordMaison(A), _estAlea(false)
{
    std::cout<<" je construis à la position ("<<_coordMaison.X<<","<<_coordMaison.Y<<","<<_coordMaison.Z<<")"<<std::endl;
}

maison::maison(): instruction(), _estAlea(true){
   _coordMaison ={0,0,0};
    std::cout<<" je construis à la position ("<<_coordMaison.X<<","<<_coordMaison.Y<<","<<_coordMaison.Z<<")"<<std::endl;
}

std::unique_ptr<instruction> maison::clone() const{
    return std::make_unique<maison>(*this);
}

std::unique_ptr<maison> maison::copie() const{
    return std::make_unique<maison>(*this);
}

