#pragma once

#include "etat.h"
class Automate;

class Etat4 : public Etat {
public:
    Etat4() : Etat(4) {}
    virtual ~Etat4() {}

    virtual void Affiche() override;
    virtual void Transition(Symbole *s, Automate *a) override;
};
