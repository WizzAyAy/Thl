#pragma once
#include "instruction.hh"
#include "coordonnees.hh"

class detruire : public instruction
{

public:
    detruire(int indice, coordonnee coord);
    void exec (construction &C) override;
    std::shared_ptr<instruction> clone() const override {return std::make_shared<detruire>(*this);}
    void afficher(std::ostream &os) const override{}

private :
     int _indice;
     coordonnee _coordonnee;
};


