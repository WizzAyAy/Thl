#pragma once
#include <vector>
#include <memory>
#include "instruction.hh"
#include "coordonnees.hh"

class maison : public instruction
{
private:
    coordonnee _coordMaison;
    std::vector<maison* > _route;

public:
    maison(coordonnee A);
    maison();
    maison(maison const & Q) =default;
    ~maison() = default;
    coordonnee coordMaison() const;
    void ajouteRoute (maison* A);
    instruction * clone() override;
    void exec(construction const & C) const override;
    void setCoord( coordonnee Q){
        _coordMaison = Q;
    }
};


