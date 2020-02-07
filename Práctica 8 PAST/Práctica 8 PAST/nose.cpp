#include <iostream>
using namespace std;




void escribeTablero(int roto[9], int r[9], int t[9], int tam) {
	for (int i = 0; i < tam; i++) {//X
		for (int j = 0; j < tam; j++) {//Y
			if (r[j] == i) {
				cout << "R ";
			}
			else if(t[j] == i){
				cout << "T ";
			}
			else if(roto[j] == i){
				cout << "[]";
			}
			else {
				cout << ". ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

bool esValido(int roto[9], int r[9], int t[9], int nTorres, int nReinas, char tipo) {
	int i, j;
	int nuevo = nTorres + nReinas - 1;
	int tam = nuevo + 1;
	if (tipo == 'R') {

	
		//la nueva REINA es apta para el resto de REINAS
		for (int i = 0; i < tam - 1; i++) {
			if (roto[i] == r[nuevo]) {
				return false;
			}
			if (r[i] != -1) {
				if (r[i] == r[nuevo]) {
					return false;
				}
				if (abs(r[nuevo] - r[i]) == abs(nuevo - i)) {
					return false;
				}
		
				if (abs(r[nuevo] - t[i]) == abs(nuevo - i)) {
					return false;
				}
				if (t[i] == r[nuevo]) {
					return false;
				}
			}
		}


	}

	if (tipo == 'T') {
		//la nueva TORRE es apta para el resto de REINAS

		for (int i = 0; i < tam; i++) {

			if (roto[i] == t[nuevo]) {
				return false;
			}
			if(r[i] != -1){

				if (r[i] == t[nuevo]) {
					return false;
				}
				if (abs(t[nuevo] - r[i]) == abs(nuevo - i)) {
					return false;
				}
				if (t[i] == t[nuevo]) {
					return false;
				}
			}
		}


	}

	return true;
}

void pintaTodas(int r[9], int t[9], int roto[9],int n_reinas,int n_torres,int maxReina, int maxTorre, int tam) {
	if (n_reinas + n_torres == tam) {
		//cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
		escribeTablero(roto, r, t, tam);
		return;
	}
	if (n_reinas < maxReina) {//Primero pinto todas las posibles reinas
		for (int i = 0; i < tam; i++) {
			
			
			r[n_torres + n_reinas] = i;
			//escribeTablero(roto, r, t, tam);
			if (esValido(roto, r, t, n_torres, n_reinas + 1, 'R')) {//prometedor
				pintaTodas(r, t, roto, n_reinas + 1, n_torres, maxReina, maxTorre, tam);
			}
			
			
		}
		r[n_torres + n_reinas] = -1;
	}
	if (n_torres < maxTorre) {
		for (int i = 0; i < tam; i++) {
			
			t[n_torres + n_reinas] = i;
			//escribeTablero(roto, r, t, tam);
			if (esValido(roto, r, t, n_torres + 1, n_reinas, 'T')) {//prometedor
				pintaTodas(r, t, roto, n_reinas, n_torres + 1, maxReina, maxTorre, tam);
			}
			
		}
		t[n_torres + n_reinas] = -1;//en caso de que no encuentre nada
	}
	

}



int main() {
	int r[9];
	int t[9];
	int roto[9];
	int nTorres, nReinas, invalid,inv_x, inv_y, tam;

	while (cin >> nTorres >> nReinas) {
		tam = nTorres + nReinas; // tam <= 9 siempre
		cin >> invalid;

		for (int i = 0; i < tam; i++) {//evito valores basura
			r[i] = -1;
			t[i] = -1;
			roto[i] = -1;
		}
		

		for (int i = 0; i < invalid; i++) {
			cin >> inv_x >> inv_y;
			roto[inv_x] = inv_y;
		}

		

		pintaTodas(r, t, roto, 0, 0, nReinas, nTorres, tam);
	}

	return 0;
}