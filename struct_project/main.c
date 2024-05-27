#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int main(){
/* Demonstracao sem vetor
	Runner runner;
	Runner * runner_ptr = NULL;
	runner_ptr = &runner;

	printf("Corredor 1: \n");
	get_runner(runner_ptr);
	print_runner(runner_ptr); 
*/

/* Demonstracao com vetor */
	int i;
	Runner runner[2];
	Runner * runner_ptr = NULL;
	runner_ptr = runner;

	for (i=0; i<2; i++){
		printf("######### Corredor %i",i+1);
		get_runner(runner_ptr+i);
		printf("\n");
	}
	
	for (i=0; i<2; i++){
		printf("######### Corredor %i",i+1);
		print_runner(runner_ptr+i);
		printf("\n");
	}



	return 0;
}


