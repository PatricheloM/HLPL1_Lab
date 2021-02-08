#include "std_lib_facilities.h"

int main()
{
	cout << "Hello, world!\n";

	int age = 12;
	int age_2 = 15;
	char c = 'a';
	double d = 12.5;

	int age_3 = ++age;

	cout << "Age: " << age << '\n';
	cout << "D: " << d << '\n';

	string first_name = "Amin ";

	string family_name;
	
	cout << "Please enter your family name: ";
	cin >> family_name;

	first_name += family_name;

	cout << first_name << '\n';

	string full_name = first_name + ' ' + family_name;

	cout << full_name << '\n';

	return 0;
}