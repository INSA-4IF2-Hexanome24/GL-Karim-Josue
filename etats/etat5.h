#pragma once

#include "etat.h"
class Automate;

class Etat5 : public Etat {
public:
    Etat5() : Etat(5) {}
    virtual ~Etat5() {}

    virtual void Affiche() override;
    virtual void Transition(Symbole *s, Automate *a) override;
};
