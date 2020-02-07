#include <iostream>
using namespace std;

bool v[100];

/*
8 0 0 1 0 0 1 0 1 2
4 1 0 1 0 1
4 1 0 1 0 2
1 1 1
4 1 0 1 0 3
0 1
-1
*/

int lowTrue(bool v[], int n, int k) {
	int ret = n + 1;
	int ini = 0;
	int fin = 0;
	int cont = 0;
	while (ini < n || cont >= k) {
		//ampliamos la ventana, hasta encontrar k elementos a true
		if (cont < k) {
			if (v[fin]) {
				cont++;
			}
			fin++;
		}
		else {//hemos encontrado 2 elemntos, reducimos la ventana por detras
			if (v[ini]) {
				cont--;
			}
			ini++;
		}

		if (cont == k) {
			if (fin - ini < ret) {
				ret = fin - ini;
			}
		}
	}
	
	return ret;
}

int main() {
	int n, aux, k;
	cin >> n;

	while (n != -1) {
		for (int i = 0; i < n; i++) {
			cin >> aux;
			if (aux == 0) {
				v[i] = false;
			}
			else {
				v[i] = true;
			}
		}
		cin >> k;

		cout << lowTrue(v, n, k) << endl;

		cin >> n;
	}
}