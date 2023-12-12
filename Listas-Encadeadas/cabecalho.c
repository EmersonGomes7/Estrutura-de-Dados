#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

struct lista{
    int valor;
    struct lista *prox;
};
Lista* criaVazia(){
    return NULL;
}
Lista* insereNo(Lista* lista, int valor){
    Lista* novo=(Lista*)malloc(sizeof(Lista));
    novo->valor=valor;
    novo->prox=NULL;
    if(lista==NULL){
        lista=novo;
    }else{
        Lista* aux=lista;
        while(aux->prox != NULL){
            aux=aux->prox;
        }
        aux->prox=novo;
        return lista;
    }

}

void mostraLista(Lista *l2){
    if(l2==NULL){
        printf("lista vazia\n");
    }else{
        Lista *ptr3=l2;
    while(ptr3!=NULL){
        printf("%d-> ",ptr3->valor);
        ptr3=ptr3->prox;
        }
    }
    printf("rodou");
}

