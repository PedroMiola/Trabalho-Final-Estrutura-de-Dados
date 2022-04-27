typedef struct LSE
{
    int num;
    struct LSE *prox;
}LSE;

LSE *criaLista (void);
LSE *insereInicio (LSE *list, int num);
LSE *insereFinal (LSE *list, int num);
LSE *insereMeio (LSE *list, int num);
LSE *destroiLista (LSE *list);
void consultaNum (LSE *list, int num);
void imprimeLista (LSE *list);