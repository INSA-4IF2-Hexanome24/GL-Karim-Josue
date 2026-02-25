#pragma once

#include <string>
#include "symbole.h"
using namespace std;

enum IdentificateursNT { E, EPRIM };

const string EtiquettesNT[] = { "E", "EPRIM" };


class SymboleNT : public Symbole {
   public:
      SymboleNT(int i) : Symbole(i) {}
      virtual ~SymboleNT() { }
      virtual void Affiche() override;
};
