#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // deixa colocar acento no printf
typedef struct{
	int I, J, K, L, V, n;
}var;

int main() {
	printf("", setlocale(LC_ALL,"")); // printf... comando que ativa o locale.h


var p; int i;

do{
	printf("Digite o valor a ser retirado ou zero para sair \n");
	scanf("%d", &p.V);
	if(p.V < 0){
		printf("O valor digitado não pode ser menor que zero! \n");
	}else{
		if(p.V == 0){
			printf("Saindo");
			i = 1;
		}else{
	while(p.V >= 50){
		p.V -= 50;
		p.n++;	
	}
	p.I = p.n;
	p.n = 0;
	
	while(p.V >= 10){
		p.V -= 10;
		p.n++;	
	}
	p.J = p.n;
	p.n = 0;
	
	while(p.V >= 5){
		p.V -= 5;
		p.n++;	
	}
	p.K = p.n;
	p.n = 0;
	
	while(p.V >= 1){
		p.V -= 1;
		p.n++;	
	}
	p.L = p.n;
	p.n = 0;
			printf("%d %d %d %d \n", p.I, p.J, p.K, p.L);
		}
	}
}while(i == 0);
}

