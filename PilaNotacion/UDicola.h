//---------------------------------------------------------------------------

#ifndef UDicolaH
#define UDicolaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

const int MAXVD = 30;

class DicolaV {
private:
	int* v;
	int ini, fin;

	int siguiente(int dir);
	int anterior(int dir);

public:
	DicolaV();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	int ultimo();
	void poner_frente(int e);
	void sacar_final(int &e);
	string to_str();
};
#endif
