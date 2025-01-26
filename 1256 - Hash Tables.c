#include <stdio.h>

void printHashTable(int m, int table[m][100], int counts[m]) {
    for (int i = 0; i < m; i++) {
        printf("%d ->", i);
        for (int j = 0; j < counts[i]; j++) {
            printf(" %d ->", table[i][j]);
        }
        printf(" \\\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int t = 0; t < n; t++) {
        int m, c;
        scanf("%d %d", &m, &c);

        int table[m][100];
        int counts[m];

        for (int i = 0; i < m; i++) {
            counts[i] = 0;
        }

        for (int i = 0; i < c; i++) {
            int key;
            scanf("%d", &key);
            int index = key % m;
            table[index][counts[index]++] = key;
        }

        printHashTable(m, table, counts);

        if (t < n - 1) {
            printf("\n");
        }
    }

    return 0;
}
