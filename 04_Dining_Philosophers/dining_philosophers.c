#include <stdio.h>
#include <pthread.h>
int N; pthread_mutex_t road[20];
void *car(void *arg){int i=*(int*)arg;
pthread_mutex_lock(&road[i]);
printf("Car %d reserved road[%d]\n",i,i);
pthread_mutex_lock(&road[(i+1)%N]);
printf("Car %d moving through road %d\n",i,(i+1)%N);
pthread_mutex_unlock(&road[(i+1)%N]);
pthread_mutex_unlock(&road[i]);return NULL;}

int main(){
printf("Enter number of cars: "); scanf("%d",&N);
pthread_t c[N]; int id[N];
for(int i=0;i<N;i++) pthread_mutex_init(&road[i],NULL),id[i]=i,pthread_create(&c[i],NULL,car,&id[i]);
for(int i=0;i<N;i++) pthread_join(c[i],NULL);return 0;
}
