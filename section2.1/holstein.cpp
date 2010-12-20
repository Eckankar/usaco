/*
ID: eckanka1
PROG: holstein
LANG: C++
*/

#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;

int main() {
    ifstream  fin("holstein.in" );
    ofstream fout("holstein.out");

    int v;
    fin >> v;

    int req[v]; // vitamin requirements
    for (int i = 0; i < v; ++i) {
        fin >> req[i];
    }

    int g;
    fin >> g;

    int combos[1 << g][v]; // feed combinations
    memset(combos, 0, sizeof(combos));

    int bestCnt = 1000;
    ostringstream best;

    for (int i = 0; i < g; i++) {
        int feed[v];
        for (int j = 0; j < v; j++) {
            fin >> feed[j];
        }

        int feedmask = 1 << i;
        for (int j = 0; j < feedmask; ++j) {
            int target = j | feedmask;
            bool satisfied = true;
            for (int k = 0; k < v; k++) {
                combos[target][k] = combos[j][k] + feed[k];
                satisfied &= combos[target][k] >= req[k];
            }

            if (satisfied) {
                int cnt = 0;
                for (int tmp = target; tmp != 0; tmp >>= 1) {
                    if (tmp & 1) cnt++;
                }

                if (cnt < bestCnt) {
                    bestCnt = cnt;
                    best.str("");
                    best << cnt;
                    for (int i = 1; target != 0; target >>= 1, i++) {
                        if (target & 1) best << " " << i;
                    }
                }
            }
        }
    }

    fout << best.str() << endl;

}
