#include <iostream>
using namespace std;

/*

7
1
2
1
-3
6
5 4 1 9 0 2
5
-3 -1 -2 -7 -8
7
1 -3 2 -1 9 -6 -10
10
3 7 -100 1 0 1 4 6 8 100
10
0 -3 -4 -1 -9 -6 0 -5 -10 -20
*/

int v[100000];

int resuelve(int v[], int n) {
	int ret;
	int a = 0, b = 1;
	int aux;

	while (b < n) {
		if (v[a] >= 0 && v[b] >= 0) {
			b++;
			a++;
		}
		else if (v[a] >= 0 && v[b] < 0) {
			a++;//a -1 está correcto
			b++;
		}
		else if (v[a] < 0 && v[b] >= 0) {//swap
			aux = v[a];
			v[a] = v[b];
			v[b] = aux;
			b++;
			a++;
		}
		else if (v[a] < 0 && v[b] < 0){
			b++;
		}
	}

	//En caso de que el último elñemento sea positivo, se incrementa en 1, pues el bucle no contempla eta última iteración
	if (v[n - 1] >= 0) {
		a++;
	}

	return a;
}

int main() {
	int casos, n;
	cin >> casos;

	for (int i = 0; i < casos; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}

		int aux = resuelve(v, n);

		for (int x = 0; x < n; x++) {
			cout << v[x] << " ";
		}
		cout << endl <<"--> "<<aux << endl;

	}

	return 0;
}

/*int resuelve(int v[], int n) {
	int ret = 0;
	int a = 0, b = n - 1;
	int aux = 0;
	while ( a < b ) {
		if (v[a] >= 0 && v[b] < 0) {
			a++;
			b--;
			ret++;
		}
		else if (v[a] >= 0 && v[b] >= 0) {
			a++;
			ret++;
		}
		else if (v[a] < 0 && v[b] >= 0) {
			aux = v[a];
			v[a] = v[b];
			v[b] = aux;
			a++;
			b--;
			ret++;
		}
		else if (v[a] < 0 && v[b] < 0) {
			b--;
		}
	}

	return a;
}
*/