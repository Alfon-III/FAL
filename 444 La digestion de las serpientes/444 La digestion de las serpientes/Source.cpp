#include <iostream>
using namespace std;

int resuelve(int n, int k);

int main() {

	int n, k;
	cin >> n;
	cin >> k;

	while (n != 0 || k != 0) {
		cout << resuelve(n, k) << endl;
		cin >> n;
		cin >> k;
	}

	return 0;
}



int resuelve(int n, int k) {

	int i, aux, cont, max, tiempo;
	bool start;

	start = false;
	cont = 0;
	max = 0;
	tiempo = 0;
	
	i = 0;
	while (i < n) {
		cin >> aux;
		if (aux == 1) {
			cont++;
			if (start) {
				cont += tiempo;
				tiempo = 0;
			}
			start = true;
		}
		else {
			if (start) {
				tiempo++;
			}
			if (tiempo > k && start) {
				tiempo = 0;
				cont = 0;
				start = false;
			}
		}
		if (cont > max) {
			max = cont;
		}
		i++;
	}


	return max;
}