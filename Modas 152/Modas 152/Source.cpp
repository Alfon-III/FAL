#include <iostream>
#include <algorithm>
using namespace std;

int moda(int v[], int n);

int main(){
	int v[25000];
	int casos; cin >> casos;
	int i = 0;

	while (casos != 0) {
		//introduzco datos en el array
		while (i < casos) {
			cin >> v[i];
			i++;
		}

		cout << moda(v, casos) << endl;

		i = 0;
		cin >> casos;
	}
	
	return 0;
}

int moda(int v[], int n) {
	
	sort(v, v+n);
	/*
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << v[i] << endl;
		
	}
	cout << endl;
	*/
	int ret = v[0];
	int frecMax = 1;// la de v[0]
	int frecAux = 0;


	int i = 0;
	while (i < n) {
		if (v[i] == v[i + 1]) {
			frecAux++;
		}
		else {
			frecAux = 1;	
		}

		if (frecAux > frecMax) {
			frecMax = frecAux;
			ret = v[i];
		}

		i++;
	}

	return ret;
}

