#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int heapifica(int vec[], int tam, int i) {
    int e, d, maior, qtd;
    qtd = 1;
    e = 2 * i + 1;
    d = 2 * i + 2;
    if (e < tam && vec[e] > vec[i]) {
        maior = e;
    }
    else {
        maior = i;
    }
    if (d < tam && vec[d] > vec[maior]) {
        maior = d;
    }
    if (maior != i) {
        troca(&vec[i], &vec[maior]);
        qtd += heapifica(vec, tam, maior);
    }
    return qtd;
}

int constroiHeap(int vec[], int tam) {
    int i, qtd;
    qtd = 0;
    for (i = tam / 2; i >= 0; i--) {
        qtd += heapifica(vec, tam, i);
    }
    return qtd;
}

int heapSort(int vec[], int tam) {
    int n, i, qtd;
    qtd = 0;
    qtd += constroiHeap(vec, tam);
    n = tam;
    for (i = tam - 1; i > 0; i--) {
        troca(&vec[0], &vec[i]);
        n--;
        qtd += heapifica(vec, n, 0);
    }
    return qtd;
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

    heapSort(arr, arr_size);

    printf("Vetor ordenado:\n");
    for (i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
