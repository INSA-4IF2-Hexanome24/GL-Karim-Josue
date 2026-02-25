#include "symbole.h"
#include <iostream>
#include "etat.h"

void Etat::Transition(Symbole *s, Pile *p) {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}