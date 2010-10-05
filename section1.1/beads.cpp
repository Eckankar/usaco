/*
ID: eckanka1
PROG: beads
LANG: C++
*/
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin("beads.in");
    ofstream fout("beads.out");

    int n;
    string beads;
    fin >> n >> beads;

    int max = 0;

    for (int i = 0; i < n; ++i) {
        char color;
        int offL, offR;
        for (color = '\0', offR = 0; offR < n; ++offR) {
            char b = beads[(i+offR) % n];
            if (b == 'w' || b == color) continue;
            if (color == '\0') {
                color = b;
                continue;
            }
            --offR;
            break;
        }
        for (color = '\0', offL = 1; offL < n; ++offL) {
            char b = beads[(n+i-offL) % n];
            if (b == 'w' || b == color) continue;
            if (color == '\0') {
                color = b;
                continue;
            }
            --offL;
            break;
        }

        if (offL + offR + 1 > max) {
            max = offL + offR + 1;
        }
    }

    if (max > n) max = n;

    fout << max << endl;
}
