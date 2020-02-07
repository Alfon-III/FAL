#include <iostream>
using namespace std;

void resuelveCaso(int n);

int main() {

	int paises; cin >> paises;

	while (paises != 0) {
		resuelveCaso(paises);
		cin >> paises;
	}

	return 0;
}

void resuelveCaso(int n) {

	int v[100000];
	long long int total = 0;
	int i = 0;

	while (i < n) {
		cin >> v[i];
		i++;
	}

	long long int ret = 0;

	i = 0;
	while (i < n) {
		ret += total * v[i];
		total += v[i];
		i++;
	}



	cout << ret << endl;
}