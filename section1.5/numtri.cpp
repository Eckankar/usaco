/*
ID: eckanka1
PROG: numtri
LANG: C++
*/
#include <fstream>
#include <cstring>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int main() {
    ifstream  fin("numtri.in" );
    ofstream fout("numtri.out");

    int n;
    fin >> n;
    int table[n+1][n+1];
    int m = 0;

    memset(table, 0, sizeof(table));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int num;
            fin >> num;
            table[i][j] = MAX(table[i-1][j], table[i-1][j-1]) + num;
            m = MAX(m, table[i][j]);
        }
    }

    fout << m << endl;
}
