#include "automate.h"
#include "etats/etat0.h"

Automate::Automate(Lexer * l) : lexer(l) {
    // Initialiser l'automate avec l'état initial
    pileEtats.push(new Etat0());
}
