/*
ID: eckanka1
PROG: zerosum
LANG: C++
*/
#include <fstream>

#define MAX_N 9

using namespace std;

ifstream  fin("zerosum.in" );
ofstream fout("zerosum.out");
char trace[MAX_N-1];

void sums(int cur, int n, int sum, int last, char beforelast) {
    int sumcons;
    switch (beforelast) {
        case '+':
            sumcons = sum + last;
            break;
        case '-':
            sumcons = sum - last;
            break;
    }
    if (cur == n) {
        if (sumcons == 0) {
            fout << '1';
            for (int i = 1; i < n; i++) {
                fout << trace[i-1] << i+1;
            }
            fout << endl;
        }
        return;
    }

    cur++;

    trace[cur-2] = ' ';
    sums(cur, n, sum, 10*last+cur, beforelast);
    trace[cur-2] = '+';
    sums(cur, n, sumcons, cur, '+');
    trace[cur-2] = '-';
    sums(cur, n, sumcons, cur, '-');
}

int main() {
    int n;
    fin >> n;

    char trace[MAX_N-1];
    sums(1, n, 0, 1, '+');
}
