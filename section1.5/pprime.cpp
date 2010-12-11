/*
ID: eckanka1
PROG: pprime
LANG: C++
*/
#include <fstream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

bool check_prime(int n) {
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    ifstream  fin("pprime.in" );
    FILE *fout = fopen("pprime.out", "w");

    int a, b;
    fin >> a >> b;

    // Generate palindromes {{{
    // 1-digit palindromes
    if (a < 10 && b > 1) {
        for (int d0 = 1; d0 < 10; d0++) {
            int pal = d0;
            if (pal <= b && check_prime(pal) && pal >= a) {
                fprintf(fout, "%d\n", pal);
            }
        }
    }
    // 2-digit palindromes
    if (a < 100 && b > 10) {
        for (int d0 = 1; d0 < 10; d0++) {
            int pal = 10*d0 + d0;
            if (pal <= b && check_prime(pal) && pal >= a) {
                fprintf(fout, "%d\n", pal);
            }
        }
    }
    // 3-digit palindromes
    if (a < 1000 && b > 100) {
        for (int d0 = 1; d0 < 10; d0++) {
        for (int d1 = 0; d1 < 10; d1++) {
            int pal = 100*d0 + 10*d1 + d0;
            if (pal <= b && check_prime(pal) && pal >= a) {
                fprintf(fout, "%d\n", pal);
            }
        }
        }
    }
    // 4-digit palindromes
    if (a < 10000 && b > 1000) {
        for (int d0 = 1; d0 < 10; d0++) {
        for (int d1 = 0; d1 < 10; d1++) {
            int pal = 1000*d0 + 100*d1 + 10*d1 + d0;
            if (pal <= b && check_prime(pal) && pal >= a) {
                fprintf(fout, "%d\n", pal);
            }
        }
        }
    }
    // 5-digit palindromes
    if (a < 100000 && b > 10000) {
        for (int d0 = 1; d0 < 10; d0++) {
        for (int d1 = 0; d1 < 10; d1++) {
        for (int d2 = 0; d2 < 10; d2++) {
            int pal = 10000*d0 + 1000*d1 + 100*d2 + 10*d1 + d0;
            if (pal <= b && check_prime(pal) && pal >= a) {
                fprintf(fout, "%d\n", pal);
            }
        }
        }
        }
    }
    // 6-digit palindromes
    if (a < 1000000 && b > 100000) {
        for (int d0 = 1; d0 < 10; d0++) {
        for (int d1 = 0; d1 < 10; d1++) {
        for (int d2 = 0; d2 < 10; d2++) {
            int pal = 100000*d0 + 10000*d1 + 1000*d2 + 100*d2 + 10*d1 + d0;
            if (pal <= b && check_prime(pal) && pal >= a) {
                fprintf(fout, "%d\n", pal);
            }
        }
        }
        }
    }
    // 7-digit palindromes
    if (a < 10000000 && b > 1000000) {
        for (int d0 = 1; d0 < 10; d0++) {
        for (int d1 = 0; d1 < 10; d1++) {
        for (int d2 = 0; d2 < 10; d2++) {
        for (int d3 = 0; d3 < 10; d3++) {
            int pal = 1000000*d0 + 100000*d1 + 10000*d2 + 1000*d3 + 100*d2 + 10*d1 + d0;
            if (pal <= b && check_prime(pal) && pal >= a) {
                fprintf(fout, "%d\n", pal);
            }
        }
        }
        }
        }
    }
    // 8-digit palindromes
    if (a < 100000000 && b > 10000000) {
        for (int d0 = 1; d0 < 10; d0++) {
        for (int d1 = 0; d1 < 10; d1++) {
        for (int d2 = 0; d2 < 10; d2++) {
        for (int d3 = 0; d3 < 10; d3++) {
            int pal = 10000000*d0 + 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d3 + 100*d2 + 10*d1 + d0;
            if (pal <= b && check_prime(pal) && pal >= a) {
                fprintf(fout, "%d\n", pal);
            }
        }
        }
        }
        }
    }
    // }}}
}
