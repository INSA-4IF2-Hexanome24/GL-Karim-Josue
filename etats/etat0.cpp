#include "etat0.h"
#include "pile.h"
#include "symboleNT.h"
#include <iostream>

// Implementa las transiciones del estado 0
void Etat0::Transition(Symbole *s, Pile *p) {
   if (s == nullptr || p == nullptr) return;
   
   switch (s->ident) {
      case E:
         // Transición: E -> empilar Etat(1)
         p->Empile(new Etat0()); // Nota: reemplaza con new Etat1() cuando crees esa clase
         break;
      case EPRIM:
         // Transición: EPRIM -> empilar Etat(2)
         p->Empile(new Etat0()); // Nota: reemplaza con new Etat2() cuando crees esa clase
         break;
      default:
         // No hay transición definida para este símbolo
         break;
   }
}

void Etat0::Affiche() {
   std::cout << "Etat0";
}
