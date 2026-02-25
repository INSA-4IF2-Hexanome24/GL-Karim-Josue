#include "etat0.h"
#include "etat1.h"
#include "etat2.h"
#include "etat3.h"
#include "symboleNT.h"
#include "symbole.h"
#include "automate.h"
#include <iostream>


void Etat0::Transition(Symbole *s, Automate *p) {
   if (s == nullptr || p == nullptr) return;
   
   switch ((int)*s) {
      case INT:
         p->Decaler(s, new Etat3());
         break;
      case OPENPAR:
         p->Decaler(s, new Etat2());
         break;
      case E:
         p->AllerA(s, new Etat1());
         break;
      default:
         break;
   }
}

void Etat0::Affiche() {
   std::cout << "Etat0";
}
