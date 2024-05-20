#include <stdio.h>
#include <time.h>

int main() {
    // Variáveis para armazenar o tempo inicial e final
    clock_t start, end;
    double cpu_time_used;

    // Obter o tempo inicial
    start = clock();

    // Trecho de código cujo tempo de execução será medido
    for (long i = 0; i < 1000000000; i++) {
        // Operação de exemplo: incremento de uma variável
    }

    // Obter o tempo final
    end = clock();

    // Calcular o tempo usado em segundos
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Exibir o tempo usado
    printf("Tempo de execução: %f segundos\n", cpu_time_used);

    return 0;
}
