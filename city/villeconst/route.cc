#include "route.hh"

route::route(const maison &A, const maison &B):instruction(),_extremite1(A),_extremite2(B)
{}
instruction * route::clone(){
    return new route(*this);
}
void route::exec(){
    //
}
