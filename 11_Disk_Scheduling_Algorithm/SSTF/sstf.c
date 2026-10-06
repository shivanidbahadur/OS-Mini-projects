#include <stdio.h>
#include <stdlib.h>

#define N 8

int main() {
    int req[N], n, head, i, j, pos, min, diff, total = 0, temp;

    printf("Enter no. of CCTV requests: ");
    scanf("%d", &n);

    printf("Enter disk tracks: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter current head: ");
    scanf("%d", &head);

    for (i = 0; i < n; i++) {
        min = 9999;
        pos = i;

        for (j = i; j < n; j++) {
            diff = abs(head - req[j]);

            if (diff < min) {
                min = diff;
                pos = j;
            }
        }

        temp = req[i];
        req[i] = req[pos];
        req[pos] = temp;

        total += abs(head - req[i]);
        head = req[i];
    }

    printf("Seek Sequence: ");

    for (i = 0; i < n; i++)
        printf("%d ", req[i]);

    printf("\nTotal Seek Time: %d\n", total);

    return 0;
}
