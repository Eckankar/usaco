/*
ID: eckanka1
PROG: frac1
LANG: C++
*/
#include <fstream>
#include <cstring>
#include <queue>
#include <utility>

#define MAX_N 160

using namespace std;

int gcdt[MAX_N+1][MAX_N+1];

bool gcd(int a, int b) {
    switch (gcdt[a][b]) {
        case -1: return false;
        case  1: return true;
        case  0:
            if (b == 0) {
                gcdt[a][b] = a == 1;
                return a == 1;
            } else {
                bool res = gcd(b, a % b);
                gcdt[a][b] = res;
                return res;
            }
    }

}

pair<double, pair<int, int> > make_frac(int a, int b) {
    return make_pair(-((double)a)/b, make_pair(a, b));
}

int main() {
    ifstream  fin("frac1.in" );
    ofstream fout("frac1.out");

    int n;
    fin >> n;

    memset(gcdt, 0, sizeof(gcdt));

    priority_queue<pair<double, pair<int, int> > > fractions;

    fractions.push(make_frac(0, 1));
    fractions.push(make_frac(1, 1));

    for (int b = 1; b <= n; b++) {
        for (int a = 1; a < b; a++) {
            if (gcd(a, b)) {
                fractions.push(make_frac(a, b));
            }
        }
    }

    while (!fractions.empty()) {
        pair<int, int> frac = fractions.top().second;
        fout << frac.first << "/" << frac.second << endl;
        fractions.pop();
    }
}
