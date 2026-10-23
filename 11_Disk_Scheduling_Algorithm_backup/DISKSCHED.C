#include <stdio.h>
#include <stdlib.h>
#define M 20
void s(int a[], int n) {
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j]) {
                int t=a[i]; a[i]=a[j]; a[j]=t;
            }}
int main() {
    int n,h,d,ds=200,r[M],t[M],v[M]={0};
    int i,j,tot,c,p,mn;
    printf("Req: "); scanf("%d",&n);
    printf("Tracks: ");
    for(i=0;i<n;i++) scanf("%d",&r[i]);
    printf("Head Dir: "); scanf("%d%d",&h,&d);
    for(i=0;i<n;i++) t[i]=r[i];
    t[n]=h; s(t,n+1);
    printf("FCFS: %d ",h);
    for(tot=0,c=h,i=0;i<n;i++) {
        tot+=abs(c-r[i]); c=r[i];
        printf("%d ",c);
    }
    printf("=%d\n",tot);
    printf("SSTF: %d ",h);
    for(tot=0,c=h,i=0;i<n;i++) {
        mn=9999;
        for(j=0;j<n;j++)
            if(!v[j] && abs(c-r[j])<mn)
                mn=abs(c-r[j]),p=j;
        v[p]=1; tot+=mn; c=r[p];
        printf("%d ",c);
    }
    printf("=%d\n",tot);
    printf("SCAN: ");
    for(tot=0,c=h,i=0;i<=n;i++)
        if(t[i]>=h) {
            printf("%d ",t[i]);
            tot+=abs(c-t[i]); c=t[i];
        }
    tot+=abs(c-ds+1); c=ds-1;
    printf("%d ",c);
    for(i=n;i>=0;i--)
        if(t[i]<h) {
            printf("%d ",t[i]);
            tot+=abs(c-t[i]); c=t[i];
        }
    printf("=%d\n",tot);
    printf("CSCAN: ");
    for(tot=0,c=h,i=0;i<=n;i++)
        if(t[i]>=h) {
            printf("%d ",t[i]);
            tot+=abs(c-t[i]); c=t[i];
        }
    tot+=abs(c-ds+1)+ds-1; c=0;
    printf("%d 0 ",ds-1);
    for(i=0;i<=n;i++)
        if(t[i]<h) {
            printf("%d ",t[i]);
            tot+=abs(c-t[i]); c=t[i];
        }
    printf("=%d\n",tot);
   printf("LOOK: ");
    for(tot=0,c=h,i=0;i<=n;i++)
        if(t[i]>=h) {
            printf("%d ",t[i]);
            tot+=abs(c-t[i]); c=t[i];
        }
    for(i=n;i>=0;i--)
        if(t[i]<h) {
            printf("%d ",t[i]);
            tot+=abs(c-t[i]); c=t[i];
        }
    printf("=%d\n",tot);
    printf("CLOOK: ");
    for(tot=0,c=h,i=0;i<=n;i++)
        if(t[i]>=h) {
            printf("%d ",t[i]);
            tot+=abs(c-t[i]); c=t[i];
        }
    for(i=0;i<=n;i++)
        if(t[i]<h) {
            printf("%d ",t[i]);
            tot+=abs(c-t[i]); c=t[i];
        }
    printf("=%d\n",tot);
    return 0;
}