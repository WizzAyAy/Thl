#include "construction.hh"
#include <iostream>

#include "maison.hh"
#include "route.hh"
#include "instruction.hh"

unsigned int construction::rayon() const
{

    return _rayon;
}
void construction::setRayon(unsigned int rayon)
{
    _rayon = rayon;


}
std::vector<maison *> construction::maisonDeLaVille() const
{
    return _maisonDeLaVille;
}
construction::construction(int rayon, std::vector<instruction *> lesInstruction):_rayon(rayon)
{
    std::cout<<"je construis avec un rayon de  "<< _rayon <<std::endl;
}
construction::construction():_rayon(3)
{
    std::cout<<"je construis avec un rayon de  "<< _rayon<<std::endl;

}
bool construction::maisonExiste(coordonnee c){
    for(auto n : _maisonDeLaVille){
        if (((n->coordMaison().X ==  c.X) and (n->coordMaison().Y ==  c.Y)) and (n->coordMaison().Z ==  c.Z)) return true;
    }
    return false;
}
void construction::ajouteMaison(maison* A) const{
   if((A->coordMaison().X ==0 && A->coordMaison().Y ==0 ) && (A->coordMaison().Z ==0)){
       coordonnee nouv;
       nouv.X = (rand() % _rayon) +1;
       nouv.Y = (rand() % _rayon) +1;
       nouv.Z = (rand() % _rayon) +1;
       A->setCoord(nouv);
   }
   _maisonDeLaVille.push_back(A);
}
void construction::ajouteInstruction(instruction *&inst){
    _instruction.push_back(inst->clone());
    std::cout<<"j'ai ajoute une instruction"<<std::endl;
}
void construction::ajouteRoute(route *R){
    _routeDeLaVille.push_back(R);
}
