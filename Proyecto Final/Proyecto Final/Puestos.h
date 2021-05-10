#pragma once
#include <iostream>
#include "Puestos.h"
using namespace std;

class Puestos
{
		// atributos
	protected: string Puesto;
			 // costructor
	protected:
		Puestos() {
		}
		Puestos(string pu) {
			Puesto = pu;
		}
};

