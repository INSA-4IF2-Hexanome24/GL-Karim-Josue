#include "symboleNT.h"
#include <iostream>

void SymboleNT::Affiche() {
   if (ident >= 0 && ident < 2) {
      cout << EtiquettesNT[ident] << "[" << valeur << "]";
   } else {
      cout << "SymboleNT(?)";
   }
}

int SymboleNT::eval() const {
   return valeur;
}

void SymboleE::Affiche() {
   cout << "E[" << valeur << "]";
}

int SymboleE::eval() const {
   if (leftOperand == nullptr || rightOperand == nullptr) {
      return valeur;
   }

   int left = leftOperand->eval();
   int right = rightOperand->eval();

   switch (operateur) {
      case PLUS:
         return left + right;
      case MULT:
         return left * right;
      default:
         return left;
   }
}

void SymboleE::defineOp(SymboleNT *left, int op, SymboleNT *right) {
   leftOperand = left;
   operateur = op;
   rightOperand = right;
}

void SymboleEPRIM::Affiche() {
   cout << "EPRIM[";
   if (e != nullptr) {
      e->Affiche();
   }
   cout << "]";
}

int SymboleEPRIM::eval() const {
   if (e != nullptr) {
      return e->eval();
   }
   return valeur;
}

void SymboleEPRIM::setE(SymboleE *expression) {
   e = expression;
}
