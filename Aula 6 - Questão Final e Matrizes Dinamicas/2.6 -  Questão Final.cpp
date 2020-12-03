#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cidade {
 char nome[21];
 struct cidade* ant;  
 struct cidade* prox;
};

typedef struct cidade Cidade;

struct br {
    char name[21];
    Cidade* nome;
    struct br* prox;
    struct br* fim; 
    struct br* ini;
};

typedef struct br Br;

Cidade* criaCity(void) {
    Cidade* i = (Cidade*) malloc(sizeof(Cidade));
    i->ant = i->prox = NULL;
    return i;
}

Br* cria (void){
	Br* p = (Br*) malloc(sizeof(Br));
	p->prox = NULL;
	p->ini = NULL;
	p->fim = NULL;
	return p;
}

Cidade* insereCidade(Br* l, char* v){
	Cidade* novo = (Cidade*) malloc(sizeof(Cidade));
    strcpy(novo->nome, v);
    
    novo->prox = l->prox->nome->prox;
    novo->ant = NULL;
    if (l->prox->nome != NULL)
        l->prox->nome->ant = novo;
    //l->prox->nome->prox = novo;
    return novo;
}

Br* insereRod(Br* i, char *v) {
    Br* novo = (Br*) malloc(sizeof(Br));
    strcpy(novo->name, v); //copia
    
    novo->nome = criaCity(); //aloca espa?o pra outra struct
    
    novo->prox = i->prox;
    i->prox = novo;
    i->fim = novo;
    
    if (i->ini == NULL){
    	 i->ini = novo;
	}
	
	return novo;
}

Cidade* insereOrdem(Br* l, char* v) {
    Cidade *novo = (Cidade*) malloc(sizeof(Cidade));
    strcpy(novo->nome, v);
    
    Cidade* p;
    for (p = l->prox->nome; p->prox != NULL; p = p->prox){
    	 if (strcmp(p->prox->nome, v) <= 0){
    	 	 break;
		 }  
	}

    novo->prox = NULL;
    novo->ant = NULL;
    if (p != NULL)
        novo->ant = p;
    if (p->prox != NULL) {
        novo->prox = p->prox;
        p->prox->ant = novo;
    }
    p->prox = novo;
    return novo;
}

Br* rodCity(Br* l, char* v){
	Br* rd = cria();
    rd->nome = NULL;
    Br* p;
    Cidade* pc;
    for (p = l->prox; p != NULL; p = p->prox) {
        for (pc = p->nome->prox; pc != NULL; pc = pc->prox)
            if (strcmp(pc->nome, v) == 0) {
                Br* novo = (Br*) malloc(sizeof(Br));
                novo->nome = NULL;
                strcpy(novo->name, p->name);
                novo->prox = rd->prox;
                rd->prox = novo;
                break;
            }
    }
    return rd;
}

int cruza(Br* l, char* rod, char* rod2) {
    Br* p1;
    Br* p2;
    Cidade* pc1;
	Cidade* pc2;
	
    for (p1 = l->prox; p1 != NULL; p1 = p1->prox)
        if (strcmp(p1->name, rod) == 0)
            for (p2 = l->prox; p2 != NULL; p2 = p2->prox)
                if (strcmp(p2->name, rod2) == 0)
                    for (pc1 = p1->nome->prox; pc1 != NULL; pc1 = pc1->prox)
                        for (pc2 = p2->nome->prox; pc2 != NULL; pc2 = pc2->prox)
                            if (strcmp(pc1->nome, pc2->nome) == 0)
                                return 1;
    return 0;
}

void imprime(Br* l) {
    Br* p;
    Cidade* pc;
    for (p = l->prox; p != NULL; p = p->prox) {
        printf("Rodovia %s\n", p->name);
        if (p->nome != NULL)
            for (pc = p->nome->prox; pc != NULL; pc = pc->prox)
                printf("Cidade %s\n", pc->nome);
    }
}

int main(void) {
    Br* lista = cria();
    char palavra[21];
    strcpy(palavra, "BR123");
    insereRod(lista, palavra);
    
    strcpy(palavra, "Alert");
    lista->prox->nome->prox = insereCidade(lista, palavra);
    
    strcpy(palavra, "Blert");
    lista->prox->nome->prox = insereCidade(lista, palavra);
    
    strcpy(palavra, "Dlert");
    lista->prox->nome->prox = insereCidade(lista, palavra);
    
    strcpy(palavra, "Clert");
    insereOrdem(lista, palavra); 
    
    
    
    
    strcpy(palavra, "BR456");
    insereRod(lista, palavra);
    
    strcpy(palavra, "Flert");
    lista->prox->nome->prox = insereCidade(lista, palavra);
    
    strcpy(palavra, "Glert");
    lista->prox->nome->prox = insereCidade(lista, palavra);
    
    strcpy(palavra, "Zlert");
    lista->prox->nome->prox = insereCidade(lista, palavra);
    
    strcpy(palavra, "Hlert");
    insereOrdem(lista, palavra);
    
    
    
    strcpy(palavra, "Flert");
    Br *listaCity = rodCity(lista, palavra); 
    
    strcpy(palavra, "BR456");
    char palavra2[21];
     strcpy(palavra2, "BR123");
    if(cruza(lista, palavra, palavra2) == 0){
    	printf("N?o cruza \n");
	}else{
		printf("Cruza! \n");
	}
	
    imprime(lista);
    system("pause");
}
