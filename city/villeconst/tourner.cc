#include "tourner.h"
#include "construction.hh"
#include "maison.hh"

tourner::tourner(int ind, coordonnee C, int angle)
    :instruction(),_indice(ind),_coordonne(C),_angle(angle)
{

}

void tourner::exec(construction & C)
{

    if (_indice != 0 ){
      auto const & house = C.getMaisonI(_indice);
      house->setTourner(_angle);

  }
  else if (((_coordonne.X != 0) && (_coordonne.Z != 0)) &&(_coordonne.Z != 0)){
      auto const & house = C.getMaisonCoo(_coordonne);
      house->setTourner(_angle);

  }
}
