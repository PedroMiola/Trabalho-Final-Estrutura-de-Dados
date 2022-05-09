#include <stdlib.h>
#include <stdio.h>
#include "LSE.h"

LSE *criaLista(void)
{
    return NULL;
}

LSE *insereInicio(LSE *list, long num)
{
    LSE *novo;
    novo = (LSE*) malloc (sizeof(LSE));
    novo->num = num;

    novo->prox = list;
    list = novo;
    return list;
}

LSE *insereFinal (LSE *list, long num)
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

LSE *insereMeio (LSE *list, long num)
{
    int tamanhoLista = 0;
    LSE *novo, *aux; 
    novo = (LSE*) malloc (sizeof(LSE));
    novo->num = num;

    if (list == NULL)
    {
        novo->prox = NULL;
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

    while(tamanhoLista > 0)
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

void consultaNum (LSE *list, long num)
{
    LSE *aux; 
    aux = list;
    int i = 0;
    while (aux != NULL && aux->num != num)    
    {
        aux = aux->prox;
    }
    if(aux == NULL)
    {
        //printf("Numero nao presente");
    }
    else
    {
        //printf("Numero encontrado");
    }
}

void imprimeLista (LSE *list)
{
    LSE *aux;
    aux = list;
    int i = 1;
    while (aux != NULL)
    {
        printf("\n%d- %d", i, aux->num);
        aux = aux->prox;
        i++;
    }
}

LSE *insereInicioComp (LSE *list, long num, long long *comp)
{
    LSE *novo;
    novo = (LSE*) malloc (sizeof(LSE));
    novo->num = num;

    novo->prox = list;
    list = novo;
    return list;
}

LSE *insereFinalComp (LSE *list, long num, long long *comp)
{
    LSE *novo, *aux;
    novo = (LSE*) malloc (sizeof(LSE));
    novo->num = num;
    novo->prox = NULL;

    *comp += 1;
    if (list == NULL)
    {
        
        list = novo;
        return list;
    }

    aux = list;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
        *comp += 1;
    }
    aux->prox = novo;
    return list;
}

LSE *insereMeioComp (LSE *list, long num, long long *comp)
{
    int tamanhoLista = 0;
    LSE *novo, *aux; 
    novo = (LSE*) malloc (sizeof(LSE));
    novo->num = num;

    *comp += 1;
    if (list == NULL)
    {
        novo->prox = NULL;
        list = novo;
        return list;
    }

    aux = list;
    while (aux != NULL)
    {
        aux = aux->prox;
        tamanhoLista++;
        *comp += 1;
    }

    tamanhoLista = tamanhoLista/2;
    tamanhoLista--;
    aux = list;

    while(tamanhoLista > 0)
    {
        aux = aux->prox;
        tamanhoLista--;
        *comp += 1;
    }

    novo->prox = aux->prox;
    aux->prox = novo;
    return list;
}

void consultaNumComp (LSE *list, long num, long long *comp)
{
    LSE *aux; 
    aux = list;
    int i = 0;
    while (aux != NULL && aux->num != num)
    {            
        aux = aux->prox;
        *comp += 1;
    }
    if(aux == NULL)
    {
        //printf("Numero nao presente");
    }
    else
    {
        //printf("Numero encontrado");
    }
}