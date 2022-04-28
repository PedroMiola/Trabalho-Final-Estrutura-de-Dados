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

        printf("%d\n", arv->info);

        if (arv->esq != NULL)
            imprimeArvore(arv->esq, (nivel + 1));
        if (arv->dir != NULL)
            imprimeArvore(arv->dir, (nivel + 1));
    }
}

ABP* insereArvore(ABP *arv, int chave)
{
     if (arv == NULL)
     {
         arv =  (ABP*) malloc(sizeof(ABP));
         arv->info = chave;
         arv->esq = NULL;
         arv->dir = NULL;
         return arv;
     }
     else
          if (chave < arv->info)
              arv->esq = insereArvore(arv->esq,chave);
          else if (chave >= arv->info)
              arv->dir = insereArvore(arv->dir,chave);
     return arv;
}

ABP* consultaABP(ABP *arv, int chave)
{
    while (arv!=NULL)
    {
        if (arv->info == chave)
            return arv;
        else
            if (arv->info > chave)
                arv = arv->esq;
            else
                arv = arv->dir;
    }
    return NULL;
}

ABP* consultaOrdenadaPrimeiroABP(ABP *arv)
{
    return arv;
}

ABP* consultaOrdenadaMeioABP(ABP *arv, int qDados)
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

ABP* consultaOrdenadaUltimoABP(ABP *arv, int qDados)
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

void destroiNodos(ABP *arv)
{
    if (arv == NULL)
        return;
    else
    {
        destroiNodos(arv->esq);
        destroiNodos(arv->dir);
        free(arv);
    }
}

ABP* destroiArvore(ABP* arv)
{
    destroiNodos(arv);
    return NULL;
}
