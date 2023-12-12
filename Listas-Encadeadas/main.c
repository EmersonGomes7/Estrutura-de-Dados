#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

int main(){
    Lista* lista = criaVazia();
    lista=insereNo(lista,2);
    lista=insereNo(lista,3);
    lista=insereNo(lista,4);
    lista=insereNo(lista,5);
    lista=insereNo(lista,6);
    mostraLista(lista);
    //free(l);
    return 0;
}
