
typedef struct arv Arvore;

//função que verifiqua se uma árvore passada é uma folha.
int ehFolha(Arvore* a);
//função que imprime a expressão em notação pós-fixada.
void imprimePos(Arvore* a);
//função que retorna o valor correspondente à avaliação da expressão.
float avalia(Arvore* a);
//funçao que mostra opções para o usuario
void menuInicial();
//função que cria arvore apenas para somar
Arvore* criarArvoreSoma();
//funcão que libera memória 
void liberarArvore(Arvore* a);