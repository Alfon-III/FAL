#include <iostream>
using namespace std;

void resuelve(int v[], int n);

int main() {
	
	int tam = 0;
	int tamAux = 0;

	int i = 0;
	int pos = 0;
	int posAux = 0;

	int n, m;

	cin >> n;
	while (n != -1 ) {
		cin >> m;
		while (m != -1) {
			if (n == m) {
				tamAux++;
				posAux = i;
			}
			else {
				tamAux = 0;
			}
			if (tamAux > tam) {
				tam = tamAux;
				pos = i - tamAux + 1;
			}
			i++;
			n = m;
			cin >> m;
			
		}

		if (tam == 0) {
			cout << "HOY NO COMEN" << endl;
		}
		else {
			cout << pos << " " << tam << endl;
		}
		//renicializo variabless
		pos = 0; posAux = 0; tam = 0; tamAux = 0; i = 0;

		cin >> n;
	}
	
	return 0;
}

