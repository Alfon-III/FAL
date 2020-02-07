#include <iostream>
#include <algorithm>    // std::min
using namespace std;

int v[2048];

bool ordenado(int v[], int ini, int fin, int& minI, int& maxD, int& sum) {
	//OLVIDAR SUM, pensaba que maxDer >= sumIzq y minIzq <= SumDer pero he leido mal el problema por que soy listisimoi
	if (fin == ini) {
		minI= maxD = sum =  v[ini];
		return true;
	}
	int mid = (ini + fin) / 2;

	int minDer, minIzq, maxDer, maxIzq;
	int sumDer, sumIzq;
	

	
	if (ordenado(v, ini, mid, minIzq, maxIzq, sumIzq) && ordenado(v, mid + 1, fin, minDer, maxDer, sumDer)) {
		if (maxDer >= maxIzq && minIzq <= minDer) {//aquí está la magia
			sum = sumDer + sumIzq;
			minI = min(minIzq, minDer);
			maxD = max(maxIzq, maxDer);
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	
}

int main() {

	int n = 0;
	int aux;
	cin >> aux;
	while (aux != 0) {
		while (aux != 0) {
			v[n] = aux;
			cin >> aux;
			n++;
		}
		
		/*for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;*/
		

		//cout << n;
		int sum, max, min;
		if (ordenado(v, 0, n - 1, min, max, sum)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}

		cin >> aux;
		n = 0;
	}

	return 0;
}

/*

	for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
*/