#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, total = 0, temp, dir, disk_size = 200;

    printf("Enter no. of CCTV requests: ");
    scanf("%d", &n);

    int req[n + 1];

    printf("Enter disk tracks: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter current head: ");
    scanf("%d", &head);

    printf("Enter direction (1=right,0=left): ");
    scanf("%d", &dir);

    req[n] = head;
    n++;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    printf("Seek Sequence: ");

    if (dir == 1) {
        for (i = 0; i < n; i++) {
            if (req[i] >= head) {
                printf("%d ", req[i]);
                total += abs(head - req[i]);
                head = req[i];
            }
        }

        total += abs(head - (disk_size - 1));
        head = disk_size - 1;
        printf("%d ", head);

        for (i = n - 1; i >= 0; i--) {
            if (req[i] < head) {
                printf("%d ", req[i]);
                total += abs(head - req[i]);
                head = req[i];
            }
        }
    } else {
        for (i = n - 1; i >= 0; i--) {
            if (req[i] <= head) {
                printf("%d ", req[i]);
                total += abs(head - req[i]);
                head = req[i];
            }
        }

        total += abs(head - 0);
        head = 0;
        printf("%d ", head);

        for (i = 0; i < n; i++) {
            if (req[i] > head) {
                printf("%d ", req[i]);
                total += abs(head - req[i]);
                head = req[i];
            }
        }
    }

    printf("\nTotal Seek Time: %d\n", total);

    return 0;
}

