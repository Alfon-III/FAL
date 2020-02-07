/*	
CAE 100PRE
a = Número de llamadas recursivas
¿Cómo decrece el tamaño de los datos? ¿Cuánto resto/divido? 
	- Restando un valor		b = cantidad 
	- Dividimos 			b = cantidad
En factorial
	a = 1
	b = 1
Fractal punto azul
	a = 4
	b = 2 //divdiamos entre 2 el tam de los cuadrados
Polidivisibles
	a = 1
	b = 10
k = como de dificil es hacer las llamadas recursivas, hasta ahora 0

Si restamos:
	a = 1:	 O(n ^ (k + 1))
	a > 1:	 O(a ^(n/b))
Si dividimos:
	a < b^k: O(n^k)
	a = b^k: O((n^k) * log n)
	a > b^k: O(n ^ (log b de a))


*/

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


