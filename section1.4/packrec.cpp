/*
ID: eckanka1
PROG: packrec
LANG: C++
*/
#include <fstream>
#include <algorithm>
#include <limits>
#include <vector>
#include <utility>

using namespace std;

void amend_bests(int &best_area, vector< pair<int,int> > &best_pairs, int &a, int &w, int &h, int alg_num) {
    if (a < best_area) {
        best_area = a;
        best_pairs.clear();
    }

    if (a <= best_area) {
        if (w <= h) {
            best_pairs.push_back(make_pair(w, h));
        } else {
            best_pairs.push_back(make_pair(h, w));
        }
    }
}

void layout_1 (int rects[4][2], int &a, int &w, int &h) {
    w = rects[0][0] + rects[1][0] + rects[2][0] + rects[3][0];
    h = 0;
    for (int i = 0; i < 4; i++) {
        h = max(h, rects[i][1]);
    }
    a = w*h;
}

void layout_2 (int rects[4][2], int &a, int &w, int &h) {
    w = max(rects[0][0], rects[1][0] + rects[2][0] + rects[3][0]);
    h = rects[0][1] + max(rects[1][1], max(rects[2][1], rects[3][1]));
    a = w*h;
}

void layout_3 (int rects[4][2], int &a, int &w, int &h) {
    w = rects[0][0] + max(rects[1][0], rects[2][0] + rects[3][0]);
    h = max(rects[0][1], rects[1][1] + max(rects[2][1], rects[3][1]));
    a = w*h;
}

void layout_4 (int rects[4][2], int &a, int &w, int &h) {
    w = rects[0][0] + max(rects[1][0], rects[2][0]) + rects[3][0];
    h = max(rects[0][1], max(rects[1][1] + rects[2][1], rects[3][1]));
    a = w*h;
}

void layout_5 (int rects[4][2], int &a, int &w, int &h) {
    w = max(rects[0][0], rects[1][0]) + rects[2][0] + rects[3][0];
    h = max(rects[0][1] + rects[1][1], max(rects[2][1], rects[3][1]));
    a = w*h;
}

void layout_6 (int rects[4][2], int &a, int &w, int &h) {
    w = rects[0][0] + rects[2][0];
    string extra;
    if (rects[0][1] < rects[2][1]) {
        w = max(w, rects[1][0] + rects[2][0]);
    }
    if (rects[0][1] > rects[2][1]) {
        w = max(w, rects[0][0] + rects[3][0]);
    }
    if (rects[0][1] + rects[1][1] > rects[2][1] &&
        rects[0][1] < rects[2][1] + rects[3][1]) {
        w = max(w, rects[1][0] + rects[3][0]);
    }
    if (rects[0][1] >= rects[2][1] + rects[3][1]) {
        w = max(w, rects[1][0]);
    }
    if (rects[0][1] + rects[1][1] <= rects[2][1]) {
        w = max(w, rects[3][0]);
    }

    h = max(rects[0][1] + rects[1][1], rects[2][1] + rects[3][1]);

    a = w*h;
}

int main() {
    ifstream fin("packrec.in");
    ofstream fout("packrec.out");

    int perm[4] = {0, 1, 2, 3};
    int rects[4][2];
    for (int i = 0; i < 4; i++) {
        fin >> rects[i][0] >> rects[i][1];
    }

    int best_area = numeric_limits<int>::max();
    vector< pair<int, int> > best_pairs;
    do {
        // i = bitfield; covers which rectangles to rotate 90 degrees
        for (int i = 0; i < 16; i++) {
            int a, w, h;

            // rotate rects
            int currects[4][2];
            for (int j = 0; j < 4; j++) {
                if (i & (1 << j)) {
                    currects[j][0] = rects[perm[j]][1];
                    currects[j][1] = rects[perm[j]][0];
                } else {
                    currects[j][0] = rects[perm[j]][0];
                    currects[j][1] = rects[perm[j]][1];
                }
            }

            layout_1(currects, a, w, h);
            amend_bests(best_area, best_pairs, a, w, h, 1);

            layout_2(currects, a, w, h);
            amend_bests(best_area, best_pairs, a, w, h, 2);

            layout_3(currects, a, w, h);
            amend_bests(best_area, best_pairs, a, w, h, 3);

            layout_4(currects, a, w, h);
            amend_bests(best_area, best_pairs, a, w, h, 4);

            layout_5(currects, a, w, h);
            amend_bests(best_area, best_pairs, a, w, h, 5);

            layout_6(currects, a, w, h);
            amend_bests(best_area, best_pairs, a, w, h, 6);
        }

    } while (next_permutation(perm, perm+4));

    sort(best_pairs.begin(), best_pairs.end());

    // Remove duplicates
    vector< pair<int, int> >::iterator it = unique(best_pairs.begin(), best_pairs.end());
    best_pairs.resize(it - best_pairs.begin());

    fout << best_area << endl;
    for (int i = 0; i < best_pairs.size(); i++) {
        fout << best_pairs[i].first << " " << best_pairs[i].second << endl;
    }
}
