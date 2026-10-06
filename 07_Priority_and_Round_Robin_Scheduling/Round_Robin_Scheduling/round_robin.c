#include <stdio.h>
int main() {
    char *inst[] = {"GPS", "HeartRate", "Oxygen", "ECG"};
    int burst[] = {5, 3, 4, 6}, rem[4], tq = 2, time = 0, done = 0;
    for(int i = 0; i < 4; i++) rem[i] = burst[i];
    printf("Time | Instrument | Remaining\n");
    while(done < 4) {
        for(int i = 0; i < 4; i++) {
            if(rem[i] > 0) {
                int run = (rem[i] > tq) ? tq : rem[i];
                time += run; rem[i] -= run;
                printf("%4d | %-10s | %d\n", time, inst[i], rem[i]);
                if(rem[i] == 0) done++;
 }}}
    printf("\nAll instruments monitored successfully.\n");
    return 0;
}
