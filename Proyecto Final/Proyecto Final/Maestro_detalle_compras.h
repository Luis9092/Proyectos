#pragma once
#include "Producto.h"
#include "Maestro_detalle_compras.h"
#include <iostream>
#include "ConexionDB.h"
#include <string>
#include <mysql.h>

using namespace std;


	class Maestro_detalle_compras :Compras {

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
		Maestro_detalle_compras(int Nocompra, int idprod, string fechaO, string ing) : Compras(Nocompra, idprod, fechaO, ing) {

		}

		void setNo_orden_compra(int Nocompra) { No_orden_compra = Nocompra; }
		void setAId_proveedor(int idprod) { idProveedor = idprod; }
		void setAFecha_orden(string fechaO) { fecha_orden = fechaO; }
		void setFecha_ingreso(string ing) { fecha_ingreso = ing; }

		


		int getNo_orden_compra() { return  No_orden_compra; }
		int getId_proveedor() { return  idProveedor; }
		string getADFecha_orden() { return  fecha_orden; }
		string getFecha_ingreso() { return  fecha_ingreso; }

void leer() {
			int q_estado;
			ConexionBD cn = ConexionBD();
			MYSQL_ROW fila;
			MYSQL_RES* resultado;
			cn.abrir_conexion();

			if (cn.getConectar()) {
				string consulta = "select   x.idProducto,x.producto,x.descripcion,precio_costo,x.precio_venta, m.marca from productos as x inner join marcas as m on x.idMarca=m.idMarca";

				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getConectar(), c);
				if (!q_estado) {
					resultado = mysql_store_result(cn.getConectar());
					while (fila = mysql_fetch_row(resultado)) {
						cout << fila[0] << "|      " << fila[1] << "|     " << fila[2] << "|    " << fila[3] << "|    " << fila[4] << "|   " << fila[5] << endl;
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
		void Leer_compras() {
			int q_estado;
			ConexionBD cn = ConexionBD();
			MYSQL_ROW fila;
			MYSQL_RES* resultado;
			cn.abrir_conexion();
			int zx = 8;
			if (cn.getConectar()) {
				string consulta = "select   x.idCompra,x.no_orden_compra,x.fecha_orden,x.fechaingreso, m.proveedor from compras as x inner join proveedores as m on x.idProveedor=m.idProveedor";
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getConectar(), c);
				if (!q_estado) {
					resultado = mysql_store_result(cn.getConectar());
					while (fila = mysql_fetch_row(resultado)) {
						gotoxy(64,zx++);	cout << fila[0] << "|      " << fila[1] << "|     " << fila[2] << "|    " << fila[3] << "|    " << fila[4] << "| " << fila[4] << endl;
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


};


class Maestro_detalle_compras2 :Compras_detalle {

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

	Maestro_detalle_compras2() {
	}
	Maestro_detalle_compras2(int Nocompra, int idprod, int cant, float pcu) : Compras_detalle(Nocompra, idprod, cant, pcu) {

	}

	
	void setId_compra(int Nocompra) { Id_compra = Nocompra; }
	void setId_producto(int idprod) { Id_producto = idprod; }
	void setCantidad(int cant) { cantidad = cant; }
	void setPrecio_Unitario(float pcu) { precio_costo_U = pcu; }

	int getId_compra() { return Id_compra; }
	int getId_producto() { return  Id_producto; }
	int getCantidad() { return  cantidad; }
	float getPrecio_Unitario() { return  precio_costo_U; }

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "select   x.idProducto,x.producto,x.descripcion,precio_costo,x.precio_venta, m.marca from productos as x inner join marcas as m on x.idMarca=m.idMarca";

			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "|      " << fila[1] << "|     " << fila[2] << "|    " << fila[3] << "|    " << fila[4] << "|   " << fila[5] << endl;
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

	void Crear_detalle() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		
		string a = to_string(Id_compra);
		string b = to_string(Id_compra);
		string d = to_string(cantidad);
		string e = to_string(precio_costo_U);

		if (cn.getConectar()) {
			string  insertar = "insert into compras_detalle(idCompra,idProducto,cantidad,precio_costo_unitario) VALUES (" + a + "," + b + "," + d + "," + e + ")";

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
	void Leer_compras_Detalle() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "select   x.idCompra_detalle,x.cantidad,x.precio_costo_unitario, m.no_orden_compra ,d.producto from compras_detalle as x inner join compras as m on x.idCompra=m.idCompra inner join productos as d on x.idProducto=d.idProducto";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " |      " << fila[1] << "|       " << fila[2] << "|             " << fila[3] << "|     " << fila[4] << endl;
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


};