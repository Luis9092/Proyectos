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
	
	void Crear2(int idProveedor) {
		int q_estado;
		int q_estado2;
		int q_estado3;
	
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		string c = to_string(idProveedor);
		int z;
		int val;
		if (cn.getConectar()) {
			string consulta = "select * from proveedores where idProveedor= " + c + "";
			const char* cz = consulta.c_str();
			q_estado3 = mysql_query(cn.getConectar(), cz);
			if (!q_estado3) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					fila[0], fila[1];
					cout <<"\t\t\t\t\t\t\t"<< fila[1];
				}
			}
			else {
				cout << "\n\n\t--------- Error en la Base de datos  ---------";
			}

		
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
						// Compras
					
						if (cn.getConectar()) {
							int op = z;
							string fs = to_string(op);
							string  insertar = "insert into compras(no_orden_compra,idproveedor,fecha_orden,fechaingreso) VALUES (" + fs + "," + c + "," + fecha_orden + "," + fecha_ingreso + ")";

							const char* g = insertar.c_str();
							q_estado2 = mysql_query(cn.getConectar(), g);
							if (!q_estado2) {

								if (!q_estado2) {
									cout << "\n\n\t\t\t\tIngreso Exitoso!!";
									
								}
								else {
									cout << "\n\t\t\t--------- Error al Ingresar Datos ---------";
									
								}

							}
							else {
								cout << "\n\n\t--------- Error en la Conexion1 ---------";
							}

						}
						else {
							cout << "\n\n\t--------- Error en la Base de datos2  ---------";
						}
					}
				}
				else {
					cout << "\n\n\t--------- Error en la Conexion2 ---------";
				}
		
	}
		else {
				cout << "\n\n\t--------- Error en la Conexion ---------";
	}

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
				 cout << "\n\t\t\t\t\t\tEliminacion  Exitosa ... ...";
			}
			else {
				gotoxy(40, 18);	cout << "--------- Error al ELiminar Datos ---------";
			}
			q_estado = mysql_query(cn.getConectar(), ii);
			if (!q_estado) {
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


	void modificar(int idpro) {
		int q_estado;
		int q_estado2;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string Id = to_string(idpro);
		string gh = to_string(idProveedor);

		if (cn.getConectar()) {
			char s, gen;
		
				string consulta2 = "update compras set idProveedor = " + gh + ", fecha_orden = " + fecha_orden + ", fechaingreso= " + fecha_ingreso + " where idCompra=" + Id + "";

				const char* c = consulta2.c_str();
				q_estado = mysql_query(cn.getConectar(), c);
				if (!q_estado) {
				}
				else {
				}
	}
	else {
		cout << "\n\n--------- Error En la conexion  ---------" << endl;
}		cn.cerrar_conexion();
	}

	int validaridcom(int id)
	{
		int q_estado, a;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string uno = to_string(id);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select idCompra from compras where idCompra = " + uno + "";
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

	int validaridetalle(int id)
	{
		int q_estado, a;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string uno = to_string(id);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select idCompra_detalle from compras_detalle where idCompra_detalle = " + uno + "";
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
	void Leer_idcomp() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		int t = 6;
		if (cn.getConectar()) {
			string a;
			int t = 8, h = 8;
			int  b = 8, d = 8, e = 8, f = 8, g = 8;

			string consulta = "select * from compras";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {

					gotoxy(32, 4); cout << ("Id Disponible");
					gotoxy(25, 5); cout << ("--------------------------------");
					gotoxy(24, 6); cout << ("|  ID |");
					gotoxy(35, 6); cout << ("|No. Orden     |");
					gotoxy(25, 7); cout << ("--------------------------------");

					gotoxy(25, t++); cout << fila[0];
					gotoxy(32, h++); cout << fila[1];

					gotoxy(24, b++); cout << ("|");
					gotoxy(30, d++); cout << ("|");
					gotoxy(56, e++); cout << ("|");


				}
				cout << ("\n\t\t\t---------------------------------");
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
	void Leer_prov() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		int t = 6;
		if (cn.getConectar()) {
			string a;
			int t = 8, h = 8;
			int  b = 8, d = 8, e = 8, f = 8, g = 8;

			string consulta = "select * from proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
				
					gotoxy(32, 4); cout << ("Id Disponible");
					gotoxy(25, 5); cout << ("--------------------------------");
					gotoxy(24, 6); cout << ("|  ID |");
					gotoxy(35, 6); cout << ("      Proveedor      |");
					gotoxy(25, 7); cout << ("--------------------------------");

					gotoxy(25, t++); cout << fila[0];
					gotoxy(32, h++); cout << fila[1];

					gotoxy(24, b++); cout << ("|");
					gotoxy(30, d++); cout << ("|");
					gotoxy(56, e++); cout << ("|");


				}
				cout << ("\n\t\t\t---------------------------------");
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
			string consulta = "select idProveedor from proveedores where idProveedor = " + uno + "";
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
	Maestro_detalle_compras2( int idprod, int cant) : Compras_detalle( idprod, cant) {

	}


	void setId_producto(int idprod) { Id_producto = idprod; }
	void setCantidad(int cant) { cantidad = cant; }

	int getId_producto() { return  Id_producto; }
	int getCantidad() { return  cantidad; }
	/*
	void prod(int Id_Producto) {
		int q_estado3;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		string b = to_string(Id_producto);

		if (cn.getConectar()) {
			string consulta = "select * from productos where idProducto= " + b + "";
			const char* cz = consulta.c_str();
			q_estado3 = mysql_query(cn.getConectar(), cz);
			if (!q_estado3) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					fila[0], fila[1];
					cout << "\t\t\t\t\t\t\t" << fila[1];
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
	*/
	void Leer5(int id) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		string Id = to_string(id);
		if (cn.getConectar()) {
			string consulta = "select * from productos where idProducto= " + Id + "";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					fila[0], fila[1];
					cout <<"\n\t\t\t\t\t\t\t"<< fila[1]<<"          "<<fila[5];
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

	

	void entrada() {
		int q_estado;
		int q_estado2;
		int q_estado3;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		string b = to_string(Id_producto);
		string d = to_string(cantidad);

		float zeta=0;
		int val;
		

		if (cn.getConectar()) {
			string consulta = "select max(idCompra) FROM compras";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					val = atoi(fila[0]);
				}

				
				if (cn.getConectar()) {

					string consulta3 = "select precio_costo from productos where idProducto="+ b +"";
					const char* cf = consulta3.c_str();
					q_estado3 = mysql_query(cn.getConectar(), cf);
					if (!q_estado3) {
						resultado = mysql_store_result(cn.getConectar());
						while (fila = mysql_fetch_row(resultado)) {
							zeta = atof(fila[0]);
						
						}
					
				if (cn.getConectar()) {
					int op = val;
					string hj = to_string(op);
					string hk = to_string(zeta);

					string  insertar = "insert into compras_detalle(idCompra,idProducto,cantidad,precio_costo_unitario) VALUES (" + hj + "," + b + "," + d + "," + hk + ")";

					const char* p = insertar.c_str();

					q_estado2 = mysql_query(cn.getConectar(), p);
					if (!q_estado2) {


						if (!q_estado2) {
							
						}
						else {
							
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
					gotoxy(94, xh++); cout << fila[9];//Marca
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
					gotoxy(93, zg++); cout << ("|");//7
				
					gotoxy(126, zh++); cout << ("|");//8
					gotoxy(140, zj++); cout << ("|");//9
					gotoxy(166, zk++); cout << ("|");//9
					gotoxy(105, zl++); cout << ("|");//9

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

	void modificar(int idpro) {
		int q_estado;
		int q_estado2;
		int q_estado3;

		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		string Id = to_string(idpro);
		string gh = to_string(Id_producto);
		string gj = to_string(cantidad);
	
		float zeta=0;
		if (cn.getConectar()) {

			string consulta3 = "select precio_costo from productos where idProducto=" + gh + "";
			const char* cf = consulta3.c_str();
			q_estado2 = mysql_query(cn.getConectar(), cf);
			if (!q_estado2) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					zeta = atof(fila[0]);

				}
			

if (cn.getConectar()) {
			char s, gen;
			string hk = to_string(zeta);

string consulta2 = "update compras_detalle set idProducto = " +gh + ", cantidad = " + gj + ", precio_costo_unitario= " +hk + " where idCompra_detalle =" + Id + "";
						const char* c = consulta2.c_str();
						q_estado = mysql_query(cn.getConectar(), c);
						if (!q_estado) {
							
						}
						else {	
						}
			}
			else {
				cout << "\n\n--------- Error al Conectar  ---------" << endl;
			}

		}
		else {
			cout << " \n\n---------  Error en la Conexion ---------" << endl;
		}
			}

	

		cn.cerrar_conexion();
	}
	void producto_Leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		int t = 8,h=8;
		int  b = 8, d = 8, e = 8, f = 8, g = 8 ;
		if (cn.getConectar()) {
			string consulta = "select * from productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					/// <summary>
					/// 
					/// </summary>
					gotoxy(125, 4); cout << ("Id disponible");

					
					gotoxy(119, 5); cout << ("----------------------");
					gotoxy(119, 6); cout << ("|   ID   |");
					gotoxy(130, 6); cout << (" Producto |");
					gotoxy(119, 7); cout << ("----------------------");

					gotoxy(120, t++); cout << fila[0];
					gotoxy(130, h++); cout<<fila[1];
				
					gotoxy(119, b++); cout << ("|");
					gotoxy(128, d++); cout << ("|");
					gotoxy(140, e++); cout << ("|");


					
				}
				cout << ("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t----------------------");
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
			string consulta = "select idProducto from productos where idProducto = " + uno + "";
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


};