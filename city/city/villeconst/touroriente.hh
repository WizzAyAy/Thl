#pragma once

#include "instruction.hh"
#include "construction.hh"

class tourOriente : public instruction
{
public:
    tourOriente(int const & indice, int const & angle, bool const & coor);


    void exec(construction &C);
    void afficher(std::ostream & os)const{}
    std::shared_ptr<instruction> clone()const{return std::make_shared<tourOriente>(*this);}

    void setCoordonnee(coordonnee A){_coordonnee =A;}

private:
    int _indice;
    int _angle;
    bool Acoordonnee; //faux si c'est l'indice qui a ete donnee et oui si les coordonnees
    coordonnee _coordonnee;
};

