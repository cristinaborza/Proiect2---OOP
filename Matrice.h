#pragma once

#include <bits/stdc++.h>

using namespace std;

class Matrice {
    int **a;
    int rows, cols;
public:
    ///Constructorii
    Matrice ();
    Matrice (int);
    Matrice (int, int);
    Matrice (int, int, int);

    ///Desctructorii
    virtual ~Matrice();

    ///Copy-constructorul
    Matrice (const Matrice &other);

    /// Operatorii =, ==
    Matrice& operator = (const Matrice &other);
    bool operator == (const Matrice &other);
    bool operator != (const Matrice &other);

    /// Citire/ Scriere
    friend istream& operator >> (istream&, Matrice&);
    friend ostream& operator << (ostream&, Matrice);

    int getRows ();
    int getCols ();
    int getElement (int, int);

    void setElement (int, int, int);
};
