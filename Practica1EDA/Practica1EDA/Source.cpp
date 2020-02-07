/*
Alfonso Antonio Tercero López
Jorge García Cerros
*/

#include <iostream>
using namespace std;

const int MAX = 300000;
int v[MAX];


int posMinima(int v[], int n, int k);

void esconde() {//introducimos los datos
	int n, k, a, b;
	int i = 0, res = 0;
	cin >> n;//n arbustos
	cin >> k;//tam coche
	while (i < n) {
		cin >> v[i];
		i++;
	}
	cout << posMinima(v, n, k) << endl;

}

int posMinima(int v[], int n, int k) {
	int ret = 0, a, b, pos;
	int area, areaAux;
	int i = 0;
	//pos nos da la primera posición que no es arbusto
	a = k;
	b = k;
	area = 0;
	areaAux = v[a];
	
	while (b < n) {

		if (area < areaAux) {
			ret = a;
			area = areaAux;
		}

		if ((b - a) < k) {//contamos hasta llegar al tam del coche
			
			areaAux += v[b];
			b++;
		}
		else {
			areaAux += v[b];
			areaAux -= v[a];
			a++;
			b++;
		}
		if (area < areaAux) {
			ret = a;
			area = areaAux;
		}
	}


	return ret;
}


int main() {
	int casos;
	int i = 0;
	cin >> casos;
	while (i < casos) {
		esconde();
		i++;
	}

	return 0;
}

