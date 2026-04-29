#include <stdio.h>
#include <semaphore.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;

sem_t empty, full, mutex;

void produce() {
    static int item = 1;

    if(sem_trywait(&empty) == 0) {
        sem_wait(&mutex);

        buffer[in] = item;
        printf("Producer has produced: Item %d\n", item);
        in = (in + 1) % SIZE;
        item++;

        sem_post(&mutex);
        sem_post(&full);
    } else {
        printf("Buffer is full!\n");
    }
}

void consume() {
    if(sem_trywait(&full) == 0) {
        sem_wait(&mutex);

        int item = buffer[out];
        printf("Consumer has consumed: Item %d\n", item);
        out = (out + 1) % SIZE;

        sem_post(&mutex);
        sem_post(&empty);
    } else {
        printf("Buffer is empty!\n");
    }
}

int main() {
    int choice;

    sem_init(&empty, 0, SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    while(1) {
        printf("\nEnter 1.Producer 2.Consumer 3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                produce();
                break;

            case 2:
                consume();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
