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
    std::vector<std::shared_ptr<maison>> _maisonDeLaVille;
    std::vector<std::shared_ptr<route>> _routeDeLaVille;
public:
    construction(int rayon);
    construction ();

    unsigned int rayon() const{return _rayon;}
    void setRayon(unsigned int rayon){_rayon = rayon;}
    std::vector<std::shared_ptr<maison>> maisonDeLaVille()const{return _maisonDeLaVille;}
    std::vector<std::shared_ptr<route>>  routeDeLaVille()const{return _routeDeLaVille;}
    std::shared_ptr<maison> getMaisonI(int indice)const;
    std::shared_ptr<maison> getMaisonCoo(coordonnee A)const;


    bool maisonExiste(coordonnee c)const;

    void ajouteMaison(std::shared_ptr<maison> A);
    void ajouteRoute(std::shared_ptr<route> R);

    void exec(const std::vector<std::shared_ptr<instruction>> &vect);
    void afficherVille() const;
};

