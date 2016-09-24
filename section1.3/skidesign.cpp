/*
ID: eckanka1
PROG: skidesign
LANG: C++
*/
#include <fstream>
#include <cstring>

using namespace std;

int costs[101];

int main() {
    ifstream  fin("skidesign.in" );
    ofstream fout("skidesign.out");

    int n;
    fin >> n;

    memset(costs, 0, sizeof(costs));

    int minCost;

    for (int i = 0; i < n; i++) {
        int hill;
        fin >> hill;

        for (int h = 1; h <= 100; h++) {
            if (hill < h) {
                costs[h] += (hill - h) * (hill - h);
            } else if (hill - h > 17) {
                costs[h] += (hill - h - 17) * (hill - h - 17);
            }

            if (h == 1)  minCost = costs[h];
            if (costs[h] < minCost) minCost = costs[h];
        }
    }

    fout << minCost << endl;
}

