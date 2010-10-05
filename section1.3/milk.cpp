/*
ID: eckanka1
PROG: milk
LANG: C++
*/
#include <fstream>
#include <queue>

using namespace std;

class Farmer {
public:
    int price, amount;

    Farmer(int p, int a) {
        price = p;
        amount = a;
    }
};

bool operator<(const Farmer &a, const Farmer &b) {
    return a.price > b.price;
}

int main() {
    ifstream fin("milk.in");
    ofstream fout("milk.out");

    int n, m;
    fin >> n >> m;

    priority_queue<Farmer> farmers;
    for (int i = 0; i < m; i++) {
        int price, amount;
        fin >> price >> amount;

        farmers.push( Farmer(price, amount) );
    }

    int remaining = n, price = 0;

    while (remaining > 0) {
        Farmer farmer = farmers.top();
        farmers.pop();

        if (farmer.amount >= remaining) {
            price += remaining * farmer.price;
            remaining = 0;
        } else {
            price += farmer.amount * farmer.price;
            remaining -= farmer.amount;
        }
    }

    fout << price << endl;
}
