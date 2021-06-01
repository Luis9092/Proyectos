#pragma once
#include <iostream>
#include <string>
#include "ConexionDB.h"
#include <stdlib.h>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include <string.h> 
#include <fstream>

using namespace std;


class Maestro_ventas
{
private: string serie, fechafactura, fechaingreso;
	   int no_factura = 0, idcliente = 0, idempleado = 0;
public:
	Maestro_ventas()
	{
	}
	Maestro_ventas(string ser, string fechafac, int id_cl, int id_emp)
	{
		serie = ser;	fechafactura = fechafac;	idcliente = id_cl;	idempleado = id_emp;
	}


	void gotoxy(int x, int y)
	{
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon, dwPos);
	}

	void setno_factura(int no_f) { no_factura = no_f; }
	void setserie(string ser) { serie = ser; }
	void setfechafactura(string fechafac) { fechafactura = fechafac; }
	void setidcliente(int id_cl) { idcliente = id_cl; }
	void setidempleado(int id_emp) { idempleado = id_emp; }


	int getno_factura() { return no_factura; }
	string getserie() { return serie; }
	string getfechafactura() { return fechafactura; }
	int getidcliente() { return idcliente; }
	int getidempleado() { return idempleado; }




	///
	/// ////////////////////////////////////////////////////////////////////////////////////////////
	/// 

	void insert_ventas() {
		MYSQL_RES* resultado;
		MYSQL_ROW fila;
		int q_estado;
		int valor;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string no_fac = to_string(no_factura);
		string idcl = to_string(idcliente);
		string idemp = to_string(idempleado);

		string buscarmayor = "select MAX(nofactura) from ventas";
		const char* b = buscarmayor.c_str();
		q_estado = mysql_query(cn.getConectar(), b);
		if (!q_estado) {
			resultado = mysql_store_result(cn.getConectar());
			while (fila = mysql_fetch_row(resultado))
			{
				valor = atoi(fila[0]);
			}
		}
		if (cn.getConectar()) {
			int retorno = valor + 1;
			string ret = to_string(retorno);
			string  insertar = "INSERT INTO ventas(nofactura, serie, fechafactura, idcliente, idempleado, fechaingreso) VALUES (" + ret + ",'A',now()," + idcl + "," + idemp + ",now())";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	///
	/// ////////////////////////////////////////////////////////////////////////////////////////////
	/// 

	void leer_ventas()
	{
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
		
			string consulta = "select vd.idventa_detalle, v.serie,v.nofactura, v.fechafactura, prod.idProducto, prod.producto, vd.cantidad, vd.precio_unitario, c.idCliente, c.nombres, c.apellidos,c.NIT,e.idempleado,e.nombres, e.apellidos, v.fechaingreso from ventas_detalle as vd INNER JOIN ventas v on vd.idventa=v.idventa INNER JOIN productos prod on vd.idproducto=prod.idproducto INNER JOIN	clientes c on v.idcliente=c.idcliente INNER JOIN empleados e on v.idempleado=e.idempleado ORDER BY idventa_detalle";
			const char* c = consulta.c_str();
			int x = 6;
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << ("________________________________________________________________________________________________________________________________________________________________________") << endl;

				cout <<"|"<< fila[0] <<" |  " << fila[1] << " |  " << fila[2] << " |  " << fila[3] << " |  " << fila[4] << " |  " << fila[5] << " |  " << fila[6] << " |  " << fila[7] << " |  " << fila[8]<<" |  " << fila[9] << "  " << fila[10] << " |  " << fila[11]<<" |  " << fila[12] <<" |  "<< fila[13]<<" " << fila[14]<<" | " << fila[15] <<"|"<< endl;
				cout << ("________________________________________________________________________________________________________________________________________________________________________")<<endl;
				}
		
			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	//// 
	//// /////////////////////
	////

	void modificar(int idpro) {
		int q_estado, q_estado2, q_estado3;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila, fila2, fila3;
		MYSQL_RES* resultado;
		MYSQL_RES* resultado2;
		MYSQL_RES* resultado3;
		cn.abrir_conexion();
		string Id = to_string(idpro);
		string no_fac = to_string(no_factura);
		//string idc = to_string(idcliente);
		//string ide = to_string(idempleado);
		char opcion, opcion2;
		int valor, obtener;
		string nit;

		if (cn.getConectar()) {

			char s;

			string consulta3;
			string buscarmayor = "select idventa from ventas_detalle where idventa_detalle=" + Id + ";";
			const char* b = buscarmayor.c_str();
			q_estado = mysql_query(cn.getConectar(), b);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado))
				{
					valor = atoi(fila[0]);

				}
				//obtener = valor;
			}
			string val = to_string(valor);
			//string consulta2 = "select v.idventa, v.nofactura, v.serie, v.fechafactura, c.idcliente, c.nombres, e.idempleado, e.nombres, v.fechaingreso from ventas as v INNER JOIN	clientes c on v.idventa=c.idcliente INNER JOIN empleados e on v.idventa=e.idempleado	 where idventa= " + val + "";
			//string consulta2 = "select * from ventas where idventa="+val+";";
			//select v.nofactura, v.serie, v.fechafactura, c.nombres, c.apellidos, e.nombres, e.apellidos, v.fechaingreso from ventas as v INNER JOIN	clientes c on v.idventa=c.idcliente INNER JOIN empleados e on v.idventa=e.idempleado;
			string consulta2 = "select v.idventa, v.nofactura, v.serie, v.fechafactura, c.nit, c.nombres, e.idempleado, e.nombres, v.fechaingreso from ventas as v INNER JOIN	clientes c on v.idcliente=c.idcliente INNER JOIN empleados e on v.idempleado=e.idempleado where idventa=" + val + ";";
			const char* c = consulta2.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			system("cls");
			gotoxy(30, 2); cout << ("__________________________________________________________________________________");
			gotoxy(30, 3); cout << ("|                 M O D I F I C A R             D A T O S                           |");
			gotoxy(30, 4); cout << ("|_________________________________________________________________________________|");
			cout << ("\n\n");
			Leer_empleado();
			Leer_productos();
			Leer_cliente();
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado))
				{
					cout << "\n\n\n\t\t\t\t\t\t------------    [" << fila[0] << "]     ------------- ";
					cout << "\n\t\t\t\t\t\tnumero de factura:  " << fila[1];
					cout << "\n\t\t\t\t\t\tSerie: " << fila[2];
					cout << "\n\t\t\t\t\t\tfecha de factura:   " << fila[3];
					cout << "\n\t\t\t\t\t\tnit del cliente:    " << fila[4];
					cout << "\t" << fila[5];
					cout << "\n\t\t\t\t\t\tid del empleado:    " << fila[6];
					cout << "\t" << fila[7];
					cout << "\n\t\t\t\t\t\tfecha de ingreso:   " << fila[8];

					cin.ignore();

					//cout << ("\n\n\n\tnumero de factura: ") << fila[1] << endl;
					//cout << "\tingrese el nuevo numero de factura: \n\t";
					//cin >> no_fac;	cin.ignore();
					//string no_fac = to_string(no_factura);
					//cin.ignore();

					cout << ("\n\n\tserie: ") << fila[2] << endl;
					cout << "\tingrese nueva serie: \n\t";
					getline(cin, serie);

					cout << ("\n\n\tfecha de factura: ") << fila[3] << endl;
					cout << "\tingrese la nueva fecha de la factura(anio/mes/dia): \n\t";
					getline(cin, fechafactura);

					cout << ("\n\n\tnit del cliente: ") << fila[4] << endl;
					cout << "\tingrese nuevo nit cliente: \n\t";
					cin >> nit;
					validarnit(nit);
					while (validarnit(nit) == 1) {
						cout << "\tNit no valido, vuelva a ingresar el nit: ";

						cin >> nit;
						validarnit(nit);
					}
					idcliente = retornaridcliente(nit);
					mostrarcliente(idcliente);
					cin.ignore();


					cout << ("\n\n\tid del empleado: ") << fila[6] << endl;
					cout << "\tingrese nuevo id empleado: \n\t";
					cin >> idempleado;
					validaridempleado(idempleado);
					while (validaridempleado(idempleado) == 1) {
						cout << "\tidempleado invalido, ingrese un id existente: ";
						cin >> idempleado;
						validaridempleado(idempleado);
					}
					mostrarempleado(idempleado);
					string ide = to_string(idempleado);

					cin.ignore();
				}
				cout << "\n\n\t\t*** Desea modificar los registros (s/n): ";
				cin >> opcion;
				if ((opcion == 's') || (opcion == 'S'))
				{
					string idc = to_string(idcliente);
					string ide = to_string(idempleado);
					string modificar1 = "update ventas set serie = '" + serie + "',fechafactura = '" + fechafactura + "',idcliente = " + idc + ",idempleado=" + ide + ", fechaingreso=now()  where idventa =" + val + "";
					//string modificar1 = "update ventas set nofactura = " + no_fac + ",serie = '" + serie + "',fechafactura = '" + fechafactura + "',idcliente = " + idc + ",idempleado=" + ide + ", fechaingreso=now()  where idventa =" + Id + "";
					const char* d = modificar1.c_str();
					q_estado = mysql_query(cn.getConectar(), d);
				}
				else
				{
					cout << "...error en esto....";
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
			string idp = to_string(idempleado);
			string idc = to_string(idcliente);
			int idventa = 0, idproducto = 0, cantidad = 0;
			float preciounitario = 0;

			string idven = to_string(idventa);

			string cant = to_string(cantidad);


			char s;
			string consulta3 = "select vd.idventa_detalle, v.idventa, prod.idproducto, prod.producto, vd.cantidad, vd.precio_unitario from ventas_detalle as vd INNER JOIN ventas v on vd.idventa=v.idventa INNER JOIN productos prod on vd.idproducto=prod.idproducto where idventa_detalle=" + Id + ";";
			const char* d = consulta3.c_str();
			q_estado = mysql_query(cn.getConectar(), d);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "\n\n\n\t\t\t\t\t\t------------    [" << fila[0] << "]     ------------- ";
					cout << "\n\t\t\t\t\t\tId venta:        " << fila[1];
					cout << "\n\t\t\t\t\t\tId producto:     " << fila[2];
					cout << "\t" << fila[3];
					cout << "\n\t\t\t\t\t\tcantidad:        " << fila[4];
					cout << "\n\t\t\t\t\t\tprecio unitario: " << fila[5];



					cout << ("\n\n\tid producto: ") << fila[2] << endl;
					cout << " \tingrese el nuevo id producto: ";
					cin >> idproducto;
					validaridproducto(idproducto);
					while (validaridproducto(idproducto) == 1) {
						cout << "\tidproducto invalido, ingrese un id existente: ";
						cin >> idproducto;
						validaridproducto(idproducto);
					}
					mostrarproducto(idproducto);
					string idprod = to_string(idproducto);

					cout << ("\n\n\tcantidad: ") << fila[4] << endl;
					cout << " \tingrese la nueva Cantidad: ";
					cin >> cant;

					//cout << ("\n\n\tPrecio Unitario: ") << fila[5] << endl;
					//cout << "\tingrese el nuevo precio unitario:";
					//cin >> precio_u;
					preciounitario = retornarprecio_venta(idproducto);
					string precio_u = to_string(preciounitario);
					//string dd = to_string(precio_un);

					cout << "\n\n\t\t*** Desea modificar los registros (s/n): ";
					cin >> opcion2;
					if ((opcion2 == 's') || (opcion2 == 'S'))
					{

						string modificar2 = "update ventas_detalle set idproducto = " + idprod + ",cantidad = " + cant + ",precio_unitario = " + precio_u + "  where idventa_detalle =" + Id + "";
						//string modificar2 = "update ventas_detalle set idventa = " + idven + ",idproducto = " + idprod + ",cantidad = " + cant + ",precio_unitario = " + precio_u + "  where idventa_detalle =" + Id + "";
						const char* e = modificar2.c_str();
						q_estado = mysql_query(cn.getConectar(), e);
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
	void mostrarcliente(int idcliente) {
		int q_estado3;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila3;
		MYSQL_RES* resultado3;
		string idc = to_string(idcliente);
		cn.abrir_conexion();
		string consulta4 = "select nombres from clientes where idcliente=" + idc + ";";
		const char* g = consulta4.c_str();
		q_estado3 = mysql_query(cn.getConectar(), g);

		if (!q_estado3) {
			resultado3 = mysql_store_result(cn.getConectar());

			while (fila3 = mysql_fetch_row(resultado3))
			{
				cout << "\t*** " << fila3[0] << " ***";
			}
		}
	}


	void mostrarempleado(int idempleado) {
		int q_estado3;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila3;
		MYSQL_RES* resultado3;
		string idem = to_string(idempleado);
		cn.abrir_conexion();
		string consulta4 = "select nombres from empleados where idempleado=" + idem + ";";
		const char* g = consulta4.c_str();
		q_estado3 = mysql_query(cn.getConectar(), g);

		if (!q_estado3) {
			resultado3 = mysql_store_result(cn.getConectar());

			while (fila3 = mysql_fetch_row(resultado3))
			{
				cout << "\t*** " << fila3[0] << " ***";
			}
		}
	}

	void mostrarproducto(int idproducto) {
		int q_estado3;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila3;
		MYSQL_RES* resultado3;
		string idprod = to_string(idproducto);
		cn.abrir_conexion();
		string consulta4 = "select producto, precio_venta from productos where idproducto=" + idprod + ";";
		const char* g = consulta4.c_str();
		q_estado3 = mysql_query(cn.getConectar(), g);

		if (!q_estado3) {
			resultado3 = mysql_store_result(cn.getConectar());

			while (fila3 = mysql_fetch_row(resultado3))
			{
				cout << "\t*** " << fila3[0] << ",   Q" << fila3[1] << " ***";
			}
		}
	}



	void Eliminar(int id) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string a = to_string(id);
			string eliminar = "delete from ventas_detalle where idventa_detalle = " + a + "";
			string eliminar2 = "delete from ventas where idventa = " + a + "";
			const char* i = eliminar.c_str();
			const char* ii = eliminar2.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "\n\n\n\n\t\tEliminacion 1 Exitosa... ...";
			}
			else {
				cout << "\n\n\n\n\t\t--------- Error al ELiminar Datos ---------";
			}
			q_estado = mysql_query(cn.getConectar(), ii);
			if (!q_estado) {
				cout << "\n\n\n\n\t\tEliminacion 2 Exitosa... ...";
			}
			else {
				cout << "\n\n\n\n\t\t--------- Error al ELiminar Datos ---------";
			}
		}
		else {
			cout << "--------- Error en la Conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}

	/// <summary>
	/// ///////////////////////////////
	/// </summary>

	void Leer_cliente() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		int t = 10, h = 10;
		int  b = 10, d = 10, e = 10, f = 10, g = 10, z = 10, w = 10;
		if (cn.getConectar()) {
			string a;
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			gotoxy(1, 6);	cout << "---------Id cliente disponibles---------" << endl;
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					//gotoxy(1, t); cout << "\n" << fila[0] << "  |" << fila[1] << "  |" << fila[3];
					//gotoxy(1, t); cout << fila[0]; 
					//gotoxy(3, t); cout << fila[1] << "  |" << fila[3];
					//gotoxy(9, 6); cout << ("Id Disponible");
					gotoxy(2, 7); cout << ("--------------------------------------");
					gotoxy(1, 8); cout << ("| ID|");
					gotoxy(10, 8); cout << ("     Cliente      |");
					gotoxy(31, 8); cout << ("  NIT    |");
					gotoxy(2, 9); cout << ("--------------------------------------");

					gotoxy(2, t++); cout << fila[0];
					gotoxy(7, h++); cout << fila[1];
					gotoxy(29, z++); cout << fila[3];

					gotoxy(1, b++); cout << ("|");
					gotoxy(5, d++); cout << ("|");
					gotoxy(28, e++); cout << ("|");
					gotoxy(40, w++); cout << ("|");

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

	int retornaridcliente(string id)
	{
		int q_estado, a;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		int ide;
		//string uno = to_string(id);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select idcliente from clientes where nit = '" + id + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					ide = atoi(fila[0]);
					return ide;
				}
			}
		}
		else {
			cout << "--------- Error en la Conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}

	float retornarprecio_venta(int id)
	{
		int q_estado, a;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		float precio_venta;
		string ide = to_string(id);
		//string uno = to_string(id);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select precio_venta from productos where idproducto=" + ide + ";";
			//string consulta = "select  p.precio_venta from ventas_detalle as v INNER JOIN productos as p on v.idproducto=p.idproducto where idventa_detalle="+ide+";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					precio_venta = atof(fila[0]);
					return precio_venta;
				}
			}
		}
		else {
			cout << "--------- Error en la Conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}



	float total() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		int valor = 0;
		int idventa = 0;

		string buscarmayor = "select MAX(idventa) from ventas";
		const char* b = buscarmayor.c_str();
		q_estado = mysql_query(cn.getConectar(), b);
		if (!q_estado) {
			resultado = mysql_store_result(cn.getConectar());
			while (fila = mysql_fetch_row(resultado))
			{
				valor = atoi(fila[0]);

			}
		}

		if (cn.getConectar()) {
			string a;
			//int retorno = valor;
			idventa = valor;
			float retorno;
			//int idventa = valor;
			string ret = to_string(idventa);
			string consulta = "select SUM(cantidad * precio_unitario) from ventas_detalle where idventa=" + ret + ";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					//cout << "\n" << fila[0];
					retorno = atoi(fila[0]);

					return retorno;
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


	void Leer_empleado() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_ROW filac;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		int t = 10, h = 10;
		int  b = 10, d = 10, e = 10, f = 10, g = 10, z = 10, w = 10;
		if (cn.getConectar()) {
			string a;
			string consulta = "select * from empleados";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			gotoxy(45, 6);	cout << "-----------Id empleado disponibles-----------" << endl;
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					gotoxy(46, 7); cout << ("-------------------------------------------");
					gotoxy(45, 8); cout << ("| ID|");
					gotoxy(52, 8); cout << ("               Empleado              |");
					gotoxy(46, 9); cout << ("-------------------------------------------");

					gotoxy(46, t++); cout << fila[0];
					gotoxy(51, h++); cout << fila[1];
					gotoxy(70, z++); cout << fila[2];

					gotoxy(45, b++); cout << ("|");
					gotoxy(49, d++); cout << ("|");
					gotoxy(69, e++); cout << ("|");
					gotoxy(89, w++); cout << ("|");

				}
			}
		}
		else {
			cout << "--------- Error en la Conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}

	int validaridempleado(int id)
	{
		int q_estado, a;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string uno = to_string(id);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select idempleado from empleados where idempleado = " + uno + "";
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


	void Leer_productos() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_ROW filac;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		int t = 10, h = 10;
		int  b = 10, d = 10, e = 10, f = 10, g = 10, z = 10, w = 10;
		if (cn.getConectar()) {
			string a;
			string consulta = "select p.idproducto, p.producto, m.marca from productos as p INNER JOIN marcas as m on p.idmarca=m.idmarca;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			gotoxy(96, 6);	cout << "----------Id productos disponibles-----------" << endl;
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					gotoxy(97, 7); cout << ("-------------------------------------------");
					gotoxy(96, 8); cout << ("| ID|");
					gotoxy(102, 8); cout << ("       Producto     |");
					gotoxy(126, 8); cout << ("    Marca     |");
					gotoxy(97, 9); cout << ("-------------------------------------------");

					gotoxy(97, t++); cout << fila[0];
					gotoxy(102, h++); cout << fila[1];
					gotoxy(123, z++); cout << fila[2];

					gotoxy(96, b++); cout << ("|");
					gotoxy(100, d++); cout << ("|");
					gotoxy(122, e++); cout << ("|");
					gotoxy(140, w++); cout << ("|");

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
	int validaridproducto(int id)
	{
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string uno = to_string(id);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select idproducto from productos where idproducto = " + uno + "";
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
	int validarnit(string id)
	{
		int q_estado, a;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		//string uno = to_string(id);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select nit from clientes where nit = '" + id + "'";
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
	int validar_nit(string vnit) {
		const char* vali = vnit.c_str();
		//strcpy(vali, vnit.c_str());
		if (strlen(vali) < 8) {
			//cout << "                                                                  ";
			cout << "\t------Su nit es demasiado corto" << endl;
			return 1;
		}
		if (strlen(vali) > 8) {
			//cout << "                                                                  ";
			cout << "\t------Su nit es demasiado largo" << endl;
			return 1;
		}
		if (strlen(vali) == 8) {
			//cout << "                                                                  ";
			cout << "\t------El nit es valido" << endl;
			return 3;
		}
	}
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Maestro_detalle_ventas2 {
	void gotoxy(int x, int y)
	{
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon, dwPos);
	}
	/*
	struct Factura {

		int id;
		char traduccion[20];
		char funcionalidad[70];
		int codigo;
	};
	*/
private: int idventa = 0, idproducto = 0, cantidad = 0;
	   float preciounitario = 0;

	   // constructor
public:

	Maestro_detalle_ventas2() {
	}
	Maestro_detalle_ventas2(int idprod, int cant, float pu) {
		idproducto = idprod;	cantidad = cant;	preciounitario = pu;
	}


	void setId_venta(int idv) { idventa = idv; }
	void setId_producto(int idprod) { idproducto = idprod; }
	void setCantidad(int cant) { cantidad = cant; }
	void setPrecio_Unitario(float pcu) { preciounitario = pcu; }

	int getId_venta() { return idventa; }
	int getId_producto() { return  idproducto; }
	int getCantidad() { return  cantidad; }
	float getPrecio_Unitario() { return  preciounitario; }


	void insert() {
		int q_estado;
		int valor;
		MYSQL_RES* resultado;
		MYSQL_ROW fila;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();

		string idv = to_string(idventa);
		string idp = to_string(idproducto);
		string cant = to_string(cantidad);
		string preciou = to_string(preciounitario);


		string buscarmayor = "select MAX(idventa) from ventas";
		const char* b = buscarmayor.c_str();
		q_estado = mysql_query(cn.getConectar(), b);
		if (!q_estado) {
			resultado = mysql_store_result(cn.getConectar());
			while (fila = mysql_fetch_row(resultado))
			{
				valor = atoi(fila[0]);
			}
		}

		if (cn.getConectar()) {
			int retorno = valor;
			string ret = to_string(retorno);
			string  insertar = "insert into ventas_detalle(idventa,idproducto,cantidad,precio_unitario) VALUES (" + ret + "," + idp + "," + cant + "," + preciou + ")";

			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "\n\n\tIngreso Exitoso ... ...";
			}
			else {
				cout << "\n\n\t--------- Error al Ingresar Datos ---------";
			}
		}
		else {
			cout << "\n\n\t--------- Error en la Conexion ---------";
		}
		cn.cerrar_conexion();
	}

	void Crear_factura() {
		int q_estado;
		int q_estado2;
		int q_estado3;
		int q_estado4;
		int q_estado5;

		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		int  xa = 8, xb = 8, xc = 8, xd = 8, xe = 8, xf = 8, xg = 8, xh = 8, xi = 8, xj = 8, xl = 8;
		int za = 8, zb = 8, zc = 4, zd = 8, ze = 8, zf = 8, zg = 8, zh = 8, zi = 8, zj = 8, zk = 8, zl = 8;
		int lleva, lleva2;
		float lleva3;
	
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

				if (cn.getConectar()) {
					int valor = lleva;
					string encontrar = to_string(valor);
					//string consulta = "select max(idCompra) FROM compras";
				//	string consulta= "select max(no_orden_compra) FROM compras";
					string consulta4 = "select   x.idVenta, x.nofactura,x.serie, m.nombres,m.apellidos, m.NIT, m.telefono,m.correo_electronico, d.nombres,d.apellidos, fechafactura from ventas as x inner join clientes as m on x.idCliente=m.idCliente inner join empleados as d on x.idempleado=d.idempleado where idVenta=" + encontrar + "";

					const char* jk = consulta4.c_str();
					q_estado2 = mysql_query(cn.getConectar(), jk);
					if (!q_estado2) {
						resultado = mysql_store_result(cn.getConectar());
						while (fila = mysql_fetch_row(resultado)) {
							//							cout << fila[1] << fila[2] << fila[3] << fila[4] << fila[5] << fila[6] << fila[7] << fila[8] << fila[9] << endl;
							gotoxy(45, 10); cout << "No pedido: " << fila[0]; //idVenta
							gotoxy(45, 8); cout << "Serie: " << fila[2];//Serie
							gotoxy(55, 8); cout << "No factura: " << fila[1]; //no fact
							gotoxy(50, 13); cout << ("Cliente:    ");
							gotoxy(45, 15); cout << fila[3] << " " << fila[4]; //Nombres //Apellidos

							gotoxy(45, 16); cout << "NIT: " << fila[5];   //Nit
							gotoxy(45, 17); cout << "No. Telefono: " << fila[6];  //Telefono
							gotoxy(45, 18); cout << "Correo: " << fila[7];  //correo

							gotoxy(110, 15); cout << (" Atendido por :");  //Apellidos
							gotoxy(101, 17); cout << fila[8] << " " << fila[9];  //Apellidos

							gotoxy(115, 8); cout << "Fecha: " << fila[10] << endl;  //Fecha Factura
							lleva2 = atoi(fila[1]);

						
						}
						int ma = 25, mb = 25, mc = 25, md = 25, me = 25, mf = 25, mg = 25, mh = 25, mi = 25, mj = 25, mk = 25, ml = 25,mm=25;
						if (cn.getConectar()) {
							string encontrado = to_string(lleva2);

							string consulta5 = "select   x.idVenta_detalle,d.producto,d.descripcion, x.precio_unitario,x.cantidad, m.idVenta from ventas_detalle as x inner join ventas as m on x.idVenta=m.idVenta inner join productos as d on x.idProducto=d.idProducto where nofactura="+ encontrado+"";
							const char* cc = consulta5.c_str();
							q_estado3 = mysql_query(cn.getConectar(), cc);
							if (!q_estado3) {
								resultado = mysql_store_result(cn.getConectar());
								while (fila = mysql_fetch_row(resultado)) {
									gotoxy(43, 22); cout << ("--------------------------------------------------------------------------------------------");
									gotoxy(43, 23); cout << ("|  No.   |"); gotoxy(54, 23); cout << ("     Producto    |"); gotoxy(73, 23); cout << ("       Descripcion        |"); 
									gotoxy(100, 23); cout << ("  precio |"); gotoxy(110, 23); cout << ("Cantidad|"); gotoxy(120, 23); cout << ("  Sub-Total   |");
									gotoxy(43, 24); cout << ("--------------------------------------------------------------------------------------------");

									gotoxy(46, ma++); cout << fila[0]; gotoxy(53, mb++); cout << fila[1]; gotoxy(72, mc++);cout << fila[2];
									gotoxy(101, md++); cout<<"Q." << fila[3]; gotoxy(110, me++); cout << fila[4]; //idVenta
									gotoxy(43, mf++); cout << "|";
									gotoxy(52, mg++); cout << "|";
									gotoxy(71, mh++); cout << "|";
									gotoxy(99, mi++); cout << "|";
									gotoxy(109, mj++); cout << "|";
									gotoxy(118, ml++); cout << "|";
									gotoxy(134, mk++); cout << "|";

								
				
								}
								if (cn.getConectar()) {
									string consultar = "select (cantidad * precio_unitario) from ventas_detalle where idventa="+encontrar +"";
									const char* dc = consultar.c_str();
									q_estado5 = mysql_query(cn.getConectar(), dc);
									if (!q_estado5) {
										resultado = mysql_store_result(cn.getConectar());
										while (fila = mysql_fetch_row(resultado)) {
											
											gotoxy(121, mm++); cout<<"Q." << fila[0];
										}

										if (cn.getConectar()) {
											string consulta6 = "select sum(cantidad * precio_unitario) from ventas_detalle where idventa=" + encontrar + "";
											const char* bb = consulta6.c_str();
											q_estado4= mysql_query(cn.getConectar(),bb);
											if (!q_estado4) {
												resultado = mysql_store_result(cn.getConectar());
												while (fila = mysql_fetch_row(resultado)) {
													//	
													cout << ("\n\t\t\t\t\t   |-------------------------------------------------------------------------------------------");
													cout << "\n\t\t\t\t\t   |                                                                 Total    |"<<"  Q." << fila[0]<<" ";
													cout << ("\n\t\t\t\t\t   |-------------------------------------------------------------------------------------------");

												}
								cout << ("\n\t\t\t\t\t   |                                                                                          |");

								cout << ("\n\t\t\t\t\t   |                                   Gusto en atenderle!!                                   |");
								cout << ("\n\t\t\t\t\t   --------------------------------------------------------------------------------------------");

							}
							else {
								cout << "\n\n\t--------- Error en la Base de datos1  ---------";
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
				}
			}
			else {
			cout << "\n\n\t--------- Error en la Conexion ---------";
			}
		cn.cerrar_conexion();
		/*
		void documento() {
			FILE* archivo;
			fopen_s(&archivo, "Luna.txt", "ab");
			Factura factura;

			int pedido = atoi(fila[0]);
			fopen_s(&archivo, "Luna.txt", "ab"); // ab
			cin >> factura.codigo;
			fwrite(&factura, sizeof(Factura), 1, archivo);

			lleva2 = atoi(fila[1]);

			fclose(archivo);

		}
		*/
}

};
