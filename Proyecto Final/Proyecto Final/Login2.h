#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<cstdio>
#include<string.h> 
#include <string> 
#include <cstdio>
#include<dos.h>
#include <stdarg.h>
#include <cstdlib>
#include <cstring>     // for printf
#include <errno.h>  
#include "Login2.h"

#define s 40
#define ENTER 13 
#define BACKSPACE 8
#define getch() _getch()

using namespace std;

class Login2
{
	/*
void fondo();
void cambiarcolor(int x);
void gotoxy(int x, int y);
void co(int, int);
*/
//const char* Archivo = "prueba2.dat";

public:
	Login2() {
	}

struct Login {

	char Nombre[40];
	char Apellidos[40];
	char contra[20];
	int codigo;
};
/*
void Registrarse();
void Mostrar();
void control();
void crear_usuario();
void cargando();
*/

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


void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void cambiarcolor(int X) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), X);
}
void fondo() {
	system("COLOR f3");
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
};