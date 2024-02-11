/*
Example: execlp
 */

#include <iostream>
#include <stdexcept>
#include <unistd.h>
using namespace std;

int main()
{
    const char *file = "arithmetic"; // This is the expected binary
    const char *arg1 = "Hello world!";
    execlp(file, file, arg1, NULL);
    return 0;
}
