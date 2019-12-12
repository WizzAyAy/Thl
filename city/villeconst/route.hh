#pragma once
#include "maison.hh"
#include <instruction.hh>

class route : public instruction
{
private:
    maison _extremite1;
    maison _extremite2;
public:
    route(maison const & A,maison const & B);
    route (route const &R) =default;
    ~route () =default;
    instruction * clone() override;
    void exec() override;
};


