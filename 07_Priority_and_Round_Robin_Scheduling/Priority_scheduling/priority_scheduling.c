#include <stdio.h>
int main() {
    char *inst[] = {"GPS", "HeartRate", "Oxygen", "ECG"};
    int burst[] = {5, 3, 4, 6}, pri[] = {3, 1, 2, 1};
    int order[] = {0,1,2,3}, time = 0;
    for(int i=0; i<3; i++)
        for(int j=0; j<3-i; j++)
            if(pri[order[j]] > pri[order[j+1]]) {
                int t = order[j]; order[j] = order[j+1]; order[j+1] = t;
            }
    printf("Instrument | Priority | Start | Finish\n");
    for(int i=0; i<4; i++) {
        int idx = order[i];
        printf("%-10s | %8d | %5d | %6d\n", inst[idx], pri[idx], time, time+burst[idx]);
        time += burst[idx];
    }
    printf("\nAll instruments monitored successfully.\n");
    return 0;
}
