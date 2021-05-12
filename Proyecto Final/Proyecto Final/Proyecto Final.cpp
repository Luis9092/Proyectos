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

#define s 40
#define ENTER 13 
#define BACKSPACE 8
#define getch() _getch()

void fondo();
void cambiarcolor(int x);
void gotoxy(int x, int y);
void co(int, int);

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
void controlz();
void Mostrar();
void Registrarse();
void crear_usuario();
void cargando();
void marco();
void bla(int);

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
/*
void eliminar_Maestro_detalle_compras();
void modificar_Maestro_detalle_compras();
*/


struct Login {

	char Nombre[40];
	char Apellidos[40];
	char contra[20];
	int codigo;
};

int main() {
	//	system("mode con: cols=390 lines=540");
	//Login2 a;
	//a.controlz();
	controlz();
}


void control1() {
	int a;
	do {
		co(0,240);
		system("cls");
		marco();
		gotoxy(47, 2); cout << ("같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같�");
		gotoxy(47, 3); cout << ("같�                 M E N U    D E    O P C I O N E S                 같�");
		gotoxy(47, 4); cout << ("같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같�");
		gotoxy(60, 8); cout << ("1. T A B L A   P R O D U C T O S");
		gotoxy(60, 9); cout << ("2. T A B L A   M A R C A S ");
		gotoxy(60, 10); cout << ("3. T A B L A   P R O V E E D O R E S ");
		gotoxy(60, 11); cout << ("4. T A B L A   P U E S T O S ");
		gotoxy(60, 12); cout << ("5. T A B L A   E M P L E A D O S ");
		gotoxy(60, 13); cout << ("6. T A B L A   C L I E N T E S ");
		gotoxy(60, 14); cout << ("7. T A B L A  M  A E S T R O    D E T A L L E  ");
		gotoxy(60, 15); cout << ("8. S A L I R ");
		gotoxy(60, 20); cout << ("Ingresar Opcion: ");
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
		case 2: system("cls");
			mostrar_Maestro_detalle_compras();
			break;
			/*
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
	int No_orden, idproveedor, idcompra, idproducto, Cantidad;
	float Preciocosto;
	string  fechaorden,fechaIn = "now()";
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");
	gotoxy(0, 6); cout << "ID |" << "Producto |" << "Descripcion |" << "Precio costo |" << "Precio Venta |"  << "Id marca";
	cout << ("\n\n");

	Maestro_detalle_compras P = Maestro_detalle_compras();
	P.leer();
	_getch();
	cout << ("\n\n");
	cout << ("Ingrese No. de Orden: ");
	cin >> No_orden;

	cout << ("Ingrese Id proveedor: ");
	cin >> idproveedor;

	cout << ("Ingrese Fecha orden: ");
	cin >> fechaorden;

	//Comienza el detalle

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
	
	Maestro_detalle_compras2 f = Maestro_detalle_compras2(idcompra,idproducto,Cantidad,Preciocosto);
	f.Crear_detalle();

	system("pause");
}

void mostrar_Maestro_detalle_compras() {
	gotoxy(20, 2); cout << ("__________________________________________________________________________________");
	gotoxy(20, 3); cout << ("|                    D A T O S             G U A R D A D O S                      |");
	gotoxy(20, 4); cout << ("|_________________________________________________________________________________|");
	gotoxy(0, 6); cout << "ID |"  << "  Cantidad  " << " Precio Unidad " << " Id Compra  " << "  id Producto  " << "   id Compra " << "  No. Orden " << "  Fecha Orden " << "     Fecha Ingreso    " << "  Id Proveedor";
	cout << ("\n\n");
	Maestro_detalle_compras2 P = Maestro_detalle_compras2();
	P.Leer_compras_Detalle();
	Maestro_detalle_compras r = Maestro_detalle_compras();
	r.Leer_compras();
	_getch();
}

void controlz() {
	int a;
	do {
		fondo();
		system("cls");
		co(0, 240);
		gotoxy(65, 5); cout << (" 1. REGISTRASE");
		gotoxy(65, 6); cout << (" 2. VER DATOS");
		gotoxy(65, 7); cout << (" 3. CREAR USUARIO");
		gotoxy(65, 10); cout << ("4. SALIR");
		gotoxy(65, 15); cout << ("Ingrese Opcion: ");
		cin >> a;
		switch (a) {
		case 1: system("cls"); Registrarse();
			break;
		case 2: system("cls"); Mostrar();
			break;
		case 3:crear_usuario();
			break;
		}
	} while (a != 4);
}


void crear_usuario() {
	system("cls");
	//	FILE* archivo = fopen(Archivo, "ab"); // ab
		//FILE* busqueda = fopen(Archivo, "rb");
	//	FILE* busqueda;
	FILE* archivo;
	fopen_s(&archivo, "c:\\Archivo proyecto\\cas.txt", "ab");

	Login login;
	string reg, ape, contras;
	string pre, pk;
	char  jk;
	int error = 0;
	int comparacion;


	do {
		string palabra;//buscar dato

		FILE* busqueda;
		fopen_s(&busqueda, "c:\\Archivo proyecto\\cas.txt", "rb");

		cin.ignore();
		fflush(stdin);
		gotoxy(20, 5); cout << "Ingrese Nombres: ";
		getline(cin, palabra);
		char* pal;
		pal = (char*)palabra.c_str();
		fread(&login, sizeof(Login), 1, busqueda);

		while (!feof(busqueda)) {
			fread(&login, sizeof(Login), 1, busqueda);
			comparacion = strcmp(pal, login.Nombre);
			if (comparacion == 0) {
				cout << ("Nombre Repetido, Vuela A intentarlo") << endl;
				crear_usuario();
				break;
			}

		}
		fclose(busqueda);
	} while (pre == login.Nombre);

	if (comparacion != 0) {
		fflush(stdin);
		login.codigo = 0;
		login.codigo = login.codigo + 1;
		gotoxy(20, 8); cout << ("Vuela a repetir el Nombre: ");
		getline(cin, reg);
		strcpy_s(login.Nombre, reg.c_str());

		gotoxy(20, 10); cout << ("Apellidos: ");
		getline(cin, ape);
		strcpy_s(login.Apellidos, ape.c_str());

		gotoxy(20, 12); cout << "Ingrese Id Usuario: ";

		jk = getch();
		while (jk != ENTER) {
			if (jk != BACKSPACE) {
				contras.push_back(jk);
				cout << "*";

			}
			else {

				if (contras.length() > 0) {
					cout << "\b \b";
					contras = contras.substr(0, contras.length() - 1);
				}
			}
			jk = getch();
		}
		pk += contras;
		cin.ignore();
		strcpy_s(login.contra, pk.c_str());
		fflush(stdin);
		gotoxy(20, 16); cout << ("Usuario Creado Correctamente");
		fwrite(&login, sizeof(Login), 1, archivo);
		fclose(archivo);
	}
}

void Registrarse() {
	int error = 0;
	int comparacion;
	Login login;
	//	FILE* busqueda = fopen(Archivo, "rb");
		//FILE* busqueda;
	//	FILE* archivo;
	//	busqueda = fopen("c:\\Archivo proyecto\\casa.txt", "rb");
		//archivo = fopen("c:\\Archivo proyecto\\casa.txt", "ab");
	FILE* busqueda;
	fopen_s(&busqueda, "c:\\Archivo proyecto\\cas.txt", "rb");


	int id;
	char jk;
	string codigo;//buscar dato

	gotoxy(50, 2); cout << "Ingrese su codigo de ingreso: ";

	jk = getch();
	while (jk != ENTER) {

		if (jk != BACKSPACE) {
			codigo.push_back(jk);
			cout << "*";

		}
		else {

			if (codigo.length() > 0) {
				cout << "\b \b";
				codigo = codigo.substr(0, codigo.length() - 1);

			}
		}
		jk = getch();
	}
	char* cstr;
	cstr = (char*)codigo.c_str();
	/*
		char cstr[codigo.size() + 1];
		codigo.copy(cstr, codigo.size() + 1);
		cstr[codigo.size()] = '\0';
		*/
	while (!feof(busqueda)) {
		fread(&login, sizeof(Login), 1, busqueda);

		comparacion = strcmp(cstr, login.contra);

		if ((comparacion == 0) && (login.contra == login.contra)) {
			gotoxy(45, 3); cout << ("------------------------------------------------------------------------");
			gotoxy(55, 4); cout << ("      Bienvenido Al sistema	   Jefe :3      ");
			gotoxy(55, 14); cout << login.Nombre << " " << login.Apellidos;
			gotoxy(45, 15); cout << ("------------------------------------------------------------------------");
			cargando();
			_getch();
			control1();
			error = 1;
			break;
		}
	}

	if (error == 0)
	{
		cout << endl << "Error! Usuario No creado";
	}
	fclose(busqueda);
	getch();
}

void co(int x, int c) {
	cambiarcolor(c);
	int i;
	for (i = 1; i <= x; i++) {
		cout << char(219) << char(219);
	}
}


void Mostrar() {
	system("cls");
	//FILE* busqueda;
	FILE* archivo;
	//busqueda = fopen("c:\\Archivo proyecto\\casa.txt", "rb");

	fopen_s(&archivo, "c:\\Archivo proyecto\\cas.txt", "r+b");

	//	archivo = fopen("c:\\Archivo proyecto\\casa.txt", "ab");
	if (!archivo) {
		fopen_s(&archivo, "c:\\Archivo proyecto\\cas.txt", "w+b");
		//		archivo = fopen(Archivo, "w+b");
	}

	Login login;
	int registro = 0;
	fread(&login, sizeof(Login), 1, archivo);
	cout << "____________________________________________________________________" << endl;
	cout << "id" << "|" << " Nombres " << "|\t" << "Apellidos " << "|\t " << "id" << endl;
	do {
		cout << "____________________________________________________________________" << endl;
		cout << registro << " \t| " << login.Nombre << " \t|" << login.Apellidos << " \t|" << "\t|" << login.contra << endl;

		fread(&login, sizeof(Login), 1, archivo);
		registro += 1;

	} while (feof(archivo) == 0);
	cout << endl;

	fclose(archivo);
	getch();
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
	gotoxy(83, 39); cout << ("Cargando...");

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
void marco() {

	int z = 247, m = 249, k = 247;

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