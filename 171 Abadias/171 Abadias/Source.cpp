#include <iostream>
#include <ctime> 
using namespace std;

int main(){
	int num, cont;
	int mon[100000];
	int mayor;

	cin >> num;
	while (num != 0) {

		for (int i = 0; i < num; ++i) {
			cin >> mon[i];
		}
		mayor = 0;
		cont = 0;
		for (int i = num - 1; i >= 0; i--) {
			if (mayor < mon[i]) {
				mayor = mon[i];
				cont++;
			}
		}
		
		cout << cont << endl;
		
		cin >> num;
	}

	return 0;
}