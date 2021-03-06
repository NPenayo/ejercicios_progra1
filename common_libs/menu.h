/**
 * menu.h
 *
 *
 *  Author: Nicolas Alejandro Penayo
 *  Description: Mostrar un menu y funciones relacionadas
 */

#ifndef MENU_H_
#define MENU_H_

typedef struct {
	char index;
	char opt_description[50];
} Option;

void setOption(char index, char description[], Option menu[], int position);

void printMenu(Option menu[], int lenght);

int getOption(char input, Option menu[], int arrLength);
#endif /* MENU_H_ */
