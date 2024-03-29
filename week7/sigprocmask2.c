/*
Example of signal sets and sigprocmask
Note: When the program is executing, type Control-backslash, in the terminal to send a quit signal.

Example:
$ ./a.out
ˆ\                      generate signal once (before 5 seconds are up)
SIGINT pending         after return from sleep
caught SIGINT          in signal handler
SIGINT unblocked       after return from sigprocmask
ˆ\Quit(coredump)        generate signal again

$ ./a.out
ˆ\ˆ\ˆ\ˆ\ˆ\ˆ\ˆ\ˆ\ˆ\ˆ\    generate signal 10 times (before 5 seconds are up)
SIGINT pending
caught SIGINT          signal is generated only once
SIGINT unblocked
ˆ\Quit(coredump)        generate signal again

^\: means control + backslash
*/

#include "apue.h"

static void sig_quit(int);

int main(void)
{
    // Signal sets
    sigset_t newmask, oldmask, pendmask;

    if (signal(SIGINT, sig_quit) == SIG_ERR)
        printf("can’t catch SIGINT");

    // Initialize the signal set to empty, with all signals excluded from the set.
    sigemptyset(&newmask);

    // Add SIGINT to the set of signal to ignore
    sigaddset(&newmask, SIGINT);

    // The process blocks the signals in the set newmask (SIGINT), saving its current signal mask in oldset (to restore later)
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        printf("SIG_BLOCK error");

    /*
    Sleep for 5 seconds.
    Any occurrence of the quit signal (SIGINT) during this period is blocked and won’t be delivered until the signal is unblocked.
    At the end of the 5-second sleep, we check whether the signal is pending and unblock the signal.
    */
    sleep(5);

    // Return the set of signals that are pending for delivery
    if (sigpending(&pendmask) < 0)
        printf("sigpending error");

    if (sigismember(&pendmask, SIGINT))
        printf("\nSIGINT pending\n");
    /*
     Restore the signal mask which unblocks SIGINT.
     Note that we saved the old mask when we blocked the signal.
     To unblock the signal, we do a SIG_SETMASK of the old mask.
     Note: Alternatively, we could SIG_UNBLOCK only the signal that we had blocked. i.e. - > sigprocmask(SIG_UNBLOCK, &newmask, NULL);
     */
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        printf("SIG_SETMASK error");

    printf("SIGINT unblocked\n");
    sleep(5); /* SIGINT here will terminate with core file */
    exit(0);
}

// Custom Handler for SIG_QUIT
static void sig_quit(int signo)
{
    printf("caught SIGINT\n");

    // Fallback to the behavior
    if (signal(SIGINT, SIG_DFL) == SIG_ERR)
        printf("can’t reset SIGINT");
}