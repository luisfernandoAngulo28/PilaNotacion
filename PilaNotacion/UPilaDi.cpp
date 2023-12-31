//---------------------------------------------------------------------------

#pragma hdrstop

#include "UPilaDi.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PilaDi::PilaDi() {
	k = new DicolaV();
}

bool PilaDi::vacia() {
	return k->vacia();
}

void PilaDi::meter(int e) {
	k->poner(e);
}

void PilaDi::sacar(int& e) {
	if (!vacia())
		k->sacar_final(e);
}

int PilaDi::cima() {
	return k->ultimo();
}

string PilaDi::to_str() {
	string r = "";
	PilaDi* aux = new PilaDi();
	while (!vacia()) {
		int e;
		sacar(e);
		r += "| " + to_string(e) + " |\n";
		aux->meter(e);
	}
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		meter(e);
	}
	r += "+---+\n";
	return r;
}

