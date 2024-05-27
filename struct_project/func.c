#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

void init_runner(Runner * runner, int num_runs){
	runner->num_runs = num_runs;
	runner->run_arr = malloc(sizeof(Run)*num_runs);
}

void get_runner(Runner * runner){
	int i;
	printf("\nCategoria [M/F]: ");
	scanf(" %c",&runner->gender);
	printf("\nNumero de corridas: ");
	scanf("%i",&runner->num_runs);
	
	init_runner(runner, runner->num_runs);

	for (i=0;i<runner->num_runs;i++){
		printf("\nDistancia percorrida para corrida %i: ",i+1);
		scanf("%f",&runner->run_arr[i].distance);
		printf("\nHoras gastas no percurso da corrida %i: ",i+1);
		scanf("%i",&runner->run_arr[i].hour);
		printf("\nMinutos gastos no percurso da corrida %i: ",i+1);
		scanf("%i",&runner->run_arr[i].minute);
	}

}

void print_runner(Runner * runner){
	int i;
	printf("\n#######################################################");
	printf("\nCategoria: %c",runner->gender);
	printf("\nNumero de corridas: %i",runner->num_runs);
	for (i=0;i<runner->num_runs;i++){
		printf("\n#######################################################");
		printf("\nDistancia percorrida na corrida %i: %.2f km",i+1,runner->run_arr[i].distance);
		printf("\nHoras gastas na corrida %i: %i h",i+1,runner->run_arr[i].hour);
		printf("\nMinutos gastos na corrida %i: %i m",i+1,runner->run_arr[i].minute);
		printf("\nPace da corrida %i: %.2f min/km",i+1,pace_per_run(runner,i));
		printf("\n#######################################################");
	}
	final_stat(runner);
	printf("\n#######################################################\n");
}

float pace_per_run(Runner * runner, int index){
	float hour_to_min = runner->run_arr[index].hour * 60;
	float tot_min = runner->run_arr[index].minute + hour_to_min;
	float distance = runner->run_arr[index].distance;

	return tot_min / distance; 
}

void final_stat(Runner * runner){
	int i;
	float km_sum=0, pace_sum=0;
	int hr=0,min=0;
	for (i=0;i<runner->num_runs;i++){
		km_sum+=runner->run_arr[i].distance;
		pace_sum+=pace_per_run(runner,i);
		hr+=runner->run_arr[i].hour;
		min+=runner->run_arr[i].minute;
	}
	while (min >= 60){
		min-=60;
		hr+=1;
	}
	
	if (min > 0 && hr > 0){
	printf("\nNo total, percorreu %.2f km por %i hora(s) e %i minuto(s). A media de pace foi de %.2f min/km!!!",km_sum,hr,min,pace_sum/runner->num_runs);
	}else if (min <= 0 ){
	printf("\nNo total, voce percorreu %.2f km por %i hora(s). A media de pace foi de %.2f min/km!!!",km_sum,hr,pace_sum/runner->num_runs);
	}else if (hr <= 0){
	printf("\nNo total, voce percorreu %.2f km por %i minutos(s). A media de pace foi de %.2f min/km!!!",km_sum,min,pace_sum/runner->num_runs);
	}
}

