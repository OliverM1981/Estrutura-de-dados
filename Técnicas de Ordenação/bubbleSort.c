#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar os valores de duas variáveis
void troca(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Aplica o algoritmo Bubble Sort para ordenar o vetor
void bubbleSort(int array[], int size) {
    int i, j;
    int trocou; // Variável para indicar se houve troca em uma iteração

    for (i = 0; i < size - 1; i++) {
        trocou = 0; // Inicializa como falso no início de cada iteração
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                troca(&array[j], &array[j + 1]); // Troca os elementos fora de ordem
                trocou = 1; // Indica que houve troca nesta iteração
            }
        }
        if (trocou == 0) {
            break; // Se não houve troca, o vetor já está ordenado
        }
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

    bubbleSort(vetor, elementos); // Chama a função para ordenar o vetor

    printf("\nVetor ordenado: ");
    for (i = 0; i < elementos; i++) {
        printf("%d ", vetor[i]); // Imprime o vetor ordenado
    }

    return 0;
}
