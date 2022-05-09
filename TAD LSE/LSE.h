typedef struct LSE
{
    long num;
    struct LSE *prox;
}LSE;

LSE *criaLista (void);

LSE *insereInicio (LSE *list, long num);
LSE *insereFinal (LSE *list, long num);
LSE *insereMeio (LSE *list, long num);

LSE *insereInicioComp (LSE *list, long num, long long int *comp);
LSE *insereFinalComp (LSE *list, long num, long long int *comp);
LSE *insereMeioComp (LSE *list, long num, long long int *comp);

LSE *destroiLista (LSE *list);
void consultaNum (LSE *list, long num);
void consultaNumComp (LSE *list, long num, long long int *comp);
void imprimeLista (LSE *list);