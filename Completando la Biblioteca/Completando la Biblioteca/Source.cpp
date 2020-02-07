#include <iostream>
using namespace std;

void resuelve(int n);
int maxPrecio(int v[], int n);

const int MAX = 10000;
int v[MAX];

int main() {

	int nLibros; cin >> nLibros;
	
	while (nLibros > 0) {
		resuelve(nLibros);
		cin >> nLibros;
	}
	return 0;
}


void resuelve(int n) {/*Se da por hecho que no acepta n < 3*/
	//introducimos los datos en un array
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << maxPrecio(v, n) << endl;;
}

// O(n) 
int maxPrecio(int v[], int n) {
	int a, b, c, i; 
	a = 0;
	b = 1;
	c = 2;
	
	i = 3;//siguiente elemento a analizar
	
	//I: (i <= n) & (res:max=((0 <= a < n) && (1 <= b < n) && (2 <= c < n): V[a]+V[b]+v[c]) 
	while (i < n) {
		//I: (i < n)
		if (v[a] < v[b] && v[a] < v[c] && v[a] < v[i]) {//a es el menor
			a = i;
		}
		else if (v[b] < v[a] && v[b] < v[c] && v[b] < v[i]) { // b es el menor
			b = i;
		}
		else if (v[c] < v[a] && v[c] < v[b] && v[c] < v[i]) {//c es el menor
			c = i;
		}
		i++;
		//I: (i <= n) 
	}
	//I (i = n) 
	
	//esto es igual a res
	return (v[a] + v[b] + v[c]);
}