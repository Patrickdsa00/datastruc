#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int main (){
	Lista * liSrc=NULL;
	Lista * liTgt=NULL;
	Aluno al;
	int flag;

	printf("Criar Lista...\n");
	liSrc = cria_lista();
	liTgt = cria_lista();

	printf("li=%X \n tamanho_lista = %i\n", liSrc, tamanho_lista(liSrc));
	printf("lista_cheia(li)=%i \n lista_vazia(li) = %i\n", lista_cheia(liSrc), lista_vazia(liSrc));

	printf("------------------------------\n");
	
	al.matricula = 123;
	strcpy(al.nome, "Andre del Mestre");
	al.n1=9.1;
	al.n2=9.3;
	al.rec=9.8;

	flag = insere_lista_final(liSrc, al);
	printf("inserir aluno na Lista... flag=%i\n", flag);

	al.matricula = 321;
	strcpy(al.nome, "Fulano da silva");
	al.n1=3.1;
	al.n2=4.3;
	al.rec=7.8;

	flag = insere_lista_final(liSrc, al);
	printf("inserir aluno na Lista... flag=%i\n", flag);

	al.matricula = 987;
	strcpy(al.nome, "Patrick Almeida");
	al.n1=9.1;
	al.n2=9.3;
	al.rec=9.8;

	flag = insere_lista_final(liTgt, al);
	printf("inserir aluno na Lista... flag=%i\n", flag);

	printf("liSrc content:\n");
	imprime_lista(liSrc);
	printf("liTgt content:\n");
	imprime_lista(liTgt);

	/*
	flag = remove_lista_final(li);
	printf("deletar aluno na Lista... flag=%i\n", flag);

	imprime_lista(li);
	*/

	
	printf("\nJunta turmas: %i\n",junta_turmas(liSrc, liTgt));
	liSrc = libera_lista(liSrc);

	printf("Imprime liTgt após junta turmas\n");
	imprime_lista(liTgt);

	remove_top(liTgt);
	
	printf("Imprime liTgt após remove on top\n");
	imprime_lista(liTgt);
	
	printf("\n\nLiberar a Lista...\n");
	//liSrc = libera_lista(liSrc);
	liTgt = libera_lista(liTgt);

	imprime_lista(liSrc);
    return 0;
}
