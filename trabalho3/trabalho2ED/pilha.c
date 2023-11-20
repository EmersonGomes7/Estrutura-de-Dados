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


    /*if(pessoa==NULL){
        printf("erro! nenhuma pessoa para inserir!\n");
        return pilha;
    }
    else{
        if(pilha==NULL){
            Pilha* novaPilha = (Pilha*)malloc(sizeof(Pilha));
            if (novaPilha == NULL) {
                printf("Erro ao alocar memória para a pilha!\n");
                return pilha;
            }
            novaPilha->primeira=pessoa;
            novaPilha->primeira->prox=NULL; 
            printf("Primeira pessoa inserida\n");
            return novaPilha;
            }
            else{
            pessoa->prox=pilha->primeira;
            pilha->primeira=pessoa;
            printf("pessoa inserida na pilha\n");
            return pilha;
        }       
    }*/
 void mostraClientesAtendidos(Pilha* pilha){
    if(pilha==NULL){
        printf("erro! pilha vazia! nenhum cliente atendido!\n");
    }else{
        Pessoa* aux;
        printf("********* CLIENTES ATENDIDOS *********\n");
        for(aux=pilha->primeira;aux!=NULL;aux=aux->prox){
            printf("\tNumero: [%d]\n ",aux->senha);
        }
    }
 }