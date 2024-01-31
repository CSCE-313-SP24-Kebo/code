/*
Example: C program to implement 2 forks
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	fork(); // Child process 1
	fork(); // Child process 2
	
	printf("Welcome to CSCE 313!\n");
	return 0;
}
