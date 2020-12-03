#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // deixa colocar acento no printf

struct matriz {
	int m;
	int n;
	float** mat;
};

typedef struct matriz Matriz;


Matriz* cria(int m, int n){
	Matriz* mat = (Matriz*) malloc(sizeof(Matriz)); //alocação da matriz
	
	if (mat == NULL) {  //teste pra ver se tem memoria
		printf("Memória insuficiente!\n");
		exit(1);
	}
	
	mat->m = m; // m do struct recebe m
	mat->n = n; // n do struct recebe n
	
	mat->mat = (float**) malloc(m*sizeof(float*)); //alocação da matriz que esta no struct
	for (int i=0; i<m; i++){
		mat->mat[i] = (float*) malloc(n*sizeof(float));
	}
	return mat;
}


void atribui(Matriz *mat, float num, int i, int j){
	if (i<0 || i>=mat->m || j<0 || j>=mat->n) {
		printf("Atribuição inválida!\n");
		exit(1);
	}
	mat->mat[i][j] = num;
}

int verifica(Matriz* mat, int m, int n){
	if(m == n){
	int h = 0;
	for (int i=0; i<m; i++){
	 	for (int j=0; j<n; j++){
	 		if(i == j){
	 			
			}else{
				printf("%0.0f ", mat->mat[i][j]);
				if(mat->mat[i][j] != mat->mat[j][i]){
					return 0;
				}
			}
	 	
	 		if(j == n - 1){
	 			printf("\n");
			}
		 }	
	}
		
	}else{
		printf("Matriz não é simetrica quadrada!");
	}
	return 1;
}

int main(){
	printf("", setlocale(LC_ALL,"")); // printf... comando que ativa o locale.h
	Matriz* mat;
	int m, n;
	int teste;
	float num;
	printf("colunas da matriz: ");
	scanf("%d", &n);
	printf("linhas da matriz: ");
	scanf("%d", &m);
	
	mat = cria(m,n);
	
	for (int i=0; i<m; i++){
	 	for (int j=0; j<n; j++){
	 		scanf("%f", &num); 
	 		
	 		atribui(mat, num, i, j);
		 }	
	}
 	printf("\n");
 	
 	printf("Matriz: \n");
	for (int i=0; i<m; i++){
	 	for (int j=0; j<n; j++){
	 		printf("%0.0f ", mat->mat[i][j]);
	 		if(j == n - 1){
	 			printf("\n");
			}
		 }	
	}
	printf("\n");
	teste = verifica(mat, m, n);
	if(teste == 1){
		printf("Matriz é simetrica quadrada!");
	}else{
		printf("Matriz não é simetrica quadrada!");
	}
	
	return 0;
}
