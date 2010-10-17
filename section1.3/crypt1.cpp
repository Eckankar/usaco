/*
ID: eckanka1
PROG: crypt1
LANG: C++
*/
#include <fstream>
#include <vector>
#include <cstdio>

using namespace std;

bool fits(bool digits[10], int num, int len) {
    int d;
    for (int i = 0; i < len; i++) {
        d = num % 10;
        if (!digits[d])
            return false;
        num /= 10;
    }
    return num == 0;
}

main() {
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");

    int n;
    fin >> n;

    bool digits[10] = {false};
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int m;
        fin >> m;
        digits[m] = true;
        nums.push_back(m);
    }

    int cnt = 0;

    for (int a = 0; a < n; a++)
    for (int b = 0; b < n; b++)
    for (int c = 0; c < n; c++)
    for (int d = 0; d < n; d++)
    for (int e = 0; e < n; e++) {
        int num = 100*nums[a] + 10*nums[b] + nums[c];

        int mid1 = nums[d] * num;
        if (!fits(digits, mid1, 3))
            continue;
        int mid2 = nums[e] * num;
        if (!fits(digits, mid2, 3))
            continue;

        int num2 = 10 * nums[d] + nums[e];

        int res = num * num2;
        if (!fits(digits, res, 4))
            continue;

        ++cnt;
    }

    fout << cnt << endl;
}
