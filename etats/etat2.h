#pragma once

#include "etat.h"
class Automate;

class Etat2 : public Etat {
public:
    Etat2() : Etat(2) {}
    virtual ~Etat2() {}

    virtual void Affiche() override;
    virtual void Transition(Symbole *s, Automate *a) override;
};
