#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

/*TAD que que possibilita criar e manipular as duas filas, a fila normal
e a fila Prioritária e suas respectivas funções abaixo.

autores:
Antonio Emerson Gomes Camelo;
Eduardo Levi Portela Miranda;
Wenderson Gabriel Sousa Mourão;


obs: as senhas são distribuídas com intervalos diferentes para cada fila:
para fila normal, são distribuidas de 1 a 10;
para fila prioritária, de 11 a 20;

exemplo: se tiver um cliente com a senha 10, a próxima pessoa que chegar receberá a senha 1 e assim sucessivamente,
variando somente no intervalo permitido. isso considerando que há menos de 10 pessoas na fila no momento para ser inserido uma nova pessoa;
*/



typedef struct filaNormal FilaNormal;
typedef struct filaPrioritaria FilaPrioritaria;
//função que cria a fila normal;
FilaNormal* criaNormal();
//função que cria a fila Prioritaria;
FilaPrioritaria* criaPrioritaria();
//função que insere uma pessoa na fila Normal;
FilaNormal *insereNormal(FilaNormal* fila);
//função que insere uma pessoa na fila prioritária;
FilaPrioritaria* inserePrioritaria(FilaPrioritaria* fila);
//função que calcula quantas pessoas existem na fila Normal no momento;
int quantidadeFilaNormal(FilaNormal* fila);
//função que calcula quantas pessoas existem na fila Prioritaria no momento;
int quantidadeFilaPrioritaria(FilaPrioritaria* fila);
//função que atualiza a fila Normal após uma pessoa for chamada pelo caixa;
FilaNormal* atualizarFilaNormal(FilaNormal* fila);
//função que atualiza a fila Prioritária após uma pessoa for chamada pelo caixa;
FilaPrioritaria* atualizarFilaPrioritaria(FilaPrioritaria* fila);
//função que retorna verdadeiro se a fila Normal estiver vazia;
int vaziaNormal(FilaNormal* fila);
//função que retorna verdadeiro se a fila Prioritária estiver vazia;
int vaziaPrioritaria(FilaPrioritaria* fila);
//função que imprime a senha da pessoa da fila Normal que é chamada, além de retornar a senha da mesma para que possa ser inserida na pilha posteriormente;
int imprimeEcopiaSenhaPessoaChamadaNormal(FilaNormal* fila);
//função que imprime a senha da pessoa da fila Prioritária que é chamada, além de retornar a senha da mesma para que possa ser inserida na pilha posteriormente;
int imprimeEcopiaSenhaPessoaChamadaPrioritaria(FilaPrioritaria* fila);

#endif // FILA_H_INCLUDED
