#include "../std_lib_facilities.h"

struct Person
{
	private: 	string first_name;
				string second_name;
				int age;
	
	public:		Person(string c_first_name, string c_second_name, int c_age)
	{
		if (c_age >= 0 && c_age < 150)
		{
			age = c_age;
		}
		else
		{
			error("Gondolom...");
		
		}

		string special_chars = ";:\"\'[]*&^%$#@!.";

		for (int i = 0; i < c_first_name.size(); ++i)
		{
			for (int j = 0; j < special_chars.size(); ++j)
			{
				if (c_first_name[i] == special_chars[j])
				{
					error("Special character in name!");
				}
			}
		}

		for (int i = 0; i < c_second_name.size(); ++i)
		{
			for (int j = 0; j < special_chars.size(); ++j)
			{
				if (c_second_name[i] == special_chars[j])
				{
					error("Special character in name!");
				}
			}
		}

		first_name = c_first_name;
		second_name = c_second_name;
	}

	const string get_name() { return first_name + ' ' + second_name; }
	const int get_age() { return age; }

};


istream &operator>>(istream &i, Person &p)
{
	string in_first_name;
	string in_second_name;
	int in_age;

	i >> in_first_name >> in_second_name >> in_age;
	p = Person{in_first_name, in_second_name, in_age};

	return i;
}

ostream &operator<<(ostream &o, Person &p)
{
	o << p.get_name() << " - " << p.get_age() << endl;

	return o;
}

int main()
{

	Person buffer {"", "", 0};

	/*
	cin >> buffer;

	cout << buffer;
	*/

	vector<Person> persons;

	while (cin >> buffer)
	{
		persons.push_back(buffer);
	}

	for (int i = 0; i < persons.size(); ++i)
	{
		cout << persons[i];
	}

	return 0;
}