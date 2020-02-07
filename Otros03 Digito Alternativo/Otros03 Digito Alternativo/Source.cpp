#include <iostream>
using namespace std;

long long resuelve(long long n, int numD) {
	if (n <= 10) {
		return 10;
	}
	if (n % 10 == 0) {
		int resta = (n / 10) % 10;
		int numDif = (pow(10, numD) - 10) / 2;

		return numDif + (n % 10) / 2 + (resuelve(((n / 10) - resta), numD - 1));
	}
	else {
		return (n % 10) / 2 + resuelve((n - n % 10), numD - 1);
	}
}

int main() {
	long long n;
	cin >> n;
	int numD = 0;
	while (n != -1) {
		if (n <= 10) {
			cout << n << "\n";
		}
		else {
				
			cout << resuelve(n, numD) << "\n";
		}
		cin >> n;
	}
	return 0;

}

/*bool alternado(int n) {
	bool correcto = true;
	int aux1, aux2;
	while (n > 10  && correcto) {
		aux1 = n % 10;
		aux2 = ((n % 100) / 10);
		if (!((aux1 % 2 == 0 && aux2 % 2 == 1) ||
			(aux1 % 2 == 1 && aux2 % 2 == 0) )){
			correcto = false;
		}
		n = n / 10;
	}
	return correcto;
}


int main() {
	int n;
	cin >> n;
	int ret;
	while (n != -1) {
		ret = 0;
		for (int i = 1; i <= n; i++) {
			if (alternado(i)) {
				ret++;
			}
		}

		cout << ret << endl;
		cin >> n;
	}

	return 0;
}
*/