#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

 int x=0,y=0,z=0;

struct arvore{
    int valor;
    struct arvore *esq;
    struct arvore *dir;
};
Arv *criaVazia(){
    return NULL;
}

Arv* criaArvore(int valor, Arv *esquerda, Arv *direita){
    Arv* novo = (Arv*)malloc(sizeof(Arv));
    novo->valor =valor;
    novo->esq = esquerda;
    novo->dir = direita;
    return novo;
}
int arvoreVazia(Arv *a){
    return (a == NULL);
}

void imprime(Arv *a){
    if(!arvoreVazia(a)){
        printf("%d ",a->valor);
        imprime(a->esq);
        imprime(a->dir);
    }
}
int pertence(Arv *a, int c){
    if(arvoreVazia(a)){
        return 0;
    }else{
        return a->valor == c ||
        pertence(a->esq, c) ||
        pertence(a->dir, c);
    }
}
Arv* libera(Arv *a){
    if(!arvoreVazia(a)){
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
    return NULL;
}

int nos(Arv* a){
    if(arvoreVazia(a)){
            return 0;
    }else{
            x++;
        nos(a->esq);
        nos(a->dir);
    }
    return x;
    }

int folhas(Arv* a){
    if(arvoreVazia(a)){
        return 0;
    }else{
        if(a->dir==NULL && a->esq==NULL)
            y++;
        folhas(a->esq);
        folhas(a->dir);
    }
    return y;
}
int um_filho(Arv* a){
    if(arvoreVazia(a)){
        return 0;
    }else{
        if(a->esq==NULL && a->dir!=NULL || a->esq!=NULL && a->dir==NULL)
            z++;
        um_filho(a->esq);
        um_filho(a->dir);
    }
    return z;
}

int main(){
    Arv* dir=criaVazia();
    Arv* esq=criaVazia();
    Arv *arvore=criaArvore(1,criaArvore(2,criaArvore(4,esq,dir),dir),criaArvore(3,esq,dir));
    imprime(arvore);
    printf("quantidade de nos: %d\n",nos(arvore));
    printf("quantidade de folhas: %d\n",folhas(arvore));
    printf("quantidade nos com unico filho: %d\n",um_filho(arvore));
    libera(arvore);
}
