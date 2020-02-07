#include <iostream>
#include <algorithm> 
using namespace std;


int n[100000];
int m[100000];
int repeA[5000];
int repeM[5000];

int aux[5000];

void resuelve() {

	int ale, mat;

	//Cojo y ordeno los cromos de Ant
	cin >> ale;
	for (int i = 0; i < ale; i++) {
		cin >> n[i];
	}
	sort(n, n+ale);

	int ra = 0;
	repeA[0] = 0;
	for (int i = 0; i < ale - 1; i++) {
		if (n[i] == n[i + 1] && repeA[ra] != n[i]) {
			repeA[ra] = n[i];
			ra++;
		}
	}
	sort(repeA, repeA+ra);
	
	//Cogo y ordeno los cromos de Mat
	cin >> mat;
	for (int i = 0; i < mat; i++) {
		cin >> m[i];
	}
	sort(m, m + mat);

	int ma = 0;
	repeM[0] = 0;
	for (int i = 0; i < mat - 1; i++) {
		if (m[i] == m[i + 1] && repeM[ra] != m[i]) {
			repeM[ma] = m[i];
			ma++;
		}
	}
	sort(repeM, repeM + ma);
	

	
	//Mostramso los que tiene A repetidos y puede interesar a M
	if (ra == 0){
		cout << "Nada que intercambiar" << endl;
	}
	else {
		int in = 0;
		int x = 0, y = 0;
		while (x < ra){
			if (repeA[x] == m[y]) {
				x++;
				y++;
			}
			if (repeA[x] > m[y]) {//No lo tiene M y yo lo tengo repe
				x++;
			}
			if (repeA[x] < m[y]) {
				aux[in] = repeA[x];
				in++;
				x++;
			}
		}

		if (in == 0) {
			cout << "Nada que intercambiar" << endl;
		}
		else{
			for (int i = 0; i < in; i++){
				cout << aux[i] << " ";
			}
			cout << endl;

		}

	}

	//Caso M
	if (ma == 0) {
		cout << "Nada que intercambiar" << endl;
	}
	else {
		int in = 0;
		int x = 0, y = 0;
		while (x < ma) {
			if (repeM[x] == n[y]) {
				x++;
				y++;
			}
			if (repeM[x] > n[y]) {//No lo tiene M y yo lo tengo repe
				x++;
			}
			if (repeM[x] > n[y]) {
				aux[in] = repeM[x];
				in++;
				x++;
			}
		}

		if (in == 0) {
			cout << "Nada que intercambiar" << endl;
		}
		else {
			for (int i = 0; i < in; i++) {
				cout << aux[i] << " ";
			}
			cout << endl;

		}

	}

}

int main() {

	int casos;
	cin >> casos;

	for (int i = 0; i < casos; i++) {
		resuelve();
	}

	return 0;
}

/*	for (int i = 0; i < ma; i++) {
		cout << repeM[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < ra; i++) {
		cout << repeA[i] << " ";
	}
	cout << endl;*/