#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Implemente uma fun��o que verifique se duas listas encadeadas s�o iguais. Duas listas s�o consideradas iguais
//se t�m a mesma sequ�ncia de elementos. O prot�tipo da fun��o deve ser dado por:

struct lista{
	int i;
	struct lista* prox;
};

typedef struct lista Lista;

Lista* cria(void){
	return NULL;	
}

Lista* insere (Lista* list, int i){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	novo->i = i;
	novo->prox = list;
	return novo;
}

void imprime(Lista* list){
	
	Lista* p;
	
	for(p = list; p!=NULL; p=p->prox){
		printf("%d\n", p->i);
	}
	
}

int igual(Lista* l, Lista* i){
	Lista* q;
	Lista* p;
	
	p = l;
	q = i;
	
	do{
		if(p->i != q->i){
			return 1;
		}
		q = q->prox;
		p = p->prox;
	}while((p!=NULL) && (q!=NULL));
	
	return 0;
}


int main(){
	Lista* list = cria();
    list = insere(list, 5);
    list = insere(list, 10);
	list = insere(list, 15);
	list = insere(list, 20);
	
	printf("Lista 1: \n");
	imprime(list);
	
	Lista* tsil = cria();
    tsil = insere(tsil, 5);
    tsil = insere(tsil, 10);
	tsil = insere(tsil, 15);
	tsil = insere(tsil, 70);
	
	printf("\nLista 2:\n");
	imprime(tsil);
	
	if(igual(list, tsil) == 0){
		printf("\n S�o iguais!");
	}else{
		printf("\n N�o iguais!");
	}
	
	return 0;
}
