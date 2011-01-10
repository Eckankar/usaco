/*
ID: eckanka1
PROG: nocows
LANG: C++
*/
#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;

int table[201][101];

int calculate(int n, int k) {
    if (table[n][k] != -1) return table[n][k];

    if (n < k || k == 0) {
        table[n][k] = 0;
        return 0;
    }

    int amt = 0;
#define MODAMT 50
#define MODRIGHT 50
    int modAmt = MODAMT, modRight = MODRIGHT;
    for (int i = k-1; i < n-1; i++, modAmt--) {
        // Assume left branch is longer than right branch
        // Calculate how many possibilities there are then
        // Multiply by two 'cause to get right longer than left
        // Then add the case where both are equally long
        int left = calculate(i, k-1);
        int right = 0;
        for (int j = 1; j < k-1; j++, modRight--) {
            right += calculate((n-1)-i, j);
            if (modRight == 0) {
                right %= 9901;
                modRight = MODRIGHT;
            }
        }
        right %= 9901;

        amt += 2 * left * right;
        amt += left * calculate((n-1)-i, k-1);
        if (modAmt == 0) {
            amt %= 9901;
            modAmt = MODAMT;
        }
    }
    amt %= 9901;

    table[n][k] = amt;
    return table[n][k];
}

int main() {
    ifstream  fin("nocows.in" );
    ofstream fout("nocows.out");

    int n, k;
    fin >> n >> k;

    memset(table, -1, sizeof(table));
    table[1][1] = 1;

    fout << calculate(n, k) << endl;
}
