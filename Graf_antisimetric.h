#pragma once

#include <bits/stdc++.h>

#include "Matrice.h"
#include "Graf.h"

class Graf_antisimetric: public virtual Graf {
    Matrice adia;
public:
    ///Constructoii
    Graf_antisimetric();
    Graf_antisimetric(Matrice);
    Graf_antisimetric(int, Matrice);

    ///Destructorul
    virtual ~Graf_antisimetric();

    ///Copy-constructorul
    Graf_antisimetric (const Graf_antisimetric &other);

    ///Operatorii =, ==
    Graf_antisimetric& operator = (const Graf_antisimetric &other);
    bool operator == (const Graf_antisimetric &other);

    ///Citire / scriere
    friend istream& operator >>(istream&, Graf_antisimetric&);
    friend ostream& operator <<(ostream&, Graf_antisimetric);

    int getElement(int, int);
    Matrice getAdia ();

    virtual void printEdges();
    virtual void display();
};
