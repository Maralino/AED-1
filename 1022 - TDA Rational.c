#include <stdio.h>

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplificar(int *num, int *den) {
    int divisor = mdc(*num, *den);
    *num /= divisor;
    *den /= divisor;
    if (*den < 0) {
        *num = -*num;
        *den = -*den;
    }
}

int main() {
    int N, n1, d1, n2, d2, num, den;
    char operador;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d / %d %c %d / %d", &n1, &d1, &operador, &n2, &d2);

        switch (operador) {
            case '+':
                num = n1 * d2 + n2 * d1;
                den = d1 * d2;
                break;
            case '-':
                num = n1 * d2 - n2 * d1;
                den = d1 * d2;
                break;
            case '*':
                num = n1 * n2;
                den = d1 * d2;
                break;
            case '/':
                num = n1 * d2;
                den = n2 * d1;
                break;
        }

        printf("%d/%d = ", num, den);
        simplificar(&num, &den);
        if (num < 0) {
            printf("-%d/%d\n", -num, den);
        } else {
            printf("%d/%d\n", num, den);
        }
    }

    return 0;
}
