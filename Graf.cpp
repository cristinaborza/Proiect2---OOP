#include <bits/stdc++.h>

#include "Graf.h"

using namespace std;

Graf::Graf (): nr_noduri(0){
}

Graf::Graf (int n): nr_noduri(n) {
}

Graf::~Graf () {
    //cout << "Destructor Graf called\n";
    nr_noduri = 0;
}

Graf::Graf (const Graf &other) {
    nr_noduri = other.nr_noduri;
}

Graf& Graf::operator = (const Graf &other) {
    nr_noduri = other.nr_noduri;
    return *this;
}

bool Graf:: operator == (const Graf &other) {
    if (nr_noduri != other.nr_noduri)
        return false;
    return true;
}

int Graf::getNoduri() {
    return nr_noduri;
}

void Graf::setNoduri(int x) {
    nr_noduri = x;
}
