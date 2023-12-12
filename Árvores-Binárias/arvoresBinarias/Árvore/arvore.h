#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct arvore Arv;
//fun��o que retorne a quantidade de n�s de uma �rvore
int nos(Arv *a);
//fun��o que retorne a quantidade de folhas de uma �rvore bin�ria.
int folhas(Arv *a);
// fun��o que retorne a quantidade de n�s de uma �rvore bin�ria que possuem apenas um filho
int um_filho(Arv *a);
//fun��o que imprime toda a arvore
void imprime(Arv *a);
//fun��o que verifica se arvore est� vazia
int arvoreVazia(Arv *a);
//fun��o que consulta se determinado inteiro pertence � arvore
int pertence(Arv *a, int c);
//fun��o que libera aloca��o
Arv* libera(Arv *a);
//fun��o que cria no apontando para null
Arv *criaVazia();
//fun��o que cria no com dois filhos
Arv* criaArvore(int valor, Arv *esquerda, Arv *direita);

#endif // ARVORE_H_INCLUDED
