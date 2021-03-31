#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

#include <iostream>
#include <string>
// ATTENTION : Pas de using namespace std dans les .h

#define Pi 3.14

class Figure
{
public :
    static int cpt;
    Figure();
    virtual int perimetre()=0;
    virtual void afficherCaracteristiques()=0;
};




class Polygone : public Figure{
public :
    int nbCotes ;
    Polygone();
    Polygone(int nb);

    virtual void afficherCaracteristiques();
};

class Rectangle : public Polygone{
public :
    int largeur;
    int longueur;

    Rectangle();

    Rectangle(int large, int longue);

    int getLargeur();

    int getLongueur();


    void setLargeur(int large);


    void setLongueur(int longue);

    virtual int perimetre();


    virtual void afficherCaracteristiques();
};


class Carre : public Rectangle{

public :
    Carre();
    Carre(int cote);

    virtual void afficherCaracteristiques();

};

class Triangle : public Polygone{
public :
    int cote;
    Triangle();
    Triangle(int c);

    int getCote();

    void setCote(int c);

    virtual int perimetre();
    virtual void afficherCaracteristiques();
};


class Coloriable {

protected :
    std :: string couleur;

public :
    Coloriable();
    Coloriable(std :: string coul);

    std :: string getCouleur();

    void setCouleur(std :: string coul);
};


class Cercle : public Figure, public Coloriable{
public :
    int rayon;
    Cercle();
    Cercle(int r, std :: string couleur);


    int getRayon();
    void setRayon(int r);

    virtual int perimetre();

    virtual void afficherCaracteristiques();

};


#endif // FIGURE_H_INCLUDED
