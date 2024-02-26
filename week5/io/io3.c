/**
 C program to illustrate I/O system Calls
**/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main (void)
{
	int fd[2];
	char buf1[12] = "hello world";
	char buf2[12];

	// assume foobar.txt is already created
	fd[0] = open("today.txt", O_RDWR); // file descriptor 1
	fd[1] = open("today.txt", O_RDWR); // file descriptor 2
	
	// Write 12 Bytes in the file today - starting from the cursor at position 0
	write(fd[0], buf1, strlen(buf1));		

	// Write to the STDOUT the value read from the file today.txt (fd[0])
	// write(1, buf2, read(fd[0], buf2, 12));
	write(1, buf2, read(fd[1], buf2, 12));

	close(fd[0]);
	close(fd[1]);

	return 0;
}


/*
CASE 1:

file content:
Happy Valentines Day!

After the first write:
hello worldtines Day!

At the second write:
tines Day!

*/