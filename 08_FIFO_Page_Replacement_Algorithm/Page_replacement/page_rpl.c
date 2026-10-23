#include <stdio.h>
int main() {
    int pages[]={7,0,1,2,0,3,0,4,2,3,0,3,2}, n=13, f=3;
    int frame[3]={-1,-1,-1}, faults=0, i, j, k, pos, farthest;
    for(i=0; i<n; i++) {
        int found=0;
        for(j=0; j<f; j++) if(frame[j]==pages[i]) {found=1; break;}
        if(!found) {
            int empty=-1;
            for(j=0; j<f; j++) if(frame[j]==-1) {empty=j; break;}
            if(empty!=-1) frame[empty]=pages[i];
            else {
                farthest=-1; pos=0;
                for(j=0; j<f; j++) {
                    int next=n;
                    for(k=i+1; k<n; k++) if(frame[j]==pages[k]) {next=k; break;}
                    if(next>farthest) {farthest=next; pos=j;}
                }
                frame[pos]=pages[i];
            }
            faults++;
        }
        printf("%d → ", pages[i]);
        for(j=0; j<f; j++) printf("%2d ", frame[j]);
        printf("\n");
    }
    printf("Total Page Faults = %d\n", faults);
}
