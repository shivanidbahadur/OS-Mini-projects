#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int seats;
sem_t sem;
pthread_mutex_t mon = PTHREAD_MUTEX_INITIALIZER;
void* book_sem(void* a) {
    sem_wait(&sem);
    if (seats > 0) { seats--; printf("Sem  -> Booked! Left: %d\n", seats); }
    else printf("Sem  -> Sold out!\n");
    sem_post(&sem);
    return NULL;
}
void* book_mon(void* a) {
    pthread_mutex_lock(&mon);
    if (seats > 0) { seats--; printf("Mon  -> Booked! Left: %d\n", seats); }
    else printf("Mon  -> Sold out!\n");
    pthread_mutex_unlock(&mon);
    return NULL;
}
int main() {
    int n, i; pthread_t t[20];
    printf("Enter seats & total requests: ");
    scanf("%d %d", &seats, &n);
    sem_init(&sem, 0, 1);
    for (i = 0; i < n/2; i++) pthread_create(&t[i], NULL, book_sem, NULL);
    for (i = n/2; i < n; i++) pthread_create(&t[i], NULL, book_mon, NULL);
    for (i = 0; i < n; i++) pthread_join(t[i], NULL);
    sem_destroy(&sem);
    return 0;
}
