#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

ABP* criaArvore()
{
    return NULL;
}

void imprimeArvore(ABP *arv , int nivel)
{
    int x;

    if (arv != NULL)
    {
        for (x = 1; x <= nivel; x++)
            printf("=");

        printf("%li\n", arv->info);

        if (arv->esq != NULL)
            imprimeArvore(arv->esq, (nivel + 1));
        if (arv->dir != NULL)
            imprimeArvore(arv->dir, (nivel + 1));
    }
}

ABP* insereArvoreComp(ABP *arv, long int chave, long long int *comp)
{
    ABP *novo;
    novo = (ABP*) malloc(sizeof(ABP));
    novo->info = chave;
    novo->dir = NULL;
    novo->esq = NULL;

    *comp += 1;
    if(arv == NULL)
        arv = novo;
    else
    {
        ABP *atual = arv;
        ABP *ant = NULL;

        while(atual != NULL)
        {
            ant = atual;

            if (chave >= atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;

            *comp += 2;
        }

        *comp += 1;
        if(chave >= ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }

    return arv;
}

ABP* consultaABP(ABP *arv, long int chave)
{
    while (arv != NULL)
    {
        if (chave == arv->info)
            return arv;
        else
            if (chave >= arv->info)
                arv = arv->esq;
            else
                arv = arv->dir;
    }
    return NULL;
}

ABP* consultaCompABP(ABP *arv, long int chave, long long int *comp)
{
    while (arv != NULL)
    {
        if (chave == arv->info)
            return arv;
        else
        {
            *comp += 1;
            if (chave >= arv->info)
                arv = arv->esq;
            else
                arv = arv->dir;
        }

        *comp += 2;
    }
    return NULL;
}

ABP* consultaOrdenadaInicioABP(ABP *arv)
{
    return arv;
}

ABP* consultaOrdenadaInicioCompABP(ABP *arv, long long int *comp)
{
    return arv;
}

ABP* consultaOrdenadaMeioABP(ABP *arv, int long qDados)
{
    int i;

    if (arv->dir == NULL)               //arvore decrescente
    {
        for (i = 0; i < qDados/2; i++)
            arv = arv->esq;
    }
    else                                //arvore crescente
    {
        for (i = 0; i < qDados/2; i++)
            arv = arv->dir;
    }

    return arv;
}

ABP* consultaOrdenadaMeioCompABP(ABP *arv, int long qDados, long long int *comp)
{
    int i;

    *comp += 1;
    if (arv->dir == NULL)               //arvore decrescente
    {
        for (i = 0; i < qDados/2; i++)
        {
            arv = arv->esq;
            *comp += 1;
        }
    }
    else                                //arvore crescente
    {
        for (i = 0; i < qDados/2; i++)
        {
            arv = arv->dir;
            *comp += 1;
        }
    }

    return arv;
}

ABP* consultaOrdenadaFimABP(ABP *arv, int long qDados)
{
    int i;

    if(arv->dir == NULL)    //arvore decrescente
    {
        for (i = 0; i < qDados - 1; i++)
            arv = arv->esq;
    }
    else                    //arvore crescente
    {
        for (i = 0; i < qDados - 1; i++)
            arv = arv->dir;
    }

    return arv;
}

ABP* consultaOrdenadaFimCompABP(ABP *arv, int long qDados, long long int *comp)
{
    int i;

    *comp += 1;
    if(arv->dir == NULL)    //arvore decrescente
    {
        for (i = 0; i < qDados - 1; i++)
        {
            arv = arv->esq;
            *comp += 1;
        }
    }
    else                    //arvore crescente
    {
        for (i = 0; i < qDados - 1; i++)
        {
            arv = arv->dir;
            *comp += 1;
        }
    }

    return arv;
}

void destroiArvore(ABP* arv)
{
    if (arv == NULL)
        return;
    else
    {
        destroiArvore(arv->esq);
        destroiArvore(arv->dir);
        free(arv);
    }
}
