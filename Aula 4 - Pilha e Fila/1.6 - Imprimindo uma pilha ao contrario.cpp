
#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
typedef struct no{
	float info;
	struct no* prox;
}No;

typedef struct pilha{
	No* prim;
}Pilha;

Pilha* cria (){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

//final da inserção
No* ins_ini (No* l, float var){
	No* p = (No*) malloc(sizeof(No));
	p->info = var;
	p->prox = l;
	return p;
}
// Inicio da inserção
void push(Pilha* p, float var){
	p->prim = ins_ini(p->prim,var);
}

void libera(Pilha *p){
	No* q = p->prim;
	while(q!=NULL){
		No* t = q->prox;
		free(q);
		q = t;
	} 
	free(p);
}

void imprime(Pilha* p){
	No* q;
	printf("\nImprime Normal : \n");
	for(q=p->prim; q!=NULL; q=q->prox){
		printf("%0.2f\n", q->info);
	}
}



Pilha* inverte(Pilha* p){
	Pilha *v;
	v= cria();
	No* q;
	for(q=p->prim; q!=NULL; q=q->prox){
		push(v, q->info);
	}
	return v;
}

main(){
	Pilha *p;
	p = cria();
	float var;
	
	do{
		printf("Digite o valor a ser adicionado ou qualquer valor abaixo ou igual a 0 para sair: ");
		scanf("%f", &var);
		if(var > 0){
			push(p, var);
		}
	}while(var > 0);
	
	imprime(p);
	p = inverte(p);
	imprime(p);
	libera(p);
}
