#include <stdio.h>
#include <stdlib.h>

// Função para inverter um array usando ponteiros
int* inverterArray(int *array, int tamanho) {
    int *arrayInvertido = malloc(tamanho * sizeof(int)); // Aloca memória para o novo array invertido

    if (arrayInvertido == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    int *ptrOriginal = array + tamanho - 1; // Ponteiro para o último elemento do array original
    int *ptrInvertido = arrayInvertido; // Ponteiro para o primeiro elemento do array invertido

    // Copia os elementos do array original para o novo array invertido, em ordem inversa
    for (int i = 0; i < tamanho; i++) {
        *ptrInvertido = *ptrOriginal; // Copia o valor apontado pelo ponteiro original para o ponteiro invertido
        ptrOriginal--; // Move o ponteiro original para o elemento anterior
        ptrInvertido++; // Move o ponteiro invertido para o próximo elemento
    }

    return arrayInvertido; // Retorna o novo array invertido
}

// Função para imprimir um array
void imprimirArray(int *array, int tamanho) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int main() {
    int tamanho;

    // Pedir ao usuário o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    // Alocar memória para o array
    int *array = malloc(tamanho * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Pedir ao usuário os elementos do array
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Inverter o array
    int *arrayInvertido = inverterArray(array, tamanho);

    // Imprimir o array original e o array invertido
    printf("\nArray original: ");
    imprimirArray(array, tamanho);
    printf("Array invertido: ");
    imprimirArray(arrayInvertido, tamanho);

    // Liberar memória alocada para os arrays
    free(array);
    free(arrayInvertido);

    return 0;
}
