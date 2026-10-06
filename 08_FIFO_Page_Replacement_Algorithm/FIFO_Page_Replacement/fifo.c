#include <stdio.h>
#include <string.h>
#define N 6
char *nodes[] = {"A","B","C","D","E","F"};
int graph[N][N] = {{0,1,1,0,0,0},{1,0,0,1,1,0},{1,0,0,0,0,1},
                   {0,1,0,0,0,0},{0,1,0,0,0,1},{0,0,1,0,1,0}};
void bfs(int start, int goal) {
    int q[N], front=0, rear=0, vis[N]={0}, prev[N];
    memset(prev, -1, sizeof(prev));
    q[rear++]=start; vis[start]=1;
    while(front<rear){
        int u=q[front++];
        if(u==goal) break;
        for(int v=0;v<N;v++) if(graph[u][v]&&!vis[v]){
            vis[v]=1; prev[v]=u; q[rear++]=v;}}
    int path[N], len=0;
    for(int u=goal;u!=-1;u=prev[u]) path[len++]=u;
    for(int i=len-1;i>=0;i--) printf("%s%s",nodes[path[i]],i?" -> ":"");
    printf("\n");}
int main(){
printf("FIFO Page Replacement Algorithm \nGoogle Maps – Route Navigation \n");
bfs(0,5); }
