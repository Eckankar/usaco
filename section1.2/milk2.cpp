/*
ID: eckanka1
PROG: milk2
LANG: C++
*/
#include <fstream>
#include <queue>

using namespace std;

class Milking {
public:
    int time;
    bool start;

    Milking(int t, bool s) {
        time = t;
        start = s;
    }
};

bool operator<(const Milking &a, const Milking &b) {
    return a.time > b.time;
}

int main() {
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    int n;
    fin >> n;

    priority_queue<Milking> times;
    for (int i = 0; i < n; i++) {
        int start, end;
        fin >> start >> end;

        times.push( Milking(start, true) );
        times.push( Milking(end, false) );
    }

    int longest_nomilk = 0, longest_milk = 0;
    int milk_count = 0, start = times.top().time;

    while (!times.empty()) {
        Milking time = times.top();
        times.pop();

        if (milk_count == 0 && time.start) {
            if (longest_nomilk < time.time - start) {
                longest_nomilk = time.time - start;
            }
            start = time.time;
        }

        if (time.start) {
            milk_count++;
        } else {
            milk_count--;
            if (milk_count == 0) {
                if (longest_milk < time.time - start) {
                    longest_milk = time.time - start;
                }
                start = time.time;
            }
        }
    }

    fout << longest_milk << " " << longest_nomilk << endl;
}
