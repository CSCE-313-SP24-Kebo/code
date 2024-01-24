#include <iostream>
#include <stdexcept>
using namespace std;

float divide(float numerator, float denominator)
{
	if (denominator == 0) {
        throw runtime_error("Math error: Zero division\n");
    }
	return (numerator / denominator);
}

int main()
{
	float numerator;
	float denominator;
	float quotient;

  cout << "Enter the numerator: ";
  cin >> numerator;
  cout << "Enter the denominator: ";
  cin >> denominator;

  try {
				quotient = divide(numerator, denominator);
				cout << "The quotient is: " << quotient << endl;
    }

  catch (runtime_error& e) {
        cout << "Exception caught - " << e.what();
    }
} // end main
