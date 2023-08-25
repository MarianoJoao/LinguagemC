#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* criarNo(int data) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->data = data;
    novoNo->next = NULL;
    return novoNo;
}

// Função para adicionar um nó ao final da lista
void adicionarElemento(struct Node** head, int data) {
    struct Node* novoNo = criarNo(data);

    if (*head == NULL) {
        *head = novoNo;
        return;
    }

    struct Node* atual = *head;
    while (atual->next != NULL) {
        atual = atual->next;
    }
    
    atual->next = novoNo;
}

// Função para remover um nó da lista
void removerElemento(struct Node** head, int data) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->data == data) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node* atual = *head;
    while (atual->next != NULL && atual->next->data != data) {
        atual = atual->next;
    }

    if (atual->next == NULL) {
        return;
    }

    struct Node* temp = atual->next;
    atual->next = atual->next->next;
    free(temp);
}

// Função para imprimir os elementos da lista
void imprimirLista(struct Node* head) {
    struct Node* atual = head;
    while (atual != NULL) {
        printf("%d -> ", atual->data);
        atual = atual->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* lista = NULL;

    adicionarElemento(&lista, 1);
    adicionarElemento(&lista, 2);
    adicionarElemento(&lista, 3);

    printf("Lista original:\n");
    imprimirLista(lista);

    removerElemento(&lista, 2);

    printf("Lista após remover o elemento 2:\n");
    imprimirLista(lista);

    return 0;
}
