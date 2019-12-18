#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <vector>
#include "instruction.hh"
#include "contexte.hh"
#include "construction.hh"

class Driver {
private:
    Contexte variables;       
    std::vector<instruction *> lesInstructions;
    std::vector<construction*> _ville;
public:
    Driver() = default;
    void ajoutInst(std::vector<instruction *> inst);
    ~Driver() = default;
    Driver(const Driver&) = default;
    std::vector<instruction *> getLesInstructions() const;
    void salut(){

        std::cout<<"Salut";
    }
    void seTville(construction * ville){
        _ville.push_back(ville);
    }
    std::vector<construction*> getVille(){
        return _ville;
    }
};

#endif
