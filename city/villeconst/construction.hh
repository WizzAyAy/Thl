#pragma once
#include <array>
#include <vector>
#include "maison.hh"
#include "route.hh"
#include "instruction.hh"
int const NMAX(100);
using tab = std::array<bool,NMAX>;
using ensembleroute =std::array<tab,NMAX>;
class construction
{
private:
    unsigned int _rayon;
    std::vector<maison*> _maisonDeLaVille;
    std::vector<route*> _routeDeLaVille;
    std::vector<instruction*> _instruction; //vecteur d'instruction a excecuter a la fin du parser
public:
    construction(int rayon);
    construction ();
    unsigned int rayon() const;
    void setRayon(unsigned int rayon);
    bool maisonExiste(coordonnee c);
    void ajouteMaison(maison* A);
    void ajouteInstruction(instruction* & inst);
    std::vector<maison *> maisonDeLaVille() const;
};

