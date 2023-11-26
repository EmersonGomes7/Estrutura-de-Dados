#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

/*TAD que que possibilita criar e manipular a pilha que armazena 
a senha das pessoas que ja foram chamadas pelo caixa.

autores:
Antonio Emerson Gomes Camelo;
Eduardo Levi Portela Miranda;
Wenderson Gabriel Sousa Mourão;
*/

typedef struct pessoa Pessoa;
typedef struct pilha Pilha;
//função que empilha uma pessoa que foi chamada na pilha;
Pilha* empilhar(Pilha* pilha,Pessoa* pessoa);
//função que cria uma pilha;
Pilha* criaPilha();
//função que cria uma pessoa para ser inserida na pilha contendo a mesma senha da pessoa que foi chamada;
Pessoa* criaPessoa(int senha,char tipo[]);
//função que mostra os clientes que ja foram atendidos;
void mostraClientesAtendidos(Pilha* pilha);
/*função que verifica se a última e a penúltima pessoa da pilha que foram atendidas derivam da fila prioritária ou da normal baseado
na senha delas. o intervalo de senhas entre 1 e 10 indica que é uma pessoa da fila normal e de 11 a 20 indica que é da fila prioritária.
isso para verificar qual das regras do processo de Chamar Próximo será feito para poder chamar o próximo seguindo a regra*/
int verificarPilha(Pilha* pilha);
//função que libera memória alocada para a pilha
void liberaPilha(Pilha* pilha);

#endif // PILHA_H_INCLUDED
