//Crie um programa em C, que contenha uma função recursiva que receba dois inteiros positivos k e n e calcule kn
//Utilize apenas multiplicações. O programa principal deve solicitar ao usuário os valores de k e n e imprimir o resultado da chamada da função. 
#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
int func(int k, int n, int i){
	if(n == 1){
		return k;
	}else{
		k = k * i;
		return func(k, n-1, i);
	}
}

int main(){
	int k, n, r, i;
	printf("Digite o valor de k: ");
	scanf("\n%d", &k);
	printf("Digite o valor de n: ");
	scanf("\n%d", &n);
	i = k;
	r = func(k, n, i);
	printf("\n R: %d", r);
	return 0;
}	




