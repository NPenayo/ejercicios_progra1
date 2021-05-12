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
#include "arrays.h"
#include "menu.h"
#include "validations.h"
#include "student.h"
#include <stdio_ext.h>
#define REGISTERS 10
#define DEGREES_AMOUNT 3
#define STD_AMOUNT 5
#define MAIN_OPT 6
#define ORDER_OPT 4
#define MOD_OPT 7
#define MAX_ATTEMPTS 3
void clearConsole();
int main(void) {
	Student student;
	Student students[REGISTERS];
	Degree degrees[DEGREES_AMOUNT] = { { 1, "Programacion", 0 }, { 2,
			"Electromecanica", 0 }, { 3, "Electricidad", 0 } };
	//Inicializar array de alumnos
	initializeStudents(students, REGISTERS);
	//Declarar variables
	char opt_input;
	int empty_register = 0;
	char confirm;
	char valid_confirms[3] = { 's', 'n', 'x' };
	char sexValues[2] = { 'f', 'm' };
	int aux = 0;
	int attempts;
	char auxStr[20];
	initializeChar(auxStr);
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
	setOption('f', "Carrera", modMenu, 5);
	setOption('x', "Volver al menu", modMenu, 6);

	do {
		clearConsole();
		printf("\n---------------Menu Alumnos----------");
		printMenu(menu, MAIN_OPT);
		printf("\nElija una opcion: ");
		__fpurge(stdin);
		scanf("%c", &opt_input);
		if (getOption(opt_input, menu, MAIN_OPT)) {
			switch (opt_input) {
			case '1':
				clearConsole();
				do {
					if (getUnassigned(students, REGISTERS, &empty_register)) {
						createStudent(students, REGISTERS, empty_register,
								degrees, DEGREES_AMOUNT);
						do {
							aux =
									validChar(
											"¿Desea cargar los datos de otro/a alumno/a?(s/n)",
											"Error.Opcion invalida", &confirm,
											valid_confirms, 3, MAX_ATTEMPTS);
						} while (!aux);

					} else {
						printf(
								"\nBase completa. Si desea cargar un/a nuevo/a alumno/a debe eliminar un registro.");
						break;
					}
				} while (!(confirm == 'n'));

				break;
			case '2':
				aux = 0;
				for (int i = 0; i < REGISTERS; i++) {
					if (!students[i].assigned) {
						aux++;
					}
				}
				if (aux == REGISTERS) {
					printf("\nNo hay registros de alumnos cargados.");
					printf("\n\nPresione una tecla para volver atras.");
					__fpurge(stdin);
					getchar();
				} else {
					system("clear");
					indexStudents(students, REGISTERS, degrees, DEGREES_AMOUNT);
					printf("\n\nPresione una tecla para volver atras.");
					__fpurge(stdin);
					getchar();
				}
				break;
			case '3':
				aux = 0;
				attempts = 0;
				if (isEmpty(students, REGISTERS)) {
					printf("\nNo hay registros de alumnos cargados.");
					printf("\n\nPresione una tecla para volver atras.");
					__fpurge(stdin);
					getchar();
				} else {
					do {
						indexStudents(students, REGISTERS, degrees,
						DEGREES_AMOUNT);
						printf("\n\nNumero de legajo: ");
						__fpurge(stdin);
						scanf("%d", &aux);
						if (getStudentByDocket(students, REGISTERS, aux,
								degrees,
								DEGREES_AMOUNT, &student)) {
							printf(
									"\n¿Seguro que desea eliminar el siguiente registro?");
							showStudent(student, degrees, DEGREES_AMOUNT);
							if (validChar("s/n", "Error.Opcion invalida",
									&opt_input, valid_confirms, 3, MAX_ATTEMPTS)
									&& !(opt_input == 'n')) {
								if (deleteStudent(student, students,
								REGISTERS)) {
									printf(
											"\nRegistro eliminado exitosamente.Presione un boton para volver ");
									__fpurge(stdin);
									getchar();
								}
							}
						} else {
							clearConsole();
							printf("\nNumero de legajo no encontrado");
							attempts++;
						}
					} while (attempts < MAX_ATTEMPTS);
				}
				break;
			case '4':

				aux = 0;
				attempts = 0;
				if (isEmpty(students, REGISTERS)) {
					printf("\nNo hay registros de alumnos cargados.");
					printf("\n\nPresione una tecla para volver atras.");
					__fpurge(stdin);
					getchar();
				} else {
					do {
						indexStudents(students, REGISTERS, degrees,
						DEGREES_AMOUNT);
						printf("\n\nNumero de legajo: ");
						__fpurge(stdin);
						scanf("%d", &aux);
						if (getStudentByDocket(students, REGISTERS, aux,
								degrees, DEGREES_AMOUNT, &student)) {
							do {
								clearConsole();
								printf(
										"\n**************** MENU EDITAR ALUMNO/A *************");
								printMenu(modMenu, MOD_OPT);
								printf("\n\n Editar: ");
								scanf("%c", &opt_input);
								if (getOption(opt_input, modMenu, MOD_OPT)) {

									switch (opt_input) {
									case 'a':
										clearConsole();
										printf("\nSexo actual: %c",
												student.gender);
										if (validChar("Nuevo sexo(f/m):",
												"Error.Dato ingresado incorrecto",
												&student.gender, sexValues, 2,
												MAX_ATTEMPTS)) {
											updateStudent(student, students,
											REGISTERS);
											printf(
													"\nModificado exitosamente!");
										}
										break;
									case 'b':
										clearConsole();
										printf("\nEdad actual: %d",
												student.age);
										if (validInt("Nueva edad(+18):",
												"Error. La edad ingresada es invalida",
												&student.age, 18, 70,
												MAX_ATTEMPTS)) {
											updateStudent(student, students,
											REGISTERS);
											printf(
													"\nModificado exitosamente!");
										}
										break;
									case 'c':
										clearConsole();
										printf("\nNota 1 actual: %d",
												student.score1);
										if (validInt("Nota 1 (1-10): ",
												"Error. Nota invalida",
												&student.score1, 1, 10,
												MAX_ATTEMPTS)) {
											updateStudent(student, students,
											REGISTERS);
											printf(
													"\nModificado exitosamente!");
										}
										break;
									case 'd':
										clearConsole();
										printf("\nNota 2 actual: %d",
												student.score2);
										if (validInt("Nota 1 (1-10): ",
												"Error. Nota invalida",
												&student.score1, 1, 10,
												MAX_ATTEMPTS)) {
											updateStudent(student, students,
											REGISTERS);
											printf(
													"\nModificado exitosamente!");
										}
										break;
									case 'e':
										clearConsole();
										printf("\nApellido actual: %s",
												student.surname);
										if (appendToString("Nuevo apellido",
												student.surname, 20)) {
											updateStudent(student, students,
											REGISTERS);
											printf(
													"\nModificado exitosamente!");
										}
										break;
									case 'f':
										clearConsole();
										getDescription(degrees, DEGREES_AMOUNT,
												student.id_degree, auxStr);
										printf("\nCarrera actual: %s", auxStr);
										if (validDegree(degrees, DEGREES_AMOUNT,
												&student.id_degree,
												MAX_ATTEMPTS)) {
											updateStudent(student, students,
											REGISTERS);
											printf(
													"\nModificado exitosamente!");
										}
										break;

									}
								} else {
									printf("Error.Opcion inválida");
									attempts++;
								}
							} while (!(opt_input == 'x')
									&& attempts <= MAX_ATTEMPTS);

						} else {
							clearConsole();
							printf("\nNumero de legajo no encontrado");
							attempts++;
						}

					} while (!(opt_input == 'x') && attempts <= MAX_ATTEMPTS);
				}
				break;
			case '5':
				aux = 0;
				attempts = 0;
				if (isEmpty(students, REGISTERS)) {
					printf("\nNo hay registros de alumnos cargados.");
					printf("\n\nPresione una tecla para volver atras.");
					__fpurge(stdin);
					getchar();
				} else {
					do {
						clearConsole();
						printf("*********** ORDENAR REGISTROS ***********");
						printMenu(orderMenu, ORDER_OPT);
						__fpurge(stdin);
						printf("\nElegir opcion: ");
						scanf("%c", &opt_input);
						if (getOption(opt_input, orderMenu, ORDER_OPT)) {
							orderBy(students, REGISTERS, degrees, DEGREES_AMOUNT, opt_input, 'a');
						} else {
							printf("Error.Opcion inválida");
							attempts++;
						}

					} while (!(opt_input == 'x') && attempts <= MAX_ATTEMPTS);
				}
				break;

			}
		} else {
			clearConsole();
			printf("\nOpción invalida. Presione una tecla para volver al menu");
			__fpurge(stdin);
			getchar();
		}
	} while (!(opt_input == '6'));

	return EXIT_SUCCESS;
}
/**
 * @brief Limpia la consola
 *
 */
void clearConsole() {
#ifdef _WIN32
	system("cls");
#endif
#ifdef __linux__
	system("clear");
#endif
}
