#include <iostream>
using namespace std;

int v[1000];

/*
6 
2
1000 1500
2
1500 1000
5
1500 1600 1200 1000 2000
6
1500 1200 1000 1000 1000 500
10
2250 2200 2300 2350 2325 2300 2210 2190 2101 1940
12
1000 950 900 825 910 800 750 700 650 650 500 425
*/

int segLargo(int v[], int n) {
	int cont = 1;
	int a = 0, b = 1;
	int ret = 0;
	
	while (b < n) {
		if (v[a] >= v[b]) {
			a++;
			b++;
			cont++;
		}
		else{
			a++;
			b++;
			cont = 1;
		}

		if (cont > ret) {
			ret = cont;
		}
	}

	return ret;

}

int main() {
	int casos, n;
	cin >> casos;

	for (int x = 0; x < casos; x++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << segLargo(v, n) << endl;
	}
	
	return 0;
}