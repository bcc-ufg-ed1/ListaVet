#include<stdio.h>
#include<stdlib.h>
#include "ListaVet.h"

ListaVet* criarLista() {
    ListaVet* lista = malloc(sizeof(*lista));
    if (lista == NULL)
        return NULL;
    lista->ultimo = 0;
    return lista;
}

int liberarLista(ListaVet* lista) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    free(lista);
    lista = NULL;
    return OK;
}

int estahCheia(ListaVet* lista) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (lista->ultimo == TAM_MAX) return TRUE;
    else return FALSE;
}

int estahVazia(ListaVet* lista) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (lista->ultimo == 0) return TRUE;
    else return FALSE;
}

/*
* Esta função verifica se o valor do parâmetro "pos"
* está dentro do intervalo permitido para manipular
* uma lista. O parâmetro "incluiUltimo" indica se o valor
* "lista->ultimo" deve ser incluído ou não na verificação.
* Por exemplo, a função verifica se "pos <= lista->ultimo"
* caso o valor do parâmetro "incluiUltimo" seja TRUE e
  verifica se "pos < lista->ultimo", caso contrário.
*/
int verificaIndice(ListaVet* lista, int pos, int incluiUltimo) {
    if (pos < 0)
        return FALSE;
    if ((incluiUltimo) && (pos > lista->ultimo))
        return FALSE;
    if ((!incluiUltimo) && (pos >= lista->ultimo))
        return FALSE;
    return TRUE;
}

int inserir(ListaVet* lista, int item, int pos) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahCheia(lista))
        return ESTRUTURA_CHEIA;
    if (!verificaIndice(lista, pos, TRUE))
        return INDICE_INVALIDO;

    // Desloca elementos para a direita.
    for(int i = lista->ultimo; i > pos; i--)  {
        lista->itens[i] = lista->itens[i - 1];
    }
    lista->itens[pos] = item;
    lista->ultimo++;
    return OK;
}

int remover(ListaVet* lista, int* item, int pos) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(lista))
        return ESTRUTURA_VAZIA;
    if (!verificaIndice(lista, pos, FALSE))
        return INDICE_INVALIDO;

    *item = lista->itens[pos];

    // Desloca elementos para a esquerda.
    for(int i = pos; i < (lista->ultimo - 1); i++)  {
        lista->itens[i] = lista->itens[i + 1];
    }
    lista->ultimo--;
    return OK;
}

int obterElemento(ListaVet* lista, int* item, int pos) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(lista))
        return ESTRUTURA_VAZIA;
    if (!verificaIndice(lista, pos, FALSE))
        return INDICE_INVALIDO;

    *item = lista->itens[pos];
    return OK;
}

int obterTamanho(ListaVet* lista, int* tam) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    *tam = lista->ultimo;
    return OK;
}

