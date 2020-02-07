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
/*Necestito marcaje para pasar un array de boolenaos y descartar rápidamente gente que ya se ha sentado o no, para usar un solo bucle*/

int busca(int solucion[], int k, int x) {
	for (int i = 0; i < k; i++) {
		if (solucion[i] == x) {
			return i;
		}
	}


}

bool esValida(int solucion[], int k, Restriccion restricciones[], int nRestricciones, bool libre[]) {
	bool correcto = true;
	
	int a, b, p;

	for (int j = 0; j < nRestricciones; j++) {
		
		a = restricciones[j].a;
		b = restricciones[j].b;

		if (restricciones[j].a == solucion[k] && !libre[b]) {//Si k es a y b está en el array
			p = busca(solucion, k, b);
			
			if ((k - p < abs(restricciones[j].dist)) && !restricciones[j].amigos) {
				correcto = false;
			}
			else if ((k - p > abs(restricciones[j].dist)) && restricciones[j].amigos) {
				correcto = false;
			}
		}
		else if (restricciones[j].b == solucion[k] && !libre[a]) {
			p = busca(solucion, k, a);
			
			if ((k - p < abs(restricciones[j].dist)) && !restricciones[j].amigos) {
				correcto = false;
			}
			else if ((k - p > abs(restricciones[j].dist)) && restricciones[j].amigos) {
				correcto = false;
			}
		}


		
			
		
	}

	return correcto;
}




int cuantas(
	// Descripción del problema
	int n, // Personas a sentar
	Restriccion restricciones[],
	int nRestricciones,
	//Sol parcial
	int k,
	int solucion[], 
	//marcaje
	bool libres[]

	// ... Añade otros parámetros si los necesitas ...
) {

	/*
	Si restricciones son 0 , devolver el factorial para que no sea fuerza bruta*/


	if (k == n) {
		/*for (int i = 0; i < n; i++) {
			cout << solucion[i] << " ";
		}
		cout << "\n";*/
			
		return 1;
	}


	int cont = 0;
	for (int i = 0; i < n; i++) {
		if (libres[i]) {
			solucion[k] = i;
			libres[i] = false;
			if (esValida(solucion, k, restricciones, nRestricciones, libres)) {
				cont += cuantas(n, restricciones, nRestricciones, k + 1, solucion, libres);

			}
			libres[i] = true;
		}
	}

	return cont;


	// ...

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
	bool libres[MAX_N];
	for (int i = 0; i < n; ++i) {
		libres[i] = true;
	}

	int k = 0;
	int cont = 0;
	int solucion[MAX_N];
	int ret = cuantas(n, restricciones, m, k, solucion, libres);

	cout << ret << '\n';

	return true;

} // resuelve

int main() {

	while (resuelve())
		;

	return 0;
} // main