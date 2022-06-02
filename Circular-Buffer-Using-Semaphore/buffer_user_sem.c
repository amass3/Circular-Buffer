/**************
 * user-space *
 **************/
#include "buffer_user.c"
#include <pthread.h>
#include <time.h>

int in = 0;
int out = 0;
int item = 0; //Item to be produced or removed

void *producer(void *pno)
{
    int limit = 9;//char from 0 to 9
    char data[DATA_LENGTH];
    char *ptr = data;

    sem_wait(&empty_count);
    sem_wait(&mutex);
    printf("Producer %d: Insert Item: ", *((int *)pno));
    for(int i = 0; i < DATA_LENGTH; i++) {
	if(item > limit)
		item = 0;
 	data[i] = item;
	}
    for(int i = 0; i < SIZE_OF_BUFFER; i++)
    	printf("%d",data[i]);
    printf("... ");
    printf("at node %d\n", buffer.length);
    sem_post(&mutex);
    sem_post(&fill_count);
    enqueue_buffer_421(ptr);
    item++;
}

void *consumer(void *cno)
{
    int item = -1;// consume an item
    char data[DATA_LENGTH];
    char *ptr = data;

    sem_wait(&fill_count);
    sem_wait(&mutex);
    printf("Consumer %d: Remove Item: ", *((int *)cno));
    for(int i = 0; i < DATA_LENGTH; i++) {
        data[i] = item;
        }
    for(int i = 0; i < SIZE_OF_BUFFER; i++)
        printf("%d",data[i]);
    printf("... ");
    printf("at node %d\n", buffer.length);
    sem_post(&mutex);
    sem_post(&empty_count);
    dequeue_buffer_421(ptr);
}
