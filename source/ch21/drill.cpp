#include "../std_lib_facilities.h"

struct Item
{
	private:	string name;
				int iid;
				double value;

	public:		Item(string c_name, int c_iid, double c_value)
	{
		name = c_name;
		iid = c_iid;
		value = c_value;
	}

	const string get_name(){ return name;}
	const int get_iid(){ return iid;}
	const double get_value(){ return value;}
};

void fillVectorFromFile(string filename, vector<Item> &itemVector)
{
	ifstream sr {filename};
	if (!sr)
	{
		error("Can't open output file ", filename);
	}

	while(true)
	{
		if (sr.eof())
		{
			break;
		}

		string tmp;
		getline(sr, tmp);
		vector<string> v;
		stringstream ss(tmp);

		while(ss.good())
		{
			string substr;
			getline(ss, substr, ',');
			v.push_back(substr);
		}

		string in_name = v[0];
		int in_iid = stoi(v[1]);
		double in_value = stod(v[2]); // <--- valamiért a nagyobb számokat kerekíti, pl.: 189999.99-ből 190000 lesz

		itemVector.push_back(Item{in_name, in_iid, in_value});
	}
}

istream &operator>>(istream &i, Item &item)
{
	string in_name;
	int in_iid;
	double in_value;

	i >> in_name >> in_iid >> in_value;
	item = Item{in_name, in_iid, in_value};

	return i;
}

ostream &operator<<(ostream &o, Item &item)
{
	o << item.get_name() << " (ID: " << item.get_iid() << ") " << item.get_value() << " Ft" << endl;

	return o;
}

void printItemVector(vector<Item> itemVector)
{
	for (auto a : itemVector)
	{
		cout << a;
	}
}

bool compareName (Item &a, Item &b) { return a.get_name() < b.get_name();}
bool compareID (Item &a, Item &b) { return a.get_iid() < b.get_iid();}
bool compareValue (Item &a, Item &b) { return a.get_value() < b.get_value();}

int findInBy(vector<Item> itemVector, int what, string which) 	// int what: (1->name; 2->ID; 3->value); not in vector: (return index->-1); string which: (is a string but converted to according variable inside function)
{
	int index = -1;

	switch (what)
	{
		case 1:
		{
			for (int i = 0; i < itemVector.size(); ++i)
			{
				if (itemVector[i].get_name() == which)
				{
					index = i;
					break;
				}
			}
			break;
		}
		case 2:
		{
			for (int i = 0; i < itemVector.size(); ++i)
			{
				if (itemVector[i].get_iid() == stoi(which))
				{
					index = i;
					break;
				}
			}
			break;
		}
		case 3:
		{
			for (int i = 0; i < itemVector.size(); ++i)
			{
				if (itemVector[i].get_value() == stod(which))
				{
					index = i;
					break;
				}
			}
			break;
		}
		default:
		{
			error("Item struct does not have a member like that.");
			break;
		}
	}
	return index;
}

void eraseByIndex(vector<Item> &itemVector, int index)
{
	if (index < 0 || index >= itemVector.size())
	{
		error("Wrong index!");
	}
	else
	{
		itemVector.erase(itemVector.begin()+index);
	}
}


int main()
{
	vector<Item> itemVector;
	fillVectorFromFile("items.txt", itemVector);

	itemVector.push_back(Item{"horse shoe", 99, 12.34});
	itemVector.push_back(Item{"Canon S400", 9988, 499.95});

	//sort(itemVector.begin(), itemVector.end(), compareName);
	//sort(itemVector.begin(), itemVector.end(), compareID);
	sort(itemVector.begin(), itemVector.end(), compareValue);

	printItemVector(itemVector);

	eraseByIndex(itemVector, findInBy(itemVector, 1, "vonalzó"));
	eraseByIndex(itemVector, findInBy(itemVector, 1, "ceruza"));

	eraseByIndex(itemVector, findInBy(itemVector, 2, "234"));
	eraseByIndex(itemVector, findInBy(itemVector, 2, "9988"));


	return 0;
}