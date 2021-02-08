#include "std_lib_facilities.h"

int square(int a)
{
	return a*a;
}

int main()
{
	/*
	int i = 0;

	while(i < 100)
	{
		cout << i << '\t' << i*i << '\n';
		++i;
	}
	*/
	
	for (int j = 0; j < 100; ++j)
		cout << j << '\t' << square(j) << '\n';

	return 0;
}