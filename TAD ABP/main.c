#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "ABP.h"

#define QDADOS 50000

int main()
{
    clock_t start, end;
    double tempo;
    long long int comp = 0;
    ABP *nodoConsultado = criaArvore();
    ABP *arv1 = criaArvore(), *arv2 = criaArvore();

    printf("=======================TEMPO E COMPARACOES PARA CARREGAR E INSERIR A BASE DE DADOS EM UMA ARVORE ORDENADA=======================\n\n");

    comp = 0;
    start = clock();
    for (int i = 0; i < QDADOS; i++)
        arv1 = insereArvoreComp(arv1, i + 1, &comp);
    end = clock();
    tempo = ((double) (end - start));
    printf("Comparacoes para carregar e inserir %li dados ordenados: %lli\n", QDADOS, comp);
    printf("Tempo para carregar e inserir %li dados ordenados (ms): %.2lf\n", QDADOS, tempo);

    printf("\n=======================VALOR, TEMPO, E COMPARACOES DA CONSULTA NO INICIO DA ARVORE ORDENADA=======================\n\n");

    comp = 0;
    nodoConsultado = consultaOrdenadaInicioCompABP(arv1, &comp);
    printf("Valor consultado no inicio: %li\n", nodoConsultado->info);
    printf("Numero de comparacoes no inicio: %lli\n", comp);

    start = clock();
    nodoConsultado = consultaOrdenadaInicioABP(arv1);
    end = clock();
    tempo = ((double) (end - start));
    printf("Tempo gasto na execucao (ms): %.2lf\n", tempo);

    printf("\n=======================VALOR, TEMPO, E COMPARACOES DA CONSULTA NO MEIO DA ARVORE ORDENADA=======================\n\n");

    comp = 0;
    nodoConsultado = consultaOrdenadaMeioCompABP(arv1, QDADOS, &comp);
    printf("Valor consultado no meio: %li\n", nodoConsultado->info);
    printf("Numero de comparacoes no meio: %lli\n", comp);

    start = clock();
    nodoConsultado = consultaOrdenadaMeioABP(arv1, QDADOS);
    end = clock();
    tempo = ((double) (end - start));
    printf("Tempo gasto na execucao (ms): %.2lf\n", tempo);

    printf("\n=======================VALOR, TEMPO, E COMPARACOES DA CONSULTA NO FIM DA ARVORE ORDENADA=======================\n\n");

    comp = 0;
    nodoConsultado = consultaOrdenadaFimCompABP(arv1, QDADOS, &comp);
    printf("Valor consultado no fim: %li\n", nodoConsultado->info);
    printf("Numero de comparacoes no fim: %lli\n", comp);

    start = clock();
    nodoConsultado = consultaOrdenadaFimABP(arv1, QDADOS);
    end = clock();
    tempo = ((double) (end - start));
    printf("Tempo gasto na execucao (ms): %.2lf\n", tempo);

    printf("\n=======================TEMPO E COMPARACOES PARA CARREGAR E INSERIR A BASE DE DADOS EM UMA ARVORE ALEATORIA=======================\n\n");

    srand(time(NULL));
    comp = 0;
    start = clock();
    for (int i = 0; i < QDADOS; i++)
        arv2 = insereArvoreComp(arv2, (rand() % QDADOS), &comp);
    end = clock();
    tempo = ((double) (end - start));
    printf("Comparacoes para carregar e inserir %li dados aleatorios: %lli\n", QDADOS, comp);
    printf("Tempo para carregar e inserir %li dados aleatorios (ms): %.2lf\n", QDADOS, tempo);

    printf("\n=======================CONSULTA DE 10 VALORES ALEATORIOS=======================\n\n");

    //Sleep(10000);
    //srand(time(NULL));
    int aleatorio;
    double mediaTempo = 0;
    for (int i = 0; i < 10; i++)
    {
        aleatorio = rand() % QDADOS;
        start = clock();
        nodoConsultado = consultaABP(arv2, aleatorio);
        end = clock();
        tempo = ((double) (end - start));
        mediaTempo += tempo;

        if(nodoConsultado == NULL)
            printf("Tempo %d da consulta de valor %li (ms): %.2lf (Nao encontrado na arvore)\n", i + 1, aleatorio, tempo);
        else
            printf("Tempo %d da consulta de valor %li (ms): %.2lf\n", i + 1, aleatorio, tempo);

        comp = 0;
        nodoConsultado = consultaCompABP(arv2, aleatorio, &comp);
        printf("Numero de comparacoes: %lli\n\n", comp);
    }
    printf("MEDIA DE TEMPO DAS 10 CONSULTAS ALEATORIAS (ms): %.2lf\n", mediaTempo/10);

    return 0;
}
