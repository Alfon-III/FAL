#include <iostream>
using namespace std;

int v[1000];

/*Casos de Prueba:
20

4
1 1 1 1

4
1 1 1 2

4
1 1 1 9

4
1 1 2 2

4
1 2 3 4

4 
1 1 3 3
*/

bool semiCreciente(int v[], int ini, int fin) {
	//la diferencia entre inicio y fin cumple
	if ((v[fin] - v[ini]) <= 1) {
		return true;
	}
	//entre inicio y fin es IPOSIBLE que lo cumpla, pues 
	//no hay suficientes número s para que llegue
	if (v[fin] - v[ini] > fin - ini) { 
		//n = 5 y ini = 1 y fin = 10, jodido q se cumpla
		return false;
	}


	int mid = ini + fin / 2;
	
	//antes de dividir, vemos que en la "fractura"
	//siga siendo válido
	if (v[mid + 1] - v[mid] > 1) {
		return false;
	}

	return semiCreciente(v,ini, mid) &&
		   semiCreciente(v, mid + 1, fin);

}
/**/


int main() {
	int casos, n;
	cin >> casos;
	while (casos != 0) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		if (semiCreciente(v, 0, n - 1)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}


		casos--;
	}
	return 0;
}