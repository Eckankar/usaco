/*
ID: eckanka1
PROG: ariprog
LANG: C++
*/

#include <fstream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    int n, m;
    fin >> n >> m;

    // Our sum of two squares cannot be larger than this.
    int biLimit = 2 * m * m;

    // Build table of squares
    bool bsq[biLimit + 1];
    memset(bsq, 0, sizeof(bsq));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= i; j++) {
            bsq[i*i + j*j] = true;
        }
    }

    // Store progressions as a tuple (diff, start)
    vector< pair<int, int> > progs;

    for (int i = 0; i < biLimit; i++) {
        if (!bsq[i]) continue;

        // Only check the cases that're within the bounds of our
        // largest sum of squares.
        int maxDiff = (biLimit - i) / (n-1);

        // Check sequences; add to progs if successful.
        for (int diff = 1; diff <= maxDiff; diff++) {
            bool seqWorks = true;
            for (int b = 1; seqWorks && b < n; b++) {
                seqWorks = bsq[i + b*diff];
            }
            if (seqWorks) {
                progs.push_back( make_pair( diff, i ) );
            }
        }
    }

    // Sorted lexicographically, our vector of progressions
    // gives us the output in the correct order
    sort(progs.begin(), progs.end());

    for (int i = 0; i < progs.size(); i++) {
        pair<int, int> prog = progs[i];
        fout << prog.second << " " << prog.first << endl;
    }

    if (progs.empty()) {
        fout << "NONE" << endl;
    }
}

