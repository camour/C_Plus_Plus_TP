#include <iostream>


using namespace std;

 // eleve : Chadi AMOUR
 // classe : 4 AE-SE groupe 2
 // TD4 : less patrons
 // travail effectue sur l'IDE Code::Blocks
 // Tous les tests sont guides et affiches dans le terminal lorsque vous lancez l'execution du programme


template<typename T> class Vecteur{
    public :

    Vecteur(){
    dim =0;
    elements=NULL;
    }

    Vecteur(int d){
        dim = d;
        elements = new T[dim];
            }


    Vecteur(int d, T * tab){
        dim= d;
        elements = new T[dim];
        for (int i =0; i<dim; i++){
            elements[i]=tab[i];

        }
    }


    Vecteur(const Vecteur<T> &autre){
    dim = autre.dim;
    elements = new T[dim];
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



    // operateur d'indice quand on veut acceder l'element numero i et lui affecter une valeur (l-values)
    T& operator [](int i){
    // on verifie que l'utilisateur ne demande pas un element du vecteur qui n'existe pas
    if (i>=0 && i<dim){
    return elements[i];
    }
    }

    // operateur d'indice, pour acceder a un element numero i et le copier
   T operator [] (int i) const {
    if (i>=0 && i<dim){
    return elements[i];
    }
    }

    // operateur d'affectation
    Vecteur <T> & operator =(const Vecteur<T> &autre){
    dim = autre.dim;
    elements=new T[dim];
    for (int i = 0; i<dim ; i++){
    elements[i]=autre.elements[i];
    }
    return (*this);
    }

    // operateur +=
    Vecteur<T>& operator+=(const Vecteur<T> & autre){
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
    void setDim(int d){
    dim=d;
    elements=new T [dim];
    }

    // accesseur pour l'attribut elements
    T * getElements(){
    return elements;
    }
    void setElements(T tab[]){

    for (int i = 0; i<dim ;i++){
        elements[i]=tab[i];
    }
    }
  template <typename N> friend  ostream & operator <<(ostream &os,  Vecteur<N> const &v);
  template <typename O> friend  istream & operator >>(istream &is, Vecteur<O> &v);


private :
    int dim;
    T * elements;



};

    // operateur +
    template<typename S> Vecteur<S> operator+( Vecteur<S> & a, Vecteur<S> &b){
    if (a.getDim() == b.getDim()){
            Vecteur<S> resultat(a);
            resultat+=b;
            return resultat;

    }
    }


    template <typename N>  ostream & operator<<(ostream &os, Vecteur<N> const &v){
        for (int i = 0; i<v.dim;i++){
           os<<v[i]<<endl;
        }
        return os;
    }

    template <typename O>  istream & operator>>(istream &is, Vecteur<O> &v){

        for (int i = 0; i<v.dim;i++){

        is>>v[i];

        }
        return is;
    }





int main()
{
    // Test sur le constructeur parametre prenant en parametre un tableau d'elements
    cout<<"Nous allons tester le constructeur parametre qui prend un tableau d'elements en parametres"<<endl;
    cout<<"Pour cela nous allons successivement lui fournir en argument un tableau de floats, de int puis de char et les afficher"<<endl;

    float tab1[3]={1.1,2.1,3.1};
    Vecteur<float>v1(3,tab1);
    cout<<"Affichage de v1 construit sur un tableau de float :"<<endl;
    v1.afficher();

    // Test sur le meme constructeur mais cette fois-ci on donne un tableau d'entiers en parametre
    cout<<"Nous passons maintenant un tableau d'entiers, voici le vecteur obtenu :"<<endl;
    int tab2[3]={1,2,3};
    Vecteur <int> v2(3,tab2);
    v2.afficher();
    cout<<endl;

    // Test sur le meme constructeur mais cette fois-ci on donne un tableau de char en parametre
    cout<<"Nous passons maintenant un tableau de char, voici le vecteur obtenu :"<<endl;
    char tab3[3]={'a','b','c'};
    Vecteur <char> v3(3,tab3);
    v3.afficher();
    cout<<endl<<endl;

    //------------------------------------------------------------------------------------------
    // Test des operateurs

    // Test de l' operateur d'affectation
    cout<<"Nous allons maintenant tester les differents operateurs "<<endl;
    cout<<"Test de l'operateur '='"<<endl;
    cout<<"Nous affectons v4 a v5 :"<<endl;
    cout<<"Tout d'abord voici v4 :"<<endl;
    Vecteur<float> v4 (3,tab1);
    v4.afficher();
    cout<<"Voici v5 :"<<endl;
    float tab4[]={3.1,4.1,6.1};
    Vecteur<float> v5(3,tab4);
    v5.afficher();
    cout<<endl;
    cout<<"Nous affectons v4 a v5 : v5.operator=(v4)"<<endl;
    v5.operator=(v4);
    cout<<"Voici v5 apres affectation"<<endl;
    v5.afficher();
    cout<<endl<<endl;

    // Test de l'operateur d'indicage
    cout<<"Testons a present l'operateur '[]', nous allons simplement afficher v5[1] avec v5 le vecteur affiche juste au-dessus:"<<endl;
    cout<< v5[1]<<endl<<endl;

    // Test de l'operateur +
   cout<<"Testons a present l'operateur '+' qui se sert de l'operateur '+='"<<endl;
   cout<<"Nous allons additionner v6 et v7 et affecter ce resultat a v8"<<endl;
   cout<<"Voici v6 :"<<endl;
    Vecteur<int>v6(3,tab2);
    v6.afficher();
    cout<< "Voici v7 :"<<endl;
    Vecteur <int> v7(3,tab2);
    v7.afficher();
    cout<<endl;

    Vecteur<int> v8(3);
    v8 = (v6 + v7);
    cout<<"Voici v8 :"<<endl;
    v8.afficher();
    //---------------------------------------------------------------------------------------------------------------------

    // Test des operateurs >> et <<
    cout<<"Derniers tests : on teste les operateurs de flux, on affiche par exemple v8, le vecteur juste au-dessus avec la commande cout<<v8"<<endl;
    cout<<v8;



    cout<<"Il reste enfinl'operateur >> "<<endl;
    cout<<"Vous allez saisir votre vecteur qu'on affichera ensuite pour verifier que la saisie a bien fonctionne"<<endl;
    cout<<"Nous prendrons une dimension 2 par exemple"<<endl;
    Vecteur<int> v9(2);
    cin>>v9;
    cout<<"Voici le vecteur saisi :"<<endl;
    v9.afficher();








    return 0;
}
