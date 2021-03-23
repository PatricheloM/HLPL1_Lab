#include "../std_lib_facilities.h"

struct Person
{

	string name;
	int age;
	string get_name() {return name;}
	int get_age() {return age;}

};

int main()
{

	Person x {"Goofy", 63};

	cout << x.get_name() << " - " << x.get_age() << endl;

	return 0;
}