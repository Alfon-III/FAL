#include <iostream>
using namespace std;

int total;

int fractal(int l);

int main() {
	int n;

	while (cin >> n) {
		fractal(n);
		cout << fractal(n) <<endl;
		total = 0;
	}
	return 0;
}

int fractal(int l) {
	int n;
	if (l == 1) {
		n = 4;
	}
	else {//tamaño del cuadrado actual + tam de las 4 esquinas
		n = l * 4 + (4 * fractal(l / 2));
	}
	return n;
}
