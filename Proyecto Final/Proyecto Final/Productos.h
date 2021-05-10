#pragma once
#include <iostream>
#include "Producto.h"
#include "ConexionDB.h"
#include "Producto.h"
#include <string>
#include <mysql.h>

using namespace std;

class Productos : Producto {

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
	Productos() {
	}
	Productos(string pro, int idmarc, string desc, string ima, float pcos, float pven, int exis, string FI) : Producto(pro, idmarc, desc, ima, pcos,pven,exis,FI) {

	}

	void setProducto(string pro) { producto = pro; }
	void setIdmarca(int idmarc) { idmarca = idmarc; }
	void setADescripcion(string desc) { Descripcion = desc; }
	void setImagen(string ima) { Imagen = ima; }
	void setPcosto(float pcos) {pcosto= pcos; }
	void setPventa(float pven) { pventa = pven; }
	void setExistencia(int exis) { existencia = exis; }
	void setFechaI(string FI) { FechaI = FI; }

	
	string getProducto() { return producto; }
	int getIdmarca() { return idmarca; }
	string getDescripcion() { return Descripcion; }
	string getImagen() { return Imagen; }
	float getPcosto() { return pcosto; }
	float getPventa() { return pventa; }
	int getExistencia() { return existencia; }
	string getFechaI() { return FechaI; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string a = to_string(idmarca);
		string b = to_string(pcosto);
		string c = to_string(pventa);
		string d = to_string(existencia);


		if (cn.getConectar()) {
			string  insertar = "inser into productos(producto,idMarca,descripcion,imagen,precio_costo,precio_venta,existencia,fecha_ingreso) VALUES ('" + producto + "'," + a + ",'" + Descripcion + "','" +Imagen + "'," + b + "," + c + "," + d + "," +FechaI + ")";
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
			gotoxy(40, 20);cout << "--------- Error en la Conexion ---------" ;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "select   x.idProducto,x.producto,x.descripcion,x.imagen,x.precio_costo,x.precio_venta, x.existencia, x.fecha_ingreso, m.marca from productos as x inner join marcas as m on x.idMarca=m.idMarca";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "|      " << fila[1] << "|     " << fila[2] << "|    " << fila[3] << "|    " << fila[4] << "|   " << fila[5] << "|      " << fila[6] << "         |" << fila[7] << "   |" << fila[8] << endl;
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
			//string eliminar = "select * from productos where Id_Producto= " + Id + "";
			string eliminar = "select   x.idProducto,x.producto,x.descripcion,x.imagen,x.precio_costo,x.precio_venta, x.existencia, x.fecha_ingreso, m.marca from productos as x inner join marcas as m on x.idMarca=m.idMarca where idProducto= " + Id + "";
			const char* c = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {

					gotoxy(30, 7); cout << "------------    [" << fila[0] << "]     ------------- ";
					gotoxy(25, 8); cout << "Producto: " << fila[1];
					gotoxy(25, 9); cout << "Descripcion: " << fila[2];
					gotoxy(25, 10); cout << "Imagen: " << fila[3];
					gotoxy(25, 11); cout << "Precio Costo: " << fila[4];
					gotoxy(25, 12); cout << "Precio Venta: " << fila[5];
					gotoxy(25, 13); cout << "Existencia: " << fila[6];
					gotoxy(25, 14); cout << "Fecha Ingreso: " << fila[7];
					gotoxy(25, 15); cout << "Id Marca: " << fila[8];

					gotoxy(25, 20); cout << ("Desea Eliminar [s/n]: ");
					cin >> z;
					if ((z == 's') || (z == 'S')) {
						string eliminar = "delete from productos where idProducto =" + Id + "";
						const char* c = eliminar.c_str();
						q_estado = mysql_query(cn.getConectar(), c);

						gotoxy(30,22); cout << "Eliminacion Exitosa, Grande Luis ...";
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
			string pro, desc, ima, fecha = "now()";
			int exis = 0, idmarc;
			double costop, ventap;
			char s;
			string consulta2 = "select   x.idProducto,x.producto,x.descripcion,x.imagen,x.precio_costo,x.precio_venta, x.existencia, x.fecha_ingreso, m.marca from productos as x inner join marcas as m on x.idMarca=m.idMarca where idProducto= " + Id + "";
			const char* c = consulta2.c_str();
			q_estado = mysql_query(cn.getConectar(), c);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					gotoxy(30, 7); cout << "------------    [" << fila[0] << "]     ------------- ";
					gotoxy(25, 8); cout << "Producto: " << fila[1];
					gotoxy(25, 9); cout << "Descripcion: " << fila[2];
					gotoxy(25, 10); cout << "Imagen: " << fila[3];
					gotoxy(25, 11); cout << "Precio Costo: " << fila[4];
					gotoxy(25, 12); cout << "Precio Venta: " << fila[5];
					gotoxy(25, 13); cout << "Existencia: " << fila[6];
					gotoxy(25, 14); cout << "Fecha Ingreso; " << fila[7];
					gotoxy(25, 15); cout << "Id Marca: " << fila[8];

					cin.ignore();

					cout << ("\n\nProducto: ") << fila[1] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cin.ignore();
						cout << "ingrese el nuevo Producto: \n";
						getline(cin, pro);

						string consulta2 = "update productos set producto = '" + pro + "' where idProducto =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}
					cin.ignore();
					cout << ("\n\nDescripcion: ") << fila[2] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cin.ignore();

						cout << "ingrese el nueva descripcion: \n";
						getline(cin, desc);
						string consulta2 = "update productos set descripcion = '" + desc + "' where idProducto =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}
					cin.ignore();

					cout << ("\n\nimagen: ") << fila[3] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "ingrese la nueva imagen : \n";
						cin >> ima;
						string consulta2 = "update productos set imagen = '" + ima + "' where idProducto =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}

					cout << ("\n\nPrecio Costo: ") << fila[4] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "ingrese el nuevo precio costo: \n";
						cin >> costop;
						string uno = to_string(costop);
						string consulta2 = "update productos set precio_costo = " + uno + " where idProducto =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}


					cout << ("\n\nPrecio Venta: ") << fila[5] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "ingrese el nuevo precio venta: \n";
						cin >> ventap;
						string dos = to_string(ventap);
						string consulta2 = "update productos set precio_venta = " + dos + " where idProducto =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}

					cout << ("\n\nExistencia: ") << fila[6] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "ingrese el nueva existencia: \n";
						cin >> exis;
						string tres = to_string(exis);
						string consulta2 = "update productos set existencia = " + tres + " where idProducto =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}



					cout << ("\n\nFecha ingreso: ") << fila[7] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						string consulta2 = "update productos set fecha_ingreso = '" + fecha + "' where idProducto =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}
					cout << ("\n\nId Marca: ") << fila[8] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "ingrese nuevo Id Marca: \n";
						cin >> idmarc;
						string cua = to_string(idmarc);
						string consulta2 = "update productos set idMarca = '" + cua + "' where idProducto =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
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