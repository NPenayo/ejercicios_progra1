/*
 * menu.h
 *
 *  Created on: 29 Apr 2021
 *      Author: Nicolas Alejandro Penayo
 *      Description: Mostrar un menu y funciones relacionadas
 */

#ifndef MENU_H_
#define MENU_H_

typedef struct {
	char index;
	char opt_description[50];
} Option;


/*
 * @brief Setea una opcion tipo numerica para el menu
 *
 * @param option El indicador correspondiente a la opcion para agregar al menu
 * @param opt_desciption Texto que se muestra en el menu para la opcion
 * @param menu Menu donde se va a agregar la opcion
 * @param position Posicion del array del menu donde se va a cargar la opcion
 *
 */
void setOption(char index, char description[],Option menu[],int position);
/*
 *@brief Imprime el menu en la consola
 *
 * @param menu Menu a imprimir
 * @param length Cantidad de opciones que tiene el menu
 */
void printMenu(Option menu[],int lenght);
#endif /* MENU_H_ */
