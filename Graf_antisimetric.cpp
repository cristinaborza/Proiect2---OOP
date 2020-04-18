#include <bits/stdc++.h>

#include "Graf_antisimetric.h"
#include "NonAntisimetric.h"

using namespace std;

Graf_antisimetric::Graf_antisimetric (): Graf(), adia(){
}

Graf_antisimetric::Graf_antisimetric (Matrice m): Graf(), adia(m){
}

Graf_antisimetric::Graf_antisimetric (int n, Matrice m): Graf(n), adia(m){
}


Graf_antisimetric::~Graf_antisimetric () {
    //cout << "Destructor Graf_antisimetric called\n";
}

Graf_antisimetric::Graf_antisimetric (const Graf_antisimetric &other): Graf(other), adia(other.adia){
}

Graf_antisimetric& Graf_antisimetric::operator= (const Graf_antisimetric &other) {
    this -> Graf::operator=(other);
    adia = other.adia;
    return *this;
}

bool Graf_antisimetric::operator == (const Graf_antisimetric &other) {
    if (Graf::operator==(other) == false)
        return false;
    if (adia != other.adia)
        return false;
    return true;
}

int Graf_antisimetric::getElement (int i, int j) {
    return adia.getElement(i, j);
}

Matrice Graf_antisimetric::getAdia() { return adia; }

void Graf_antisimetric::printEdges() {
    int n = adia.getRows();
    int m = adia.getCols();

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            if (adia.getElement(i, j)) {
                cout << i << " " << j << '\n';
            }
        }
    }

    cout << '\n';
}

void Graf_antisimetric::display() {
    cout << "Elementul este de tipul graf_antisimetric\n";
}

istream& operator >>(istream& f, Graf_antisimetric &G) {
    int n; f >> n;

    map <pair <int, int>, bool> mp;
    Matrice m(n);
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            int x; f >> x;
            m.setElement(i, j, x);

            if (x) {
                mp[{i, j}] = true;
            }
        }
    }

    for (int i = 1; i <= n; ++ i) {
        for (int j = i; j <= n; ++ j) {
            if (mp[{i, j}] == true && mp[{j, i}] == true) {
                throw (NonAntisimetric());
            }
        }
    }

    G.adia = m;
    G.setNoduri(n);

    return f;
}

ostream& operator <<(ostream& g, Graf_antisimetric G) {
    int n = G.adia.getRows();
    int m = G.adia.getCols();
    vector <pair <int, int> > Arrows;

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            if (G.adia.getElement(i, j)) {
                Arrows.push_back ({i, j});
            }
        }
    }

    for (auto it: Arrows) {
        g << it.first << " " << it.second << '\n';
    }

    return g;
}
