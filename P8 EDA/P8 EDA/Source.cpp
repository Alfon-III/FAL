//---------------------------------------------------
// Ejercicio "Una tarde en el cine"
// Estructura de Datos y Algoritmos
// Facultad de Informática
// Universidad Complutense de Madrid
//---------------------------------------------------


#include <iostream>
#include <algorithm> // Para función abs().
using namespace std;

#define MAX_N 10
#define MAX_R 20

struct Restriccion {
	int a;
	int b;
	bool amigos; // true si son amigos (dist será la distancia máxima)
	int dist; // Siempre positivo (se quita el signo en la lectura)
};


// ... Añade otras funciones si las necesitas ...

int distancia(int a, int b, int grupo[MAX_N], int k) {
	int i = 0; 
	bool encontrado = false;
	while (i < k && !encontrado) {

	}
}

bool cumpleRes(Restriccion res[], int m, int grupo[MAX_N], int k) {
	

	for (int i = 0; i < m; i++) {

		if (res[i].amigos) {

		}



	}
	return true;
}

int cuantas(
	// Descripción del problema
	int n, // Personas a sentar
	Restriccion restricciones[],
	int nRestricciones,
	int personas[MAX_N],

	//Sol parcial
	int grupo[MAX_N],
	bool perSelect[MAX_N],
	int k

	) {
	int total = 0;
	if (n == k) {

		for (int i = 0; i < n; i++) {
			cout << grupo[i] << " ";
		}
		cout << endl;
		return 1;
	}

	for (int i = k; i < n; i++) {
		
		if (perSelect[i]) {//si es valida
			perSelect[i] = false;
			
			grupo[k] = personas[i];
		}
		total += cuantas(n, restricciones, nRestricciones,personas, grupo, perSelect, k + 1);
		perSelect[i] = true;

	}
	return total;
}


bool resuelve() {

	Restriccion restricciones[MAX_R];
	// ... Añade otras declaraciones si las necesitas ...

	// Lectura

	int n, m;
	cin >> n >> m;

	if (!n && !m)
		return false;

	for (int i = 0; i < m; ++i) {
		cin >> restricciones[i].a
			>> restricciones[i].b
			>> restricciones[i].dist;
		restricciones[i].amigos = restricciones[i].dist > 0;
		restricciones[i].dist = abs(restricciones[i].dist);
	}

	//Sol parcial

	int grupo[MAX_N];
	int personas[MAX_N];
	bool perSelect[MAX_N];
	int col = 0;

	for (int i = 0; i < n; i++) {
		personas[i] = i;
		grupo[i] = i;
		perSelect[i] = true;
	}

	int ret = cuantas(n, restricciones, m,personas,  grupo, perSelect, 0);

	cout << ret << '\n';

	return true;

} // resuelve

int main() {

	while (resuelve())
		;

	return 0;
} // main