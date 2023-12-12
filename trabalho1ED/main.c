#include <stdio.h>
#include "vetor.h"
int main(){
    Vetor *v1;
    Vetor *v2;
    Vetor *v=criaVetor(4);
    for(int i=0;i<4;i++){
        atribui(v,i,2.2*i);
    }
    printf("testando...");
    listarVetor(v);
    liberaVetor(v);
}