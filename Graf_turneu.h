#pragma once

#include <bits/stdc++.h>

#include "Graf_antisimetric.h"
#include "Graf_complet.h"

using namespace std;

class Graf_turneu: public Graf_complet, public Graf_antisimetric {
public:
    ///Constructorul
    Graf_turneu();
    Graf_turneu(int, Matrice);

    ///Desctructorul
    virtual ~Graf_turneu();

    ///Copy-constructorul
    Graf_turneu (const Graf_turneu &other);

    ///Operatorii =, ==
    Graf_turneu& operator = (const Graf_turneu &other);

    /// Citire/ scriere
    friend istream& operator >>(istream&, Graf_turneu&);
    friend ostream& operator <<(ostream&, Graf_turneu);

    void printEdges();
    void display();

};
