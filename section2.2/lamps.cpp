/*
ID: eckanka1
PROG: lamps
LANG: C++
*/
#include <fstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream  fin("lamps.in" );
    ofstream fout("lamps.out");

    int n, c;
    fin >> n >> c;

    bool lampson[n], lampsoff[n];
    memset(lampson, 0, sizeof(lampson));
    memset(lampsoff, 0, sizeof(lampsoff));

    int num;
    while (fin >> num) {
        if (num == -1) break;
        lampson[num-1] = true;
    }
    while (fin >> num) {
        if (num == -1) break;
        lampsoff[num-1] = true;
    }

    // There aren't that many possibilities for the combinations, so let's
    // compute them first.
    vector<bool> empty(n, false);
    vector< vector<bool> > possibilities(10, empty);
    int pos = 0;

    if (c >= 2 || c == 0) {
        // All lamps on
        for (int i = 0; i < n; i++) {
            possibilities[pos][i] = true;
        }
        ++pos;
    }

    if (c > 0) {
        // odds
        for (int i = 0; i < n; ++i) {
            possibilities[pos][i] = i % 2 == 0;
        }
        ++pos;

        // evens
        for (int i = 0; i < n; ++i) {
            possibilities[pos][i] = i % 2 != 0;
        }
        ++pos;

        // All lamps off
        for (int i = 0; i < n; i++) {
            possibilities[pos][i] = false;
        }
        ++pos;
    }

    if (c == 1 || c >= 3) {
        // negated 3k+1s
        for (int i = 0; i < n; ++i) {
            possibilities[pos][i] = i % 3 != 0;
        }
        ++pos;
    }

    if (c >= 2) {
        // odd + 3k+1s
        for (int i = 0; i < n; ++i) {
            possibilities[pos][i] = true ^ i % 3 == 0 ^ i % 2 == 0;
        }
        ++pos;

        // even + 3k+1s
        for (int i = 0; i < n; ++i) {
            possibilities[pos][i] = true ^ i % 3 == 0 ^ i % 2 != 0;
        }
        ++pos;

        // 3k+1s
        for (int i = 0; i < n; ++i) {
            possibilities[pos][i] = i % 3 == 0;
        }
        ++pos;
    }

    possibilities.erase(possibilities.begin()+pos, possibilities.end());

    for (int i = 0; i < n; i++) {
        if (lampson[i]) {
            for (int j = 0; j < possibilities.size(); j++) {
                if (possibilities[j][i] == 0) {
                    possibilities.erase(possibilities.begin()+j);
                    j--;
                }
            }
        }
        if (lampsoff[i]) {
            for (int j = 0; j < possibilities.size(); j++) {
                if (possibilities[j][i]) {
                    possibilities.erase(possibilities.begin()+j);
                    j--;
                }
            }
        }
    }

    if (possibilities.empty()) {
        fout << "IMPOSSIBLE" << endl;
    }

    vector<string> outputs;
    for (int i = 0; i < possibilities.size(); i++) {
        string s;
        for (int j = 0; j < n; j++) {
            s += (possibilities[i][j] ? "1" : "0");
        }
        outputs.push_back(s);
    }

    sort(outputs.begin(), outputs.end());

    for (int i = 0; i < outputs.size(); i++) {
        fout << outputs[i] << endl;
    }
}
