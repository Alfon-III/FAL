#include <iostream>
#include <string>

using namespace std;

int main(){
	string num1, num2;
	cin >> num1 >> num2;
	//Longitudes de los números

	while (num1 != "0" && num2 != "0") {
		int lenNum1 = num1.length();
		int lenNum2 = num2.length();
		int min = lenNum1 < lenNum2 ? lenNum1 : lenNum2; //Cogemos el minimo de los dos

		int llevadas = 0; //Lo que se quiere obtener
		int resto = 0;
		int i = 0;
		for (; i < min; i++)
		{
			int suma = (int)num1[lenNum1 - 1 - i] - 48 + (int)num2[lenNum2 - 1 - i] - 48 + resto; //suma de los digitos y el resto que llevabamos
			//-48 es porque al castear toma el valor del numero en ascii en vez de el real; mirar tabla ascii
			//cout << "\nSUMA" << suma << '\n';
			if (suma > 9)
			{
				resto = 1; //me llevo 1
				llevadas++; //me he llevado 1 más
			}
			else
				resto = 0;
		}

		//Ahora estos dos whiles es por si algun numero al ser mas largo que el otro se ha quedado sin analizar;
		//mientras haya 9 se va a ir llevando continuamente aunque no se sume con nada, hay que tener eso en cuenta
		while (i < lenNum1 && resto > 0)//Si num1 es el más largo
		{
			if (num1[lenNum1 - 1 - i] == '9')
				llevadas++;
			else
				resto = 0; // ya no se lleva más
			i++;
		}


		while (i < lenNum2 && resto > 0)
		{
			if (num2[lenNum2 - 1 - i] == '9')
				llevadas++;
			else
				resto = 0; // ya no se lleva más
			i++;
		}


		cout << llevadas; //escribo resultado

		cin >> num1 >> num2;
	}

	return 0;
}