/*
ID: eckanka1
PROG: barn1
LANG: C++
*/
#include <fstream>
#include <algorithm>
#include <queue>
//#include <iostream>

using namespace std;

class Space {
    public:
        int space;
        int left;

        Space(int space, int left) {
            this->space = space;
            this->left = left;
        }
};

bool operator<(Space const &a, Space const &b) {
    return a.space > b.space;
}

int main() {
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");

    int m, s, c;
    fin >> m >> s >> c;

    if (m >= c) {
        fout << c << endl;
        return 0;
    }

    int cows[c];
    for (int i = 0; i < c; i++) {
        fin >> cows[i];
    }

    sort(cows, cows + c);


    priority_queue<Space> pq;
    for (int i = 1; i < c; i++) {
            pq.push( Space(cows[i] - cows[i-1], cows[i-1]) );
            if (pq.size() >= m) {
                pq.pop();
            }
    }

    int boardEnds[m];
    boardEnds[m-1] = cows[c-1];
    for (int i = 0; i < m-1; i++) {
        boardEnds[i] = pq.top().left;
        pq.pop();
    }

    sort(boardEnds, boardEnds + m);

    /*for (int i = 0; i < m; i++) {
        cerr << boardEnds[i] << " ";
    }
    cerr << endl;*/

    int len = 0;
    int start = 0;
    int j = 0;
    for (int i = 0; i < c; i++) {
        if (cows[i] == boardEnds[j]) {
            //cerr << cows[start] << " " << boardEnds[j] << endl;
            len += boardEnds[j] - cows[start] + 1;
            start = i+1;
            j++;
        }
    }

    fout << len << endl;
}
