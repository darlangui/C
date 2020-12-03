#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

typedef struct no{
	float info;
	struct no *prox;
	struct no* ant;
}No;

typedef struct lista{
	No *inicio;
	No *fim;
}Lista;

Lista* cria(){
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->fim = NULL;
	l->inicio = NULL;	
}

No* inserir(Lista* list, float v){
	No* novo = (No*) malloc(sizeof(No)); //alocação na memoria
	
	novo->info = v;
	
	novo->prox = NULL;
	novo->ant = NULL;
	
	if(list->inicio == NULL){ //verifica se a lista esta vazia
		list->inicio = novo; //primeiro elemento!
	}else{
		list->fim->prox = novo;
		list->inicio->ant = novo;
	}
	
	//deixa a lista circular
	novo->prox = list->inicio;
	novo->ant = list->fim;
	return novo;
}

void imprime(Lista *l){
	No *p;
	if(l->inicio == NULL){
		printf("Lista Vazia");
		return;
	}else{
		//p recebe o inicio de circu
		p = l->inicio;
		do{
			printf("%0.0f\n", p->info);
			p = p->prox;
		}while (p != l->inicio);
	}	
}



void remover(Lista *l){
	if(l->inicio == NULL){
		printf("\n Lista vazia!");
	}else{
		No *at, *ant; // Atual - Anterior
		float pesquisa; 
		
		// procura o valor a ser excluido
		printf("\n Infrome o dado a ser excluido: ");
		scanf("%f", &pesquisa);
		
		at = l->inicio;
		ant = l->inicio;
		
		do{ 
			if(at->info == pesquisa){
				// se o elemento esta no inicio da lista
				if(at == l->inicio){
					l->inicio = at->prox; // l do inicio recebe o proximo do atual
					l->fim->prox = at->prox; // l (o ultimo do proximo que seria o primeiro da lista) recebe o proximo do atual
					l->inicio->ant = l->fim;
					free(at); //libero o atual (dado excluido)
					break; // para o do while
				}else{ //caso não seja o primeiro
					ant->prox = at->prox; //proximo do anterior recebe o proximo do atual basicamento o 2° da lista
					at->prox->ant = ant;
					if(at == l->fim){ // caso seja o ultimo da lista
					l->fim = ant; // o ultimo de l recebe o anterior 
					}
					free(at); // libera o ultimo da lista
					break;
				}
			}else{
				ant = at; // anterior recebe o atual 
				at = at->prox; // atual recebe o proximo
			}
		}while(at != l->inicio);
	}
}

int main(void){
	Lista* list;
	list = cria();
	
	list->fim = inserir(list, 14);
	list->fim = inserir(list, 15);
	list->fim = inserir(list, 16);
	list->fim = inserir(list, 17);
	list->fim = inserir(list, 18);
	list->fim = inserir(list, 19);
	
	imprime(list);
	
	remover(list);
	
	printf("\n");
	
	list->fim = inserir(list, 10);
	
	imprime(list);
	
	return 0;
}

