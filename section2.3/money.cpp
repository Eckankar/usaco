/*
ID: eckanka1
PROG: money
LANG: C++
*/
#include <fstream>
#include <algorithm>
#include <cstring>

#define MAX_V 25
#define MAX_N 10000
#define dong long

using namespace std;

int coins[MAX_V];
long dong table[MAX_V+1][MAX_N+1];

long dong count(int n, int v) {
    if (table[v][n] != -1) {
        return table[v][n];
    }

    if (coins[v-1] > n) {
        table[v][n] = count(n, v-1);
        return table[v][n];
    }

    long dong res = count(n-coins[v-1], v) + count(n, v-1);
    table[v][n] = res;
    return res;
}

int main() {
    ifstream  fin("money.in" );
    ofstream fout("money.out");

    int v, n;
    fin >> v >> n;

    for (int i = 0; i < v; i++) {
        fin >> coins[i];
    }

    sort(coins, coins + v);

    memset(table, -1, sizeof(table));

    memset(table[0], 0, sizeof(table[0]));
    for (int i = 0; i < v; i++) {
        table[i][0] = 1;
    }

    for (int i = 1; i < n; i++) {
        count(i, v);
    }

    fout << count(n, v) << endl;
}

