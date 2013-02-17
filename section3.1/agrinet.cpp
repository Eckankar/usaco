/*
ID: eckanka1
PROG: agrinet
LANG: C++
*/
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 100

int farms[MAX_N][MAX_N] = {0};
bool connected[MAX_N] = {0};

int main() {
    ifstream  fin("agrinet.in" );
    ofstream fout("agrinet.out");

    int n;
    fin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> farms[i][j];
        }
    }

    int total_length = 0;
    priority_queue< pair<int, int> > queue; // (-weight, vertex) 

    queue.push( make_pair(0, 0) );

    while (!queue.empty()) {
        pair<int, int> p = queue.top();
        queue.pop();

        int d = -p.first; int v = p.second;

        if (connected[v]) continue;

        connected[v] = true;
        total_length += d;

        for (int i = 0; i < n; i++) {
            if (connected[i]) continue;
            queue.push( make_pair( - farms[v][i], i) );
        }
    }

    fout << total_length << endl;
}

