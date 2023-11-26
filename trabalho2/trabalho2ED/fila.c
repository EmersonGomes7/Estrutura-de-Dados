#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
int senha=1,extra=0;
int senha2=11,extra2=0;

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
    int quantidade=1;
    FilaNormal* novaPessoa=(FilaNormal*)malloc(sizeof(FilaNormal));
    if (novaPessoa==NULL) {
        printf("erro na alocação de memória.\n");
        return fila;
    }
    novaPessoa->senha=0;
    novaPessoa->prox=NULL;
    if(fila==NULL){
        fila=novaPessoa;
        novaPessoa->senha=senha;
        printf("senha gerada: %d\n",senha);
        return fila;
    }else{
        senha++;
        FilaNormal* aux=fila;                 
        while(aux->prox!=NULL){
            if(aux->prox->senha==10){
                senha=0;
                extra++;
            }
            quantidade++;
            aux=aux->prox;
        }
        if(quantidade>=10){
            printf("limite da fila normal atingido! maximo 10 pessoas!\n");
            return fila;
        }else{
            if(extra>=1){
                 while(aux->prox!=NULL){
                    aux=aux->prox;
                }  if(aux->senha==10){
                    aux->prox=novaPessoa;
                    novaPessoa->senha=1;
                    printf("senha gerada: %d\n",1); 
                }else{
                    aux->prox=novaPessoa;
                    novaPessoa->senha=aux->senha+1;
                    printf("senha gerada: %d\n",aux->senha+1);  
                }                   
            }
            else{
                aux->prox=novaPessoa;
                novaPessoa->senha=senha+extra;
                printf("senha gerada: %d\n",senha+extra);
            }        
        }     
    }
    return fila;
}
FilaPrioritaria* inserePrioritaria(FilaPrioritaria* fila){
     int quantidade=1;
    FilaPrioritaria* novaPessoa=(FilaPrioritaria*)malloc(sizeof(FilaPrioritaria));
    if (novaPessoa==NULL) {
        printf("erro na alocação de memória.\n");
        return fila;
    }
    novaPessoa->senha=11;
    novaPessoa->prox=NULL;

    if(fila==NULL){
        fila=novaPessoa;
        novaPessoa->senha=senha2;
        printf("senha gerada quando: %d\n",senha2);
        return fila;
    }else{
        senha2++;
        FilaPrioritaria* aux=fila;                 
        while(aux->prox!=NULL){
            if(aux->prox->senha==20){
                senha2=0;
                extra++;
            }
            quantidade++;
            aux=aux->prox;
        }
        if(quantidade>=10){
            printf("limite da fila prioritaria atingido! maximo 10 pessoas!\n");
            return fila;
        }else{
            if(extra>=1){
                 while(aux->prox!=NULL){
                    aux=aux->prox;
                }  if(aux->senha==20){
                    aux->prox=novaPessoa;
                    novaPessoa->senha=11;
                    printf("senha gerada: %d\n",11); 
                }else{
                    aux->prox=novaPessoa;
                    novaPessoa->senha=aux->senha+1;
                    printf("senha gerada: %d\n",aux->senha+1);  
                }                   
            }
            else{
                aux->prox=novaPessoa;
                novaPessoa->senha=senha2+extra2;
                printf("senha gerada: %d\n",senha2+extra2);
            }        
        }     
    }
    return fila;

}
int quantidadeFilaNormal(FilaNormal* fila){
     if(fila==NULL){
        printf("fila vazia.\n");
        return 0;
    }
    int cont=0;
    FilaNormal* aux=fila;
    while(aux!=NULL){
        cont++;
        aux=aux->prox;
    }
    return cont;
}
int quantidadeFilaPrioritaria(FilaPrioritaria* fila){
    if(fila==NULL){
        printf("fila vazia.\n");
        return 0;
    }
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
        return 1;
    else
        return 0;
}
int vaziaPrioritaria(FilaPrioritaria* fila){
    if(fila==NULL)
        return 1;
    else
        return 0;
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

int imprimeEcopiaSenhaPessoaChamadaNormal(FilaNormal* fila){
    if(fila==NULL){
        printf("fila vazia!\n");
        return -1;
    }else{
        printf("Senha da Pessoa chamada da fila Normal: %d\n",fila->senha);
    return fila->senha;
    }
    
}
FilaPrioritaria* atualizarFilaPrioritaria(FilaPrioritaria* fila){
    if(fila==NULL){
        printf("impossivel chamar! fila vazia!");
        return fila;
    }else{
        fila=fila->prox;
    }
    return fila;
}

int imprimeEcopiaSenhaPessoaChamadaPrioritaria(FilaPrioritaria* fila){
    if(fila==NULL){
        printf("fila vazia!\n");
        return -1;
    }else{
        printf("Senha da Pessoa chamada da fila prioritaria: %d\n",fila->senha);
    return fila->senha;
    }   
}
void liberaFilaNormal(FilaNormal* fila){
     if(fila!=NULL){
        FilaNormal* aux=fila;   
        while(aux!=NULL){
            FilaNormal* aux2=aux->prox;
            free(aux);
            aux=aux2;
        }
    }
}
void liberaFilaPrioritaria(FilaPrioritaria* fila){
      if(fila!=NULL){
        FilaPrioritaria* aux=fila;   
        while(aux!=NULL){
            FilaPrioritaria* aux2=aux->prox;
            free(aux);
            aux=aux2;
        }
    }
}
