#include <bits/stdc++.h>

#include "Graf_turneu.h"
#include "NonComplete.h"

using namespace std;

Graf_turneu::Graf_turneu(): Graf(), Graf_complet(), Graf_antisimetric() {
}

Graf_turneu::Graf_turneu(int n, Matrice adia): Graf(n), Graf_complet(n), Graf_antisimetric(adia) {
}

Graf_turneu::~Graf_turneu() {
    //cout << "Destructor graf_turneu called\n";
}

Graf_turneu::Graf_turneu (const Graf_turneu &other): Graf(other), Graf_complet(other), Graf_antisimetric(other) {
}

Graf_turneu& Graf_turneu::operator= (const Graf_turneu &other) {
    this -> Graf_complet::operator=(other);
    this -> Graf_antisimetric::operator=(other);
    return *this;
}

void Graf_turneu::printEdges () {
    Graf_antisimetric::printEdges();
}

void Graf_turneu::display() {
    cout << "Elementul este de tip Graf_turneu\n";
}

istream& operator >>(istream &f, Graf_turneu &G) {
    Graf_antisimetric aux;
    f >> aux;

    int n = aux.getNoduri(), m = 0;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            if (aux.getElement(i, j) != 0) {
                m += 2;
            }
        }
    }

    if (m != n * (n - 1)) {
        throw (NonComplete());
    }

    Graf_turneu ans(n, aux.getAdia());
    G = ans;
    return f;
}

ostream& operator <<(ostream &g, Graf_turneu G) {
    int n = G.getNoduri();
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            if (G.getElement(i, j)) {
                g << i << " " << j << '\n';
            }
        }
    }

    return g;
}
