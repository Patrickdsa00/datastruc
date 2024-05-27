#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "staticList.h"

Lista* cria_lista(){
	Lista *li;
	li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL)
		li->qtd = 0;
	return li;
}

Lista * libera_lista(Lista* li){
	free(li);
	li = NULL;
	return li;
}

int tamanho_lista(Lista* li){
	if(li == NULL)
		return -1;
	else
		return li->qtd;
}

int lista_cheia(Lista* li){
	if(li == NULL)
		return -1;
	return (li->qtd==MAX);
}

int lista_vazia(Lista* li){
	if(li == NULL)
		return -1;
	return (li->qtd==0);
}

//return 1 in case of success
int insere_lista_final(Lista* li, Aluno al){
	if(li==NULL)
		return 0;
	if(lista_cheia(li))
		return 0;
	li->dados[li->qtd] = al;
	li->qtd++;
	return 1;
}

int remove_lista_final(Lista* li){
	if(li==NULL)
		return 0;
	if(lista_vazia(li))
		return 0;
	li->qtd--;
	return 1;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    int i;
    printf("-------------------------------\n");
    for(i=0; i< li->qtd; i++){
        printf("Matricula: %d\n",li->dados[i].matricula);
        printf("Nome: %s\n",li->dados[i].nome);
        printf("Notas: %f %f %f\n",li->dados[i].n1,
                                   li->dados[i].n2,
                                   li->dados[i].rec);
        printf("-------------------------------\n");
    }
}

Aluno * query_idx(Lista * li, int pos){
	Aluno * al = malloc(sizeof(Aluno));
	if(pos < li->qtd){
		al->matricula = li->dados[pos].matricula;
		strcpy(al->nome, li->dados[pos].nome);
		al->n1 = li->dados[pos].n1;
		al->n2 = li->dados[pos].n2;
		al->rec = li->dados[pos].rec;
		return al;
	}else{
		return NULL;
	}
}

Aluno * query_mat(Lista * li, int mat){
	Aluno * al = malloc(sizeof(Aluno));
	int i,flag=1;
	for(i=0;i<li->qtd;i++){
		if(li->dados[i].matricula == mat){
			* al = li->dados[i];
			flag=0;
			break;
		}else{
			flag=1;
			continue;
		}
	}
	
	if (flag == 0){
		return al;
	}else{
		return NULL;
	}
}

void print_aluno(Aluno * aluno){
        printf("Matricula: %d\n",aluno->matricula);
        printf("Nome: %s\n",aluno->nome);
        printf("Notas: %f %f %f\n",aluno->n1,
                                   aluno->n2,
                                   aluno->rec);
        printf("-------------------------------\n");
}

void imprime_aprovados(Lista * li){
	int i;
	Aluno * al = malloc(sizeof(Aluno));
	
	printf("Alunos aprovados sem rec: \n");
	for(i=0;i<li->qtd;i++){
		if( (li->dados[i].n1 + li->dados[i].n2) / 2 >= 6){
			* al=li->dados[i];
			print_aluno(al);
		}else{
			continue;
		}
	}

	printf("Alunos aprovados com rec: \n");
	for(i=0;i<li->qtd;i++){
		if( li->dados[i].rec >= 6 &&  (li->dados[i].n1 + li->dados[i].n2) / 2 < 6){
			* al=li->dados[i];
			print_aluno(al);
		}else{
			continue;
		}
	}
}

float turma_media_rec(Lista * li){
	int i;
	float media,sum=0.0,count=0.0;
	for(i=0;i<li->qtd;i++){
		sum+=li->dados[i].rec;
		count++;
	}
	media=sum/count;
	return media;
}












