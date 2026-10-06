#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,head,i,total=0;
    printf("Enter no. of CCTV requests: ");scanf("%d",&n);
    int req[n];
    printf("Enter disk tracks: ");for(i=0;i<n;i++)scanf("%d",&req[i]);
    printf("Enter current head: ");scanf("%d",&head);
    printf("Seek Sequence: %d ",head);
    for(i=0;i<n;i++){
        total+=abs(head-req[i]);
        head=req[i];
        printf("%d ",req[i]);}
    printf("\nTotal Seek Time: %d\n",total);
    return 0;}

