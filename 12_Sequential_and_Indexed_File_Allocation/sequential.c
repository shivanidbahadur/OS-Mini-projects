#include <stdio.h>
int main() {
    int n, f, i, j, k, size, start, disk[50] = {0};
    printf("Enter total disk blocks: "); scanf("%d", &n);
    printf("Enter number of files: "); scanf("%d", &f);
    for(i = 0; i < f; i++) {
        printf("Enter size of File %d: ", i+1);
        scanf("%d", &size);
        for(j = 0; j <= n-size; j++) {
            for(k = j; k < j+size; k++)
                if(disk[k]) break;
            if(k == j+size) { start = j; break; }
        }
        if(k == j+size) {
            for(k = start; k < start+size; k++) disk[k] = i+1;
            printf("File %d allocated: Blocks %d to %d\n", i+1, start, start+size-1);
        } else
            printf("File %d: Not enough contiguous space\n", i+1);
    }
}
