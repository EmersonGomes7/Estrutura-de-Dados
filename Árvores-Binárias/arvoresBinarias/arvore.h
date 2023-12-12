#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct arvore Arvore;
Arvore* criaVazia();
Arvore* cria(char x,Arvore* esq,Arvore* dir);

#endif // ARVORE_H_INCLUDED
