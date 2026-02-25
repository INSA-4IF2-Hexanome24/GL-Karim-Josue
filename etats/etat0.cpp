#include "etat0.h"
#include "pile.h"
#include "symboleNT.h"
#include <iostream>


void Etat0::Transition(Symbole *s, Pile *p) {
   if (s == nullptr || p == nullptr) return;
   
   switch (s->ident) {
      case E:
        
      
         p->Empile(new Etat0()); 
         
         break;
      case EPRIM:
       
      
         p->Empile(new Etat0()); 
         
         break;
      default:
        
      
         break;
   }
}

void Etat0::Affiche() {
   std::cout << "Etat0";
}
