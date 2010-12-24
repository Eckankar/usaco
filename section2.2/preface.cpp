/*
ID: eckanka1
PROG: preface
LANG: C++
*/
#include <fstream>

/**
 * Numbers:
 *  I = 1
 *  V = 5
 *  X = 10
 *  L = 50
 *  C = 100
 *  D = 500
 *  M = 1000
 */


using namespace std;

struct count {
    unsigned int i, v, x, l, c, d, m;
};

void count_roman(count &cnt, int n) {
    // Thousands
    cnt.m += n / 1000;
    n %= 1000;

    // Hundreds
    int hundred = n / 100;
    switch (hundred) {
        case 4:
            cnt.c++; cnt.d++; break;
        case 9:
            cnt.c++; cnt.m++; break;
        case 5: case 6: case 7: case 8:
            cnt.d++;
        case 0: case 1: case 2: case 3:
            cnt.c += hundred % 5;
    }
    n %= 100;

    // Tens
    int ten = n / 10;
    switch (ten) {
        case 4:
            cnt.x++; cnt.l++; break;
        case 9:
            cnt.x++; cnt.c++; break;
        case 5: case 6: case 7: case 8:
            cnt.l++;
        case 0: case 1: case 2: case 3:
            cnt.x += ten % 5;
    }
    n %= 10;

    // Ones
    switch (n) {
        case 4:
            cnt.i++; cnt.v++; break;
        case 9:
            cnt.i++; cnt.x++; break;
        case 5: case 6: case 7: case 8:
            cnt.v++;
        case 0: case 1: case 2: case 3:
            cnt.i += n % 5;
    }
}

int main() {
    ifstream  fin("preface.in" );
    ofstream fout("preface.out");

    int n;
    fin >> n;

    count cnt;
    cnt.i = 0; cnt.v = 0;
    cnt.x = 0; cnt.l = 0;
    cnt.c = 0; cnt.d = 0;
    cnt.m = 0;

    for (int i = 1; i <= n; ++i) {
        count_roman(cnt, i);
    }

    if (cnt.i != 0) fout << "I " << cnt.i << endl;
    if (cnt.v != 0) fout << "V " << cnt.v << endl;
    if (cnt.x != 0) fout << "X " << cnt.x << endl;
    if (cnt.l != 0) fout << "L " << cnt.l << endl;
    if (cnt.c != 0) fout << "C " << cnt.c << endl;
    if (cnt.d != 0) fout << "D " << cnt.d << endl;
    if (cnt.m != 0) fout << "M " << cnt.m << endl;
}
