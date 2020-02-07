#include <iostream>
using namespace std;

//	n < alfa
bool limpio(int d, int alfa, unsigned long long n) {

	int cont = 0;
	while (n != 0 && cont < alfa) {
		if (n % 10 == d) {
			cont++;
		}
		else {
			cont = 0;
		}
		n = n / 10;
	}
	//En caso que n = 0 y d = 0
	if (n % 10 == d) {
		cont++;
	}

	return (n == 0 && cont < alfa);
}

int main() {
	int d, alfa;
	unsigned long long n;

	cin >> d >> alfa >> n;
	while (d != -1) {

		if (limpio(d, alfa, n)) {
			cout << "SI\n";
		}
		else {
			cout << "NO\n";
		}

		cin >> d >> alfa >> n;
	}
	return 0;
}