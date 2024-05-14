#include <stdio.h>

// Definindo a estrutura Produto
struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

// Função para calcular o valor total em estoque de um produto
float calcularValorTotal(struct Produto p) {
    return p.preco * p.quantidade;
}

int main() {
    // Definindo um array de Produtos para armazenar múltiplos produtos
    struct Produto produtos[50];
    int numProdutos = 0;
    char continuar;

    do {
        // Pedindo ao usuário para inserir os detalhes do produto
        printf("Digite o nome do produto: ");
        scanf("%s", produtos[numProdutos].nome);

        printf("Digite o preço do produto: ");
        scanf("%f", &produtos[numProdutos].preco);

        printf("Digite a quantidade em estoque: ");
        scanf("%d", &produtos[numProdutos].quantidade);

        numProdutos++; // Incrementando o contador de produtos

        // Perguntando se o usuário deseja continuar cadastrando produtos
        printf("Deseja cadastrar outro produto? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');

    // Exibindo os produtos cadastrados e o valor total em estoque
    printf("\nProdutos cadastrados:\n");
    printf("Nome\t\tPreço\t\tQuantidade\tValor Total\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("%s\t\t%.2f\t\t%d\t\t%.2f\n", produtos[i].nome, produtos[i].preco, produtos[i].quantidade, calcularValorTotal(produtos[i]));
    }

    return 0;
}
