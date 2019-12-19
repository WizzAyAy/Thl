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

    maison();
    maison(coordonnee A);
    maison(maison const & m)=default;

    std::shared_ptr<instruction> clone() const override;
    void exec(construction & C);

    coordonnee coordMaison() const{return _coordMaison;}
    void setCoord( coordonnee Q){_coordMaison = Q;}
    bool getAlea()const{return _estAlea;}
    void afficher(std::ostream &os)const override;

    bool operator ==(maison const & m);
};



