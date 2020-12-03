
/*Seja L uma lista simplesmente encadeada composta de números inteiros cujos nós são l1, l2, l3, ..., ln. Escreva
uma TAD que, percorrendo L, uma única vez, construa uma outra lista L’ formada dos seguintes elementos:
a) l2, l3, ..., ln, l1;
b) ln, ln-1 ,...,l1;
c) l1+ln, l2+ln-1, ..., ln/2+ln/2+1; onde n é par.	*/


#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */


struct lista {
		int info;
		struct lista* prox;
	};

typedef struct lista Lista;

struct no {
 int info;
 struct no* ant;
 struct no* prox;
};
typedef struct no No;


struct fila {
 No* ini;
 No* fim;
};

typedef struct fila Fila;

Lista* inicializa (void)
{
	return NULL;
}

Fila* cria (void)
{
 Fila* f = (Fila*) malloc(sizeof(Fila));
 f->ini = f->fim = NULL;
 return f;
}

/* função auxiliar: insere no início */
No* ins2_ini (No* ini, int v) {
 No* p = (No*) malloc(sizeof(No));
 p->info = v;
 p->prox = ini;
 p->ant = NULL;
 if (ini != NULL) /* verifica se lista não estava vazia */
 ini->ant = p;
 return p;
}
/* função auxiliar: insere no fim */
No* ins2_fim (No* fim, int v) {
 No* p = (No*) malloc(sizeof(No));
 p->info = v;
 p->prox = NULL;
 p->ant = fim;
 if (fim != NULL) /* verifica se lista não estava vazia */
 fim->prox = p;
 return p;
}


void insere_ini (Fila* f, int v) {
 f->ini = ins2_ini(f->ini,v);
 if (f->fim==NULL) /* fila antes vazia? */
 f->fim = f->ini;
}

void insere_fim (Fila* f, int v) {
 f->fim = ins2_fim(f->fim,v);
 if (f->ini==NULL) /* fila antes vazia? */
 f->ini = f->fim;
}

void imprimef (Fila* f)
{
 No* q;
 for (q=f->ini; q!=NULL; q=q->prox)
 printf("info = %d\n",q->info);
}

Lista* insere (Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	novo->info = i;
	novo->prox = l;
	return novo;
}



void imprime (Lista* l)
{
	Lista* p; /* variável auxiliar para percorrer a lista */
	
	for (p = l; p != NULL; p = p->prox)
		printf("info = %d\n", p->info);
		
/*	p = l;	
	do {
		printf("info = %d\n", p->info);
		p = p->prox;
	} while (p != NULL);	
	puts(""); */
}

int vazia (Lista* l)
{
	if (l == NULL)
		return 1;
	else
		return 0;
}

void libera (Lista* l) 
{
	Lista* p = l;

	while (p != NULL) {
		Lista* t = p->prox; /* guarda referência para o próximo elemento */
	
		free(p); /* libera a memória apontada por p */
		p = t; /* faz p apontar para o próximo */
	}
}

void Ta(Lista* l){  //FILA
	Lista* r;
	r = inicializa();
	
	Lista* p; /* variável auxiliar para percorrer a lista */
	for(p=l; p!=NULL; p=p->prox){
		if(p->prox == NULL){
			r = insere(r, p->info);
			Lista* q;
			for(q = l; q!=NULL; q=q->prox){
				if(q->prox == NULL){
				break;
				}else{
				r = insere(r, q->info);
				}
			}
		}
	}

	imprime(r);
	libera(r);
}

void Tb(Lista* l){       
	Lista* r;
	r = inicializa();
	
	Lista* p; /* variável auxiliar para percorrer a lista */
	
	for (p = l; p != NULL; p = p->prox){
		r = insere(r, p->info);
	}
	
	imprime(r);
	libera(r);	
}

void Tc(Lista* l){
	Fila* f;
	f = cria();
	Lista* r;
	r = inicializa();
	
	Lista* p; /* variável auxiliar para percorrer a lista */
	
	for (p = l; p != NULL; p = p->prox){
		insere_ini(f, p->info);	
	}
 	
	No* q;
	No* g;

 	q=f->ini;
 	g=f->fim;
 	r = insere(r, q->info);
 	r = insere(r, g->info);
 	do{
 		g = g->ant;
		q = q->prox;
		r = insere(r, q->info);
 		r = insere(r, g->info);
	 }while(q->prox!=g);
//	imprimef(f);
	imprime(r);
	libera(r);	
	
}
int main(){
	Lista *l;
	l = inicializa();
	l = insere(l, 10);
	l = insere(l, 11);
	l = insere(l, 12);
	l = insere(l, 13);
	printf("Normal : \n");
	imprime(l);
	printf("A : \n");
	Ta(l);
	printf("B : \n");
	Tb(l);
	printf("C: \n");
	Tc(l);
	libera(l);
	return 0;
}
