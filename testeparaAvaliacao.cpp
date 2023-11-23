
#include <iostream>

typedef struct TipoItem{
    int chave;
    char nome[81];
} TipoItem;

typedef struct TipoElemento *Apontador;
typedef struct TipoElemento{
    TipoItem item;
    struct TipoElemento *prox;
} TipoElemento;
typedef struct TipoLista{
    Apontador Primeiro;
    Apontador Ultimo;
    Apontador t;
    int tamanho = 0;
} TipoLista;
TipoLista *pfl;
TipoItem *item;

void funcao()
{
    Apontador aux;
    aux = new TipoElemento;
    aux->item = *item;
    aux->prox = pfl->t;
    pfl->t = aux;
    pfl->tamanho++;
}