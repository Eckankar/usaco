/*
ID: eckanka1
PROG: runround
LANG: C++
*/
#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;

int cnt = 0;

bool runround(unsigned long long n) {
    char digits[10];
    char length;

    bool digs[10];
    memset(digs, 0, sizeof(digs));
    digs[0] = true;

    for (length = 0; n > 0; n /= 10, length++) {
        char d = n % 10;
        digits[length] = d;

        if (digs[d]) return false;
        digs[d] = true;
    }


    bool visited[length];
    memset(visited, 0, sizeof(visited));
    visited[length-1] = true;
    int pos = length-1;
    for (int i = 0; i < length-1; i++) {
        pos = (pos - digits[pos]) % length;
        if (pos < 0) pos += length;

        if (visited[pos]) return false;
        visited[pos] = true;
    }

    pos = (pos - digits[pos]) % length;
    if (pos < 0) pos += length;
    return pos == (length - 1);
}

int main() {
    ifstream  fin("runround.in" );
    ofstream fout("runround.out");

    unsigned long long n;
    fin >> n;

    for (n++;; n++) {
        if (!runround(n)) continue;
        fout << n << endl;
        break;
    }
}
