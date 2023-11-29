#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar os valores de duas variáveis
void troca(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Aplica o algoritmo Selection Sort para ordenar o vetor
void selectionSort(int array[], int size) {
    int i, j, min_idx;

    // Percorre o vetor
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        // Encontra o índice do menor elemento restante
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        // Troca o elemento atual com o menor elemento encontrado
        troca(&array[min_idx], &array[i]);
    }
}

int main(void) {
    time_t t;
    time(&t);
    srand((unsigned int)t);

    printf("Quantos elementos você deseja que seu vetor tenha?: ");
    int elementos;
    scanf("%d", &elementos);
    int vetor[elementos];
    int i;

    printf("Vetor gerado: ");
    for (i = 0; i < elementos; i++) {
        vetor[i] = rand() % 100; // Preenche o vetor com números aleatórios
        printf("%d ", vetor[i]);
    }

    selectionSort(vetor, elementos); // Chama a função para ordenar o vetor

    printf("\nVetor ordenado: ");
    for (i = 0; i < elementos; i++) {
        printf("%d ", vetor[i]); // Imprime o vetor ordenado
    }

    return 0;
}
