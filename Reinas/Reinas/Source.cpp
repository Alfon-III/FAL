#include <iostream>
using namespace std;

int n[1000];

void escribeTablero(int tab[], int n) {
	for (int i = 0; i < n; i++) {//X
		for (int j = 0; j < n; j++) {//Y
			if (tab[j] == i) {
				cout << "X ";
			}
			else {
				cout << ". ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

bool esPrometedor(int sol[], int cuantas) {
	for (int i = 0; i < cuantas - 1; i++) {
		//cout << "hola";
		if (sol[i] == sol[cuantas - 1]) {//analizo todas las reinas respecto a la nueva candidada
			return false;
		}
		if (abs(sol[cuantas - 1] - sol[i]) == abs(cuantas - 1 - i)) {
			return false;
		}
	}
	return true;
}

void escribeTodas(int solParcial[], int k, int n) {//K = numero de reinas colocadas, k+1 puede ser o no definitiva, se ve en el bucle for
	if (k == n) {
		escribeTablero(solParcial, n);
	}
	for (int i = 0; i < n; i++){
		solParcial[k] = i;
		
		if (esPrometedor(solParcial, k + 1)) {
			escribeTodas(solParcial, k + 1, n);
		}
		//else, te jodes
	}
}

int main() {
	escribeTodas(n, 0, 14);
	return 0;
}