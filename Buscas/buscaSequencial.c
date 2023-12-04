#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Função de Busca Sequencial
int buscaSequencial(int vec[], int arg, int tam) {
    int i = 0, achou = -1;
    while ((i < tam) && (achou == -1)) {
        if (vec[i] == arg) {
            achou = i;
        }
        i++;
    }
    return achou;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    int vetor[] = {4, 7, 2, 9, 5};
    int tamanho = sizeof(vetor)/ sizeof(vetor[0]);
    int valorProcurado;
    printf(" Qual valor você deseja encontrar?: ");
    scanf("%d", &valorProcurado);
    
    int resultado = buscaSequencial(vetor, valorProcurado, tamanho);
    
    if (resultado != -1) {
        printf("O valor %d foi encontrado no índice %d\n", valorProcurado, resultado+1);
    } else {
        printf("O valor %d não foi encontrado no vetor\n", valorProcurado);
    }
    
    return 0;
}
