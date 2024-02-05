#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
  int pipefds[2]; 
  char buffer[256];

  pipe(pipefds);
  
  if(!fork()) {
    close(pipefds[0]);  
    dup2(pipefds[1], STDOUT_FILENO);

    printf("Greetings ");
    printf("from "); 
    printf("child process!");
  }
  else {
    close(pipefds[1]);
    dup2(pipefds[0], STDIN_FILENO);

    int n = read(STDIN_FILENO, buffer, 256);
    buffer[n] = 0;  
    printf("Parent received: %s\n", buffer);
  }

  return 0;  
}