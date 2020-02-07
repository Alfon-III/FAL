#include <iostream>
using namespace std;

struct obra {
	int belleza;
	int precio;
};

void maxMedia(
	//datos
	int dineroMax,
	int n,
	struct obra obra[],
	//sol parcial
	int k,
	int gastado,
	int satiAcum,
	//marcaje
	//dinero de las bras resatntes *** 
	//satisf maxima restante
	//mejor sol
	int &maxSatis
) {
	if ( k >= n) {
		cout << "*Gastado: " << gastado << "Belleza: " << satiAcum << endl;
		if (satiAcum > maxSatis) {
			maxSatis = satiAcum;
		}
		return;
	}

	if (gastado < obra[k].precio ) {//Primera obra del autor
		//Paso al siguiente autor
		maxMedia(dineroMax, n, obra,
			k + 2, gastado + obra[k].precio, satiAcum + obra[k].belleza,
			satiAcum);
	}
	if (gastado < obra[k + 1].precio && k + 1 < n) {//Compro segundo obra del autor
		//Paso al siguiente autor
		maxMedia(dineroMax, n, obra,
			k + 1, gastado + obra[k + 1].precio, satiAcum + obra[k + 1].belleza,
			satiAcum);
	}
	
	maxMedia(dineroMax, n, obra,
		k + 1, gastado, satiAcum,
		satiAcum);



}


int main() {

	struct obra obras[30];
	int n, p, satiAcum;
	while (cin >> n >> p) {
		satiAcum = 0;
		for (int i = 0; i < n; i++) {
			cin >> obras[i].precio >> obras[i].belleza;
		}
		maxMedia(p, n, obras,
			0, 0, 0,
			satiAcum);
		cout << satiAcum << endl;
	}


	return 0;
}