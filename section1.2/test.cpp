#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    char letters[10][10];
    for (int i = 0; i < n; i++)
        cin >> letters[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << letters[i][j];
        }
        cout << endl;
    }
}
