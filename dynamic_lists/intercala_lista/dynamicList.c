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

void imprime_aprovados(Lista* li){
	if(lista_vazia(li) || li == NULL){
		printf("Aluno nao encontrado!");
	}
	Elemento * nodo = *li;
	Aluno aux;
	float media = 0.00;

	printf("Approved without retest: \n");
	while(nodo != NULL){
		aux = nodo->dados;
		media = (aux.n1 + aux.n2 ) / 2;
		if(media >= 6){
			imprime_aluno(&aux);
			nodo = nodo->prox;
		}else{
			nodo = nodo->prox;
			continue;
		}
	}

	nodo = *li;
	printf("Approved with retest: \n");
	while(nodo != NULL){
		aux = nodo->dados;
		media = (aux.n1 + aux.n2 ) / 2;
		if(nodo->dados.rec >= 6 && media < 6){
			imprime_aluno(&aux);
			nodo = nodo->prox;
		}else{
			nodo = nodo->prox;
			continue;
		}
	}

}

int turma_media_rec(Lista* li){
	if (lista_vazia(li) || li == NULL){
		return 1;
	}

	Elemento * nodo = *li;
	int sum_rec = 0;
	int count_rec = 0;

	while(nodo != NULL){
		sum_rec += nodo->dados.rec;
		count_rec++;
		nodo = nodo->prox;
	}

	return sum_rec/count_rec;
}

int junta_turmas(Lista* liSrc, Lista* liTgt){
	if ( (lista_vazia(liSrc) || liSrc == NULL ) && (lista_vazia(liTgt) || liTgt == NULL ) ){
		return 0;
	}

	Elemento * nodeSrc = *liSrc;
	while(nodeSrc != NULL){
		insere_lista_inicio(liTgt,nodeSrc->dados);
		nodeSrc = nodeSrc->prox;
	}

	return 1;
}

int junta_turmas2(Lista* liSrc, Lista* liTgt){
	if ( (lista_vazia(liSrc) || liSrc == NULL ) && (lista_vazia(liTgt) || liTgt == NULL ) ){
		return 0;
	}

	Elemento * nodeTgt = *liTgt;
	Elemento * nodeSrc = *liSrc;
	Elemento * nodeAux;


	while(nodeSrc != NULL){
//Como achamos a bundinha expandida e atualizada de uma lista dinamica? Iterando outro while(abaixo) dentro de outro(acima), 
//não estamos trabalhando com listas estaticos!
		while(nodeTgt->prox != NULL){
			nodeTgt = nodeTgt->prox;
		}

	nodeAux = malloc(sizeof(Elemento));
	nodeAux->dados = nodeSrc->dados;
	nodeAux->prox = NULL;
	nodeTgt->prox = nodeAux;

	nodeSrc = nodeSrc->prox;
	}

	return 1;
}

int insere_lista_final(Lista* liTgt, Aluno al){
	if(liTgt == NULL){
        	return 0;
	}else if(lista_vazia(liTgt)){
		insere_lista_inicio(liTgt,al);
		return 1;
	}else{

	Elemento * nodeTgt = *liTgt;
	Elemento * node; 

	while(nodeTgt->prox != NULL){
		nodeTgt = nodeTgt->prox;
	}

	node = malloc(sizeof(Elemento));
    	node->dados = al;
    	node->prox = NULL;
	nodeTgt->prox = node;
    	
	return 1;
	}
}

Lista* intercala_lista(Lista* liX, Lista* liY){
	if ( (lista_vazia(liX) || liX == NULL ) && (lista_vazia(liY) || liY == NULL ) ){
		return 0;
	}

	Elemento * nodeX = *liX;
	Elemento * nodeY = *liY;
	
	int szX = tamanho_lista(liX);
	int szY = tamanho_lista(liY);

	Lista * flist = (Lista*) malloc(sizeof(Lista));
	*flist = NULL;

	if(szX >= szY){	
		while(nodeY != NULL){
			insere_lista_final(flist,nodeX->dados);
			insere_lista_final(flist,nodeY->dados);
			nodeX = nodeX->prox;
			nodeY = nodeY->prox;
		}
		while(nodeX != NULL){
			insere_lista_final(flist,nodeX->dados);
			nodeX = nodeX->prox;
		}
	}else{
		while(nodeX != NULL){
			insere_lista_final(flist,nodeX->dados);
			insere_lista_final(flist,nodeY->dados);
			nodeX = nodeX->prox;
			nodeY = nodeY->prox;
		}
		while(nodeY != NULL){
			insere_lista_final(flist,nodeY->dados);
			nodeY = nodeY->prox;
		}
	}

	return flist;
}
