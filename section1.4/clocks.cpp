/*
ID: eckanka1
PROG: clocks
LANG: C++
*/
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <iostream>

#define RPT(n) for (move[n] = 0; move[n] < 4; move[n]++)

using namespace std;

const unsigned int A = 1,
                   B = A << 3,
                   C = B << 3,
                   D = C << 3,
                   E = D << 3,
                   F = E << 3,
                   G = F << 3,
                   H = G << 3,
                   I = H << 3;

const unsigned int MOVES[9] = {
    A + B + D + E,
    A + B + C,
    B + C + E + F,
    A + D + G,
    B + D + E + F + H,
    C + F + I,
    D + E + G + H,
    G + H + I,
    E + F + H + I
};

unsigned int IGNORE_MASK = ~((A + B + C + D + E + F + G + H + I) << 2);

bool tryMove(unsigned int clock, int move[9]) {
    unsigned int temp = 0;
    for (int i = 0; i < 9; i++) {
        temp += move[i] * MOVES[i];
        temp &= IGNORE_MASK;
    }

    return clock == temp;
}

int main() {
    ifstream fin("clocks.in");
    ofstream fout("clocks.out");

    unsigned int clock = 0;

    for (int i = 0; i < 9; i++) {
        int n;
        fin >> n;
        n = (4 - n / 3) % 4;
        clock += (n << (3*i));
    }

    int move[9];
    RPT(0) RPT(1) RPT(2)
    RPT(3) RPT(4) RPT(5)
    RPT(6) RPT(7) RPT(8) {
        if (tryMove(clock, move)) {
            string output;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < move[i]; j++) {
                    output = output +  "123456789"[i] + " ";
                }
            }
            output.resize(output.size() - 1);
            fout << output << endl;
            return 0;
        }
    }
}
