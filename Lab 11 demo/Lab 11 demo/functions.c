#include "Header.h"

void RunFunction(void) {
	//create instance of employee as an array of 200
	FILE* infile = fopen("Employee.txt", "r");
	Employee emp_Array[200];
	Stats employeeStats = { .avg = 0, .min = 0, .max = 0, .sum= 0 }; //stores stats for later

	
	int n = 0; // traverse through array for each instance of employee


	while (!feof(infile)) {
		fgets(emp_Array[n].name, 100, infile);
		fscanf(infile, "%c", &emp_Array[n].role);
		fscanf(infile, "%lf", &emp_Array[n].hours);
		fscanf(infile, "%lf\n", &emp_Array[n].payrate);
		
		calc_pay(&emp_Array[n]); //calculates employee total pay
		employeeStats.sum += emp_Array[n].total_pay; // adds to sum in stats struct
		max_and_min(&emp_Array[n], &employeeStats, n); //finds minimum                         
	
		++n;
		
	}
	fclose(infile);
	employeeStats.avg = employeeStats.sum / n; //find avg
	printf("Total %.2lf\n average %.2lf\n max %.2lf\n min %.2lf\n", employeeStats.sum, employeeStats.avg, employeeStats.max, employeeStats.min);


	FILE* outfile = fopen("Stats.txt", "w"); //printing stats to file
	fprintf(outfile, "Total: %.2lf\n", employeeStats.sum);  
	fprintf(outfile, "Average: %.2lf\n", employeeStats.avg);
	fprintf(outfile, "Max: %.2lf\n", employeeStats.max);
	fprintf(outfile, "Min: %.2lf\n", employeeStats.min);

	fclose(outfile);
}


void calc_pay(Employee* e) {
	if (e->hours <= 80) { //if no overtime, total pay is just rate * hours
		e->total_pay = e->payrate * e->hours;
	}
	else {
		if (e->role == 'B') { //if overtime and base employee, overtime is 1.5

			e->total_pay = (e->payrate * 80) + (e->payrate * 1.5 * (e->hours - 80));
		}
		else { //if overtime and manager, overtime is 1.8
			e->total_pay = (e->payrate * 80) + (e->payrate * 1.8 * (e->hours - 80));
		}






	}


}
void max_and_min(Employee* e, Stats *s, int n) {
	if (n == 0) { //if first data, set min and max to that value
		s->min = e->total_pay;
		s->max = e->total_pay;
	}
	else { //else see if new info is less than min and set to min if so
		if (s->min > e->total_pay) {
			s->min = e->total_pay;
		}
		else{}
		if (s->max < e->total_pay) {//same for max
			s->max = e->total_pay;
		}
		else{}
	}

}
