#include <iostream>
using namespace std;

int res();

int main() {
	int i, casos;
	cin >> casos;
	i = 0;
	while (i < casos) {
		cout << res()<<endl;
		i++;
	}
	return 0;
}


int res() {
	char a;
	cin >> a;
	//its a operation
	if (a == '+') {
		return res() + res();
	}
	else if (a == '-') {
		return res() - res();
	}
	else if (a == '*') {
		return res() * res();
	}
	else if (a == '/') {
		return res() / res();
	}
	else{//its a number
		int aux = a - '0';
		return aux;
	}

}