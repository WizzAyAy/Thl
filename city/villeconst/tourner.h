#pragma once
#include "instruction.hh"
#include "coordonnees.hh"
class tourner  : public instruction
{
private:
    int _indice;
    coordonnee _coordonne;
    int _angle;
public:
    tourner(int ind,coordonnee C,int angle);

    void exec (construction &C) override;
    std::shared_ptr<instruction> clone()const override{return std::make_shared<tourner>(*this);}
    void afficher(std::ostream & os)const override{}
};

