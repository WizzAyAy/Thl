#include "driver.hh"
#include "construction.hh"

#include <iostream>
#include <memory>

class maison;

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

