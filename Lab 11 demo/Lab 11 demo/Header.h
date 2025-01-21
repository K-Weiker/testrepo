#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//struct creation
typedef struct employee { //stores employee information 
	char name[100];
	char role;
	double payrate;
	double hours;
	double total_pay;

}Employee;
typedef struct stats { //stores stats to print to file
	double max;
	double min;
	double avg;
	double sum;
}Stats;


void RunFunction(void); //runs the function
void calc_pay(Employee* e);
void max_and_min(Employee* e, Stats *s, int n);