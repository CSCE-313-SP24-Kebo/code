/*
Example: C program to differentiate a parent process from a child process after a fork
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

void forkexample()
{
	int child_status;
	// child process because the return value is zero
	if (fork() == 0)
	{
		printf("1. Hello from Child!\n");
		printf("1. Child process ID is %d\n", getpid()); // getpid() returns the current process PID
		printf("1. Child: My parent process ID is %d\n", getppid()); // getppid() return sthe process ID of the parent process
	}

	// parent process because the return value is non-zero.
	else
	{
		//wait();
		wait(&child_status); // Waits at least one child process to return an exit status
		printf("2. Hello from Parent!\n");
		printf("2. Parent process ID is %d\n", getpid());
		printf("2. Parent: My parent process ID is %d\n", getppid());
	}
}
int main()
{
	forkexample();
	return 0;
}
