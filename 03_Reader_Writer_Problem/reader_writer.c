#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

typedef struct { float price; int stock; } Product;
Product p = {99.99, 100};
pthread_rwlock_t lock = PTHREAD_RWLOCK_INITIALIZER;

void* reader(void* arg) {
    for(int i=0;i<5;i++){
        pthread_rwlock_rdlock(&lock);
        printf("R%d: price=%.2f stock=%d\n",*(int*)arg,p.price,p.stock);
        pthread_rwlock_unlock(&lock);
        usleep(100000);
    }
    return NULL;
}

void* writer(void* arg) {
    for(int i=0;i<3;i++){
        pthread_rwlock_wrlock(&lock);
        p.price -= 1.0; p.stock -= 5;
        printf("W: updated price=%.2f stock=%d\n",p.price,p.stock);
        pthread_rwlock_unlock(&lock);
        usleep(200000);
    }
     return NULL;
}

int main() {
    pthread_t r1,r2,w;
    int id1=1,id2=2;
    pthread_create(&r1,NULL,reader,&id1);
    pthread_create(&r2,NULL,reader,&id2);
    pthread_create(&w,NULL,writer,NULL);
    pthread_join(r1,NULL); pthread_join(r2,NULL); pthread_join(w,NULL);
    return 0;
}