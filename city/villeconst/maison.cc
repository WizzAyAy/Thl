#include "maison.hh"
#include <iostream>
#include <cstdlib>
#include "construction.hh"

int maison::id =0;
coordonnee maison::coordMaison() const
{
    return _coordMaison;
}

void maison::setId(int id)
{
    _id = id;
}

maison::maison(coordonnee A):_coordMaison(A)
{
    std::cout<<" je construis à la position ("<<_coordMaison.X<<","<<_coordMaison.Y<<","<<_coordMaison.Z<<")"<<std::endl;
}

maison::maison(){
   _coordMaison ={0,0,0};
    std::cout<<" je construis à la position ("<<_coordMaison.X<<","<<_coordMaison.Y<<","<<_coordMaison.Z<<")"<<std::endl;
}
void maison::ajouteRoute(maison * A){
    _route.push_back(A);
}
