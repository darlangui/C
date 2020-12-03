// Um exemplo simples de utilização da estrutura de fila é apresentado a seguir:

/* Módulo para ilustrar utilização da fila */
#include <stdio.h>
#include <stdlib.h>
//#include "fila.h"


// O nó da lista para armazenar valores reais, como já vimos, pode ser dado por:

struct no {
	float info;
	struct no* prox;
};

typedef struct no No;

// A estrutura da fila agrupa os ponteiros para o início e o fim da lista:

struct fila {
	No* ini;
	No* fim;
};

typedef struct fila Fila;

// A função cria aloca a estrutura da fila e inicializa a lista como sendo vazia.

Fila* cria (void)
{
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

// Cada novo elemento é inserido no fim da lista e, sempre que solicitado, retiramos o
// elemento do início da lista. Desta forma, precisamos de duas funções auxiliares de lista:
// para inserir no fim e para remover do início. A função para inserir no fim ainda não foi
// discutida, mas é simples, uma vez que temos explicitamente armazenado o ponteiro
// para o último elemento. Essa função deve ter como valor de retorno o novo “fim” da
// lista. A função para retirar do início é idêntica à função usada na implementação de
// pilha.

/* função auxiliar: insere no fim */

No* ins_fim (No* fim, float v)
{
	No* p = (No*) malloc(sizeof(No));
	p->info = v;
	p->prox = NULL;
	if (fim != NULL) /* verifica se lista não estava vazia */
		fim->prox = p;
	return p;
}

/* função auxiliar: retira do início */

No* ret_ini (No* ini)
{
	No* p = ini->prox;
	free(ini);
	return p;
}

// As funções que manipulam a fila fazem uso dessas funções de lista. Devemos salientar
// que a função de inserção deve atualizar ambos os ponteiros, ini e fim, quando da
// inserção do primeiro elemento. Analogamente, a função para retirar deve atualizar
// ambos se a fila tornar-se vazia após a remoção do elemento:

void insere (Fila* f, float v)
{
	f->fim = ins_fim(f->fim,v);
	if (f->ini==NULL) /* fila antes vazia? */
		f->ini = f->fim;
}

float retira (Fila* f)
{
	float v;
	if (f->ini==NULL) {
		printf("Fila vazia.\n");
		exit(1); /* aborta programa */
	}
	v = f->ini->info;
	f->ini = ret_ini(f->ini);
	if (f->ini == NULL) /* fila ficou vazia? */
		f->fim = NULL;
	return v;
}

// A fila estará vazia se a lista estiver vazia:

int vazia (Fila* f)
{
	return (f->ini==NULL);
}

// Por fim, a função que libera a fila deve antes liberar todos os elementos da lista.

void libera (Fila* f)
{
	No* q = f->ini;
	while (q!=NULL) {
		No* t = q->prox;
		free(q);
		q = t;
	}	
	free(f);
}

// Analogamente à pilha, para testar o código, pode ser útil implementarmos uma função
// que imprima os valores armazenados na fila. Os códigos abaixo ilustram a
// implementação dessa função nas duas versões de fila (vetor e lista). A ordem de
// impressão adotada é do início para o fim.

/* imprime: versão com lista */
void imprime (Fila* f)
{
	No* q;
	for (q=f->ini; q!=NULL; q=q->prox)
		printf("%0.2f\n",q->info);
}

int main (void)
{
	Fila* f = cria();
	Fila* z = cria();
	Fila* r = cria();
	float var;
	int i;
	do{
		printf("\n Digite o numero para inserido: ou 0 para sair:   ");
		scanf("%f", &var);
		if(var == 0){
		}else{
			do{
				printf("\n Digite a lista em que o elemento sera inserido 1 ou 2: ");
				scanf("%d", &i);
				switch(i){
					case 1:
					insere(f,var);
					insere(r,var);
					break;
					case 2:
						insere(z,var);
						insere(r,var);
					break;
					default:
						printf("\n Opção incorreta digite novamente!");
					break;
				}
			}while((i != 1) && (i != 2));
		}
	}while(var != 0);
	printf("Configuracao da fila:\n");
	imprime(f);
	printf("\n");
	imprime(z);
	printf("\n");
	imprime(r);
	libera(f);
	libera(z);
	libera(r);
	return 0;
}
