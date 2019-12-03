#pragma once
#include <array>
#include <vector>
#include "maison.hh"
class construction
{
private:
    unsigned int _rayon;
    std::vector<maison*> _maisonDeLaVille;

public:
    construction(int rayon);
    construction ();
    unsigned int rayon() const;
    void setRayon(unsigned int rayon);
    bool maisonExiste(coordonnee c);
    void ajouteMaison(maison *A);
    maison *trouveMaison(coordonnee A);
    void route(coordonnee A, coordonnee B);
    std::vector<maison *> maisonDeLaVille() const;
    void setMaisonDeLaVille(const std::vector<maison *> &maisonDeLaVille);
};

