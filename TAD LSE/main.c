#include "LSE.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 5000

int main ()
{
    LSE *listaTempo;
    LSE *listaComp;
    long long int comp = 0;
    long long tempo;
    clock_t t;

    

    listaTempo = criaLista();
    t = clock();
    for(long i = 0; i < MAX_NUM; i++)
    {
        listaTempo = insereInicio(listaTempo, i);
    }
    t = clock() - t;
    printf("\nSegundos passados para inserir %li nodos no inicio: %.2lf", MAX_NUM, ((double)t)/CLOCKS_PER_SEC);
    listaTempo = destroiLista(listaTempo);

    listaTempo = criaLista();
    t = clock();
    for(long i = 0; i < MAX_NUM; i++)
    {
        listaTempo = insereMeio(listaTempo, i);
    }
    t = clock() - t;
    printf("\nSegundos passados para inserir %li nodos no meio: %.2lf", MAX_NUM, ((double)t)/CLOCKS_PER_SEC);
    listaTempo = destroiLista(listaTempo);

    listaTempo = criaLista();
    t = clock();
    for(long i = 0; i < MAX_NUM; i++)
    {
        listaTempo = insereFinal(listaTempo, i);
    }
    t = clock() - t;
    printf("\nSegundos passados para inserir %li nodos no final: %.2lf", MAX_NUM, ((double)t)/CLOCKS_PER_SEC);

    t = clock();
    consultaNum(listaTempo, MAX_NUM-1);
    t = clock() - t;
    printf("\nSegundos passados para consultar, em uma lista de %d nodos, o nodo no final: %.2lf", MAX_NUM, ((double)t)/CLOCKS_PER_SEC);

    t = clock();
    consultaNum(listaTempo, MAX_NUM/2);
    t = clock() - t;
    printf("\nSegundos passados para consultar, em uma lista de %d nodos, o nodo no meio: %.2lf", MAX_NUM, ((double)t)/CLOCKS_PER_SEC);

    t = clock();
    consultaNum(listaTempo, 1);
    t = clock() - t;
    printf("\nSegundos passados para consultar, em uma lista de %d nodos, o nodo no inicio: %.2lf", MAX_NUM, ((double)t)/CLOCKS_PER_SEC);

    listaTempo = destroiLista(listaTempo);

    listaComp = criaLista();
    for(long i = 0; i < MAX_NUM; i++)
    {
        listaComp = insereInicioComp (listaComp, i, &comp);
    }
    printf("\n\nNumero de comps para inserir %li nodos no inicio: %lli", MAX_NUM ,comp);
    listaComp = destroiLista(listaComp);

    comp = 0;
    listaComp = criaLista();
    for(long i = 0; i < MAX_NUM; i++)
    {
        listaComp = insereMeioComp (listaComp, i, &comp);
    }
    printf("\nNumero de comps para inserir %li nodos no meio: %lli", MAX_NUM ,comp);
    listaComp = destroiLista(listaComp);

    comp = 0;
    listaComp = criaLista();
    for(long i = 0; i < MAX_NUM; i++)
    {
        listaComp = insereFinalComp (listaComp, i, &comp);
    }
    printf("\nNumero de comps para inserir %li nodos no final: %lli", MAX_NUM ,comp);

    comp = 0;
    consultaNumComp(listaComp, MAX_NUM-1, &comp);
    printf("\nNumero de comps para consultar, em uma lista de %d nodos, o nodo no final: %lli", MAX_NUM ,comp);

    comp = 0;
    consultaNumComp(listaComp, MAX_NUM/2, &comp);
    printf("\nNumero de comps para consultar, em uma lista de %d nodos, o nodo no meio: %lli", MAX_NUM ,comp);

    comp = 0;
    consultaNumComp(listaComp, 1, &comp);
    printf("\nNumero de comps para consultar, em uma lista de %d nodos, o nodo no inicio: %lli", MAX_NUM ,comp);

    listaComp = destroiLista(listaComp);



    t = clock();
    listaTempo = criaLista();
    for (long i = 0; i < MAX_NUM; i++)
    {
        listaTempo = insereInicio(listaTempo, rand()%MAX_NUM);
    }
    t = clock() - t;
    printf("\n\n\nSegundos passados para inserir %li nodos aleatorios no incio: %.2lf", MAX_NUM, ((double)t)/CLOCKS_PER_SEC);
    
    long temp;
    for(long i = 0; i < 10; i++)
    {
        temp = rand()%MAX_NUM;
        t = clock();
        consultaNum(listaTempo, -1);
        t = clock() - t;
        tempo += ((double)t/CLOCKS_PER_SEC);
        printf("\nTempo da %d consulta do numero %li: %.2llf", i+1, temp, ((double)t)/CLOCKS_PER_SEC);
    }
    printf("\nMedia de segundos passados para consultar 10 nodos, em uma lista com %d nodos, aleatoriamente: %.2lf", MAX_NUM, tempo);
    listaTempo = destroiLista(listaTempo);

    comp = 0;
    listaComp = criaLista();
    for (long i = 0; i < MAX_NUM; i++)
    {
        listaComp = insereFinalComp (listaComp, rand()%MAX_NUM, &comp);
    }
    printf("\n\nNumero de comps para inserir %li nodos aleatorios no Final: %lli", MAX_NUM ,comp);

    comp = 0;
    for (long i = 0; i < 10000; i++)
    {
        consultaNumComp (listaComp, rand()%MAX_NUM, &comp);
    }
    printf("\nMedia do numero de comps para consultar, em uma lista de %d nodos, 10000 nodos aleatorios: %lli\n\n\n", MAX_NUM ,comp/10000);
    listaComp = destroiLista(listaComp);

    return 0;
}