// A convers�o de graus Fahrenheit para cent�grados � obtida por C := ( 5 / 9 ) * ( F - 32 );
// Fazer um algoritmo que calcule e escreva uma tabela de cent�grados em fun��o de graus fahrenheit, que
// variam de 50 a 150 de 1 em 1.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // deixa colocar acento no printf

int main(){
	printf("\n", setlocale(LC_ALL,"")); // printf... comando que ativa o locale.h
	printf("Tabela de cent�grados em fun��o de graus fahrenheit: \n");
	
	float C;
	
	for(int i=50; i<=150; i++){
		C = 5.0f / 9.0f *  (i - 32); // f --> tranforma o numero inteiro em ponto flutuante.
		printf("Fahrenheit = %d e em Cent�grados = %g \n", i, C);
	}
}
