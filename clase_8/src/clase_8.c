/******************************************************************************
 Penayo, Nicolas Alejandro 1E

 Desarrollar un programa que permita guardar los datos de 5 alumnos.
 Los datos a guardar para cada alumno: legajo, sexo, edad, nota1, nota2, promedio, apellido.

 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>
#include "arrays.h"
#define AMOUNT 5
#define NOTES 2
#define SURNAME_LENGTH 20
#define MIN 1
#define MAX 10
void addStudent();
void showMenu();
int main() {

	showMenu();
	return 0;
}
void showMenu() {
	int opcion;
	int checkOpcion;
	do {
		printf("\n****************** Menu ****************");
		printf("\n\n1. Cargar datos de alumnos");
		printf("\n2. Mostrar un estudiante");
		printf("\n3. Mostrar todos los estudia1ntes");
		printf("\n4. Ordenar por legajo");
		printf("\n5. Ordenar por apellido");
		printf("\n6. Ordenar por promedio");
		printf("\n7. Salir");
		printf("\n\nElija una opcion: ");
		__fpurge(stdin);
		checkOpcion = scanf("%d", &opcion);
		if (checkOpcion != 1 || (opcion < 1 || opcion > 7)) {
			system("clear");
			printf(
					"\nOpcion invalida. Presione cualquier tecla para volver al menu");
			__fpurge(stdin);
			getchar();
		}
		switch (opcion) {
		case 1:
			addStudent();
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;

		}
		system("clear");

	} while (opcion != 7);
}
void addStudent() {
	int docket[AMOUNT];
	int inputDocket;
	char gender[AMOUNT];
	char inputGender;
	int age[AMOUNT];
	int inputAge;
	float noteOne[AMOUNT];
	float noteTwo[AMOUNT];
	float inputNoteOne;
	float inputNoteTwo;
	float avrg[AMOUNT];
	char surname[AMOUNT][SURNAME_LENGTH];
	int count = 0;
	int input = 0;
	char confirm;
	initializeInt(docket, AMOUNT);
	initializeChar(gender);
	initializeInt(age, AMOUNT);
	initializeFloat(avrg, AMOUNT);
	initializeFloat(noteOne, AMOUNT);
	initializeFloat(noteTwo, AMOUNT);
	initializeString(surname, AMOUNT);
	do {
		system("clear");
		printf("\n--------Ingresar datos del alumno----------");
		// LEGAJO
		printf("\nLegajo: ");
		__fpurge(stdin);
		input = scanf("%d", &inputDocket);
		while (!input) {
			printf(
					"\nError!Tipo de dato invalido, el legajo debe ser numerico");
			printf("\nLegajo: ");
			__fpurge(stdin);
			input = scanf("%d", &inputDocket);
		}
		// SEXO
		printf("\nSexo: ");
		__fpurge(stdin);
		scanf("%c", &inputGender);
		while (!(inputGender == 'f' || inputGender == 'm')) {
			printf("\nError!El sexo debe ser f o m");
			printf("\nSexo: ");
			__fpurge(stdin);
			scanf("%c", &inputGender);
		}
		// EDAD
		printf("\nEdad: ");
		__fpurge(stdin);
		input = scanf("%d", &inputAge);
		while (!input || (inputAge < 0 || inputAge > 150)) {
			printf("\nError!La edad debe ser mayor a 0");
			printf("\nEdad: ");
			__fpurge(stdin);
			input = scanf("%d", &inputAge);
		}
		// NOTA 1
		printf("\nNota 1: ");
		__fpurge(stdin);
		input = scanf("%f", &inputNoteOne);
		while (!input || (inputNoteOne < 1 || inputNoteOne > 10)) {
			printf("\nError!La nota debe ser entre 1 y 10");
			printf("\nNota 1: ");
			__fpurge(stdin);
			input = scanf("%f", &inputNoteOne);
		}
		// NOTA 2
		printf("\nNota 2: ");
		__fpurge(stdin);
		input = scanf("%f", &inputNoteTwo);
		while (!input || (inputNoteTwo < 1 || inputNoteTwo > 10)) {
			printf("\nError!La nota debe ser entre 1 y 10");
			printf("\nNota 2: ");
			__fpurge(stdin);
			input = scanf("%f", &inputNoteTwo);
		}
		// APELLIDO
		printf("\nApellido: ");
		__fpurge(stdin);
		fgets(surname[count], SURNAME_LENGTH, stdin);
		while()
		if (count < AMOUNT) {
			printf("\n¿Desea cargar el dato de otro alumno? s/n");
			__fpurge(stdin);
			scanf("%c", &confirm);
			while (!(confirm == 'n' || confirm == 's')) {
				printf("\nError!¿Desea cargar el dato de otro alumno? s/n");
				__fpurge(stdin);
				input = scanf("%c", &confirm);
			}
		}
		count++;
	} while (count < AMOUNT && confirm != 'n');
}

