#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct filaNormal{
    int senha;
    struct filaNormal *prox;
};
struct filaPrioritaria{
    int senha;
    struct filaPrioritaria *prox;
};
FilaNormal* criaNormal(){
    return NULL;
}
FilaPrioritaria* criaPrioritaria(){
    return NULL;
}

FilaNormal *insereNormal(FilaNormal* fila){
    int cont1=1;
    int cont2=1;
    FilaNormal* novaPessoa=(FilaNormal*)malloc(sizeof(FilaNormal));
    novaPessoa->prox=NULL;
    if(fila==NULL){
        fila=novaPessoa;
        novaPessoa->senha=cont1;
        printf("senha gerada: %d\n",cont2);
        return fila;
    }else{
        cont2++;
        FilaNormal* aux=fila;
        while(aux->prox!=NULL){
            cont2++;
            aux=aux->prox;
        }
        if(cont2>10){
            printf("limite da fila atingido! maximo 10 pessoas!\n");
            return fila;
        }else{
            aux->prox=novaPessoa;
            novaPessoa->senha=cont1+cont2;
        }     
    }
    printf("senha gerada: %d\n",cont2);
    return fila;
}
FilaPrioritaria* inserePrioritaria(FilaPrioritaria* fila){
    int cont=1;
    FilaPrioritaria* novaPessoa=(FilaPrioritaria*)malloc(sizeof(FilaPrioritaria));
    novaPessoa->prox=NULL;
    if(fila==NULL){
        fila=novaPessoa;
        fila->senha=cont;
        printf("senha gerada: %d\n",cont);
        return fila;
    }else{
        cont++;
        FilaPrioritaria* aux=fila;
        while(aux->prox!=NULL){
            cont++;
            aux=aux->prox;
        }
        if(cont>20){
            printf("limite da fila atingido! maximo 10 pessoas!\n");
            return fila;
        }else{
            aux->prox=novaPessoa;
            aux->senha=cont;
        }
    }
    printf("senha gerada: %d\n",cont);
    return fila;
}
int quantidadeFilaNormal(FilaNormal* fila){
    int cont=0;
    FilaNormal* aux=fila;
    while(aux!=NULL){
        cont++;
        aux=aux->prox;
    }
    return cont;
}
int quantidadeFilaPrioritaria(FilaPrioritaria* fila){
    int cont=0;
    FilaPrioritaria* aux=fila;
    while(aux!=NULL){
        cont++;
        aux=aux->prox;
    }
    return cont;
}
int vaziaNormal(FilaNormal* fila){
    if(fila==NULL)
        return 0;
    else
        return 1;
}
int vaziaPrioritaria(FilaPrioritaria* fila){
    if(fila==NULL)
        return 0;
    else
        return 1;
}
FilaNormal* atualizarFilaNormal(FilaNormal* fila){
    if(fila==NULL){
        printf("impossivel chamar! fila vazia!");
        return fila;
    }else{
        fila=fila->prox;
    }
    return fila;
}
int imprimeEcopiaSenhaPessoaChamada(FilaNormal* fila){
    if(fila==NULL){
        printf("erro! fila vazia!");
        return -1;
    }else{
        printf("Senha da Pessoa chamada: %d\n",fila->senha);
    return fila->senha;
    }
    
}
