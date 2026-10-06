#include <stdio.h>
int main() {
    int n, m, i, j, worst;
    printf("Enter number of memory blocks: ");
    scanf("%d", &n);
    int block[n];
    printf("Enter sizes of %d blocks:\n", n);
    for(i=0; i<n; i++) scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &m);
    int process[m], alloc[m];
    printf("Enter sizes of %d processes:\n", m);
    for(i=0; i<m; i++) scanf("%d", &process[i]);
    for(i=0; i<m; i++) {
        worst = -1;
        for(j=0; j<n; j++)
            if(block[j] >= process[i] && (worst==-1 || block[j] > block[worst]))
                worst = j;
        if(worst != -1) {
            alloc[i] = worst;
            block[worst] -= process[i];
        } else
            alloc[i] = -1;
    }
    printf("\nProcess\tSize\tBlock\n");
    for(i=0; i<m; i++)
        printf("%d\t%d\t%d\n", i+1, process[i], alloc[i]!=-1 ? alloc[i]+1 : -1);
    return 0;
}
