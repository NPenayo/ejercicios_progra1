/*
 * arrays.c
 *
 *  Created on: Apr 22, 2021
 *      Author: Nicolas Alejandro Penayo
 */
#include <string.h>
#define STRING_LENGTH 20
void initializeChar(char arr[]) {
	strcpy(arr, " ");
}
void initializeString(char arr[][STRING_LENGTH], int arrayLength) {
	strcpy(arr[STRING_LENGTH], " ");
}
void initializeInt(int arr[], int arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		arr[i] = 0;
	}
}
void initializeFloat(float arr[], int arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		arr[i] = 0;
	}
}
void appendCharToArray(char input, char arr[], int index) {
	arr[index] = input;
}
void appendIntToArray(int input, int arr[], int index) {
	arr[index] = input;
}
void appendFloatToArray(float input, float arr[], int index) {
	arr[index] = input;
}

