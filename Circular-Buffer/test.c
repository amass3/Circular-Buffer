/************************
 * to test kernel space *
 ************************/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "buffer.h"

#define __NR_init_buffer_421 442
long init_buffer_421_syscall(void){

	return syscall(__NR_init_buffer_421);
}
#define __NR_insert_buffer_421 443
long insert_buffer_421_syscall(int i){

	return syscall(__NR_insert_buffer_421);
}
#define __NR_print_buffer_421 444
long print_buffer_421_syscall(void){

	return syscall(__NR_print_buffer_421);
}
#define __NR_delete_buffer_421 445
long delete_buffer_421_syscall(void){

	return syscall(__NR_delete_buffer_421);
}

int main(int argc, char *argv[]) {

	long rv, rv1, rv2, rv3;

	//Test the function that iniates the buffer
	rv = init_buffer_421_syscall();

	if(rv < 0) {
		perror("init_buffer_421 syscall failed");
	}
	else {
		printf("init_buffer_421 syscall ran successfully, check dmesg output\n");
	}

	//Test the function that insert data in the buffer nodes
	rv1 = insert_buffer_421_syscall(1);

        if(rv1 < 0) {
                perror("insert_buffer_421 syscall failed");
        }
        else {
                printf("insert_buffer_421 syscall ran successfully, check dmesg output\n");
        }

	//Test the function that print the buffer
	rv2 = print_buffer_421_syscall();

        if(rv2 < 0) {
                perror("print_buffer_421 syscall failed");
        }
        else {
                printf("print_buffer_421 syscall ran successfully, check dmesg output\n");
        }

	//Test the function that delete the buffer
	rv3 = delete_buffer_421_syscall();


        if(rv3 < 0) {
                perror("delete_buffer_421 syscall failed");
        }
        else {
                printf("delete_buffer_421 syscall ran successfully, check dmesg output\n");
        }


	return 0;
}
