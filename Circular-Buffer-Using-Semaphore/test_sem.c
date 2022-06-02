/**********************
 * to test user-space *
 **********************/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "buffer_sem.h"

#define __NR_init_buffer_sem_421 446
long init_buffer_sem_421_syscall(void){
	return syscall(__NR_init_buffer_sem_421);
}
#define __NR_enqueue_buffer_sem_421 447
long enqueue_buffer_sem_421_syscall(char* data){
        return syscall(__NR_enqueue_buffer_sem_421);
}

#define __NR_dequeue_buffer_sem_421 448
long dequeue_buffer_sem_421_syscall(char* data){
        return syscall(__NR_dequeue_buffer_sem_421);
}

#define __NR_delete_buffer_sem_421 449
long delete_buffer_sem_421_syscall(void){
        return syscall(__NR_delete_buffer_sem_421);
}

int main(int argc, char *argv[]) {

long rv, rv1, rv2, rv3 ;
char [DATA_LENGTH];
char *ptr = data;

rv = init_buffer_sem_421_syscall();
if(rv < 0) {
	perror("init_buffer_sem_421 syscall failed");
}
else {
	printf("init_buffer_sem_421 syscall ran successfully, check dmesg output\n");
}

rv1 = enqueue_buffer_sem_421_syscall(ptr);
if(rv1 < 0) {
	perror("enqueue_buffer_sem_421 syscall failed");
}
else {
	printf("enqueue_buffer_sem_421 syscall ran successfully, check dmesg output\n");
}

rv2 = dequeue_buffer_sem_421_syscall(ptr);
if(rv2 < 0) {
	perror("dequeue_buffer_sem_421 syscall failed");
}
else {
	printf("dequeue_buffer_sem_421 syscall ran successfully, check dmesg output\n");
}

rv3 = delete_buffer_sem_421();
if(rv3 < 0) {
	perror("delete_buffer_sem_421 syscall failed");
}
else {
	printf("delete_buffer_sem_421 syscall ran successfully, check dmesg output\n");
}

return 0;
}
