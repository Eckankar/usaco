/*
ID: eckanka1
PROG: concom
LANG: C++
*/
#include <fstream>
#include <cstring>

// maximum amount of companies 
#define MAX_C 101

bool control[MAX_C][MAX_C];
int own[MAX_C][MAX_C];

using namespace std;

void give_control(int i, int j) {
    if (control[i][j]) return;

    control[i][j] = true;

    for (int c = 0; c < MAX_C; c++) {
        own[i][c] += own[j][c];
    }

    for (int c = 0; c < MAX_C; c++) {
        if (control[c][i]) {
            give_control(c, j);
        }
    }

    for (int c = 0; c < MAX_C; c++) {
        if (own[i][c] > 50) {
            give_control(i, c);
        }
    }
}

void give_shares(int i, int j, int p) {
    for (int c = 0; c < MAX_C; c++) {
        if (control[c][i]) {
            own[c][j] += p;
        }
    }

    for (int c = 0; c < MAX_C; c++) {
        if (own[c][j] > 50) {
            give_control(c, j);
        }
    }
}

int main() {
    ifstream  fin("concom.in" );
    ofstream fout("concom.out");

    memset(control, 0, sizeof(control));
    memset(own, 0, sizeof(own));

    for (int c = 0; c < MAX_C; c++) {
        control[c][c] = true;
    }

    int n;
    fin >> n;

    while (n --> 0) {
        int i, j, p;
        fin >> i >> j >> p;

        give_shares(i, j, p);
    }

    for (int i = 1; i < MAX_C; i++) {
        for (int j = 1; j < MAX_C; j++) {
            if (i==j) continue;

            if (control[i][j]) {
                fout << i << " " << j << endl;
            }
        }
    }
}

