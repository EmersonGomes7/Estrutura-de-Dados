#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

struct vetor {
int tamanho;
float *elementos;
};

Vetor* criaVetor(int n) {
    if(n<=0){
        printf("vetor de tamanho errado. deve ser maior que 0");
        return NULL;
    }
    Vetor *p = (Vetor*)malloc(sizeof(Vetor));
    if (p == NULL) {
        printf("erro ao alocar memoria para Vetor.\n");
        return NULL;
    }
    p->tamanho = n;
    p->elementos = (float*)malloc(n * sizeof(float));
    return p;
}
void liberaVetor(Vetor* v){
    if (v == NULL) {
        printf("Ponteiro recebido eh invalido! aponta para nulo.\n");
        return;
    }
    free(v->elementos);
    free(v);
}
int tamanhoVetor(Vetor* v){
    if (v == NULL) {
        printf("Ponteiro recebido eh invalido! aponta para nulo!\n");
        return -1;
    }
    int tamanho=v->tamanho;
    return tamanho;
}
float acessa(Vetor* v, int i){
    if (v == NULL || v->elementos == NULL) {
        printf("Ponteiro recebido eh invalido! aponta para nulo!\n");
        return -1;
    }if (i < 0 || i >= v->tamanho) {
        printf("invalido! indice fora do intervalo permitido!\n");
        return -1;
    }
    float valor=v->elementos[i];
    return valor;
}
void atribui(Vetor* v, int i, float c) {
    if (v == NULL || v->elementos == NULL) {
        printf("Ponteiro recebido eh invalido! aponta para nulo!\n");
        return;
    }
    if ( i < 0 || i >= v->tamanho) {
        printf("invalido! indice fora do intervalo permitido!\n");
        return;
    }
    v->elementos[i] = c;
}
float maior(Vetor* v){
    if (v == NULL || v->elementos == NULL) {
        printf("Ponteiro recebido eh invalido! aponta para nulo!\n");
        return -1;
    }
    float maior=v->elementos[0];
    for(int i=0;i<(v->tamanho);i++){
        if(v->elementos[i]>maior){
            maior=v->elementos[i];
        }
    }
    return maior;
}
float menor(Vetor* v){
    if (v == NULL || v->elementos == NULL) {
        printf("Ponteiro recebido eh invalido! aponta para nulo!\n");
        return -1;
    }
    float menor=v->elementos[0];
    for(int i=0;i<v->tamanho;i++){
        if(v->elementos[i]<menor){
            menor=v->elementos[i];
        }
    }
    return menor;
}
void listarVetor(Vetor* v){
    if (v == NULL || v->elementos == NULL) {
        printf("Ponteiro recebido eh invalido! aponta para nulo!\n");
        return;
    }printf("mostrando elementos vetor:\n");
    for(int i=0;i<v->tamanho;i++){
        printf("[%.1f] ",v->elementos[i]);
    }
    printf("\n");
}
float somaVetor(Vetor* v){
    if (v == NULL || v->elementos == NULL) {
        printf("Ponteiro recebido eh invalido! aponta para nulo!\n");
        return -1;
    }
    float soma=0;
    for(int i=0;i<(v->tamanho);i++){
            soma+=(v->elementos[i]);
        }
        return soma;
}
float somaElementos(Vetor* v, int n){
    if (v == NULL || v->elementos == NULL) {
        printf("Ponteiro recebido eh invalido! aponta para nulo!\n");
        return -1;
    }
    if (n<0 || n>= v->tamanho) {
        printf("numero invalido de elementos! impossivel somar!\n");
        return -1;
    }
    float somaParcial=0;
    for(int i=0;i<n;i++){
            somaParcial+=(v->elementos[i]);
        }
        return somaParcial;
}
Vetor* somaVetores(Vetor* v1, Vetor* v2){
     if (v1==NULL || v1->elementos==NULL || v2==NULL || v2->elementos==NULL) {
        printf("Ponteiro recebido eh invalido! aponta para nulo!\n");
        return NULL;
    }
    if(v1->tamanho!=v2->tamanho){
        printf("impossivel calcular soma! vetores de tamanhos diferentes!\n");
        return NULL;
    }
    Vetor* v3 = criaVetor(v1->tamanho);
    if (v3 == NULL) {
        printf("erro de alocacao de memoria para o vetor de resultado.\n");
        return NULL;
    }

   for (int i = 0; i < v1->tamanho; i++) {
        v3->elementos[i] = v1->elementos[i] + v2->elementos[i];
    }

    return v3;
}
void MostrarsomaVetores(Vetor* v1, Vetor* v2){
    if (v1==NULL || v1->elementos==NULL || v2==NULL || v2->elementos==NULL) {
        printf("Ponteiro recebido eh invalido! aponta para nulo!\n");
        return;
    }
     if(v1->tamanho!=v2->tamanho){
        printf("impossivel somar! vetores de tamanhos diferentes!\n");
        return;
    }
    printf("vetores de tamanhos iguais! Mostrando soma:\n");
        for(int i=0;i<(v1->tamanho);i++){
            printf("[%.1f] + [%.1f] = %.1f\n",v1->elementos[i],v2->elementos[i],(v1->elementos[i])+(v2->elementos[i]));

    }printf("\n");
}
