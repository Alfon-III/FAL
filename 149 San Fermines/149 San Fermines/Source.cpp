#include <iostream>
using namespace std;

//San Fermines
int main() {


	int n;
	int i, aux, max;
	
	while ( cin >> n )
	{
		i = 0;
		max = 0;
		while (i < n){
			cin >> aux;
			if (aux > max) {
				max = aux;
			}
			i++;
		}
		cout << max << endl;
	}



	return 0;
}