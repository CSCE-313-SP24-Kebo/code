/*
Parent fork child process
Child process inherit the file descriptor of the parent.
file position can be updated from both processes
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include <sys/wait.h>

/*
Independent processes has a File Table contains file descriptors: 0, 1, 2, 3, 4 ... etc.
Parent and child processes share the same file descriptors.
*/

int main()
{
	char c;
	int fd = open("sample.txt", O_RDONLY, 0); // File descriptor SHARED between the child and parent process
	if (fork() == 0 ){
		printf("File descriptor: %d \n", fd);
		read(fd, &c, 1); // In the child read one character from Minecraft - character 'M'
		read(fd, &c, 1); // In the child read one character from Minecraft - character 'i'
		read(fd, &c, 1); // In the child read one character from Minecraft - character 'n'
		read(fd, &c, 1); // In the child read one character from Minecraft - character 'e'
		printf("Child --- c = %c\n", c);
		return 0; 
	}
	else {
		wait(0); // Wait for the child to finish updating the fd
		printf("File descriptor: %d \n", fd);
		lseek (fd, 0, SEEK_CUR);
		read(fd, &c, 1); // In the parent read one character from Minecraft - character ??
		printf("Parent --- c = %c\n", c);
	}

	exit(0);
}


/*
- parent
-- child 1
--- child 2
----- child 3
------- child 4
--------- child 5
*/

/*
--------- M
--------- i
--------- n
--------- e
--------- c << read
---------
---------
---------
---------



*/