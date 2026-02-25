#include <stack>
#include "symbole.h"
using namespace std;

class Pile {
   public:
      Pile();
      void Empiler(Symbole *s);
      void Depiler();
      Symbole *Sommet();
      int Taille();
   private:
      stack<Symbole*> pile;
};
