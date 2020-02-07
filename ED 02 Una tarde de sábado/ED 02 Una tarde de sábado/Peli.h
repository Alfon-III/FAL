#ifndef peli_h
#define peli_h

#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <String>

#include "Horas.h"

class Pelicula {
private:
	Horas hora_inicio;
	Horas duracion;
	Horas hora_fin; //Hora_inicio + duracion + (posible error)
	string titulo;
public: 
	Pelicula(Horas hora_ini, Horas dur, string tit) {
		hora_inicio = hora_ini;
		hora_fin = hora_ini + dur;
		duracion = dur;
		titulo = tit;
	}
	bool operator < (Pelicula const& pelic) const {
		if (hora_fin.get_TimeInSec() < pelic.hora_fin.get_TimeInSec()) {
			return true;
		}
		else if (hora_fin.get_TimeInSec() == pelic.hora_fin.get_TimeInSec()) {
			if (titulo < pelic.titulo) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
};

inline std::ostream& operator << (std::ostream& out, Pelicula const& peli) {
	cout << setw(2) << setfill('0') << peli.hora_fin.get_hora()<< ":"
		<< setw(2) << setfill('0') << horas.get_min() << ":"
		<< setw(2) << setfill('0') << horas.get_sec();
	return out;
}

inline std::istream& operator>>(std::istream& entrada, Hora& h) {
	h.read(entrada);
	return entrada;
}

#endif //Peli_h