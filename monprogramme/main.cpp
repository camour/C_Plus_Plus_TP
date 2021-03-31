#include <iostream>
#include <math.h>

using namespace std;

class Personnage {
protected:

    int nom ;
public :
    int age;
    Personnage(){}

private :
    int vie ;



};

class Guerrier: public Personnage
{ public :

    Guerrier(){age=5;}
    void afficher(){
        //age=989;
        cout<<"age : "<<age<<endl;}



};

int main()
{
    Personnage X;
    Guerrier Y;
    // Y.vie = 3; =faux!! car nous sommes à l'extérieur de la classe dans le programme

    Y.afficher();
    int i =2;
    int &ref = i;
    int x = ref;
    x=0;
    cout<<i;

    return 0;
}
