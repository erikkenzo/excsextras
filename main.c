#include <stdio.h>

// Função para solicitar elementos e calcular a soma
void somaDosElementos(int array[], int tamanho) {
    int soma = 0;

    // Solicita ao usuário inserir os elementos do array
    printf("Insira os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
        soma += array[i];
    }

    // Imprime a soma dos elementos
    printf("A soma dos elementos do array é: %d\n", soma);
}

int main() {
    int tamanho;

    // Solicita ao usuário inserir o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    // Declara um array com o tamanho especificado
    int array[tamanho];

    // Chama a função para calcular a soma dos elementos
    somaDosElementos(array, tamanho);

    return 0;
}
