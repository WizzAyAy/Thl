#include "construction.hh"
#include <iostream>

#include "maison.hh"
#include "route.hh"
#include "instruction.hh"

unsigned int construction::rayon() const{

    return _rayon;
}
void construction::setRayon(unsigned int rayon){
    _rayon = rayon;

}
std::vector<std::unique_ptr<maison>> construction::maisonDeLaVille() const{
    std::vector<std::unique_ptr<maison>> temp;
    for(auto const & x : _maisonDeLaVille){
        temp.push_back(x->copie());
    }
    return temp;
}
construction::construction(int rayon):_rayon(rayon){
    std::cout<<"je construis avec un rayon de  "<< _rayon <<std::endl;
}
construction::construction():_rayon(3){
    std::cout<<"je construis avec un rayon de  "<< _rayon<<std::endl;

}
bool construction::maisonExiste(coordonnee c)const{
    for(auto const&n : _maisonDeLaVille){
        if (((n->coordMaison().X ==  c.X) and (n->coordMaison().Y ==  c.Y)) and (n->coordMaison().Z ==  c.Z)) return true;
    }
    return false;
}
void construction::ajouteMaison(std::unique_ptr<maison> &A){
    if(A->getAlea()){
       coordonnee nouv;
       //c'est soit neg soit pos donc pas full random ...
       int fois = rand()%2;
       if (fois == 1){
           nouv.X = (rand() % _rayon) +1;
           nouv.Y = (rand() % _rayon) +1;
           nouv.Z = (rand() % _rayon) +1;
           }
       else {
           nouv.X = ((rand() % _rayon) +1)*-1;
           nouv.Y = ((rand() % _rayon) +1)*-1;
           nouv.Z = ((rand() % _rayon) +1)*-1;
       }
       A->setCoord(nouv);
   }
   _maisonDeLaVille.push_back(std::move(A));
}

void construction::ajouteRoute(std::unique_ptr<route> R){
    _routeDeLaVille.push_back(std::move(R));
}

//void construction::exec(std::vector<std::unique_ptr<instruction>> const & vect){
//    for(auto const & i : vect){
//        auto element = dynamic_cast<std::unique_ptr<maison const*>
//    }
//}
