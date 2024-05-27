#include <stdio.h>
#include <stdlib.h>
#include "dynamicList.h"

void limpa(){
    getchar();
    system("cls|clear");
}

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elemento* nodo;
        while((*li) != NULL){
            // nodo = *li;
            // *li = (*li)->prox;
            // free(nodo);
            remove_lista_inicio(li);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL || lista_vazia(li))
        return 0;
    int cont = 0;
    Elemento* nodo = *li;
    while(nodo != NULL){
        cont++;
        nodo = nodo->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL) //existe?
        return 1;
    if(*li == NULL) //aponta para NULL
        return 1;
    return 0;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if(lista_vazia(li))
        return 0;
    Elemento *nodo = *li;
    *li = nodo->prox;
    free(nodo);
    return 1;
}



int insere_lista_inicio(Lista* li, Aluno al){
    if(li == NULL) //existe?
        return 0;
    Elemento* nodo;
    nodo = (Elemento*) malloc(sizeof(Elemento));
    if(nodo == NULL)
        return 0;
    nodo->dados = al;
    nodo->prox = (*li);
    *li = nodo;
    return 1;
}







void imprime_lista(Lista* li){
    if(lista_vazia(li) || li==NULL)
        return;
    Elemento* nodo = *li;
    while(nodo != NULL){
        imprime_aluno(&nodo->dados);
        nodo = nodo->prox;
    }
}

void imprime_aluno(Aluno* al){
    if(al == NULL)
        return;
    printf("Matricula: %d\n",al->matricula);
    printf("Nome: %s\n",al->nome);
    printf("Notas: %f %f %f\n",al->n1,
                               al->n2,
                               al->rec);
    printf("-------------------------------\n");
}

Aluno consulta_lista_pos(Lista* li, int pos){
	if(lista_vazia(li) || li == NULL){
		Aluno nao_encontrado = {-1,"nao encontrado",0.0,0.0,0.0};
		return nao_encontrado;
		}
	Elemento * nodo = *li;
	Aluno aux;
	int count_pos = 0;
	while(nodo != NULL){
		aux = nodo->dados;
		if(count_pos == pos){
			return aux;
		}else{
			nodo = nodo -> prox;
			count_pos++;
			continue;
		}

	}
}


Lista * inverte_lista_2(Lista * li){
	if(lista_vazia(li) || li == NULL){
		return NULL;
		}

	Elemento * nodo = *li;
	Lista * new_li = cria_lista();
	Aluno aluno_aux;

	while(nodo != NULL){
		aluno_aux = nodo->dados;
		insere_lista_inicio(new_li, aluno_aux);
		nodo = nodo->prox;
		remove_lista_inicio(li);
	}

	return new_li;

}

Aluno consulta_lista_matricula(Lista* li, int matricula){
	if(lista_vazia(li) || li == NULL){
		Aluno nao_encontrado = {-1,"nao encontrado",0.0,0.0,0.0};
		return nao_encontrado;
		}
	Elemento * nodo = *li;
	Aluno aux;
	while(nodo != NULL){
		aux = nodo->dados;
		if(matricula == nodo->dados.matricula ){
			return aux;
		}else{
			nodo = nodo -> prox;
			continue;
		}

	}
}
