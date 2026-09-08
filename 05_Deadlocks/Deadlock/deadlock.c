#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t track[2];

void *trainA(void *arg) {
    printf("Train A locked Track-0, waiting for Track-1...\n");
    pthread_mutex_lock(&track[0]);
    sleep(1);
    pthread_mutex_lock(&track[1]);
    return NULL;
}void *trainB(void *arg) {
    printf("Train B locked Track-1, waiting for Track-0...\n");
    pthread_mutex_lock(&track[1]);
    sleep(1);
    pthread_mutex_lock(&track[0]);
    return NULL;
}int main() {
    int choice;
    printf("Enter 1 to start deadlock demo: ");
    scanf("%d", &choice);
    pthread_t t1, t2;
    pthread_mutex_init(&track[0], NULL);
    pthread_mutex_init(&track[1], NULL);
    pthread_create(&t1, NULL, trainA, NULL);
    pthread_create(&t2, NULL, trainB, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
