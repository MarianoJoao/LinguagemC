#include <stdio.h>
#include <string.h>

// Função para inverter uma string usando ponteiros
void inverterString(char *str) {
    int tamanho = strlen(str);
    char *inicio = str;
    char *fim = str + tamanho - 1;

    while (inicio < fim) {
        // Troque os caracteres apontados por inicio e fim
        char temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        // Avance o ponteiro inicio e retroceda o ponteiro fim
        inicio++;
        fim--;
    }
}

int main() {
    char minhaString[] = "Hello, World!";
    
    printf("String original: %s\n", minhaString);
    inverterString(minhaString);
    printf("String invertida: %s\n", minhaString);
    
    return 0;
}
