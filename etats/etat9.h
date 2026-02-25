#pragma once

#include "etat.h"
class Automate;

class Etat9 : public Etat {
public:
    Etat9() : Etat(9) {}
    virtual ~Etat9() {}

    virtual void Affiche() override;
    virtual void Transition(Symbole *s, Automate *a) override;
};
