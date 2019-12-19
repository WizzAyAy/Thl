#pragma once
#include <iostream>
#include <memory>

class construction;
class instruction
{
public:
    instruction();
    instruction(instruction const & Q)=default;
    virtual void exec(construction & C) const {}
    virtual std::unique_ptr<instruction>clone() const=0;
};
