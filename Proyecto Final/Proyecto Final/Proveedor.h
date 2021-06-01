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
				cout << "Ingreso Exitoso!!" << endl;
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
		int  xa = 8, xb = 8, xc = 8, xd = 8, xe = 8, xf = 8, xg = 8, xh = 8, xi = 8;
		int za = 8, zb = 8, zc = 8, zd = 8, ze = 8, zf = 8, zg = 8, zh = 8, zi = 8, zj = 8;

		if (cn.getConectar()) {
			string consulta = "select   * from proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					gotoxy(41,xa++); cout << fila[0]; 
					gotoxy(48, xb++); cout << fila[1];
					gotoxy(73, xc++); cout << fila[2];
					gotoxy(93, xd++); cout << fila[3];
					gotoxy(123, xe++); cout << fila[4];

					gotoxy(40, ze++); cout << ("|");//0
					gotoxy(45, za++); cout << ("|");//1
					gotoxy(68, zb++); cout << ("|");//2
					gotoxy(88, zc++); cout << ("|");//3
					gotoxy(118, zd++); cout << ("|");//4
					gotoxy(134, zf++); cout << ("|");//5

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

						cout << "\n\n\t\tEliminacion Exitosa!!" << endl;
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
					cout << "\nIngrese el nuevo nombre del proveedor:\n";
					getline(cin, pro);
					cout << "Ingrese el nuevo nit:\n";
					getline(cin, nit);
					cout << "Ingrese la nueva direccion\n";
					getline(cin, dire);
					cout << "Ingrese el nuevo telefono\n";
					getline(cin, tel);
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						string consulta2 = "update proveedores set proveedor = '" + pro + "',nit = '" + nit + "',direccion = '" + dire + "',telefono = '" + tel + "' where idProveedor =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
						if (!q_estado) {
							cout << "\n\n--------- Modificacion exitosa  ---------" << endl;
						}
						else {
							cout << "\n\n--------- Error al modificar  ---------" << endl;
						}
					}
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
