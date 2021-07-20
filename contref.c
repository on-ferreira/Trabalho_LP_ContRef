#include "contref.h"

Contador* heap = NULL;

void *malloc2(int size){
    Contador *novo = malloc(sizeof(Contador));
    novo->localnoheap = malloc(size);
    novo->ct = 1;
    novo->prox = NULL;
    if (heap==NULL)  //Se a lista for vazia, ser� inserido como elemento �nico da lista
        heap = novo;
    else{
        Contador *aux = heap;
        while(aux->prox!=NULL) // Percorre a lista at� chegar na �ltima posi��o
            aux = aux->prox;
        aux->prox = novo; //Adiciona no final da lista
    }    
    return novo->localnoheap;
}

Contador *Ct0(Contador* h, Contador *aux, Contador *prim){
  if(prim->ct == 0){
    free(h);
		return aux;
  }
	else if(aux->ct == 0){
		h->prox = aux->prox;
    free(aux);
		return h;
	}
	else 
		return Ct0(h->prox,aux->prox,prim);
}
  

void atualizaREFs(void *locala, int x){
  Contador*aux = heap;
  while (aux!=NULL){
      if(aux->localnoheap == locala){
          aux->ct = aux->ct+x; 
      if(aux->ct==0)
        heap = Ct0(heap,heap->prox,heap);
      break;}
    aux = aux->prox;
  }
}

void atrib2(void **a, void *b){
    if(*a!=NULL){
      atualizaREFs(*a,-1); // Diminui um no contador da mem�ria alocada no endere�o a
      if(b!=NULL)
          atualizaREFs(b,1); //Aumenta um no contador da mem�ria alocada no endere�o b
    }
    *a=b;
}

void dump(){
  printf("\n\n DUMP!\n");
  Contador* aux=heap;
  while(aux!=NULL) {
      printf("Local no heap: %p  Contador: %d\n",aux->localnoheap, aux->ct);
      aux=aux->prox;
  }
}
