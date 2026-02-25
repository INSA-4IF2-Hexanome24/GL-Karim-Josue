#include "etat3.h"
#include "symboleNT.h"
#include "symbole.h"
#include "automate.h"
#include <iostream>

void Etat3::Transition(Symbole *s, Automate *a) {
   if (s == nullptr || a == nullptr) return;

   switch ((int)*s) {
      case PLUS:
      case MULT:
      case CLOSEPAR:
      case FIN:
         a->Reduire(1, new SymboleE());
         break;
      default:
         break;
   }
}

void Etat3::Affiche() {
   std::cout << "Etat3";
}
