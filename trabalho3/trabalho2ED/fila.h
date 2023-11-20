#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct filaNormal FilaNormal;
typedef struct filaPrioritaria FilaPrioritaria;
FilaNormal* criaNormal();
FilaPrioritaria* criaPrioritaria();
FilaNormal *insereNormal(FilaNormal* fila);
FilaPrioritaria* inserePrioritaria(FilaPrioritaria* fila);
int quantidadeFilaNormal(FilaNormal* fila);
int quantidadeFilaPrioritaria(FilaPrioritaria* fila);
FilaNormal* atualizarFilaNormal(FilaNormal* fila);
int vaziaPrioritaria(FilaPrioritaria* fila);
int vaziaNormal(FilaNormal* fila);
int imprimeEcopiaSenhaPessoaChamada(FilaNormal* fila);

#endif // FILA_H_INCLUDED
