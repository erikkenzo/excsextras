#include <stdio.h>
#include <string.h>

int contar_vogais(char *string) {
    int contador = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        // Converte para minúscula para simplificar a verificação
        char caractere = tolower(string[i]);
        if (caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u') {
            contador++;
        }
    }
    return contador;
}

int main() {
    char entrada[100];
    printf("Digite uma frase ou palavra: ");
    fgets(entrada, 100, stdin);

    // Remove o caractere de nova linha (\n) do final da string
    entrada[strcspn(entrada, "\n")] = '\0';

    int numero_de_vogais = contar_vogais(entrada);

    printf("Número de vogais na string inserida: %d\n", numero_de_vogais);

    return 0;
}
