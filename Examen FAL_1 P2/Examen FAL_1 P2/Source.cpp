#include <iostream>
using namespace std;


bool sumDig(int n, int &k, int& sum) {
	if (n / 10 == 0) {
		k = 1;
		sum = n;
		return true;
	}

	if(sumDig(n/10, k, sum)){
		//cout << k << "  " << sum << endl;
		if ((sum + (n % 10)) % (k + 1) == 0) {
			k = k + 1;//numDigitos
			sum = sum + (n % 10);//Suma digitos
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}

}


int main() {
	int n, k, x;
	cin >> n;
	while (n != 0) {
		if (sumDig(n, k, x)) {
				cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		cin >> n;
	}
	
	
	return 0;
}