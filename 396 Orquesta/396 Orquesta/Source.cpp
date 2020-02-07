#include <iostream>
#include <algorithm>
using namespace std;


int v[100000];

int max_elem(int v[], int n) {
	int max = v[0];
	for (int i = 0; i < n; i++) {
		if (v[i] > max) {
			max = v[i];
		}
	}
	return max;
}

int resuelve(int v[], int n, int p) {
	if (p == 0) {
		return max_elem(v, n);
	}
	int  i = 0;
	while (i < n && p > 0) {
		v[i] = v[i] / 2;
		i++;
		p--;
	}
	return resuelve(v, n, p - n);
}

int main() {

	int p, n;

	while (cin >> p >> n) {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		sort(v, v + n);
		cout << resuelve(v, n , p - n) << endl;// se supone que todos tienen una partitura
	}

	return 0;
}