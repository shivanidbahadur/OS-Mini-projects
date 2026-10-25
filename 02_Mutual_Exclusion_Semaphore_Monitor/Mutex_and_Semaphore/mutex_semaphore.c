#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int seats;
sem_t mutex;
void* book(void* arg) {
    sem_wait(&mutex);
    if (seats > 0) { seats--; printf("Booked! Seats left: %d\n", seats); }
    else printf("Sold out!\n");
    sem_post(&mutex);
    return NULL;
}
int main() {
    int n, i; pthread_t t[100];
    printf("Enter seats & requests: "); scanf("%d %d", &seats, &n);
    sem_init(&mutex, 0, 1);
    for (i = 0; i < n; i++) pthread_create(&t[i], NULL, book, NULL);
    for (i = 0; i < n; i++) pthread_join(t[i], NULL);
    sem_destroy(&mutex);
    return 0;
}

