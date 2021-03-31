#include <iostream>

using namespace std;

 // eleve : Chadi AMOUR
 // classe : 4 AE-SE groupe 2
 // TD3 : heritage
 // travail effectue sur l'IDE Code::Blocks
 // tous les tests sont guides et affiches dans le terminal lorsque vous lancez l'execution du programme

 //classe mere
class Vecteur{
protected :
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
    void afficher(){
    for (int i = 0; i<dim ; i++){
    cout<<"element numero "<<i<<" : " <<elements[i]<<endl;
    }
    }

    // methode qui permet a l'utilisateur de saisir les elements du vecteur
    void saisir(){
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
    Vecteur & operator =( Vecteur const & autre){

    if (dim == autre.dim){
        elements=new float[dim];
        for (int i = 0; i<dim ; i++){
        elements[i]=autre.elements[i];
    }
        return (*this);
    }
        else {
                cout<<"vecteurs de taille differente"<<endl;
        }
    }

    // operateur +=
    Vecteur& operator+=( Vecteur const & autre){
        if (dim==autre.dim){
            for (int i = 0; i < dim ; i++){
            elements[i]+=autre.elements[i];

            }
        return (*this);
        }
        else{
            cout<<"erreur : vecteurs de taille differente"<<endl;
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

    void setDim(int d){
    dim=d;
    }
    void setElements(float * tab){
        elements = new float[dim];
    for (int i=0;i<dim;i++){
        elements[i]=tab[i];
    }

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
//------------------------------------------------------------------------------------------------------------------
//classe fille
class Vecteur_intel : public Vecteur
{
public :

    Vecteur_intel():Vecteur(){}
    Vecteur_intel(Vecteur_intel const &v):Vecteur(v){}
    Vecteur_intel(int d):Vecteur(d){}
    Vecteur_intel(int d, float * tab):Vecteur(d,tab){}


    Vecteur_intel& operator=( Vecteur_intel const &autre){

        float * copie = NULL;

        if (dim==autre.dim){
            setElements(autre.elements);
        }

        else if(dim<autre.dim){

            copie = new float[autre.dim];


            for (int i=0;i<autre.dim;i++){
                        copie[i]=autre[i];
            }


            dim=autre.dim;
            setElements(copie);

       }
       else {


        for (int i=0;i<autre.dim;i++){
            elements[i]=autre[i];
        }

       }

        return (*this);

    }

    Vecteur_intel & operator+=(Vecteur_intel& autre){

    float * copie=NULL;

    if (dim == autre.dim){
        for (int i = 0;i<dim;i++){
            elements[i]+=autre.elements[i];
        }
    }
    else if (dim<autre.dim){
        copie = new float[autre.dim];
        for (int i=0; i<dim;i++){
            copie[i]=(*this)[i] + autre[i];
        }
        for(int j=dim;j<autre.dim;j++){
            copie[j]=autre[j];
        }
        setDim(autre.dim);
        setElements(copie);
    }
    else{
        for(int i=0;i<autre.dim;i++){
            (*this)[i]+=autre[i];
        }
    }
    }



};

Vecteur_intel operator+(Vecteur_intel  &u1, Vecteur_intel &u2){
    Vecteur_intel resultat;
    int size_u1=u1.getDim();
    int size_u2=u2.getDim();

    if (size_u1 > size_u2){
            resultat=u1;
            resultat+=u2;
    }
    else {
        resultat=u2;
        resultat+=u1;
    }
    return resultat;
}


int main(){
float tab1[]={6.0};
float tab2[]={1.0,2.0};

//test sur l'operateur =
Vecteur_intel v1(1,tab1);
Vecteur_intel v2(2,tab2);
cout<<"Test de l'operateur ""="", on ecrit v2 = v1, le resultat aura la taille la plus grande"<<endl;
cout<<"Affichage de v1 et v2 avant l'affectation "<<endl;
cout<<" v1 : "<<endl;
v1.afficher();
cout<<" v2  "<<endl;
v2.afficher();
cout<<"Voici v2 apres affectation :"<<endl;
v2=(v1);
v2.afficher();
cout<<endl;

//----------------------------------------------------------------------------------------------------------
// test sur l'operateur +=
cout<<"Test de l'operateur ""+="", on ecrit v1+=v3"<<endl;
cout<<"Nous allons realiser la somme de v1 et v3 avec v3 de plus grande taille que v1:"<<endl;

cout<<"Vecteur v1:"<<endl;
v1.afficher();

cout<<"Vecteur v3:"<<endl;
Vecteur_intel v3 (2,tab2);
v3.afficher();
cout<<endl;

cout<<"v1+=v3.."<<endl;
v1.operator+=(v3);
cout<<"nouveau vecteur v1:"<<endl;
v1.afficher();
cout<<endl;

//---------------------------------------------------------------------------------------------------
//test sur l'operateur +

cout<<"test de l'operateur ""+"", on ecrit v5 = (v3 + v4)"<<endl;
cout<<"vecteur v3 :"<<endl;
v3.afficher();
Vecteur_intel v4(1);
cout<<" veuillez saisir le vecteur v4 de dimension 1:"<<endl;
v4.saisir();
cout<<"v3 est bien de dimension "<<v3.getDim()<<" et v4 est de dimension "<<v4.getDim()<<endl;
Vecteur_intel v5(2);

cout<<"on affecte (v3 + v4) a v5 :"<<endl;
v5.operator=(v3+v4);
cout<<"nouveau vecteur v5 :"<<endl;
v5.afficher();
return 0;

}
