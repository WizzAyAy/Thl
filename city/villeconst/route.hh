#pragma once
#include "instruction.hh"

class maison;
class route : public instruction
{
private:
    std::shared_ptr<maison> _extremite1;
    std::shared_ptr<maison> _extremite2;
public:
    route(std::shared_ptr<maison> const &A, std::shared_ptr<maison> const &B);
    route (route const &R) =default;
    ~route () =default;

    std::shared_ptr<instruction> clone() const override;
    void afficher(std::ostream &os)const override;

    void exec(construction & C) override;
};


