#include <iostream>
#include <ctime> 
using namespace std;

int v[1000];



void escribe(
	/*Datos del problema*/
		int n,
		int d,
		int v[],
	//Solución parcial
		int k,
		int cont_d
) {
	if (n - 1 == k) {
		for (int i = 0; i < n; i++) {
			cout << v[i];
		}
		cout << endl;
		return;
	}
	//Caso 1: Ponemos el mismo
	if (cont_d < d) {//El numero no se pasa
		v[k + 1] = v[k];
		escribe(n, d, v, k + 1, cont_d + 1);
	}
	
	//Caso 2: Ponemos el sigueinte se pase o no

	v[k + 1] = v[k] + 1;
	escribe(n, d, v, k + 1, 1);
	
}

void escribeCD(int n, int d, int e) {
	v[0] = e;
	escribe(n, d, v, 0, 1);
}

int main() {
	int casos, n, d, e;
	unsigned t0, t1;


	cin >> casos;
	for (int i = 0; i < casos; i++){
		cin >> n >> d >> e;
		t0 = clock();
			
		// Code to execute
		escribeCD(n, d, e);

		t1 = clock();

		double time = (double(t1 - t0) / CLOCKS_PER_SEC);
		cout << "Execution Time: " << time << endl;
		
	}
}