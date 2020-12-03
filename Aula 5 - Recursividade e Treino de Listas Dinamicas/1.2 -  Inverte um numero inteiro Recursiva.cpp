//Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321 

#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */


int func(int n){
    if(n==0){
    	return n;
	}else{
     printf("%d", n % 10); // mostra cada digito do numero invertendo
     n = n / 10;
     return func(n);
    }
 }
int main(){
	int n;
    printf("Digite um numero inteiro:");
    scanf("\n%d",&n);
    printf("\n");
    func(n);
    return 0;
}
