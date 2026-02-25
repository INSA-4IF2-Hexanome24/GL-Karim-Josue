#include "symboleNT.h"
#include <iostream>

void SymboleNT::Affiche() {
   if (ident >= 0 && ident < 2) {
      cout << EtiquettesNT[ident];
   } else {
      cout << "SymboleNT(?)";
   }
}
