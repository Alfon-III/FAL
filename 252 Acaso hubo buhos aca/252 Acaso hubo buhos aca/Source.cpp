#include <iostream>
#include <string>
using namespace std;

char frase[100];

int normaliza(string f);
void resuelve(char frase[], int n);


int main() {
	int n;
	string f;
	getline (cin, f);
	
	while (f != "XXX") {
		n = normaliza(f);
		resuelve(frase, n);
		getline(cin, f);
	}

	return 0;
}



void resuelve(char frase[], int n) {

	int m = n / 2;
	int i = 0;
	bool pali = true;

	while (i < n && pali) {
		//cout << frase[i] << " --- " << frase[(n - 1) - i] << endl;
		if (frase[i] != frase[(n - 1) - i]) {
			pali = false;
		}
		i++;
	}
	if (pali) {
		cout << "SI"<<endl;
	}
	else {
		cout << "NO" << endl;
	}

}

int normaliza(string f) {
	int i = 0;
	int n = 0;//tam de la frase sin espacios ni nada
	while (i < f.size()) {
		if (f[i] != ' ' && f[i] != '.' && f[i] != ';' && f[i] != ',') {
			frase[n] = tolower(f[i]);
			n++;
		}
		i++;
	}
	return n;
}


/*

cout << endl;
		for (int i = 0; i < n; i++) {
			cout << frase[i];
		}
		cout << endl << n;

*/