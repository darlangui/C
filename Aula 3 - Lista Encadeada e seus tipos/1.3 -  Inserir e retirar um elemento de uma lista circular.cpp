#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

typedef struct lista{
	int info;
	struct lista *prox;
}Lista;



typedef struct plista{
	Lista *inicio;
	Lista *fim;
}PLista;

//DEFINE COMO NULO O INICIO DA LISTA
void iniciar(PLista *l){
	l->inicio = NULL;
	l->fim = NULL;
}

//inserir
void inserir(PLista *l){
	Lista* novo = (Lista*) malloc(sizeof(Lista)); //alocação na memoria
	
	printf("\n Digite o número que sera adicionado a lista: ");
	scanf("%d", &novo->info);
	
	novo->prox = NULL;
	
	if(l->inicio == NULL){
		l->inicio = novo;
	}else{
		l->fim->prox = novo;
	}
	
	//deixa a lista circular
	l->fim = novo;
	novo->prox = l->inicio;
}

void imprime(PLista *l){
	Lista *p;
	if(l->inicio == NULL){
		printf("Fim da lista!");
		return;
	}else{
		//p recebe o inicio de circu
		p = l->inicio;
		do{
			printf("%d\n", p->info);
			p = p->prox;
		}while (p != l->inicio);
	}	
}


void remover(PLista *l){
	if(l->inicio == NULL){
		printf("\n Lista vazia!");
	}else{
		Lista *at, *ant; // Atual - Anterior
		int pesquisa; 
		
		// procura o valor a ser excluido
		printf("\n Infrome o dado a ser excluido: ");
		scanf("%d", &pesquisa);
		
		at = l->inicio;
		ant = l->inicio;
		
		do{ 
			if(at->info == pesquisa){
				// se o elemento esta no inicio da lista
				if(at == l->inicio){
					l->inicio = at->prox; // l do inicio recebe o proximo do atual
					l->fim->prox = at->prox; // l (o ultimo do proximo que seria o primeiro da lista) recebe o proximo do atual
					free(at); //libero o atual (dado excluido)
					break; // para o do while
				}else{ //caso não seja o primeiro
					ant->prox = at->prox; //proximo do anterior recebe o proximo do atual basicamento o 2° da lista
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
int main(){

	int num;
	int teste = 0;
	
	PLista listaCircular;
	
	iniciar(&listaCircular);
	
	do{
		printf("\n MENU: \n");
		printf("\n 1 - inserir elemento na lista");
		printf("\n 2 - remover elemento da lista");
		printf("\n 3 - imprime lista");
		printf("\n 0 -  Sair \n \n");
		scanf("%d", &num);
		switch(num){
			case 1:
				inserir(&listaCircular);
			break;
			case 2:
				remover(&listaCircular);
			break;
			case 3:
				imprime(&listaCircular);
			break;
			case 0:
				printf("\n Fechando!");
				teste = 1;
				return 0;
			break;
			default:
				printf("\n opção invalida!");
			break;
		}
	
	}while(teste == 0);
	return 0;
}


