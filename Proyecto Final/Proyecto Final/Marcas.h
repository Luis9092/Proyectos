#pragma once
#include "Producto.h"
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionDB.h"
#include "Marcas.h"
using namespace std;

class Marcas : Marca {

	void gotoxy(int x, int y)
	{
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon, dwPos);
	}

public:
	Marcas() {
	}
	Marcas(string mar) : Marca(mar) {

	}

	// METODOS
	//set (modificar)
	void setmarca(string mar) { marca = mar; }

	//get (mostrar)
	string getmarca() { return marca; }

	// metodo
	void Crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		//idMarca   marca

		if (cn.getConectar()) {
			string  insertar = "insert into marcas(marca) VALUES ('" + marca + "')";
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
		int ab = 8, ac = 8;
		int ba = 8, be = 8, bc = 8;
		if (cn.getConectar()) {
			string a;
			string consulta = "select * from marcas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					gotoxy(41, ab++); cout << fila[0];
					gotoxy(46,ac++); cout << fila[1];
					
					gotoxy(40, bc++); cout << ("|");
					gotoxy(45, ba++); cout << ("|");
					gotoxy(78, be++); cout << ("|");
				}

			}
			else {
				cout << "--------- Error en la Base de datos  ---------" << endl;
			}

		}
		else {
			cout << "--------- Error en la Conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar(int idmarca) {
	
			int q_estado;
			ConexionBD cn = ConexionBD();
			MYSQL_ROW fila;
			MYSQL_RES* resultado;
			cn.abrir_conexion();

			if (cn.getConectar()) {
				string Id = to_string(idmarca);
				string marca;
				char s;
				string consulta2 = "select * from marcas where idMarca= " + Id + "";
				const char* c = consulta2.c_str();
				q_estado = mysql_query(cn.getConectar(), c);

				if (!q_estado) {
					resultado = mysql_store_result(cn.getConectar());

					while (fila = mysql_fetch_row(resultado)) {

						gotoxy(30, 7); cout << "------------    [" << fila[0] << "]     ------------- ";
						gotoxy(25, 8); cout << "Marca: " << fila[1];

						cout << ("\n\n\t\tDesea eliminar [s/n]: ");
						cin >> s;
						if ((s == 's') || (s == 'S')) {
							string consulta3 = "delete from marcas where idMarca =" + Id + "";
							const char* d = consulta3.c_str();
							q_estado = mysql_query(cn.getConectar(), d);
							cout << ("\n\t\t Marca Eliminadocorrectamente ");
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

	void modificar(int idmarca) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string Id = to_string(idmarca);
			string marca;
			char s;
			string consulta2 = "select * from marcas where idMarca= " + Id + "";
			const char* c = consulta2.c_str();
			q_estado = mysql_query(cn.getConectar(), c);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					gotoxy(30, 7); cout << "------------    [" << fila[0] << "]     ------------- ";
					gotoxy(25, 8); cout << "Marca: " << fila[1];
					cout << "\ningrese el nueva marca: \n";
					cin >> marca;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						string consulta2 = "update marcas set marca = '" + marca + "' where idMarca =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
						cout << (" Marca modificada correctamente \n");
					}
					else {
						cout << "\n\n--------- Error al modificar  ---------" << endl;
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