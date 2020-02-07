#include <iostream>
using namespace std;

int divide(int f, int n);

int main() {
	int f, n;
	cin >> f;
	cin >> n;
	while (f != 0) {
		cout << divide(f, n) << endl;
		cin >> f >> n;
	}
	return 0;
}

int divide(int f, int n) {
	if (n <= 2 * f) {
		return 0;
	}
	else {
		return 1 + divide(f, n / 3) + divide(f, n - (n / 3));
	}
}