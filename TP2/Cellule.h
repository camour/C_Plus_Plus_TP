#ifndef CELLULE_H_INCLUDED
#define CELLULE_H_INCLUDED
#include <iostream>
#include <string>
#include "Cellule.h"


// Toujours definir les fonctions templates dans le .h, oui je parle bien de leur corps , bon ici yen a pas mais faut le savoir
template<typename T> class Cellule {

public :
    Cellule<T> * next_cellule;
    T element;
public:
    Cellule (){next_cellule = NULL;}
    Cellule (T const &elem){(*this).element = elem; (*this).next_cellule=NULL;}
   // friend File<T> ; // Pas besoin du File :: File, en effet car on ne cherche pas quelque chose qui est dans la classe File!
    };

#endif // CELLULE_H_INCLUDED
