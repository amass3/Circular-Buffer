/**************
 * user-space *
 **************/
#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"

node_421_t* tail = NULL;
node_421_t* head = NULL;
int buffer_length = 0;
ring_buffer_421_t buffer;


long init_buffer_421(void){
	// Initializes a new circular buffer in memory(kernel memory for kernel space), allocating
	//memory for each node. (Use malloc in user space, kmalloc in kernel space.)
	int i;

	//Return 0 if we successfully initialize, -1 if we fail for any reason
	if((head == NULL) && (tail == NULL)){
		node_421_t* temp = (struct node_421*)malloc(sizeof(node_421_t));

		//There should be 20 nodes total.
		for(i = 0; i < SIZE_OF_BUFFER; i++){

			if(i == 0){

				head = temp;
				//Each node should store an initial integer value of 0.
				head->data = 0;

			}else{

				temp->next = (struct node_421*)malloc(sizeof(node_421_t));

				//Each node should store an initial integer value of 0.
				temp->next->data = 0;
				temp = temp->next;
			}
		}

		//The final node's next pointer should point to the first node to create a circle.
		tail = temp;
		tail->next = head;
		printf("successfully initialized buffer.\n");
		return 0;
	}

	printf("failed to initialized buffer.\n");
	printf("buffer already initialized.\n");
	return -1;

	//being initialized. Do not reinitialize the buffer if it already exists.
}

long insert_buffer_421(int i){

	//Inserts the integer i into the next available node.
	int j;
        node_421_t *temp = head;

	//Note: We cannot insert data into an uninitialized buffer.
	if((head != NULL) && (tail != NULL)){

		if(buffer_length < SIZE_OF_BUFFER){

		        for(j = 0; j < SIZE_OF_BUFFER; j++)
        		{
				if(temp->data == 0){
                			temp->data = i;
					//Note: Increment the buffer length when you insert value
                                	buffer_length++;
					//Stop the loop to avoid adding the same value for every node
					j = SIZE_OF_BUFFER;
				}

                		temp = temp->next;
			}

		//Inserting fails if the buffer is already full.
        	}else{

			printf("the buffer is already full.\n");
			return -1;
		}
	}else{

		printf("cannot insert data into an uninitialized buffer.\n");
		return -1;
	}


	//Returns 0 if the insert is successful, -1 if it fails.
	return 0;
}

long print_buffer_421(void){

	int i;
	node_421_t *temp = head;//Begins at the buffer's read pointer.

	//Note: We cannot print an uninitialized buffer.
        if((head != NULL) && (tail != NULL)){

		// Writes a string representation of every node in the buffer, along with the data in each node,
		//to the kernel log. If in user-space, print to stdout instead.
		for(i = 0; i < SIZE_OF_BUFFER; i++)
        	{
        		printf("Node #%d--->Value:%d\n",i, temp->data);
                	temp = temp->next;
        	}
		return 0;
	}

	//Returns 0 if successful, -1 if not.
	printf("Cannot print an uninitialized buffer.\n");
	return -1;
}

long delete_buffer_421(void){

	int i;
	node_421_t *current = head;
	node_421_t *prev;

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
	}

	//Returns 0 if successful, -1 if not
	if((head == NULL)&&(tail == NULL))
		return 0;
	else{
		printf("Deleting buffer fail.\n");
		return -1;
	}
}
