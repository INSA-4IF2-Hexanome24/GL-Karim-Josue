#pragma once

#include "etat.h"
class Automate; 

class Etat1 : public Etat {
public:
    Etat1() : Etat(1) {}
    virtual ~Etat1() {}
    
    virtual void Affiche() override;
    virtual void Transition(Symbole *s, Automate *a) override;
};
