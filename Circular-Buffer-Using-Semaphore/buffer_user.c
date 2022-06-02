#include <stdlib.h>
#include <stdio.h>
#include "buffer_sem.h"

static bb_buffer_421_t buffer;
static sem_t mutex;
static sem_t fill_count;
static sem_t empty_count;
bb_node_421_t *head = NULL;
bb_node_421_t *tail = NULL;


long init_buffer_421(void) {
	// Write your code to initialize buffer
	int i;

	//Return 0 if we successfully initialize, -1 if we fail for any reason
	if((head == NULL) && (tail == NULL)){

		bb_node_421_t* temp = (struct bb_node_421*)malloc(sizeof(bb_node_421_t));

		//There should be 20 nodes total.
		for(i = 0; i < SIZE_OF_BUFFER; i++){
			if(i == 0){
				head = temp;
			}else{
				temp->next = (struct bb_node_421*)malloc(sizeof(bb_node_421_t));
				temp = temp->next;
			}
		}

		//The final node's next pointer should point to the first node to create a circle.
		tail = temp;
		tail->next = head;
		printf("successfully initialized buffer.\n");
	}else{

		printf("failed to initialized buffer.\n");
		printf("buffer already initialized.\n");
		return -1;
		//being initialized. Do not reinitialize the buffer if it already exists.
	}

	// Initialize your semaphores here.
	sem_init(&mutex, 0, 1);
	sem_init(&fill_count, 0, 0);
	sem_init(&empty_count, 0, SIZE_OF_BUFFER);

	return 0;
}


long enqueue_buffer_421(char * data) {
	// Write your code to enqueue data into the buffer
	int i;
	int value;
        sem_getvalue(&fill_count, &value);
	buffer.write = head;

	// We cannot insert data into an uninitialized buffer.
	if((head != NULL) && (tail != NULL)){
		//We cannot insert data into a full buffer. When this happens, we
		//should BLOCK the caller (Hint: use a Semaphore)
		if(value < SIZE_OF_BUFFER){
			//Copies 1024 bytes from data into the write node's data variable.
			for(i = 0; i < DATA_LENGTH; i++)
				buffer.write->data[i] = data[i];
			//correctly update the buffer's length and write pointer.
			buffer.write = buffer.write->next;
			buffer.length++;
		}else{
			printf("We cannot insert data into a full buffer. When this happens,should BLOCK the caller\n");
			return -1;
		}
	}else{
		printf("We cannot insert data into an uninitialized buffer.\n");
		return -1;
	}
	return 0;
}

long dequeue_buffer_421(char * data) {

	// Write your code to dequeue data from the buffer
	int i;
	int value;
        sem_getvalue(&empty_count, &value);
	buffer.read = head;

        // We cannot dequeue data into an uninitialized buffer.
        if(buffer.length != 0){
                //We cannot dequeuue data into a empty buffer. When this happens, >
                //should BLOCK the caller (Hint: use a Semaphore)
                if(value < SIZE_OF_BUFFER){
                        //Copies 1024 bytes from data into the write node's dat>
			for(i = 0; i < DATA_LENGTH; i++)
	                        buffer.read->data[i] = data[i];
                        //correctly update the buffer's length and write pointe>
                        buffer.read = buffer.read->next;
                        buffer.length--;
                }else{
                        printf("We cannot dequeue data into an empty buffer\n");
                        return -1;
                }
        }else{
                printf("We cannot dequeue data into an uninitialized buffer.\n");
		return -1;
	}
	return 0;
}


long delete_buffer_421(void) {
	// Tip: Don't call this while any process is waiting to enqueue or dequeue.
	// write your code to delete buffer and other unwanted components
	int i;
	bb_node_421_t *current = head;
	bb_node_421_t *prev;

	//If it exists, delete the buffer.
	if((head != NULL) && (tail != NULL)){

		//Free any memory (free in user-space, kfree in kernel-space) that you allocated in
		//init_buffer_421.
		for(i = 0; i < SIZE_OF_BUFFER; i++)
                {
			prev = current;
                        current = current->next;
			free(prev);
                }
		head = NULL;
		tail = NULL;
		sem_destroy(&mutex);
		sem_destroy(&fill_count);
		sem_destroy(&empty_count);
	}

	//Returns 0 if successful, -1 if not
	if((head == NULL)&&(tail == NULL))
		return 0;
	else{
		printf("Deleting buffer fail.\n");
		return -1;
	}
}

void print_semaphores(void) {
	// You can call this method to check the status of the semaphores.
	// Don't forget to initialize them first!
	// YOU DO NOT NEED TO IMPLEMENT THIS FOR KERNEL SPACE.
	int value;
	sem_getvalue(&mutex, &value);
	printf("sem_t mutex = %d\n", value);
	sem_getvalue(&fill_count, &value);
	printf("sem_t fill_count = %d\n", value);
	sem_getvalue(&empty_count, &value);
	printf("sem_t empty_count = %d\n", value);
	return;
}
