#include "route.hh"
#include "maison.hh"

route::route(maison *A, maison *B):instruction(),_extremite1(A),_extremite2(B)
{}
instruction * route::clone(){
    return new route(*this);
}
void route::exec(const construction &C) const{
  C.
}
