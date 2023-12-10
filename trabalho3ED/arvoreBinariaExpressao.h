
typedef struct arv Arvore;

//função que verifiqua se uma árvore passada é uma folha.
int ehFolha(Arvore* a);
//função que imprime a expressão em notação pós-fixada.
void imprimePos(Arvore* a);
//função que retorna o valor correspondente à avaliação da expressão.
float avalia(Arvore* a);
//funçao que mostra opções para o usuario
void menuInicial();
//função que cria arvore personalizada
Arvore* criarArvorePersonalizada();
//funcão que libera memória 
void liberarArvore(Arvore* a);
//função para criar uma arvore
Arvore* criaArvore(char op,int valor, Arvore* esquerda, Arvore* direita);
//função que cria um novo nó a partir do recebimento de um número
Arvore* novoNo(float numero);