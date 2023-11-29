#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar os valores de duas variáveis
void troca(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Aplica o algoritmo Shell Sort para ordenar o vetor
void shellSort(int array[], int size) {
    int i, j, valor, qtd = 0;
    int gap = 1;

    // Calcula o valor inicial do gap
    do {
        gap = 3 * gap + 1;
    } while (gap < size);

    // Loop principal do algoritmo Shell Sort
    do {
        gap /= 3;
        for (i = gap; i < size; i++) {
            valor = array[i];
            j = i - gap;

            // Realiza a inserção nos subgrupos
            while (j >= 0 && valor < array[j]) {
                array[j + gap] = array[j];
                j -= gap;
                qtd++; // Conta o número de trocas
            }
            array[j + gap] = valor;
        }
    } while (gap > 1);

    printf("\n\n\n Realizou %d trocas\n\n\n", qtd); // Imprime o número de trocas realizadas
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

    shellSort(vetor, elementos); // Chama a função para ordenar o vetor

    printf("\nVetor ordenado: ");
    for (i = 0; i < elementos; i++) {
        printf("%d ", vetor[i]); // Imprime o vetor ordenado
    }

    return 0;
}
