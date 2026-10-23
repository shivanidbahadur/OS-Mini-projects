#include <stdio.h>
#include <string.h>
int main() {
    int n, i; char user[20][20], file[20][20], u[20], f[20];
    printf("Enter number of files (max 19): "); scanf("%d", &n);
    printf("Enter %d pairs (student file): ", n);
    for (i = 0; i < n; i++) scanf("%s %s", user[i], file[i]);
    printf("Enter student and file: "); scanf("%s %s", u, f);
    printf("\n%-4s %-10s %-10s\n", "No.", "Student", "File");
    for (i = 0; i < n; i++) printf("%-4d %-10s %-10s\n", i + 1, user[i], file[i]);
    for (i = 0; i < n; i++) if (!strcmp(user[i], u) && !strcmp(file[i], f)) {
        printf("\nError: '%s' already has '%s' (entry %d)\n", u, f, i + 1); return 0; }
    strcpy(user[n], u); strcpy(file[n++], f); printf("\nFile '%s' created for '%s'\n", f, u);
printf("Total files now: %d\n", n); return 0; }

