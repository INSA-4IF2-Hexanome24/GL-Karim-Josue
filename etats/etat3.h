#pragma once

#include "etat.h"
class Automate;

class Etat3 : public Etat {
public:
    Etat3() : Etat(3) {}
    virtual ~Etat3() {}

    virtual void Affiche() override;
    virtual void Transition(Symbole *s, Automate *a) override;
};
