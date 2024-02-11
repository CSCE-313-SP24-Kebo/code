/*
Example: execl
 */

#include <iostream>
#include <stdexcept>
#include <unistd.h>
using namespace std;

int main()
{
    cout << "This is the main program running before the exec syscall" << endl;
    const char *file = "/home/davidkebo/2024_spring/week4/exec/arithmetic";
    const char *arg2 = "Hello world!\n\nToday is Wednesday.";
    const char *arg1 = "-e";
    execl(file, file, arg1, arg2, NULL); // Executable + Path to the Binary + Rest of the options ... + NULL
    cout << "This is the main program running after the exec syscall" << endl; // Not execute
    return 0;
}
