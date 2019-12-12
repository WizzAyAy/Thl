#pragma once
#include <vector>
#include <memory>
#include "instruction.hh"
#include "construction.hh"
struct coordonnee {
    int X;
    int Y;
    int Z;
};
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
    void exec() override;
};


