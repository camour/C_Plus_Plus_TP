#include <iostream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include <vector>

using namespace std;


bool anagram (char mot_A[], char mot_B[] ) // fonction qui teste si le mot B et un anagramme du mot A
{

    int longueur_mot_A = strlen (mot_A) ;
    int longueur_mot_B = strlen (mot_B) ;
    bool resultat = false ; // Variable boolean finale qui sera retourn�e par la fonction pour savoir si deux mots sont anagrammes avvec une initialisation � false

    if (longueur_mot_A == longueur_mot_B)  // je compare la longueur des deux mots, premi�re condition pour avoir un anagramme
    {
        cout << "Les mots " << mot_A << " et " << mot_B << "  ont une longueur identique, verifions s'il s'agit d'un anagramme" << endl ;
        int index_A = 0 ; // les index sont des variables permettant de parcourir les deux mots
        int index_B = 0 ;
        int tableau_indices [longueur_mot_A] ; // Ce tableau sert � stocker les indices correspondant aux lettres deja trouvees dans le mot B afin d'eviter de comparer plusieurs fois le meme caractere
        int indice_tableau = 0 ; // Cette variable va me permettre de parcourir le tableau_indice afin de le remplir
        tableau_indices [0] = 10000 ; // initialisation "random" du tableau pour qu'il ne soit pas vide.
        bool indice_deja_trouve ;
        resultat = true ;
        system("PAUSE") ;
        while ((index_A < longueur_mot_A)&&(resultat == true))
        {
            while (index_B < longueur_mot_B)
            {
                if (mot_A[index_A] == mot_B[index_B])   // Je compare chaque caractere du mot A avec les caracteres du mot B
                {

                    for (int i = 0 ; i < indice_tableau; i++)  // Je m'assure que la lettre du mot B n'a pas deja ete comparee pr�alablement
                    {
                        if (tableau_indices [i] == index_B)
                        {
                            indice_deja_trouve = true ;
                            break ;
                        }
                        else
                        {
                            indice_deja_trouve = false ;
                        }
                    }

                    if (indice_deja_trouve)
                    {
                        index_B = index_B +1;    // Si la lettre a deja ete trouvee alors je passe � l'iteration suivante pour verifier qu'il y en a bien une autre
                        continue;
                    }
                    else   // Sinon, si l'indice n'apparait pas dans tableau_indice alors on a bien trouve une lettre identique unique, jamais utilis�e pr�alablement
                    {
                        tableau_indices [indice_tableau] = index_B ;
                        indice_tableau = indice_tableau + 1 ; // je n'oublie pas d'incrementer indice_tableau a chaque fois que la lettre a ete trouvee
                        resultat = true ; // Une fois la lettre trouvee dans mot B l'anagramme commence a �tre vrai mais cela ne suffit pas, il faut poursuivre les iterations
                        break ;
                    } // On passe alors a la prochaine lettre du mot A
                }
                else
                {
                    resultat = false ;
                }
                index_B = index_B + 1 ;
            }
            index_B = 0 ;
            index_A = index_A + 1 ;
        }

    }
    else
    {
        cout << "les mots ne sont pas de longueur identique" << endl ;

    }
    return resultat ;
}

int digital_root (int n) { // fonction recursive de la somme des digits d'un nombre n
int resultat ;
if (n>=10) resultat = ((n%10) + digital_root (n/10)) ;
else resultat = n ;
return ((resultat%10) + (resultat/10)) ;
}

int main()
{
    // procedures de test de la fonction anagram et de la fonction digital_root
    char test_1 []= "ANAGRAM" ;
    char test_2 []= "NAGRAMA";
    char test_3 []= "rat" ;
    char test_4 []= "car" ;

    int test_digital_root = 67868988;
    int test_digital_root_2 = 100576 ;
    int test_digital_root_3 = 86900 ;
    int test_digital_root_4 = 5276 ;
    int test_digital_root_5 = 258 ;
    int test_digital_root_6 = 15 ;
    int test_digital_root_7 = 8 ;
    int nombre ;
    if (anagram (test_1,test_2))
    {
        cout << test_2 << " est un anagramme de " << test_1 << endl ;
        cout << endl ;
    }
    else
    {
        cout << test_2 << " n'est pas un anagramme " << test_1 << endl ;
        cout << endl ;
    }
    system ("PAUSE") ;
    if (anagram (test_3,test_4))
    {
        cout << test_4 << " est un anagramme de " << test_3 << endl ;
        cout << endl ;
    }
    else
    {
        cout << test_4 << " n'est pas un anagramme de " << test_3 << endl ;
        cout << endl ;
    }
    system ("PAUSE") ;
cout << "la somme recursive de tous les digits dans le nombre " << test_digital_root << " est " << digital_root(test_digital_root) << endl ;
cout << endl ;
cout << "la somme recursive de tous les digits dans le nombre " << test_digital_root_2 << " est " << digital_root(test_digital_root_2) << endl ;
cout << endl ;
cout << "la somme recursive de tous les digits dans le nombre " << test_digital_root_3 << " est " << digital_root(test_digital_root_3) << endl ;
cout << endl ;
cout << "la somme recursive de tous les digits dans le nombre " << test_digital_root_4 << " est " << digital_root(test_digital_root_4) << endl ;
cout << endl ;
cout << "la somme recursive de tous les digits dans le nombre " << test_digital_root_5 << " est " << digital_root(test_digital_root_5) << endl ;
cout << endl ;
cout << "la somme recursive de tous les digits dans le nombre " << test_digital_root_6 << " est " << digital_root(test_digital_root_6) << endl ;
cout << endl ;
cout << "la somme recursive de tous les digits dans le nombre " << test_digital_root_7 << " est " << digital_root(test_digital_root_7) << endl ;
cout << endl ;
    return 0;
}
