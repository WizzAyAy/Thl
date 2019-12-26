#pragma once
#include <iostream>
#include <memory>

class construction;
class instruction
{
public:
    instruction()=default;
    instruction(instruction const & Q)=default;

    virtual void exec(construction & C)= 0;
    virtual std::shared_ptr<instruction>clone() const=0;

    virtual void afficher(std::ostream &os)const=0;
};
