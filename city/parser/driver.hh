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
    std::vector<std::shared_ptr<instruction>> _lesInstructions;
    std::shared_ptr<construction> _ville;
public:
    Driver() = default;
    ~Driver() = default;
    Driver(const Driver&) = default;

    void setInstructions(std::vector<std::shared_ptr<instruction>> &inst);
    void setVille(std::shared_ptr<construction> ville);

    std::shared_ptr<construction> getVille() const{return _ville;}

    void afficherDriver()const;
    void afficherLesMaisons()const;
};

#endif
