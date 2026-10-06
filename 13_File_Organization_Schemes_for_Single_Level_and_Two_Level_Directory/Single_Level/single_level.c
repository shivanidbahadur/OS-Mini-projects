#include <stdio.h>
#include <string.h>

int main() {
    int n, i;
    char files[20][20], name[20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%s", files[i]);

    printf("Enter new file name: ");
    scanf("%s", name);

    for (i = 0; i < n; i++)
        if (strcmp(files[i], name) == 0) {
            printf("File already exists\n");
            return 0;
        }

    strcpy(files[n], name);

    printf("File created successfully\n");

    return 0;
}

