/*
ID: eckanka1
PROG: sort3
LANG: C++
*/

#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    ifstream  fin("sort3.in" );
    ofstream fout("sort3.out");

    int n;
    fin >> n;

    int nums[n]; // numbers
    int cnt[3]; // count of each type
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) {
        fin >> nums[i];
        cnt[nums[i]-1]++;
    }

    int pos[3][3]; // pos[i][j] tells how many j's are where an i should be
    memset(pos, 0, sizeof(pos));
    int state = 0;
    for (int i = 0; i < n; i++) {
        if (i == cnt[0] || i == cnt[0]+cnt[1]) state++;
        pos[state][nums[i]-1]++;
    }

    int moves = 0; // number of moves needed.

    // deal with all the straight-forward switches
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < i; j++) {
            int m = min(pos[i][j], pos[j][i]);
            moves += m;
            pos[i][j] -= m;
            pos[j][i] -= m;
        }
    }

    // all there is left is cycles; fixing a cycle takes 2 moves.
    moves += (pos[0][1] + pos[0][2])*2;

    fout << moves << endl;
}
