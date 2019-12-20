#pragma once

#include "instruction.hh"
#include "construction.hh"

class tourOriente : public instruction
{
public:
    tourOriente(int const & indice, int const & angle, bool const & tourner);

    void exec(construction &C);
    void afficher(std::ostream & os)const{}
    std::shared_ptr<instruction> clone()const{return std::make_shared<tourOriente>(*this);}

private:
    int _indice;
    int _angle;
    //si true alors on tourne si false alors on oriente
    bool _tourner;
};

