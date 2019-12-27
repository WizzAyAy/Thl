#pragma once
#include "coordonnees.hh"
#include "instruction.hh"
class Deplace : public instruction
{

public:
    Deplace(int ind,coordonnee A,coordonnee B): instruction(),_indice(ind),_nouvelleCoordonne(A),_anciennecoordonnee(B){}
    void exec (construction &C) override;
    std::shared_ptr<instruction> clone()const override{return std::make_shared<Deplace>(*this);}
    void afficher(std::ostream & os)const override{}

private:
    int _indice; //indice de la maison a detruire
    coordonnee _nouvelleCoordonne;
    coordonnee _anciennecoordonnee;

};
