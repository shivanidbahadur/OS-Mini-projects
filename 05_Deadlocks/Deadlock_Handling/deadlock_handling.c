#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t t0 = PTHREAD_MUTEX_INITIALIZER, t1 = PTHREAD_MUTEX_INITIALIZER;
void *train(void *id) {
    int tid = *(int*)id;
    printf("Train %d: requesting Track-0\n", tid); pthread_mutex_lock(&t0);
    printf("Train %d: LOCKED Track-0\n", tid); sleep(1);
    printf("Train %d: requesting Track-1\n", tid); pthread_mutex_lock(&t1);
    printf("Train %d: LOCKED Track-1, crossing...\n", tid); sleep(1);
    printf("Train %d crossed safely\n", tid); pthread_mutex_unlock(&t1); pthread_mutex_unlock(&t0); return NULL;
}
int main() {
    int x, y; pthread_t a, b;
    printf("Enter Train IDs: "); scanf("%d %d", &x, &y);
    pthread_create(&a, NULL, train, &x); pthread_create(&b, NULL, train, &y);
    pthread_join(a, NULL); pthread_join(b, NULL);
    printf("No deadlock occurred\n");
}
