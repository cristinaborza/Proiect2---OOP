#include <bits/stdc++.h>

#include "Matrice.h"
#include "Graf.h"
#include "Graf_complet.h"
#include "Graf_antisimetric.h"
#include "Graf_turneu.h"

using namespace std;

int main() {
    vector <Graf*> v;
    int n; cin >> n;

    for (int i = 1; i <= n; ++ i) {
        int type; cin >> type;
        if (type == 1) {
            Graf_complet *G = new Graf_complet;
            try {
                cin >> (*G);
                v.push_back (G);
            } catch(exception &e){
                cout << e.what() << '\n';
            }
        }

        if (type == 2) {
            Graf_antisimetric *G = new Graf_antisimetric;
            try {
                cin >> (*G);
                v.push_back (G);
            } catch (exception &e) {
                cout << e.what() << '\n';
            }
        }

        if (type == 3) {
            Graf_turneu *G = new Graf_turneu;
            try {
                cin >> (*G);
                v.push_back (G);
            } catch (exception &e) {
                cout << e.what() << '\n';
            }
        }
    }

    for (int i = 0; i < (int)v.size(); ++ i) {
        v[i] -> display();
        v[i] -> printEdges();
    }

    for (int i = v.size() - 1; i >= 0; -- i) {
        delete v[i];
    }
    return 0;
}
