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
    std::vector<std::unique_ptr<instruction>> lesInstructions;
    std::unique_ptr<construction> _ville;
public:
    Driver() = default;
    void ajoutInst(std::vector<std::unique_ptr<instruction>> inst);
    ~Driver() = default;
    Driver(const Driver&) = default;
    std::vector<std::unique_ptr<instruction>> getLesInstructions() const;

    void seTville(std::unique_ptr<construction> ville){_ville = std::move(ville);}
    std::unique_ptr<construction> getVille(){return _ville;}
};

#endif
