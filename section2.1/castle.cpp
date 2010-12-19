/*
ID: eckanka1
PROG: castle
LANG: C++
*/

#include <fstream>
#include <cstring>

#define WALL_WEST  1
#define WALL_NORTH 2
#define WALL_EAST  4
#define WALL_SOUTH 8

#define MAX_N 50
#define MAX_M 50
#define MAX_ROOMS MAX_N*MAX_M

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int castle[MAX_N][MAX_M],
    nums[MAX_N][MAX_M];

void floodfill(int x, int y, int baseCol, int newCol) {
    if (x < 0 || y < 0 || y >= MAX_N || x >= MAX_M) return;

    if (nums[y][x] == baseCol) {
        nums[y][x] = newCol;
        floodfill(x-1, y, baseCol, newCol);
        floodfill(x, y-1, baseCol, newCol);
        floodfill(x+1, y, baseCol, newCol);
        floodfill(x, y+1, baseCol, newCol);
    }
}

int main() {
    ifstream  fin("castle.in" );
    ofstream fout("castle.out");

    int m, n;
    fin >> m >> n;

    int room_sizes[MAX_ROOMS];
    memset(room_sizes, 0, sizeof(room_sizes));

    int room = 0,
        destroyed = 0;

    int maxSize = 0, maxMergeSize = 0, maxMergeX, maxMergeY;
    char maxMergeDir;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            fin >> castle[y][x];
            int cur = castle[y][x];

            int roomWest = -1, roomNorth = -1;
            if (y > 0 && !(cur & WALL_NORTH)) {
                roomNorth = nums[y-1][x];
            }
            if (x > 0 && !(cur & WALL_WEST)) {
                roomWest = nums[y][x-1];
            }

            if (roomNorth == -1 && roomWest == -1) {
                nums[y][x] = room;
                room_sizes[room]++;
                ++room;
            } else if (roomNorth != -1 && roomWest != -1 && roomNorth != roomWest) {
                floodfill(x-1, y, roomWest, roomNorth);
                nums[y][x] = roomNorth;
                room_sizes[roomNorth] += room_sizes[roomWest] + 1;
                room_sizes[roomWest] = 0;
                destroyed++;
            } else {
                int roomNo = MAX(roomNorth, roomWest);
                nums[y][x] = roomNo;
                room_sizes[roomNo]++;
            }

            int curRoomSize = room_sizes[nums[y][x]];
            if (curRoomSize > maxSize) {
                maxSize = curRoomSize;
            }
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            int curRoomSize = room_sizes[nums[y][x]];
            if (y > 0 && nums[y-1][x] != nums[y][x]) {
                int northRoomSize = room_sizes[nums[y-1][x]];
                int newSize = northRoomSize + curRoomSize;
                if (newSize > maxMergeSize || (newSize == maxMergeSize && x <= maxMergeX)) {
                    maxMergeSize = newSize;
                    maxMergeX = x;
                    maxMergeY = y;
                    maxMergeDir = 'N';
                }
            }
            if (x > 0 && nums[y][x-1] != nums[y][x]) {
                int westRoomSize = room_sizes[nums[y][x-1]];
                int newSize = westRoomSize + curRoomSize;
                if (newSize > maxMergeSize || (newSize == maxMergeSize && // fuck, this is ugly
                     ((x-1) < maxMergeX || (maxMergeX == (x-1) && maxMergeY != y)))) {
                    maxMergeSize = newSize;
                    maxMergeX = x-1;
                    maxMergeY = y;
                    maxMergeDir = 'E';
                }
            }
        }
    }

    fout << room - destroyed << endl
         << maxSize << endl
         << maxMergeSize << endl
         << maxMergeY + 1 << " "
         << maxMergeX + 1 << " "
         << maxMergeDir << endl;

    /*
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            printf("%2d ", nums[y][x]);
        }
        printf("\n");
    }*/

}
