#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"

//função que chama a próxima pessoa de uma das fila a depender da regra a ser seguida no momento;
void chamarProximo();
//função que visualiza a quantidade de pessoas presentes em cada fila no momento;
void visualizarFilas();
//função que mostra a senha de todas últimas pessoas chamadas pelo caixa de "cima para baixo" indicando a mais recente no topo da pilha;
void ultimasChamadas();
//função para mostrar menu do caixa com as opções e  garantir a interação correta do usuario com o programa;
void menuCaixa();
//função para mostrar menu inicial de controle com as opções e  garantir a interação correta do usuario com o programa;
void menuControle();
//função para mostrar as opções do menu do cliente e garantir a interação correta do usuário com o programa;
void menuCliente();
//função para gerar uma senha única para a fila prioritária dentro do intevalo permitido(11 a 20);
void GerarSenhaPrioritaria();
//função para gerar uma senha única para a fila Normal dentro do intevalo permitido(1 a 10);
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
    if(contN + contP==2){
        printf("Impossivel chamar! filas vazias!\n");
        menuCaixa();
    }if(contN==0 && contP==1){
        int senha=imprimeEcopiaSenhaPessoaChamadaNormal(filaNormal);  
        Pessoa* pessoa=criaPessoa(senha);       
        filaNormal=atualizarFilaNormal(filaNormal);                
        pilha=empilhar(pilha,pessoa); 
        menuCaixa();
    }if(contN==1 && contP==0){
        int senha=imprimeEcopiaSenhaPessoaChamadaPrioritaria(filaPrioritaria);  
        Pessoa* pessoa=criaPessoa(senha);       
        filaPrioritaria=atualizarFilaPrioritaria(filaPrioritaria);                
        pilha=empilhar(pilha,pessoa); 
        menuCaixa();

    }if(contN==0 && contP==0){
        if(verificarPilha(pilha)){
            int senha=imprimeEcopiaSenhaPessoaChamadaNormal(filaNormal);  
            Pessoa* pessoa=criaPessoa(senha);       
            filaNormal=atualizarFilaNormal(filaNormal);                
            pilha=empilhar(pilha,pessoa); 
            menuCaixa();
        }else{
            int senha=imprimeEcopiaSenhaPessoaChamadaPrioritaria(filaPrioritaria);  
            Pessoa* pessoa=criaPessoa(senha);       
            filaPrioritaria=atualizarFilaPrioritaria(filaPrioritaria);                
            pilha=empilhar(pilha,pessoa); 
            menuCaixa();
        }
        menuCaixa();
    }
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
