/*
ID: eckanka1
PROG: subset
LANG: C++
*/
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    ifstream  fin("subset.in" );
    ofstream fout("subset.out");

    int n;
    fin >> n;

    unsigned int nums[n+1][n*(n+1)/2+1];
    memset(nums, 0, sizeof(nums));
    nums[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i*(i+1)/2; ++j) {
            nums[i][j] = nums[i-1][j] + (j-i < 0 ? 0 : nums[i-1][j-i]);
        }
    }

    fout << ((n*(n+1)/2) % 2 == 0 ? nums[n][n*(n+1)/4]/2 : 0) << endl;
}
