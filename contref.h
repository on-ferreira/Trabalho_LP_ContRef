#ifndef contref_h
#define contref_h

#include<stdio.h>
#include<stdlib.h>

typedef struct Contador{
    void *localnoheap;
    int ct;
    struct Contador *prox;
}Contador;

void atualizaREFs(void *locala, int x);

Contador * Ct0(Contador* h, Contador *aux, Contador *prim);

void dump();

void atrib2(void **a, void *b);

void *malloc2(int size);

#endif