#include "etat2.h"
#include "etat3.h"
#include "etat5.h"
#include "etat8.h"
#include "symboleNT.h"
#include "symbole.h"
#include "automate.h"
#include <iostream>

void Etat5::Transition(Symbole *s, Automate *a) {
if (s == nullptr || a == nullptr) return;

   switch ((int)*s) {
      case INT:
         a->Decaler(s, new Etat3());
         break;
      case OPENPAR:
         a->Decaler(s, new Etat2());
         break;
      case E:
         a->AllerA(s, new Etat8());
         break;
      default:
         break;
   }

}

void Etat5::Affiche() {
   std::cout << "Etat5";
}
