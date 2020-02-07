#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000;
int v[MAX];
int aux[MAX];


long long int resuelve(vector <int>& v, vector <int>& aux, int m, int ini, int fin, int mid) {
	long long tot;
	if (fin - ini <= 1) {
		return tot;
	}

	vector <int> alfa(mid - ini);//2
	vector <int> omeg(fin - mid);//2

	tot = resuelve()

}

int main() {

	int n;
	cin >> n;

	while (n != 0) {	
		vector<int> v(n);
		vector<int> n(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << resuelve(v, aux, 0, n, n / 2) << endl;
		cin >> n;
	}
	return 0;
}