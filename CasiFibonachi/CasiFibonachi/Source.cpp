#include <iostream>
using namespace std;

int v[1000];

void casiFibo(int v[], int k, int n) {
	if (k == n) {
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}
	v[k] = v[k - 1];
	casiFibo(v, k + 1, n);
	if (k > 1) {
		v[k] = v[k - 1] + v[k - 2];
		casiFibo(v, k + 1, n);
	}
}


int main() {
	int ini = 2;
	v[0] = ini;
	casiFibo(v, 1, 5);
	return 0;
}