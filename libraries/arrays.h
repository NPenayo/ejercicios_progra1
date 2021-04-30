/*
 * arrays.h
 *
 *  Created on: Apr 22, 2021
 *      Author: Nicolas Alejandro Penayo
 */

#ifndef ARRAYS_H_
#define ARRAYS_H_
#define STRING_LENGTH 20

/**
 * @brief Insertar un dato en un array de tipo char
 *
 * @param char Dato a insertar
 * @param char[] Array donde se inserta el dato
 * @param int Largo del array
 */
void appendCharToArray(char, char[], int);

/**
 * @brief Insertar un dato en un array de tipo int
 *
 * @param int Dato a insertar
 * @param int[] Array donde se inserta el dato
 * @param int Largo del array
 */
void appendIntToArray(int, int[], int);

/**
 * @brief Insertar un dato en un array de tipo flotante
 *
 * @param float Dato a insertar
 * @param float[] Array donde se inserta el dato
 * @param int Largo del array
 */
void appendFloatToArray(float, float[], int);

/**
 * @brief Inicializa un array de caracteres
 *
 * @param char[] Array a inicializar
 * @param int Largo del array
 */
void initializeChar(char[]);
/**
 * @brief Inicializa un string
 *
 * @param char[] Array a inicializar
 * @param int Largo del array
 */
void initializeString(char[][STRING_LENGTH], int);

/**
 * @brief Inicializa un array de numeros
 *
 * @param int[] Array a inicializar
 * @param int Largo del array
 */
void initializeInt(int[], int);

/**
 * @brief Inicializa un array de tipo flotante
 *
 * @param float[] Array a inicializar
 * @param int Largo del array
 */
void initializeFloat(float[], int);
#endif /* ARRAYS_H_ */
