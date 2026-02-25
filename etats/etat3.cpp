#include "etat3.h"
#include "symboleNT.h"
#include "symbole.h"
#include "automate.h"
#include <iostream>

void Etat3::Transition(Symbole *s, Automate *a) {
   if (s == nullptr || a == nullptr) return;

   switch ((int)*s) {
      case PLUS:
         a->Reduire(5, new SymboleE());
         break;

      case MULT:
      a->Reduire(5, new SymboleE());
         break;
      case CLOSEPAR:
      a->Reduire(5, new SymboleE());
         break;
      case FIN:
         a->Reduire(5, new SymboleE());
         break;
      default:
         break;
   }
}

void Etat3::Affiche() {
   std::cout << "Etat3";
}
