#include <iostream>
#include <list>
#include "StringList.h"
#include "StringListIterator.h"
using namespace std;

int main()
{
    std::list<string> strings;
    strings.insert(strings.end(), "123");
    strings.insert(strings.end(), "1234");

    const std::list<string> strings2 = strings;
    strings2.begin()._M_node = nullptr;

    cout << std::equal(strings2.begin(), strings2.end(), strings.begin());
    return 0;
}