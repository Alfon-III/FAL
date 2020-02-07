#include <iostream>
#include <math.h>
using namespace std;
int calculaPeso(int peso);

int main() {

	int pesoMax;
	cin >> pesoMax;
	while (pesoMax > 0 && pesoMax<pow(10, 9)) {//bucle principal, se repite hasta que el peso == 0
		
		
		cout << calculaPeso(pesoMax) << endl;
		cin >> pesoMax;
	}
}

int calculaPeso(int peso) {
	int valor, contador = 0;
	int total = 0;
	cin >> valor;
	while (valor > 0) { //se introducen valores hasta que el peso de un elefante sea 0
		total = total + valor;
		if (total <= peso) {
			contador++;
		}
		cin >> valor;
	}
	return contador;
}
