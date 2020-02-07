#include <iostream>
using namespace std;


void subdi(int n, int k, int max, /*marcaje vivo*/int sum) {
	
	if (max == k && sum % k == 0) {
		cout << n << endl;
		return;
	}

	if (sum % k == 0) {
		
		for (int i = 0; i < 9; i++) {
			subdi(n * 10 + i, k + 1, max, sum + i);
		}
	}
	else {
		return;
	}

}


int main() {

	int n = 3;
	subdi(n, 1, 5, n);

	return 0;
}