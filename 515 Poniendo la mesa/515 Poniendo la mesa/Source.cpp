#include <iostream>
using namespace std;

int mesa(int n, int h);
/*
h == 0 -> Hermano pequeño
h == 1 -> Hermano mayor
*/
int main() {
	int n;
	cin >> n;
	while (n != 0) {
		cout << mesa(n, 0)<< endl;
		cin >> n;
	}

	return 0;
}

int mesa(int n, int h) {
	if (n == 0) {
		return 0;
	}
	//si aún quedan copas...
	if (h == 0) {
		return 1 + mesa(n - 1, 1);
	}
	else {
		if (n % 2 == 0) {//par
			return 1 + mesa(n - 2, 0);
		}
		else {//impar
			return 1 + mesa(n - 1, 0);
		}
	}


}