#include "std_lib_facilities.h"

int main()
{
	constexpr double cm_per_inch = 2.54;

	// "Enter length: 10 c, 5 i"
	double length = 1;
	char unit = 0;
	cout << "Please enter a length followed by a unit (c or i):\n";

	cin >> length >> unit;

	if (unit == 'c')
		cout << length << " cm == " << length / cm_per_inch << "in\n";
	else if (unit == 'i')
		cout << length << " in == " << length * cm_per_inch << "cm\n";
	else
		cout << "Unrecognized unit\n";

	return 0;
}