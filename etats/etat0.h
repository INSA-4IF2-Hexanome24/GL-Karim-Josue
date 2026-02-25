#pragma once

#include "etat.h"

class Etat0 : public Etat {
public:
    Etat0() : Etat(0) {}
    virtual ~Etat0() {}
    
    virtual void Affiche() override;
    virtual void Transition(Symbole *s, Pile *p) override;
};
