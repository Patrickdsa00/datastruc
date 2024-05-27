#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int main(){
	int i;
	Date birthday[2];
	Date * birthday_ptr = NULL;
	birthday_ptr = birthday;

	Time alarm[2];
	Time * alarm_ptr = NULL;
	alarm_ptr = alarm;

	Person homies[2];
	Person * homies_ptr = NULL;
	homies_ptr = homies;
	
	printf("#################################################################################");
	printf("\n######                                                                      #####");
	printf("\n###########DATE ADT                                                         #####");
	printf("\n######                                                                      #####");
	printf("\n#################################################################################");

	for (i=0; i<2; i++){
		read_date(birthday_ptr+i);	
	}

	for (i=0; i<2; i++){
		print_date(birthday_ptr+i);	
	}

	printf("#################################################################################");
	printf("\n######                                                                      #####");
	printf("\n###########TIME ADT                                                         #####");
	printf("\n######                                                                      #####");
	printf("\n#################################################################################");

	for (i=0; i<2; i++){
		read_time(alarm_ptr+i);	
	}

	for (i=0; i<2; i++){
		print_time(alarm_ptr+i);	
	}

	printf("\n#################################################################################");
	printf("\n######                                                                      #####");
	printf("\n###########PERSON ADT                                                       #####");
	printf("\n######                                                                      #####");
	printf("\n#################################################################################");

	for (i=0; i<2; i++){
		read_person(homies_ptr+i);	
	}

	for (i=0; i<2; i++){
		print_person(homies_ptr+i);	
	}

	printf("\n%i",(countMonthDates(birthday, 2, 5)));
	printf("\n%i",countAfterHourAppointments(alarm,2,18));
	printf("\n%.2f",imcMedia(homies, 2));
	
	printf("\n---Pessoa mais nova\n");
	print_person(youngestPerson(homies, 2));
	printf("\n---Pessoa mais baixa\n");
	print_person(shortestPerson(homies, 2));










	return 0;
}


