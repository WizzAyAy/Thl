#pragma once
#include <iostream>


class instruction
{
public:
    instruction();
    instruction(instruction const & Q)=default;
    virtual void exec() =0;
    virtual instruction* clone() =0;
};
