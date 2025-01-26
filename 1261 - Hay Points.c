#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LEN 16
#define MAX_DESC_LEN 1000

typedef struct {
    char word[MAX_WORD_LEN + 1];
    int value;
} DictionaryEntry;

int findValue(DictionaryEntry *dictionary, int m, char *word) {
    for (int i = 0; i < m; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return dictionary[i].value;
        }
    }
    return 0;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    DictionaryEntry dictionary[m];

    for (int i = 0; i < m; i++) {
        scanf("%s %d", dictionary[i].word, &dictionary[i].value);
    }

    for (int i = 0; i < n; i++) {
        char description[MAX_DESC_LEN];
        int total = 0;

        while (1) {
            fgets(description, MAX_DESC_LEN, stdin);
            if (description[0] == '.') break;

            char *word = strtok(description, " \n");
            while (word != NULL) {
                total += findValue(dictionary, m, word);
                word = strtok(NULL, " \n");
            }
        }

        printf("%d\n", total);
    }

    return 0;
}
