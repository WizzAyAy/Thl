#pragma once
#include <vector>
#include <memory>
#include "instruction.hh"
#include "coordonnees.hh"

class maison : public instruction
{
private:
    coordonnee _coordMaison;
    int _idMaison;
    int _orientation;
    int _tourne;
    bool _estAlea;
    bool _detruire;


    static int compteur;
public:

    maison();
    maison(coordonnee A);
    maison(maison const & m)=default;

    std::shared_ptr<instruction> clone() const override;
    void exec(construction & C) override;

    coordonnee coordMaison() const{return _coordMaison;}
    void setCoord( coordonnee Q){_coordMaison = Q;}
    bool getAlea()const{return _estAlea;}
    int getIndice()const{return _idMaison;}
    void setOrientation(int const & angle){_orientation = angle; _orientation = _orientation%360;}
    int getOrientation () {return _orientation;}
    void setTourner(int const & angle){_tourne += angle;/* _tourne = _tourne%360;*/}
    int getTourne() const {

        return _tourne;
    }
    bool getDetruire () {return _detruire;}

    void afficher(std::ostream &os)const override;

    bool operator ==(maison const & m);
};



