#include <stdio.h>
#define N 5
int id[N], freq[N], size=0;
void insert(int x){
    for(int i=0;i<size;i++)if(id[i]==x){freq[i]++;return;}
    if(size==N){int m=0;for(int i=1;i<N;i++)if(freq[i]<freq[m])m=i;
    printf("Evict %d (freq %d)\n",id[m],freq[m]);id[m]=x;freq[m]=1;}
    else{id[size]=x;freq[size++]=1;}}
void display(){for(int i=0;i<size;i++)printf("%d(%d) ",id[i],freq[i]);printf("\n");}
int main(){int x;printf("Enter product IDs (0 to stop):\n");
while(scanf("%d",&x)==1&&x)insert(x);display();return 0;}