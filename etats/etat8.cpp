#include "etat8.h"
#include "symboleNT.h"
#include "symbole.h"
#include "automate.h"
#include <iostream>

void Etat8::Transition(Symbole *s, Automate *a) {
if (s == nullptr || a == nullptr) return;

   switch ((int)*s) {
      case PLUS:
         a->Reduire(3, new SymboleE());
         break;
      case MULT:
         a->Reduire(3, new SymboleE());
         break;
      case CLOSEPAR:
         a->Reduire(3, new SymboleE());
         break;
      case FIN:
         a->Reduire(3, new SymboleE());
         break;
      default:
         break;
   }
   
}

void Etat8::Affiche() {
   std::cout << "Etat8";
}
