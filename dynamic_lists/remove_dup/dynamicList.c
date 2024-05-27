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

Lista* sub_lista(Lista* li, int pos_inicio, int pos_fim){
	if(lista_vazia(li) || li == NULL){
		return 0;
	}

	if( ! ( pos_inicio >= 0 && pos_fim <= tamanho_lista(li) ) ) {
		return 0;
	}

	Elemento * nodeLi = *li;
	Lista * flist = (Lista*) malloc(sizeof(Elemento));
	*flist = NULL;
	int idx=0;

	while(nodeLi != NULL){
		if( idx >= pos_inicio && idx <= pos_fim ){
			insere_lista_final(flist,nodeLi->dados);
		}
		nodeLi = nodeLi->prox;
		idx++;
	}

	return flist;

}

Lista* interseccao_lista(Lista* x, Lista* y){
	if ( (lista_vazia(x) || x == NULL ) && (lista_vazia(y) || y == NULL ) ){
		return 0;
	}

	Elemento * nodeX = *x;
	Elemento * nodeY = *y;
	Lista * flist = (Lista*) malloc(sizeof(Elemento));
	*flist = NULL;
	
	Elemento * nodeAux;
	
	while(nodeY != NULL){
		nodeX = *x;
		while(nodeX != NULL){
			if(nodeX->dados.matricula == nodeY->dados.matricula){
				nodeAux = malloc(sizeof(Elemento));
				nodeAux = nodeX;
				insere_lista_final(flist,nodeAux->dados);
			}
			nodeX = nodeX->prox;
		}
		nodeY = nodeY->prox;
	}
	
	return flist;

}

Aluno enesimo_elemento_a_partir_do_fim(Lista* li, int n){
	Aluno nao_encontrado = {-1,"nao encontrado",0.0,0.0,0.0};
	if(lista_vazia(li) || li == NULL){
		return nao_encontrado;
	}

	Elemento * nodeLi = *li;
	int szLi = tamanho_lista(li) - n;
	int idx=0;

	while(nodeLi != NULL){
		if(idx == szLi){
			return nodeLi->dados;
		}else{
			nodeLi = nodeLi->prox;
			idx++;
		}
	}

	return nao_encontrado;

}

int eh_lista_ordenada(Lista* li){
	if(lista_vazia(li) || li == NULL){
		return 0;
	}

	Elemento * nodeLi = *li;
	Elemento * nodeAux = *li;
	Elemento * nodeAuxx;
	int cnt;
	
	while(nodeLi != NULL){
		if(nodeAux->prox != NULL){
			nodeAux = nodeAux->prox;
		}

		if(nodeLi->dados.matricula <= nodeAux->dados.matricula){
			nodeLi = nodeLi->prox;
		}else{
			nodeAuxx = *li;
			cnt=0;
			while(nodeAuxx != NULL){
				if(nodeAux->dados.matricula == nodeAuxx->dados.matricula){
					cnt++;
				}
				nodeAuxx = nodeAuxx->prox;
			}
			if(cnt < 2){
				return 0;
			}else{
				nodeLi = nodeLi->prox;
			}
		}
	}
	
	return 1;

}

int remove_lista_pos(Lista* li,int pos){
	if(lista_vazia(li) || li == NULL){
		return 0;
	}

	if(pos == 0){
		remove_lista_inicio(li);
		return 1;
	}

	Elemento * nodeLi = *li;
	Elemento * nodeAux = *li;
	int idx=0;
	
	while(nodeLi != NULL){
		if(idx == pos){
			nodeAux->prox = nodeLi->prox;	
			free(nodeLi);
			return 1;
		}
		nodeAux = nodeLi;
		nodeLi = nodeLi->prox;
		idx++;
	}
	
	return 0;
}

int remove_lista_mat(Lista* li,int mat){
	if(lista_vazia(li) || li == NULL){
		return 0;
	}

	Elemento * nodeLi = *li;
	Elemento * nodeAux = *li;
	int idx=0;
	
	while(nodeLi != NULL){
		if(nodeLi->dados.matricula == mat){
			if(idx == 0){
				remove_lista_inicio(li);
				return 1;
			}else{
				nodeAux->prox = nodeLi->prox;
				free(nodeLi);
				return 1;
			}
		}
		nodeAux = nodeLi;
		nodeLi = nodeLi->prox;
		idx++;
	}
	
	return 0;
}

int remove_lista_mat_dup(Lista* li,int mat){
	if(lista_vazia(li) || li == NULL){
		return 0;
	}

	Elemento * nodeLi = *li;
	Elemento * nodeAux = *li;
	int idx=0,cnt=0;
	
	while(nodeLi != NULL){
		if(nodeLi->dados.matricula == mat){
			cnt++;
			if(cnt == 2){
				if(idx == 0){
					remove_lista_inicio(li);
					return 1;
				}else{
					nodeAux->prox = nodeLi->prox;
					free(nodeLi);
					return 1;
				}
			}
		}
		nodeAux = nodeLi;
		nodeLi = nodeLi->prox;
		idx++;
	}
	
	return 0;
}

int remove_duplicados(Lista* li){
	if( (lista_vazia(li) || li == NULL) && eh_lista_ordenada(li) != 1 ){
		return 0;
	}

	Elemento * nodeLi = *li;
	Elemento * nodeAux = *li;
	int cnt=0,qntR=0,mat;

	while(nodeLi != NULL){
		nodeAux = *li;
		cnt=0;
		while(nodeAux != NULL){
			if(nodeLi->dados.matricula == nodeAux->dados.matricula){
				cnt++;
				mat=nodeLi->dados.matricula;
			}
			
			nodeAux = nodeAux->prox;
		}
		
		nodeLi = nodeLi->prox;

		if(cnt >= 2){
			remove_lista_mat_dup(li,mat);
			qntR++;
		}

	}

	return qntR;
}

int remove_duplicados2(Lista* li){
	if( (lista_vazia(li) || li == NULL) && eh_lista_ordenada(li) != 1 ){
		return 0;
	}

	Elemento * nodeLi = *li;
	Elemento * nodeAux = *li;
	int idx=1,cnt=0,qntR=0,aux;

	while(nodeLi != NULL){
		nodeAux = *li;
		cnt=0;
		idx=1;
		while(nodeAux != NULL){
			if(nodeLi->dados.matricula == nodeAux->dados.matricula){
				cnt++;
				if(cnt == 2){
					aux = idx;
				}
			}
			
			idx++;
			nodeAux = nodeAux->prox;
		}
		
		nodeLi = nodeLi->prox;

		if(cnt >= 2){
			remove_lista_pos(li,aux-1);
			qntR++;
		}

	}

	return qntR;
}
