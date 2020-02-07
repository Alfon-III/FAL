#include <iostream>
using namespace std;



/*
4
1 2
2
1 2
7 5

2 3
2 3
4 1 5
20 1 15
15 1 5

3 6
2 3 6
2 2 5 4 8 9
10 25 6 12 20 8
5 14 10 10 13 9
16 16 17 12 11 5

10 15
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

Este último casoi es para ver si es eficiente y bueno... Pichi picha, 
igualemte la solucion del profesor es tal y como describo abajo, por tanto no es necesario 
poner ni cota ni poda, mas q nada por q no se le ocurre ni a el como carajo hacerlo xdd

*/

int calidad[50][50];//[maquina][carretera]
int aMaquina[50];
int aCalle[50];

void mayorCalidad(
	//Datos del problema
	int m,
	int n,
	int aMaquina[],
	int aCalle[],
	//Solucion parcial
	int k, //maquinas colocadas
	bool calleTomada[],//que calles no pueden ser usadas
	int calidAcumulada,
	//Poda
	int calidadPotencial,//par ver si podemos llegar a la maxCalidad
	//Mejor solucion 
	int& maxCalidad
) {
	if (k == m) {
		//cout << "Calidad acumulada: " << calidAcumulada << endl;
		if (calidAcumulada > maxCalidad) {
			maxCalidad = calidAcumulada;
		}
		return;
	}
	//n = calle y k = camimion, este for viene a ser que para el camión k, vamos a ver por qué calle puede circular y si cabe
	//En tal caso, ocupamos la calle, sumamos la calidad y llamamos al siguiente camión a ver si tiene suerte y sube el listón de la calidad,
	//Pero eso es problema de otro... Pobre imbécil el k+1 (siguiente camión) 
	for (int i = 0; i < n; i++) {
		if ((aMaquina[k] <= aCalle[i]) && (!calleTomada[i])) {//Reviso q el coche quepa y que la calle no esté ocupada por otro coche
			calleTomada[i] = true;
			mayorCalidad(m, n, aMaquina, aCalle, k + 1, calleTomada, calidAcumulada + calidad[k][i], calidadPotencial, maxCalidad);
			calleTomada[i] = false;//No olvidar ponerlo como desocupado, por que si no empezamos a ocupar carriles y es un despiporre!
		}
	}

}

/*Fuera coñas esto es lo más dificil*/
int main() {
	int casos, m, n;
	bool calleTomada[50];
	cin >> casos;

	for (int c = 0; c < casos; c++) {
		cin >> m >> n;
		//Introducimos tamCamion
		for (int i = 0; i < m; i++) {
			cin >> aMaquina[i];
		}
		//Introducimso tamCalle
		for (int i = 0; i < n; i++) {
			cin >> aCalle[i];
			calleTomada[i] = false;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {//[maquina][carret]
				cin >> calidad[i][j];
			}
		}
		int dummy;

		mayorCalidad(m, n, aMaquina, aCalle, 0, calleTomada, 0, 0, dummy);
		cout << "Mejor calidad: " << dummy << endl;
	}
	return 0;
}