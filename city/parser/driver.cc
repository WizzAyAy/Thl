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

void Driver::afficherDriver() const{
    std::cout << "Driver : \nrayon = " << _ville->rayon() << std::endl;
    std::cout << "nb instructions " << _lesInstructions.size() << std::endl;
}

void Driver::afficherLesMaisons() const
{
    for(auto x : _lesInstructions){
        auto i = dynamic_cast<maison>(x);
        if(i != nullptr)
            std::cout << *i << std::endl;
    }
}

