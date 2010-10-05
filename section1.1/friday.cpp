/*
ID: eckanka1
PROG: friday
LANG: C++
*/
#include <fstream>

using namespace std;

bool isLeap(int year) {
    return year % 4 == 0 &&
           (year % 100 != 0 || year % 400 == 0);
}

const int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int daysInMonth(int month, int year) {
    return isLeap(year) && month == 1 ? 29 : months[month];
}

int main() {
    ifstream fin("friday.in");
    ofstream fout("friday.out");

    int endYear;
    fin >> endYear;
    endYear += 1900;

    // sat = 0, ..., fri = 6
    int weekday = 2;

    int fallsOn[7] = {0};

    for (int year = 1900; year < endYear; year++) {
        for (int month = 0; month < 12; month++) {
            fallsOn[(weekday + 12) % 7]++;
            weekday = (weekday + daysInMonth(month, year)) % 7;
        }
    }

    for (int i = 0; i < 6; i++) {
        fout << fallsOn[i] << " ";
    }
    fout << fallsOn[6] << endl;
}
