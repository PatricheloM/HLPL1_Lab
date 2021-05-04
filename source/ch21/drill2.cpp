#include "../std_lib_facilities.h"

map<string, int> msi;
map<int, string> mis;

void insertTest()
{
    msi.insert({"lecture0", 21});
    msi.insert({"lecture1", 65});
    msi.insert({"lecture2", 34});
    msi.insert({"lecture3", 17});
    msi.insert({"lecture4", 36});
    msi.insert({"lecture5", 59});
    msi.insert({"lecture6", 11});
    msi.insert({"lecture7", 0});
    msi.insert({"lecture8", 7});
    msi.insert({"lecture9", 92});
}

template<typename data>
void printMap(data MAP)
{
    for (auto a : MAP)
    {
        cout << "Key: " << a.first << " - Mapped value: " << a.second << endl;
    }
    
    cout << "---------------------------------" << endl;
}

template<typename data2>
void fullEraseMap(data2 &MAP)
{
    MAP.erase(MAP.begin(), MAP.end());
}

void cinValuesToMap(map<string, int> &MAP)
{
    string tmpS;
    int tmpI;
    
    while(cin >> tmpS >> tmpI)
    {
        MAP.insert({tmpS, tmpI});
    }
    
    cout << "---------------------------------" << endl;
}

void copyMap(map<string, int> &MAP1, map<int, string> &MAP2)
{
    string tmpS;
    int tmpI;
    
    for (auto a : MAP1)
    {
        string tmpS = a.first;
        int tmpI = a.second;
        MAP2.insert({tmpI, tmpS});
    }
}

int main()
{
    insertTest();
    printMap(msi);
    fullEraseMap(msi);
    cinValuesToMap(msi);
    printMap(msi);
    
    int iCount = 0;
    for (auto a : msi)
    {
        iCount += a.second;
    }
    cout << "Sum of integers in \'msi\': " << iCount << endl << "---------------------------------" << endl;
    
    copyMap(msi, mis);
    printMap(mis);
	
	return 0;
}