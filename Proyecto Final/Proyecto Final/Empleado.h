#pragma once
#include <iostream>
#include "Persona.h"
#include "ConexionDB.h"
#include "Empleado.h"
#include <string>
#include <mysql.h>

using namespace std;

class Empleado : Empleados {

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
	Empleado() {
	}
	Empleado(string nom, string ape, string direc, string tel, string DP, int gen, string fn, int idp, string iniciof, string FI) : Empleados(nom, ape, direc, tel, DP, gen, fn, idp, iniciof, FI) {

	}

	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setADireccion(string direc) { direccion = direc; }
	void setTelefono(string tel) { telefono = tel; }
	void setDpi(string DP) { dpi = DP; }
	void setPGenero(int gen) { genero = gen; }
	void setFecha_nacimiento(string fn) { Fnacido = fn; }
	void setId_puesto(int idp) { idpuesto = idp; }
	void setFecha_nicio_laboral(string iniciof) { Finicio = iniciof; }
	void setFecha_ingreso(string FI) { fechai = FI; }


	string getNombres() { return  nombres; }
	string getApellidos() { return  apellidos; }
	string getADireccion() { return  direccion; }
	string getTelefono() { return  telefono; }
	string getDpi() { return  dpi; }
	int getPGenero() { return  genero; }
	string getFecha_nacimiento() { return  Fnacido; }
	int getId_puesto() { return idpuesto; }
	string getFecha_nicio_laboral() { return  Finicio; }
	string getFecha_ingreso() { return fechai; }

	// metodo
	void Crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string a = to_string(genero);
		string b = to_string(idpuesto);
		if (cn.getConectar()) {

			string  insertar = "insert into empleados(nombres,apellidos,direccion,telefono,DPI,genero,fecha_nacimiento,idPuesto,fecha_inicio_labores,fechaingreso) VALUES ('" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "','" + dpi + "'," + a + ",'" + Fnacido + "'," + b + ",'" + Finicio + "'," + fechai + ")";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "\t\t\tIngreso Exitoso, Grande Luis ... ...\n";
			}
			else {
				cout << "\t\t\t--------- Error al insertar ---------";
			}

		}
		else {
			gotoxy(40, 20); cout << "--------- Error en la Conexion ---------";
		}
		cn.cerrar_conexion();
	}

	void Leer_puesto() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		int t = 8;
		if (cn.getConectar()) {
			string a;
			string consulta = "select * from puestos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					gotoxy(80, t); cout << fila[0] << "  |" << fila[1] << endl;
					t++;
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

	int validar (int id)
	{
		int q_estado, a;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string uno = to_string(id);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select idPuesto from puestos where idPuesto = " + uno + "";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					if (fila[0] == 0) {
						return 1;
					}
					else {
						return 3;
					}
				}
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
			string consulta = "select   x.idempleado,x.nombres,x.apellidos,x.direccion,x.telefono,x.DPI, x.genero, x.fecha_nacimiento, fecha_inicio_labores,fechaingreso, m.puesto from empleados as x inner join puestos as m on x.idPuesto=m.idPuesto";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "|   " << fila[1] << "|   " << fila[2] << "|   " << fila[3] << "|    " << fila[4] << "|   " << fila[5] << "|   " << fila[6] << "  |" << fila[7] << "   |" << fila[8] << "  |" << fila[9] << " |" << fila[10] << endl;
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
			string eliminar = "select   x.idempleado,x.nombres,x.apellidos,x.direccion,x.telefono,x.DPI, x.genero, x.fecha_nacimiento, fecha_inicio_labores,fechaingreso, m.puesto from empleados as x inner join puestos as m on x.idPuesto=m.idPuesto where idempleado= " + Id + "";
			const char* c = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {

					cout << "\n\n\n\t\t\t------------    [" << fila[0] << "]     ------------- ";
					cout << "\n\tNombres: " << fila[1];
					cout << "\n\tApellidos: " << fila[2];
					cout << "\n\tDireccion: " << fila[3];
					cout << "\n\tTelefono: " << fila[4];
					cout << "\n\tDPI: " << fila[5];
					cout << "\n\tGenero: " << fila[6];
					cout << "\n\tFecha Nacimiento: " << fila[7];
					cout << "\n\tFecha inicio labor: " << fila[8];
					cout << "\n\tFecha Ingreso: " << fila[9];
					cout << "\n\tId Puesto: " << fila[10];

					cout << ("\n\n\tDesea Eliminar [s/n]: ");
					cin >> z;
					if ((z == 's') || (z == 'S')) {
						string eliminar = "delete from empleados where idempleado =" + Id + "";
						const char* c = eliminar.c_str();
						q_estado = mysql_query(cn.getConectar(), c);

						gotoxy(30, 22); cout << "Eliminacion Exitosa, Grande Luis ...";
					}
					else {
						gotoxy(30, 22); cout << ("Registro No Eliminado");
					}
				}
			}
			else {
				gotoxy(30, 23);	cout << "-----------   Error al eliminar    ---------";
			}
		}
		else {
			gotoxy(30, 24);	cout << "--------- Error en la Conexion ---------";
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
			string nom, ape, direc, tel, dpi, fechaN, fechainicio, fechaIngreso = "now()";
			int gen = 0, idpuesto = 0;
			char s;
			string consulta2 = "select   x.idempleado,x.nombres,x.apellidos,x.direccion,x.telefono,x.DPI, x.genero, x.fecha_nacimiento, fecha_inicio_labores,fechaingreso, m.puesto from empleados as x inner join puestos as m on x.idPuesto=m.idPuesto where idempleado= " + Id + "";
			const char* c = consulta2.c_str();
			q_estado = mysql_query(cn.getConectar(), c);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "\n\n\n\t\t\t------------    [" << fila[0] << "]     ------------- ";
					cout << "\n\tNombres: " << fila[1];
					cout << "\n\tApellidos: " << fila[2];
					cout << "\n\tDireccion: " << fila[3];
					cout << "\n\tTelefono: " << fila[4];
					cout << "\n\tDPI: " << fila[5];
					cout << "\n\tGenero: " << fila[6];
					cout << "\n\tFecha Nacimiento: " << fila[7];
					cout << "\n\tFecha inicio labor: " << fila[8];
					cout << "\n\tFecha Ingreso: " << fila[9];
					cout << "\n\tId Puesto: " << fila[10];

					cin.ignore();
					cout << ("\n\n\n\tNombreS: ") << fila[1] << endl;
					cout << ("\tDesea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cin.ignore();
						cout << "\n\tingrese el nuevo Nombres: \n\t";
						getline(cin, nom);

						string consulta2 = "update empleados set nombres = '" + nom + "' where idempleado =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}
					cin.ignore();
					cout << ("\n\n\tApellidos: ") << fila[2] << endl;
					cout << ("\tDesea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cin.ignore();

						cout << "\n\tingrese el nueva Apellido: \n\t";
						getline(cin, ape);
						string consulta2 = "update empleados set apellidos = '" + ape + "' where idempleado =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}


					cout << ("\n\n\tDireccion: ") << fila[3] << endl;
					cout << ("\tDesea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cin.ignore();
						cout << "\n\tingrese la nueva direccion : \n\t";
						getline(cin, direc);
						string consulta2 = "update empleados set direccion= '" + direc + "' where idempleado =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}

					cout << ("\n\n\tTelefono: ") << fila[4] << endl;
					cout << ("\tDesea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cin.ignore();
						cout << "\n\tingrese el nuevo No. telefono: \n\t";
						getline(cin, tel);
						string consulta2 = "update empleados set telefono = '" + tel + "' where idempleado =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}


					cout << ("\n\n\tDPI: ") << fila[5] << endl;
					cout << ("\tDesea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cin.ignore();
						cout << "\n\tingrese el nuevo No. dpi: \n\t";
						getline(cin, dpi);
						string consulta2 = "update empleados set DPI = '" + dpi + "' where idempleado =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}

					cout << ("\n\n\tGenero: ") << fila[6] << endl;
					cout << ("\tDesea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\n\tingrese el nueva existencia: \n\t";
						cin >> gen;
						string uno = to_string(gen);
						string consulta2 = "update empleados set genero = " + uno + " where idempleado =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}

					cout << ("\n\n\tFecha Fecha de nacimiento: ") << fila[7] << endl;
					cout << ("\tDesea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << ("\n\tIngrese nueva fecha de nacimiento: \n\t");
						cin >> fechaN;
						string consulta2 = "update empleados set fecha_nacimiento = '" + fechaN + "' where idempleado =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}
					cout << ("\n\n\tId puesto: ") << fila[10] << endl;
					cout << ("\tDesea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\n\tingrese nuevo Id puesto: \n\t";
						cin >> idpuesto;
						string dos = to_string(idpuesto);
						string consulta2 = "update empleados set idPuesto = " + dos + " where idempleado =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}

					cout << ("\n\n\tFecha Fecha inicio laboral: ") << fila[8] << endl;
					cout << ("\tDesea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << ("\n\tIngrese nueva fecha incio laboral: \n\t");
						cin >> fechainicio;
						string consulta2 = "update empleados set fecha_inicio_labores = '" + fechainicio + "' where idempleado =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}

					cout << ("\n\n\tFecha Fecha de ingreso: ") << fila[9] << endl;
					cout << ("\tDesea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						string consulta2 = "update empleados set fechaingreso = " + fechaIngreso + " where idempleado =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
						cout << ("\n\n\tFecha modificado correctamente");
					}

					cout << ("\t\t\n\nDatos modificados correctamente");
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