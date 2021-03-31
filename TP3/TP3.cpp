#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

//---------------------------------------------------------exo 1--------------------------------------------------

void test_exo1(){

    vector<float> v1,v2;
    float j=0.0;

    for (int i=0;i<10;i++){
        v1.push_back(j);
        j+=0.1;
    }

    cout<<"affichage du vecteur v1 : "<<endl;
    for (int k = 0 ; k<v1.size();k++){
       cout<<v1[k]<<" ";
    }
    cout<<endl;
    v2=v1;
    cout<<"affichage du vecteur v2, apres avoir ecrit : v2 = v1 : "<<endl;
    for (int k = 0 ; k<v2.size();k++){
       cout<<v2[k]<<" ";
    }

    cout<<endl<<endl;

    cout<<"Effacement de la deuxieme moitie de v2.. "<<endl;
    int taille_v2 = v2.size();

    for (int k = (taille_v2)/2 ;k<taille_v2;k++){
        v2.pop_back();
    }


    cout<<"Affichage de v2 qui est modifie : "<<endl;
    for (int k =0; k<v2.size();k++){
        cout<<v2[k]<<endl;
    }

}

//---------------------------------------------------------exo 2--------------------------------------------------

void test_exo2(){
    list<char> liste_1, list_2;
    list<char> :: iterator it;
    char lettre = 'a';

    for (int i=0; i<10 ; i++){
        liste_1.push_back(lettre);
        lettre+=1;
    }
    cout<<"Affichage de la liste composee des 10 premieres lettres de l'alphabet : "<<endl;
    for (it=liste_1.begin(); it != liste_1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl<<endl;
    list_2 = liste_1;
    cout<<"Effacement de la 2e moitie de la liste l2 = l1.. "<<endl;
    list<char> :: iterator it_first;
    list<char> :: iterator it_last;
    it_first = list_2.begin();
    it_last=list_2.end();
    for (int i = 0; i< (list_2.size()/2);i++){ it_first++;};


    it_last=list_2.erase(it_first,it_last);
    cout<<"Voici la liste 2 avec le deuxieme bloc supprime : " <<endl<<endl;
    for (it=list_2.begin(); it != list_2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl<<endl;

}

//---------------------------------------------------------exo 3--------------------------------------------------

void test_exo3(){
    set<string> s;
    set <string> :: iterator it;
    s.insert("Alex");
    s.insert("Mathilde");
    s.insert("Thomas");
    s.insert("Ana");
    cout<<"Affichage de la classe : "<<endl<<endl;
    for (it = s.begin(); it != s.end() ; it++){
        cout<<*it<<endl;
    }

    cout<<"Suppression des deux eleves suivant l'ordre lexicographique.. "<<endl<<endl;
    it=s.begin();
    s.erase(*it);
    it=s.begin();
    s.erase(*it);
    cout<<"Affichage de la classe modifiee : "<<endl<<endl;
    for (it = s.begin(); it != s.end() ; it++){
        cout<<*it<<endl;
    }
}

//---------------------------------------------------------exo 4--------------------------------------------------

void  test_exo4(){

    map<string,string> dic;
    map<string,string> :: iterator it;
    dic["Alex"] = "639126973";
    dic["Alexia"] = "691486914";
    dic["Mathilde"] = "539016251";
    dic["Ana"] = "439117972";
    dic["Thomas"] = "531172902";

    cout<<"Voici le dictionnaire des noms avec leur numero "<<endl;
    for (it =  dic.begin();it!=dic.end() ; it++){
        cout<<"numero de "<<it->first<<" : "<<it->second<<endl;
    }

    cout<<endl<<endl;

    cout<<"Suppression de tous les contacts commencant par un 5.."<<endl;

    set<string> s;

    for (it =  dic.begin(); it!=dic.end() ; it++ ){
       if (it->second[0] == '5'){
            s.insert(it->first); // je note les noms dont le numero commencent par 5, en effet je ne peux pas faire erase ici sinon je reduis le dictionnaire pendant que it s'incremente
       }
    }

    for (set<string> :: iterator it_set = s.begin(); it_set != s.end();it_set++){

        dic.erase(*it_set);
    }

    cout<<endl<<endl;

    cout<<"Voici le nouveau dictionnaire avec les contacts ne commencant par '5'  "<<endl<<endl;

    for (it =  dic.begin();it!=dic.end() ; it++){
        cout<<"numero de "<<it->first<<" : "<<it->second<<endl;
    }

}

//---------------------------------------------------------exo 5--------------------------------------------------

void test_exo5(){

    vector<string> v ;
    vector<string> :: iterator it ;
    map<string,int> dic ;

    v.push_back("bonjour");
    v.push_back("cava");
    v.push_back("oui");
    v.push_back("merci");
    v.push_back("aurevoir");

    cout<<"Affichage du vecteur non trie : "<<endl<<endl;

    for (int i=0 ; i<v.size();i++){
        cout<<v[i]<<endl<<endl;
    }
    sort(v.begin(),v.end());
    cout<<endl;
    cout<<"Affichage du vecteur trie par ordre lexiographique: "<<endl<<endl;
    for (int i=0 ; i<v.size();i++){
        cout<<v[i]<<endl<<endl;
    }

}

//---------------------------------------------------------exo 6--------------------------------------------------

void test_exo6(){
    list<string> liste;
    list<string> :: iterator it;
    liste.push_back("il");
    liste.push_back("fait");
    liste.push_back("beau");
    cout<<"Voici la liste initiale : " <<endl<<endl;
    for (it = liste.begin();it!=liste.end();it++){
        cout<<*it<<endl;
    }
    cout<<endl<<endl;
    cout<<"Voici la nouvelle liste avec l'ajout du mot ""tres"" devant le mot ""beau"<<endl<<endl;
    it = find(liste.begin(),liste.end(),"beau");
    liste.insert(it,"tres");
    for (it = liste.begin();it!=liste.end();it++){
        cout<<*it<<endl;
    }
}



int main()
{
    cout<<"Exo 1 : " <<endl<<endl;
    test_exo1();
    cout<<"----------------------------------------------------"<<endl;
    cout<<"On passe a l'exo 2 "<<endl<<endl;
    test_exo2();
    cout<<"----------------------------------------------------"<<endl;
    cout<<"On passe a l'exo 3  "<<endl<<endl;
    test_exo3();
    cout<<"----------------------------------------------------"<<endl;
    cout<<"On passe a l'exo 4  "<<endl<<endl;
    test_exo4();
    cout<<"----------------------------------------------------"<<endl;
    cout<<"On passe a l'exo 5  "<<endl<<endl;
    test_exo5();
    cout<<"----------------------------------------------------"<<endl;
    cout<<"On passe a l'exo 6 "<<endl<<endl;
    test_exo6();
    return 0;
}
