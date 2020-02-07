#include <iostream>
using namespace std;
int v[100000];
void resuelve(int v[], int n);

int main() {

	int n; cin >> n;

	while (n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		resuelve(v, n);
		cin >> n;
	}

	return 0;
}

void resuelve(int v[], int n) {
	int suma = 0;

	for (int i = 0; i < n; i++) {
		suma += v[i];
	}

	int ret = 0;
	int aux = suma - v[ret];
	bool enc = false;

	while (ret < n && !enc) {
		enc = (v[ret] == aux);
		ret++;
		aux -= v[ret];
	}


	if (ret == n) {
		cout << "NO" << endl;
	}
	else {
		cout << "SI " << ret << endl;
	}

}