//Daniel Nasim Santos Ouafki

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <fstream>
#include "Horas.h"
#include "Peli.h"


using namespace std;

bool resuelveCaso() {

	int casos;
	if (casos == 0) {
		return false;
	}

	vector<Peli> peliculas(peliculas);

	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}