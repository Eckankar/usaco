/*
ID: eckanka1
PROG: ttwo
LANG: C++
*/
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>

#define WIDTH 10
#define HEIGHT 10

// The longest length of a cycle < w*h
// If both are cycling and aperiodic, the longest it'll
// take before they meet is thus < (w*h)^2
#define MAX_STEPS WIDTH*HEIGHT*WIDTH*HEIGHT

using namespace std;

bool obstacles[HEIGHT][WIDTH];

enum {
    NORTH, EAST, SOUTH, WEST
};

struct pos_t {
    int x, y;
    int dir;
};

int nextdir(int dir) {
    return (dir+1)%4;
}

bool move(pos_t *obj) {
    switch (obj->dir) {
        case NORTH:
            if (obj->y == 0 || obstacles[obj->y-1][obj->x]) return false;
            obj->y--;
            break;
        case EAST:
            if (obj->x == WIDTH-1 || obstacles[obj->y][obj->x+1]) return false;
            obj->x++;
            break;
        case SOUTH:
            if (obj->y == HEIGHT-1 || obstacles[obj->y+1][obj->x]) return false;
            obj->y++;
            break;
        case WEST:
            if (obj->x == 0 || obstacles[obj->y][obj->x-1]) return false;
            obj->x--;
            break;
    }
    return true;
}

int main() {
    ifstream  fin("ttwo.in" );
    ofstream fout("ttwo.out");

    pos_t farmer, cows;
    farmer.dir = NORTH;
    cows.dir = NORTH;

    memset(obstacles, 0, sizeof(obstacles));

    string s;
    for (int i = 0; i < HEIGHT; i++) {
        fin >> s;
        for (int j = 0; j < WIDTH; j++) {
            switch (s[j]) {
                case '*':
                    obstacles[i][j] = true;
                    break;
                case 'C':
                    cows.x = j;
                    cows.y = i;
                    break;
                case 'F':
                    farmer.x = j;
                    farmer.y = i;
                    break;
                default:
                    break;
            }
        }
    }

    for (int i = 0; i < MAX_STEPS; i++) {
        if (!move(&farmer)) {
            farmer.dir = nextdir(farmer.dir);
        }
        if (!move(&cows)) {
            cows.dir = nextdir(cows.dir);
        }

        if (farmer.x == cows.x &&
            farmer.y == cows.y) {
            fout << (i+1) << endl;
            return 0;
        }
    }

    fout << 0 << endl;

}

