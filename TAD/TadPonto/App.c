#include <stdio.h>
#include "ponto.h"
int main(){
    Ponto *meuponto1=cria(2.2,3.3);
    Ponto *meuponto2=cria(1.1,4.4);

    printf("dinstancia: %.1f",distancia(meuponto1,meuponto2));
    
    float x,y;
    acessa(meuponto1,&x,&y);
    printf("ponto1: %.1f,%.1f\n",x,y);
}
