#pragma once
#include <iostream>

class construction;
class instruction
{
public:
    instruction();
    instruction(instruction const & Q)=default;
    virtual void exec(construction const & C) const =0;
    virtual instruction* clone() =0;
};
