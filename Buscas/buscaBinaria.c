#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int vec[], int arg, int tam) {
    int menor, maior, meio;
    menor = 0;
    maior = tam - 1;
    while (menor <= maior) {
        meio = (menor + maior) / 2;
        if (arg == vec[meio]) {
            return meio;
        }
        if (arg < vec[meio]) {
            maior = meio - 1;
        } else {
            menor = meio + 1;
        }
    }
    return -1;
}

int main() {
    int vetor[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valorProcurado = 16;
    int resultado = buscaBinaria(vetor, valorProcurado, tamanho);
    if (resultado != -1) {
        printf("Elemento encontrado na posição: %d\n", resultado);
    } else {
        printf("Elemento não encontrado\n");
    }
    return 0;
}

