#include "route.hh"
#include "maison.hh"
#include "construction.hh"


route::route(coordonnee A, coordonnee B)
    :instruction(),_extremite1(A),_extremite2(B) {}

std::shared_ptr<instruction> route::clone() const{
    return std::make_shared<route>(*this);
}

void route::afficher(std::ostream &os) const
{
    os << "route de ";
    os<<"("<<_extremite1.X <<","<<_extremite1.Y<<","<<_extremite1.Z<<")";
    os << " vers ";
    os<<"("<<_extremite2.X <<","<<_extremite2.Y<<","<<_extremite2.Z<<")";
}

void route::exec(construction &C){
    C.ajouteRoute(std::make_shared<route>(*this));
}
