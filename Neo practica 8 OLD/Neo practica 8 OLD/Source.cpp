#include <iostream>
using namespace std;




void print(int r[8], int t[8], int tam) {
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			if (r[j] == i) {
				cout << " R";
			}
			else if (t[j] == i) {
				cout << " T";
			}
			else {
				cout << " .";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void printNum(int tab[8][8], int tam) {
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			cout << tab[i][j];
		}
		cout << endl;
	}
	cout << endl;
}


int libres(int tab[8][8], int tam) {
	int libres = 0;

	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			if (tab[i][j] == 0) {
				libres++;
			}
		}
	}
	return libres;
}

bool noDiagonal(int r[8], int t[8], int k) {

	int tam = k + 1;

	bool choca = true;
	for (int i = 0; i < tam - 1; i++) {
		if (r[i] != -1) {

			if (abs(r[k] - r[i]) == abs(k - i)) {
				return false;
			}
		}

		if (t[i] != -1) {
			//cout << r[k] <<" "<< t[i] << " " << abs(r[k] - t[i]) << " " << abs(k - i) << endl;
			if (abs(r[k] - t[i]) == abs(k - i)) {
				//cout << "nope" << endl;
				return false;
			}

		}
	}
	return choca;
}

int tablero(
	//Info problema
	int r[8],
	int nReinas,
	int t[8],
	int nTorres,

	//Sol parcial
	int tab[8][8],
	int kReinas,
	int kTorres
	//marca


) {
	//--------------------------------AL TURRÓN
	int tam = nReinas + nTorres;
	int k = kTorres + kReinas;
	if (tam == k) {
		print(r, t, tam);
		return 1;
	}

	int libre = 10;
	int aux[8][8];
	int total = 0;

	if (kReinas < nReinas) {
		for (int i = 0; i < tam; i++) {
			r[k] = i;
			for (int x = 0; x < tam; x++) {
				for (int y = 0; y < tam; y++) {
					//copia de seguridad
					aux[x][y] = tab[x][y];

				}
			}
			//print(r, t, tam);
			if (tab[k][i] == 0 && noDiagonal(r, t, k)) {//casilla vacia
				//Pongo que las casillas se incrementan en 1 en piezas que la atraviesan

				for (int x = 0; x < tam; x++) {
					for (int y = 0; y < tam; y++) {
						//horizontal y vertical
						if (x == k) {

							aux[k][y]++;
						}
						if (y == i) {
							aux[x][i]++;

						}

						//diagonales
						if (abs(i - y) == abs(k - x)) {
							aux[x][y]++;
						}

					}
				}

				//resto el exceso
				aux[k][i] = aux[k][i] - 2;
				//printNum(aux, tam);
				//print(r, t, tam);
				//cuento si quedan casillas libres para evitar este despropósito

				//libre = libres(aux, tam);
				//Si hay heco, merece la pena comprobarlo
				if (libre > 0) {
					total += tablero(r, nReinas, t, nTorres,
						aux, kReinas + 1, kTorres);
				}


			}
		}
		r[k] = -1;
	}
	if (kTorres < nTorres) {
		for (int i = 0; i < tam; i++) {
			t[k] = i;

			for (int x = 0; x < tam; x++) {
				for (int y = 0; y < tam; y++) {
					//horizontal y vertical
					aux[x][y] = tab[x][y];

				}
			}

			if (tab[k][i] == 0) {//casilla vacia
				//Pongo que las casillas se incrementan en 1 en piezas que la atraviesan

				for (int x = 0; x < tam; x++) {
					for (int y = 0; y < tam; y++) {
						//horizontal y vertical
						if (x == k) {

							aux[k][y]++;
						}
						if (y == i) {
							aux[x][i]++;

						}


					}
				}

				//resto el exceso
				aux[k][i] = aux[k][i] - 2;

				//cuento si quedan casillas libres para evitar este despropósito
				//printNum(aux, tam);
				//libre = libres(aux, tam);
				//Si hay heco, merece la pena comprobarlo
				if (libre > 0) {
					total += tablero(r, nReinas, t, nTorres,
						aux, kReinas, kTorres + 1);
				}


			}
		}
		t[k] = -1;
	}

	return total;
}


int main() {
	int nTorres, nReinas, invalid, invX, invY, tam;
	int r[8];
	int t[8];
	int tab[8][8];

	while (cin >> nTorres >> nReinas) {

		tam = nTorres + nReinas;
		//pongo el tablero a 0
		for (int i = 0; i < tam; i++) {
			for (int j = 0; j < tam; j++) {
				tab[i][j] = 0;
			}
			r[i] = -1;
			t[i] = -1;
		}
		//Para cada casilla no valida, pongo un 1, que significa que ya pasa alguien por ahí
		cin >> invalid;
		for (int i = 0; i < invalid; i++) {
			cin >> invX >> invY;
			tab[invX][invY] = 1;
		}

		cout << tablero(r, nReinas, t, nTorres, tab, 0, 0) << endl;

	}

	return 0;

}