#include "automate.h"
#include "etats/etat0.h"

Automate::Automate(Lexer * l) : lexer(l) {
    pileEtats.push(new Etat0());
}

void Automate::Analyse() {
    Symbole * s = lexer->Consulter();
    int step = 0;
    const int maxSteps = 500;

    while (!accepted) {
        ++step;
        if (step > maxSteps) {
            std::cerr << "[Analyse] stop: max steps atteints (" << maxSteps << ")" << std::endl;
            break;
        }

        Etat * e = pileEtats.top();
       

        e->Transition(s, this);
        s = lexer->Consulter();

        
    }

    if (accepted) {
        std::cerr << "[Analyse] fin: accepte en " << step << " etapes" << std::endl;
    } else {
        std::cerr << "[Analyse] fin: arret sans acceptation" << std::endl;
    }
}
