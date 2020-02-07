#include <iostream>
using namespace std;

string combina(string pre, int c, int v) {
	string aux;
	if ((c == 0) && (v == 0)) {
		aux +=  (pre + " ");
	}
	if (c > 0) {
		aux +=  combina(pre + "C", c - 1, v);
	}
	if (v > 0) {
		aux += combina(pre + "V", c , v - 1);
	}

	return aux;
}


int main() {
	int n, c, v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> c >> v;
		string aux = combina("", c, v);
		cout <<aux.substr(0, aux.size() - 1)  << endl;//el último pero sin el espacio
	}
	return 0;
}