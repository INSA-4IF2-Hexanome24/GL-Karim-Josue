#pragma once

#include "etat.h"
class Automate;  // Forward declaration

class Etat0 : public Etat {
public:
    Etat0() : Etat(0) {}
    virtual ~Etat0() {}
    
    virtual void Affiche() override;
    virtual void Transition(Symbole *s, Automate *a) override;
};
