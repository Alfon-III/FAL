#include <iostream>
using namespace std;
const int MAX = 6;
int sup[MAX];
int inf[MAX];

bool dientes(int sup[], int inf[]) {

	bool aux = true;
	int i = 1;
	int regla = sup[0] + inf[0];
	while (aux && i < MAX) {
		if (sup[i] + inf[i] == regla) {
			i++;
		}
		else {
			aux = false;
		}
	}
	return aux;

}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		//Introduzco los datos
		for (int x = 0; x < MAX; x++) {
			cin >> sup[x];
		}
		for (int y = 0; y < MAX; y++) {
			cin >> inf[y];
		}

		if (dientes(sup, inf)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}


