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
#define AMOUNT 20
#define REGISTERS 5

typedef struct {
	int docket;
	char gender;
	int age;
	int score1;
	int score2;
	int scoreAvg;
	char surname[AMOUNT];
} Student;

int main(void) {
	int inputDocket;
	char inputGender;
	int inputAge;
	int inputScore1;
	int inputScore2;
	char inputSurname[AMOUNT];
	Student students[REGISTERS];
	initializeString(students,REGISTERS);
	char confirm;
	char count = 0;
	do {
		printf("Datos del alumno: ");
		printf("\nLegajo: ");
		__fpurge(stdin);
		scanf("%d", &inputDocket);
		students[count].docket = inputDocket;
		printf("\nSexo: ");
		__fpurge(stdin);
		scanf("%c", &inputGender);
		students[count].gender = inputGender;
		printf("\nEdad: ");
		__fpurge(stdin);
		scanf("%d", &inputAge);
		students[count].age = inputAge;
		printf("\nNota 1: ");
		__fpurge(stdin);
		scanf("%d", &inputScore1);
		students[count].score1 = inputScore1;
		printf("\nNota 2: ");
		__fpurge(stdin);
		scanf("%d", &inputScore2);
		students[count].score2 = inputScore2;
		count++;
		system("clear");
		printf("Cargar otro estudiante?s/n");
		__fpurge(stdin);
		scanf("%c",&confirm);

	} while (count < REGISTERS && !(confirm == 'n'));
	return EXIT_SUCCESS;
}
