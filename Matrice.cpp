#include <bits/stdc++.h>

#include "Matrice.h"
#include "depDim.h"

using namespace std;

Matrice::Matrice() {
    rows = 0;
    cols = 0;
    a = new int*[rows + 1];
    for (int i = 1; i <= rows; ++ i) {
        a[i] = new int[cols + 1];
    }

    for (int i = 1; i <= rows; ++ i) {
        for (int j = 1; j <= cols; ++ j) {
            a[i][j] = 0;
        }
    }
}

Matrice::Matrice (int n) {
    rows = n;
    cols = n;
    a = new int*[rows + 1];
    for (int i = 1; i <=  rows; ++ i) {
        a[i] = new int[cols + 1];
    }

    for (int i = 1; i <= rows; ++ i) {
        for (int j = 1; j <= cols; ++ j) {
            a[i][j] = 0;
        }
    }
}

Matrice::Matrice(int n, int m) {
    rows = n;
    cols = m;
    a = new int*[rows + 1];
    for (int i = 1; i <=  rows; ++ i) {
        a[i] = new int[cols + 1];
    }

    for (int i = 1; i <= rows; ++ i) {
        for (int j = 1; j <= cols; ++ j) {
            a[i][j] = 0;
        }
    }
}

Matrice::Matrice(int n, int m, int x) {
    rows = n;
    cols = m;
    a = new int*[rows + 1];
    for (int i = 1; i <=  rows; ++ i) {
        a[i] = new int[cols + 1];
    }

    for (int i = 1; i <= rows; ++ i) {
        for (int j = 1; j <= cols; ++ j) {
            a[i][j] = x;
        }
    }
}

Matrice::~Matrice() {
    for (int i = 1; i <= rows; ++ i) {
        delete[] a[i];
    }

    delete []a;
    rows = 0;
    cols = 0;

    //cout << "Destructor Matrice called\n";
}

Matrice::Matrice (const Matrice &other) {
    rows = other.rows;
    cols = other.cols;

    a = new int*[rows + 1];
    for (int i = 1; i <= rows; ++ i) {
        a[i] = new int[cols + 1];
    }

    for (int i = 1; i <= rows; ++ i) {
        for (int j = 1; j <= cols; ++ j) {
            a[i][j] = other.a[i][j];
        }
    }
}

Matrice& Matrice::operator = (const Matrice &other) {
    rows = other.rows;
    cols = other.cols;

    a = new int*[rows + 1];
    for (int i = 1; i <= rows; ++ i) {
        a[i] = new int[cols + 1];
    }

    for (int i = 1; i <= rows; ++ i) {
        for (int j = 1; j <= cols; ++ j) {
            a[i][j] = other.a[i][j];
        }
    }

    return *this;
}

bool Matrice::operator == (const Matrice &other) {
    if (rows != other.rows)
        return false;
    if (cols != other.cols)
        return false;

    for (int i = 1; i <= rows; ++ i) {
        for (int j = 1; j <= cols; ++ j) {
            if (a[i][j] != other.a[i][j])
                return false;
        }
    }

    return true;
}

bool Matrice::operator!= (const Matrice &other) {
    if ((*this) == other)
        return false;
    return true;
}

int Matrice::getRows () { return rows; }
int Matrice::getCols () { return cols; }
int Matrice::getElement (int x, int y) { return a[x][y]; }
void Matrice::setElement (int x, int y, int value) { a[x][y] = value; }

istream& operator >>(istream &f, Matrice& M) {
    int n, m; f >> n >> m;

    Matrice aux(n, m);
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            int x; f >> x;
            aux.a[i][j] = x;

        }
    }

    M = aux;
    return f;
}

ostream& operator <<(ostream &g, Matrice M) {
    g << M.rows << " " << M.cols << '\n';
    for (int i = 1; i <= M.rows; ++ i) {
        for (int j = 1; j <= M.cols; ++ j) {
            g << M.a[i][j] << " ";
        }

        g << '\n';
    }

    return g;
}
