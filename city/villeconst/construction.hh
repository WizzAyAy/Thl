#pragma once
#include <array>
#include <vector>
#include "coordonnees.hh"

int const NMAX(100);
using tab = std::array<bool,NMAX>;
using ensembleroute =std::array<tab,NMAX>;

class route;
class maison;
class instruction;

class construction
{
private:
    unsigned int _rayon;
    std::vector<maison*> _maisonDeLaVille;
    std::vector<route*> _routeDeLaVille;
    std::vector<instruction*> _instruction; //vecteur d'instruction a excecuter a la fin du parser
public:
    construction(int rayon,std::vector <instruction *> lesInstruction);
    construction ();
    unsigned int rayon() const;
    void setRayon(unsigned int rayon);
    bool maisonExiste(coordonnee c);
    void ajouteMaison(maison* A) const;
    void ajouteInstruction(instruction* & inst);
    void ajouteRoute(route * R);
    std::vector<maison*> maisonDeLaVille() const;
};

