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
			string  insertar = "insert into productos(producto,idMarca,descripcion,imagen,precio_costo,precio_venta,existencia,fecha_ingreso) VALUES ('" + producto + "'," + a + ",'" + Descripcion + "','" +Imagen + "'," + b + "," + c + "," + d + "," +FechaI + ")";
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
	void Leer_marca() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		int t = 8;
		if (cn.getConectar()) {
			string a;
			string consulta = "select * from marcas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					gotoxy(80, t);  cout << fila[0] << "  |" << fila[1] << endl;
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
	int validar(int id)
	{
		int q_estado, a;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string uno = to_string(id);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select idMarca from marcas where idMarca = " + uno + "";
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

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		int  xa = 8, xb = 8, xc = 8, xd = 8, xe = 8, xf = 8, xg = 8, xh = 8, xi = 8;
		int za = 8, zb = 8, zc = 8, zd = 8, ze = 8, zf = 8, zg = 8, zh = 8, zi = 8, zj = 8;

		if (cn.getConectar()) {
			string consulta = "select   x.idProducto,x.producto,x.descripcion,x.imagen,x.precio_costo,x.precio_venta, x.existencia, x.fecha_ingreso, m.marca from productos as x inner join marcas as m on x.idMarca=m.idMarca";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					gotoxy(1, xa++); cout << fila[0];//id
					gotoxy(7, xb++); cout << fila[1];//producto
					gotoxy(32, xc++);cout << fila[8];//id marca
					gotoxy(53, xd++); cout << fila[2];//Decripcion
					gotoxy(84, xe++); cout << fila[3];//Imagen
					gotoxy(109, xf++);cout << fila[4];//precioC
					gotoxy(122, xg++); cout << fila[5];//PrecioV
					gotoxy(135, xh++); cout << fila[6];//Existencia
					gotoxy(147, xi++); cout<< fila[7];//fecha
					
					gotoxy(0, zi++); cout << ("|");//0
					gotoxy(4, za++); cout << ("|");//1
					gotoxy(28, zb++); cout << ("|");//2
					gotoxy(45, zc++); cout << ("|");//3
					gotoxy(78, zd++); cout << ("|");//4
					gotoxy(104, ze++); cout << ("|");//5
					gotoxy(118, zf++); cout << ("|");//6
					gotoxy(133, zg++); cout << ("|");//7
					gotoxy(145, zh++); cout << ("|");//8
					gotoxy(167, zj++); cout << ("|");//9

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
					cout << "\nIngrese el nuevo producto:\n";
					getline(cin, pro);
					cout << "Ingrese la nueva descripcion:\n";
					getline(cin, desc);
					cout << "Ingrese la nueva imagen:\n";
					getline(cin, ima);
					cout << "Ingrese el nuevo precio de costo\n";
					cin >> costop;
					string uno = to_string(costop);
					cout << "Ingrese el nuevo precio de venta\n";
					cin >> ventap;
					string dos = to_string(ventap);
					cout << "Ingrese la nueva cantidad de existencias\n";
					cin >> exis;
					string tres = to_string(exis);
					cout << "Ingrese el nuevo id de marca\n";
					cin >> idmarc;
					string cua = to_string(idmarc);
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						string consulta2 = "update productos set producto = '" + pro + "', descripcion = '" + desc + "',  imagen = '" + ima + "', fecha_ingreso = " + fecha + ", precio_costo = " + uno + ", precio_venta = " + dos + ", existencia = " + tres + ", idMarca = " + cua + " where idProducto = " + Id + "";
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