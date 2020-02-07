#include <iostream>
#include <cmath>
using namespace std;

char resuelve(unsigned long long n, int k, unsigned long long tot);
int calculaCota(int k);

int main() {
	
	unsigned long long n;
	int k;

	while (cin >> k >> n) {
		unsigned long long tot = 0;
		unsigned long long aux = 0;
		unsigned long long b = 3;
		unsigned long long cont = 0;
		while (cont < k) {
			aux = tot;
			tot = b + tot * 2;
			cont++;
			b++;
		}
		cout << resuelve(n, k,tot) << endl;
	}

	return 0;
}

//como mucho se ejecuta 60 veces
int calculaCota(int k) {
	unsigned long long tot = 0;
	unsigned long long aux = 0;
	unsigned long long b = 3;
	unsigned long long cont = 0;
	while (cont < k) {
		aux = tot;
		tot = b + tot * 2;
		cont++;
		b++;
	}
	//cout << endl << " -> " <<aux<<" // "<<aux + b - 1<<endl;
	return aux + 1;
}

char resuelve(unsigned long long n, int k, unsigned long long tot) {
	unsigned long long aux = ((tot - k - 2) / 2) + 1;
	//cout << endl << " -> " <<aux<<" // "<<aux + k - 1<<endl;
	if (n < 3) {
		if (n == 1) return 'B';
		else if (n == 2) return 'U';
		else if (n == 3) return 'H';
	}
	else {
		//Esta en medio
		if (n >= aux && n <= aux + k + 1) {
			//cout << "MEDIO" << endl;
			if (n == aux) return 'B';
			else if (n == aux + k + 1) return 'H';
			else return 'U';
		}
		//esta al principio
		if (n < aux) {
			//cout << "IZQUIERDA" << endl;
			return resuelve(n, k - 1, (tot - 2 - k)/2);
		}
		else{//esta al final (n > aux + k + 1)
			//cout << "DERECHA" << endl;
			return resuelve(n - (aux + k + 1), k - 1, (tot - 2 - k) / 2);
		}
	}
}
