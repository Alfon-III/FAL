#include <iostream>
using namespace std;

int main() {
	int casos; cin >> casos;
	int cont = 0;

	while (cont < casos) {
		int n;

		cin >> n;
		if (n == 0) cout << "1" << endl;
		else if (n == 1) cout << "1" << endl;
		else if (n == 2) cout << "2" << endl;
		else if (n == 3) cout << "6" << endl;
		else if (n == 4) cout << "4" << endl;
		else cout << "0" << endl;
		cont++;
	}

	return 0;
}