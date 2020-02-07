#include <iostream>
using namespace std;

struct producto {
	int precio;
	int prot;
	int cal;
};

producto productos[30];
bool comraMaestra[30];
bool prod[30];

void mejorCompra(
	//Datos del problema
	int n,
	producto productos[],
	int presupuesto,
	int proteinasMin,
	//Sol parcial 
	int k, //num de obejetos que llevamos
	bool prod[],
	int gastado,
	int sumProteina,
	int sumCaloria,//Calorias q llevamos

	//Marcaje/Poda
	int calRestantes,
	int protRestantes,
	//Mejor solucion
	int& minCalorias,
	bool sol[]
) {
	if (sumProteina >= proteinasMin || k >= n) {
		/*
		for (int i = 0; i < n; i++) {
			if (prod[i]) {
				cout << i;
			}
		}
		cout << endl;
		*/
		if (minCalorias > sumCaloria) {
			//Hemos encontrado una solución mejor POR MEDIO FUERZA BRUTA!!!!!
			minCalorias = sumCaloria;

			for (int i = 0; i < n; i++) {
				if (prod[i]) {
					sol[i] = true;
				}
				else {
					sol[i] = false;
				}
			}

		}
		return;
	}
	//No lo cogemos
	
	/*
	gastado = gastado + 0;
	sumProteina = sumProteina + 0;
	sumCaloria = sumCaloria + 0;

	calRestantes = calRestantes - productos[k].cal;
	*/
	if (sumProteina + protRestantes - productos[k].prot >= proteinasMin) {
			prod[k] = false;
			mejorCompra(n, productos, presupuesto, proteinasMin,
			k + 1, prod, gastado, sumProteina, sumCaloria,
			calRestantes - productos[k].cal, protRestantes - productos[k].prot,
			minCalorias, sol);
	}
	
	
	//Lo cogemos
	prod[k] = true;
	if (gastado + productos[k].precio <= presupuesto || 
		sumProteina + protRestantes >= proteinasMin) {
		
		mejorCompra(n, productos, presupuesto, proteinasMin,
			k + 1, prod,
			gastado + productos[k].precio,
			sumProteina + productos[k].prot,
			sumCaloria + productos[k].cal,
			calRestantes - productos[k].cal, protRestantes - productos[k].prot,
			minCalorias, sol);
	}
}

int main() {
	int n, q, m;
	//M = presupuesto que no hemos de superar 
	//C = proteinas que hemos ade alcanzar si o si

	cin >> n >> m >> q;

	int totPrecio, totProt, totKal;

	while (n != -1) {
		totPrecio = 0;
		totProt = 0;
		totKal = 0;
		for (int i = 0; i < n; i++) {
			cin >> productos[i].precio >>
				productos[i].prot >>
				productos[i].cal;
			
			totPrecio += productos[i].precio;
			totProt += productos[i].prot;
			totKal += productos[i].cal;
		}

		int dummyCalorias = totKal + 1;
		bool dummyProd[30];

		for (int i = 0; i < 30; i++) {
			dummyProd[i] = false;
		}

		mejorCompra(n, productos, m, q, 
			0, prod, 0, 0, 0, totKal, totProt,
			dummyCalorias, dummyProd);
		cout << "Calorias minimas: " << dummyCalorias << endl;
		cout << "ID de la compra maestra: ";
		for (int i = 0; i < n; i++) {
			if (dummyProd[i]) {
				cout << i;
			}
		}
		cout << endl;
		cin >> n >> m >> q;
	}
	return 0;
}

/*
5 25 200

5 50 10
5 30 30
5 10 10
20 200 35
10 150 20

*/