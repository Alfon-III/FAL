#include <iostream>
using namespace std;

void analiza(int v[], int n);

int main() {

	int v[10000];

	int num; cin >> num;
	int i = 0, j, elem;
	while (i < num) {
		cin >> elem;
		j = 0;
		while (j < elem) {
			cin >> v[j];
			j++;
		}
		analiza(v, elem);
		//mostrar resultado
		i++;
	}

	return 0;
}

void analiza(int v[], int n) {

	int a, b, c, numValles, numMont;
	
	if (n < 3) {//si nos dan 1 o 2 datos, es imposible que haya valles o montes
		cout << 0 << " " << 0 << endl;
	}
	else {
		//mientras queden 2 elementos por analizar...
		numValles = 0;
		numMont = 0;
		int i = 0;
		while (i < n - 2){
			a = v[i];
			b = v[i + 1];
			c = v[i + 2];

			if (a > b && c > b) { //hay un valle
				numValles++;
			}
			else if ( a < b && b > c) {//hay una montaña
				numMont++;
			}
			i++;//apunto al siguiente
		}
		i = 0;
		cout << numMont << " " << numValles << endl;
	
	}
}