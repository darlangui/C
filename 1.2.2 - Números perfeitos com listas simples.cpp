#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // deixa colocar acento no printf
//fun��o recursiva 
int divisores(int num, int cont, int soma){
	if(num > cont){
		if((num % cont) == 0){
		soma = soma + cont;
		}
		divisores(num, cont+1, soma);	
	}else{
			return soma;
	}		
}

int main(){
	printf("", setlocale(LC_ALL,"")); // printf... comando que ativa o locale.h
	int num;
	int soma = 0;
	do{
		printf("\n Digite um n�mero ou zero para sair : ");
		scanf("%d", &num);
		if(num == 0){
			
		}else{
			if(num == 1){
				printf("N�mero perfeito!");
			}else{
				soma = divisores(num, 1, 0);
				if(soma == num){
				printf("N�mero perfeito!");
				}else{
				printf("N�mero n�o perfeito");
				}
			}
		}
	}while(num != 0);

	
	
	return 1;
}
