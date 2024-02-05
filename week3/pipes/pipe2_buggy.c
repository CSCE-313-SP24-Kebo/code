/*
Example: fork() and pipe() - *Bug
This program creates a parent process and child process
The goal is for the parent to sent a message to the child process
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	int pipefds[2];
	pid_t pid;
	char buf[30];
	//create pipe - ONE PIPE!
	
	if(pipe(pipefds)==-1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	memset(buf,0,30);
	pid = fork();// Two processes run - Parent and Child

	if(pid>0){
		printf("PARENT: writing to the pipe\n");
		//parent close the read end
		close(pipefds[0]);
		//parent write in the pipe write end
		write(pipefds[1],"CSCE313-24",10);
		//after finishing writing, parent close the write end
		close(pipefds[1]);
		//parent wait for child - parent waits for the return value of the child
		wait(NULL);
	}else{
		//child did not close the write end
		// ??
		//child read from the pipe's read end until the pipe is empty
		while(read(pipefds[0],buf,1)==1){
			printf("CHILD read from pipe --%s\n",buf);
		}
		// Close the read end of the pipe
		close(pipefds[0]);
		printf("CHILD: EXITING!");
		exit(EXIT_SUCCESS);

	}
	return 0;
}
