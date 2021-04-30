/*
 ============================================================================
 Name        : clase_9.c
 Author      : Nicolas Penayo
 Version     :
 Copyright   : Nicolas Penayo 1E
 Description : Desarrollar un programa que permita guardar los datos de 5 alumnos.
 Los datos a guardar para cada alumno:
 legajo, sexo, edad, nota1, nota2, promedio, apellido.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "arrays.h"
#include "menu.h"
#include "student.h"
#define STD_AMOUNT 5
#define MAIN_OPT 6
#define ORDER_OPT 4
#define MOD_OPT 6

void clearConsole();
int main(void) {
	//Student students[REGISTERS];
	//Declarar variables
	int count = 0;
	char confirm;

	//Declaracion de todos los menus que componen el programa
	Option menu[MAIN_OPT];
	Option orderMenu[ORDER_OPT];
	Option modMenu[MOD_OPT];
	//Setear opciones del menu principal
	setOption('1', "Alta de almuno/a", menu, 0);
	setOption('2', "Listar alumnos", menu, 1);
	setOption('3', "Eliminar registro", menu, 2);
	setOption('4', "Modificar registro", menu, 3);
	setOption('5', "Ordenar registros", menu, 4);
	setOption('6', "Salir", menu, 5);
	//Setear opciones del menu de ordenamiento
	setOption('a', "Ordenar por legajo", orderMenu, 0);
	setOption('b', "Ordenar por apellido", orderMenu, 1);
	setOption('c', "Ordenar por promedio", orderMenu, 2);
	setOption('x', "Volver al menu", orderMenu, 3);
	//Setear opciones del menu de modificiacion
	setOption('a', "Sexo", modMenu, 0);
	setOption('b', "Edad", modMenu, 1);
	setOption('c', "Nota 1", modMenu, 2);
	setOption('d', "Nota 2", modMenu, 3);
	setOption('e', "Apellido", modMenu, 4);
	setOption('x', "Volver al menu", modMenu, 5);
	do {
		clearConsole();
		printf("---------------Menu Estudiantes----------");
		printMenu(menu, MAIN_OPT);
		printf("\n\n Elija una opcion: ");
		__fpurge(stdin);
		scanf("%c", &confirm);
	} while (count < STD_AMOUNT && !(confirm == '6'));

	return EXIT_SUCCESS;
}
void clearConsole() {
#ifdef _WIN32
system("cls");
#endif
#ifdef __linux__
system("clear");
#endif
}
