/*
ID: eckanka1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	char *a = new char[7],
		 *b = new char[7];

    FILE *fin = fopen("ride.in", "r");
	fscanf(fin, "%s\n%s", a, b);
	fclose(fin);

	int aProd = 1, bProd = 1;
	for (; *a != '\0'; ++a) {
		aProd *= *a - 'A' + 1;
	}
	for (; *b != '\0'; ++b) {
		bProd *= *b - 'A' + 1;
	}

	FILE *fout = fopen("ride.out", "w");
	fprintf(fout, "%s\n", (aProd - bProd) % 47 == 0 ? "GO" : "STAY");
	fclose(fout);
}
