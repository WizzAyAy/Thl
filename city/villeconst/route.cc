#include "route.hh"
#include "maison.hh"

route::route(const std::shared_ptr<maison> &A, const std::shared_ptr<maison> &B)
    :instruction(),_extremite1(A),_extremite2(B) {}

std::shared_ptr<instruction> route::clone() const{
    return std::make_shared<route>(*this);
}
