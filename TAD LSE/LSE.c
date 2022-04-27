#include <stdlib.h>
#include <stdio.h>
#include "LSE.h"

LSE *criaLista(void)
{
    return NULL;
}

LSE *insereInicio(LSE *list, int num)
{
    LSE *novo;
    novo = (LSE*) malloc (sizeof(LSE));
    novo->num = num;

    novo->prox = list;
    list = novo;
    return list;
}

LSE *insereFinal (LSE *list, int num)
{
    LSE *novo, *aux;
    novo = (LSE*) malloc (sizeof(LSE));
    novo->num = num;
    novo->prox = NULL;

    if (list == NULL)
    {
        list = novo;
        return list;
    }
    aux = list;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = novo;
    return list;
}

LSE *insereMeio (LSE *list, int num)
{
    int tamanhoLista = 0;
    LSE *novo, *aux; 
    novo = (LSE*) malloc (sizeof(LSE));
    novo->num = num;

    if (list == NULL)
    {
        novo->prox == NULL;
        list = novo;
        return list;
    }

    aux = list;
    while (aux != NULL)
    {
        aux = aux->prox;
        tamanhoLista++;
    }

    tamanhoLista = tamanhoLista/2;
    tamanhoLista--;
    aux = list;
    whilie(tamanhoLista > 0);
    {
        aux = aux->prox;
        tamanhoLista--;
    }
    novo->prox = aux->prox;
    aux->prox = novo;
    return list;
}

LSE *destroiLista (LSE *list)
{
    LSE *aux;
    while (list != NULL)
    {
        aux = list;
        list = list->prox;
        free(aux);
    }

    return NULL;
}

void consultaNum (LSE *list, int num)
{
    LSE *aux = list;
    while (aux->num != num || aux != NULL)
    {
        aux = aux->prox;
    }
    if(aux == NULL)
    {
        printf("\n\nNumero não presente");
    }
    else
    {
        printf("\n\nNumero encontrado");
    }
}

void imprimeLista (LSE *list)
{
    LSE *aux = list;
    while (aux != NULL)
    {
        printf("\n- %d", aux->num);
        aux = aux->prox;
    }
}