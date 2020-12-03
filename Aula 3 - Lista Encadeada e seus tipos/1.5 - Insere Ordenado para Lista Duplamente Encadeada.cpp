#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

typedef struct lista{
	float info;
	struct lista* prox;
	struct lista* ant;
}Lista;

Lista* cria(void){
	return NULL;
}

Lista* insere(Lista* list, float v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
 	novo->info = v;
 	novo->prox = list;
 	novo->ant = NULL;
 	
 	/* verifica se lista não está vazia */
 	if (list != NULL){
 		list->ant = novo;
	}
 	
 	return novo;
}

Lista* insereOrdenado(Lista* list, float v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	Lista* p = list;
	Lista* ant = NULL;
	novo->info = v;
	if(list == NULL){
 		novo->prox = list;
 		novo->ant = NULL;
 		//printf("Primeiro elemento");
 		return novo;
 		
	}
	
	while (p != NULL && p->info < v) {
		ant = p;
		//printf("%0.0f", p->info);
		p = p->prox;
	}
		
	if(ant == NULL){ //adiciona no inicio
		//printf("NULL");
		novo->prox = list; 
		novo->ant = NULL;
		if (list != NULL){
			list->ant = novo;
		}
   	 	list = novo;
   	 	
	}else{
		novo->prox = ant->prox;
   	 	novo->ant = ant;
   	 	if (novo->prox != NULL){ // Eh o ultimo "a esquerda"
   	 		ant->prox->ant = novo;
		}	
   	 	ant->prox = novo;
    }
		return list;		
}		


void imprime(Lista* list){
	Lista* q;
	for(q = list; q!=NULL; q = q->prox){
		printf("%0.0f\n", q->info);
	}
	
}

int main(void){
	Lista* list = cria();
	list = insereOrdenado(list, 9);
	list = insereOrdenado(list, 10);
	list = insereOrdenado(list, 8);
	list = insereOrdenado(list, 5);
	list = insereOrdenado(list, 7);
	list = insereOrdenado(list, 6);
	//list = insereOrdenado(list, 12);
	//list = insereOrdenado(list, 11);
	//list = insereOrdenado(list, 10);
	
	imprime(list);
}
