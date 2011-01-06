/*
ID: eckanka1
PROG: prefix
LANG: C++
*/
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Trie {
        bool _end;
        int _num;
        Trie *children[26];
    public:
        Trie();
        Trie operator[](char);
        bool exists(char);
        void insert(string);
        bool end();
        int num();
};

vector<Trie*> tries;
int n = 0;

Trie::Trie () {
    memset(children, 0, sizeof(children));
    _end = false;
    _num = n++;
}

bool Trie::exists (char c) {
    return children[c - 'A'] != NULL;
}

Trie Trie::operator[] (char c) {
    return *children[c - 'A'];
}

int Trie::num () {
    return _num;
}

bool Trie::end () {
    return _end;
}

void Trie::insert (string s) {
    if (s.empty()) {
        _end = true;
        return;
    }

    char first = s[0];
    if (!exists(first)) {
        Trie* child = new Trie;
        tries.push_back(child);
        children[first - 'A'] = child;
    }

    string rest = s.substr(1);
    children[first - 'A']->insert(rest);
}

int main() {
    ifstream  fin("prefix.in" );
    ofstream fout("prefix.out");

    Trie root;
    tries.push_back(&root);

    string instr;
    while (fin >> instr) {
        if (instr == ".") break;
        root.insert(instr);
    }

    bool active[n], newActive[n];

    memset(active, 0, sizeof(active));
    active[root.num()] = true;
    bool activeEmpty = false;

    char c;
    int cnt = 0;
    int lastEnd = 0;
    while (fin >> c && !activeEmpty) {
        ++cnt;
        memset(newActive, 0, sizeof(newActive));

        for (int i = 0; i < n; ++i) {
            if (!active[i]) continue;

            Trie curTrie = *tries[i];
            // cout << cnt << " " << curPref << endl;

            if (curTrie.exists(c)) {
                newActive[curTrie[c].num()] = true;

                if (curTrie[c].end()) {
                    newActive[0] = true;

                    if (cnt > lastEnd) {
                        lastEnd = cnt;
                    }
                }
            }
        }

        memcpy(active, newActive, sizeof(active));
    }

    fout << lastEnd << endl;
}
