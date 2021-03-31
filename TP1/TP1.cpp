#include <iostream>
#include <string.h>
#include <list>
using namespace std;
#define Pi 3.14

class Figure {
    public: static int cpt ;
    public :

    Figure(){
    cpt++;
    }
    virtual int perimetre() =0;
    virtual void afficherCaracteristiques()=0;
};

int Figure::cpt =0;


class Polygone : public Figure{
public :
    int nbCotes ;
    Polygone(){
        nbCotes =0;

    }
    Polygone(int nb){
        nbCotes=nb;

    }

    virtual void afficherCaracteristiques(){
        cout<<"nombre de cotes du polygone : "<<nbCotes<<endl;
    }
};

class Rectangle : public Polygone{
public :
    int largeur;
    int longueur;

    Rectangle():Polygone(4), largeur(0),longueur(0){}

    Rectangle(int large, int longue):Polygone(4), largeur(large),longueur(longue){}

    int getLargeur(){
        return largeur;
    }

    int getLongueur(){
        return longueur;
    }


    void setLargeur(int large){
        largeur = large;
    }


    void setLongueur(int longue){
        longueur = longue;
    }

    virtual int perimetre(){
        return (2*largeur + 2*longueur);
    }


    virtual void afficherCaracteristiques(){
        cout<<"Figure : Polygone "<<endl;
        cout<<"polygone : rectangle "<<endl;
        cout<<"largeur : "<<largeur<<endl;
        cout<<"longueur : "<<longueur<<endl;
    }
};


class Carre : public Rectangle{

public :
    Carre():Rectangle(){}
    Carre(int cote):Rectangle(cote,cote){}

    virtual void afficherCaracteristiques(){
        cout<<"Figure : Polygone "<<endl;
        cout<<"Polygone : Carre "<<endl;
        cout<<"Longueur du cote : "<<longueur<<endl;
        cout<<"Perimetre : " << perimetre()<<endl;
        }

};

class Triangle : public Polygone{
public :
    int cote;
    Triangle():Polygone(3),cote(0){}
    Triangle(int c):cote(c){}

    int getCote(){
        return cote;
    }

    void setCote(int c){
        cote = c;
    }

    virtual int perimetre(){
        return 3*cote;
    }
    virtual void afficherCaracteristiques(){
        cout<<"Figure : Polygone "<<endl;
        cout<<"Polygone : Triangle equilateral "<<endl;
        cout<<"longueur du cote : "<<cote<<endl;
        cout<<"Perimetre : "<< perimetre()<<endl;
        }
};


class Coloriable {
protected :
    string couleur;

public :
    Coloriable(){couleur = "blanc";}
    Coloriable(string coul){
    couleur = coul;
    }

    string getCouleur(){
    return couleur;
    }

    void setCouleur(string coul){
    couleur = coul;
    }
};

class Cercle : public Figure, public Coloriable{
public :
    int rayon;
    Cercle():Coloriable(),rayon(0){}
    Cercle(int r, string couleur):Coloriable(couleur),rayon(r){}


    int getRayon(){
        return rayon;
    }
    void setRayon(int r){
        rayon = r;
    }

    virtual int perimetre(){
        return 2*Pi*rayon;
    }

    virtual void afficherCaracteristiques(){
        cout<<"Figure : Cercle "<<endl;
        cout<<"Rayon : "<<rayon<<endl;
        cout<<"Perimetre : "<< perimetre()<<endl;
        cout<<"Couleur : "<<getCouleur()<<endl;
    }

};




int main()
{

    Cercle * ptr_cercle = new Cercle(3,"rouge");
    Carre * ptr_carre = new Carre (3);
    Triangle * ptr_triangle = new Triangle(3);
    Figure * tab[3] = {ptr_carre,ptr_cercle,ptr_triangle};


    for (int i = 0; i<3 ; i++){

        tab[i]->afficherCaracteristiques(); // notion de liaisons dynamiques. En effet la methode virtuelle afficherCaracteristiques()
        //elle definie lors de l'execution a travers son appel via une instance de classe fille (Carre, Cercle etc).
        // Rmq : on se rappelle bien deja qu'une classe abstraite n'est pas instanciable. Et surtout que normalement une classe mere
        // ne peut utiliser les fonctions redefinies dans une classe fille, sauf si cette fonction est justement virtuelle
        // C'est pour ca que lorsque l'element i du tableau, meme s'il est de classe abstraite mere Figure, en referencant
        // une classe fille, peut se permettre d'acceder a la nouvelle version  de la methode afficherCaracteristiques

        cout<<endl;
    }
    cout<<"nombre de figures creees : "<< Figure::cpt<<endl;
    return 0;
}
