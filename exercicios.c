#include <stdio.h>

int main() {
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int somaDiagonalPrincipal = 0;
    for (int i = 0; i < 3; i++) {
        somaDiagonalPrincipal += matriz[i][i];
    }

    printf("Soma dos elementos da diagonal principal: %f\n", somaDiagonalPrincipal);

    return 0;
}
