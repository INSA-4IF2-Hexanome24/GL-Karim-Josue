#pragma once

#include "etat.h"
class Automate;

class Etat7 : public Etat {
public:
    Etat7() : Etat(7) {}
    virtual ~Etat7() {}

    virtual void Affiche() override;
    virtual void Transition(Symbole *s, Automate *a) override;
};
