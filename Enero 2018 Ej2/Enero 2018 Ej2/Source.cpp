#include <iostream>
#include <algorithm>
using namespace std;

int v[1000];

/*

4
5
2
1 9
2
2
1 9
-2
7
-5 -3 -1 0 1 3 5
2
10
-1 0 1 1 2 2 2 3 6 9

*/

//Si maxCerc == x -> cercano devuelve 0
int cercano(int v[], int n, int x, int ini, int fin, int& maxCerc) {
	if (fin == ini || v[fin] == v[ini]) {//caso base
		maxCerc = v[fin];
		cout << " --> " << abs(v[fin] - x) << endl;
		return abs(v[fin] - x );
	}

	int mid = (ini + fin) / 2;

	int maxCerDer, maxCerIzq, disDer, disIzq; 
	disIzq = cercano(v, n, x, ini	 , mid, maxCerIzq);
	disDer = cercano(v, n, x, mid + 1, fin, maxCerDer);
	
	//La distancia de un numero encontrado a la derecha es más cercano al x
	if (disDer < disIzq) {
		maxCerc = maxCerDer;
		return disDer;
	}

	//La distancia de un numero encontrado a la izquierda es más cercano al x
	else if (disDer > disIzq) {
		maxCerc = maxCerIzq;
		return disIzq;
	}
	//Si la distancia es igual por ambos lados,  devuelvo el menor numero
	else if (disDer == disIzq) {
		if (maxCerIzq < maxCerDer) {
			maxCerc = maxCerIzq;
			return disIzq;
		}
		else {
			maxCerc = maxCerDer;
			return disDer;
		}
	}

}

int main() {

	int casos, x, n;
	cin >> casos;

	for (int c = 0; c < casos; c++) {
		cin >> x >> n;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		//Mostramos resultado;+
		int dummy;
		cout << cercano(v, n, x, 0, n - 1, dummy)<< endl;
		cout << "El mas cercano es: " << dummy << endl;
	}

	return 0;
}