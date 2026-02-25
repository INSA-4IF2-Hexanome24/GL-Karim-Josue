#pragma once

#include "etat.h"
class Automate;

class Etat8 : public Etat {
public:
    Etat8() : Etat(8) {}
    virtual ~Etat8() {}

    virtual void Affiche() override;
    virtual void Transition(Symbole *s, Automate *a) override;
};
