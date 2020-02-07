#include <iostream>
using namespace std;


int main() {

	int index; cin >> index;
	while (index != 0) {
		int tens[2];
		string basura;
		cin >> tens[0];
		cin >> basura;
		cin >> tens[1];

		if (tens[0] >= tens[1]) {
			cout << "BIEN" << endl;
		}
		else {
			cout << "MAL" << endl;
		}

		index--;
	}

	return 0;
}