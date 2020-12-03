#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // deixa colocar acento no printf

//Dados 3 valores inteiros, leia-os em qualquer ordem e mostre-os em ordem crescente e decrescente.




void troca(int *pa, int *pb, int *pc){
	int aux;
	if(*pa > *pb){
		aux = *pb;
		*pb = *pa;
		*pa = aux;
	}
	if(*pb > *pc){
		aux = *pc;
		*pc = *pb;
		*pb = aux;
	}
	if(*pa > *pb){
		aux = *pb;
		*pb = *pa;
		*pa = aux;
	}
}


int main(){
	printf("", setlocale(LC_ALL,"")); // printf... comando que ativa o locale.h
	int a, b, c;
	printf("Digite 3 números inteiros: \n");
	scanf("%d %d %d", &a, &b, &c);
	troca(&a, &b, &c); //passando o endereço da variavel
	printf("\n Ordem crescente: %d %d %d \n", a, b, c);
	printf("\n Ordem decrescente: %d %d %d \n", c, b, a);
	return 0;
}
