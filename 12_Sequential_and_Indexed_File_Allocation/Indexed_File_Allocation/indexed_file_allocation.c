#include <stdio.h>
int main() {
    int n, f, i, j, size, index, disk[50] = {0};
    printf("Enter total disk blocks: "); scanf("%d", &n);
    printf("Enter number of files: "); scanf("%d", &f);
    for(i = 0; i < f; i++) {
        printf("Enter size of File %d: ", i+1);
        scanf("%d", &size);
        printf("Enter index block for File %d: ", i+1);
        scanf("%d", &index);
        if(index >= n || disk[index] != 0) {
            printf("File %d: Invalid or occupied index block\n", i+1);
            continue;
        }
        disk[index] = i+1;
        printf("File %d allocated\n", i+1);
        printf("Index Block: %d\n", index);
        printf("Data Blocks: ");
        for(j = 0; j < size; j++)
            printf("%d ", (index + j + 1) % n);  // simple sequential data blocks
        printf("\n");
    }
}
