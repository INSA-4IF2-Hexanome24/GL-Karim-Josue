#include "etat9.h"
#include "symboleNT.h"
#include "symbole.h"
#include "automate.h"
#include <iostream>

void Etat9::Transition(Symbole *s, Automate *a) {
if (s == nullptr || a == nullptr) return;

   switch ((int)*s) {
      case PLUS:
         a->Reduire(4, new SymboleE());
         break;
      case MULT:
         a->Reduire(4, new SymboleE());
         break;
      case CLOSEPAR:
         a->Reduire(4, new SymboleE());
         break;
      case FIN:
         a->Reduire(4, new SymboleE());
         break;
      default:
         break;
   }
   
}

void Etat9::Affiche() {
   std::cout << "Etat9";
}
