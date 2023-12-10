#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arvoreBinariaExpressao.h"

struct arv{
    char op;
    float valor;
    struct arv *esq, *dir;
};

Arvore* raiz=NULL;
Arvore* dir=NULL;
Arvore* esq=NULL;


Arvore* novoNo(float numero){
    Arvore* no = (Arvore*)malloc(sizeof(Arvore));
    no->valor = numero;
    no->esq=NULL;
    no->dir=NULL;
    return no;
}
int ehFolha(Arvore* no){
    return(no!=NULL && no->esq==NULL && no->dir ==NULL);
}

Arvore* criaArvore(char op,int valor, Arvore* esquerda, Arvore* direita){
    Arvore* novo = (Arvore*)malloc(sizeof(Arvore));
    novo->op=op;
    novo->valor =valor;
    novo->esq =esquerda;
    novo->dir =direita;
    return novo;
}
Arvore* criarArvorePersonalizada(){
    char entrada[100];
    char op;
    float valor;
    Arvore* esquerda =NULL;
    Arvore* direita =NULL;

    printf("Digite um operador (+, -, *, /) ou um numero: ");
    fgets(entrada, sizeof(entrada), stdin);
    sscanf(entrada, " %c", &op);

    if (isdigit(op)){
        valor = atof(entrada);
        return novoNo(valor);

    }else if (op == '+' || op == '-' || op == '*' || op == '/'){
        printf("Digite a subarvore esquerda de %c:\n", op);
        esquerda = criarArvorePersonalizada();

        printf("Digite a subarvore direita de %c:\n", op);
        direita = criarArvorePersonalizada();
        printf("arvore criada!\n");
        return criaArvore(op, -1, esquerda, direita);
    }else{
        printf("Operador invalido!\n");
        return NULL;
    }
    
}


void imprimePos(Arvore* a){
    if (a != NULL) {
        imprimePos(a->esq);
        imprimePos(a->dir);

        if (ehFolha(a)) {
            printf("%.1f ", a->valor);
        } else {
            printf("%c ", a->op);
        }
    }
}

float avalia(Arvore* a) {
    if (ehFolha(a)) {
        return a->valor;
    } else {
        float esq = avalia(a->esq);
        float dir = avalia(a->dir);

        switch (a->op) {
            case '+':
                return esq + dir;
            case '-':
                return esq - dir;
            case '*':
                return esq * dir;
            case '/':
                return esq / dir;
            default:
                printf("Operacao invalida.\n");
                return 0.0;
        }
    }
}

void liberarArvore(Arvore* a){
    if(a != NULL){
        liberarArvore(a->esq);
        liberarArvore(a->dir);
        free(a);
    }
}

void menuInicial(){
    int cont = 0;
    char opcao[100];

    do {
        printf("******* MENU INICIAL *******\nEscolha uma opcao:\n\t1 - Criar Arvore Personalizada\n\t2 - Imprimir Arvore\n\t3 - Avaliar Arvore\n\t4 - criar Arvore Exemplo do trabalho \n\t5 - Sair\n");
        fgets(opcao, 100, stdin);
        if(strlen(opcao) == 2 && isdigit(opcao[0])){
            int escolha = opcao[0] - '0';
            if(escolha >= 1 && escolha <= 5){
                cont = 1;
            }else{
                printf("Digito inválido! Tente novamente.\n");
            }
        }else{
            printf("Entrada inválida! Tente novamente.\n");
        }
    }while(cont!=1);

    switch(opcao[0]-'0'){
        case 1:
            raiz = criarArvorePersonalizada();
            break;
        case 2:
            if(raiz->esq != NULL || raiz->dir!=NULL){
                printf("impressao arvore de forma Pos-fixada: \n");
                imprimePos(raiz);
                printf("\n");
            }else{
                printf("arvore vazia!\n");
            }
            break;
        case 3:
            if(raiz!=NULL){
                float resultado = avalia(raiz);
                printf("Resultado da Avaliacao da arvore: %.1f\n", resultado);
            }else{
                printf("Arvore vazia! Nada para avaliar.\n");
            }
            break;
        case 4:     
                    raiz=criaArvore('+',-1,criaArvore('*',-1,criaArvore('+',-1,criaArvore(' ',3,esq,dir),criaArvore(' ',6,esq,dir)),criaArvore('-',-1,criaArvore(' ',4,esq,dir),criaArvore(' ',1,esq,dir))),criaArvore(' ',5,esq,dir));
                    printf("arvore criada!\n");
            break;
        case 5:
            liberarArvore(raiz);
            exit(0);
            break;
    }
    menuInicial();
}

int main() {
    menuInicial();
    return 0;
}
