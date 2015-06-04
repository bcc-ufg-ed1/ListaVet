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
    if (lista->ultimo == TAM_MAX)
        return TRUE;
    return FALSE;
}

int estahVazia(ListaVet* lista) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (lista->ultimo == 0)
        return TRUE;
    return FALSE;
}

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

    if (item != NULL)
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
    if (item == NULL)
        return PARAMETRO_INVALIDO;
    *item = lista->itens[pos];
    return OK;
}

int obterTamanho(ListaVet* lista, int* tam) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (tam == NULL)
        return PARAMETRO_INVALIDO;
    *tam = lista->ultimo;
    return OK;
}
