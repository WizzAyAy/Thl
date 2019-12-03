#pragma once
#include <vector>
struct coordonnee {
    int X;
    int Y;
    int Z;
};
class maison
{
private:
    coordonnee _coordMaison;
    int _id;
    static int id;
    std::vector<maison* > _route;

public:
    maison(coordonnee A);
    maison();
    coordonnee coordMaison() const;
    void setId(int id);
    int getId() const{
        return _id;
    }
    void ajouteRoute (maison *A);
};


