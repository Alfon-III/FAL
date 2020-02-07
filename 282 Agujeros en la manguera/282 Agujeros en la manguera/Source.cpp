#include <iostream>
using namespace std;
int v[100000];
int resuelve(int n, int k);

int main() {
	int n;
	int k;

	while (cin >> n >> k) {
	
		cout << resuelve(n, k) << endl;
	}

	return 0;
}
//precondicion: Hay un agujero
int resuelve(int n, int k) {
	int ret, ini, i;
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	i = 1;
	ini = v[0];
	ret = 1;
	
	while (i < n){//empiezo en la pos 2
		if ((v[i] - ini) <= k) {
			ret += 0;
		}
		else {
			ini = v[i];
			ret++;
		}
		i++;
	}

	return ret;
}