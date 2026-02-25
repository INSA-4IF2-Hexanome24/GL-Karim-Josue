#pragma once

#include <iostream>
#include "lexer.h"
#include "symbole.h"
#include "symboleNT.h"
#include "etats/etat.h"
#include <stack>
#include <vector>

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

    void Reduire(int regle, Symbole *s) {
        int tailleReduction = 0;

        switch (regle) {
            case 1: // E' -> E
                tailleReduction = 1;
                break;
            case 2: // E -> E + E
                tailleReduction = 3;
                break;
            case 3: // E -> E * E
                tailleReduction = 3;
                break;
            case 4: // E -> ( E )
                tailleReduction = 3;
                break;
            case 5: // E -> val
                tailleReduction = 1;
                break;
            default:
                std::cerr << "Erreur: regle inconnue " << regle << std::endl;
                return;
        }

        if ((int)pileSymbole.size() < tailleReduction || (int)pileEtats.size() < tailleReduction) {
            std::cerr << "Erreur: pile insuffisante pour reduction r" << regle << std::endl;
            return;
        }

        std::vector<Symbole*> symbolesDepiles;
        symbolesDepiles.reserve(tailleReduction);

        for (int i = 0; i < tailleReduction; ++i) {
            symbolesDepiles.push_back(pileSymbole.top());
            pileSymbole.pop();
            pileEtats.pop();
        }

        SymboleNT *resultatNT = dynamic_cast<SymboleNT*>(s);
        if (resultatNT != nullptr) {
            int valeurCalculee = 0;
            switch (regle) {
                case 1: // E' -> E
                    valeurCalculee = symbolesDepiles[0]->eval();
                    break;
                case 2: // E -> E + E
                    valeurCalculee = symbolesDepiles[2]->eval() + symbolesDepiles[0]->eval();
                    break;
                case 3: // E -> E * E
                    valeurCalculee = symbolesDepiles[2]->eval() * symbolesDepiles[0]->eval();
                    break;
                case 4: // E -> ( E )
                    valeurCalculee = symbolesDepiles[1]->eval();
                    break;
                case 5: // E -> val
                    valeurCalculee = symbolesDepiles[0]->eval();
                    break;
                default:
                    break;
            }
            resultatNT->setValeur(valeurCalculee);
        }

        if (pileEtats.empty()) {
            std::cerr << "Erreur: pile d'etats vide apres reduction r" << regle << std::endl;
            return;
        }

        Etat *etatCourant = pileEtats.top();
        if (!etatCourant) {
            std::cerr << "Erreur: etat courant null apres reduction r" << regle << std::endl;
            return;
        }

        etatCourant->Transition(s, this);
    }


    void Accepter() {
        // L'automate accepte l'entrée
        accepted = true;
        if (!pileSymbole.empty()) {
            std::cout << "Accepte ! Resultat = " << pileSymbole.top()->eval() << std::endl;
        } else {
            std::cout << "Accepte !" << std::endl;
        }
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
