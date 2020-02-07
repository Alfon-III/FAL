#include <iostream>
using namespace std;

const int MAX = 1000;
int v[MAX];

//PRECONDICION: 1 < n < 1000
/*
CASOS DE PRUEBA:

50
1 4
1 2 3 4

1 4 
1 2 1 2

1 4 
1 2 3 3

1 4 
4 3 2 1

2 4 
1 2 3 4

2 4 
1 2 3 3

2 4 
1 1 2 2

2 4 
1 1 3 3

2 4 
1 1 1 2

2 4 
1 1 1 3

5 4 
1 1 1 1

5 4 
1 1 3 4
*/


//Coste: O(n)
//Precondición 1 < n <= long(v)
bool creceDiver(int v[], int n, int d) {
	int i = 1;
	int cont = 1;
	int aux = v[0];

	while (i < n && //Queden elementos en el array
		((v[i - 1] - v[i]) == (0 || -1)) &&//La diferencia sea 0 o -1
		!(cont > d)//el contador no se pase...
		) {
		if (aux == v[i]) cont++;
		else
		{
			cont = 1;
			aux = v[i];
		}
		//cout << v[i] << " " << cont << endl;
		i++;
	}
	
	return (i == n && ((v[i - 2] - v[i - 1]) == 0 || (v[i - 2] - v[i - 1]) == -1) && !(cont > d));
}


int main() {
	int d, n, casos;

	cin >> casos;
	while (casos != 0) {
		cin >> d >> n;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		
		if (creceDiver(v, n, d)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		casos--;
	}


}