/*
ID: eckanka1
PROG: calfflac
LANG: C++
*/
#include <fstream>
#include <streambuf>
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

bool is_palindrome(char plain[20000], int start, int end) {
    while (start < end) {
        if (plain[start++] != plain[end--])
            return false;
    }
    return true;
}

main() {
    ifstream fin("calfflac.in");
    ofstream fout("calfflac.out");

    string input((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    int input_length = input.size();

    char plain[20000];
    int plainRev[20000];
    int index[20000];
    int pi = 0;
    for (int i = 0; i < input_length; i++) {
        if (isalpha(input[i])) {
            plain[pi] = toupper(input[i]);
            plainRev[pi] = i;
            index[i] = pi++;
        } else {
            index[i] = -1;
        }
    }

    int best_length = 0;
    int best_start = 0, best_actuallength = 0;
    for (int i = 0; i < input_length ; i++) {
        int start_index = index[i], end_index;
        if (start_index == -1)
            continue;

        for (int j = i + 2000 < input_length ? 2000 : input_length - i - 1; j > best_length; --j) {
            end_index = index[i + j];
            if (end_index == -1)
                continue;
            for (; end_index - start_index + 1 > best_length; end_index--) {
                if (is_palindrome(plain, start_index, end_index)) {
                    best_length = end_index - start_index + 1;
                    best_start = plainRev[start_index];
                    best_actuallength = plainRev[end_index] - plainRev[start_index] + 1;
                    break;
                }
            }

            break;
        }
    }

    fout << best_length << endl << input.substr(best_start, best_actuallength) << endl;
}
