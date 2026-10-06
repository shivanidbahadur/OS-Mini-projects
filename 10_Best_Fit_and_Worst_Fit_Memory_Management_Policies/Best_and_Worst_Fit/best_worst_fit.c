#include <stdio.h>
int main() {
    int n,m,i,j,b,w,blk[20],tmp[20],p[20],ba[20],wa[20];
    printf("Enter no. of blocks: "); scanf("%d",&n);
    printf("Enter block sizes: ");
    for(i=0;i<n;i++){scanf("%d",&blk[i]);tmp[i]=blk[i];}
    printf("Enter no. of processes: "); scanf("%d",&m);
    printf("Enter process sizes: ");
    for(i=0;i<m;i++)scanf("%d",&p[i]);
    for(i=0;i<m;i++){b=w=-1;
        for(j=0;j<n;j++){if(blk[j]>=p[i]&&(b==-1||blk[j]<blk[b]))b=j;
            if(tmp[j]>=p[i]&&(w==-1||tmp[j]>tmp[w]))w=j;}
        if(b!=-1){ba[i]=b;blk[b]-=p[i];}else ba[i]=-1;
        if(w!=-1){wa[i]=w;tmp[w]-=p[i];}else wa[i]=-1;}
    printf("\nBest Fit:\n");
    for(i=0;i<m;i++)printf("P%d -> %d\n",i+1,ba[i]!=-1?ba[i]+1:-1);
    printf("\nWorst Fit:\n");
    for(i=0;i<m;i++)printf("P%d -> %d\n",i+1,wa[i]!=-1?wa[i]+1:-1);
}
