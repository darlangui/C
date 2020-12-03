#include <stdio.h>
#include <stdlib.h>

typedef struct filaNo{
    int valor;
    struct filaNo *proximo;
}FilaNo;

typedef struct fila{
    FilaNo *inicio;
    FilaNo *final;
}Fila;

Fila *cria(void) {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    fila->inicio = fila->final = NULL;
    return fila;
}

FilaNo *criaNo(int valor) {
    FilaNo *filaNo = (FilaNo *) malloc(sizeof(FilaNo));
    filaNo->valor = valor;
    filaNo->proximo = NULL;
    return filaNo;
}

void insere(Fila *fila, int valor) {
    FilaNo *novo = criaNo(valor);
    if (fila->inicio == NULL)
        fila->inicio = novo;
    else
        fila->final->proximo = novo;
    fila->final = novo;
    novo->proximo = fila->inicio;
}

void imprime(Fila *fila) {
    FilaNo *p = fila->inicio;
    puts("Fila");
    while (1) {
        printf("valor %d\n", p->valor);
        if (p == fila->final)
            break;
        p = p->proximo;
    }
    puts("Fim");
}

int tamanho(Fila *fila) {
    int contador = 0;
    FilaNo *p = fila->inicio;
    while (1) {
        p = p->proximo;
        contador++;
        if (p == fila->final->proximo)
            break;

    }
    return contador;
}

void matar(Fila *fila, int primeiro) {
    int intervalo = primeiro, i = 1;
    FilaNo *percorre = fila->inicio;
    FilaNo *anterior = NULL;

    for (;;) {
        if (i == primeiro) {
            if (percorre == fila->inicio)
                fila->inicio = percorre->proximo;
            anterior->proximo = percorre->proximo;
            printf("Morreu %d\n", percorre->valor);
            primeiro += intervalo;
        }
        if (percorre == fila->final->proximo)
            percorre = fila->inicio;
        if (tamanho(fila) == 1)
            break;
        anterior = percorre;
        percorre = percorre->proximo;
        i++;
    }

    printf("Sobrevivente %d\n", percorre->proximo->valor);
}

int main() {
    int pessoas, primeiro;
    Fila *fila = cria();

    printf("Numero de pessoas\n");
    scanf("%d", &pessoas);

    for (size_t i = 1; i <= pessoas; ++i)
        insere(fila, i);

    printf("Primeiro a morrer\n");
    scanf("%d", &primeiro);

    imprime(fila);

    matar(fila, primeiro);

    system("pause");
}
