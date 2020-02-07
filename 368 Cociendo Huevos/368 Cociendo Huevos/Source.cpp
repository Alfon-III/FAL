#include <iostream>
using namespace std;


int main() {

	int h, c, ret;

	cin >> h; 
	cin >> c;

	while (h != 0 && c != 0) {
	
		
		if (h < c) {
			ret = 1;
		}
		else {
			ret = (h / c) + 1;
			if (h % c == 0) {
				ret = (h / c);
			}
		}
		cout << ret * 10 << endl;
		cin >> h;
		cin >> c;
	}


	return 0;
}