#pragma once
#include "Persona.h"

#include <iostream>
using namespace std;

class Proveedores
{
	// atributos
protected: string proveedor,nit,direccion,telefono;

		 // costructor
protected:
	Proveedores() {
	}
	Proveedores(string pro, string ni, string direc, string tel) {
		proveedor = pro;
		nit = ni;
		direccion = direc;
		telefono = tel;
	}
};

class Puestos
{
protected: string puesto;
protected:
	Puestos() {
	}
	Puestos(string pu) {
		puesto = pu;
		
	}
};

class Empleados
{
protected: string nombres, apellidos, direccion, telefono,dpi,fechai,Finicio ,Fnacido;
		 int genero, idpuesto;
protected:
	Empleados() {
	}
	Empleados(string nom, string ape, string direc, string tel,string DP, int gen, string fn,int idp, string iniciof, string FI) {
		nombres = nom;
		apellidos = ape;
		direccion = direc;
		telefono = tel;
		dpi = DP;
		genero = gen;
		Fnacido = fn;
		idpuesto = idp;
		Finicio = iniciof;
		fechai = FI;
	}
};

class Clientes
{
protected: string nombres, apellidos, nit, telefono, correo, fechaIngreso;
		 int genero;
protected:
	Clientes() {
	}
	Clientes(string nom, string ape, string Nit, int gen, string tel, string coe, string FI) {
		nombres = nom;
		apellidos = ape;
		nit = Nit;
		genero = gen;
		telefono = tel;
		correo = coe;
		fechaIngreso = FI;
	
	}
};

