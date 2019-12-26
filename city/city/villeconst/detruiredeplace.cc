#include "detruiredeplace.hh"
#include "construction.hh"
#include "maison.hh"


void Deplace::exec(construction &C) {
    if (_indice != 0) // l'indice a ete passe au lieu des coordonne
      {
        C.getMaisonI(_indice)->setCoord(_nouvelleCoordonne);
            }
    else //coordonnee donnee
    {
        C.getMaisonCoo(_anciennecoordonnee)->setCoord(_nouvelleCoordonne);
    }
}
