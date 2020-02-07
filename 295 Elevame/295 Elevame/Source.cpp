#include <iostream>
using namespace std;

const int PRIME = 31543;

long long int power(unsigned long long x, unsigned long long n);

int main() {

	unsigned long long x, n;//x^n % PRIME
	cin >> x >> n;
	while (x != 0 && n != 0) {
		cout << power(x, n) << endl;
		cin >> x >> n;
	}
	return 0;
}


long long int power(unsigned long long x, unsigned long long n) {
	//x^10 = x ^5 * x^5
	if (n == 0) {
		return 1;
	}
	//para asegurarse
	unsigned long long aux = power(x, n/2);
	unsigned long long ret = aux * aux;
	ret = ret % PRIME;
	if (n % 2 == 1){
		ret = ret * x;
		ret = ret % PRIME;
	}
	return ret;
}