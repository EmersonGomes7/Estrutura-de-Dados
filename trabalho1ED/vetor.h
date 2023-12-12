#ifndef VETOR_H
#define VETOR_H
/*TAD que possibilita representar vetores de float com alocação de memória e manipula-los através das funções abaixo.
autores:
Antonio Emerson Gomes Camelo - 555535
Wenderson Gabriel Sousa Mour�o - 537734
Eduardo Levi Portela Miranda - 537030
*/
typedef struct  vetor Vetor;

//Função que cria um vetor de tamanho n.
Vetor* criaVetor(int n);

//Função que libera a memória alocada para um vetor.
void liberaVetor(Vetor* v);

//Função que retorna o tamanho de um vetor.
int tamanhoVetor(Vetor* v);

//Função que acessa o conteúdo de uma determinada posição i do vetor.
float acessa(Vetor* v, int i);

//Função que atribui um conteúdo c a uma determinada posição i do vetor.
void atribui(Vetor* v, int i, float c);

//Função que retorna o maior elementos do vetor.
float maior(Vetor* v);

//Função que retorna o menor elementos do vetor.
float menor(Vetor* v);

//Função que lista todos os elementos do vetor.
void listarVetor(Vetor* v);

//Função que retorna a soma de todos os elementos de um vetor.
float somaVetor(Vetor* v);

//Função que retorna a soma dos n primeiros elementos do vetor.
float somaElementos(Vetor* v, int n);

//Função que retorna um vetor resultante da soma dos elementos correspondentes de dois vetores.
Vetor* somaVetores(Vetor* v1, Vetor* v2);

//Função que mostra a soma dos elementos correspondentes de dois vetores do mesmo tamanho
void MostrarsomaVetores(Vetor* v1, Vetor* v2);
#endif

