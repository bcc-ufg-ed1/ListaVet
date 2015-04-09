#include "ListaVet.h"

void imprimir(ListaVet* lista) {
    int qtdeElementos;
    obterTamanho(lista, &qtdeElementos);
    printf("[");
    int i;
    for(i = 0;i < qtdeElementos; i++) {
        int el;
        obterElemento(lista, &el, i);
        printf(" %d ", el);
    }
    printf("]\n");
}

int main() {
    ListaVet* minhaLista = criarLista();

    // insere o 7 no início da lista {7}
    inserirInicio(minhaLista, 7);

    // insere o 9 no fim da lista {7, 9}
    int tam;
    obterTamanho(minhaLista, &tam);
    inserirFim(minhaLista, 8);


    inserirFim(minhaLista, 9);
    imprimir(minhaLista);
    int i,x=-1;

    obterPosicao(minhaLista,&x,8);
    printf("posiçao = %d\n",x);

    obterElemento(minhaLista,&i,1);
    printf("elemento = %d\n",i);

    // remove o elemento final {8, 9}
    removerFinal(minhaLista, &i);
    printf("Elemento removido: %d\n", i);
    imprimir(minhaLista);

    //obtem o tamanho da lista
    obterTamanho(minhaLista, &tam);
    printf("tamanho lista = %d\n",tam);
    //remove o primeiro
    removerInicio(minhaLista, &i);
    printf("Elemento removido: %d\n", i);
    imprimir(minhaLista);

    // remove o primeiro
    removerInicio(minhaLista, &i);
    printf("Elemento removido: %d\n", i);
    imprimir(minhaLista);

}

