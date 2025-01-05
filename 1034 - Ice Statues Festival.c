#include <stdio.h>
#include <limits.h>

#define MAX_BLOCKS 25

int minBlocks(int types[], int n, int length) {
    int dp[length + 1];
    dp[0] = 0;

    for (int i = 1; i <= length; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i >= types[j] && dp[i - types[j]] != INT_MAX) {
                dp[i] = dp[i] < dp[i - types[j]] + 1 ? dp[i] : dp[i - types[j]] + 1;
            }
        }
    }

    return dp[length] == INT_MAX ? -1 : dp[length];
}

int main() {
    int t, n, m, blocks[MAX_BLOCKS];
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &blocks[i]);
        }
        printf("%d\n", minBlocks(blocks, n, m));
    }

    return 0;
}
