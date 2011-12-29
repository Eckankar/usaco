/*
ID: eckanka1
PROG: comehome
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

#define INFTY 100000000

using namespace std;

int graph[52][52];

int ltopos(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    } else {
        return 26 + c - 'A';
    }
}

char postol(int pos) {
    if (pos < 26) {
        return 'a' + pos;
    } else {
        return 'A' + (pos - 26);
    }
}

int main() {
    ifstream  fin("comehome.in" );
    ofstream fout("comehome.out");

    int n;
    fin >> n;

    memset(graph, 0, sizeof(graph));

    while (n --> 0) {
        char f, t;
        int d;
        fin >> f >> t >> d;

        int pf = ltopos(f),
            pt = ltopos(t);

        if (!graph[pf][pt] || d < graph[pf][pt]) {
            graph[pf][pt] = graph[pt][pf] = d;
        }
    }

    bool visited[52];
    int dist[52];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < 52; i++) {
        dist[i] = INFTY;
    }

    priority_queue< pair<int, int> > queue;

    int barn = ltopos('Z');
    dist[barn] = 0;

    queue.push(make_pair(0, barn));

    while (!queue.empty()) {
        pair<int, int> e = queue.top();
        queue.pop();

        int d = -e.first, n = e.second;
        if (visited[n]) continue;

        visited[n] = true;

        for (int i = 0; i < 52; i++) {
            if (!graph[n][i]) continue;

            if (dist[i] > dist[n] + graph[n][i]) {
                dist[i] = dist[n] + graph[n][i];
            }

            queue.push(make_pair(-dist[i], i));
        }
    }

    char bestc;
    int bestd = INFTY;
    for (int i = ltopos('A'); i < ltopos('Z'); i++) {
        if (dist[i] > 0 && dist[i] < bestd) {
            bestc = postol(i);
            bestd = dist[i];
        }
    }

    fout << bestc << " " << bestd << endl;
}

