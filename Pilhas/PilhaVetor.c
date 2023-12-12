#include "PilhaVetor.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 5
//
struct pilha{
  int qtdeItens;
  float vet[TAM];
};

/*Cria uma pilha vazia*/
Pilha* criaPilha(){
  Pilha* p = (Pilha*) malloc(sizeof(Pilha));
  p->qtdeItens = 0; //inicializa com zero elementos
  return p;
}
/*Insere um elemento na pilha */
void push(Pilha *p, float valor){
  if (p->qtdeItens == TAM){
    printf("Pilha cheia!\n");
    exit(1);
  }
  p->vet[p->qtdeItens] = valor;
  p->qtdeItens++;
}
/*Remove o elemento do topo*/
float pop(Pilha *p){
  float topo;
  if (pilhaVazia(p)){
    printf("Pilha vazia!\n");
    exit(1);
  }
  topo = p->vet[p->qtdeItens - 1];
  p->qtdeItens--;
return topo;
}
/*Verifica se a pilha está vazia*/
int pilhaVazia(Pilha *p){
  return (p->qtdeItens == 0);
}
/*Libera a pilha*/
void pilhaLibera(Pilha *p){
  free(p);
}

