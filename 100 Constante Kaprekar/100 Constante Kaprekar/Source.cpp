#include <iostream>
#include <algorithm>
using namespace std;

const int kap = 6174;
const int MAX = 4;
void numCiclos(int num);
int up(int num, int v[]);
int low(int num, int v[]);

int main() {
	int casos, i, num;
	i = 0;
	cin >> casos;

	while (i < casos) {
		cin >> num;
		numCiclos(num);
		i++;
	}

}

//ret esl el numero de ciclos necesarios para que nos de la const
void numCiclos(int num) {
	int ret;

	int v[MAX];

	for (int i = 0; i < MAX; i++) {
		v[i] = num % 10;
		num = num / 10;
	}


	if ((v[0] == v[1] == v[2] == v[3])) {
		ret = 8;
	}
	else {//en caso de ser un repdigit, estpo sería un buicle infinito
		int decr, crec, res;
		res = num;
		ret = 0;
		//I: (mientras que la resta sea distinta de la constante)
		while (res != kap) {
			decr = low(res, v);
			crec = up(res, v);
			res = crec - decr;
			for (int i = 0; i < MAX; i++) {
				v[i] = res % 10;
				res = res / 10;
			}

			ret++;
		}
	}
		

	cout << ret << endl;
}

int up(int num, int v[]) {
	int n = 0;

	sort(v, v + MAX, greater<int>());//ordena de mayor a menor

	for (int i = 0; i < MAX; i++) {
		n = (n * 10) + v[i];
	}

	//cout << n << endl;

	return n;
}
int low(int num, int v[] ){
	int n = 0;

	sort(v, v + MAX, greater<int>());//ordena de mayor a menor

	for (int i = MAX - 1; i >= 0; i--) {//introducimos los datos al reves
		n = (n * 10) + v[i];
	}

	return n;
}
