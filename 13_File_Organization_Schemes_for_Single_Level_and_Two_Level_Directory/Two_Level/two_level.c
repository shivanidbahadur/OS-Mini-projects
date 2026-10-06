#include <stdio.h>
#include <string.h>

int main() {
    int n, i;
    char user[20][20], file[20][20], u[20], f[20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%s %s", user[i], file[i]);

    printf("Enter student and file: ");
    scanf("%s %s", u, f);

    for (i = 0; i < n; i++)
        if (strcmp(user[i], u) == 0 && strcmp(file[i], f) == 0) {
            printf("File already exists\n");
            return 0;
        }

    printf("File created successfully\n");

    return 0;
}
