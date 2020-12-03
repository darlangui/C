#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // deixa colocar acento no printf]


void troca(int *v, int n){
	int j, aux;
	for(int i = 0; i < n; i++){
		j=i;
		for(j; j < n; j++){
			if(v[i] < v[j]){
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			}
		}
	}

 
}

int main(){
	printf("", setlocale(LC_ALL,"")); // printf... comando que ativa o locale.h
	
	int n;
	int *v;
	
	printf("Digite o numero de valores: \n");
	scanf("%d", &n);
	
	v = (int *) malloc(n * sizeof(int));
	if(v == NULL){
		printf("Memória insuficiente!\n");
		exit(1); //aborta e retorna 1
	}
	printf("Digite os valores: \n");
	for(int i; i < n; i++){
		scanf("%d", &v[i]);
	}
	troca(v, n);
	
	printf("\n descrescente: \n");
	for(int i = 0; i < n; i++){
		printf(" %d ", v[i]);
	}
	
	printf("\n crescente: \n");
	for(int i = n - 1; i >= 0; i--){
		printf(" %d ", v[i]);
	}
	free(v); 
	return 0;
}
