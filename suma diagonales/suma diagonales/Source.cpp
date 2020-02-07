#include <iostream>
using namespace std;



int main() {
	int max;
	int x, y;
	cin >> x >> y;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (abs(y - j) == abs(x - i)) {
				cout << i << " " << j << endl;
			}
		}

	}

	return 0;
}