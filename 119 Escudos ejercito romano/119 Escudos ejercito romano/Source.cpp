#include <iostream>
#include <cmath>
using namespace std;

int calculaEscudos(int n);
void soldados(int n);


int main() {
	
	int n; cin >> n; 
	while(n != 0) {
		soldados(n);
		cin >> n;
	}


	return 0;
}

void soldados(int n) {
	int aux, total = 0;

	while (n!=0) {
		aux = sqrt(n);
		total += calculaEscudos(aux * aux);
		n -= pow(aux, 2);
	}

	cout << total << endl;

}

int calculaEscudos(int n) {//recubo un numero elevado al cuadardo
	int total = 0;

	int raso, lat, esq;//raso, lateral, esquina

	if (n == 1) {//si la formacion es de un soldado, llevara 5 escudos
		total = 5;
	}
	else {
		//escuderos rasos, solo se cubren la cabeza
		raso = pow(sqrt(n) - 2, 2);
		total += raso;

		// los que estan en los laterales pero no en las esquinas, levan 2 escudos
		lat = ((n - raso) - 4);
		total += lat * 2;

		total += 12; //siempre son 4, pues hay 4 esquinas, llevan 3 escudos = 12
	}

	return total;
}