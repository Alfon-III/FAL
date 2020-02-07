#include <iostream>
using namespace std;
const int max = 2000000;
int v[max];

bool esCreciente(int v[], int n);
bool porPelos(int v[], int ini, int fin);

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		if (esCreciente(v, n)) {
			cout << "ES CRECIENTE POR LOS PELOS" << endl;
		}
		else {
			cout << "NO POR LOS PELOS" << endl;
		}
		cin >> n;
	}
	return 0;
}

bool esCreciente(int v[], int n) {
	return porPelos(v, 0, n);
}

bool porPelos(int v[], int ini, int fin) {
	
	int mid = (ini + fin) / 2;//Operación peligrosa si ini y fin son números muy grandes
	if (v[mid] - v[mid - 1] >= 2 || v[mid + 1] - v[mid] >= 2) {
		return false;
	}
	if (v[ini] == v[mid] || v[mid] == v[fin] || v[ini] == v[mid] - 1 || v[mid] + 1 == v[fin] || v[ini] == v[fin] || v[ini] + 1 == v[fin]) {
		return true;
	}
	else if(v[mid] + 1 > v[fin] ) {//en caso que sea superior fin a mid por más de 1, entonces tengo que mirar si en medio esta todo ok
		return porPelos(v, mid, fin);
	}
	else if (v[ini] < v[mid] - 1) {
		return porPelos(v, ini, mid); 
	}

}