#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

struct pessoa{
    int senha;
    char tipo[20];
    struct pessoa *prox;
};
struct pilha{
    Pessoa *primeira;
};
Pilha* criaPilha(){
    return NULL;
}
Pessoa* criaPessoa(int senha,char tipo[]){
     Pessoa* novaPessoa = (Pessoa*)malloc(sizeof(Pessoa));
    if (novaPessoa == NULL) {
        printf("erro na alocação de memória.\n");
        return NULL;
    }
    novaPessoa->senha = senha;
    strcpy(novaPessoa->tipo, tipo);
    novaPessoa->prox = NULL;

    return novaPessoa;
}
Pilha* empilhar(Pilha* pilha,Pessoa* pessoa){       
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
            printf("\tNumero: [%d] %s\n ",aux->senha,aux->tipo);
        }
    }
 }
int verificarPilha(Pilha* pilha) {
    if (pilha == NULL || pilha->primeira == NULL) {
        printf("pilha vazia\n");
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

void liberaPilha(Pilha* pilha) {
    if(pilha!=NULL){
        Pessoa* atual=pilha->primeira;
        while (atual!=NULL) {
            Pessoa* temp=atual;
            atual=atual->prox;
            free(temp);
        }
        free(pilha);
    }
}
