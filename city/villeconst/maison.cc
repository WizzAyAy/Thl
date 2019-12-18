#include "maison.hh"
#include <iostream>
#include <cstdlib>
#include "construction.hh"
coordonnee maison::coordMaison() const
{
    return _coordMaison;
}

maison::maison(coordonnee A):instruction(),_coordMaison(A)
{
    std::cout<<" je construis à la position ("<<_coordMaison.X<<","<<_coordMaison.Y<<","<<_coordMaison.Z<<")"<<std::endl;
}

maison::maison(): instruction(){
   _coordMaison ={0,0,0};
    std::cout<<" je construis à la position ("<<_coordMaison.X<<","<<_coordMaison.Y<<","<<_coordMaison.Z<<")"<<std::endl;
}
void maison::ajouteRoute(maison* A){
    _route.push_back(A);
}

instruction * maison::clone(){
    return new maison(*this);
}
void maison::exec(construction const &C) const{
    C.ajouteMaison(*this);
}
