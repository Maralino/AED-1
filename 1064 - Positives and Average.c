#include <stdio.h>

int main() {
    float valor, soma = 0.0;
    int positivos = 0;

    for (int i = 0; i < 6; i++) {
        scanf("%f", &valor);
        if (valor > 0) {
            positivos++;
            soma += valor;
        }
    }

    printf("%d valores positivos\n", positivos);
    printf("%.1f\n", soma / positivos);

    return 0;
}
