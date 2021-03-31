#include <iostream>
#include <string.h>

// eleve : Chadi AMOUR
 // classe : 4 AE-SE groupe 2
 // TD5 : Exceptions, Ami et Polymorphisme
 // travail effectue sur l'IDE Code::Blocks
 // tous les tests sont guides et affiches dans le terminal lorsque vous lancez l'execution du programme

using namespace std;

//Classe mere
class Vecteur {

// Declares protected pour donner acces a la classe fille Vecteur_Intel
protected :
    int dim;
    float * elements;

public:

    // Constructeur sans parametres
    Vecteur(){
    dim =0;
    elements=NULL;
    }

    Vecteur(int d ){
    dim=d;
    elements=new float [dim];
    }

    // Constructeur de recopie
    Vecteur (Vecteur const &autre){
    dim=autre.dim;
    for (int i = 0; i<dim ; i++){
        elements[i]=autre.elements[i];
    }
    }


    Vecteur(int d, float tab[]){
    dim=d;
    elements= new float [dim];
    for (int i= 0; i<dim;i++){
    elements[i]=tab[i];

    }
    }

    // Accesseurs
    int getDim(){
    return dim;
    }


    float * getElements(){
    return elements;
    }

    // Mutateur, je ne l'ai pas fait pour l'attribut dim car je n'en avais pas besoin
    void setElements(float tab []){

        elements = new float[dim];
        for (int i=0;i<dim;i++){
            elements[i]=tab[i];
        }
    }

    // Affiche les elements du vecteurs
    void Afficher(){
    for (int i =0; i<dim;i++){
        cout<<elements[i]<<endl;
    }
    }


    // Classe contenant les informations sur le depassement, lorsque l'on essaie d'acceder a un element i du vecteur par l'operateur d'indicage
    class Depassement{
    public :
        int indice;
        int dimension;

        Depassement(int i, int dim){

        indice = i;
        dimension = dim;
    }

    };
    float & operator[](int i){
        if (0<=i && i<dim){

        return elements[i];
        }
        else{

       throw Depassement(i,dim);
       }
    }

    // Classe utilise pour gerer l'exception liee a l'operateur d'affectation, lorsque les vecteurs sont de tailles differentes
    class Affectation{
        public :
            Affectation(){NULL;}
        };


    Vecteur & operator = (Vecteur &v){

        if (dim == v.dim){
            for (int i=0;i<dim;i++){
                elements[i]=v.elements[i];
            }
        }
        else{
            throw Affectation();
        }
    }

    friend Vecteur & Multiplication(float scalaire,Vecteur &v);

};

//-------------------------------------------------------------------------------------------------------

    // Renvoie la multiplication du vecteur par le scalaire passe en argument

Vecteur & Multiplication(float scalaire, Vecteur &v){
    for (int i = 0; i<v.dim;i++){
        v.elements[i]=v.elements[i]*scalaire;

        }
    return v;
    }

//------------------------------------------------------------------------------------------------

// Classe fille Vecteur_Intel

    class Vecteur_intel : public Vecteur
{
public :

    Vecteur_intel():Vecteur(){}
    Vecteur_intel(Vecteur_intel const &v):Vecteur(v){}
    Vecteur_intel(int d):Vecteur(d){}
    Vecteur_intel(int d, float * tab):Vecteur(d,tab){}


    Vecteur_intel& operator=( Vecteur_intel &autre){

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
};


//--------------------------------------------------------------------------------------

// Classe Matrix

class Matrix {
public :

    Vecteur * tab[2];

    // Constructeur sans parametres
    Matrix(){
        for (int i =0;i<2;i++){
            tab[i]=NULL;
        }
    }

    Matrix(Matrix const &M){
        memcpy(tab,M.tab,sizeof(Matrix));
    }

    Matrix(Vecteur * tableau[]){
       memcpy(tab,tableau,2*sizeof(Vecteur *));
    }

    void Affichage_Matrice()  {
        for (int i =0; i<2;i++){
            cout<<"Vecteur numero "<<i<<" :"<<endl;
            tab[i]->Afficher();
        }
    }

};




int main()
{



    float tab[]={1.1,1.2};

    Vecteur v1 (2,tab);
    Vecteur v2(1);
    int i=0;
    cout<<"Affichons l'element d'indice de votre choix du vecteur v1 qui est de dimension 2 "<<endl;
    cout<<"Veuillez saisir un indice superieur ou egal a la dimension du vecteur v1 pour verifier que l'exception liee a l'operateur d'indicage est bien geree "<<endl;
    try{
        cin>> i;
        cout<<v1[i]<<endl;




    }

    catch(Vecteur::Depassement const &v){
    cerr<<"Error : vous avez effectue un depassement en essayant d'acceder a l'element numero "<<v.indice<<" par l'operateur d'indicage alors que le taille du vecteur est :"<<v.dimension<<endl;
    }
    cout<<endl;
    try{
    cout<<"Creeons maintenant un vecteur v2 de taille 1 et affectons v1 a v2 par l'operateur '=' et verifions que l'exception est geree"<<endl;
        v2=v1;
    }
    catch ( Vecteur::Affectation const a){
    cerr<<"Error : Affectation impossible car vecteurs de tailles differentes"<<endl<<endl;

    }

    //---------------------------------------------------------------------------------------
    // Multiplication par un scalaire

    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"Nous allons maintenant tester la multiplication entre le vecteur v1 et le scalaire de votre choix"<<endl<<endl;
    cout<<"Voici v1 :"<<endl;
    v1.Afficher();
    cout<<"Veuillez saisir le scalaire :"<<endl;
    float f;
    cin>>f;
    cout<<"Nouveau vecteur v1 apres multiplication par votre scalaire :"<<endl;
    (Multiplication(f,v1));
    v1.Afficher();

    //----------------------------------------------------------------------------------------
    // Polymorphisme

    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"Terminons avec le polymorphisme et la classe Matrix"<<endl<<endl;
    cout<<"Tout d'abord, affichons notre premiere matrice M :"<<endl;
    float tab_0[]={1.1,1.2};
    float tab_1[]={2.1,2.2};
    Vecteur * tableau[2];
    tableau[0] = new Vecteur(2,tab_0);
    tableau[1]=new Vecteur(2,tab_1);

    Matrix M(tableau);
    M.Affichage_Matrice();

    cout<<"Ensuite affichons notre deuxieme matrice M1 constituee de vecteurs intelligents "<<endl;
    float tab_2[]={3.1,3.2,3.3};
    float tab_3[]={4.1,4.2,4.3};
    Vecteur * tableau_bis[2];
    tableau_bis[0] = new Vecteur_intel(3,tab_2);
    tableau_bis[1]=new Vecteur_intel(3,tab_3);

    Matrix M1(tableau_bis);
    M1.Affichage_Matrice();
    cout<<endl<<endl;
    cout<<"Pour terminer remarquons que la class Matrice est constitue de vecteurs qui peuvent soit appartenir a la classe mere Vecteur ou la classe fille Vecteur_Intel qui realise";
    cout<<"des operations plus intelligentes et s'adaptent a la taille notamment du vecteur operande"<<endl;




    return 0;


}
