#include <stdio.h>
#include <ctype.h>

void converteMaiusculas(char *str) {
    // Percorre a string até encontrar o caractere nulo
    while (*str != '\0') {
        // Converte o caractere para maiúscula, se for uma letra
        *str = toupper(*str);
        // Avança para o próximo caractere na string
        str++;
    }
}

int main() {
    char str[100];

    // Solicita ao usuário inserir uma string
    printf("Digite uma string: ");
    scanf("%s", str);

    // Converte todas as letras para maiúsculas
    converteMaiusculas(str);

    // Exibe a string convertida
    printf("String convertida: %s\n", str);

    return 0;
}
