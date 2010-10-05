/*
ID: eckanka1
PROG: dualpal
LANG: C++
*/
#include <fstream>
#include <string>

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
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");

    int n, s;

    fin >> n >> s;

    string num;
    int cnt = 0;
    for (int i = s+1; cnt < n; i++) {
        int p = 0;
        for (int b = 2; b <= 10; b++) {
            itoa(i, b, num);
            if (is_palindrome(num)) {
                p++;
            }
        }
        if (p >= 2) {
            fout << i << endl;
            ++cnt;
        }
    }

}
