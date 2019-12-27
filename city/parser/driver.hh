#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <vector>

#include "../IG/villeGUI.hh"
#include "instruction.hh"
#include "contexte.hh"
#include "construction.hh"

class Driver {
private:
    Contexte variables;       
    std::vector<std::shared_ptr<instruction>> _lesInstructions;
    std::vector<std::shared_ptr<instruction>> _lesInstructionsDeGestion;
    std::shared_ptr<construction> _ville;
    VilleGUI* V;
public:
    Driver();
    ~Driver() = default;
    Driver(const Driver&) = default;

    void setInstructions(std::vector<std::shared_ptr<instruction>> &inst);
    void setVille(std::shared_ptr<construction> ville);

    std::shared_ptr<construction> getVille() const{return _ville;}
    VilleGUI * getville(){return V;}
    std::vector<std::shared_ptr<instruction>> getGestion() {return _lesInstructionsDeGestion;}

    void exec();

    void afficherDriver()const;
    void afficherVille()const;

    void construireVille() const;
};

#endif
