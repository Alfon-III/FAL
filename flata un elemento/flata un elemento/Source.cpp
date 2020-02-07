#include<iostream>


using namespace std;





int ordenados(int a[], int b[], int ini, int fin) {
	int m = (ini + fin) / 2;
	if (ini < fin) {
		if (a[m] == b[m]) {
			ordenados(a, b, m + 1, fin);
		}
		else if (a[m] < b[m]) {
			ordenados(a, b, ini, m - 1);
		}
		else {
			return a[m];
		}
	}
	else {
		return a[m + 1];
	}

}








int main() {

	int n;
	cin >> n;

	int a[1000];
	int b[1000];

	int i = 0;

	while (i < n) {
		cin >> a[i];
		i++;
	}

	int j = 0;

	while (j < n - 1) {
		cin >> b[j];
		j++;
	}

	cout << ordenados(a, b, 0, n - 1);

	return 0;
}