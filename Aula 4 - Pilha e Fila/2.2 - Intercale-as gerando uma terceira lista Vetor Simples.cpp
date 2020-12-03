
#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

#define N 5
#define A 10

struct fila {
	int ini, fim;
	float vet[N];
};


typedef struct fila Fila;

struct terc {
	int ini, fim;
	float vet[A];
};


typedef struct terc Terc;

int incr (int i)
{
	if (i == N-1)
		return 0;
	else
		return i+1;
}

int incr1 (int i)
{
	if (i == A-1)
		return 0;
	else
		return i+1;
}
// A fun��o para criar a fila aloca dinamicamente essa estrutura e inicializa a fila como
// sendo vazia, isto �, com os �ndices ini e fim iguais entre si (no caso, usamos o valor
// zero).

Fila* cria (void)
{
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = f->fim = 0; /* inicializa fila vazia */
	return f;
}

Terc* cria1 (void)
{
	Terc* f = (Terc*) malloc(sizeof(Terc));
	f->ini = f->fim = 0; /* inicializa fila vazia */
	return f;
}

// Para inserir um elemento na fila, usamos a pr�xima posi��o livre do vetor, indicada por
// fim. Devemos ainda assegurar que h� espa�o para a inser��o do novo elemento, tendo
// em vista que trata-se de um vetor com capacidade limitada. Consideraremos que a
// fun��o auxiliar que faz o incremento circular est� dispon�vel.

void insere (Fila* f, float v)
{
	if (incr(f->fim) == f->ini) { /* fila cheia: capacidade esgotada */
		printf("Capacidade da fila estourou.\n");
		exit(1); /* aborta programa */
	}
	/* insere elemento na pr�xima posi��o livre */
	f->vet[f->fim] = v;
	f->fim = incr(f->fim);
}

void insere1 (Terc* f, float v)
{
	if (incr1(f->fim) == f->ini) { /* fila cheia: capacidade esgotada */
		printf("Capacidade da fila estourou.\n");
		exit(1); /* aborta programa */
	}
	/* insere elemento na pr�xima posi��o livre */
	f->vet[f->fim] = v;
	f->fim = incr1(f->fim);
}
// A fun��o para retirar o elemento do in�cio da fila fornece o valor do elemento retirado
// como retorno. Podemos tamb�m verificar se a fila est� ou n�o vazia.

float retira (Fila* f)
{
	float v;
	if (f->ini == f->fim) {
		printf("Fila vazia.\n");
		exit(1); /* aborta programa */
	}
	/* retira elemento do in�cio */
	v = f->vet[f->ini];
	f->ini = incr(f->ini);
	return v;
}

// A fun��o que verifica se a fila est� vazia pode ser dada por:

int vazia (Fila* f)
{
	return (f->ini == f->fim);
}

// Finalmente, a fun��o para liberar a mem�ria alocada pela fila pode ser:

void libera (Fila* f)
{
	free(f);
}

/* imprime: vers�o com vetor */

void imprime (Fila* f)
{
	int i;
	for (i=f->ini; i!=f->fim; i=incr(i))
		printf("%0.2f\n",f->vet[i]);
}

void imprime1 (Terc* f)
{
	int i;
	for (i=f->ini; i!=f->fim; i=incr(i))
		printf("%0.2f\n",f->vet[i]);
}

Terc* inverte(Fila* f, Fila* h){
	Terc* c;
	c = cria1();
	int i;
	for(i=f->ini; i!=f->fim; i=incr(i)){
	//	insere1(c, f->vet[i]);
	//	insere1(c, h->vet[i]);
		printf("%f\n", f->vet[i]);
		printf("%f\n", h->vet[i]);	
	}
	return c;
}
main() {
	Fila* f;
	Fila* h;
	f = cria();	
	h = cria();
	Terc* g = cria1();
	int i = 1;
	float var;
	while(i != 5){
		printf("\n Digite o valor para ser inserido na lista 1: ");
		scanf("%f", &var);
		insere(f, var);
		i++;
	}
	i = 1;
	while(i != 5){
		printf("\n Digite o valor para ser inserido na lista 2: ");
		scanf("%f", &var);
		insere(h, var);
		i++;
	}


	imprime(f);
	printf("\n");
	imprime(h);
	printf("\n");
	g = inverte(f, h);
	imprime1(g);
}
