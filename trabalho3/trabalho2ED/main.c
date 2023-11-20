#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"

void chamarProximo();
void visualizarFilas();
void ultimasChamadas();
void menuCaixa();
void menuControle();
void menuCliente();
void GerarSenhaPrioritaria();
void GerarSenhaNormal();

FilaNormal* filaNormal;
FilaPrioritaria* filaPrioritaria;
Pilha* pilha;

void menuControle(){
    int cont=0;
    char opcao[100];
    do{
       printf("******* MENU DE CONTROLE *******\nescolha uma opcao:\n\t1 - Menu caixa\n\t2 - Menu cliente\n\t3 - Encerrar\n");
        fgets(opcao,100,stdin);
        if (strlen(opcao)==2 && isdigit(opcao[0])) {
            int escolha=opcao[0]-'0';
            if (escolha>=1 && escolha<=3) {
                cont=1;
            } else {
                printf("Digito invalido! Tente novamente.\n");
            }
        } else {
            printf("Entrada invalida! Tente novamente.\n");
        }

    }while(cont!=1);

    switch(opcao[0]-'0'){
    case 1: menuCaixa();
        break;
    case 2: menuCliente();
        break;
    case 3: exit(0);
        break;
        }
}
void menuCaixa(){
    int cont=0;
    char opcao[100];
    do{
       printf("******* MENU CAIXA *******\nescolha uma opcao:\n\t1 - Chamar o proximo\n\t2 - Visualizar filas\n\t3 - Ultimas chamadas\n\t4 - Voltar ao menu anterior\n");
        fgets(opcao,100,stdin);
        if (strlen(opcao)==2 && isdigit(opcao[0])) {
            int escolha=opcao[0]-'0';
            if (escolha>=1 && escolha<=4) {
                cont=1;
            } else {
                printf("Digito invalido! Tente novamente.\n");
            }
        } else {
            printf("Entrada invalida! Tente novamente.\n");
        }

    }while(cont!=1);

    switch(opcao[0]-'0'){
    case 1: chamarProximo();
        break;
    case 2: visualizarFilas();
        break;
    case 3: ultimasChamadas();
        break;
    case 4: menuControle();
        break;
    }
}
void menuCliente(){
    int cont=0;
    char opcao[100];
    do{
       printf("******* MENU CLIENTE *******\nescolha uma opcao:\n\t1 - Normal\n\t2 - Prioritaria\n\t3 - Voltar ao menu anterior\n");
        fgets(opcao,100,stdin);
        if (strlen(opcao)==2 && isdigit(opcao[0])) {
            int escolha=opcao[0]-'0';
            if (escolha>=1 && escolha<=3) {
                cont=1;
            } else {
                printf("Digito invalido! Tente novamente.\n");
            }
        } else {
            printf("Entrada invalida! Tente novamente.\n");
        }

    }while(cont!=1);

    switch(opcao[0]-'0'){
    case 1: GerarSenhaNormal();
        break;
    case 2: GerarSenhaPrioritaria();
        break;
    case 3: menuControle();
        break;
        }
}

void chamarProximo(){
    int contN=0,contP=0;
    if(vaziaPrioritaria(filaPrioritaria))
        contP++;
    if(vaziaNormal(filaNormal))
        contN++;
    if((contN + contP)==2){
        printf("filas vazias!");
        menuCliente();
    }if(contN==1 && contP==0){
        int senha=imprimeEcopiaSenhaPessoaChamada(filaNormal);  
        Pessoa* pessoa=criaPessoa(senha);       
        filaNormal=atualizarFilaNormal(filaNormal);                
        pilha=empilhar(pilha,pessoa); 
        menuCaixa();
    }if(contN==0 && contP==1){
        //chamo da prioridade
    }if(contN==0 && contP==0){
        //usar regra
    }
    menuCaixa();

}
void visualizarFilas(){
    int tamanhoFilaNormal=quantidadeFilaNormal(filaNormal);
    int tamanhoFilaPrioritaria=quantidadeFilaPrioritaria(filaPrioritaria);
    printf("quantidade de pessoas:\nfila normal: %d\nfila prioritaria: %d\n",tamanhoFilaNormal,tamanhoFilaPrioritaria);
    menuCaixa();
}
void ultimasChamadas(){
    mostraClientesAtendidos(pilha);
    menuCaixa();
}
void GerarSenhaPrioritaria(){
    filaPrioritaria=inserePrioritaria(filaPrioritaria);
    menuCliente();
}
void GerarSenhaNormal(){
    filaNormal=insereNormal(filaNormal);
    menuCliente();
}
int main(){ 
    pilha=criaPilha(); 
    filaNormal=criaNormal();
    filaPrioritaria=criaPrioritaria();
    menuControle();
    return 0;
}
