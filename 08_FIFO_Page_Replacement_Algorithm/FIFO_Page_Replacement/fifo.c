#include <stdio.h>
#include <string.h>
#define N 6
int g[N][N] = {{0,1,1,0,0,0},{1,0,0,1,1,0},{1,0,0,0,0,1},{0,1,0,0,0,0},{0,1,0,0,0,1},{0,0,1,0,1,0}};
int main() { char s, d; int q[N], f = 0, r = 0, vis[N] = {0}, prev[N], path[N], len = 0;
    printf("Enter start and goal (A-F): "); scanf(" %c %c", &s, &d); s -= 'A'; d -= 'A';
    memset(prev, -1, sizeof(prev)); q[r++] = s; vis[s] = 1; printf("Visiting order: ");
    while (f < r) { int u = q[f++]; printf("%c ", 'A' + u); if (u == d) break;
        for (int v = 0; v < N; v++) if (g[u][v] && !vis[v]) { vis[v] = 1; prev[v] = u; q[r++] = v; } }
    for (int u = d; u != -1; u = prev[u]) path[len++] = u;
    printf("\nShortest route: ");
    for (int i = len - 1; i >= 0; i--) printf("%c%s", 'A' + path[i], i ? " -> " : "\n");
    printf("Total hops: %d\n", len - 1);
    printf("Nodes explored: %d\n", f);
return 0; }
