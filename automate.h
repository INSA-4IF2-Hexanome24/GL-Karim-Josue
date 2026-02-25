#pragma once

#include <iostream>
#include "lexer.h"
#include "symbole.h"
#include "etats/etat.h"
#include <stack>

using namespace std;

class Automate {
    public:
    
    Automate(Lexer * l);
    
    void Decaler(Symbole *s, Etat *e) {
        // Empiler le symbole et l'état correspondant
        pileSymbole.push(s);
        pileEtats.push(e);
        lexer->Avancer(); // Avancer le lexer pour lire le prochain symbole
    }

    void AllerA(Symbole *s, Etat *e) {
        // Transition sur non-terminal (goto) : ne pas avancer le lexer
        pileSymbole.push(s);
        pileEtats.push(e);
    }

    void Reduire(int n, Symbole *s) {
        // Dépiler les n derniers symboles et états
        for (int i = 0; i < n; ++i) {
            pileSymbole.pop();
            pileEtats.pop();
        }
        // Empiler le symbole résultant de la réduction
        pileSymbole.push(s);
    }


    void Accepter() {
        // L'automate accepte l'entrée
        accepted = true;
        std::cout << "Accepté!" << std::endl;
    }
    
    
    private:
    Lexer * lexer;
    stack<Symbole *> pileSymbole;
    stack<Etat *> pileEtats;
 bool accepted = false;

    public:
    // Lance l'analyse complète jusqu'à Acceptation ou erreur
    void Analyse();

};
