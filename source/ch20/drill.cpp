#include "../std_lib_facilities.h"

int array1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<int> vector1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
list<int> list1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

template<typename data>
void increase(data& DATA, int n)
{
	for (auto& a : DATA)
	{
		a += n;
	}
}

template<typename Iter1, typename Iter2>
Iter2 copy(Iter1 begin1, Iter1 end1, Iter2 begin2)
{
	while (begin1 != end1)
	{
		*begin2 = *begin1;
		++begin1;
		++begin2;
	}
	return begin2;
}


int main()
{
	int array2[10];
	for (int i = 0; i < 10; ++i)
	{
		array2[i] = array1[i];
	}
	vector<int> vector2 = vector1;
	list<int> list2 = list1;

	increase(array1, 2);
	increase(vector1, 3);
	increase(list1, 5);

	//copy(array2.begin(), array2.end(), vector2.begin());
	//copy(list2.begin(), list2.end(), array2.begin());

	vector<int>::iterator vecIterator;
	vecIterator = find(vector1.begin(), vector1.end(), 3);
	if (vecIterator != vector1.end())
	{
		cout << "Found at: " << distance(vector1.begin(), vecIterator) << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}

	list<int>::iterator listIterator;
	listIterator = find(list1.begin(), list1.end(), 27);
	if (listIterator != list1.end())
	{
		cout << "Found at: " << distance(list1.begin(), listIterator) << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}

	return 0;
}