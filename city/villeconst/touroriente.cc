#include "touroriente.hh"
#include "maison.hh"

tourOriente::tourOriente(const int &indice, const int &angle, const bool &tourner, const bool &coor)
    :instruction(),_indice(indice),_angle(angle), _tourner(tourner), _coordonnee(coor){}

void tourOriente::exec(construction &C)
{

    if(_tourner){
        if(!_coordonnee)
        C.getMaisonI(_indice)->setTourner(_angle);
        else;
//        C.getMaisonI( ici on veut les coordonnées )->setTourner(_angle);
    }
    else{
        if(!coordonnee)
            C.getMaisonI(_indice)->setOrientation(_angle);
        else;
//        C.getMaisonI( ici on veut les coordonnées )->setOrientation(_angle);

    }
}


