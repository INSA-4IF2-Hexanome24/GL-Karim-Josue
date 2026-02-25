#include "etat7.h"
#include "etat5.h"
#include "symboleNT.h"
#include "symbole.h"
#include "automate.h"
#include <iostream>

void Etat7::Transition(Symbole *s, Automate *a) {
if (s == nullptr || a == nullptr) return;

   switch ((int)*s) {
      case PLUS:
         a->Reduire(2, new SymboleE());
         break;
      case MULT:
         a->Decaler(s, new Etat5());
         break;
      case CLOSEPAR:
         a->Reduire(2, new SymboleE());
         break;
      case FIN:
         a->Reduire(2, new SymboleE());
         break;
      default:
         break;
   }

}

void Etat7::Affiche() {
   std::cout << "Etat7";
}
