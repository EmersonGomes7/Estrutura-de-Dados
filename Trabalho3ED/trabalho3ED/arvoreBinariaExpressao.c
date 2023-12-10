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


Arvore* novoNo(float numero){
    Arvore* no = (Arvore*)malloc(sizeof(Arvore));
    no->valor = numero;
    no->esq=NULL;
    no->dir=NULL;
    return no;
}

Arvore* criarArvoreSoma(){
    Arvore* raiz = NULL;

    char escolha[10];
    printf("Digite um numero para inserir na arvore ou 'x' para encerrar: \n");

    while (1){
        scanf("%s",escolha);
        getchar();

        if(strcmp(escolha, "x")==0){
            break;
        }else if (isdigit(escolha[0])){
            float numero=atof(escolha);
            if (raiz==NULL){
                raiz=novoNo(numero);
            } else {
                Arvore* temp = raiz;
                while (temp->esq!=NULL && temp->dir!=NULL){
                    // Busca por um nó livre na árvore
                    if(temp->esq!=NULL){
                        temp=temp->esq;
                    }else{
                        temp=temp->dir;
                    }
                }

                if(temp->esq==NULL){
                    temp->esq=novoNo(numero);
                }else{
                    temp->dir=novoNo(numero);
                }
            }
        }else{
            printf("Entrada invalida! Digite somente numeros ou 'x' para encerrar.\n");
        }
    }

    return raiz;
}



void imprimePos(Arvore* a){
    if (a != NULL) {
        imprimePos(a->esq);
        imprimePos(a->dir);

        if(a->esq==NULL && a->dir==NULL){
            printf("%.2f ", a->valor);
        }
    }
}

float avalia(Arvore* a){
    if(a != NULL){
        if(a->esq == NULL && a->dir==NULL){
            return a->valor;
        }

        float esq=avalia(a->esq);
        float dir=avalia(a->dir);

        return esq + dir;
    }
    return 0.0;
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
        printf("******* MENU INICIAL *******\nEscolha uma opcao:\n\t1 - Criar Arvore de Soma\n\t2 - Imprimir Arvore\n\t3 - Avaliar Arvore\n\t4 - Sair \n");
        fgets(opcao, 100, stdin);
        if(strlen(opcao) == 2 && isdigit(opcao[0])){
            int escolha = opcao[0] - '0';
            if(escolha >= 1 && escolha <= 4){
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
            raiz = criarArvoreSoma();
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
            if(raiz->dir!=NULL || raiz->esq!=NULL){
                float resultado = avalia(raiz);
                printf("Resultado da Avaliacao da arvore: %.1f\n", resultado);
            }else{
                printf("Arvore vazia! Nada para avaliar.\n");
            }
            break;
        case 4:
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
