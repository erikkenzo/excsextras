#include <stdio.h>
#include <stdlib.h>

// Função para multiplicar duas matrizes
int **multiplicarMatrizes(int **matriz1, int **matriz2, int linhas1, int colunas1, int colunas2) {
    int **resultado;
    resultado = (int **)malloc(linhas1 * sizeof(int *));
    for (int i = 0; i < linhas1; i++) {
        resultado[i] = (int *)malloc(colunas2 * sizeof(int));
    }

    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < colunas1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    return resultado;
}

// Função para transpor uma matriz
int **transporMatriz(int **matriz, int linhas, int colunas) {
    int **transposta;
    transposta = (int **)malloc(colunas * sizeof(int *));
    for (int i = 0; i < colunas; i++) {
        transposta[i] = (int *)malloc(linhas * sizeof(int));
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
    return transposta;
}

// Função para liberar memória alocada para matriz
void liberarMemoria(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// Função para imprimir uma matriz
void imprimirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhas1, colunas1, linhas2, colunas2;

    printf("Informe o número de linhas e colunas da primeira matriz: ");
    scanf("%d %d", &linhas1, &colunas1);

    printf("Informe o número de linhas e colunas da segunda matriz: ");
    scanf("%d %d", &linhas2, &colunas2);

    if (colunas1 != linhas2) {
        printf("As matrizes não podem ser multiplicadas. O número de colunas da primeira matriz deve ser igual ao número de linhas da segunda matriz.\n");
        return 1;
    }

    // Alocar memória para as matrizes
    int **matriz1 = (int **)malloc(linhas1 * sizeof(int *));
    for (int i = 0; i < linhas1; i++) {
        matriz1[i] = (int *)malloc(colunas1 * sizeof(int));
    }

    int **matriz2 = (int **)malloc(linhas2 * sizeof(int *));
    for (int i = 0; i < linhas2; i++) {
        matriz2[i] = (int *)malloc(colunas2 * sizeof(int));
    }

    printf("Informe os elementos da primeira matriz:\n");
    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas1; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("Informe os elementos da segunda matriz:\n");
    for (int i = 0; i < linhas2; i++) {
        for (int j = 0; j < colunas2; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Multiplicar as matrizes
    int **resultadoMultiplicacao = multiplicarMatrizes(matriz1, matriz2, linhas1, colunas1, colunas2);

    printf("\nResultado da multiplicação:\n");
    imprimirMatriz(resultadoMultiplicacao, linhas1, colunas2);

    // Transpor a primeira matriz
    int **transpostaMatriz1 = transporMatriz(matriz1, linhas1, colunas1);

    printf("\nTransposta da primeira matriz:\n");
    imprimirMatriz(transpostaMatriz1, colunas1, linhas1);

    // Liberar memória alocada para as matrizes
    liberarMemoria(matriz1, linhas1);
    liberarMemoria(matriz2, linhas2);
    liberarMemoria(resultadoMultiplicacao, linhas1);
    liberarMemoria(transpostaMatriz1, colunas1);

    return 0;
}
