#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct arvore Arv;
//função que retorne a quantidade de nós de uma árvore
int nos(Arv *a);
//função que retorne a quantidade de folhas de uma árvore binária.
int folhas(Arv *a);
// função que retorne a quantidade de nós de uma árvore binária que possuem apenas um filho
int um_filho(Arv *a);
//função que imprime toda a arvore
void imprime(Arv *a);
//função que verifica se arvore está vazia
int arvoreVazia(Arv *a);
//função que consulta se determinado inteiro pertence à arvore
int pertence(Arv *a, int c);
//função que libera alocação
Arv* libera(Arv *a);
//função que cria no apontando para null
Arv *criaVazia();
//função que cria no com dois filhos
Arv* criaArvore(int valor, Arv *esquerda, Arv *direita);

#endif // ARVORE_H_INCLUDED
