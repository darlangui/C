#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // deixa colocar acento no printf
#include <string.h>

typedef struct no{
	int i;
	char nome[21];
	struct no* prox;	
}No;

typedef struct fila{
	No* ini;
	No* fim;
}Fila;

Fila* cria (void)
{
 	Fila* f = (Fila*) malloc(sizeof(Fila));
 	f->ini = f->fim = NULL;
 	return f;
}

No* ins_fim (No* fim, int i, char* nome)
{
 No* p = (No*) malloc(sizeof(No));
 p->i = i;
 strcpy(p->nome, nome);
 p->prox = NULL;
 if (fim != NULL) /* verifica se lista não estava vazia */
 fim->prox = p;
 return p;
}

void insere (Fila* f,  char *v, int i)
{
 	f->fim = ins_fim(f->fim, i, v);
 	if (f->ini==NULL) /* fila antes vazia? */
 	f->ini = f->fim;
}


int vazia (Fila* f)
{
 return (f->ini==NULL);
}


/* função auxiliar: retira do início */
No* ret_ini (No* ini)
{
 No* p = ini->prox;
 free(ini);
 return p;
}


float retira (Fila* f)
{
 int v;
 char nome[21];
 if (vazia(f)) {
 printf("Fila vazia.\n");
 exit(1); /* aborta programa */
 }
 v = f->ini->i;
 //strcpy(nome, f->ini->nome);
 f->ini = ret_ini(f->ini);
 if (f->ini == NULL) /* fila ficou vazia? */
 f->fim = NULL;
 return v;
}


/* imprime: versão com lista */
void imprime (Fila* f)
{
	printf("\nFila : \n");
 	No* q;
 	for (q=f->ini; q!=NULL; q=q->prox){
 		printf("Número: %d   Nome: %s",q->i, q->nome);	
	}
}

int main(void){
	printf("", setlocale(LC_ALL,"")); // printf... comando que ativa o locale.h
	Fila* fila = cria();
	int i = 0;
	int z = 0;
	int tam = 0;
	char nome[21];
	do{
		printf("\nEscolha: \n");
		printf("1 - Listar número de aviões aguardando na fila\n");
		printf("2 - Autorizar a decolagem do primeiro avião da fila\n");
		printf("3 - Adicionar avião na fila\n");
		printf("4 - Listar todos os aviões na fila\n");
		printf("5 - Listar as caracteristicas do primeiro avião da fila\n");
		printf("6 - Sair\n");
		scanf("%d", &i);
		fflush(stdin);
		switch(i){
			case 1:
				printf("\n Atualmente há %d aviões na fila", tam);
			break;
			case 2:
				if(fila->ini == NULL){
					printf("\n fila vazia!");
				}else{
				tam--;
				printf("\n O avião %s decolou!", fila->ini->nome);
				retira(fila);
				}
			break;
			case 3:
				printf("\n Digite o nome do avião: ");
				fflush(stdin);
				fgets(nome, sizeof(nome), stdin);
				printf("\n Digite o número de identificação do avião: ");
				scanf("%d", &z);
				tam++;
				insere(fila, nome, z);
			break;
			case 4:
				imprime(fila);
			break;
			case 5:
				if(fila->fim == NULL){					
					printf("Fila esta vazia");
				}else{
					printf("\nPrimeiro avião: ");
					printf("\n Nome: %s Número: %d", fila->ini->nome, fila->ini->i);
				}
				break;
			case 6:
				printf("\n Fechando!");
				exit(1);
				break;
			default:
				printf("\n Opção incorreta! Tente Novamente! \n");
			break;
		}
		
	}while(i != 6);
	
	
}
