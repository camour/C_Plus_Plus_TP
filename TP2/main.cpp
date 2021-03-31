#include <iostream>
#include "Figure.h"
#include "File.h"



using namespace std;

int main()
{   cout<<"Nous allons creer une liste de trois cellules chacune contenant une figure " <<endl<<endl;
    cout<<"Plus precisement, la liste sera chainee de cette maniere : Triangle --> Carre --> Cercle " <<endl<<endl;
    cout<<"Voici les trois cellule, pour l'instant on verifie juste leur bonne instanciation (aucune liste n'est creee): "<<endl<<endl;
    Figure * cercle ;
    cercle = new Cercle(3,"rouge");
    Cellule<Figure *> cellule_1(cercle);
    cellule_1.element->afficherCaracteristiques();
    cout<<endl;

    Figure * carre ;
    carre = new Carre(3);
    Cellule<Figure *> cellule_2(carre);
    cellule_2.element->afficherCaracteristiques();
    cout<<endl;

    Figure * triangle ;
    triangle = new Triangle(3);
    Cellule<Figure *> cellule_3(triangle);
    cellule_3.element->afficherCaracteristiques();
    cout<<endl<<endl;


    cout<<"Creeons alors la liste chainee ..."<<endl<<endl;
    File<Figure *> file;
    file.add_Element(cellule_1);
    file.add_Element(cellule_2);
    file.add_Element(cellule_3);
    cout<<"test sur la file : on verifie  alors que l'element en tete est le triangle car ajoute en dernier"<<endl<<endl;

    file.get_Element_debut();
    cout<<endl<<endl;

    cout<<"test sur la file : on supprime l'element numero 1 par exemple qui est donc la premier cellule soit le Triangle"<<endl<<endl;

    cout<<"on verifie donc que le premier element est maintenant le carre  : " <<endl<<endl;
    file.remove_Element(1);
    file.get_Element_debut();


    //Cellule<Cercle> c (a);
   // File<Figure> f (c); en faisant ça, le compilateur doit instancier un objet de type File<Figure>
   // le compilateur se rend alors dans la classe File en posant le parametre T = Figure
   // le compilateur check alors les attributs qui sont des pointeurs et un entier (pour lui c ok, il cree son espace mem)
   // pour les pointeurs le compilateur reserve un simple espace memoire (pas d'allocation encore, juste
    // juste il place en memoire les variable first et last qui ne pointent sur aucun espace donc)
    // cpdt, le compilateur check le type pointe
   // le compilateur va donc seulement "regarder" pour la classe Cellule<Figure> (et NON instancier un objet de type Cellule<Figure>
   //
   // meme procede que file  sauf qu'il n'y a aucune instanciation :
   // le compilateur sait donc qu'il devra ( dans le FUTUR) instancier un objet de type Cellule<Figure>
   // le compilateur regarde alors la classe Cellule avec T = Figure
   // et se rend aux attributs, et se rend compte que l'un des attributs est de type T = Figure
    cout<<endl<<endl;
    cout<<"Creation d'une autre file vide pour tester l'exception, essayons par exemple de demander l'element en tete de liste avec la methode get_Element_debut(), alors que la liste est vide "<<endl;
    try{
        File<Figure *> file_2;
        file_2.get_Element_debut();
    }
    catch(File<Figure *>::Vide &vide){
    cout << "Exception : Vous ne pouvez effectuer l'operation suivante : " <<vide.get_operation()<<endl;
    }



    return 0;
}
