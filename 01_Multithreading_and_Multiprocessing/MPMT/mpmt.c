#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
void* driver(void* id) {long d=(long)id;printf("Driver %ld: Ride accepted\n",d);sleep(1);
printf("Driver %ld: Trip done | Payment received\n",d);return NULL;}
int main() {if(fork()==0){ pthread_t t[2];
        for(long i=0;i<2;i++) pthread_create(&t[i],NULL,driver,(void*)i);
        for(int i=0;i<2;i++) pthread_join(t[i],NULL); }
else if(fork()==0){ pthread_t t[2];
        for(long i=2;i<4;i++) pthread_create(&t[i-2],NULL,driver,(void*)i);
        for(int i=0;i<2;i++) pthread_join(t[i],NULL); }
else { wait(NULL); wait(NULL); }return 0;}
