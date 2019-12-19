#include "driver.hh"
#include <iostream>

std::vector<instruction *> Driver::getLesInstructions() const
{
    return lesInstructions;
}

void Driver::ajoutInst(std::vector<std::unique_ptr<instruction>> inst){
    lesInstructions = inst;
}
