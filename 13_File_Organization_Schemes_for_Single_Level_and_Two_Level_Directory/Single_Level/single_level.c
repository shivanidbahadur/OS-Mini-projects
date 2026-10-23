#include <stdio.h>
#include <string.h>
int main() {
    int n, i; char files[20][20], name[20];
    printf("Enter number of files (max 19): "); scanf("%d", &n);
    printf("Enter %d file names: ", n);
    for (i = 0; i < n; i++) scanf("%s", files[i]);
    printf("Enter new file name: "); scanf("%s", name);
    printf("\nCurrent directory:\n");
    for (i = 0; i < n; i++) printf("  %d. %s\n", i + 1, files[i]);
    for (i = 0; i < n; i++) if (strcmp(files[i], name) == 0) {
        printf("\nError: '%s' already exists at position %d\n", name, i + 1); return 0; }
    strcpy(files[n++], name); printf("\nFile '%s' created successfully\n", name);
    printf("Updated directory (%d files):\n", n); for (i = 0; i < n; i++) printf("  %d. %s\n", i + 1, files[i]);
return 0; }
