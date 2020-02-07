#include <iostream>
using namespace std;


//turno 1 = oponente
//turno 0 = mio

int num[9][4] = {
{ 2, 3, 4, 7 },
{ 1, 3, 5, 8 },
{ 9, 6, 1, 2 },
{ 1, 7, 5, 6 },
{ 8, 4, 6, 2 },
{ 9, 3, 4, 5 },
{ 8, 9, 4, 1 },
{ 7, 9, 5, 2 },
{ 7, 8, 6, 3 } };

bool juego(int sum, int x, int turno) {
	if (sum >= 31) {//Alguien se ha pasado
		if (turno == 1)//A mi enemigo le llega que me he pasado, sonríe y pierdo
			return false;
		else {//Es mi turno y mi enemigo se ha pasado, he ganado
			return true;
		}
	}

	bool res1, res2, res3, res4;
	//calculo las posiciones válidas
	if (turno == 0) {//si es mi turno, pregunto por el de mi contrincante
		res1 = juego(sum + num[x - 1][0], num[x - 1][0], 1);
		res2 = juego(sum + num[x - 1][1], num[x - 1][1], 1);
		res3 = juego(sum + num[x - 1][2], num[x - 1][2], 1);
		res4 = juego(sum + num[x - 1][3], num[x - 1][3], 1);
		return res1 || res2 || res3 || res4;
	}
	else if(turno == 1){
		res1 = juego(sum + num[x - 1][0], num[x - 1][0], 0);
		res2 = juego(sum + num[x - 1][1], num[x - 1][1], 0);
		res3 = juego(sum + num[x - 1][2], num[x - 1][2], 0);
		res4 = juego(sum + num[x - 1][3], num[x - 1][3], 0);
		return res1 && res2 && res3 && res4;

	}

}



int main(){
	
	int c, sum, x;//total y numero de la discordia
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> sum >> x;
		if (juego(sum, x, 0)) {
			cout << "GANA" << endl;
		}
		else {
			cout << "PIERDE" << endl;
		}
	}


	return 0;
}