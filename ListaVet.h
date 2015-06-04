#ifndef LISTA_VET_H
#define LISTA_VET_H

#define TRUE 1
#define FALSE 0
#define TAM_MAX 100 // quantidade máxima de elementos suportada

#define OK 1
#define ESTRUTURA_NAO_INICIALIZADA -1
#define ESTRUTURA_VAZIA -2
#define ESTRUTURA_CHEIA -3
#define INDICE_INVALIDO -4
#define PARAMETRO_INVALIDO -5

// declaração da estrutura de uma lista.
typedef struct {
	int itens[TAM_MAX];
	int ultimo;
} ListaVet;

ListaVet* criarLista();
int liberarLista(ListaVet* lista);
int estahVazia(ListaVet* lista);
int estahCheia(ListaVet* lista);
int inserir(ListaVet* lista, int item, int pos);
int remover(ListaVet* lista, int* item, int pos);
int obterElemento(ListaVet* lista, int* item, int pos);
int obterTamanho(ListaVet* lista, int* tam);

#endif
