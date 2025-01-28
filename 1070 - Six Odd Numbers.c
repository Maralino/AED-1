#include <stdio.h>

int main() {
    int x, contador = 0;

    scanf("%d", &x);

    while (contador < 6) {
        if (x % 2 != 0) {
            printf("%d\n", x);
            contador++;
        }
        x++;
    }

    return 0;
}
