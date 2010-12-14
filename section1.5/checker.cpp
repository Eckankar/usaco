/*
ID: eckanka1
PROG: checker
LANG: C++
*/
#include <fstream>

#define MAX_N 13

using namespace std;

ifstream fin("checker.in");
ofstream fout("checker.out");

int n, cnt;

void nqueens(int r, int queens[MAX_N], bool taken[MAX_N], int blockedup, int blockeddown, bool half, int mid) {
    // Check for valid solution
    if (r == n) {
        if (cnt++ < 3) {
            fout << queens[0]+1;
            for (int i = 1; i < n; i++) {
                fout << " " << queens[i]+1;
            }
            fout << endl;
        }
    }

    // Try to place pieces
    int lim = r == 0 && half ? mid : n;
    for (int i = 0; i < lim; i++) {
        if (taken[i]) continue;

        int pos = 1 << i;
        if (blockedup & pos || blockeddown & pos) continue;

        taken[i] = true;
        queens[r] = i;
        nqueens(r+1, queens, taken, (blockedup | pos) << 1, (blockeddown | pos) >> 1, half, mid);
        taken[i] = false;
    }
}

int main() {
    fin >> n;

    int queens[MAX_N] = {0};
    bool taken[MAX_N] = {0};

    cnt = 0;
    bool half = n > 8;
    nqueens(0, queens, taken, 0, 0, half, n/2);
    if (half) {
        cnt *= 2;
        if (n % 2) {
            queens[0] = n/2;
            taken[queens[0]] = true;
            nqueens(1, queens, taken, 1 << (n/2+1), 1 << (n/2-1), half, n/2);

        }
    }

    fout << cnt << endl;
}
