/*
ID: eckanka1
PROG: milk3
LANG: C++
*/
#include <fstream>
#include <cstring>
#include <stack>

#define C_TO_A 0
#define C_TO_B 1
#define B_TO_A 2
#define B_TO_C 3
#define A_TO_B 4
#define A_TO_C 5
#define MAX_STATE A_TO_C

#define MIN(x, y) (x) < (y) ? (x) : (y)

#define MOVE(x, y, state)            \
    do {                             \
        int v = MIN(y - y##y, x##x); \
        if (v == 0) {                \
            states.pop();            \
            states.push(state+1);    \
            continue;                \
        }                            \
        y##y += v;                   \
        x##x -= v;                   \
        if (aa == 0) {               \
            cstates[cc] = true;      \
        }                            \
        amounts.push(v);             \
        states.push(0);              \
        continue;                    \
    } while (0)

using namespace std;

void undo_move(int &a, int &b, int &c, int move, int amount) {
    switch (move) {
        case A_TO_B: a += amount; b -= amount; break;
        case A_TO_C: a += amount; c -= amount; break;
        case B_TO_A: b += amount; a -= amount; break;
        case B_TO_C: b += amount; c -= amount; break;
        case C_TO_A: c += amount; a -= amount; break;
        case C_TO_B: c += amount; b -= amount; break;
    }
}

int main() {
    ifstream  fin("milk3.in" );
    ofstream fout("milk3.out");

    int a, b, c;
    fin >> a >> b >> c;

    bool configs[a+1][b+1][c+1];
    memset(configs, 0, sizeof(configs));

    bool cstates[c+1];
    memset(cstates, 0, sizeof(cstates));
    cstates[c] = true;

    int aa = 0, bb = 0, cc = c;
    stack<int> states;
    stack<int> amounts;
    states.push(0);
    int cnt;
    while (!states.empty()) {
        switch (states.top()) {
            case C_TO_A:
                if (configs[aa][bb][cc]) {
                    states.pop();
                    undo_move(aa, bb, cc, states.top(), amounts.top());
                    amounts.pop();

                    int state = states.top();
                    states.pop();
                    states.push(state+1);
                    continue;
                }

                configs[aa][bb][cc] = true;

                MOVE(c, a, C_TO_A);
                break;
            case C_TO_B:
                MOVE(c, b, C_TO_B);
                break;
            case B_TO_A:
                MOVE(b, a, B_TO_A);
                break;
            case B_TO_C:
                MOVE(b, c, B_TO_C);
                break;
            case A_TO_B:
                MOVE(a, b, A_TO_B);
                break;
            case A_TO_C:
                MOVE(a, c, A_TO_C);
                break;
            default:
                states.pop();
                if (!states.empty()) {
                    undo_move(aa, bb, cc, states.top(), amounts.top());
                    amounts.pop();

                    int state = states.top();
                    states.pop();
                    states.push(state+1);
                }
        }
    }

    for (int i = 0; i < c; i++) {
        if (cstates[i])
            fout << i << " ";
    }
    fout << c << endl;
}
