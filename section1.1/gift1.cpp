/*
ID: eckanka1
PROG: gift1
LANG: C++
*/

#include <fstream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main() {
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");

    int n;
    fin >> n;

    map<string, int> gifts;
    string names[10];
    for (int i = 0; i < n; ++i) {
        fin >> names[i];
        gifts[names[i]] = 0;
    }

    for (int i = 0; i < n; ++i) {
        string name;
        fin >> name;
        int money, friends;
        fin >> money >> friends;

        if (friends == 0) continue;

        int gift = money / friends;
        gifts[name] -= gift * friends;

        for (int j = 0; j < friends; ++j) {
            fin >> name;
            gifts[name] += gift;
        }
    }

    for (int i = 0; i < n; i++) {
        fout << names[i] << " " << gifts[names[i]] << endl;
    }
}
