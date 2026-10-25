#include <stdio.h>
#define MAX 20
int main() {
    int pages[MAX], frames[MAX], time[MAX];
    int n, f, i, j, faults = 0, counter = 0, pos, min;
    printf("===== LRU PAGE REPLACEMENT =====\n");
    printf("Enter number of frames: ");
    scanf("%d", &f);
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference string:\n");
    for(i = 0; i < n; i++) scanf("%d", &pages[i]);
    for(i = 0; i < f; i++) frames[i] = -1;
    printf("\nPage\tFrames\t\tStatus\n");
    printf("-----------------------------\n");
    for(i = 0; i < n; i++) {
        int found = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }}
        if(!found) {
          min = 0;
            for(j = 1; j < f; j++)
                if(time[j] < time[min]) min = j;

            frames[min] = pages[i];
            counter++;
            time[min] = counter;
            faults++;
        }
        printf("%d\t", pages[i]);
        for(j = 0; j < f; j++)
            printf("%d ", frames[j] == -1 ? 0 : frames[j]);
        printf("\t%s\n", found ? "Hit" : "Fault");
    }
    printf("-----------------------------\n");
    printf("Total Page Faults = %d\n", faults);
    return 0;
}
