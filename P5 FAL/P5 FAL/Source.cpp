#include <iostream>
using namespace std; 

int long long SNN(long long int n);

int main() {
	long long int n;
	cin >> n;

	while (n != 0) {
		cout << SNN(n) << endl;
		cin >> n;
	}
	return 0;
}



long long int SNN(long long int n) {
	if (n < 10) {
		if (n == 1) {
			return 1;
		}
		else if (n == 2) {
			return 3;
		}
		else if (n == 3) {
			return 6;
		}
		else if (n == 4) {
			return 10;
		}
		else if (n == 5) {
			return 15;
		}
		else if (n == 6) {
			return 21;
		}
		else if (n == 7) {
			return 28;
		}
		else if (n == 8) {
			return 36;
		}
		else if (n == 9) {
			return 45;
		}
		else if (n == 0) {
			return 0;
		}

	}
	else {//n > 10
		long long int aux = n % 10;
		return (n / 10 * 45) + SNN(n / 10) + SNN(aux);

	}
}