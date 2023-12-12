#ifndef PILHAVETOR_H_INCLUDED
#define PILHAVETOR_H_INCLUDED
typedef struct pilha Pilha;

int main(){
  Pilha *p1=criaPilha();
  push(p1,12);
  printf("deu certo");
}

#endif // PILHAVETOR_H_INCLUDED
