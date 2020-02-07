#include <iostream>
using namespace std;


int v[1000];


/*
20
5 5 5 5 5 5 5 5 4 4 4 4 4 4 1 1 1 7 9 2
*/

int numCadenas(int v[], int n, int ini, int fin) {
	
	if (v[ini] == v[fin]) {
		return 1;
	}
	
	int mid = (ini + fin) / 2;

	if (v[mid] != v[mid + 1]) {
		return numCadenas(v, n, ini, mid) +
			   numCadenas(v, n, mid + 1, fin);
	}
	else {
		return numCadenas(v, n, ini, mid) +
			numCadenas(v, n, mid + 1, fin) - 1;
	}

}

int main() {

	int n;
	cin >> n;
	while (n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		cout << numCadenas(v, n, 0, n - 1) << endl;

		cin >> n;
	}


	return 0;
}