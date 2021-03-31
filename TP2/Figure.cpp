#include "Figure.h"
using namespace std ;

//----------------------------------------------------------------------------------------

// Classe Figure
// pour l'attribu cpt par exemple, vu qu'on l'utilise dans une fonction etant declaree dans le cadre Figure :: alors pas
// besoin de redeclarer Figure :: cpt
Figure :: Figure(){cpt++;}

int Figure::cpt =0;

//----------------------------------------------------------------------------------------
// classe Polygone

Polygone :: Polygone(){nbCotes =0;}

Polygone :: Polygone(int nb){nbCotes=nb;}

void Polygone :: afficherCaracteristiques(){cout<<"nombre de cotes du polygone : "<<nbCotes<<endl;}

//----------------------------------------------------------------------------------------

// Class Rectangle

Rectangle :: Rectangle():Polygone(4), largeur(0),longueur(0){}

Rectangle :: Rectangle(int large, int longue):Polygone(4), largeur(large),longueur(longue){}

int Rectangle :: getLargeur(){return largeur;}

int Rectangle :: getLongueur(){return longueur;}

void Rectangle :: setLargeur(int large){largeur = large;}


void Rectangle :: setLongueur(int longue){longueur = longue;}

int Rectangle :: perimetre(){return (2*largeur + 2*longueur);}


void Rectangle :: afficherCaracteristiques(){
        cout<<"Figure : Polygone "<<endl;
        cout<<"polygone : rectangle "<<endl;
        cout<<"largeur : "<<largeur<<endl;
        cout<<"longueur : "<<longueur<<endl;
    }

//----------------------------------------------------------------------------------------

// Classe Carre

    Carre :: Carre():Rectangle(){}

    Carre :: Carre(int cote):Rectangle(cote,cote){}

void Carre :: afficherCaracteristiques(){
        cout<<"Figure : Polygone "<<endl;
        cout<<"Polygone : Carre "<<endl;
        cout<<"Longueur du cote : "<<longueur<<endl;
        cout<<"Perimetre : " << perimetre()<<endl;
        }

//----------------------------------------------------------------------------------------

// Classe Triangle

Triangle :: Triangle():Polygone(3),cote(0){}

Triangle :: Triangle(int c):cote(c){}

int Triangle :: getCote(){return cote;}

void Triangle :: setCote(int c){cote = c;}

int Triangle :: perimetre(){return 3*cote;}

void Triangle :: afficherCaracteristiques(){
        cout<<"Figure : Polygone "<<endl;
        cout<<"Polygone : Triangle equilateral "<<endl;
        cout<<"longueur du cote : "<<cote<<endl;
        cout<<"Perimetre : "<< perimetre()<<endl;
    }


//----------------------------------------------------------------------------------------

// Classe Coloriable

Coloriable :: Coloriable(){couleur = "blanc";}

Coloriable :: Coloriable(string coul){couleur = coul;}

string Coloriable :: getCouleur(){return couleur;}

void Coloriable :: setCouleur(string coul){couleur = coul;}

//----------------------------------------------------------------------------------------

// Classe Cercle


Cercle :: Cercle():Coloriable(),rayon(0){}

Cercle :: Cercle(int r, string couleur):Coloriable(couleur){rayon = r;}


int Cercle :: getRayon()
{return rayon;}

void Cercle :: setRayon(int r){rayon = r;}

int Cercle ::  perimetre(){return 2*Pi*rayon;}

void Cercle :: afficherCaracteristiques(){
        cout<<"Figure : Cercle "<<endl;
        cout<<"Rayon : "<<rayon<<endl;
        cout<<"Perimetre : "<< perimetre()<<endl;
        cout<<"Couleur : "<<getCouleur()<<endl;
    }



//----------------------------------------------------------------------------------------


