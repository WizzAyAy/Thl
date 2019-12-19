#include "route.hh"
#include "maison.hh"
#include "construction.hh"


route::route(const std::shared_ptr<maison> &A, const std::shared_ptr<maison> &B)
    :instruction(),_extremite1(A),_extremite2(B) {}

std::shared_ptr<instruction> route::clone() const{
    return std::make_shared<route>(*this);
}

void route::afficher(std::ostream &os) const
{
    os << "route de ";
    _extremite1->afficher(os);
    os << " vers ";
    _extremite2->afficher(os);
}

void route::exec(construction &C){
    C.ajouteRoute(std::make_shared<route>(*this));
}
