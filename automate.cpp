#include "automate.h"
#include "etats/etat0.h"

Automate::Automate(Lexer * l) : lexer(l) {
    pileEtats.push(new Etat0());
}

void Automate::Analyse() {
    Symbole * s = lexer->Consulter();
    while (!accepted) {
        if (pileEtats.empty()) {
            std::cerr << "Erreur: pile d'etats vide" << std::endl;
            break;
        }
        Etat * e = pileEtats.top();
        if (!e) break;
        e->Transition(s, this);
        s = lexer->Consulter();
    }
}
