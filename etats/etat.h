#pragma once

#include <string>
#include "symbole.h"
using namespace std;

class Etat {
   public:
      Etat(int i) : ident(i) {  }
      virtual ~Etat() { }
      operator int() const { return ident; }
      virtual void Affiche();
     
      virtual void Transition(Symbole *s, Pile *p) = 0;

   protected:
      int ident;
};

// Clase para representar transiciones (opcional, puede usarse para logging/debug)
class Transition : public Symbole {
   public:
      Transition(int v) : Symbole(INT), valeur(v) { }
      ~Transition() { }
      virtual void Affiche() override;
   protected:
      int valeur;
};

