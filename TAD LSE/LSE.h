typedef struct LSE
{
    int num;
    struct LSE *prox;
}LSE;

LSE *criaLista (void);

LSE *insereInicio (LSE *list, int num);
LSE *insereFinal (LSE *list, int num);
LSE *insereMeio (LSE *list, int num);

LSE *insereInicioComp (LSE *list, int num, double *comp);
LSE *insereFinalComp (LSE *list, int num, double *comp);
LSE *insereMeioComp (LSE *list, int num, double *comp);

LSE *destroiLista (LSE *list);
void consultaNum (LSE *list, int num);
void consultaNumComp (LSE *list, int num, double *comp);
void imprimeLista (LSE *list);