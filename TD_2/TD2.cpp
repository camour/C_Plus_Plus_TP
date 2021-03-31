#include <iostream>

using namespace std;

 // eleve : Chadi AMOUR
 // classe : 4 AE-SE groupe 2
 // TD2
 // travail effectue sur l'IDE Code::Blocks

class Vecteur{
private :
    int dim;
    float * elements;

public :

    Vecteur(){
    dim =0;
    elements=NULL;
    }

    Vecteur(int d){
        dim = d;
        elements = new float[dim];
            }


    Vecteur(int d, float * tab){
        dim= d;
        elements = new float[dim];
        for (int i =0; i<dim; i++){
            elements[i]=tab[i];

        }
    }


    Vecteur(const Vecteur & autre){
    dim = autre.dim;
    elements = new float[dim];
    for (int i = 0; i < dim ; i++){
        elements[i]=autre.elements[i];
    }
    }


    // methode qui affiche les elements du vecteur
    void get(){
    for (int i = 0; i<dim ; i++){
    cout<<"element numero "<<i<<" : " <<elements[i]<<endl;
    }
    }

    // methode qui permet a l'utilisateur de saisir les elements du vecteur
    void put(){
    for (int i =0; i<dim ; i++){
    cin>>elements[i];

    }
    }


    // operateur d'indice quand on veut acceder l'element numero i et lui affecter une valeur (l-values)
    float & operator [](int i){
    // on verifie que l'utilisateur ne demande pas un element du vecteur qui n'existe pas
    if (i < dim){
    return elements[i];
    }
    }

    // operateur d'indice, pour acceder a un element numero i et le copier
    float operator [] (int i) const {
    if (i<dim){
    return elements[i];
    }
    }

    // operateur d'affectation
    Vecteur & operator =(const Vecteur & autre){
    dim = autre.dim;
    elements=new float[dim];
    for (int i = 0; i<dim ; i++){
    elements[i]=autre.elements[i];
    }
    return (*this);
    }

    // operateur +=
    Vecteur& operator+=(const Vecteur & autre){
    if (dim==autre.dim){
        for (int i = 0; i < dim ; i++){
        elements[i]+=autre.elements[i];

        }
    return (*this);
    }
    else{cout<<"erreur : vecteurs de taille differente"<<endl;
    }
    }

    // accesseur pour l'attribut dim
    int getDim(){
    return dim;
    }

    // accesseur pour l'attribut elements
    float * getElements(){
    return elements;
    }

};

    // operateur +
    Vecteur operator+( Vecteur & a, Vecteur &b){
    if (a.getDim() == b.getDim()){
            Vecteur resultat(a);
            resultat+=b;
            return resultat;

    }
    }


int main()
{
    float tab[] = {1,2,3};

    //test operateur d'indiçage
    Vecteur v1(3);
    float f;
    v1[0]=3.1;
    f=v1[0];
    cout<<"test de l'operateur d'indicage en ecrivant "" v1[0] = 3.1 "" puis "" f=v1[0] "<<endl;
    cout<<" f vaut : "<<f<<endl;
    cout<<endl<<endl;


    // test operateur d'affectation
    Vecteur v2(3,tab);
    Vecteur v3 ;
    v3=v2;
    cout<<"test de l'operateur d'affectation, en ecrivant v3 = v2 "<<endl;
    cout<<"Voici d'abord v2 : "<<endl;
    v2.get();
    cout<<"Voici v3 (on constate que v3 est bien le meme vecteur que v2) : "<<endl;
    v3.get();
    cout<<endl<<endl;


    // test operateur + et +=
    cout<<"test des operateurs ""+="" et ""+"" en ecrivant"" v4 = v2+v3 "<<endl;
    cout<<"Voici donc le vecteur v4 :"<<endl;
    Vecteur v4(3);
    v4=v2+v3;
    v4.get();
    cout<<endl<<endl;
    cout<<"test des operateurs "" += "" et " " + "", pour deux vecteurs de taille differente  "<<endl;
    cout<<" On ecrit "" v5+=v2 "" avec v2 de taille 3 et v5 de taille 2 "<<endl;
    cout<<"Voici donc v5 : "<<endl;
    Vecteur v5(2,tab);
    v5+=v2;


    return 0;
}
