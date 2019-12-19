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

    std::unique_ptr<instruction> clone() const override;
};


