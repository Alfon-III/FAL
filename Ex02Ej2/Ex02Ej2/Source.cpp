#include <iostream>
using namespace std;

/*
4 25
20 1 2
10 1.5 2
10 2.5 5
10 5 1

4 30
20 6 1
10 4 3
10 0 3
10 0 3
*/

struct tema {
	float t;
	float c1;
	float c2;
};


void maxMedia(
	//datos
	int n,
	float maxTime,
	struct tema tema[],
	//sol parcial
	int k, //temas que me he planteado ya
	float notaC1, //Nota que ya tengo del C1 y C2,. junto al tiempo que ya he invertido
	float notaC2,
	float tiempoAcum,
	//marcaje
	float maxC1, 
	float maxC2,

	//mejor sol
	float& mejorNota
) {
	if (k == n) {

		if ((notaC1 + notaC2)/2 > mejorNota) {
			mejorNota = (notaC1 + notaC2) / 2;
		}
		return;
	}

	if (tiempoAcum + tema[k].t <= maxTime) {//si tengo tiempo, me lo estudio
		maxMedia(n, maxTime, tema,
			k + 1, notaC1 + tema[k].c1, notaC2 + tema[k].c2, tiempoAcum + tema[k].t,
			maxC1 - tema[k].c1, maxC2 - tema[k].c2,
			mejorNota);
	}
	//a lo mejor no me quyiero estudiar el primer tema
	if (notaC1 + maxC1 - tema[k].c1 >= 5 &&
		notaC2 + maxC2 - tema[k].c2 >= 5) {
		maxMedia(n, maxTime, tema,
				k + 1, notaC1, notaC2, tiempoAcum,
				maxC1 - tema[k].c1, maxC2 - tema[k].c2, //"pierdes los puntos"
				mejorNota);
	
	}
	

}
//mejorar eficiencia:
/*
1. Es posible siquiera aprobar?
acabar cuando la suma del C1 + maxC1restante - tema[k].c1 < 5 
esto significa que si con la suma en el mejor de los casos de los puntos restantes 
sigo teniendo un suspenso, lo mismo no merece la pena seguir
2. En caso de aprobar, ¿voy a poder superar la máxima nota?
c1+ c2 + maxC1 + maxC2 - tema[k].c1 - tema[k].c2 > mejorNota

*/


int main() {
	
	struct tema tema[20];
	int n;
	float mejorNota, time, maxC1, maxC2;

	cin >> n;
	while (n != -1) {
		mejorNota = 0;
		maxC1 = maxC2 = 0;
		cin >> time;
		for (int i = 0; i < n; i++) {
			cin >> tema[i].t >> tema[i].c1 >> tema[i].c2;
			maxC1 += tema[i].c1;
			maxC2 += tema[i].c2;
		}

		//resuelve

		
		
		maxMedia(n, time, tema,
				0, 0, 0, 0,
				maxC1, maxC2,
				mejorNota);
		
		if (mejorNota < 5) {
			cout << -1 << endl;
		}
		else {
			cout << mejorNota << endl;
		}
		

		cin >> n;
	}

	return 0;
}