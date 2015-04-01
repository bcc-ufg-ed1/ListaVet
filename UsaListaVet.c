#include "ListaVet.h"

void imprimir(ListaVet* lista) {
    int qtdeElementos;
    obterTamanho(lista, &qtdeElementos);
    printf("[");
    for(int i = 0;i < qtdeElementos; i++) {
        int el;
        obterElemento(lista, &el, i);
        printf(" %d ", el);
    }
    printf("]\n");
}

int main() {
    ListaVet* minhaLista = criarLista();

    // insere o 7 no início da lista {7}
    inserir(minhaLista, 7, 0);

    // insere o 9 no fim da lista {7, 9}
    int tam;
    obterTamanho(minhaLista, &tam);
    inserir(minhaLista, 9, tam);

    // insere o 8 entre o 7 e o 9 {7, 8, 9}
    inserir(minhaLista, 8, 1);

    imprimir(minhaLista);

    int i;
    // remove o elemento da primeira posição {8, 9}
    remover(minhaLista, &i, 0);
    printf("Elemento removido: %d\n", i);
    imprimir(minhaLista);

    // remove o elemento do final da lista {8}
    obterTamanho(minhaLista, &tam);
    remover(minhaLista, &i, tam - 1);
    printf("Elemento removido: %d\n", i);
    imprimir(minhaLista);

    // remove o último elemento da lista {}
    remover(minhaLista, &i, 0);
    printf("Elemento removido: %d\n", i);
    imprimir(minhaLista);

}

