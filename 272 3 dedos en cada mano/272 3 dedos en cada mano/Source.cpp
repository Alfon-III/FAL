#include <iostream>
#include <cmath>
using namespace std;

int bender(int k, int sumDig);

int main() {
	int i, n, k;
	cin >> n;
	i = 0;
	while (i < n) {
		cin >> k;
		cout << bender(k, 0) << endl;
		i++;
	}
	return 0;
}

int bender(int k, int sumDig){
	if (k < 6) {
		return (k * (pow(10, sumDig)));
	}
	else {
		int aux = k / 6;
		int res = k % 6;

		return bender(aux, sumDig + 1) + res * (pow(10, sumDig));
	}
}
