#include "Producto.h"
//#include "Maestro_detalle_compras.h"
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
	Maestro_detalle_compras(int idprod, string fechaO, string ing) : Compras(idprod, fechaO, ing) {

	}
    void setAId_proveedor(int idprod) { idProveedor = idprod; }
	void setAFecha_orden(string fechaO) { fecha_orden = fechaO; }
	void setFecha_ingreso(string ing) { fecha_ingreso = ing; }



	int getId_proveedor() { return  idProveedor; }
	string getADFecha_orden() { return  fecha_orden; }
	string getFecha_ingreso() { return  fecha_ingreso; }
	
	void Crear2() {
		int q_estado;
		int q_estado2;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		string c = to_string(idProveedor);
		int z;
		int val;
		if (cn.getConectar()) {
			string consulta = "select max(no_orden_compra) FROM compras";
			const char* j = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), j);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					val = atoi(fila[0]);
					z = val + 1;
				}

				if (cn.getConectar()) {
					int op = z;
					string fs = to_string(op);
					string  insertar = "insert into compras(no_orden_compra,idproveedor,fecha_orden,fechaingreso) VALUES (" + fs + "," + c + "," + fecha_orden + "," + fecha_ingreso + ")";

					const char* g = insertar.c_str();

					q_estado2 = mysql_query(cn.getConectar(), g);
					if (!q_estado2) {

						if (!q_estado2) {
							cout << "\n\n\t\t\t\tIngreso Exitoso, Grande Luis ...";
							_getch();
						}
						else {
							cout << "\n\t\t\t--------- Error al Ingresar Datos ---------";
							_getch();
						}

					}
					else {
						cout << "\n\n\t--------- Error en la Conexion ---------";
					}

				}
				else {
					cout << "\n\n\t--------- Error en la Base de datos  ---------";
				}
			}
		}
		else {
			cout << "\n\n\t--------- Error en la Conexion ---------";
		}

		cn.cerrar_conexion();
	}

	

	
	void modificar_compras(int idcom) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string Id = to_string(idcom);
			int No_orden, Idprov;
			string Ofecha, fecha_IN = "now()";
			double precio_un;

			char s;
			string consulta2 = "select   x.idCompra,x.no_orden_compra,x.fecha_orden,x.fechaingreso, m.proveedor from compras as x inner join proveedores as m on x.idProveedor=m.idProveedor where idCompra= " + Id + "";

			const char* c = consulta2.c_str();

			q_estado = mysql_query(cn.getConectar(), c);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "\n------------    [" << fila[0] << "]     ------------- ";
					cout << "\nNo Orden Compra: " << fila[1];
					cout << "\nFecha orden" << fila[2];
					cout << "\nFecha Ingreso " << fila[3];
					cout << "\nProveedor " << fila[4];

					cout << ("\n\nNo Orden Compra: ") << fila[1] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {

						cout << "\ningrese el nuevo No. Orden Compra: \n";
						cin >> No_orden;
						string a = to_string(No_orden);
						string consulta2 = "update compras set no_orden_compra= " + a + " where idCompra =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}

					cout << ("\n\nFecha id Proveedor: ") << fila[4] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {

						cout << "\ningrese nuevo Id Proveedor: \n";
						cin >> Idprov;
						string b = to_string(Idprov);
						string consulta2 = "update compras set idProveedor = " + b + " where idCompra =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}

					cout << ("\n\nFecha Orden: ") << fila[2] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\ningrese la nueva Fecha Orden: \n";
						cin >> Ofecha;
						string consulta2 = "update compras set fecha_orden = '" + Ofecha + "' where idCompra =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
					}

					cout << ("\n\nDFecha Ingreso: ") << fila[3] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {

						string consulta2 = "update compras set fechaingreso = " + fecha_IN + " where idCompra =" + Id + "";
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


		if (cn.getConectar()) {
			string Id = to_string(idcom);
			int idcomp, idprods, cantidad;
			double precio_un;

			char s;
			string consulta3 = "select   x.idCompra_detalle,x.cantidad,x.precio_costo_unitario, m.no_orden_compra ,d.producto from compras_detalle as x inner join compras as m on x.idCompra=m.idCompra inner join productos as d on x.idProducto=d.idProducto where idCompra_detalle= " + Id + "";

			const char* d = consulta3.c_str();

			q_estado = mysql_query(cn.getConectar(), d);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "\n------------    [" << fila[0] << "]     ------------- ";
					cout << "\t\t\t\t\t\tICantidad: " << fila[1];
					cout << "\t\t\t\t\t\tIPrecio Costo Unitario: " << fila[2];
					cout << "\t\t\t\t\t\tIId Compra: " << fila[3];
					cout << "\t\t\t\t\t\tIId Producto: " << fila[4];

					// Seguna parte maestro detalle
					// Verificar este update, es lo mismo que la primer update que compras :v

					cout << ("\n\n\t\t\t\t\t\tId Producto: ") << fila[4] << endl;
					cout << (" \t\t\t\t\t\ttDesea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {

						cout << " \t\t\t\t\t\tingrese nuevo Id Producto:";
						cin >> idprods;
						string b = to_string(idprods);
						string consulta3 = "update compras_detalle set idProducto = " + b + " where idCompra_detalle =" + Id + "";
						const char* d = consulta3.c_str();
						q_estado = mysql_query(cn.getConectar(), d);
					}

					cout << ("\n\n\t\t\t\t\t\tCantidad: ") << fila[1] << endl;
					cout << ("\t\t\t\t\t\tDesea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {

						cout << " \t\t\t\t\t\tingrese la nueva Cantidad: ";
						cin >> cantidad;
						string cc = to_string(cantidad);
						string consulta3 = "update compras_detalle set cantidad = " + cc + " where idCompra_detalle =" + Id + "";
						const char* d = consulta3.c_str();
						q_estado = mysql_query(cn.getConectar(), d);
					}

					cout << ("\n\n\t\t\t\t\t\tPrecio Costo Unitario: ") << fila[2] << endl;
					cout << ("\t\t\t\t\t\tDesea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\t\t\t\t\t\tingrese la nueva Costo unitario:";
						cin >> precio_un;
						string dd = to_string(precio_un);
						string consulta3 = "update compras_detalle set precio_costo_unitario = " + dd + " where idCompra_detalle =" + Id + "";
						const char* d = consulta3.c_str();
						q_estado = mysql_query(cn.getConectar(), d);
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
		cout << ("\n\t\t\t\t\t Modificacion Exitosa!!");
		cn.cerrar_conexion();
	}


	void Eliminar(int id) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string a = to_string(id);
			string eliminar = "delete from compras_detalle where idcompra = " + a + "";
			string eliminar2 = "delete from compras where idcompra = " + a + "";
			const char* i = eliminar.c_str();
			const char* ii = eliminar2.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				gotoxy(40, 18); cout << "Eliminacion 1 Exitosa, Grande Luis ... ...";
			}
			else {
				gotoxy(40, 18);	cout << "--------- Error al ELiminar Datos ---------";
			}
			q_estado = mysql_query(cn.getConectar(), ii);
			if (!q_estado) {
				gotoxy(40, 19); cout << "Eliminacion 2 Exitosa, Grande Luis ... ...";
			}
			else {
				gotoxy(40, 18);	cout << "--------- Error al ELiminar Datos ---------";
			}
		}
		else {
			cout << "--------- Error en la Conexion ---------" << endl;
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
	Maestro_detalle_compras2( int idprod, int cant, float pcu) : Compras_detalle( idprod, cant, pcu) {

	}


	void setId_producto(int idprod) { Id_producto = idprod; }
	void setCantidad(int cant) { cantidad = cant; }
	void setPrecio_Unitario(float pcu) { precio_costo_U = pcu; }

	int getId_producto() { return  Id_producto; }
	int getCantidad() { return  cantidad; }
	float getPrecio_Unitario() { return  precio_costo_U; }


	void entrada() {
		int q_estado;
		int q_estado2;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		string b = to_string(Id_producto);
		string d = to_string(cantidad);
		string e = to_string(precio_costo_U);

		string numero;
		int z;
		int val;
		if (cn.getConectar()) {
			string consulta = "select max(idCompra) FROM compras";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					val = atoi(fila[0]);
					cout << val;
				}

				if (cn.getConectar()) {
					int op = val;
					string hj = to_string(op);
					string  insertar = "insert into compras_detalle(idCompra,idProducto,cantidad,precio_costo_unitario) VALUES (" + hj + "," + b + "," + d + "," + e + ")";

					const char* p = insertar.c_str();

					q_estado2 = mysql_query(cn.getConectar(), p);
					if (!q_estado2) {


						if (!q_estado2) {
							cout << "\n\n\t\t\t\tIngreso Exitoso, Grande Luis ...";
						}
						else {
							cout << "\n\t\t\t--------- Error al Ingresar Datos ---------";
						}

					}
					else {
						cout << "\n\n\t--------- Error en la Conexion ---------";
					}

				}
				else {
					cout << "\n\n\t--------- Error en la Base de datos  ---------";
				}
			}
		}
		else {
			cout << "\n\n\t--------- Error en la Conexion ---------";
		}

		cn.cerrar_conexion();
	}

	void Leer_compras() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		int  xa = 8, xb = 8, xc = 8, xd = 8, xe = 8, xf = 8, xg = 8, xh = 8, xi = 8, xj = 8, xl = 8;
		int za = 8, zb = 8, zc = 8, zd = 8, ze = 8, zf = 8, zg = 8, zh = 8, zi = 8, zj = 8, zk = 8,zl = 8;

		if (cn.getConectar()) {
			//string consulta = "select max(idCompra) FROM compras";
		//	string consulta= "select max(no_orden_compra) FROM compras";
			string consulta4 = "select   x.idCompra_detalle, x.cantidad,x.precio_costo_unitario, m.no_orden_compra ,d.producto,d.descripcion,k.idCompra, k.fecha_orden,k.fechaingreso, b.marca,f.proveedor from compras_detalle as x inner join compras as m on x.idCompra=m.idCompra inner join productos as d on x.idProducto=d.idProducto inner join compras as k on x.idCompra=k.idCompra inner join marcas as b on  d.idProducto=b.idMarca inner join proveedores as f on k.idProveedor=f.idProveedor ";

			const char* jk = consulta4.c_str();
			q_estado = mysql_query(cn.getConectar(), jk);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					gotoxy(1, xa++); cout << fila[0];//id compra detalle
					gotoxy(7, xb++); cout << fila[3];//No Orden
					gotoxy(18, xc++); cout << fila[4];//Porducto
					gotoxy(37, xd++); cout << fila[5];//Decripcion
					gotoxy(69, xe++); cout << fila[1];//Cantidad
					gotoxy(77, xf++); cout << fila[2];//precio
					gotoxy(85, xg++); cout << fila[6];//id Compra
					gotoxy(93, xh++); cout << fila[9];//Marca
					gotoxy(107, xl++); cout << fila[10];//Proveedor

					gotoxy(128, xi++); cout << fila[7];//fecha Orden
					gotoxy(142, xj++); cout << fila[8];//fecha Ingreso
				
					gotoxy(0, zi++); cout << ("|");//0
					gotoxy(5, za++); cout << ("|");//1
					gotoxy(16, zb++); cout << ("|");//2
					gotoxy(35, zc++); cout << ("|");//3
					gotoxy(67, zd++); cout << ("|");//4
					gotoxy(76, ze++); cout << ("|");//5
					gotoxy(84, zf++); cout << ("|");//6
					gotoxy(92, zg++); cout << ("|");//7
					gotoxy(105, zl++); cout << ("|");//9

					gotoxy(126, zh++); cout << ("|");//8
					gotoxy(140, zj++); cout << ("|");//9
					gotoxy(166, zk++); cout << ("|");//9
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