/* Author: Patrick Almeida */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int main(){
	Date date;
	Time time;
	Person person;

	Date * date_ptr = NULL;
	date_ptr = &date;
	
	Time * time_ptr = NULL;
	time_ptr = &time;

	Person * person_ptr = NULL;
	person_ptr = &person;

	printf("#################################################################################");
	printf("\n######                                                                      #####");
	printf("\n###########DATE ADT                                                         #####");
	printf("\n######                                                                      #####");
	printf("\n#################################################################################");

	init_date(date_ptr);
	read_date(date_ptr);
	print_date(date_ptr);
	fullDate(date_ptr);

	printf("\n#################################################################################");
	printf("\n######                                                                      #####");
	printf("\n###########TIME ADT                                                         #####");
	printf("\n######                                                                      #####");
	printf("\n#################################################################################");

	init_time(time_ptr);
	read_time(time_ptr);
	print_time(time_ptr);
	USTimePattern(time_ptr);

	printf("\n#################################################################################");
	printf("\n######                                                                      #####");
	printf("\n###########PERSON ADT                                                       #####");
	printf("\n######                                                                      #####");
	printf("\n#################################################################################");
	
	init_person(person_ptr);
	read_person(person_ptr);
	print_person(person_ptr);
	printf("\nIMC: %.2f!\n",getIMC(person_ptr));

	return 0;
}


