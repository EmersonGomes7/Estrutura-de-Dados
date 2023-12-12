#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arvore{
    char info;
    struct arvore *esq;
    struct arvore *dir;
};

Arvore* criaVazia(){
    return NULL;
}
Arvore* cria(char x,Arvore* esq,Arvore* dir){
    Arvore* novo=(Arvore*)malloc(sizeof(Arvore));
    novo->info=x;
    novo->esq=esq;
    novo->dir=dir;
    return novo;
}
