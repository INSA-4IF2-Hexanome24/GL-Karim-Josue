#include "etat.h"
#include <iostream>

void Etat::Affiche() {
   std::cout << "Etat(" << ident << ")";
}

void Transition::Affiche() {
   Symbole::Affiche();
   std::cout << "(" << valeur << ")";
}