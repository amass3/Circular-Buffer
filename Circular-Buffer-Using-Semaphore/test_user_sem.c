/**********************
 * to test user-space *
 **********************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "buffer_user_sem.c"

int main(){

	init_buffer_421();

	pthread_t pro[SIZE_OF_BUFFER],con[SIZE_OF_BUFFER];
    	//pthread_mutex_init(&mutex, NULL);

    	int a[SIZE_OF_BUFFER] = {1,2,3,4,5,6,7,8,9,10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; //Just used for numbering the producer and consumer

    	for(int i = 0; i < SIZE_OF_BUFFER; i++) {
        	pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    	}
    	for(int i = 0; i < SIZE_OF_BUFFER; i++) {
        	pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    	}

    	for(int i = 0; i < SIZE_OF_BUFFER; i++) {
        	pthread_join(pro[i], NULL);
    	}
    	for(int i = 0; i < SIZE_OF_BUFFER; i++) {
        	pthread_join(con[i], NULL);
    	}

	delete_buffer_421();
	print_semaphores();
	return 0;
}
