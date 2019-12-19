#pragma once
#include <vector>
#include <memory>
#include "instruction.hh"
#include "coordonnees.hh"

class maison : public instruction
{
private:
    coordonnee _coordMaison;
    bool _estAlea;

public:
    maison(coordonnee A);
    maison();

    std::unique_ptr<instruction> clone() const override;
    std::unique_ptr<maison> copie()const;

    coordonnee coordMaison() const{return _coordMaison;}
    void setCoord( coordonnee Q){_coordMaison = Q;}
    bool getAlea()const{return _estAlea;}
};



