#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar os valores de duas variáveis
void troca(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Aplica o algoritmo Insertion Sort para ordenar o vetor
void insertionSort(int array[], int size) {
    int i, j, chave;
    for (i = 1; i < size; i++) {
        chave = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = chave;
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

    insertionSort(vetor, elementos); // Chama a função para ordenar o vetor

    printf("\nVetor ordenado: ");
    for (i = 0; i < elementos; i++) {
        printf("%d ", vetor[i]); // Imprime o vetor ordenado
    }

    return 0;
}
