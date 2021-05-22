#pragma once
#include <iostream>
#include "Cliente.h"
#include "ConexionDB.h"
#include "Persona.h"
#include <string>
#include <mysql.h>

using namespace std;

class Cliente : Clientes {

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
	Cliente() {
	}
	Cliente(string nom, string ape, string Nit, int gen, string tel, string coe, string FI) : Clientes(nom, ape, Nit, gen, tel, coe,  FI) {

	}

	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setNit(string Nit) { nit = Nit; }
	void setGenero(int gen) { genero = gen; }
	void setTelefono(string tel) { telefono = tel; }
	void setCorreo_electronico(string coe) { correo = coe; }
	void setFecha_ingreso(string FI) { fechaIngreso = FI; }


	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getNit() { return nit; }
	int getGenero() { return genero; }
	string getTelefono() { return telefono; }
	string getCorreo_electronico() { return correo; }
	string getFecha_ingreso() { return fechaIngreso; }

	// metodo
	void Crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string a = to_string(genero);

		if (cn.getConectar()) {
			string  insertar = "insert into clientes(nombres,apellidos,NIT,genero,telefono,correo_electronico,fechaingreso) VALUES ('" + nombres + "','" +apellidos + "','" + nit + "'," + a + ",'" +telefono+ "','" +correo + "'," + fechaIngreso + ")";
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
	void Leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		int f = 8, x = 8, xa = 8, xb = 8, xc = 8, xd = 8, xe = 8, xf = 8;
		int za = 8, zb=8,zc=8, zd=8,ze=8, zf = 8, zg = 8, zh = 8;
		if (cn.getConectar()) {
			string consulta = "select  * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {

					//	cout << fila[0] << "|      " << fila[1] << "|     " << fila[2] << "|    " << fila[3] << "| " << fila[5] << "|      " << fila[6] << "         |" << fila[7];
					gotoxy(1, f++); cout << fila[0]; //id
					gotoxy(5, x++); cout << fila[1]; //Nombres
					gotoxy(30, xa++); cout << fila[2]; //Apellidos
					gotoxy(54, xb++); cout << fila[3]; //Nit
					gotoxy(92, xc++); cout << fila[5]; //telefono
					gotoxy(110, xd++); cout << fila[6]; //correo
					gotoxy(138, xe++); cout << fila[7]; //fecha

					if (strlen(fila[4]) == 0) {
						gotoxy(69, xf++); cout << "    Femenino"; //Genero
					}// Verificar esto
					else {
						gotoxy(69, xf++); cout << "    Masculino";//Genero
					}
					gotoxy(4, za++); cout << ("|"); //id
					gotoxy(28, zb++); cout << ("|"); //Nombres
					gotoxy(52, zc++); cout << ("|"); //Apellidos
					gotoxy(68, zd++); cout << ("|"); //Nit
					gotoxy(87, ze++); cout << ("|"); //telefono
					gotoxy(106, zf++); cout << ("|"); //correo
					gotoxy(134, zg++); cout << ("|"); //fecha
					gotoxy(160, zh++); cout << ("|");
				
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
	void Eliminar(int idmarca) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		char z;
		if (cn.getConectar()) {
			string Id = to_string(idmarca);
			// executar el query
			string eliminar = "select * from clientes where idCliente= " + Id + "";
			const char* c = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {

					gotoxy(30, 8); cout << "------------    [" << fila[0] << "]     ------------- ";
					gotoxy(25, 9); cout << "Nombres: " << fila[1];
					gotoxy(25, 10); cout << "Apellidos: " << fila[2];
					gotoxy(25, 11); cout << "Nit: " << fila[3];
					gotoxy(25, 12); cout << "Genero: " << fila[4];
					gotoxy(25, 13); cout << "Telefono: " << fila[5];
					gotoxy(25, 14); cout << "Corre eletronico: " << fila[6];
					gotoxy(25, 15); cout << "Fecha ingreso: " << fila[7];

					gotoxy(25, 20); cout << ("Desea Eliminar [s/n]: ");
					cin >> z;
					if ((z == 's') || (z == 'S')) {
						string eliminar = "delete from clientes where idCliente =" + Id + "";
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
			string nom, ape, nit, telefono, correo, fechaIngreso = "now()";
			char s, gen;
			string consulta2 = "select * from clientes where idCliente= " + Id + "";
			const char* c = consulta2.c_str();
			q_estado = mysql_query(cn.getConectar(), c);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					gotoxy(30, 8); cout << "------------    [" << fila[0] << "]     ------------- ";
					gotoxy(25, 9); cout << "Nombres: " << fila[1];
					gotoxy(25, 10); cout << "Apellidos: " << fila[2];
					gotoxy(25, 11); cout << "Nit: " << fila[3];
					gotoxy(25, 12); cout << "Genero: ";
					if (strlen(fila[4]) == 0) {
						cout << "Femenino";
					}
					else {
						cout << "Masculino";
					}
					gotoxy(25, 13); cout << "Telefono: " << fila[5];
					gotoxy(25, 14); cout << "Correo electronico: " << fila[6];
					gotoxy(25, 15); cout << "Fecha ingreso: " << fila[7];

					cin.ignore();
					cout << "\nIngrese los nuevos Nombres:\n";
					getline(cin, nom);
					cout << "Ingrese los nuevos apellidos:\n";
					getline(cin, ape);
					cout << "Ingrese el nuevo nit:\n";
					getline(cin, nit);
					cout << "Ingrese el nuevo genero [M o F]:\n";
					cin >> gen;
					cin.ignore();
					if ((gen == 'm') || (gen == 'M')) {
						gen = '1';
					}
					if ((gen == 'f') || (gen == 'F')) {
						gen = '0';
					}
					cout << "Ingrese el nuevo numero de telefono:\n";
					getline(cin, telefono);
					cout << "Ingrese el nuevo correo electronico:\n";
					getline(cin, correo);
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						string consulta2 = "update clientes set nombres = '" + nom + "', apellidos = '" + ape + "', NIT= '" + nit + "', genero = " + gen + ", telefono = '" + telefono + "',correo_electronico =' " + correo + "', fechaingreso = " + fechaIngreso + " where idCliente =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
						if (!q_estado) {
							cout << "\n\n--------- Modificacion Exitosa  ---------" << endl;
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

