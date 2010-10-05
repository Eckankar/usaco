/*
ID: eckanka1
PROG: transform
LANG: C++
*/
#include <fstream>
#include <iostream>

using namespace std;

const int MAX_N = 11;

void rotate(char orig[MAX_N][MAX_N], int n) {
    char copy[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            copy[i][j] = orig[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            orig[j][n-i-1] = copy[i][j];
        }
    }
}

void reflect(char orig[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n/2; j++) {
            swap(orig[i][j], orig[i][n-j-1]);
        }
    }
}

bool compare(char orig[MAX_N][MAX_N], char trans[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (orig[i][j] != trans[i][j]) return false;
    return true;
}

int main() {
    ifstream fin("transform.in");
    ofstream fout("transform.out");

    int n;
    fin >> n;

    char orig[MAX_N][MAX_N];
    char trans[MAX_N][MAX_N];

    for (int i = 0; i < n; i++)
        fin >> orig[i];
    for (int i = 0; i < n; i++)
        fin >> trans[i];

    rotate(orig, n);
    if (compare(orig, trans, n)) {
        fout << 1 << endl;
        return 0;
    }

    rotate(orig, n);
    if (compare(orig, trans, n)) {
        fout << 2 << endl;
        return 0;
    }

    rotate(orig, n);
    if (compare(orig, trans, n)) {
        fout << 3 << endl;
        return 0;
    }

    rotate(orig, n);
    reflect(orig, n);
    if (compare(orig, trans, n)) {
        fout << 4 << endl;
        return 0;
    }

    bool combo = false;
    rotate(orig, n);
    combo |= compare(orig, trans, n);

    rotate(orig, n);
    combo |= compare(orig, trans, n);

    rotate(orig, n);
    combo |= compare(orig, trans, n);

    if (combo) {
        fout << 5 << endl;
        return 0;
    }

    rotate(orig, n);
    reflect(orig, n);
    if (compare(orig, trans, n)) {
        fout << 6 << endl;
        return 0;
    }
    fout << 7 << endl;
}

