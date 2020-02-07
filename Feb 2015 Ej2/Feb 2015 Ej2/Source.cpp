#include <iostream>
using namespace std;

/*Recursion no final, REQUIERE combinacion de resultados, 
es decir info de la recursion y mi estado actual*/

unsigned int especular(int n, int& dig) {
	if (n < 10) {
		dig = 0;
		return n;
	}
	else {

		int aux = especular(n / 10, dig);//devuelve el anterior
		dig++;
		return aux + ((n % 10) * pow(10, dig));
	}
}

//Final = 1º se hacen las operaciones y luego se hace la 
//recursion

void especularFinal(int n) {
	if (n < 10) {
		cout << n;
		return;
	}
	else{
		int aux = n % 10;
		cout << n;
		especularFinal(n / 10);
	}
}

int main() {


	int n, dummy;
	cin >> n;
	while (n > 0) {
		
		
		especularFinal(n);	cout << endl;
		
		//cout << especular(n, dummy) << endl;
		cin >> n;
	}

	return 0;
}

