#include "construction.hh"
#include <iostream>
unsigned int construction::rayon() const
{

    return _rayon;
}
void construction::setRayon(unsigned int rayon)
{
    _rayon = rayon;


}
std::vector<maison *> construction::maisonDeLaVille() const
{
    return _maisonDeLaVille;
}

void construction::setMaisonDeLaVille(const std::vector<maison *> &maisonDeLaVille)
{
    _maisonDeLaVille = maisonDeLaVille;
}

construction::construction(int rayon):_rayon(rayon)
{
    for (int i=0;i<rayon;++i)
        for (int  j=0;j<rayon;++j){
            _emsembleroute[i][j] =false;
        }
    std::cout<<"je construis avec un rayon de  "<< _rayon <<std::endl;
}
construction::construction():_rayon(5)
{
    for (unsigned int i=0;i<_rayon;++i)
        for (unsigned int  j=0;j<_rayon;++j){
            _emsembleroute[i][j] =false;
        }
    std::cout<<"je construis avec un rayon de  "<< _rayon<<std::endl;

}
bool construction::maisonExiste(coordonnee c){
    for(auto  n : _maisonDeLaVille){
        if (((n->coordMaison().X ==  c.X) and (n->coordMaison().Y ==  c.Y)) and (n->coordMaison().Z ==  c.Z)) return true;
    }
    return false;
}
void construction::ajouteMaison(maison * A){
    std::cout<<"j'ai ajouté une maison"<<std::endl;
    _maisonDeLaVille.push_back(A);
}
/*maison* construction::trouveMaison(coordonnee A){
    for (auto const & n : _maisonDeLaVille ) {
        if (((n->coordMaison().X == A.X) and (n->coordMaison().Y == A.Y)) and ((n->coordMaison().Z == A.Z))) return n;
    }
}*/
/*void construction::route(coordonnee A, coordonnee B){
    if (maisonExiste(A) and maisonExiste(B)){
        int id1 =trouveMaison(A)->getId();
        int id2 =trouveMaison(B)->getId();
        _emsembleroute.at(id1).at(id2) =true;
        std::cout<<"j'ai cree une route"<<std::endl;
    }
}
*/
