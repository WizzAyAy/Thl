#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

#include "maison.hh"
#include "route.hh"
#include "instruction.hh"
#include "construction.hh"



construction::construction(int rayon):_rayon(rayon){}
construction::construction():_rayon(3){}

std::shared_ptr<maison> construction::getMaisonI(int indice) const
{
    for (auto it =_maisonDeLaVille.begin();it != _maisonDeLaVille.end();++it){
                if ((*it)->getIndice() == indice) return (*it);
    }


}

std::shared_ptr<maison> construction::getMaisonCoo(coordonnee A) const
{

    for (auto house : _maisonDeLaVille){
        if((house->coordMaison().X == A.X && house->coordMaison().Y == A.Y) && house->coordMaison().Z == A.Z)
            return house;
    }

}

bool construction::maisonExiste(coordonnee c)const{
    for(auto const&n : _maisonDeLaVille){
        if (((n->coordMaison().X ==  c.X) and (n->coordMaison().Y ==  c.Y)) and (n->coordMaison().Z ==  c.Z)) return true;
    }
    return false;
}
void construction::ajouteMaison(std::shared_ptr<maison> A){
    if(A->getAlea()){
       coordonnee nouv;
       do
       {
       nouv.X = _rayon*(-1) + (int)((float)rand() * (_rayon-(_rayon*(-1))+1)/ (RAND_MAX-1));
       nouv.Y = _rayon*(-1) + (int)((float)rand() * (_rayon-(_rayon*(-1))+1)/ (RAND_MAX-1));
       nouv.Z = _rayon*(-1) + (int)((float)rand() * (_rayon-(_rayon*(-1))+1)/ (RAND_MAX-1));
       }while (nouv.X + nouv.Y + nouv.Z != 0);
       A->setCoord(nouv);

    }
   _maisonDeLaVille.push_back(A);
}

void construction::ajouteRoute(std::shared_ptr<route> R){
    _routeDeLaVille.push_back(R);
}

void construction::exec(const std::vector<std::shared_ptr<instruction> > &vect){
    for(auto x : vect){
        x->exec(*this);
    }
}

void construction::afficherVille() const
{
    for( auto & road : _routeDeLaVille){
        road->afficher(std::cout);
    }
    std::cout<<std::endl;
    for( auto & house : _maisonDeLaVille){
        house->afficher(std::cout);
    }
}


//void construction::exec(std::vector<std::unique_ptr<instruction>> const & vect){
//    for(auto const & i : vect){
//        auto element = dynamic_cast<std::unique_ptr<maison const*>
//    }
//}
