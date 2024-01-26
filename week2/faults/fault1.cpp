// C++ program to demonstrate segmentation
// fault when array out of bound is accessed.
#include <iostream>
using namespace std;

int main()
{
int arr[2];
arr[120] = 10; // Access out of bound
arr[10] = 10; // Access out of bound
arr[60] = 10; // Access out of bound
cout << arr[120] << endl;
cout << arr[10] << endl;
cout << arr[60] << endl;
return 0;
}
