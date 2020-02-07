#include <iostream>
using namespace std;

int v[1000];

/*
5
3 5 6 8 10

4
2 4 5 7

5
2 4 6 8 10

5
1 3 5 7 9

6
3 6 8 9 13 14
*/

//O(n)
//Pre: 0 <= n < v.length() && Ord(v[], n)
//	Ord(v[], n): Pt i: 0 <= i < n - 1: v[i] <= v[i + 1]

//Cota: n - i
int ordenaPar(int v[], int n) {
	int i = 0;
	int aux = 0;

	while (i < n) {
		if (v[i] % 2 == 0) {
			v[aux] = v[i];
			aux++;
		}
		i++;
	}

	return aux;

}

int main() {
	int n;
	cin >> n;
	while (n != -1) {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		int aux = ordenaPar(v, n);

		for (int i = 0; i < aux; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		cin >> n;
	}
}