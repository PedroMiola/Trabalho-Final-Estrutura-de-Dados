typedef struct ABP{
        int info;
        struct ABP *esq;
        struct ABP *dir;
}ABP;

ABP* insereArvore(ABP *arv, int chave);
ABP* consultaABP(ABP *arv, int chave);
ABP* criaArvore(void);
ABP* destroiArvore(ABP *arv);
void destroiNodos(ABP *arv);
void imprimeArvore(ABP *arv , int nivel);
ABP* consultaOrdenadaPrimeiroABP(ABP *arv);
ABP* consultaOrdenadaMeioABP(ABP *arv, int qDados);
ABP* consultaOrdenadaUltimoABP(ABP *arv, int qDados);
