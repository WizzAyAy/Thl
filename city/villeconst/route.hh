#pragma once
#include "instruction.hh"

class maison;
class route : public instruction
{
private:
    maison* _extremite1;
    maison* _extremite2;
public:
    route(maison *A, maison *B);
    route (route const &R) =default;
    ~route () =default;
    instruction * clone() override;
    void exec(construction const & C) const override;
};


