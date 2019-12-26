#pragma once
#include "instruction.hh"
#include "coordonnees.hh"
class maison;
class route : public instruction
{
private:
    coordonnee _extremite1;
    coordonnee _extremite2;
public:
    route(coordonnee A, coordonnee B);
    route (route const &R) =default;
    ~route () =default;

    std::shared_ptr<instruction> clone() const override;
    void afficher(std::ostream &os)const override;

    coordonnee getMaison1()const{return _extremite1;}
    coordonnee getMaison2()const{return _extremite2;}

    void exec(construction & C) override;
};


