#include <iostream>
using namespace std;

bool v[100];

/*

8 0 0 1 0 0 1 0 1 2
4 1 0 1 0 1
4 1 0 1 0 2
1 1 1
4 1 0 1 0 3
0 1

*/

int menorTramo(bool v[], int n, int k) {
	int ret = n + 1, numTrue = 0;
	int a = 0, b = 0;
	//Mientras que queden elementos o haya mas trues que k, 
	//en tal ca<so hay que reducir 
	while (b < n || numTrue >= k) {

		if (numTrue < k) {//ampliamos ventana
			if (v[b]) {
				numTrue++;
			}
			b++;
		}
		else {//reducimos
			if (v[a]) {
				numTrue--;
			}
			a++;
		}

		if ((numTrue == k) && ((b - a) < ret)) {
			ret = b - a;
		}
	}

	return ret;
}

int main() {
	int n, aux, k;
	cin >> n;
	while (n != -1) {
		for (int i = 0; i < n; i++) {
			cin >> aux;
			if (aux == 1) {
				v[i] = true;
			}
			else {//aux == 0
				v[i] = false;
			}
		}

		cin >> k;

		cout <<"Menor tramo es: "<<menorTramo(v, n, k) << endl;

		cin >> n;
	}
	return 0;
}