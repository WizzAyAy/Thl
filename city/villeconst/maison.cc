#include "maison.hh"
#include "construction.hh"


#include <iostream>
#include <cstdlib>



maison::maison(coordonnee A):instruction(),_coordMaison(A), _estAlea(false){}

maison::maison(): instruction(),_coordMaison({0,0,0}), _estAlea(true){}

std::shared_ptr<instruction> maison::clone() const{
    return std::make_shared<maison>(*this);
}

void maison::exec(construction &C){
   C.ajouteMaison(std::make_shared<maison>(*this));
}

void maison::afficher(std::ostream &os) const
{
    os << "maison (" << coordMaison().X << "," << coordMaison().Y << "," << coordMaison().Z << ") [" << getAlea() << "].";
}

bool maison::operator ==(const maison &m){
    return (m.coordMaison().X == coordMaison().X && m.coordMaison().Y == coordMaison().Y && m.coordMaison().Z == coordMaison().Z);
}

//std::unique_ptr<maison> maison::copie() const{
//    return std::make_unique<maison>(*this);
//}

