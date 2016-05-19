#include <iostream>
#include <list>
#include "StringList.h"
#include "StringListIterator.h"
using namespace std;

int main()
{
    std::list<int> listInt = {};
    auto end3 = listInt.end();
    listInt.insert(listInt.begin(), 233);
    auto end4 = listInt.end();
    int i = *--end4;
    int k = *--end3;
    CStringList list;
    auto end = list.end();
    list.Append("3");
    auto end2 = list.end();
    cout << (addressof(end) == addressof(end2)) << endl;

    cout << (addressof(end3) == addressof(end4)) << endl;
    listInt.insert(listInt.begin(), 1);
    listInt.end();
    cout << "Hello, World!" << endl;

    return 0;
}