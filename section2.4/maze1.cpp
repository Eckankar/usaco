/*
ID: eckanka1
PROG: maze1
LANG: C++
*/
#include <fstream>
#include <string>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int main() {
    ifstream  fin("maze1.in" );
    ofstream fout("maze1.out");

    int w, h;
    fin >> w >> h;

    queue< pair<int, int> > todo;
    int scores[w][h];
    bool hwalls[w][h+1], vwalls[w+1][h];
    string s;

    memset(scores, 0, sizeof(scores));
    memset(hwalls, 0, sizeof(hwalls));
    memset(vwalls, 0, sizeof(vwalls));

    getline(fin, s); // clear current line

    for (int y = 0; y <= 2*h; y++) {
        getline(fin, s);
        if (y % 2 == 0) {
            for (int x = 1; x <= 2*w; x += 2) {
                bool wall = s[x] == '-';
                hwalls[x/2][y/2] = wall;
                if (!wall && y == 0) {
                    todo.push(make_pair(x/2, 0));
                    scores[x/2][0] = 1;
                } else if (!wall && y == 2*h) {
                    todo.push(make_pair(x/2, h-1));
                    scores[x/2][h-1] = 1;
                }
            }
        } else {
            for (int x = 0; x <= 2*w; x += 2) {
                bool wall = s[x] == '|';
                vwalls[x/2][y/2] = wall;
                if (!wall && x == 0) {
                    todo.push(make_pair(0, y/2));
                    scores[0][y/2] = 1;
                } else if (!wall && x == 2*w) {
                    todo.push(make_pair(w-1, y/2));
                    scores[w-1][y/2] = 1;
                }
            }
        }
    }

    int high = 1;
    while (!todo.empty()) {
        int x = todo.front().first,
            y = todo.front().second;
        todo.pop();

        int score = scores[x][y]+1;
        high = scores[x][y];

        if (x > 0 && !vwalls[x][y] && scores[x-1][y] == 0) {
            scores[x-1][y] = score;
            todo.push(make_pair(x-1, y));
        }
        if (x < w-1 && !vwalls[x+1][y] && scores[x+1][y] == 0) {
            scores[x+1][y] = score;
            todo.push(make_pair(x+1, y));
        }
        if (y > 0 && !hwalls[x][y] && scores[x][y-1] == 0) {
            scores[x][y-1] = score;
            todo.push(make_pair(x, y-1));
        }
        if (y < h-1 && !hwalls[x][y+1] && scores[x][y+1] == 0) {
            scores[x][y+1] = score;
            todo.push(make_pair(x, y+1));
        }
    }

    fout << high << endl;
}

