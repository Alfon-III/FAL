#include <iostream>
using namespace std;

void calculaPisos(int p);

int main() {

	int casos = 0, i, p;
	i = 0;
	cin >> casos;
	while (i < casos) {
		cin >> p;
		calculaPisos(p);
		i++;
	}

	return 0; 
}

void calculaPisos(int p) {
	long long int aux = 0;
	long long int ret = 0;
	int i = 1;
	while (i < p + 1){
		aux += i;
		ret += aux;
		i++;
	}
	cout << ret << endl;
}