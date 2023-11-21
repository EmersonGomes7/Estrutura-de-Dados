#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pessoa{
    int senha;
    struct pessoa *prox;
};
struct pilha{
    Pessoa *primeira;
};
Pilha* criaPilha(){
    return NULL;
}
Pessoa* criaPessoa(int senha){
    Pessoa* novaPessoa=(Pessoa*)malloc(sizeof(Pessoa));
    novaPessoa->senha=senha;
    novaPessoa->prox=NULL;
    printf("pessoa criada");
   return novaPessoa;
}
Pilha* empilhar(Pilha* pilha,Pessoa* pessoa){   
    Pilha* empilhar(Pilha* pilha, Pessoa* pessoa);    
    if (pessoa==NULL) {
        printf("Erro! Nenhuma pessoa para inserir!\n");
        return pilha;
    } else {
        Pilha* novaPilha;
        if (pilha==NULL) {
            novaPilha=(Pilha*)malloc(sizeof(Pilha));
            if (novaPilha==NULL) {
                printf("erro na alocação de memoria para a pilha!\n");
                return pilha;
            }
            novaPilha->primeira=pessoa;
            novaPilha->primeira->prox=NULL; 
            printf("Primeira pessoa inserida\n");
            return novaPilha;
        } else {
            pessoa->prox=pilha->primeira;
            pilha->primeira=pessoa;
            printf("Pessoa inserida na pilha\n");
            return pilha;
         }
    }
}
 void mostraClientesAtendidos(Pilha* pilha){
    if(pilha==NULL){
        printf("nenhum cliente atendido ainda!\n");
    }else{
        Pessoa* aux;
        printf("********* CLIENTES ATENDIDOS *********\n");
        for(aux=pilha->primeira;aux!=NULL;aux=aux->prox){
            printf("\tNumero: [%d]\n ",aux->senha);
        }
    }
 }
int verificarPilha(Pilha* pilha) {
    if (pilha == NULL || pilha->primeira == NULL) {
        printf("pilha vazia");
        return -1; 
    }  
    if (pilha->primeira->senha >= 11 && pilha->primeira->senha <= 20) {
        return 1;
    } else if (pilha->primeira->prox != NULL && pilha->primeira->senha >= 1 && pilha->primeira->senha <= 10 && pilha->primeira->prox->senha >= 11 && pilha->primeira->prox->senha <= 20) {
        return 1;
    } else {
        return 0;
    }
}      
