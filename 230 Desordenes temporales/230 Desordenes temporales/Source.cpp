#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000;
int v[MAX];
int aux[MAX];


long long opera(vector <int>& alfa, vector <int>& omega, vector <int>& aux) {
	int x = 0;
	int i, j, k;
	i = j = k = 0;



}

long long int resuelve(vector <int>& v, vector <int>& aux, int ini, int fin, int mid) {
	long long tot;
	if (fin - ini <= 1) {
		aux[0] = v[ini];
		return tot;
	}

	vector <int> alfa(mid - ini);//2
	vector <int> omeg(fin - mid);//2

	tot = resuelve(v, alfa, ini, mid, (mid / 2)) + resuelve(v, omeg, mid, fin, (fin/2));
	tot += opera(alfa, omeg, aux);
	return tot;
}

int main() {

	int n = 0;
	cin >> n;
	

	while (n != 0) {
		vector<int> v(n);
		vector<int> aux(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << resuelve(v, aux, 0, n, (n / 2)) << endl;
		cin >> n;
	}
	return 0;
}