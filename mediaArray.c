#include <stdio.h>

// Função para calcular a média de um array de números
double calcularMedia(const double *arr, int tamanho) {
    if (tamanho == 0)
        return 0.0; // Retorna 0 se o array estiver vazio

    const double *ptr = arr; // Inicializa um ponteiro para percorrer o array
    double soma = 0.0;

    // Percorre o array e calcula a soma dos elementos
    while (ptr < arr + tamanho) {
        soma += *ptr;
        ptr++;
    }

    // Calcula a média
    return soma / tamanho;
}

int main() {
    double numeros[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    double media = calcularMedia(numeros, tamanho);

    printf("Array de números:\n");
    for (int i = 0; i < tamanho; ++i) {
        printf("%.2lf ", numeros[i]);
    }

    printf("\nMédia: %.2lf\n", media);

    return 0;
}
