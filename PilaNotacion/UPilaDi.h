//---------------------------------------------------------------------------

#ifndef UPilaDiH
#define UPilaDiH
//---------------------------------------------------------------------------
#include <iostream>
#include "UDicola.h"

using namespace std;

class PilaDi {
private:
	DicolaV* k;

public:
	PilaDi();
	bool vacia();
	void meter(int e);
	void sacar(int& e);
	int cima();
	string to_str();
};
#endif
