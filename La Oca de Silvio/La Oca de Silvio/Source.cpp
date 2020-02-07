#include <iostream>
#include <cmath>
#include <time.h> 
#include <stdlib.h>  

using namespace std;


int casillas(int n);

int main() {
	srand(time(0));
	int	dado;
	bool victoria = false;

	int posA = 0, posB = 0;
	int aux;
	while (!victoria) {
		dado = rand() % 6 + 1;
		posA = posA + dado;

		dado = rand() % 6 + 1;
		posB = posB + dado;

		aux = casillas(posA);
		posA = aux;
		aux = casillas(posB);
		posB = aux;

		cout << "A: " << posA << " B: " << posB << endl;

		if (posA >= 50 || posB >= 50) {
			victoria = true;
		}
	}

	if (posA >= 50) {
		cout << "Ha ganado A" << endl;
	}
	else if (posB >= 50) {
		cout << "Ha ganado B" << endl;
	}

	return 0;
}


int casillas(int n) {
	int nuevaPos = n;
	if (n == 6) {
		cout << "De Puente a puente y tiro por que me lleva la corriente" << endl;
		nuevaPos = 11;
	}
	else if (n == 11) {
		cout << "De Puente a puente ayy que me voy para atras" << endl;
		nuevaPos = 6;
	}
	else if (n == 42){
		cout << "Me he perdido en el laberinto vuelvo a la 30" << endl;
		nuevaPos = 30;
	}
	else if (n % 6 == 0) {
		cout << "De oca a oca y me sumo 2 por que me toca" << endl;
		nuevaPos = n + 6;
	}
	else if (n == 45) {
		cout << "MUERTE Y DESTRUCCION" << endl;
		nuevaPos = 0;
	}

	return nuevaPos;
}