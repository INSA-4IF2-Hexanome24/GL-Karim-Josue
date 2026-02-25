#pragma once

#include "etat.h"
class Automate;

class Etat6 : public Etat {
public:
    Etat6() : Etat(6) {}
    virtual ~Etat6() {}

    virtual void Affiche() override;
    virtual void Transition(Symbole *s, Automate *a) override;
};
