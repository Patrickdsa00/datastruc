#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int main (){
 	Aluno aluno1 = {1, "Fulano", 9.0, 9.5, 10.0};
 	Aluno aluno2 = {2, "Ciclano", 3.0, 2.5, 8.0};
 	Aluno aluno3 = {3, "Belo", 9.0, 9.5, 10.0};
 	Aluno aluno4 = {4, "Felino", 3.0, 6.5, 10.0};
 	Aluno aluno5 = {5, "Canino", 3.0, 5.5, 8.0};
 	Aluno aluno6 = {6, "Osvaldino", 3.0, 5.5, 8.0};
	Aluno aluno7 = {7,"Osvaldo",2.0,3.0,8.5};
	Aluno aluno8 = {8,"Osvante",2.0,3.0,8.5};
	Aluno aluno9 = {9,"Valtair",2.0,3.0,8.5};
	
 	Lista * liX = cria_lista();
 	Lista * liY = cria_lista();

 	insere_lista_inicio(liX, aluno1);
 	insere_lista_inicio(liX, aluno2);
 	insere_lista_inicio(liX, aluno3);
 	insere_lista_inicio(liX, aluno4);
 	insere_lista_inicio(liX, aluno5);
 	insere_lista_inicio(liX, aluno6);
 	insere_lista_inicio(liX, aluno7);
 	insere_lista_inicio(liX, aluno8);
 	insere_lista_inicio(liX, aluno9);

 	insere_lista_inicio(liY, aluno1);
 	insere_lista_inicio(liY, aluno3);
 	insere_lista_inicio(liY, aluno5);
 	insere_lista_inicio(liY, aluno7);
 	insere_lista_inicio(liY, aluno9);

//	insere_lista_inicio(liX, aluno1);
//	insere_lista_inicio(liX, aluno2);
//	insere_lista_inicio(liX, aluno3);
//	insere_lista_inicio(liX, aluno4);
//
//	insere_lista_inicio(liY, aluno6);
//	insere_lista_inicio(liY, aluno7);
//	insere_lista_inicio(liY, aluno8);
//	insere_lista_inicio(liY, aluno9);

 	printf("---------- Imprime liY ----------\n");
 	imprime_lista(liY);
 	printf("---------- Fim do print ----\n");

 	printf("---------- Imprime liX ----------\n");
 	imprime_lista(liX);
 	printf("---------- Fim do print ----\n");

	Lista * flist = subtrai_listas(liX,liY);

 	printf("---------- Imprime lista resultante ----------\n");
 	imprime_lista(flist);
 	printf("---------- Fim do print ----\n");




   return 0;
}
