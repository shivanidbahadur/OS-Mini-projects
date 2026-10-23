#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t track[2] = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER};
void *train(void *arg) {
    int id = *(int*)arg, f = id % 2, s = 1 - f;
    printf("Train %d: requesting Track-%d\n", id, f);
    pthread_mutex_lock(&track[f]);
    printf("Train %d: LOCKED Track-%d\n", id, f);
    for (int i = 1; i <= 3; i++) {
        printf("Train %d: moving on Track-%d (step %d/3)\n", id, f, i);
        sleep(1);
    }
    printf("Train %d: requesting Track-%d\n", id, s);
    pthread_mutex_lock(&track[s]);
    printf("Train %d: crossed safely\n", id);
    pthread_mutex_unlock(&track[s]);
    pthread_mutex_unlock(&track[f]);
    return NULL;
}
int main() {
    int x, y;
    pthread_t a, b;
    printf("Enter two train IDs: ");
    scanf("%d %d", &x, &y);
    pthread_create(&a, NULL, train, &x);
    pthread_create(&b, NULL, train, &y);
    pthread_join(a, NULL);
    pthread_join(b, NULL);
   printf("No deadlock occurred\n");
}
