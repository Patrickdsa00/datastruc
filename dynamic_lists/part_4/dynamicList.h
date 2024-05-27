#ifndef DYNAMICLIST_H_INCLUDED
#define DYNAMICLIST_H_INCLUDED

// TADs
struct aluno{
	int matricula;
	char nome[30];
	float n1, n2, rec;
}typedef Aluno;


//Definição do tipo lista
struct elemento{
    Aluno dados;
    struct elemento *prox;
}typedef Elemento;

typedef Elemento* Lista;

void limpa();

//functions prototype
Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
int insere_lista_inicio(Lista* li, Aluno al);
int remove_lista_inicio(Lista* li);
void imprime_aluno(Aluno* al);
void imprime_lista(Lista* li);


int insere_lista_final(Lista* li, Aluno al);
int insere_lista_ordenada(Lista* li, Aluno al);

int tamanho_lista_recursivo(Lista* li);
void inverte_lista(Lista* li);
Lista * inverte_lista_2(Lista* li);
void inverte_lista_desafio(Lista *li);
Aluno consulta_lista_pos(Lista* li, int pos);
Lista * inverte_lista_2(Lista * li);
Aluno consulta_lista_matricula(Lista* li, int matricula);
void imprime_aprovados(Lista* li);
int turma_media_rec(Lista* li);
#endif /* DYNAMICLIST_H_INCLUDED */
