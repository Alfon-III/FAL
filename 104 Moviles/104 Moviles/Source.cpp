#include <iostream>
using namespace std;

bool movil(int p1, int d1, int p2, int d2, int& total) {
	//caso base -> movil con pesos
	if (p1 != 0 && p2 != 0) {
		if (p1 * d1 == p2 * d2) {
			total = p1 + p2;
			return true;
		}
		else {
			return false;
		}
	}

	//caso recursico aka hay un sub-movil, tengo que analizar ambos extremos
	bool a = true, b = true;
	if (p1 == 0) {//rec en ex izq
		int p1a, p2a, d1a, d2a;
		cin >> p1a >> d1a >> p2a >> d2a;
		a = movil(p1a, d1a, p2a, d2a, total);
		p1 = total;
	}
	if (p2 == 0) {//recv en ex dcho
		int p1b, p2b, d1b, d2b;
		cin >> p1b >> d1b >> p2b >> d2b;
		b = movil(p1b, d1b, p2b, d2b, total);
		p2 = total;
		
	}

	total = p1 + p2;
	return (a && b && (p1 * d1 == p2 * d2));
}


int main() {
	int p1, p2, d1, d2, dummy = 0;
	cin >> p1 >> d1 >> p2 >> d2;
	while (!(p1 == 0 && d1 == 0 && p2 == 0 && d2 == 0)) {
		if (movil(p1, d1, p2, d2, dummy)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		cin >> p1 >> d1 >> p2 >> d2;
	}
	return 0;
}