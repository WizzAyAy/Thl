#include "driver.hh"
#include <iostream>

std::vector<instruction *> Driver::getLesInstructions() const
{
    return lesInstructions;
}

void Driver::ajoutInst(std::vector<instruction *> inst){
    lesInstructions = inst;
}
