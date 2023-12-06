#include <stdio.h>
#include <stdlib.h>

// Função de busca por interpolação
int buscaInterpol(int vec[], int arg, int tam) {
    int menor, maior, meio, achou;
    menor = 0;
    maior = tam - 1;
    achou = -1;
    
    while ((menor <= maior) && (achou == -1)) {
        meio = menor + (maior - menor) * ((arg - vec[menor]) / (vec[maior] - vec[menor]));
        
        if (arg == vec[meio]) {
            achou = meio;
        }
        
        if (arg < vec[meio]) {
            maior = meio - 1;
        } else {
            menor = meio + 1;
        }
    }
    
    return achou;
}

int main() {
    int vetor[] = {10, 20, 30, 40, 50}; // Exemplo de vetor ordenado
    int tamanho = 5; // Tamanho do vetor
    int valorProcurado = 35; // Valor a ser procurado

    int resultado = buscaInterpol(vetor, valorProcurado, tamanho);

    if (resultado == -1) {
        printf("Valor nao encontrado\n");
    } else {
        printf("Valor encontrado na posicao: %d\n", resultado);
    }

    return 0;
}
