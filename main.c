#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do funcionário
struct Funcionario {
    char nome[50];
    int idade;
    float salario;
};

// Função de comparação para qsort, para ordenar por idade
int compararIdade(const void *a, const void *b) {
    const struct Funcionario *funcionarioA = (const struct Funcionario *)a;
    const struct Funcionario *funcionarioB = (const struct Funcionario *)b;
    return funcionarioA->idade - funcionarioB->idade;
}

// Função de comparação para qsort, para ordenar por salário
int compararSalario(const void *a, const void *b) {
    const struct Funcionario *funcionarioA = (const struct Funcionario *)a;
    const struct Funcionario *funcionarioB = (const struct Funcionario *)b;
    if (funcionarioA->salario < funcionarioB->salario) return -1;
    if (funcionarioA->salario > funcionarioB->salario) return 1;
    return 0;
}

int main() {
    int numFuncionarios;

    // Pedir ao usuário o número de funcionários
    printf("Digite o numero de funcionarios: ");
    scanf("%d", &numFuncionarios);

    // Alocar memória para o array de funcionários
    struct Funcionario *funcionarios = malloc(numFuncionarios * sizeof(struct Funcionario));
    if (funcionarios == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Pedir ao usuário os dados de cada funcionário
    for (int i = 0; i < numFuncionarios; i++) {
        printf("\nFuncionario %d:\n", i+1);
        printf("Nome: ");
        scanf("%s", funcionarios[i].nome);
        printf("Idade: ");
        scanf("%d", &funcionarios[i].idade);
        printf("Salario: ");
        scanf("%f", &funcionarios[i].salario);
    }

    // Pedir ao usuário o critério de ordenação
    int opcao;
    printf("\nEscolha o criterio de ordenacao:\n");
    printf("1. Ordenar por idade\n");
    printf("2. Ordenar por salario\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    // Ordenar o array de funcionários de acordo com a escolha do usuário
    switch (opcao) {
        case 1:
            qsort(funcionarios, numFuncionarios, sizeof(struct Funcionario), compararIdade);
            break;
        case 2:
            qsort(funcionarios, numFuncionarios, sizeof(struct Funcionario), compararSalario);
            break;
        default:
            printf("Opcao invalida.\n");
            free(funcionarios);
            return 1;
    }

    // Imprimir o array ordenado
    printf("\nFuncionarios ordenados:\n");
    for (int i = 0; i < numFuncionarios; i++) {
        printf("Nome: %s, Idade: %d, Salario: %.2f\n", funcionarios[i].nome, funcionarios[i].idade, funcionarios[i].salario);
    }

    // Liberar memória alocada para o array de funcionários
    free(funcionarios);

    return 0;
}
