#include "../std_lib_facilities.h"

vector<double> vd;
vector<int> vi;
vector<double> vd2;

void fillVectorFromFile(string filename, vector<double> &vec)
{
	ifstream sr {filename};
	if (!sr)
	{
		error("Can't open input file ", filename);
	}

	while(true)
	{
		if (sr.eof())
		{
			break;
		}

		string tmp;
		getline(sr, tmp);
		vec.push_back(stod(tmp));
	}
}

template<typename VECTOR>
void printVector(VECTOR vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << '[' << i << "]:" << '\t' << vec[i] << endl;
	}

	cout << "--------------------------" << endl;
}

template<typename VECTOR1, typename VECTOR2>
void printVectorPairs(VECTOR1 vec1, VECTOR2 vec2)
{
	for (int i = 0; i < vec1.size(); ++i)
	{
		cout << '[' << i << "]:" << '\t' << vec1[i] << '\t' << " ~ " << '\t' << vec2[i] << endl;
	}

	cout << "--------------------------" << endl;
}

int main()
{
	fillVectorFromFile("float.txt", vd);
	printVector(vd);

	
	for (auto a : vd)
	{
		vi.push_back(a);
	}
	

	//copy(vd.begin(), vd.end(), vi.begin()); 	//Segmentation fault

	printVectorPairs(vd, vi);

	double sumOfVd = 0;
	for (auto a : vd)
	{
		sumOfVd += a;
	}

	double sumOfVi;
	for (auto a : vi)
	{
		sumOfVi += a;
	}

	cout << "Sum of \'vd\': " << sumOfVd << endl << "Difference between \'vd\' and \'vc\': " << abs(sumOfVd - sumOfVi) << endl << "--------------------------" << endl;

	reverse(vd.begin(), vd.end());

	printVector(vd);

	double meanOfVd = sumOfVd / vd.size();

	cout << "Mean value of \'vd\': " << meanOfVd << endl << "--------------------------" << endl;

	for (auto a : vd)
	{
		if (a > meanOfVd)
		{
			vd2.push_back(a);
		}
	}

	printVector(vd2);

	sort(vd);

	printVector(vd);

	return 0;
}