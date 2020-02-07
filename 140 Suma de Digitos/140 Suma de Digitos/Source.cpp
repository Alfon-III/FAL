#include <iostream>
using namespace std;

int sumaDig(int n);

int main() {
	int n;
	cin >> n;
	while (n >= 0) {
		int aux = sumaDig(n);
		cout <<" = "<< aux << endl;
		cin >> n;
	}

	return 0;
}

/*
sumaDig(1234)
sumaDig(123)
sumaDig(12)
sumaDig(1)
Muestra 1 
Muestra 2
Muestra 3
Muestra 4
*/


int sumaDig(int n) {
	int sum;
	if (n < 10) {
		cout << n ;
		return n;
	}
	else {
		sum = sumaDig(n / 10) + n % 10;
		cout << " + " << n % 10;
		return sum;
	}
}