#include "automate.h"
#include "etats/etat0.h"

Automate::Automate(Lexer * l) : lexer(l) {
    pileEtats.push(new Etat0());
}
