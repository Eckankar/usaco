/*
ID: eckanka1
PROG: cowtour
LANG: C++
*/
#include <fstream>
#include <cmath>
#include <cstring>
#include <limits>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef struct {
    int x, y;
} Point;

double euclDist(Point p, Point q) {
    return sqrt(pow(p.x-q.x, 2) + pow(p.y-q.y, 2));
}

double INFTY = std::numeric_limits<double>::max();
double NEG_INFTY = std::numeric_limits<double>::min();

bool isInfty(double d) {
    return d > 1000000;
}

int main() {
    ifstream  fin("cowtour.in" );
    ofstream fout("cowtour.out");

    int n;
    fin >> n;

    Point pos[n];
    for (int i = 0; i < n; i++) {
        fin >> pos[i].x >> pos[i].y;
    }

    // w is described in CRLS p685
    double dist[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c = '\0';
            while (c != '0' && c != '1') {
                fin >> c;
            }

            bool connected = c == '1';

            if (i == j) {
                dist[i][j] = 0;
            } else if (connected) {
                dist[i][j] = euclDist(pos[i], pos[j]);
            } else {
                dist[i][j] = INFTY;
            }
        }
    }

    // Floyd-Warshall, CLRS 695
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    double mdist[n];
    double diam[2];
    for (int i = 0; i < n; i++) {
        double md = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] > md && !isInfty(dist[i][j])) {
                md = dist[i][j];
            }
        }
        mdist[i] = md;

        int grp = isInfty(dist[0][i]);
        if (diam[grp] < mdist[i]) diam[grp] = mdist[i];
    }

    double maxDiam = max(diam[0], diam[1]);

    double minMaxDist = INFTY;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (!isInfty(dist[i][j])) continue;
            double maxDist = max(maxDiam, mdist[i] + euclDist(pos[i], pos[j]) + mdist[j]);

            if (maxDist < minMaxDist) {
                minMaxDist = maxDist;
            }
        }
    }

    // Ugly hack to get right precision
    char output[2550];
    sprintf(output, "%f", minMaxDist);

    fout << output << endl;
}

