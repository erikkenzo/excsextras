#include <stdio.h>
#include <stdlib.h>

// Função para comparar dois inteiros para qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Função para calcular a média
double calcularMedia(int arr[], int n) {
    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += arr[i];
    }
    return soma / n;
}

// Função para calcular a mediana
double calcularMediana(int arr[], int n) {
    // Ordena o array
    qsort(arr, n, sizeof(int), compare);

    if (n % 2 == 0) {
        // Se o número de elementos for par, a mediana é a média dos dois elementos do meio
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    } else {
        // Se o número de elementos for ímpar, a mediana é o elemento do meio
        return arr[n / 2];
    }
}

// Função para calcular a moda
int calcularModa(int arr[], int n) {
    int maxCount = 0, moda = arr[0], count = 1;

    // Ordena o array
    qsort(arr, n, sizeof(int), compare);

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            moda = arr[i];
        }
    }

    return moda;
}

int main() {
    int n;

    printf("Digite o número de elementos do array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    double media = calcularMedia(arr, n);
    double mediana = calcularMediana(arr, n);
    int moda = calcularModa(arr, n);

    printf("Media: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);

    return 0;
}
