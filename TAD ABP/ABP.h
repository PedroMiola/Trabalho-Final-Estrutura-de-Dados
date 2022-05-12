typedef struct ABP{
        long int info;
        struct ABP *esq;
        struct ABP *dir;
}ABP;

ABP* insereArvoreComp(ABP *arv, long int chave, long long int *comp);
ABP* criaArvore(void);
void destroiArvore(ABP *arv);
void imprimeArvore(ABP *arv , int nivel);

ABP* consultaABP(ABP *arv, long int chave);
ABP* consultaOrdenadaInicioABP(ABP *arv);
ABP* consultaOrdenadaMeioABP(ABP *arv, long int qDados);
ABP* consultaOrdenadaFimABP(ABP *arv, long int qDados);

ABP* consultaCompABP(ABP *arv, long int chave, long long int *comp);
ABP* consultaOrdenadaInicioCompABP(ABP *arv, long long int *comp);
ABP* consultaOrdenadaMeioCompABP(ABP *arv, long int qDados, long long int *comp);
ABP* consultaOrdenadaFimCompABP(ABP *arv, long int qDados, long long int *comp);
