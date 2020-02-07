#include <iostream>
using namespace std;

int M = 78787;

int main() {
	int m, N;
	while (cin >> m >> N) {
		int mul = 1; int sum = 0, h;
		cout << mul << endl;
		for (int i = 0; i < N / 2; i++) {
			cin >> h;
			sum = (sum + (m * h * mul) % M) % M;
			mul = (mul * 3) % M;
		}

		cout << mul << endl;

		if (N % 2 == 0) {
			mul = M - (26262 * mul) % M;
			cout << mul << endl;
		}
		else {
			cin >> h;
			sum = (sum + (m * h * mul) % M) % M;
			mul = M - (26262 * mul) % M;
			cout << mul << endl;
		}

		for (int i = 0; i < N / 2; i++) {
			cin >> h;
			sum = (sum + (m * h * mul) % M) % M;
			mul = M - (26262 * mul) % M;
			cout << mul << endl;
		}

		cout << sum << endl;
	}

	return 0;
}