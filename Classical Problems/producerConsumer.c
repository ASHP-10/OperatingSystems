#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex, full, empty;
int gitem = 0, put = 0, get = 0, pro[20],con[20], buffer[5], item = 0;

void *producer(void *args) {
    do{
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[put % 5] = item;
        printf("producer %d produced item %d at buffer %d\n", (*(int*)args),buffer[put%5], put%5);
        put++;
        item++;

        sem_post(&mutex);
        sem_post(&full);
        sleep(3);
    } while(1);
}

void *consumer(void * args) {
    do{
        sem_wait(&full);
        sem_wait(&mutex);

        gitem = buffer[get % 5];
        printf("Consumer %d consumes item %d at buffer %d\n", (*(int *)args), gitem, get % 5);
        get++;

        sem_post(&mutex);
        sem_post(&empty);
        sleep(3);
    } while(1);
}

int main()
{
    int p, c;
    pthread_t a[10],b[10];

    sem_init(&mutex, 0 , 1);
    sem_init(&empty, 0 , 5);
    sem_init(&full, 0 , 0);

    printf("Enter number of producers: ");
    scanf("%d", &p);

    printf("Enter number of consumers: ");
    scanf("%d", &c);

    for(int i = 0; i < p; i++) {
        pro[i] = i;

        pthread_create(&a[i], NULL, producer, &pro[i]);
    }

    for(int i = 0; i < c; i++) {
        con[i] = i;

        pthread_create(&b[i], NULL, consumer, &con[i]);
    }

    for(int i = 0; i < p; i++) 
        pthread_join(a[i], NULL);

    for(int i = 0; i < c; i++) 
        pthread_join(b[i], NULL);

    return 0;
}