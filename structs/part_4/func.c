#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

void init_date(Date * date){
	date->day = 1;
	date->month = 1;
	date->year = 1900;
}

void read_date(Date * date){
	printf("\nDay: ");
	scanf("%i",&date->day);
	while(date->day > 31 || date->day <= 0){
		printf("Not a valid day number, type again: ");
		scanf("%i",&date->day);
	}
	
	printf("Month: ");
	scanf("%i",&date->month);
	while(date->month > 12 || date->month <= 0){
		printf("Not a valid month number, type again: ");
		scanf("%i",&date->month);
	}
	
	printf("Year: ");
	scanf("%i",&date->year);
	while(date->year < 1900){
		printf("Not a valid year number, type again: ");
		scanf("%i",&date->year);
	}
}

void print_date(Date * date){
	printf("\n########### Date: %i/%i/%i\n",date->day,date->month,date->year);
}

void init_time(Time * time){
	time->hour = 0;
	time->minute = 0;
	time->second = 0;
}

void read_time(Time * time){
	printf("\nHour: ");
	scanf("%i",&time->hour);
	while(time->hour > 23 || time->hour < 0){
		printf("Not a valid hour number, type again: ");
		scanf("%i",&time->hour);
	}
	
	printf("Minute: ");
	scanf("%i",&time->minute);
	while(time->minute > 59 || time->minute < 0){
		printf("Not a valid minute number, type again: ");
		scanf("%i",&time->minute);
	}
	
	printf("Second: ");
	scanf("%i",&time->second);
	while(time->second > 59 || time->second < 0){
		printf("Not a valid second number, type again: ");
		scanf("%i",&time->second);
	}
}

void print_time(Time * time){
	printf("\n########### Time: %i:%i:%i\n",time->hour,time->minute,time->second);
}

void init_person(Person * person){
	person->height = 0.1;
	person->age = 0;
	person->gender = 'U';
	person->weight = 0.1;
}

void read_person(Person * person){
	printf("\nHeight: ");
	scanf("%f",&person->height);
	while(person->height > 3.00 || person->height < 0.1){
		printf("Not a valid height number, type again: ");
		scanf("%f",&person->height);
	}

	printf("Age: ");
	scanf("%i",&person->age);
	while(person->age > 150 || person->age < 0){
		printf("Not a valid age number, type again: ");
		scanf("%i",&person->age);
	}

	printf("Gender: ");
	scanf(" %c",&person->gender);
	while(person->gender != 'M' && person->gender != 'F'){
		printf("Not a valid gender character, type again: ");
		scanf(" %c",&person->gender);
	}

	printf("Weight: ");
	scanf("%f",&person->weight);
	while(person->weight > 1000.00 || person->weight < 0.1){
		printf("Not a valid weight number, type again: ");
		scanf("%f",&person->weight);
	}
}

void print_person(Person * person){
	printf("\n########### Height: %.2fm\n",person->height);
	printf("########### Age: %i\n",person->age);
	printf("########### Gender: %c\n",person->gender);
	printf("########### Weight: %.2fkg\n",person->weight);
}

void fullDate(Date * date){
	char months[13][10] = { {"Undefined"},
				{"Janeiro"}, 
			     	{"Fevereiro"},
				{"Março"},
				{"Abril"},
				{"Maio"},
				{"Junho"}, 
				{"Julho"}, 
				{"Agosto"}, 
				{"Setembro"}, 
				{"Outubro"}, 
				{"Novembro"}, 
				{"Dezembro"} };

	printf("\n########### Dia %i de %s de %i!\n",date->day,months[date->month],date->year);
}


void USTimePattern(Time * time){
	if(time->hour == 0){
		time->hour=12;
		printf("\n########### Padrão americano: %i:%i:%i A.M.\n",time->hour,time->minute,time->second);
	}else if(time->hour < 12){
		printf("\n########### Padrão americano: %i:%i:%i A.M.\n",time->hour,time->minute,time->second);
	}else if(time->hour == 12){
		printf("\n########### Padrão americano: %i:%i:%i P.M.\n",time->hour,time->minute,time->second);
	}else if(time->hour > 12){
		time->hour-=12;
		printf("\n########### Padrão americano: %i:%i:%i P.M.\n",time->hour,time->minute,time->second);
	}
}

float getIMC(Person * person){
	float imc = person->weight/(person->height*person->height);
	return imc;
}


int countMonthDates(Date * arrDate, int size, int month){
	int i, count=0;
	for(i=0; i<size; i++){
		if((arrDate+i)->month == month){
			count++;
		}
	}
	return count;
}

int countAfterHourAppointments(Time * arrTime, int size, int hour){
	int i, count=0;
	for(i=0; i<size; i++){
		if((arrTime+i)->hour >=hour){
			count++;
		}
	}
	return count;
}


float imcMedia(Person * arrPerson, int size){
	int i;
	float media, sum=0;
	for(i=0; i<size; i++){
		sum+=getIMC(arrPerson+i);
	}
	media=sum/size;
	return media;
}

Person * youngestPerson(Person * arrPerson, int size){
	int i;
	Person * personPTR_aux = arrPerson;
	for(i=0; i<size; i++){
	if((arrPerson+i)->age <= (personPTR_aux)->age){
		personPTR_aux = (arrPerson+i);
	}
	
	}
	return personPTR_aux;
}

Person * shortestPerson(Person * arrPerson, int size){
	int i;
	Person * personPTR_aux = arrPerson;
	for(i=0; i<size; i++){
	if((arrPerson+i)->height <= (personPTR_aux)->height){
		personPTR_aux = (arrPerson+i);
	}
	
	}
	return personPTR_aux;
}

