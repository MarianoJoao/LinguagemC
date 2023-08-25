#include <stdio.h>

// Função para remover elementos duplicados de um array
int removeDuplicatas(int arr[], int tamanho) {
    if (tamanho <= 1)
        return tamanho;

    int *ptrAtual, *ptrComparacao, *ultimo;
    int novoTamanho = tamanho;

    for (ptrAtual = arr; ptrAtual < arr + tamanho - 1; ++ptrAtual) {
        for (ptrComparacao = ptrAtual + 1; ptrComparacao < arr + tamanho; ) {
            if (*ptrComparacao == *ptrAtual) {
                for (ultimo = ptrComparacao; ultimo < arr + tamanho - 1; ++ultimo)
                    *ultimo = *(ultimo + 1);

                --novoTamanho;
            } else {
                ++ptrComparacao;
            }
        }
    }

    return novoTamanho;
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5, 5, 6};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (int i = 0; i < tamanho; ++i) {
        printf("%d ", arr[i]);
    }

    tamanho = removeDuplicatas(arr, tamanho);

    printf("\nArray sem elementos duplicados:\n");
    for (int i = 0; i < tamanho; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}
