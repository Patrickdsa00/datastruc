/* Author: Patrick Almeida */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int main(){
	Date date;
	Time time;
	Person person;
	
	printf("#################################################################################");
	printf("\n######                                                                      #####");
	printf("\n###########DATE ADT                                                         #####");
	printf("\n######                                                                      #####");
	printf("\n#################################################################################");

	printf("\nDay: ");
	scanf("%i",&date.day);
	while(date.day > 31 || date.day <= 0){
		printf("Not a valid day number, type again: ");
		scanf("%i",&date.day);
	}
	
	printf("Month: ");
	scanf("%i",&date.month);
	while(date.month > 12 || date.month <= 0){
		printf("Not a valid month number, type again: ");
		scanf("%i",&date.month);
	}
	
	printf("Year: ");
	scanf("%i",&date.year);
	while(date.year <= 0){
		printf("Not a valid year number, type again: ");
		scanf("%i",&date.year);
	}
	
	printf("\n########### %i/%i/%i\n",date.day,date.month,date.year);

	printf("\n#################################################################################");
	printf("\n######                                                                      #####");
	printf("\n###########TIME ADT                                                         #####");
	printf("\n######                                                                      #####");
	printf("\n#################################################################################");

	printf("\nHour: ");
	scanf("%i",&time.hour);
	while(time.hour > 23 || time.hour < 0){
		printf("Not a valid hour number, type again: ");
		scanf("%i",&time.hour);
	}
	
	printf("Minute: ");
	scanf("%i",&time.minute);
	while(time.minute > 59 || time.minute < 0){
		printf("Not a valid minute number, type again: ");
		scanf("%i",&time.minute);
	}
	
	printf("Second: ");
	scanf("%i",&time.second);
	while(time.second > 59 || time.second < 0){
		printf("Not a valid second number, type again: ");
		scanf("%i",&time.second);
	}

	printf("\n########### %i:%i:%i\n",time.hour,time.minute,time.second);

	printf("\n#################################################################################");
	printf("\n######                                                                      #####");
	printf("\n###########PERSON ADT                                                       #####");
	printf("\n######                                                                      #####");
	printf("\n#################################################################################");
	
	printf("\nHeight: ");
	scanf("%f",&person.height);
	while(person.height > 3.00 || person.height < 0.1){
		printf("Not a valid height number, type again: ");
		scanf("%f",&person.height);
	}

	printf("Age: ");
	scanf("%i",&person.age);
	while(person.age > 150 || person.age < 0){
		printf("Not a valid age number, type again: ");
		scanf("%i",&person.age);
	}

	printf("Gender: ");
	scanf(" %c",&person.gender);
	while(person.gender != 'M' && person.gender != 'F'){
		printf("Not a valid gender character, type again: ");
		scanf(" %c",&person.gender);
	}

	printf("Weight: ");
	scanf("%f",&person.weight);
	while(person.weight > 1000.00 || person.weight < 0.1){
		printf("Not a valid weight number, type again: ");
		scanf("%f",&person.weight);
	}

	printf("\n########### Height: %.2fm\n",person.height);
	printf("########### Age: %i\n",person.age);
	printf("########### Gender: %c\n",person.gender);
	printf("########### Weight: %.2fkg\n",person.weight);

	return 0;
}


