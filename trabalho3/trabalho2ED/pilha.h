#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pessoa Pessoa;
typedef struct pilha Pilha;
Pilha* empilhar(Pilha* pilha,Pessoa* pessoa);
Pilha* criaPilha();
Pessoa* criaPessoa(int senha);
void mostraClientesAtendidos(Pilha* pilha);

#endif // PILHA_H_INCLUDED
