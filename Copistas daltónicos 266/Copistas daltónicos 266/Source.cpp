#include <iostream>
using namespace std;
//constante gloval
const int max_col = 26;
char paleta_original[max_col] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

char nuevo_color(char a, char mut[max_col]);
void funcion(int n, int m);

int main() {

	
	//FASE 1: pido tamaño de n = ancho, m = alto
	int n, m; cin >> n; cin >> m;

	while (n != 0 && m != 0) {
		funcion(n, m);
		cin >> n; cin >> m;
	}

	return 0;
}


//dado un color a del dibujo original, devuelvo el color de la paleta transformada
char nuevo_color(char a, char mut[max_col]) {
	char x = ' ';
	for (int i = 0; i < max_col; i++) {
		if (a == paleta_original[i]) {
			x = mut[i];
		}
	}
	return x;
}


void funcion(int n, int m) {

const int max_paint = 500;

	char cuadro[max_paint][max_paint];
	char paleta[max_col] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	//FASE 2: relleno el cuadro (original)
	char aux[250];
	

	for (int i = 0; i < n; i++) {

		

		for (int j = 0; j < m; j++) {
			cin >> cuadro[i][j];
		}
	}
	//FASE 3: Leo los pintores y voy alterando la paleta en función de su daltonismo
	int p; cin >> p;
	for (int i = 0; i < p; i++) {
		char alfa, dalt;
		cin >> alfa, cin >> dalt;
		//ESTE (segundo) FOR ES "constante" o no lo contamos como for anidado, pues no es cuadrático
		for (int j = 0; j < max_col; j++) {
			if (alfa == paleta[j]) {
				paleta[j] = dalt;
			}
		}

	}

	//cout << endl;
	//FASE 4: Cambio el cuadro original por el alterado en función de la paleta alterada por los artista s daltonicos
	char t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			t = nuevo_color(cuadro[i][j], paleta);
			cuadro[i][j] = t;	
			cout << cuadro[i][j];
		}

		cout << endl;
	}


}