buffer (part 1)
Author: Ayrton L. Massamba

To implement the files in part 1, I started by reading the articles given in the project
instruction documents for this project. Then, I did some more reseach to better understand how to implement
a circular buffer in the user and the kernel space. below are the sources, which helped
me finish part 1.

Sources:

https://medium.com/anubhav-shrimal/adding-a-hello-world-system-call-to-linux-kernel-dad32875872
https://www.linuxjournal.com/article/6930
https://brennan.io/2016/11/14/kernel-dev-ep3/
https://www.kernel.org/doc/html/v4.10/process/adding-syscalls.html

Moreover, I also refered to the project 1 instructions when it came to working
on the buffer in kernel-space. I must say that working on adding new system calls was very
time and effort consuming( It was the most challenging part). 
I went to various series of code modifications/changes to achieve the appropriate results.
All in all, implementing the user-space first allowed me to have a better approch when it came to implementing the circular buffer in the kernel-space.

There is no Makefile for test.c or test_user.c, THEREFORE, please compile them
separately or one at the time. The only Mafile present in the folder is for
compiling the kernel. Thank you!
