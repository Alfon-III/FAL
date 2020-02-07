#include <iostream>
using namespace std;

bool esPoli(int n);
int numDig(int n);

int main() {

	int n;
	bool poli;
	while (cin >> n) {
		poli = esPoli(n);
		if (poli) {
			cout << "POLIDIVISIBLE" << endl;
		}
		else {
			cout << "NO POLIDIVISIBLE" << endl;
		}
	}

	return 0;
}

int numDig(int n) {
	int ret = 0;

	while (n != 0) {
		n = n / 10;
		ret++;
	}
	//cout << ret << endl;
	return ret;
}

bool esPoli(int n) {
	if (n < 10) {
		return true;
	}

	int nd = numDig(n);
	if ((n % nd) == 0) {
		return esPoli(n / 10);
	}
	else {
		return false;
	}

}
