#pragma once

#include <bits/stdc++.h>

#include "Graf.h"

using namespace std;

class Graf_complet: public virtual Graf {
    int nr_muchii;
public:
    ///Constructorii
    Graf_complet();
    Graf_complet(int);
    Graf_complet(int, int);

    ///Destructorul
    virtual ~Graf_complet();

    ///Copy-constructorul
    Graf_complet (const Graf_complet &other);

    ///Operatorii =, ==
    Graf_complet& operator = (const Graf_complet &other);
    bool operator == (const Graf_complet &other);

    ///Citire / scriere
    friend istream& operator >> (istream&, Graf_complet&);
    friend ostream& operator << (ostream&, Graf_complet);

    virtual void printEdges();
    virtual void display();

    int getMuchii ();
};
