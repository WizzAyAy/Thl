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
    int _id;
    static int id;
    std::vector<maison*> _route;

public:
    maison(coordonnee A);
    maison();
    coordonnee coordMaison() const;
    void setId(int id);
    int getId() const{return _id;}
    void ajouteRoute (maison *A);
    //void exec(construction &c)override;
};


