#include <stdio.h>

int main()
{char *app[] = {"Instagram", "Whatsapp", "Youtube"};
 int bt[] = {5, 2, 4}, i, j, t;
 for (i = 0; i < 3; i++){for (j = i + 1; j < 3; j++){
     if (bt[i] > bt[j]){t = bt[i];bt[i] = bt[j];bt[j] = t;
char *p = app[i];
app[i] = app[j];
app[j] = p;
}}}
printf("SJF CPU scheduling\n");
int wt = 0;
for (i = 0; i < 3; i++)
{printf("%s Burst = %d Waiting = %d\n",
 app[i], bt[i], wt);
wt = wt + bt[i];}
return 0;
}
