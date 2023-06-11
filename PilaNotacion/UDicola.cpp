//---------------------------------------------------------------------------

#pragma hdrstop

#include "UDicola.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

DicolaV::DicolaV() {
	ini = fin = 0;
	v = new int[MAXVD];
}

bool DicolaV::vacia() {
	return ini == fin;
}

int DicolaV::siguiente(int dir) {
	if (dir == MAXVD - 1)
		return 0;
	else
		return dir + 1;
}

void DicolaV::poner(int e) {
	if (siguiente(fin) != ini) {
		v[fin] = e;
		fin = siguiente(fin);
	}
}

void DicolaV::sacar(int &e) {
	if (!vacia()) {
		e = v[ini];
		ini = siguiente(ini);
	}
}

int DicolaV::primero() {
	if (!vacia())
		return v[ini];
}

int DicolaV::anterior(int dir) {
	if (dir == 0)
		return MAXVD - 1;
	else
		return dir - 1;
}

int DicolaV::ultimo() {
	if (!vacia()) {
		return v[fin - 1];
	}
}

void DicolaV::poner_frente(int e) {
	if (siguiente(fin) != ini) {
		ini = anterior(ini);
		v[ini] = e;
	}
}

void DicolaV::sacar_final(int &e) {
	if (!vacia()) {
		e = v[fin - 1];
		fin = anterior(fin);
	}
}

string DicolaV::to_str() {
	string s = "<<";
	int e;
	DicolaV* aux = new DicolaV();
	while (!vacia()) {
		sacar(e);
		aux->poner(e);
		s += to_string(e);
		if (!vacia())
			s += ",";
	}
	while (!aux->vacia()) {
		aux->sacar(e);
		poner(e);
	}
	return s + "<<";
}
