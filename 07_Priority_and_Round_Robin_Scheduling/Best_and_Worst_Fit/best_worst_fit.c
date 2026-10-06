#include <stdio.h>

int main() {
    int n, m, i, j;
    int block[20], temp[20], process[20];
    int best[20], worst[20];

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block sizes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &block[i]);
        temp[i] = block[i];
    }

    printf("Enter number of processes: ");
    scanf("%d", &m);

    printf("Enter process sizes: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &process[i]);
    }

    for (i = 0; i < m; i++) {
        int b = -1, w = -1;

        for (j = 0; j < n; j++) {
            if (block[j] >= process[i] &&
                (b == -1 || block[j] < block[b])) {
                b = j;
            }

            if (temp[j] >= process[i] &&
                (w == -1 || temp[j] > temp[w])) {
                w = j;
            }
        }

        if (b != -1) {
            best[i] = b;
            block[b] -= process[i];
        } else {
            best[i] = -1;
        }

        if (w != -1) {
            worst[i] = w;
            temp[w] -= process[i];
        } else {
            worst[i] = -1;
        }
    }

    printf("\nBest Fit:\n");
    for (i = 0; i < m; i++) {
        printf("P%d -> %d\n", i + 1,
               best[i] != -1 ? best[i] + 1 : -1);
    }

    printf("\nWorst Fit:\n");
    for (i = 0; i < m; i++) {
        printf("P%d -> %d\n", i + 1,
               worst[i] != -1 ? worst[i] + 1 : -1);
    }

    return 0;
}
