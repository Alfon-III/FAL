#include <iostream>
using namespace std;

/*
	a = 2 llamadas recursivas
	b = (b - a + 1)/2 => Como estoy dividieno por la mitad
	k = n // mezcla() es lineal = 1

	Coste = O(n * log n)

*/

void ordena(int v[], int a, int b){
	//caso recursivo, repito mientras a < b
	if(a < b){
	int m = (a + b)/2;
	ordena(v[], a, m - 1);
	ordena(v[], m, b);
	mezcla(v, a, m, b);
	}
}


void ordena(int v[], int n){
	ordena(v, 0, n - 1);

}