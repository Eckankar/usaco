/*
ID: eckanka1
PROG: namenum
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");

    ifstream nin("dict.txt");
    string name;
    multimap<string, string> numMap;
    while (nin >> name) {
        string number = "";
        for (int i = 0; i < name.length(); i++) {
            switch (name[i]) {
                case 'A': case 'B': case 'C':
                    number.append("2");
                    break;
                case 'D': case 'E': case 'F':
                    number.append("3");
                    break;
                case 'G': case 'H': case 'I':
                    number.append("4");
                    break;
                case 'J': case 'K': case 'L':
                    number.append("5");
                    break;
                case 'M': case 'N': case 'O':
                    number.append("6");
                    break;
                case 'P': case 'R': case 'S':
                    number.append("7");
                    break;
                case 'T': case 'U': case 'V':
                    number.append("8");
                    break;
                case 'W': case 'X': case 'Y':
                    number.append("9");
                    break;
            }
        }
        numMap.insert( pair<string, string>(number, name) );
    }

    string input;
    fin >> input;

    pair<multimap<string, string>::iterator, multimap<string, string>::iterator> fnd = numMap.equal_range(input);
    for (multimap<string, string>::iterator it = fnd.first; it != fnd.second; ++it) {
        fout << (*it).second << endl;
    }

    if (fnd.first == fnd.second)
        fout << "NONE" << endl;
}

