#include <mysql.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include "Productos.h"
#include "Marcas.h"
#include "Proveedor.h"
#include "Puesto.h"
#include "Empleado.h"
#include"Cliente.h"
#include "Maestro_detalle_compras.h"
#include "Maestro_ventas.h"
#include <conio.h>
#include <fstream>
#include "SerialPort.h"

//NOTA:::: lo que haria falta es lo de validar en compras(modificar) y validar las demas tablas 
//ejemplo Empleados que valide el puesto 
typedef std::basic_ifstream<TCHAR> tifstream;
typedef std::basic_string<TCHAR> tstring;
using namespace  std;

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];

char commport[] = "\\\\.\\COM4";
char* port = commport;
SerialPort arduino(port);

#define getch() _getch()
#define s 40
#define ENTER 13 
#define BACKSPACE 8

void fondo();
void cambiarcolor(int x);
void gotoxy(int x, int y);
void co(int, int);


void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void automatico();
void apagar();
void encender();
void Mandarlo();
void control8();
void control7();
void control6();
void control5();
void control4();
void control3();
void control2();
void control1();
void control();
void cargando();
void marco();
void bla(int);
void marco2();
void marco_factura();
void insertar_producto();
void mostrar_producto();
void eliminar_producto();
void modificar_producto();

void insertar_marca();
void mostrar_marca();
void eliminar_marca();
void modificar_marca();

void insertar_proveedor();
void mostrar_proveedor();
void eliminar_proveedor();
void modificar_proveedor();

void insertar_puesto();
void mostrar_puesto();
void eliminar_puesto();
void modificar_puesto();

void insertar_empleado();
void mostrar_empleado();
void eliminar_empleado();
void modificar_empleado();

void insertar_cliente();
void mostrar_cliente();
void eliminar_cliente();
void modificar_cliente();

void insertar_Maestro_detalle_compras();
void mostrar_Maestro_detalle_compras();
void eliminar_Maestro_detalle_compras();
void modificar_Maestro_detalle_compras();

void insertar_Maestro_detalle_ventas();
void mostrar_Maestro_detalle_ventas();
void eliminar_Maestro_detalle_ventas();
void modificar_Maestro_detalle_ventas();
void txt();
int main() {
	_getch();
	//insertar_Maestro_detalle_ventas();
	//	system("mode con: cols=390 lines=540");
	//marco_factura();
//Maestro_detalle_ventas2 a;
//a.Crear_factura();
//	insertar_Maestro_detalle_ventas();
//mostrar_Maestro_detalle_ventas();
//	mostrar_Maestro_detalle_compras();
//	insertar_Maestro_detalle_compras();
//	modificar_Maestro_detalle_compras();
//	mostrar_empleado();
// 
	//txt();
	encender();
	//control1();
//txt();
//	cout << ("\n\n\n");
//	system("pause");
}


void txt() {
	int q_estado;
	int q_estado2;
	int q_estado3;
	int q_estado4;
	int q_estado5;
	ConexionBD cn = ConexionBD();
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	cn.abrir_conexion();
	int lleva, lleva2;
	float lleva3;
	ofstream archivo;

	if (cn.getConectar()) {
		string consulta = "select max(idVenta) from ventas";
		const char* c = consulta.c_str();
		q_estado = mysql_query(cn.getConectar(), c);
		if (!q_estado) {
			resultado = mysql_store_result(cn.getConectar());
			while (fila = mysql_fetch_row(resultado)) {
				lleva = atoi(fila[0]);
				//		cout << lleva << endl;
			}
			string serie, nombres, apellidos, nit, telefono, correo, nombres2, apellidos2, fechafactura;
			int idVenta, noFact;
			if (cn.getConectar()) {
				int valor = lleva;

				string encontrar = to_string(valor);
				string consulta4 = "select   x.idVenta, x.nofactura,x.serie, m.nombres,m.apellidos, m.NIT, m.telefono,m.correo_electronico, d.nombres,d.apellidos, fechafactura from ventas as x inner join clientes as m on x.idCliente=m.idCliente inner join empleados as d on x.idempleado=d.idempleado where idVenta=" + encontrar + "";

				const char* jk = consulta4.c_str();
				q_estado2 = mysql_query(cn.getConectar(), jk);
				if (!q_estado2) {
					resultado = mysql_store_result(cn.getConectar());
					while (fila = mysql_fetch_row(resultado)) {
						idVenta = atoi(fila[0]);
						noFact = atoi(fila[1]);
						serie = fila[2];
						nombres = fila[3];
						apellidos = fila[4];
						nit = fila[5];
						telefono = fila[6];
						correo = fila[7];
						nombres2 = fila[8];
						apellidos2 = fila[9];
						fechafactura = fila[10];
					}
					string producto[10], descripcion[10];
					int idvent[20], cantidad[20];
					int aumentar = 0;
					float precio[20];
					int xx = 0;
					if (cn.getConectar()) {
						string encontrado = to_string(noFact);

						string consulta5 = "select   x.idVenta_detalle,d.producto,d.descripcion, x.precio_unitario,x.cantidad, m.idVenta from ventas_detalle as x inner join ventas as m on x.idVenta=m.idVenta inner join productos as d on x.idProducto=d.idProducto where nofactura=" + encontrado + "";
						const char* cc = consulta5.c_str();
						q_estado3 = mysql_query(cn.getConectar(), cc);
						if (!q_estado3) {
							resultado = mysql_store_result(cn.getConectar());
							while (fila = mysql_fetch_row(resultado)) {
						
								idvent[aumentar] = atoi(fila[0]);
								producto[aumentar] = fila[1];
								descripcion[aumentar] = fila[2];
								precio[aumentar] = atof(fila[3]);
								cantidad[aumentar] = atoi(fila[4]);

								++aumentar;
							}

							int mm = 9, incrementar = 0;
							float obtenersubtotal[20];
							float obtenertotal = 0;
							if (cn.getConectar()) {
								string consultar = "select (cantidad * precio_unitario) from ventas_detalle where idventa=" + encontrar + "";
								const char* dc = consultar.c_str();
								q_estado5 = mysql_query(cn.getConectar(), dc);
								if (!q_estado5) {
									resultado = mysql_store_result(cn.getConectar());
									while (fila = mysql_fetch_row(resultado)) {

										obtenersubtotal[incrementar] = atof(fila[0]);
										++incrementar;
									}

									if (cn.getConectar()) {
										string consulta6 = "select sum(cantidad * precio_unitario) from ventas_detalle where idventa=" + encontrar + "";
										const char* bb = consulta6.c_str();
										q_estado4 = mysql_query(cn.getConectar(), bb);
										if (!q_estado4) {
											resultado = mysql_store_result(cn.getConectar());
											while (fila = mysql_fetch_row(resultado)) {
												obtenertotal = atof(fila[0]);
											}
								


											archivo.open("factura2.txt", ios::out);
											if (archivo.fail()) {
												cout << ("Archivo No encontrado") << endl;
												exit(1);
											}
											else {
												archivo << ("|-------------------------------------------------------------------------------|")<<endl;
												archivo << ("|                                Empresa Onitech, S.A                           |") << endl;
												archivo << ("|                      4ta calle Poniente, Antigua Guatemala                    |") << endl;
												archivo << ("|                                     Tel 454343423                             |") << endl;
												archivo << ("|-------------------------------------------------------------------------------|") << endl;

												archivo << ("Serie ") << serie << " No. Factura:  " << noFact << "                       Fecha: " << fechafactura << endl << endl;
												archivo << ("No Pedido: ") << idVenta << endl << endl << endl;
												archivo << "-----------------------------------------------------------------------------------\n";
												archivo << "Cliente: "<<endl;
												archivo << nombres << " " << apellidos << endl;
												archivo << ("NIT: ") << nit << "                                            Atendido Por: " << endl;
												archivo << ("No telefono: ") << telefono << "                      " << nombres2 << " " << apellidos2 << endl;
												archivo << ("Correo: ") << correo << endl << endl << endl;
												archivo << "|--------------------------------------------------------------------------------|\n";
												archivo << "| No |   Producto     |   Descripcion     |	Precio    |  Cantidad    |  Subtotal  |\n";
												archivo << "|--------------------------------------------------------------------------------|\n";



												for (int i = 0; i < aumentar; i++) {
													archivo << "|" << idvent[i] << "  | " << producto[i] << "       | " << descripcion[i] << "        |Q. " << precio[i] << "      |" << cantidad[i] << "       |Q." << obtenersubtotal[i] << endl;
												}
												archivo << "|--------------------------------------------------------------------------------|\n";

												archivo << "|                                                            | Total:  " << obtenertotal << endl;
												archivo << "|--------------------------------------------------------------------------------|\n";
												archivo << "|                             Gusto en atenderle!!                               |\n";
												archivo << "|--------------------------------------------------------------------------------|\n";
                                              	archivo.close();

											}

										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void control1() {
	int a;
	do {
		

		system("cls");
		fondo();
		marco();
		
		co(0, 243);

		gotoxy(47, 2); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(47, 3); cout << ("°°°                      Distribuidora Onitech, S.A.                  °°°");
		gotoxy(47, 4); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(70, 8); cout << ("1.   P R O D U C T O S");
		gotoxy(70, 9); cout << ("2.   M A R C A S ");
		gotoxy(70, 10); cout << ("3.   P R O V E E D O R E S ");
		gotoxy(70, 11); cout << ("4.   P U E S T O S ");
		gotoxy(70, 12); cout << ("5.   E M P L E A D O S ");
		gotoxy(70, 13); cout << ("6.   C L I E N T E S ");
		gotoxy(70, 14); cout << ("7.   C O M  P R A S");
		gotoxy(70, 15); cout << ("8.   V E N T A S ");
		gotoxy(70, 16); cout << ("9.   S A L I R ");
		gotoxy(70, 20); cout << ("Ingresar Opcion: ");
		cin >> a;
		switch (a) {
		case 1: system("cls");
			control();
			break;

		case 2: system("cls");
			control2();
			break;

		case 3: system("cls");
			control3();
			break;


		case 4: system("cls");
			control4();
			break;

		case 5: system("cls");
			control5();
			break;

		case 6: system("cls");
			control6();
			break;

		case 7: system("cls");
			control7();
			break;

		case 8: system("cls");
			control8();
			break;

		}

	} while (a != 9);
}

void control() {
	int a;
	do {
		system("cls");
		marco2();
		gotoxy(47, 2); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(47, 3); cout << ("°°°                           P R O D U C T O S                       °°°");
		gotoxy(47, 4); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(70, 8); cout << ("1. Registrar Datos");
		gotoxy(70, 9); cout << ("2. Mostrar Datos ");
		gotoxy(70, 10); cout << ("3. Eliminar datos");
		gotoxy(70, 11); cout << ("4. Modificar Datos");
		gotoxy(70, 12); cout << ("5. Salir");
		gotoxy(70, 15); cout << ("Ingresar Opcion: ");
		cin >> a;
		switch (a) {
		case 1: system("cls");
			insertar_producto();
			break;

		case 2: system("cls");
			mostrar_producto();
			break;

		case 3:system("cls");
			mostrar_producto();
			eliminar_producto();
			break;

		case 4:system("cls");
			mostrar_producto();
			modificar_producto();
			break;

		}

	} while (a != 5);
}


void insertar_producto()
{
	string pro, desc, ima, Fecha_Ingreso = "now()";
	int idmar, exis, t = 15;
	float pcosto, pventa;
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                 R E G I S T R A R              D A T O S                        |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");

	cin.ignore();
	gotoxy(20, 8); cout << "Ingrese Producto: ";
	getline(cin, pro);
	gotoxy(20, 9); cout << "Ingrese Descripcion: ";
	getline(cin, desc);
	gotoxy(20, 10); cout << "Ingrese Imagen: ";
	getline(cin, ima);
	gotoxy(20, 11); cout << "Ingrese Precio Costo: ";
	cin >> pcosto;
	gotoxy(20, 12); cout << "Ingrese Precio Venta: ";
	cin >> pventa;
	gotoxy(20, 13); cout << "Ingrese Existencia: ";
	cin >> exis;
	gotoxy(20, 14); cout << "Ingrese Id Marca: ";
	Productos Pu = Productos();

	Pu.Leer_marca();
	gotoxy(38, 14); cin >> idmar;
	cout << Pu.validar(idmar);

	while (Pu.validar(idmar) == 1)
	{
		gotoxy(20, t); cout << "Id marca invalido, ingrese un id existente: ";
		t++;
		cin >> idmar;
		Pu.validar(idmar);
	
	}
	Productos P = Productos(pro, idmar, desc, ima, pcosto, pventa, exis, Fecha_Ingreso);

	P.crear();

	system("pause");

}

void mostrar_producto() {
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");
	gotoxy(0, 5); cout<<("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	gotoxy(0, 6); cout << "|ID |";gotoxy(10, 6); cout << "     Producto     |"; gotoxy(32, 6); cout << "  Id marca   |"; gotoxy(56, 6); cout << "     Descripcion      |";
	gotoxy(88, 6); cout << "     Imagen     |"; gotoxy(106, 6); cout << "Precio costo|"; gotoxy(120, 6); cout << "Precio Venta |";
	gotoxy(135, 6); cout << "Existencia|"; gotoxy(150, 6); cout<< "Fecha Ingreso    |";
	gotoxy(0, 7); cout << ("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");

	Productos c = Productos();
	c.leer();
	 cout << ("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");

	 getch();
}

void eliminar_producto() {
	int idpro;
	system("cls");
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                   E L I M I N A R                  D A T O S                    |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");


	gotoxy(20, 6); cout << "Ingrese el id del registro que desea eliminar: ";
	cin >> idpro;
	cin.ignore();
	Productos c = Productos();
	c.eliminar(idpro);

	system("pause");

}
void modificar_producto() {

	int idpro;
	gotoxy(45, 0);	cout << ("__________________________________________________________________________________");
	gotoxy(45, 1);	cout << ("|                   M O D I F I C A R                D A T O S                    |");
	gotoxy(45, 2);	cout << ("|_________________________________________________________________________________|");


	gotoxy(20, 6); cout << "Ingrese el id del registro que desea modificar: ";
	cin >> idpro;

	Productos c = Productos();
	c.modificar(idpro);

	system("pause");

}

void control2() {
	int a;
	do {
		system("cls");
		marco2();
		gotoxy(47, 2); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(47, 3); cout << ("°°°                              M A R C A S                          °°°");
		gotoxy(47, 4); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(70, 8); cout << ("1. Registrar Datos");
		gotoxy(70, 9); cout << ("2. Mostrar Datos ");
		gotoxy(70, 10); cout << ("3. Eliminar datos");
		gotoxy(70, 11); cout << ("4. Modificar Datos");
		gotoxy(70, 12); cout << ("5. Salir");
		gotoxy(70, 15); cout << ("Ingresar Opcion: ");
		cin >> a;
		switch (a) {
		case 1: system("cls");
			insertar_marca();
			break;

		case 2: system("cls");
			mostrar_marca();
			break;

		case 3:system("cls");
			eliminar_marca();
			break;

		case 4:system("cls");
			modificar_marca();
			break;


		}
	} while (a != 5);
}

void insertar_marca() {
	string marca;
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                 R E G I S T R A R              D A T O S                        |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");

	cin.ignore();
	gotoxy(30, 8); cout << "Ingrese Marca: ";
	getline(cin, marca);

	Marcas P = Marcas(marca);

	P.Crear();
	system("pause");

}


void mostrar_marca() {
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");
	gotoxy(40, 5); cout << ("---------------------------------------");
	gotoxy(40, 6); cout << "|ID  |"; gotoxy(46,6);cout << "             Marca              |";
	gotoxy(40,7); cout << ("---------------------------------------");

	Marcas P = Marcas();
	P.Leer();
	cout << ("\n\t\t\t\t\t---------------------------------------");

	system("pause");
}

void eliminar_marca() {
	system("cls");
	int idmarca;
	
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                   E L I M I N A R                  D A T O S                    |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");


	gotoxy(20, 6); cout << "Ingrese el id del registro que desea eliminar: ";
	cin >> idmarca;
	
	Marcas dd = Marcas();
	dd.eliminar(idmarca);

	system("pause");

}
void modificar_marca() {

	int id_marca;
	gotoxy(45, 0);	cout << ("__________________________________________________________________________________");
	gotoxy(45, 1);	cout << ("|                   M O D I F I C A R                D A T O S                    |");
	gotoxy(45, 2);	cout << ("|_________________________________________________________________________________|");


	gotoxy(20, 6); cout << "Ingrese el id del registro que desea modificar: ";
	cin >> id_marca;

	Marcas c = Marcas();
	c.modificar(id_marca);

	system("pause");

}

void control3() {
	int a;
	do {
		system("cls");
		marco2();
		gotoxy(47, 2); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(47, 3); cout << ("°°°                       P R O V E E D O R E S                       °°°");
		gotoxy(47, 4); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(70, 8); cout << ("1. Insertar a tabla Proveedores");
		gotoxy(70, 9); cout << ("2. Mostrar Datos de la tabla");
		gotoxy(70, 10); cout << ("3. Eliminar dato");
		gotoxy(70, 11); cout << ("4. Modificar Datos");
		gotoxy(70, 12); cout << ("5. Salir");
		gotoxy(70, 15); cout << ("Ingresar Opcion: ");
		cin >> a;
		switch (a) {
		case 1: system("cls");
			insertar_proveedor();
			break;

		case 2: system("cls");
			mostrar_proveedor();
			break;

		case 3:system("cls");
			eliminar_proveedor();
			break;

		case 4:system("cls");
			modificar_proveedor();
			break;

		}

	} while (a != 5);
}
void insertar_proveedor() {
	string proveedor, nit, direccion, telefono;
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|               R E G I S T R A R             D A T O S                           |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");

	cin.ignore();
	gotoxy(30, 8); cout << "Ingrese Proveedor: ";
	getline(cin, proveedor);
	gotoxy(30, 9); cout << "Ingrese Nit: ";
	getline(cin, nit);
	gotoxy(30, 10); cout << "Ingrese Direccion: ";
	getline(cin, direccion);
	gotoxy(30, 11); cout << "Ingrese No. Telefono: ";
	getline(cin, telefono);

	Proveedor P = Proveedor(proveedor, nit, direccion, telefono);
	P.Crear();
	system("pause");

}

void mostrar_proveedor() {
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");
	gotoxy(40, 5); cout << ("-----------------------------------------------------------------------------------------------");
	gotoxy(40, 6); cout << "| ID |"; gotoxy(53, 6); cout << "Proveedor      |"; gotoxy(79, 6); cout << "Nit      |";
	gotoxy(100, 6); cout << "Direccion         |"; gotoxy(125, 6); cout << "Telefono |";
	gotoxy(40, 7); cout << ("-----------------------------------------------------------------------------------------------");

	Proveedor P = Proveedor();
	P.Leer();
	 cout << ("\n\t\t\t\t\t-----------------------------------------------------------------------------------------------");
	 getch();
}

void eliminar_proveedor() {
	int idpro;
	system("cls");
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                   E L I M I N A R                  D A T O S                    |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");


	gotoxy(20, 6); cout << "Ingrese el id del registro que desea eliminar: ";
	cin >> idpro;

	Proveedor P = Proveedor();
	P.eliminar(idpro);

	system("pause");
}

void modificar_proveedor() {

	int id_pro;
	gotoxy(45, 0);	cout << ("__________________________________________________________________________________");
	gotoxy(45, 1);	cout << ("|                   M O D I F I C A R                D A T O S                    |");
	gotoxy(45, 2);	cout << ("|_________________________________________________________________________________|");


	gotoxy(20, 6); cout << "Ingrese el id del registro que desea modificar: ";
	cin >> id_pro;

	Proveedor P = Proveedor();
	P.modificar(id_pro);

	system("pause");

}

void control4() {
	int a;
	do {
		system("cls");
		marco2();
		gotoxy(47, 2); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(47, 3); cout << ("°°°                            P U E S T O S                          °°°");
		gotoxy(47, 4); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(70, 8); cout << ("1. Registrar Datos");
		gotoxy(70, 9); cout << ("2. Mostrar Datos ");
		gotoxy(70, 10); cout << ("3. Eliminar dato");
		gotoxy(70, 11); cout << ("4. Modificar Datos");
		gotoxy(70, 12); cout << ("5. Salir");
		gotoxy(70, 15); cout << ("Ingresar Opcion: ");
		cin >> a;
		switch (a) {
		case 1: system("cls");
			insertar_puesto();
			break;
		case 2: system("cls");
			mostrar_puesto();
			break;

		case 3:system("cls");
			eliminar_puesto();
			break;

		case 4:system("cls");
			modificar_puesto();
			break;

		}

	} while (a != 5);
}

void insertar_puesto() {
	string puesto;
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|               R E G I S T R A R             D A T O S                           |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");

	cin.ignore();
	gotoxy(30, 8); cout << "Ingrese Puesto: ";
	getline(cin, puesto);

	Puesto P = Puesto(puesto);
	P.Crear();
	system("pause");
}

void mostrar_puesto() {
	gotoxy(45,0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");
	
	gotoxy(40, 5); cout << ("---------------------------------------");
	gotoxy(40, 6); cout << "| ID |";
	gotoxy(60,6);cout <<"Puesto            |";
	gotoxy(40, 7); cout << ("---------------------------------------");

	Puesto P = Puesto();
	P.Leer();
	cout << ("\n\t\t\t\t\t-------------------------------------- - ");


	system("pause");
}

void eliminar_puesto() {
	int idpu;
	system("cls");
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                   E L I M I N A R                  D A T O S                    |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");

	gotoxy(20, 6); cout << "Ingrese el id del registro que desea eliminar: ";
	cin >> idpu;

	Puesto P = Puesto();
	P.eliminar(idpu);

	system("pause");
}
void modificar_puesto() {
	int id_pu;
	gotoxy(45, 0);	cout << ("__________________________________________________________________________________");
	gotoxy(45, 1);	cout << ("|                   M O D I F I C A R                D A T O S                    |");
	gotoxy(45, 2);	cout << ("|_________________________________________________________________________________|");


	gotoxy(20, 6); cout << "Ingrese el id del registro que desea modificar: ";
	cin >> id_pu;

	Puesto P = Puesto();
	P.modificar(id_pu);

	system("pause");

}
void control5() {
	int a;
	do {
		system("cls");
		marco2();
		gotoxy(47, 2); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(47, 3); cout << ("°°°                         E M P L E A D O S                         °°°");
		gotoxy(47, 4); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(70, 8); cout << ("1. Registrar Datos");
		gotoxy(70, 9); cout << ("2. Mostrar Datos ");
		gotoxy(70, 10); cout << ("3. Eliminar dato");
		gotoxy(70, 11); cout << ("4. Modificar Datos");
		gotoxy(70, 12); cout << ("5. Salir");
		gotoxy(70, 15); cout << ("Ingresar Opcion: ");
		cin >> a;
		switch (a) {
		case 1: system("cls");
			insertar_empleado();
			break;

		case 2: system("cls");
			mostrar_empleado();
			break;

		case 3:system("cls");
			eliminar_empleado();
			break;

		case 4:system("cls");
			modificar_empleado();
			break;

		}

	} while (a != 5);
}

void insertar_empleado() {
	string nombres, apellidos, direccion, telefono, dpi, fechaN, fecha_inicio="now()", fecha_ingreso = "now()";
	int  idpuesto, t = 17, a = 0, b = 1; int cd;
	char genero;
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|               R E G I S T R A R             D A T O S                           |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");
	cin.ignore();
	gotoxy(20, 8); cout << "Ingrese Nombres: ";
	getline(cin, nombres);

	gotoxy(20, 9); cout << "Ingrese Apellidos: ";
	getline(cin, apellidos);

	gotoxy(20, 10); cout << "Ingrese Direccion: ";
	getline(cin, direccion);

	gotoxy(20, 11); cout << "Ingrese Telefono: ";
	getline(cin, telefono);

	gotoxy(20, 12); cout << "Ingrese No DPI: ";
	getline(cin, dpi);
	Empleado tan = Empleado();
	tan.validar_DPI(dpi);
	while (tan.validar_DPI(dpi) == 1) {
		gotoxy(36, 12);  cout << "                                 ";
		gotoxy(36, 12);  getline(cin, dpi);
		tan.validar_DPI(dpi);
	}

	gotoxy(20, 15); cout << "Ingrese Genero[F,M]: ";
	cin >> genero;

	if (genero == 'M' || genero == 'm') {
		cd = 1;
	}
	else if (genero == 'F' || genero == 'f') {
		cd = 0;
	}

	cin.ignore();
	gotoxy(20, 16); cout << "Ingrese Fecha Nacimiento: ";
	cin >> fechaN;

	gotoxy(20, 17); cout << "Ingrese Id puesto: ";
	Empleado Pu = Empleado();
	Pu.Leer_puesto();

	gotoxy(39, 17); cin >> idpuesto;
	Pu.validar(idpuesto);
	while (Pu.validar(idpuesto) == 1) {
		gotoxy(20, t); cout << "Id puesto invalido, ingrese un id existente: ";
		t++;
		cin >> idpuesto;
		Pu.validar(idpuesto);
	}

	Empleado P = Empleado(nombres, apellidos, direccion, telefono, dpi, cd, fechaN, idpuesto, fecha_inicio, fecha_ingreso);
	P.Crear();
	system("pause");
}

void mostrar_empleado() {
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");
	

	gotoxy(0, 5); cout << ("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	gotoxy(0, 6); cout << "|ID |"; gotoxy(5, 6); cout << "     Nombres       |"; gotoxy(25, 6); cout << "     Apellidos     |"; gotoxy(47, 6); cout << "      Direccion       |";
	gotoxy(70, 6); cout << " Telefono  |"; gotoxy(82, 6); cout << "     DPI       |"; gotoxy(99, 6); cout << "  Genero  |"; gotoxy(110, 6); cout << "   Puesto    |";
	gotoxy(124,6);cout << "Fecha Nac. |" << "Fecha Labor|" << "   Fecha ingreso   |";
	gotoxy(0, 7); cout << ("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");

	Empleado P = Empleado();
	P.Leer();

	cout << ("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------");

	cout << ("\n\n");
	system("pause");
}


void eliminar_empleado() {
	int idemp;

	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                   E L I M I N A R                  D A T O S                    |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");

	gotoxy(20, 6); cout << "Ingrese el id del registro que desea eliminar: ";
	cin >> idemp;

	Empleado P = Empleado();
	P.eliminar(idemp);

	system("pause");
}
void modificar_empleado() {
	int id_emp;
	gotoxy(45, 0);	cout << ("__________________________________________________________________________________");
	gotoxy(45, 1);	cout << ("|                   M O D I F I C A R                D A T O S                    |");
	gotoxy(45, 2);	cout << ("|_________________________________________________________________________________|");


	gotoxy(20, 6); cout << "Ingrese el id del registro que desea modificar: ";
	cin >> id_emp;

	Empleado P = Empleado();
	P.modificar(id_emp);

	system("pause");
}

void control6() {
	int a;
	do {
		system("cls");
		marco2();
		gotoxy(47, 2); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(47, 3); cout << ("°°°                            C L I E N T E S                        °°°");
		gotoxy(47, 4); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(70, 8); cout << ("1. Registrar Datos");
		gotoxy(70, 9); cout << ("2. Mostrar Datos  ");
		gotoxy(70, 10); cout << ("3. Eliminar dato");
		gotoxy(70, 11); cout << ("4. Modificar Datos");
		gotoxy(70, 12); cout << ("5. Salir");
		gotoxy(70, 15); cout << ("Ingresar Opcion: ");
		cin >> a;
		switch (a) {
		case 1: system("cls");
			insertar_cliente();
			break;

		case 2: system("cls");
			mostrar_cliente();
			break;

		case 3:system("cls");
			eliminar_cliente();
			break;

		case 4:system("cls");
			modificar_cliente();
			break;

		}

	} while (a != 5);
}

void insertar_cliente() {
	string nombres, apellidos, nit, telefono, correo_electronico, fecha_ingreso = "now()";
	char genero;
	int cd;
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                 R E G I S T R A R             D A T O S                         |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");

	cin.ignore();
	gotoxy(40, 8); cout << "Ingrese Nombres: ";
	getline(cin, nombres);
	gotoxy(40, 9); cout << "Ingrese Apellidos: ";
	getline(cin, apellidos);
	gotoxy(40, 10); cout << "Ingrese Nit: ";
	getline(cin, nit);
	Cliente Pu = Cliente();
	Pu.validar_nit(nit);
	while (Pu.validar_nit(nit) == 1) {
		gotoxy(53, 10);  cout << "                                 ";
		gotoxy(53, 10);  getline(cin, nit);
		Pu.validar_nit(nit);
	}
	gotoxy(40, 12); cout << "Ingrese genero[M, F]: ";
	cin >> genero;

	if (genero == 'M' || genero == 'm') {
		cd = 1;
	}
	else if (genero == 'F' || genero == 'f') {
		cd = 0;
	}
	cin.ignore();
	gotoxy(40, 13); cout << "Ingrese telefono: ";
	getline(cin, telefono);
	gotoxy(40, 14); cout << "Ingrese Correo electronico: ";
	getline(cin, correo_electronico);

	Cliente P = Cliente(nombres, apellidos, nit, cd, telefono, correo_electronico, fecha_ingreso);

	P.Crear();
	system("pause");
}

void mostrar_cliente() {
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");

	gotoxy(0, 5); cout << ("-----------------------------------------------------------------------------------------------------------------------------------------------------------------");
	gotoxy(0, 6); cout << "ID  |"; gotoxy(6, 6); cout << "        Nombres       |"; gotoxy(32, 6); cout << "     Apellidos      |";
	gotoxy(53, 6); cout << "     NIT       |"; gotoxy(70, 6); cout<< "    Genero       |"; gotoxy(89, 6); cout << "     Telefono    |"; 
	gotoxy(108, 6); cout << "    Correo electronico    |"; gotoxy(140, 6); cout << "   Fecha Ingreso    |";
	gotoxy(0, 7); cout << ("-----------------------------------------------------------------------------------------------------------------------------------------------------------------");
	Cliente P = Cliente();
	P.Leer();
	cout << ("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------");

	getch();
}


void eliminar_cliente() {
	int idcliente;
	system("cls");
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                   E L I M I N A R                  D A T O S                    |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");

	gotoxy(20, 6); cout << "Ingrese el id del registro que desea eliminar: ";
	cin >> idcliente;

	Cliente P = Cliente();
	P.Eliminar(idcliente);

	system("pause");
}

void modificar_cliente() {
	int idcliente;
	gotoxy(45, 0);	cout << ("__________________________________________________________________________________");
	gotoxy(45, 1);	cout << ("|                   M O D I F I C A R                D A T O S                    |");
	gotoxy(45, 2);	cout << ("|_________________________________________________________________________________|");


	gotoxy(20, 6); cout << "Ingrese el id del registro que desea modificar: ";
	cin >> idcliente;

	Cliente P = Cliente();
	P.modificar(idcliente);
	system("pause");
}

void control7() {
	int a;
	do {
		system("cls");
		marco2();
		gotoxy(47, 2); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(47, 3); cout << ("°°°                              C O M P R A S                        °°°");
		gotoxy(47, 4); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(70, 8); cout << ("1. Registrar Datos");
		gotoxy(70, 9); cout << ("2. Mostrar Datos ");
		gotoxy(70, 10); cout << ("3. Eliminar dato");
		gotoxy(70, 11); cout << ("4. Modificar Datos");
		gotoxy(70, 12); cout << ("5. Salir");
		gotoxy(70, 15); cout << ("Ingresar Opcion: ");
		cin >> a;
		switch (a) {
		case 1: system("cls");
			insertar_Maestro_detalle_compras();
			break;
		case 2: system("cls");
			mostrar_Maestro_detalle_compras();
			break;

		case 3:system("cls");
			mostrar_Maestro_detalle_compras();
			eliminar_Maestro_detalle_compras();
			break;
		case 4:system("cls");
			mostrar_Maestro_detalle_compras();
			modificar_Maestro_detalle_compras();
			break;


		}

	} while (a != 5);
}
void insertar_Maestro_detalle_compras() {
	int idproveedor, idcompra,cero, idproducto, Cantidad, r=20, u=24;
	string  fechaorden="now()", fechaIn = "now()";
	
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                 R E G I S T R A R             C O M P R A S                     |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");
	
	char op;
	Maestro_detalle_compras za = Maestro_detalle_compras();
	za.Leer_prov();
	Maestro_detalle_compras2 ze = Maestro_detalle_compras2();
	ze.producto_Leer();

	cout << ("\n\n\n");

	cout << ("\n\t\t\t\t\t\t\tIngrese Id proveedor: ");
	cin >> idproveedor;

	while (za.validar(idproveedor) == 1)
	{
		cout << ("\n\t\t\t\t\t\t\tId proveedor no encontrado");
		cout<< ("\n\t\t\t\t\t\t\tIngrese un id existente: ");
		cin >> idproveedor;
		za.validar(idproveedor);

	}
	Maestro_detalle_compras z = Maestro_detalle_compras(idproveedor, fechaorden, fechaIn);
	z.Crear2(idproveedor);

	//Comienza el detalle
	do
	{
	cout << ("\n\n");
	cout << ("\t\t\t\t\t\t\tIngrese Id Producto: ");

	cin >> idproducto;
	while (ze.validar(idproducto) == 1)
	{
		 cout << ("\n\t\t\t\t\t\t\tId producto no encontrado");
		cout<<("\n\t\t\t\t\t\t\tIngrese un id existente: ");
		cin >> idproducto;
		ze.validar(idproducto);
	}
	Maestro_detalle_compras2 sa = Maestro_detalle_compras2();
	sa.Leer5(idproducto);


	cout << ("\n\t\t\t\t\t\t\tIngrese Cantidad: ");
	cin >> Cantidad;

	Maestro_detalle_compras2 f = Maestro_detalle_compras2( idproducto, Cantidad);
	f.entrada();
	
	cout << ("\n\t\t\t\t\t\t\tdesea agregar otro producto: ");
	cin >> op;

	} while ((op == 's') || (op == 'S'));


}


void mostrar_Maestro_detalle_compras() {
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");
	gotoxy(0, 5); cout << ("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");

	gotoxy(0, 6); cout << "| ID |"; gotoxy(6, 6); cout << " No. Orden|"; gotoxy(20, 6); cout << "    Producto   |"; gotoxy(40, 6); cout << "       Descripcion         |";
	gotoxy(68, 6); cout << "Cantidad|"; gotoxy(78, 6); cout << "Pcosto|"; gotoxy(85, 6); cout << "idCompra|"; gotoxy(97, 6); cout << "Marca   |"; gotoxy(108, 6); cout << "   Proveedores    |";
	gotoxy(128, 6); cout << "Fecha orden |"; gotoxy(142, 6);cout << "     Fecha Ingreso      |";
	gotoxy(0, 7); cout << ("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");

	Maestro_detalle_compras2 rr = Maestro_detalle_compras2();
	rr.Leer_compras();
	 cout << ("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");

	_getch();
}

void modificar_Maestro_detalle_compras() {
	int idcomp,detalle, producto, cantidad, idProv;
	string fechaO = "now()", fechaIn = "now()"; char respuesta;
	mostrar_Maestro_detalle_compras();
	cout << ("\n\n\n\t\t__________________________________________________________________________________");
	cout << ("\n\t\t|                   M O D I F I C A R                D A T O S                    |");
	cout << ("\n\t\t|_________________________________________________________________________________|");
	Maestro_detalle_compras pa = Maestro_detalle_compras();
	Maestro_detalle_compras pe = Maestro_detalle_compras();
	Maestro_detalle_compras2 ze = Maestro_detalle_compras2();
	Maestro_detalle_compras za = Maestro_detalle_compras();

	cout << "\n\t\t\t\t\t\t Ingrese el id de compra: ";
	cin >> idcomp;
	while (pa.validaridcom(idcomp) == 1)
	{
		 cout << ("\n\t\t\t\t\t\t\tId compra no encontrado");
		cout<<("\n\t\t\t\t\t\t\tIngrese un id existente: ");
		cin >> idcomp;
		pa.validaridcom(idcomp);
	}

	cout << "\n\t\t\t\t\t\t Ingrese el id del detalle: ";
	cin >> detalle;
	while (pe.validaridetalle(detalle) == 1)
	{
		cout << ("\n\t\t\t\t\t\t\tId detalle no encontrado");
		cout << ("\n\t\t\t\t\t\t\tIngrese un id existente: ");
		cin >> detalle;
		pe.validaridetalle(detalle);
	}

	cout << "\n\t\t\t\t\t\t Ingrese el id del producto: ";
	cin >> producto;
	while (ze.validar(producto) == 1)
	{
		cout << ("\n\t\t\t\t\t\t\tId producto no encontrado");
		cout << ("\n\t\t\t\t\t\t\tIngrese un id existente: ");
		cin >> producto;
		ze.validar(producto);
	}

	cout << "\n\t\t\t\t\t\t Ingrese el id del proveeedor: ";
	cin >> idProv;
	while (za.validar(idProv) == 1)
	{
		cout << ("\n\t\t\t\t\t\t\tId proveedor no encontrado");
		cout << ("\n\t\t\t\t\t\t\tIngrese un id existente: ");
		cin >> idProv;
		za.validar(idProv);

	}



	cout << "\n\t\t\t\t\t\t Ingrese cantidad: ";
	cin >> cantidad;

	cout << ("\n\t\t\t\t\t\t Desea Modifcar [s/n]:");
	cin >> respuesta;
	if((respuesta=='s')|| (respuesta=='S')){
	Maestro_detalle_compras kk = Maestro_detalle_compras(idProv, fechaO,fechaIn);
	kk.modificar(idcomp);

	Maestro_detalle_compras2 ff = Maestro_detalle_compras2(producto,cantidad);

	ff.modificar(detalle);
	cout << ("\t\t\t\t\t\t Registro  Modificado Exitosamente :)");
	}
	else {
		cout << ("\t\t\t\t\t\t Registro No Modificado :)");
	}

	getch();

}

void eliminar_Maestro_detalle_compras() {
	int ID;
	mostrar_Maestro_detalle_compras();
	cout << ("\n\n\n\t\t__________________________________________________________________________________");
	cout << ("\n\t\t|                   E L I M I N A R                  D A T O S                    |");
	cout << ("\n\t\t|_________________________________________________________________________________|");

	cout << "\n\n\tIngrese el id del registro que desea eliminar: ";
	
	cin >> ID;
	Maestro_detalle_compras MP = Maestro_detalle_compras();
	MP.Eliminar(ID);
	getch();
}
void control8() {
	int a;
	do {
		system("cls");
		marco2();
		gotoxy(47, 2); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(47, 3); cout << ("°°°                            V E N T A S                            °°°");
		gotoxy(47, 4); cout << ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(70, 8); cout << ("1. Registrar Datos");
		gotoxy(70, 9); cout << ("2. Mostrar Datos ");
		gotoxy(70, 10); cout << ("3. Eliminar dato");
		gotoxy(70, 11); cout << ("4. Modificar Datos");
		gotoxy(70, 12); cout << ("5. Salir");
		gotoxy(70, 15); cout << ("Ingresar Opcion: ");
		cin >> a;
		switch (a) {
		case 1: system("cls");
			insertar_Maestro_detalle_ventas();
			break;

		case 2: system("cls");
			mostrar_Maestro_detalle_ventas();	
			break;

		case 3:system("cls");
			mostrar_Maestro_detalle_ventas();
			eliminar_Maestro_detalle_ventas();

			break;

		case 4:system("cls");
			mostrar_Maestro_detalle_ventas();
			modificar_Maestro_detalle_ventas();
			break;

		}

	} while (a != 5);
}

void insertar_Maestro_detalle_ventas() {
	int No_factura, idcliente = 0, idempleado, idventa, idproducto, cantidad, t = 18, opcion = 0, cd = 0;
	float preciounitario, total;
	char repetir, obteneridventa, genero;
	string nombres, apellidos, telefono, correo, fechaingreso = "now()";
	string nit;
	string  serie = "A", fechafactura = "now()", fechaIn = "now()";
	Maestro_ventas Mv = Maestro_ventas();
	Maestro_detalle_ventas2 Mdv = Maestro_detalle_ventas2();
	Cliente c = Cliente();
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                 R E G I S T R A R            V E N T A S                        |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");
	cout << ("\n\n");
	Mv.Leer_empleado();
	
	Mv.Leer_productos();
	Mv.Leer_cliente();
	automatico();
	
	cout << ("\n\n");
	cout << ("\n\nIngrese nit de cliente: ");
	cin >> nit;
	Mv.validarnit(nit);
	while (Mv.validarnit(nit) == 1) {
		Mv.validar_nit(nit);
		cout << ("Nit no existente 1")<<endl;
		cout << ("1.volver a ingresar nit.")<<endl;
		cout<<( "2.Registrar este nit : ")<<endl;

		cin >> opcion;	cin.ignore();
		if (opcion == 1)
		{
			cout << "\nVuelva a ingresar el Nit: ";
			cin >> nit;
		}
		else
		{
			cout << "\n\ningrese nombres: ";	getline(cin, nombres);
			cout << "ingrese apellidos: ";	getline(cin, apellidos);
			cout << "ingrese el genero[F,M]:"; cin >> genero;
			if (genero == 'M' || genero == 'm') {
				cd = 1;
			}
			else if (genero == 'F' || genero == 'f') {
				cd = 0;
			}
			cin.ignore();
			cout << "ingrese telefono: ";	getline(cin, telefono);
			cout << "ingrese correo electronico: ";	getline(cin, correo);
			c = Cliente(nombres, apellidos, nit, cd, telefono, correo, fechaingreso);
			c.Crear();
		}

		Mv.validarnit(nit);
	}
	idcliente = Mv.retornaridcliente(nit);
	Mv.mostrarcliente(idcliente);
	cout << ("\n\nIngrese Id empleado: ");
	cin >> idempleado;
	Mv.validaridempleado(idempleado);
	while (Mv.validaridempleado(idempleado) == 1) {
		cout << "idempleado invalido, ingrese un id existente: ";
		cin >> idempleado;
		Mv.validaridempleado(idempleado);
	}
	Mv.mostrarempleado(idempleado);

	//Comienza el detalle
	cout << ("\n\nIngrese Id Producto: ");
	cin >> idproducto;
	Mv.validaridproducto(idproducto);
	while (Mv.validaridproducto(idproducto) == 1) {
		cout << "idproducto invalido, ingrese un id existente: ";
		cin >> idproducto;
		Mv.validaridproducto(idproducto);
	}
	Mv.mostrarproducto(idproducto);
	cout << ("\n\nIngrese Cantidad: ");
	cin >> cantidad;

	preciounitario = Mv.retornarprecio_venta(idproducto);
	Mv = Maestro_ventas(serie, fechafactura, idcliente, idempleado);
	Mv.insert_ventas();
	Mdv = Maestro_detalle_ventas2(idproducto, cantidad, preciounitario);
	Mdv.insert();
	cout << "Desea ingresar otro registro (s/n): ";	cin >> repetir;
	while ((repetir == 's') || (repetir == 'S'))
	{
		cout << ("\n\nIngrese Id Producto: ");
		cin >> idproducto;
		Mv.validaridproducto(idproducto);
		while (Mv.validaridproducto(idproducto) == 1) {
			cout << "idproducto invalido, ingrese un id existente: ";
			cin >> idproducto;
			Mv.validaridproducto(idproducto);
		}
		Mv.mostrarproducto(idproducto);
		cout << ("\n\nIngrese Cantidad: ");
		cin >> cantidad;
		preciounitario = Mv.retornarprecio_venta(idproducto);
		Mdv = Maestro_detalle_ventas2(idproducto, cantidad, preciounitario);
		Mdv.insert();

		cout << "Desea ingresar otro registro (s/n): ";	cin >> repetir;
	}
	system("cls");
	marco_factura();
	Maestro_detalle_ventas2 okla = Maestro_detalle_ventas2();
	okla.Crear_factura();
	_getch();
	Mandarlo();
	system("pause");
}





void mostrar_Maestro_detalle_ventas() {
	gotoxy(45, 0); cout << ("__________________________________________________________________________________");
	gotoxy(45, 1); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(45, 2); cout << ("|_________________________________________________________________________________|");
	cout << ("\n\n\n");
	cout << ("------------------------------------------------------------------------------------------------------------------------------------------------------------------------") << endl;
	cout << "idV|" << "Serie|" << "Factura|" << "Fecha Factura|" << "idProd|" << "Producto|" << "Cant|" << "P.unidad|" << "idCliente|" << "Cliente|" << "Nit|" << "IdEmp |" << "Nombres |" << "             Fingreso     |"<<endl;
	cout << ("------------------------------------------------------------------------------------------------------------------------------------------------------------------------") << endl;

	Maestro_ventas Mv = Maestro_ventas();
	Mv.leer_ventas();
	_getch();
}


void modificar_Maestro_detalle_ventas() {
	int idven;
	cout << ("\n\n\n\t\t__________________________________________________________________________________");
	cout << ("\n\t\t|                   M O D I F I C A R                D A T O S                    |");
	cout << ("\n\t\t|_________________________________________________________________________________|");

	cout << "\n\n\tIngrese el id del registro que desea modificar: ";
	cin >> idven;

	Maestro_ventas Mv = Maestro_ventas();
	Mv.modificar(idven);

	getch();

}

void eliminar_Maestro_detalle_ventas() {
	int ID;
	cout << ("\n\n\n\t\t__________________________________________________________________________________");
	cout << ("\n\t\t|                   E L I M I N A R                  D A T O S                    |");
	cout << ("\n\t\t|_________________________________________________________________________________|");

	cout << "\n\n\tIngrese el id del registro que desea eliminar: ";
	cin >> ID;
	Maestro_ventas Mv = Maestro_ventas();
	Mv.Eliminar(ID);
	getch();
}
void marco_factura() {
	gotoxy(43, 1); cout << ("--------------------------------------------------------------------------------------------");
	gotoxy(43, 12); cout << ("--------------------------------------------------------------------------------------------");
	gotoxy(43,6); cout << ("--------------------------------------------------------------------------------------------");
	gotoxy(79, 3); cout << ("Empresa Onitech, S.A.");
	gotoxy(68, 4); cout << ("4ta. Calle Poniente, Antigua Guatemala");
	gotoxy(80, 5); cout << ("Tel. 89128871");

	for (int i = 2; i <= 22; i++) {
		gotoxy(43, i); cout << ("|");

}
	for (int i = 2; i <= 32; i++) {
		gotoxy(134, i); cout << ("|");

	}
}
void co(int x, int c) {
	cambiarcolor(c);
	int i;
	for (i = 1; i <= x; i++) {
		cout << char(219) << char(219);
	}
}


void cambiarcolor(int X) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), X);
}
void fondo() {
	system("COLOR f3");
}

void bla(int u) {
	int q;
	for (q = 1; q <= u; q++) {
		cout << char(255) << char(255);
	}
}

void cargando() {
	int o = 255, x = 219;
	int i, u;
	cout << ("\n");
	gotoxy(83, 39); cout << ("Eliminado prro :v");

	for (u = 1; u <= 55; u++) {
		gotoxy(u, 40);
	}

	for (i = 1; i <= 30; i++) {
		co(0, 244);
		cout << char(x);
		Beep(493, 100);
		Sleep(60);
		cout << char(o);
	}
}

void Outtextxy(HDC hdc, int x, int y, tstring Msg)
{
	TextOut(hdc, x, y, Msg.c_str(), static_cast<int>(Msg.length()));
}
void ShowError(tstring strMsg)
{
	MessageBox(NULL, strMsg.c_str(), TEXT("Imprimir"), MB_ICONERROR);
	exit(1);
}
void ShowInformation(tstring strText)
{
	MessageBox(NULL, strText.c_str(), TEXT("Imprimir"), MB_ICONINFORMATION);
}


	
	void PrintFile(tifstream & f)
	{
		PRINTDLG pd;
		DOCINFO di;
		tstring strLine;
		int y = 100;

		memset(&pd, 0, sizeof(PRINTDLG));
		memset(&di, 0, sizeof(DOCINFO));

		di.cbSize = sizeof(DOCINFO);
		di.lpszDocName = TEXT("Imprimiendo");

		pd.lStructSize = sizeof(PRINTDLG);
		pd.Flags = PD_PAGENUMS | PD_RETURNDC;
		pd.nFromPage = 1;
		pd.nToPage = 1;
		pd.nMinPage = 1;
		pd.nMaxPage = 0xFFFF;


		if (f.fail()) {
			ShowError(TEXT("\n\n\t\t\t\t\t\t\t\tError en el archivo!!"));
		}

		if (PrintDlg(&pd)) {
			if (pd.hDC) {
				if (StartDoc(pd.hDC, &di) != SP_ERROR) {
					cout << "\n\n\t\t\t\t\t\t\t\tImprimiendo...";
					StartPage(pd.hDC);
					while (!f.eof()) {
						getline(f, strLine);
						Outtextxy(pd.hDC, 0, y, strLine.c_str());
						y += 100;
					}
					EndPage(pd.hDC);
					EndDoc(pd.hDC);

				}
				else {
					ShowError(TEXT("\n\n\t\t\t\t\t\t\t\tError al imprimir"));
				}
			}
			ShowInformation(TEXT("Impresion Exitosa"));
		}
	}


void Mandarlo()
	{
	txt();
		tifstream in(TEXT("factura2.txt"));
		PrintFile(in);
		in.close();
	
}
void marco2() {

	int  m = 243;

	for (int i = 1; i <= 49; i++) {
		gotoxy(124, i); co(1, m);
	}
	for (int i = 1; i <= 49; i++) {
		gotoxy(43, i); co(1, m);
	}
	for (int i = 43; i <= 124; i++) {
		gotoxy(i, 0); co(1, m);
	}
	for (int i = 43; i <= 124; i++) {
		gotoxy(i, 49); co(1, m);
	}
}

void marco() {

	int z = 247, m = 243, k = 247;

	for (int i = 1; i <= 49; i++) {
		gotoxy(124, i); co(1, m);
	}
	for (int i = 1; i <= 49; i++) {
		gotoxy(43, i); co(1, m);
	}
	for (int i = 43; i <= 124; i++) {
		gotoxy(i, 0); co(1, m);
	}
	for (int i = 43; i <= 124; i++) {
		gotoxy(i, 49); co(1, m);
	}

	for (int u = 0; u <= 49; u += 1) {
		gotoxy(132, u); co(8, k); bla(2); co(8, k);;
	}
	for (int r = 1; r <= 49; r += 6) {
		gotoxy(132, r); co(18, m);
	}

	for (int x = 0; x <= 49; x++) {
		gotoxy(0, x); co(8, k); bla(2); co(8, k);
	}
	for (int i = 1; i <= 49; i += 6) {
		gotoxy(0, i); co(18, m);
	}
}

void encender() {
	
		string data = "a";


		char* charArray = new char[data.size() + 1];
		copy(data.begin(), data.end(), charArray);
		charArray[data.size()] = '\n';

		arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
		arduino.readSerialPort(output, MAX_DATA_LENGTH);

		cout << ">> " << output << endl;

		delete[] charArray;
		system("pause");
	
}

void apagar() {
	string data = "e";


	char* charArray = new char[data.size() + 1];
	copy(data.begin(), data.end(), charArray);
	charArray[data.size()] = '\n';

	arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
	arduino.readSerialPort(output, MAX_DATA_LENGTH);

	cout << ">> " << output << endl;

	delete[] charArray;
	system("pause");
}

void automatico() {
	string data = "z";


	char* charArray = new char[data.size() + 1];
	copy(data.begin(), data.end(), charArray);
	charArray[data.size()] = '\n';

	arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
	arduino.readSerialPort(output, MAX_DATA_LENGTH);

	cout << ">> " << output << endl;

	delete[] charArray;
}
