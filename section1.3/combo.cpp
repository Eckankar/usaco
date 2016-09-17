/*
ID: eckanka1
PROG: combo
LANG: C++
*/
#include <fstream>
#include <stdlib.h>

using namespace std;

int main() {
    ifstream  fin("combo.in" );
    ofstream fout("combo.out");

    int n;
    fin >> n;

    int john[3];
    fin >> john[0] >> john[1] >> john[2];

    int master[3];
    fin >> master[0] >> master[1] >> master[2];

    int count = 0;

    for (int i = 1; i <= n; i++) {
        bool j_close_0 = abs(john[0] - i) <= 2 || abs(min(john[0],i)+n - max(john[0],i)) <= 2;
        bool m_close_0 = abs(master[0] - i) <= 2 || abs(min(master[0],i)+n - max(master[0],i)) <= 2;
        if (! (j_close_0 || m_close_0)) continue;

        for (int j = 1; j <= n; j++) {
            bool j_close_1 = j_close_0 && (abs(john[1] - j) <= 2 || abs(min(john[1],j)+n - max(john[1],j)) <= 2);
            bool m_close_1 = m_close_0 && (abs(master[1] - j) <= 2 || abs(min(master[1],j)+n - max(master[1],j)) <= 2);
            if (! (j_close_1 || m_close_1)) continue;

            for (int k = 1; k <= n; k++) {
                bool j_close_2 = j_close_1 && (abs(john[2] - k) <= 2 || abs(min(john[2],k)+n - max(john[2],k)) <= 2);
                bool m_close_2 = m_close_1 && (abs(master[2] - k) <= 2 || abs(min(master[2],k)+n - max(master[2],k)) <= 2);
                if (! (j_close_2 || m_close_2)) continue;

                count += 1;
            }
        }
    }

    fout << count << endl;
}

