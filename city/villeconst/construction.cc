#include "construction.hh"
#include <iostream>
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
construction::construction(int rayon):_rayon(rayon)
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
void construction::ajouteMaison(maison* A){
    std::cout<<"j'ai ajouté une maison"<<std::endl;
    _maisonDeLaVille.push_back(A);
}
void construction::ajouteInstruction(instruction *&inst){
    _instruction.push_back(inst->clone());
    std::cout<<"j'ai ajoute une instruction"<<std::endl;
}
