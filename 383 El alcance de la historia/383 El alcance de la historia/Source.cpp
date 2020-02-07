#include <iostream>
using namespace std;
const int MAX = 300000;
int v[MAX];
int menor[MAX];
void resuelve(int v[], int n);

int main() {
	int casos, n, p;
	cin >> casos;

	for (int i = 0; i < casos; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}

		resuelve(v, n);
	
	}

}

void resuelve(int v[], int n){
	
	int ret, aux;

	int min = v[n - 1];//ultimo elemento
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] < min) {
			min = v[i];
		}
		menor[i] = min;
	}


	/*
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << menor[i] << " ";
	}
	cout << endl;
	*/


	int i = 0;
	ret = v[0] - menor[i + 1];

	while (i < n - 1){ // el ultimo "no cuenta"
		aux = v[i] - menor[i + 1];
		if (aux > ret) { 
			ret = aux;
		}
		i++;
	}

	cout <<ret<<endl;
}