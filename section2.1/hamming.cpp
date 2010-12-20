/*
ID: eckanka1
PROG: hamming
LANG: C++
*/
#include <fstream>
#include <cstdio>

#define MAX_N 64
#define MAX_B 8
#define MAX_D 7

using namespace std;

int n, b, d;
int lim;
int nums[MAX_N];

// Verify that a and b have a Hamming distance of at least d.
bool verify(int a, int b) {
    int dist = 0;
    for (int diff = a^b; diff != 0; diff >>= 1) {
        if (diff & 1) dist++;
    }
    return dist >= d;
}

bool dfs(int cur, int amt) {
    // Check that suggestion doesn't break any of our previous numbers
    for (int i = 0; i < amt; ++i) {
        if (!verify(cur, nums[i])) return false;
    }

    // Add suggestion to list of numbers
    nums[amt++] = cur;

    // Are we done?
    if (amt == n) return true;

    // If not, try to find more
    for (int i = cur+1; i < lim; ++i) {
        if (dfs(i, amt)) return true;
    }

    // Nothing found, back up a level
    return false;
}

int main() {
    ifstream  fin("hamming.in" );
    ofstream fout("hamming.out");

    fin >> n >> b >> d;
    lim = 1 << b;

    // Guess on the first number and try to search for more
    for (int i = 0; i < lim; ++i) {
        if (dfs(i, 0)) break;
    }

    // Print out results, 10 per line
    for (int i = 0; i < n; i++) {
        if (i != 0 && i % 10 == 0)
            fout << endl;
        else if (i != 0)
            fout << " ";

        fout << nums[i];
    }
    fout << endl;
}
