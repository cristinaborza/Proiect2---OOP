#include <bits/stdc++.h>

#include "Graf_complet.h"
#include "NonComplete.h"
#include "SelfLoop.h"
#include "MultipleArrows.h"
#include "NoduriInvalide.h"

using namespace std;

Graf_complet::Graf_complet(): Graf(), nr_muchii(0) {
}

Graf_complet::Graf_complet(int n): Graf(n), nr_muchii(n * (n - 1)) {
}

Graf_complet::Graf_complet(int n, int m): Graf(n), nr_muchii (m) {
}

Graf_complet::~Graf_complet() {
    //cout << "Destructor Graf_complet called\n";
    nr_muchii = 0;
}

Graf_complet::Graf_complet (const Graf_complet &other): Graf(other), nr_muchii(other.nr_muchii) {
}

Graf_complet& Graf_complet::operator = (const Graf_complet &other) {
    Graf::operator=(other);
    nr_muchii = other.nr_muchii;
    return *this;
}

bool Graf_complet::operator==(const Graf_complet &other) {
    if (Graf::operator==(other) == false)
        return false;
    if (nr_muchii != other.nr_muchii)
        return false;
    return true;
}

void Graf_complet::printEdges() {
    int n = this -> Graf::getNoduri();
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            if (i != j) cout << i << " " << j << '\n';
        }
    }

    cout << '\n';
}

void Graf_complet::display() {
    cout << "Elementul este de tipul Graf_complet\n";
}

int Graf_complet::getMuchii() { return nr_muchii; }

istream& operator >>(istream &f, Graf_complet &G) {
    int n, m; f >> n >> m;
    map <pair <int, int>, int> mp;
    bool ok = true;
    for (int i = 1; i <= m; ++ i) {
        int x, y; f >> x >> y;
        mp[{x, y}]++;
        if (x < 1 || x > n || y < 1 || y > n) {
            ok = false;
        }
    }

    if (ok == false) {
        throw (NoduriInvalide());
    }

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            if (i != j && mp[{i, j}] == 0) {
                throw (NonComplete());
            }

            if (i == j && mp[{i, j}] != 0) {
                throw (SelfLoop());
            }

            if (mp[{i, j}] > 1) {
                throw (MultipleArrows ());
            }
        }
    }


    G.setNoduri(n);
    G.nr_muchii = m;

    return f;
}

ostream& operator <<(ostream& g, Graf_complet G) {
    int n = G.Graf::getNoduri();
    g << n << '\n';
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            if (i != j) g << i << " " << j << '\n';
        }
    }

    return g;
}
