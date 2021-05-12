#pragma once
#include <iostream>
#include "Persona.h"
#include "ConexionDB.h"
#include "Proveedor.h"
#include <string>
#include <mysql.h>

using namespace std;

class Proveedor : Proveedores {

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
	Proveedor() {
	}
	Proveedor(string pro, string ni, string direc, string tel) : Proveedores(pro, ni, direc, tel) {

	}

	void setProveedor(string pro) { proveedor = pro; }
	void setNit(string ni) { nit = ni; }
	void setADireccion(string direc) { direccion = direc; }
	void setTelefono(string tel) { telefono = tel; }
	
	

	string getProveedor() { return proveedor; }
	string getNit() { return nit; }
	string getDireccion() { return direccion; }
	string getTelefono() { return telefono; }

	void Crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string  insertar = "insert into proveedores(proveedor,nit,direccion,telefono) VALUES ('" + proveedor + "','" + nit + "','" + direccion + "','" + telefono + "')";
		
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso, Grande Luis ... ..." << endl;
			}
			else {
				cout << "--------- Error al Ingresar Datos ---------" << endl;
			}
		}
		else {
			cout << "--------- Error en la Conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}
	void Leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "select   * from proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " |      " << fila[1] << "|     " << fila[2] << "|    " << fila[3] << "|    " << fila[4]  << endl;
				}

			}
			else {
				cout << "\n\n\t--------- Error en la Base de datos  ---------";
			}
		}
		else {
			cout << "\n\n\t--------- Error en la Conexion ---------";
		}
		cn.cerrar_conexion();
	}	
	void eliminar(int idpro) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		char z;
		if (cn.getConectar()) {
			string Id = to_string(idpro);
			// executar el query
			string eliminar = "select * from proveedores where idProveedor= " + Id + "";
			const char* c = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {

					gotoxy(30, 7); cout << "------------    [" << fila[0] << "]     ------------- ";
					gotoxy(25, 8); cout << "Proveedor: " << fila[1];
					gotoxy(25, 9); cout << "Nit: " << fila[2];
					gotoxy(25, 10); cout << "Direccion: " << fila[3];
					gotoxy(25, 11); cout << "Telefono: " << fila[4];
					
					gotoxy(25, 18); cout << ("Desea Eliminar [s/n]: ");
					cin >> z;
					if ((z == 's') || (z == 'S')) {
						string eliminar = "delete from proveedores where idProveedor =" + Id + "";
						const char* c = eliminar.c_str();
						q_estado = mysql_query(cn.getConectar(), c);

						cout << "\n\n\t\tEliminacion Exitosa, Grande Luis ..." << endl;
					}
					else {
						cout << ("\n\t\tRegistro No Eliminado");
					}
				}
			}
			else {
				cout << "\n\n\t\t--------- Error al eliminar  ---------" << endl;
			}
		}
		else {
			cout << "\n\n\t\t--------- Error en la Conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}
	void modificar(int idpro) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string Id = to_string(idpro);
			string pro, nit, dire, tel;
			char s;
			string consulta2 = "select * from proveedores where idProveedor= " + Id + "";
			const char* c = consulta2.c_str();
			q_estado = mysql_query(cn.getConectar(), c);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					gotoxy(30, 7); cout << "------------    [" << fila[0] << "]     ------------- ";
					gotoxy(25, 8); cout << "Proveedor: " << fila[1];
					gotoxy(25, 9); cout << "Nit: " << fila[2];
					gotoxy(25, 10); cout << "Direccion: " << fila[3];
					gotoxy(25, 11); cout << "Telefono: " << fila[4];
					cin.ignore();

					cout << ("\n\nProveedor: ") << fila[1] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cin.ignore();

						cout << "ingrese el nuevo Proveedor: \n";
						getline(cin, pro);
						string consulta2 = "update proveedores set proveedor = '" + pro + "' where idProveedor =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}
				
					cout << ("\n\nNit: ") << fila[2] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cin.ignore();

						cout << "ingrese nuevo  Nit: \n";
						getline(cin, nit);
						string consulta2 = "update proveedores set nit = '" + nit + "' where idProveedor =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}

					cout << ("\n\nDireccion: ") << fila[3] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cin.ignore();
						cout << "ingrese la nueva direccion: \n";
						getline(cin, dire);
						string consulta2 = "update proveedores set direccion = '" + dire + "' where idProveedor =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}
					cin.ignore();

					cout << ("\n\nDTelefono: ") << fila[4] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
			
						cout << "ingrese nuevo No. Telfono: \n";
						cin >> tel;
						string consulta2 = "update proveedores set telefono = '" + tel + "' where idProveedor =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}
					cin.ignore();

				}

			}
			else {
				cout << "\n\n--------- Error al modificar  ---------" << endl;
			}

		}
		else {
			cout << " \n\n---------  Error en la Conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}

};
