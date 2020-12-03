#include <stdio.h>
#include <stdlib.h>

int soma(int *vet, int i, int result){
	if(i == 10){
		return result;
	}else{
		result = result + vet[i];
		i++;
		return soma(vet, i, result);
	}
}

int main(void){
	int vet[10];
	int retult;
	for(int i = 0; i < 10; i++){
		scanf("%d", &vet[i]);
    }
	
	for(int i = 0; i < 10; i++){
		printf("%d ", vet[i]);
    }
	int i = 0;
	int result = 0;
	result = soma(vet, i, result);
	printf("Soma: %d", result);
	return 0;
}
