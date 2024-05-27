#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int main (){
 	Aluno aluno1 = {1, "Fulano", 9.0, 9.5, 10.0};
 	Aluno aluno2 = {2, "Ciclano", 3.0, 2.5, 8.0};
 	Aluno aluno3 = {3, "Beltrano", 6.0, 9.5, 10.0};
 	Aluno aluno4 = {4, "Felino", 3.0, 6.5, 10.0};
 	Aluno aluno5 = {5, "Canino", 3.0, 5.5, 8.0};
 	Aluno aluno6 = {6, "Carnivoro", 7.0, 9.5, 10.0};
	Aluno aluno7 = {7,"Osvaldo",2.0,3.0,8.5};
	Aluno aluno8 = {8,"Osvante",2.0,3.0,8.5};
	
 	Lista * liX = cria_lista();

	insere_lista_inicio(liX, aluno8);
	insere_lista_inicio(liX, aluno7);
 	insere_lista_inicio(liX, aluno6);
 	insere_lista_inicio(liX, aluno5);
 	insere_lista_inicio(liX, aluno4);
 	insere_lista_inicio(liX, aluno3);
 	insere_lista_inicio(liX, aluno2);
 	insere_lista_inicio(liX, aluno1);

 	printf("---------- Imprime liX ----------\n");
 	imprime_lista(liX);
 	printf("---------- Fim do print liX ----\n");

 	printf("---------- Imprime sublista ----------\n");
	Lista * sublist = sub_lista(liX,2,5);
 	imprime_lista(sublist);
 	printf("---------- Fim do print sublist ----\n");
	
	libera_lista(liX);
	libera_lista(sublist);
   return 0;
}
