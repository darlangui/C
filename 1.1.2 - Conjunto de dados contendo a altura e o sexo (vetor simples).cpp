#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // deixa colocar acento no printf

// estrutura de dados (Struct)
// armazena idade e altura 
struct dados {
	int sexo[5];
	float altur[5];
};
//Definindo o novo tipo (Dados) baseado na estrutura de dados(dados)
typedef struct dados Dados;


int main(){
	printf("", setlocale(LC_ALL,"")); // printf... comando que ativa o locale.h
	Dados g;

	for(int i = 0; i < 5; i++){
		printf("Digite seu sexo: \n");
		printf("1 - Masculino \n");
		printf("2 - Feminino \n");
		scanf("%d", &g.sexo[i]);
		
		if(g.sexo[i] == 0){
			printf("Fechando!");
			exit(1);
		}
		
		if((g.sexo[i] != 1) && (g.sexo[i] != 2)){
			printf("Incorreto valor não encontrado. Tente Novamente ou digite 0 para sair \n");
			i = i - 1;
			} else{
				printf("Digite sua altura: ");
				scanf("%f", &g.altur[i]);	
				}
	}
			
		
	
		
	
	for(int i = 0; i < 5; i++){
		if(g.sexo[i] == 1){
			printf("\n Masculino   Altura: ");
		}else{
			printf("\n Feminino   Altura: ");
		}
			printf("%0.2f \n", g.altur[i]);
		}
	float menor = 0;
	float maior = 0;
	float media = 0;
	int hom = 0;
	int mul = 0;
	
	for(int i=0; i < 5; i++){
		
		if((menor == 0) || (maior ==0)){
			menor = g.altur[i];
			maior = g.altur[i];
		}
		if(g.altur[i] < menor){
			menor = g.altur[i];
		}
		
		if(g.altur[i] > maior){
			maior = g.altur[i];
		}	
		
		if(g.sexo[i] == 2){
			media = media + g.altur[i];
			mul++;
		}
		
		if(g.sexo[i] == 1){
			hom++;
		}
	}
	media = media/ (float) mul;
	printf("\n Maior altura: %f    Menor altura: %f", maior, menor);
	printf("\n Média da altura das mulheres: %f ", media);
	printf("\n Número de homens: %d", hom);
	return 0;
}
