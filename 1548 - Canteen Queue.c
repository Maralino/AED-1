#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n, m;
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &m);
        int grades[m], sorted_grades[m];
        
        for (int i = 0; i < m; i++) {
            scanf("%d", &grades[i]);
            sorted_grades[i] = grades[i];
        }

        qsort(sorted_grades, m, sizeof(int), compare);

        int unchanged_count = 0;
        for (int i = 0; i < m; i++) {
            if (grades[i] == sorted_grades[i]) {
                unchanged_count++;
            }
        }

        printf("%d\n", unchanged_count);
    }

    return 0;
}
