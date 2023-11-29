#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaração antecipada das funções
int particiona(int vec[], int left, int right);
int quickSort(int vec[], int left, int right);

// Aplica o modo do quickSort
int quickSort(int vec[], int left, int right) {
    if (right > left) {
        int r = particiona(vec, left, right);
        quickSort(vec, left, r - 1);
        quickSort(vec, r + 1, right);
    }
    return 0; // Não é necessário contar as comparações/movimentações aqui
}

// Divide o vetor em pedaços menores
int particiona(int vec[], int left, int right) {
    int i, j;
    i = left;
    for (j = left + 1; j <= right; ++j) {
        if (vec[j] < vec[left]) {
            ++i;
            // Troca os elementos do vetor
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
        }
    }
    // Troca os elementos do vetor
    int temp = vec[left];
    vec[left] = vec[i];
    vec[i] = temp;
    return i;
}

int main() {
    int i;
    time_t t;
    time(&t);
    srand((unsigned int)t);

    printf("Quantos elementos você deseja que seu vetor tenha?: ");
    int elementos;
    scanf("%d", &elementos);

    int arr[elementos];
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (i = 0; i < arr_size; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, arr_size - 1);

    printf("Array ordenado:\n");
    for (i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
