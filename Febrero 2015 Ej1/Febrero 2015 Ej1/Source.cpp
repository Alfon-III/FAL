#include <iostream>
using namespace std;

int v[10000];

//O(n)
//Cota = n - i
/*
	Pre: 0 <= n < v.length() &&
	int sum = Sum i: 0 <= i < n: sum += v[i]
*/
int sumLista(int v[], int n, int sum) {
	int i = 0;
	int ret = 0;
	int a = 0;

	while (i < n || sum == 0) {
		ret += v[i] * (sum - v[i]);
		sum -= v[i];
		i++;
	}
	return ret;
}
//Post: ret = Sum i: 0 <= i < n: ret += Sum_j
//			 Sum j, x: i < j < n: x +=v[j] 

int main() {
	int n, sum;
	cin >> n;
	while (n != -1) {
		sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			sum += v[i];
		}
		cout << sumLista(v, n, sum) << endl;
		cin >> n;
	}
}