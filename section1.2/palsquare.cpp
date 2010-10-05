/*
ID: eckanka1
PROG: palsquare
LANG: C++
*/
#include <fstream>

using namespace std;

void itoa(int n, int base, string &out) {
    out = "";
    for (; n > 0; n /= base) {
        out = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % base] + out;
    }
}

bool is_palindrome(string s) {
    int len = s.length();
    for (int i = 0; i < len/2; i++) {
        if (s[i] != s[len-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");

    int b;
    fin >> b;

    string num;
    for (int i = 1; i <= 300; i++) {
        itoa(i*i, b, num);
        if (is_palindrome(num)) {
            string n;
            itoa(i, b, n);
            fout << n << " " << num << endl;

        }
    }
}

