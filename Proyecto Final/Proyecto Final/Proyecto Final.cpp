#include <mysql.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "Productos.h"
#include "Marcas.h"
#include "Proveedor.h"
#include "Puesto.h"
#include "Empleado.h"
#include"Cliente.h"
#include "Maestro_detalle_compras.h"
#include <conio.h>

using namespace  std;
void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void control7();
void control6();
void control5();
void control4();
void control3();
void control2();
void control1();
void control();

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
/*
void mostrar_Maestro_detalle_compras();
void eliminar_Maestro_detalle_compras();
void modificar_Maestro_detalle_compras();
*/

int main() {
	control1();
}


void control1() {
	int a;
	do {
		system("cls");
		gotoxy(35, 3); cout << ("----------      M E N U     D E    O P C I O N E S      ---------");
		gotoxy(50, 8); cout << ("1. T A B L A   P R O D U C T O S");
		gotoxy(50, 9); cout << ("2. T A B L A   M A R C A S ");
		gotoxy(50, 10); cout << ("3. T A B L A   P R O V E E D O R E S ");
		gotoxy(50, 11); cout << ("4. T A B L A   P U E S T O S ");
		gotoxy(50, 12); cout << ("5. T A B L A   E M P L E A D O S ");
		gotoxy(50, 13); cout << ("6. T A B L A   C L I E N T E S ");
		gotoxy(50, 14); cout << ("7. T A B L A  M  A E S T R O    D E T A L L E  ");
		gotoxy(50, 15); cout << ("8. S A L I R ");
		gotoxy(50, 20); cout << ("Ingresar Opcion: ");
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

		}

	} while (a != 8);
}

void control() {
	int a;
	do {
		system("cls");
		gotoxy(35, 3); cout << ("----------      M E N U     D E    O P C I O N E S      ---------");
		gotoxy(50, 8); cout << ("1. Insertar a tabla Productos");
		gotoxy(50, 9); cout << ("2. Mostrar Datos de la tabla");
		gotoxy(50, 10); cout << ("3. Eliminar dato");
		gotoxy(50, 11); cout << ("4. Modificar Datos");
		gotoxy(50, 12); cout << ("5. Salir");
		gotoxy(50, 15); cout << ("Ingresar Opcion: ");
		cin >> a;
		switch (a) {
		case 1: system("cls");
			insertar_producto();
			break;
			
		case 2: system("cls");
			mostrar_producto();
			break;
			
		case 3:system("cls");
			eliminar_producto();
			break;
	
		case 4:system("cls");
			modificar_producto();
			break;
	
		}
		
	} while (a != 5);
}


void insertar_producto()
{
	string pro, desc, ima, Fecha_Ingreso="now()";
	int idmar,exis;
	float pcosto, pventa;
	gotoxy(30, 2); cout << ("__________________________________________________________________________________");
	gotoxy(30, 3); cout << ("|                 I N S E R T A R             D A T O S                           |");
	gotoxy(30, 4); cout << ("|_________________________________________________________________________________|");

	cin.ignore();
	gotoxy(40, 8); cout << "Ingrese Producto: ";
	getline(cin, pro);
	gotoxy(40, 9); cout << "Ingrese Id Marca: ";
    cin>>idmar;
	cin.ignore();
	gotoxy(40, 10); cout << "Ingrese Descripcion: ";
	getline(cin, desc);
	gotoxy(40, 11); cout << "Ingrese Imagen: ";
	getline(cin, ima);
	gotoxy(40, 12); cout << "Ingrese Precio Costo: ";
	cin >> pcosto;
	gotoxy(40, 13); cout << "Ingrese Precio Venta: ";
	cin >> pventa;
	gotoxy(40, 14); cout << "Ingrese Existencia: ";
	cin >> exis;

	Productos P = Productos (pro, idmar, desc, ima, pcosto, pventa,exis,Fecha_Ingreso);

	P.crear();

	system("pause");

}
void mostrar_producto() {
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");
	gotoxy(0, 6); cout << "ID |" << "Producto |" << "Descripcion |" << " Imagen  |" << "Precio costo |" << "Precio Venta |" << "Existencia |    " << "Fecha Ingreso       |" << "Id marca";
	cout << ("\n\n\n");

	Productos c = Productos();
	c.leer();
	system("pause");
}

void eliminar_producto() {
	int idpro;
	system("cls");
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                   E L I M I N A R                  D A T O S                    |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");


	gotoxy(20, 6); cout << "Ingrese el id del registro que desea eliminar: ";
	cin >> idpro;
	cin.ignore();
	Productos c = Productos();
	c.eliminar(idpro);

	system("pause");

}
void modificar_producto() {

	int idpro;
	gotoxy(20, 2);	cout << ("__________________________________________________________________________________");
	gotoxy(20, 3);	cout << ("|                   M O D I F I C A R                D A T O S                    |");
	gotoxy(20, 4);	cout << ("|_________________________________________________________________________________|");


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
		gotoxy(35, 3); cout << ("----------      M E N U     D E    O P C I O N E S      ---------");
		gotoxy(50, 8); cout << ("1. Insertar a tabla marcas");
		gotoxy(50, 9); cout << ("2. Mostrar Datos de la tabla");
		gotoxy(50, 10); cout << ("3. Eliminar datos");
		gotoxy(50, 11); cout << ("4. Modificar Datos");
		gotoxy(50, 12); cout << ("5. Salir");
		gotoxy(50, 15); cout << ("Ingresar Opcion: ");
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
	gotoxy(30, 2); cout << ("__________________________________________________________________________________");
	gotoxy(30, 3); cout << ("|                 I N S E R T A R             D A T O S                           |");
	gotoxy(30, 4); cout << ("|_________________________________________________________________________________|");

	cin.ignore();
	gotoxy(30, 8); cout << "Ingrese Marca: ";
	getline(cin, marca);

	Marcas P = Marcas(marca);

	P.Crear();
	system("pause");

}


void mostrar_marca() {
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");
	gotoxy(0, 6); cout << "ID |" << "Marca |";
	cout << ("\n\n");
	Marcas P = Marcas();
	P.Leer();
	system("pause");
}

void eliminar_marca() {
	int idmarca;
	system("cls");
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                   E L I M I N A R                  D A T O S                    |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");


	gotoxy(20, 6); cout << "Ingrese el id del registro que desea eliminar: ";
	cin >> idmarca;
	cin.ignore();
	Marcas P = Marcas();
	P.eliminar(idmarca);

	system("pause");

}
void modificar_marca() {

	int id_marca;
	gotoxy(20, 2);	cout << ("__________________________________________________________________________________");
	gotoxy(20, 3);	cout << ("|                   M O D I F I C A R                D A T O S                    |");
	gotoxy(20, 4);	cout << ("|_________________________________________________________________________________|");


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
		gotoxy(35, 3); cout << ("----------      M E N U     D E    O P C I O N E S      ---------");
		gotoxy(50, 8); cout << ("1. Insertar a tabla Proveedores");
		gotoxy(50, 9); cout << ("2. Mostrar Datos de la tabla");
		gotoxy(50, 10); cout << ("3. Eliminar dato");
		gotoxy(50, 11); cout << ("4. Modificar Datos");
		gotoxy(50, 12); cout << ("5. Salir");
		gotoxy(50, 15); cout << ("Ingresar Opcion: ");
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
	gotoxy(30, 2); cout << ("__________________________________________________________________________________");
	gotoxy(30, 3); cout << ("|                 I N S E R T A R             D A T O S                           |");
	gotoxy(30, 4); cout << ("|_________________________________________________________________________________|");

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
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");
	gotoxy(0, 6); cout << "ID |" << "Proveedor    |" << "Nit  |      " << "Direccion    |" << "Telefono |";
	cout << ("\n\n");
	Proveedor P = Proveedor();
	P.Leer();
	system("pause");
}

void eliminar_proveedor() {
	int idpro;
	system("cls");
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                   E L I M I N A R                  D A T O S                    |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");


	gotoxy(20, 6); cout << "Ingrese el id del registro que desea eliminar: ";
	cin >> idpro;
	
	Proveedor P = Proveedor();
	P.eliminar(idpro);

	system("pause");

}

void modificar_proveedor() {

	int id_pro;
	gotoxy(20, 2);	cout << ("__________________________________________________________________________________");
	gotoxy(20, 3);	cout << ("|                   M O D I F I C A R                D A T O S                    |");
	gotoxy(20, 4);	cout << ("|_________________________________________________________________________________|");


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
		gotoxy(35, 3); cout << ("----------      M E N U     D E    O P C I O N E S      ---------");
		gotoxy(50, 8); cout << ("1. Insertar a tabla Puesto");
		gotoxy(50, 9); cout << ("2. Mostrar Datos de la tabla");
		gotoxy(50, 10); cout << ("3. Eliminar dato");
		gotoxy(50, 11); cout << ("4. Modificar Datos");
		gotoxy(50, 12); cout << ("5. Salir");
		gotoxy(50, 15); cout << ("Ingresar Opcion: ");
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
	gotoxy(30, 2); cout << ("__________________________________________________________________________________");
	gotoxy(30, 3); cout << ("|                 I N S E R T A R             D A T O S                           |");
	gotoxy(30, 4); cout << ("|_________________________________________________________________________________|");

	cin.ignore();
	gotoxy(30, 8); cout << "Ingrese Puesto: ";
	getline(cin, puesto);
	
	Puesto P = Puesto(puesto);
	P.Crear();
	system("pause");
}

void mostrar_puesto() {
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");
	gotoxy(0, 6); cout << "ID |" << "  Puesto";
	cout << ("\n\n");
	Puesto P = Puesto();
	P.Leer();
	system("pause");
}

void eliminar_puesto() {
	int idpu;
	system("cls");
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                   E L I M I N A R                  D A T O S                    |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");

	gotoxy(20, 6); cout << "Ingrese el id del registro que desea eliminar: ";
	cin >> idpu;

	Puesto P = Puesto();
	P.eliminar(idpu);

	system("pause");
}
void modificar_puesto() {
	int id_pu;
	gotoxy(20, 2);	cout << ("__________________________________________________________________________________");
	gotoxy(20, 3);	cout << ("|                   M O D I F I C A R                D A T O S                    |");
	gotoxy(20, 4);	cout << ("|_________________________________________________________________________________|");


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
		gotoxy(35, 3); cout << ("----------      M E N U     D E    O P C I O N E S      ---------");
		gotoxy(50, 8); cout << ("1. Insertar a tabla Empleados");
		gotoxy(50, 9); cout << ("2. Mostrar Datos de la tabla");
		gotoxy(50, 10); cout << ("3. Eliminar dato");
		gotoxy(50, 11); cout << ("4. Modificar Datos");
		gotoxy(50, 12); cout << ("5. Salir");
		gotoxy(50, 15); cout << ("Ingresar Opcion: ");
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
	string nombres,apellidos, direccion, telefono, dpi,fechaN,fecha_inicio,fecha_ingreso="now()";
	int genero, idpuesto;
	gotoxy(30, 2); cout << ("__________________________________________________________________________________");
	gotoxy(30, 3); cout << ("|                 I N S E R T A R             D A T O S                           |");
	gotoxy(30, 4); cout << ("|_________________________________________________________________________________|");

	cin.ignore();
	gotoxy(30, 8); cout << "Ingrese Nombres: ";
	getline(cin,nombres);
	cin.ignore();

	gotoxy(30, 9); cout << "Ingrese Apellidos: ";
	getline(cin, apellidos);
	cin.ignore();
	
	gotoxy(30, 10); cout << "Ingrese Direccion: ";
	getline(cin, direccion);
	cin.ignore();
	
	gotoxy(30, 11); cout << "Ingrese Telefono: ";
	getline(cin, telefono);
	cin.ignore();
	
	gotoxy(30, 12); cout << "Ingrese No DPI: ";
	getline(cin, dpi);
	cin.ignore();
	
	gotoxy(30, 13); cout << "Ingrese Genero[0, 1]: ";
	cin >> genero;

	cin.ignore();
	gotoxy(30, 14); cout << "Ingrese Fecha Nacimiento: ";
	cin >> fechaN;

	cin.ignore();
	gotoxy(30, 15); cout << "Ingrese Id puesto: ";
	cin >> idpuesto;

	cin.ignore();
	gotoxy(30, 16); cout << "Ingrese Fecha de Incio laboral: ";
	cin >> fecha_inicio;

	
	Empleado P = Empleado(nombres,apellidos,direccion,telefono,dpi,genero,fechaN,idpuesto,fecha_inicio,fecha_ingreso);
	P.Crear();
	system("pause");
}

void mostrar_empleado() {
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");
	gotoxy(0, 6); cout << "ID |" << "  Nombres " << " Apellidos" << " Direccion" << "  Telefono" << "  DPI    " << "  Genero" << " Fecha Nacimiento"  << " Fecha inicio "<<"Fecha ingreso" << " Puesto";
	cout << ("\n\n");
	Empleado P = Empleado();
	P.Leer();
	system("pause");
}


void eliminar_empleado() {
	int idemp;
	
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                   E L I M I N A R                  D A T O S                    |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");

	gotoxy(20, 6); cout << "Ingrese el id del registro que desea eliminar: ";
	cin >> idemp;

	Empleado P = Empleado();
	P.eliminar(idemp);

	system("pause");
}
void modificar_empleado() {
	int id_emp;
	gotoxy(20, 2);	cout << ("__________________________________________________________________________________");
	gotoxy(20, 3);	cout << ("|                   M O D I F I C A R                D A T O S                    |");
	gotoxy(20, 4);	cout << ("|_________________________________________________________________________________|");


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
		gotoxy(35, 3); cout << ("----------      M E N U     D E    O P C I O N E S      ---------");
		gotoxy(50, 8); cout << ("1. Insertar a tabla Clientes");
		gotoxy(50, 9); cout << ("2. Mostrar Datos de la tabla");
		gotoxy(50, 10); cout << ("3. Eliminar dato");
		gotoxy(50, 11); cout << ("4. Modificar Datos");
		gotoxy(50, 12); cout << ("5. Salir");
		gotoxy(50, 15); cout << ("Ingresar Opcion: ");
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
	string nombres, apellidos, nit,telefono,correo_electronico,fecha_ingreso = "now()";
	int genero;
	gotoxy(30, 2); cout << ("__________________________________________________________________________________");
	gotoxy(30, 3); cout << ("|                 I N S E R T A R             D A T O S                           |");
	gotoxy(30, 4); cout << ("|_________________________________________________________________________________|");

	cin.ignore();
	gotoxy(40, 8); cout << "Ingrese Nombres: ";
	getline(cin, nombres);
	gotoxy(40, 9); cout << "Ingrese Apellidos: ";
	getline(cin,apellidos);
	gotoxy(40, 10); cout << "Ingrese Nit: ";
	getline(cin, nit);
	cin.ignore();
	gotoxy(40, 11); cout << "Ingrese genero[0,1]: ";
	cin >> genero;
	cin.ignore();
	gotoxy(40, 12); cout << "Ingrese telefono: ";
	getline(cin,telefono);
	gotoxy(40, 13); cout << "Ingrese Correo electronico: ";
	getline(cin,correo_electronico);

	Cliente P = Cliente(nombres, apellidos, nit, genero, telefono, correo_electronico, fecha_ingreso);

	P.Crear();
	system("pause");
}

void mostrar_cliente() {
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");
	gotoxy(0, 6); cout << "ID |" << "  Nombres " << " Apellidos" << " Nit" << "  Genero" << " Telefono    " << "  Correo electronico  " << " Fecha Ingreso";
	cout << ("\n\n");
	Cliente P = Cliente();
	P.Leer();
	system("pause");
}


void eliminar_cliente() {
	int idcliente;
	system("cls");
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                   E L I M I N A R                  D A T O S                    |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");

	gotoxy(20, 6); cout << "Ingrese el id del registro que desea eliminar: ";
	cin >> idcliente;

    Cliente P = Cliente();
	P.Eliminar(idcliente);

	system("pause");
}

void modificar_cliente() {
	int idcliente;
	gotoxy(20, 2);	cout << ("__________________________________________________________________________________");
	gotoxy(20, 3);	cout << ("|                   M O D I F I C A R                D A T O S                    |");
	gotoxy(20, 4);	cout << ("|_________________________________________________________________________________|");


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
		gotoxy(35, 3); cout << ("----------      M E N U     D E    O P C I O N E S      ---------");
		gotoxy(50, 8); cout << ("1. Insertar a Maestro detalle");
		gotoxy(50, 9); cout << ("2. Mostrar Datos de la tabla");
		gotoxy(50, 10); cout << ("3. Eliminar dato");
		gotoxy(50, 11); cout << ("4. Modificar Datos");
		gotoxy(50, 12); cout << ("5. Salir");
		gotoxy(50, 15); cout << ("Ingresar Opcion: ");
		cin >> a;
		switch (a) {
		case 1: system("cls");
			insertar_Maestro_detalle_compras();
			break;
/*		case 2: system("cls");
			mostrar_producto();
			break;

		case 3:system("cls");
			eliminar_producto();
			break;

		case 4:system("cls");
			modificar_producto();
			break;
			*/

		}

	} while (a != 5);
}
void insertar_Maestro_detalle_compras() {
	int No_orden, idproveedor, idcompra, idproducto, Cantidad, Preciocosto;
	string  fechaorden,fechaIn = "now()";
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");
	gotoxy(0, 6); cout << "ID |" << "Producto |" << "Descripcion |" << " Imagen  |" << "Precio costo |" << "Precio Venta |" << "Existencia |    " << "Fecha Ingreso       |" << "Id marca";
	cout << ("\n\n");

	Productos P = Productos();
	P.leer();
	_getch();
	cout << ("\n\n");
	cout << ("Ingrese No. de Orden: ");
	cin >> No_orden;

	cout << ("Ingrese Id proveedor: ");
	cin >> idproveedor;

	cout << ("Ingrese Fecha orden: ");
	cin >> fechaorden;
	
	cout << ("Ingrese Id Compra: ");
	cin >> idcompra;

	cout << ("Ingrese Id Producto: ");
	cin >> idproducto;

	cout << ("Ingrese Cantidad: ");
	cin >> Cantidad;

	cout << ("Precio Costo unitario: ");
	cin >> Preciocosto;
	Maestro_detalle_compras z = Maestro_detalle_compras(No_orden,idproveedor ,fechaorden,fechaIn);
	z.Crear1();
	

	system("pause");
}
