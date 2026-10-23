#include <stdio.h>
int main() {
    int pages[]={7,0,1,2,0,3,0,4,2,3,0,3,2}, n=13, f=3;
    int frame[3]={-1,-1,-1}, front=0, faults=0, i,j,hit;
    printf("Map Tile Requests → Frames (FIFO Cache)\n");
    for(i=0;i<n;i++){
        hit=0;
        for(j=0;j<f;j++) if(frame[j]==pages[i]){hit=1;break;}
        if(!hit){frame[front]=pages[i]; front=(front+1)%f; faults++;}
        printf("Tile %d → ",pages[i]);
        for(j=0;j<f;j++) printf("%2d ",frame[j]);
        printf("\n");
    }
    printf("Total Cache Misses (Page Faults) = %d\n",faults);
}
