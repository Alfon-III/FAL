#include <iostream>
using namespace std;

int factorial(int n);

int main() {
	int casos; cin >> casos;
	cout << endl;
	while (casos > 0) {
		int n; 
		
		cin >> n;
		if (n == 0) cout << "0" << endl;
		else if (n == 1) cout << "1" << endl;
		else if (n == 2) cout << "2" << endl;
		else if (n == 3) cout << "6" << endl;
		else if (n == 4) cout << "4" << endl;
		else cout << "0" << endl;
		casos--;
	}

	return 0;
}	