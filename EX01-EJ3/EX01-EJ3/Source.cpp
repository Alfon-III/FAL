#include <iostream>
using namespace std;


//HAy que hacerlo con vectores, mátame camión cisterna

unsigned long long int cuantosSD(//datos del problema
				int d,
				int k,
	
				//sol_parcial
	unsigned long long int sol,
	unsigned long long int sumDig,
	unsigned long long int dig
				) {
	//------------------
	unsigned long int cuenta = 0;
	unsigned long long int num, suma;//variables auxiliares para no sobreescribir los valores E/S

	if (k == dig) {
		//cout << sol << endl;
		return 1;
	}
	else {
		
		for (int i = 0; i < 10; i++) {
			num = (sol * 10) + i;
			suma = sumDig + i;
			if (suma % (dig + 1) == 0) {
				cuenta += cuantosSD(d, k, num, suma, dig + 1);
			}
		}
	}
	return cuenta;

}


int main() {
	int d, k;
	cin >> d >> k;
	while (d != 0) {
		cout << cuantosSD(d, k, d, d, 1) <<endl;
		cin >> d >> k;
	}


	return 0;
}