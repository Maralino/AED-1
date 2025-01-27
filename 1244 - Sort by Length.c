#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 50
#define MAX_LENGTH 50

typedef struct {
    char word[MAX_LENGTH + 1];
    int length;
    int order;
} Word;

int compare(const void *a, const void *b) {
    Word *word1 = (Word *)a;
    Word *word2 = (Word *)b;

    if (word1->length != word2->length) {
        return word2->length - word1->length;
    }
    return word1->order - word2->order;
}

void process_line(char *line) {
    Word words[MAX_WORDS];
    int count = 0, order = 0;
    char *token = strtok(line, " ");

    while (token) {
        strcpy(words[count].word, token);
        words[count].length = strlen(token);
        words[count].order = order++;
        count++;
        token = strtok(NULL, " ");
    }

    qsort(words, count, sizeof(Word), compare);

    for (int i = 0; i < count; i++) {
        if (i > 0) printf(" ");
        printf("%s", words[i].word);
    }
    printf("\n");
}

int main() {
    int n;
    char line[MAX_WORDS * (MAX_LENGTH + 1)];

    scanf("%d", &n);
    getchar();

    while (n--) {
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';
        process_line(line);
    }

    return 0;
}
