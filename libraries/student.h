/*
 * student.h
 *
 *  Created on: 29 Apr 2021
 *      Author: Nicolas Alejandro Penayo
 *      Description: Struct Student y funciones relacionadas
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#define AMOUNT 20
typedef struct {
	int docket;
	char gender;
	int age;
	int score1;
	int score2;
	int scoreAvg;
	char surname[AMOUNT];
	int flag;
} Student;



#endif /* STUDENT_H_ */
