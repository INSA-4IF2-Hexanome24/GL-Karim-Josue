#include "etat1.h"
#include "etat4.h"
#include "etat5.h"
#include "symbole.h"
#include "automate.h"
#include <iostream>


void Etat1::Transition(Symbole *s, Automate *a) {
    if (s == nullptr || a == nullptr) return;
   
   switch ((int)*s) {
      case PLUS:
         a->Decaler(s, new Etat4());
         break;
      case MULT:
         a->Decaler(s, new Etat5());
         break;
      case FIN:
         a->Accepter();
         break;
      default:
         break;
   }


}

void Etat1::Affiche() {
   std::cout << "Etat1";
}
