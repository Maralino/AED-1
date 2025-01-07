#include <stdio.h>
#include <stdlib.h>

int cmp_even(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int cmp_odd(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n;
    scanf("%d", &n);

    int *even = malloc(n * sizeof(int));
    int *odd = malloc(n * sizeof(int));
    int even_count = 0, odd_count = 0;

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (num % 2 == 0)
            even[even_count++] = num;
        else
            odd[odd_count++] = num;
    }

    qsort(even, even_count, sizeof(int), cmp_even);
    qsort(odd, odd_count, sizeof(int), cmp_odd);

    for (int i = 0; i < even_count; i++)
        printf("%d\n", even[i]);
    for (int i = 0; i < odd_count; i++)
        printf("%d\n", odd[i]);

    free(even);
    free(odd);

    return 0;
}
