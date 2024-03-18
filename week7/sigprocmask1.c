/*
Example of signal sets and sigprocmask
Block and unblock signals
*/

#include "apue.h"

#include <signal.h>
#include <stdio.h>

int main() {
  sigset_t new_mask, old_mask;

  // Initialize the new signal mask.
  sigemptyset(&new_mask); // Before blocking - lear
  sigaddset(&new_mask, SIGINT); // new_mask = {SIGINT}

  // blocks the signals in the new_mask set and returns the old signal mask in the old_mask variable.
  sigprocmask(SIG_SETMASK, &new_mask, &old_mask);// Why keep a copy in old_mask - to keep a copy of the current mask

  // Print a message.
  printf("SIGINT is blocked.\n");

  // Sleep for 10 seconds.
  sleep(10);

  printf("Before restore\n");

  // Restore the old signal mask.
  sigprocmask(SIG_SETMASK, &old_mask, NULL); // Restore the old mask

  // Sleep for 10 seconds.
  sleep(10);

  // Print a message.
  printf("All signals are unblocked.\n");

  // Sleep for 10 seconds.
  sleep(10);

  return 0;
}
