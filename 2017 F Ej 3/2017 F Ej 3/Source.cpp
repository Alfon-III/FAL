#include <iostream>
using namespace std;

int torre[1000];

/*
azul = 1
rojo = 2
verde= 3
*/

void escribe(int torre[], int n) {
	for (int i = 0; i < n; i++) {
		if (torre[i] == 1) cout << "azul";
		else if (torre[i] == 2) cout << "rojo";
		else if (torre[i] == 3) cout << "verde";

		cout << " ";
	}
	cout << endl;
}

int escribeTorre(
	//Datos del problema
	int n,
	int torre[],
	int a,
	int r,
	int v,
	//Sol parcial
	int k,
	//contador de piezas ya colocadas
	int n_azul,
	int n_rojo,
	int n_verd,
	//Marcaje
	int r_poten
	//Poda

) {
	if (n - 1 == k) {
		
		escribe(torre, n);
		
		return 1;
	}
	int nTorres = 0;

	//cout << freePos << "  " << r_poten << endl;

	


	int freePos = n - k - 1;
	if (r_poten > freePos ) {
		r_poten = freePos;
	}

	if ((1 + n_verd + n_azul) < n_rojo + r_poten) {
		/*PONGO AZUL si:
			- Cortar si no podemos prometer que al final no haya más n_azul  + n_verde > n_rojas
			- QUEAN PIEZAS AZULES
		*/
		if (n_azul < a) {
			torre[k + 1] = 1;
			nTorres = escribeTorre(n, torre, a, r, v, k + 1, n_azul + 1, n_rojo, n_verd, r_poten);
		}

		/*PONGO VERDE si:
			-Anterior no es verde
			- n_azul > n_verde
			- Cortar si no podemos prometer que al final no haya más n_azul  + n_verde > n_rojas
			- QUEAN PIEZAS VERDES
		*/
		if (torre[k] != 3 && n_azul > n_verd && n_verd < v) {
			torre[k + 1] = 3;
			nTorres = escribeTorre(n, torre, a, r, v, k + 1, n_azul, n_rojo, n_verd + 1, r_poten);
		}
	}
	
	/*PONGO ROJO si:
		- QUEAN PIEZAS ROJAS
	*/


	if (n_rojo < r) {
		torre[k + 1] = 2;
		nTorres = escribeTorre(n, torre, a, r, v, k + 1, n_azul, n_rojo + 1, n_verd, r_poten - 1);
	}

	return nTorres;
}

void resuelve(int n, int a, int r, int v) {
	if (r < 2) {
		//en caso de no tener al menos 2 piezas rojas, nunca se podrá realizar la torre
		//Lo compruebo aquí para dejar más limpio el caso de vuelta atrás
		cout << "SIN SOLUCION" << endl;
	}
	else {
		//Pongo la base en rojo, pues en todos los casos empieza así
		torre[0] = 2;
		if (escribeTorre(n , torre, a, r, v, 0, 0, 1, 0, a - 1) == 0) {
			cout << "SIN SOLUCION" << endl;
		}
	}
}

int main() {

	int n, a, r, v;

	cin >> n >> a >> r >> v;

	while (n != 0 && a != 0 && r != 0 && v != 0) {
		resuelve(n, a, r, v);
		cin >> n >> a >> r >> v;
	}

	return 0;
}