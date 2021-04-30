/*
 * menu.c
 *
 *  Created on: 29 Apr 2021
 *      Author: Nicolas Alejandro Penayo
 *      Description: Mostrar un menu y funciones relacionadas
 */

#include <stdio.h>
#include "menu.h"
#include "arrays.h"
#include <string.h>

void setOption(char option, char description[], Option menu[], int position) {
	Option newOpt;
	initializeChar(newOpt.opt_description);
	newOpt.index = option;
	strcpy(newOpt.opt_description, description);
	menu[position] = newOpt;
}
void printMenu(Option menu[], int lenght) {
	for (int i = 0; i < lenght; i++) {
		if (i == 0) {
			printf("\n\n%c - %s", menu[i].index, menu[i].opt_description);
		} else {
			printf("\n%c - %s", menu[i].index, menu[i].opt_description);
		}
	}
}
