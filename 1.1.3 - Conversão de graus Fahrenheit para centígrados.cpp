// A conversão de graus Fahrenheit para centígrados é obtida por C := ( 5 / 9 ) * ( F - 32 );
// Fazer um algoritmo que calcule e escreva uma tabela de centígrados em função de graus fahrenheit, que
// variam de 50 a 150 de 1 em 1.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // deixa colocar acento no printf

int main(){
	printf("\n", setlocale(LC_ALL,"")); // printf... comando que ativa o locale.h
	printf("Tabela de centígrados em função de graus fahrenheit: \n");
	
	float C;
	
	for(int i=50; i<=150; i++){
		C = 5.0f / 9.0f *  (i - 32); // f --> tranforma o numero inteiro em ponto flutuante.
		printf("Fahrenheit = %d e em Centígrados = %g \n", i, C);
	}
}
