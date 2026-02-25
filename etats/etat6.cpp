#include "etat6.h"
#include "etat5.h"
#include "etat4.h"
#include "etat9.h"
#include "symboleNT.h"
#include "symbole.h"
#include "automate.h"
#include <iostream>

void Etat6::Transition(Symbole *s, Automate *a) {
if (s == nullptr || a == nullptr) return;

   switch ((int)*s) {
      case PLUS:
         a->Decaler(s, new Etat4());
         break;
      case MULT:
         a->Decaler(s, new Etat5());
         break;
      case CLOSEPAR:
         a->Decaler(s, new Etat9());
         break;
      default:
         break;
   }
}

void Etat6::Affiche() {
   std::cout << "Etat6";
}
