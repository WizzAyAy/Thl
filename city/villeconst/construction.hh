#pragma once
#include <array>
#include <vector>
#include "maison.hh"
int const NMAX(100);
using tab = std::array<bool,NMAX>;
using ensembleroute =std::array<tab,NMAX>;
class construction
{
private:
    unsigned int _rayon;
    std::vector<maison*> _maisonDeLaVille;
    ensembleroute _emsembleroute;
public:
    construction(int rayon);
    construction ();
    unsigned int rayon() const;
    void setRayon(unsigned int rayon);
    bool maisonExiste(coordonnee c);
    void ajouteMaison(maison *A);
    // maison *trouveMaison(coordonnee A);
   // void route(coordonnee A, coordonnee B);
    std::vector<maison *> maisonDeLaVille() const;
    void setMaisonDeLaVille(const std::vector<maison *> &maisonDeLaVille);
};

