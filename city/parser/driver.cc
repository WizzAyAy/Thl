#include "driver.hh"
#include "construction.hh"
#include "maison.hh"
#include "route.hh"

#include <iostream>
#include <memory>

class maison;
Driver::Driver(){V = new VilleGUI();}
void Driver::setInstructions(std::vector<std::shared_ptr<instruction> > &inst){
    for(auto const & x : inst){
        _lesInstructions.push_back(x->clone());
    }
}

void Driver::setVille(std::shared_ptr<construction> ville){
    _ville = ville;
}

void Driver::exec()
{
    for(auto x : _lesInstructions){
        x->exec(*_ville);
    }
}

void Driver::afficherDriver() const{
    std::cout << "Driver : \nrayon = " << _ville->rayon() << std::endl;
    std::cout << "nb instructions " << _lesInstructions.size() << std::endl;
    std::cout << "avec les instructions : " << std::endl;
    for(auto& x : _lesInstructions){
        x->afficher(std::cout);
        std::cout << std::endl;
    }
}

void Driver::afficherVille() const
{
//    std::cout << "Affichage de la ville : " << std::endl;
//    for(auto x : _ville->maisonDeLaVille()){
//        std::cout << "a" << std::endl;
    //    }
}

void Driver::construireVille() const
{
   V->setRayon(_ville->rayon());
    std::cout << "on ajoute les maison dans l'ig\n";
    std::cout << _ville->maisonDeLaVille().size() << std::endl;
    for (auto & house : _ville->maisonDeLaVille()){
        V->construireMaison(house->coordMaison().X,house->coordMaison().Y,house->coordMaison().Z);
   }
    for (auto & road : _ville->routeDeLaVille()){
        V->construireRoute(road->getMaison1()->coordMaison().X,
                           road->getMaison1()->coordMaison().Y,
                           road->getMaison1()->coordMaison().Z,
                           road->getMaison2()->coordMaison().X,
                           road->getMaison2()->coordMaison().Y,
                           road->getMaison2()->coordMaison().Z);
   }
}

