#pragma once

#include <array>
#include <vector>
#include <memory>

#include "coordonnees.hh"
#include "instruction.hh"

class route;
class maison;
class instruction;

class construction
{
private:
    unsigned int _rayon;
    std::vector<std::unique_ptr<maison>> _maisonDeLaVille;
    std::vector<std::unique_ptr<route>> _routeDeLaVille;
public:
    construction(int rayon);
    construction ();

    unsigned int rayon() const;
    void setRayon(unsigned int rayon);
    std::vector<std::unique_ptr<maison>> maisonDeLaVille()const;

    bool maisonExiste(coordonnee c)const;

    void ajouteMaison(std::unique_ptr<maison> &A);
    void ajouteRoute(std::unique_ptr<route> R);

    void exec(const std::vector<std::unique_ptr<instruction> > &vect);
};

