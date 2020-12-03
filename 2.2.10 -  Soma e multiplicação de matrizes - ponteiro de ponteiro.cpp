#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // deixa colocar acento no printf

struct matriz {
	int m;
	float** mat;
};

typedef struct matriz Matriz;

Matriz* cria(int m){
	Matriz* mat = (Matriz*) malloc(sizeof(Matriz)); //alocação da matriz
	if (mat == NULL) {  //teste pra ver se tem memoria
		printf("Memória insuficiente!\n");
		exit(1);
	}
	mat->m = m; // m do struct recebe m
	mat->mat = (float**) malloc(m*sizeof(float*)); //alocação da matriz que esta no struct
	for (int i=0; i<m; i++){
		mat->mat[i] = (float*) malloc(m*sizeof(float));
	}
	
	return mat;
}

void atribui(Matriz *mat, float num, int i, int j){
	if (i<0 || i>=mat->m || j<0 || j>=mat->m) {
		printf("Atribuição inválida!\n");
		exit(1);
	}
	mat->mat[i][j] = num;
}

void soma(Matriz *mat, Matriz *mat2, Matriz *result2, int j, int i){
	float num;
	num = mat->mat[i][j] + mat2->mat[i][j];
	result2->mat[i][j] = num;
}

void multiplica(Matriz *mat, Matriz *mat2, Matriz *result, int j, int i, int m){
	for (int k=0; k<m; k++) {
          result->mat[i][j] += mat->mat[i][k] * mat2->mat[k][j]; 
}	
}

int main(){
	Matriz *mat, *mat2, *result, *result2;
	printf("", setlocale(LC_ALL,"")); // printf... comando que ativa o locale.h
	int m, n;
	float num;
	//aloca a matriz
	printf("Digite a ordem da matriz quadrada 1: ");
	scanf("%d", &m);
	mat = cria(m);

   //adiciona valor a matriz
	for (int i=0; i<m; i++){
	 	for (int j=0; j<m; j++){
	 		scanf("%f", &num); 
	 		atribui(mat, num, i, j);
		 }	
	}
 	printf("\n");
 	
 	printf("Digite a ordem da matriz quadrada 2: ");
	scanf("%d", &n);
	mat2 = cria(n);

   //adiciona valor a matriz
	for (int i=0; i<n; i++){
	 	for (int j=0; j<n; j++){
	 		scanf("%f", &num); 
	 		atribui(mat2, num, i, j);
		 }	
	}
 	printf("\n");
	
	//soma
	if(m == n){
		result = cria(m);
		for (int i=0; i<m; i++){
	 		for (int j=0; j<m; j++){
	 			soma(mat, mat2, result, i, j);
		 	}	
		}
		printf("Matriz 1: \n");
			for (int i=0; i<m; i++){
	 	for (int j=0; j<m; j++){
	 		printf("%0.0f ", mat->mat[i][j]);
	 		if(j == m - 1){
	 			printf("\n");
			}
		 }	
	}
 		
 		printf("\n");

 	//mostra  a matriz
 	printf("Matriz 2: \n");
	for (int i=0; i<n; i++){
	 	for (int j=0; j<n; j++){
	 		printf("%0.0f ", mat2->mat[i][j]);
	 		if(j == n - 1){
	 			printf("\n");
			}
		 }	
	}
	
		printf("\n");
	printf("Matriz resultante da soma: \n");
	for (int i=0; i<n; i++){
	 	for (int j=0; j<n; j++){
	 		printf("%0.0f ", result->mat[i][j]);
	 		if(j == n - 1){
	 			printf("\n");
			}
		 }	
	}
	}else{
		printf("A ordem das matrizes são diferentes!\n");
	}
	
	//multiplicação
	if(m == n){
		result2 = cria(m);
		for (int i=0; i<m; i++){
	 		for (int j=0; j<m; j++){
	 			multiplica(mat, mat2, result2, i, j, m);
		 	}	
		}
		
		printf("Resultante da multiplicação: \n");
		for (int i=0; i<n; i++){
	 		for (int j=0; j<n; j++){
	 			printf("%0.0f ", result2->mat[i][j]);
	 			if(j == n - 1){
	 				printf("\n");
				}
		 	}	
		}
	}else{
		printf("Número de colunas da primeira deve ser igual ao número de linhas da segunda.\n");
	}

	for (int i=0; i<m; i++)
		free(mat->mat[i]);
	free(mat);
	for (int i=0; i<m; i++)
		free(mat2->mat[i]);
	free(mat);
	for (int i=0; i<m; i++)
		free(result2->mat[i]);
	free(mat);
}
