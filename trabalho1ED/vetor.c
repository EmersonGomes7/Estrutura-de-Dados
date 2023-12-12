#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

struct vetor {
int tamanho;
float *elementos;
};

Vetor* criaVetor(int n){
    Vetor *p=(Vetor*)malloc(sizeof(Vetor));
    p->tamanho=n;
    return p;
}
void liberaVetor(Vetor* v){
    free(v->elementos);
    free(v);
}
int tamanhoVetor(Vetor* v){
    int tamanho=v->tamanho;
    return tamanho;
}
float acessa(Vetor* v, int i){
    float valor=v->elementos[i];
    return valor;
}
void atribui(Vetor* v, int i, float c){
    v->elementos[i]=c;
}
float maior(Vetor* v){
    float maior=v->elementos[0];
    for(int i=0;i<(v->tamanho);i++){
        if(v->elementos[i]>maior){
            maior=v->elementos[i];
        }
    }
    return maior;
}
float menor(Vetor* v){
    float menor=v->elementos[0];
    for(int i=0;i<v->tamanho;i++){
        if(v->elementos[i]<menor){
            menor=v->elementos[i];
        }
    }
    return menor;
}
void listarVetor(Vetor* v){
    for(int i=0;i<v->tamanho;i++){
        printf("[%f] ",v->elementos[i]);
    }
}
float somaVetor(Vetor* v){
    float soma=0;
    for(int i=0;i<(v->tamanho);i++){
            soma+=(v->elementos[i]);
        }
        return soma;
}
float somaElementos(Vetor* v, int n){
    float somaParcial=0;
    for(int i=0;i<n;i++){
            somaParcial+=(v->elementos[i]);
        }
        return somaParcial;
}
Vetor* somaVetores(Vetor* v1, Vetor* v2){
    if(v1->tamanho!=v2->tamanho){
        printf("impossível calcular soma! vetores de tamanhos diferentes!\n");
        return NULL;
    }else{
        printf("vetores de tamanhos iguais!\n");
        Vetor* v3=(Vetor*)malloc(sizeof(Vetor));
        v3->tamanho=v1->tamanho;
        for(int i=0;i<v1->tamanho;i++){
            v3->elementos[i]=v1->elementos[i]+v2->elementos[i];
        }
        return v3;
    }
}
void MostrarsomaVetores(Vetor* v1, Vetor* v2){
     if(v1->tamanho!=v2->tamanho){
        printf("vetores de tamanhos diferentes!\n");
    }else{
        printf("vetores de tamanhos iguais!\n");
        for(int i=0;i<v1->tamanho;i++){
            printf("%.1f + %.1f = %1.f\n",v1->elementos[i],v2->elementos[i],(v1->elementos[i])+(v2->elementos[i]));
        }
    }
}
