/**********************
 * to test user-space *
 **********************/
#include "buffer_user.c"

int main(){

	long rv, rv1, rv2, rv3;

        //Test the function that iniates the buffer
        rv = init_buffer_421();

        if(rv < 0) {
                perror("init_buffer_421 function failed.\n");
        }
        else {
                printf("init_buffer_421 function ran successfully.\n");
        }

        //Test the function that insert data in the buffer nodes
        rv1 = insert_buffer_421(1);

	if(rv1 < 0) {
                perror("insert_buffer_421 function failed.\n");
        }
        else {
                printf("insert_buffer_421 funtion ran successfully.\n");
        }

	//Test the function that print data in the buffer nodes
        rv2 = print_buffer_421();

        if(rv2 < 0) {
                perror("print_buffer_421 function failed.\n");
        }
        else {
                printf("print_buffer_421 function ran successfully.\n");
        }

	//Test the function that delete data in the buffer nodes
        rv3 = delete_buffer_421();

        if(rv3 < 0) {
                perror("delete_buffer_421 function failed.\n");
        }
        else {
                printf("delete_buffer_421 function ran successfully.\n");
        }
	printf("\n");

	//Another way of testing code
	//Test function #1
	printf("#Trying to initialized for the first time.\n");
	init_buffer_421();

	printf("\n#Test error message (Second attempt at initialization):\n");
	init_buffer_421();
	printf("\n");

	int i;
	node_421_t *temp = head;

	//Print result
	print_buffer_421();
	printf("\n");

	//Test function #2
	printf("#Attempt to add values to each node for the first time\n");
	for(i = 0; i < SIZE_OF_BUFFER; i++)
        {
		insert_buffer_421(i+1);
	}


	printf("Results: \n");
	printf("\n");
	//Print result
	print_buffer_421();
	printf("\n");

	printf("#Attempt to add values to each node for the second time\n");
	printf("Results: \n");
	printf("\n");
	for(i = 0; i < SIZE_OF_BUFFER; i++)
        {
                insert_buffer_421(i+1);
        }
	printf("\n");

	//print result
	print_buffer_421();

	printf("\n");
	printf("Retesting using struct pointer read and write.\n");
	//Initialize buffer
        buffer.length = buffer_length;
        buffer.read = head;
        buffer.write = tail;

	printf("\n");
	printf("Reading ...\n");
	for(i = 0; i < buffer.length; i++){
                printf("Node #%d ---> value: %d.\n", i, buffer.read->data);
                buffer.read = buffer.read->next;
        }

	printf("\n");
        printf("Writing ...\n");
        //Test the ring_buffer_421_t in writing mode
        for(i = 0; i < buffer.length; i++){
                buffer.write->data = i*2;
                printf("Node #%d ---> value: %d.\n", i, buffer.write->data);
                buffer.write = buffer.write->next;
        }

	//Test fourth function
	delete_buffer_421();

	return 0;
}
