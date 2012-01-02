/*
ID: eckanka1
PROG: fracdec
LANG: C++
*/
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    ifstream  fin("fracdec.in" );
    ofstream fout("fracdec.out");

    int n, d;
    fin >> n >> d;

    fout << n / d << '.';
    n = n % d;

    if (n == 0) {
        fout << 0 << endl;
        return 0;
    }

    int w = fout.tellp();

    vector<int> digits;
    int remainders[d];
    int startGroup;
    int pos = 0;
    memset(remainders, -1, sizeof(remainders));

    while (n != 0) {
        digits.push_back(n * 10 / d);
        remainders[n] = pos++;

        if (remainders[n * 10 % d] != -1) {
            startGroup = remainders[n * 10 % d];
            break;
        }

        n = n * 10 % d;
    }

    for (int i = 0; i < digits.size(); i++) {
        if (i == startGroup) {
            fout << "(";
            if (w++ == 75) {
                w = 0;
                fout << endl;
            }
        }
        fout << digits[i];
        if (w++ == 75) {
            w = 0;
            fout << endl;
        }
    }
    if (startGroup < digits.size()) fout << ")";
    fout << endl;

    return 0;
}

