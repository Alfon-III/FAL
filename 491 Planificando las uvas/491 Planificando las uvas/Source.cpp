#include <iostream>

using namespace std;


int combina(int max, int n, int v[], int k, int sum, int i) {
	if (k == 12 && sum <= max) {
		return 1;
	}
	if (i >= n) {
		return 0;
	}
	//si importase el orde, tendría que calcular todas las posibilidades, es decir, un array con las uvas No cogidas y permutarlas con el resto
	//En este caso, como NO IMPORTA EL ORDEN, la idea es Cojer o no cogerla
	int tot = combina(max, n, v, k + 1, sum + v[i], i + 1); //añado siguiente uva
	tot += combina(max, n, v, k, sum, i + 1); //no me como la siguiente uva

	return tot;
}

int main() {

	int v[25], max, n;
	while ((cin >> max >> n) && (max and n)) {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << combina(max, n, v, 0, 0, 0) << endl;
	}

	return 0;
}