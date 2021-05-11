#pragma once
#include "Producto.h"
#include "Maestro_detalle_compras.h"
#include <iostream>
#include "ConexionDB.h"
#include <string>
#include <mysql.h>

using namespace std;

class Maestro_detalle_compras : Compras {

	void gotoxy(int x, int y)
	{
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon, dwPos);
	}
	// constructor
public:
	Maestro_detalle_compras() {
	}
	Maestro_detalle_compras(int Nocompra, int idprod, string fechaO, string ing) : Compras( Nocompra, idprod, fechaO,  ing) {

	}

	void setNo_orden_compra(int Nocompra) { No_orden_compra = Nocompra; }
	void setAId_proveedor(int idprod) { idProveedor = idprod; }
	void setAFecha_orden(string fechaO) { fecha_orden = fechaO; }
	void setFecha_ingreso(string ing) { fecha_ingreso = ing; }


	int getNo_orden_compra() { return  No_orden_compra; }
	int getId_proveedor() { return  idProveedor; }
	string getADFecha_orden() { return  fecha_orden; }
	string getFecha_ingreso() { return  fecha_ingreso; }

	
	void Crear1() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string x = to_string(No_orden_compra);
		string c = to_string(idProveedor);

		if (cn.getConectar()) {
			string  insertar = "insert into compras(no_orden_compra,idproveedor,fecha_orden,fechaingreso) VALUES (" + x + "," + c + ",'" + fecha_orden + "'," + fecha_ingreso + ")";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				gotoxy(40, 18); cout << "Ingreso Exitoso, Grande Luis ... ...";
			}
			else {
				gotoxy(40, 18);	cout << "--------- Error al Ingresar Datos ---------";
			}
		}
		else {
			gotoxy(40, 20); cout << "--------- Error en la Conexion ---------";
		}
		cn.cerrar_conexion();
	}

};