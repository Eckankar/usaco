/*
ID: eckanka1
PROG: sprime
LANG: C++
*/
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

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
    ifstream fin ("sprime.in" );
    ofstream fout("sprime.out");

    int n;
    fin >> n;

    vector<int> sprimes;
    // Initial superprimes:
    sprimes.push_back(2);
    sprimes.push_back(3);
    sprimes.push_back(5);
    sprimes.push_back(7);

    for (int m = 1; m < n; m++) {
        vector<int> new_sprimes;
        for (int i = 0; i < sprimes.size(); i++) {
            int spr = sprimes[i];
            for (int d = 1; d < 10; d++) {
                if (check_prime(10*spr + d))
                    new_sprimes.push_back(10*spr + d);
            }
        }

        sprimes = new_sprimes;
    }

    for (int i = 0; i < sprimes.size(); i++) {
        fout << sprimes[i] << endl;
    }
}
