#include "touroriente.hh"
#include "maison.hh"

tourOriente::tourOriente(int const & indice, int const & angle, bool const & coor)
    :instruction(),_indice(indice),_angle(angle),Acoordonnee(coor){}

void tourOriente::exec(construction &C)
{

    if(Acoordonnee){

         C.getMaisonCoo(_coordonnee)->setOrientation(_angle);
    }
    else{
            C.getMaisonI(_indice)->setOrientation(_angle);
    }
}


