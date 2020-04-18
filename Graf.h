#pragma once

#include <bits/stdc++.h>

using namespace std;

class Graf {
    int nr_noduri;
public:
    ///Constructorii
    Graf ();
    Graf (int);

    ///Desctructorii
    virtual ~Graf();

    ///Copy-constructorul
    Graf (const Graf &other);

    /// Operatorii =, ==
    Graf& operator = (const Graf &other);
    bool operator == (const Graf &other);

    virtual void printEdges() = 0;
    virtual void display() = 0;

    int getNoduri();
    void setNoduri(int);
};
