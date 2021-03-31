#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include <iostream>
#include <string>
#include "Cellule.h"


template<typename T> class File{

protected :
    Cellule<T>  * first_cellule;
    Cellule<T> * last_cellule;
    int nb_elements;
public :
    File(){first_cellule = NULL; last_cellule=NULL; nb_elements=0;}
    void add_Element(Cellule<T> &c){c.next_cellule=first_cellule; first_cellule = new Cellule<T>(c); nb_elements++;};
    void remove_Element(int pos){
        if(nb_elements>0){
            int i = -1 ; // il faut bien comprendre que lorsque l'on veut supprimer une cellule, cest a dire casser la chaine
                        //il faut acceder au "vrai" pointeur sur cette cellule, c est a dire le vrai maillon de chaine
                        // donc si nous nous baladons dans la liste de cellules
                        // et que l'on est au mm niveau que le pointeur qui s'appelle next et qui pointe sur la cellule a supprimer
                        // on ne pourra pas supprimer la cellule de la liste, puisque quoi que l'on fasse,
                        // notre pointeur next qui est le maillon sur cette cellule ne sera pas impacte vu que l'on pointe la ou il pointe
                        // c'est a dire qu'on est au mm niveau que next.
                        // pour casser la chaine, il faut changer l'endroit ou pointe next
                        // il faut donc etre deux pointeurs derriere la cellule que l'on cherche a supprimer, c est pour ca que je fais partir
                        // i a -1 et non 0, il faut etre un cran derriere le pointeur next
            bool supprime = false;
            Cellule<T> * aux = first_cellule;
            while (i <= (nb_elements-1) && nb_elements>0 && supprime!=true){
                    if (pos == 1){
                        first_cellule=first_cellule->next_cellule;
                        supprime = true;
                    }
                    else{
                         if(i == (pos-2)){
                        aux->next_cellule = aux->next_cellule->next_cellule;
                        supprime = true;
                    }
                    }

                    aux=aux->next_cellule;
                    i++;
            }
        }
        else{
                throw Vide("remove");
        }

    };

    // Classe contenant un attribut qui indique l'operation que l'on cherchait a faire
    class Vide{
        protected :
            std::string operation;
        public:
            Vide(std::string op){
                operation = op;
            }
            std::string get_operation(){
                return operation;
            }
    };


    bool is_Empty(){
        bool resultat = false;
        if(first_cellule==NULL){
            resultat=true;
            }
        return resultat;
    };

    int get_nbElements(){ return nb_elements;};
    void get_Element_debut(){
        if(nb_elements!=0){
            return first_cellule->element->afficherCaracteristiques();
        }
        else{
            throw Vide("get_Element_debut");
        }
    };


};

#endif // FILE_H_INCLUDED
