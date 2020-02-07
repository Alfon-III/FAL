#include <iostream>
using namespace std;

const int MAX = 250000;
int v[MAX];

void resuelve();
int numSegment(int v[], int n, int k);

int main() {
	int nCasos;
	cin >> nCasos;

	for (int i = 0; i < nCasos; i++) {
		resuelve();
	}

	return 0;
}

void resuelve() {
	int k, n;
	string num;
	cin >> k;
	cin >> num;
	for (int i = 0; i < num.size(); i++) {
		v[i] = num[i] - '0';
	}
	n = num.size();
	cout << numSegment(v, n, k) << endl;

}
//O(n)
int numSegment(int v[], int n, int k) {

	int ret = 0;
	int ini = 0;
	int fin = 0;
	int cont = 0;

	//I: 
	while (ini < n) {
		if (cont < k) {
			cont += v[fin];
			fin++;
		}
		else{
			cont -= v[ini];
			ini++;

		}
		if (k == cont) {
			ret++;
			fin = ini;
			cont = v[ini];
		}
	}

	return ret;
}