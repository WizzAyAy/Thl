#include "route.hh"
#include "maison.hh"

route::route(maison *A, maison *B):instruction(),_extremite1(A),_extremite2(B)
{}
std::unique_ptr<instruction> route::clone() const{
    return std::make_unique<route>(*this);
}
