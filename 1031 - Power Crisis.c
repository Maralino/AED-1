#include <stdio.h>

int solve(int n) {
    int m = 1;
    while (1) {
        int current = 0;
        for (int i = 1; i < n; ++i)
            current = (current + m) % i;
        if (current == 11) // Região 13 no índice zero-based
            return m;
        ++m;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) && n != 0)
        printf("%d\n", solve(n));
    return 0;
}
