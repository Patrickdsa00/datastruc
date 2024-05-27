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
	
 	Lista * liTgt = cria_lista();
	Lista * liSrc = cria_lista();

 	printf("lista vazia litgt? %i \n", lista_vazia(liTgt));
 	printf("lista vazia lisrc? %i \n", lista_vazia(liSrc));

 	insere_lista_inicio(liTgt, aluno3);
 	insere_lista_inicio(liTgt, aluno2);
 	insere_lista_inicio(liTgt, aluno1);

 	insere_lista_inicio(liSrc, aluno6);
 	insere_lista_inicio(liSrc, aluno5);
 	insere_lista_inicio(liSrc, aluno4);

 	printf("----------------------------- \n");

 	printf("tamanho da lista litgt? %i \n", tamanho_lista(liTgt));
 	printf("tamanho da lista lisrc? %i \n", tamanho_lista(liSrc));
	printf("----------LiTgt e liSrc-------------\n");
 	imprime_lista(liTgt);
 	imprime_lista(liSrc);
 	printf("----------------------------- \n");
 	printf("junta turmas \n");
	printf("%d\n",junta_turmas2(liSrc,liTgt));
	printf("----------Libera liSrc e imprime liTgt -------------\n");
	libera_lista(liSrc);
	imprime_lista(liTgt);

	printf("----Libera litgt---\n");
	libera_lista(liTgt);
 	printf("lista vazia? %i \n", lista_vazia(liTgt));
 	//printf("tamanho da lista? %i \n", tamanho_lista(liTgt));


   return 0;
}
