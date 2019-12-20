#include "touroriente.hh"
#include "maison.hh"

tourOriente::tourOriente(const int &indice, const int &angle, const bool &tourner)
    :instruction(),_indice(indice),_angle(angle), _tourner(tourner){}

void tourOriente::exec(construction &C)
{
    if(_tourner)
        C.getMaisonI(_indice)->setTourner(_angle);
    else
        C.getMaisonI(_indice)->setOrientation(_angle);
}
