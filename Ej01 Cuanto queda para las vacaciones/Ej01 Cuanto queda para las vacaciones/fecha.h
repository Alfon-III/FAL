#ifndef FECHA
#define FECHA

#include <iostream>
#include <stdexcept>
using namespace std;

class Fecha {
public:
	//Constructores
	Fecha() {};
	Fecha(int d, int m, int a) : dia(d), mes(m), anyo(a) {
		if (m <= 0 || m > 12) {
			throw std::invalid_argument("fecha invalida");
		}
		else if (d <= 0 || d > get_diasMes(m, a)) {
			throw std::invalid_argument("fecha invalida");
		}
	};

	// operador de asignación
	Fecha& operator =(Fecha const& other) {
		if (this != &other) {
			dia = other.dia; mes = other.mes; anyo = other.anyo;
		}
		return *this;
	}

	int get_dia() const { return dia; };
	int get_mes() const { return mes; };
	int get_anyo() const { return anyo; }
	bool bisiesto() const {
		return bisiesto(anyo);	}
	
	int numDias(Fecha const& fAnterior) const {
		if (*this <= fAnterior) return 0;
		else if (this -> anyo == fAnterior.anyo) {
			if (this -> mes == fAnterior.mes) { // mismo año y mismo mes
				return this -> dia - fAnterior.dia;
			}
			else { // mismo a~no distinto mes.
				return numDiasMeses(fAnterior, *this);
			}
		}
		else { // Distinto a~no
		// Completa este a~no hasta el final
			int suma = numDiasMeses(fAnterior, { 31 ,12 , fAnterior.anyo });
			// Suma los a~nos completos entre una fecha y otra
			for (int i = fAnterior.anyo + 1; i < this -> anyo; ++i)
				suma += get_diasAnyo(i);
			// Completa con el principio del año
			suma += numDiasMeses({ 1 ,1 , this -> anyo }, *this);
			return suma;
		}
	}

	//Operators para el Objeto Fecha
	bool operator < (Fecha const& f) const {
		if (anyo < f.anyo) return true;
		else if (anyo > f.anyo) return false;
		else if (mes < f.mes) return true;
		else if (mes > f.mes) return false;
		else if (dia < f.dia) return true;
		else return false;
	}

	bool operator == (Fecha const& f) const {
		return anyo == f.anyo && mes == f.mes && dia == f.dia;
	}
	bool operator <= (Fecha const& f) const {
		return *this < f || *this == f;
	}
	bool operator > (Fecha const& f) const {
		return !(*this <= f);
	}
	bool operator >= (Fecha const& f) const {
		return !(*this < f);
	}

private:
	const int DIAS_ANYO = 365;
	int dia, mes, anyo;
	const int diasMes[12] = { 31 ,29 ,31 ,30 ,31 ,30 ,31 ,31 ,30 ,31 ,30 ,31 };

	bool bisiesto(int a) const {
		return a % 4 == 0 && (a % 100 != 0 || a % 400 == 0);
	}

	int get_diasMes(int m, int a) const {
		if (m != 2) return diasMes[m - 1];
		else if (bisiesto(a)) return diasMes[m - 1];
		else return diasMes[m - 1] - 1;
	}

	int get_diasAnyo(int a) const {
		if (bisiesto(a)) return DIAS_ANYO + 1;
		else return DIAS_ANYO;
	}

	int numDiasMeses(Fecha const& fAnterior, Fecha const& fPosterior) const {
		if (fPosterior.mes == fAnterior.mes) { // mismo año, mismo mes
			return fPosterior.dia - fAnterior.dia + 1;
		}
		else { // mismo año distinto mes.
		// completa este mes hasta el final
			int suma = get_diasMes(fAnterior.mes, fAnterior.anyo) - fAnterior.dia + 1;
			// suma el numero de meses completos entre una fecha y la otra
			for (int i = fAnterior.mes + 1; i < fPosterior.mes; ++i)
				suma += get_diasMes(i, fAnterior.anyo);
			// completa con el comienzo del ultimo mes.
			suma += fPosterior.dia;
			return suma;
		}
	}
};

//Escritura/respuestra
inline std::ostream& operator << (std::ostream& out, Fecha const& f) {
	out << f.get_anyo() << ' ' << f.get_mes() << ' ' << f.get_dia() << '\n';
	return out;
}

//Lectura/Inicializacion
inline std::istream& operator >> (std::istream& in, Fecha& f) {
	int a, m, d;
	in >> a >> m >> d;
	f = Fecha(a, m, d);
	return in;
}
#endif
