#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int count_diamonds(const char *str) {
    int diamonds = 0, open_brackets = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '<') {
            open_brackets++;
        } else if (str[i] == '>' && open_brackets > 0) {
            diamonds++;
            open_brackets--;
        }
    }

    return diamonds;
}

int main() {
    int n;
    char line[MAX_LENGTH + 1];

    scanf("%d", &n);
    while (n--) {
        scanf("%s", line);
        printf("%d\n", count_diamonds(line));
    }

    return 0;
}
