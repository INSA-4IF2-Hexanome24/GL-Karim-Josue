#pragma once

#include <string>
#include "symbole.h"
using namespace std;

enum IdentificateursNT { E, EPRIM };

const string EtiquettesNT[] = { "E", "EPRIM" };


class SymboleNT : public Symbole {
   public:
      SymboleNT(int i, int v = 0) : Symbole(i), valeur(v) {}
      virtual ~SymboleNT() { }
      
      virtual void Affiche() override;
      
      virtual int eval() const;
      
    
      void setValeur(int v) { valeur = v; }
   
      int getValeur() const { return valeur; }

   protected:
      int valeur; 
};

class SymboleE : public SymboleNT {
   public:
      SymboleE(int v = 0) : SymboleNT(E, v), leftOperand(nullptr), rightOperand(nullptr), operateur(ERREUR) {}
      virtual ~SymboleE() { }

      virtual void Affiche() override;
      virtual int eval() const override;

      void defineOp(SymboleNT *left, int op, SymboleNT *right);

   private:
      SymboleNT *leftOperand;
      SymboleNT *rightOperand;
      int operateur;
};

class SymboleEPRIM : public SymboleNT {
   public:
      SymboleEPRIM(SymboleE *e  = nullptr) : SymboleNT(EPRIM, 0), e(e) {}
      virtual ~SymboleEPRIM() { }

      virtual void Affiche() override;
      virtual int eval() const override;

      void setE(SymboleE *expression);

   private:
      SymboleE *e;
};
