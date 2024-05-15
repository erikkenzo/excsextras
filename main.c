#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do registro
struct Funcionario {
    char nome[50];
    int idade;
    float salario;
};

// Função para adicionar um novo registro ao arquivo
void adicionarRegistro(FILE *arquivo) {
    struct Funcionario novoFuncionario;

    printf("Digite o nome do funcionario: ");
    scanf("%s", novoFuncionario.nome);
    printf("Digite a idade do funcionario: ");
    scanf("%d", &novoFuncionario.idade);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &novoFuncionario.salario);

    // Escrever o registro no arquivo
    fwrite(&novoFuncionario, sizeof(struct Funcionario), 1, arquivo);
}

// Função para listar todos os registros do arquivo
void listarRegistros(FILE *arquivo) {
    struct Funcionario funcionario;

    rewind(arquivo); // Voltar para o início do arquivo

    printf("\nLista de Funcionarios:\n");
    while (fread(&funcionario, sizeof(struct Funcionario), 1, arquivo)) {
        printf("Nome: %s, Idade: %d, Salario: %.2f\n", funcionario.nome, funcionario.idade, funcionario.salario);
    }
}

// Função para buscar um registro pelo nome
void buscarPorNome(FILE *arquivo, char *nome) {
    struct Funcionario funcionario;
    int encontrado = 0;

    rewind(arquivo); // Voltar para o início do arquivo

    while (fread(&funcionario, sizeof(struct Funcionario), 1, arquivo)) {
        if (strcmp(funcionario.nome, nome) == 0) {
            printf("Funcionario encontrado:\n");
            printf("Nome: %s, Idade: %d, Salario: %.2f\n", funcionario.nome, funcionario.idade, funcionario.salario);
            encontrado = 1;
            break; // Encerrar a busca após encontrar o primeiro registro com o nome
        }
    }

    if (!encontrado) {
        printf("Funcionario com nome %s nao encontrado.\n", nome);
    }
}

int main() {
    FILE *arquivo;
    int opcao;
    char nomeBusca[50];

    // Abrir o arquivo para escrita binária (ou criar se não existir)
    arquivo = fopen("funcionarios.bin", "ab+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Menu de opções
    do {
        printf("\nMenu:\n");
        printf("1. Adicionar novo registro\n");
        printf("2. Listar todos os registros\n");
        printf("3. Buscar por nome\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarRegistro(arquivo);
                break;
            case 2:
                listarRegistros(arquivo);
                break;
            case 3:
                printf("Digite o nome a ser buscado: ");
                scanf("%s", nomeBusca);
                buscarPorNome(arquivo, nomeBusca);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    // Fechar o arquivo
    fclose(arquivo);

    return 0;
}
