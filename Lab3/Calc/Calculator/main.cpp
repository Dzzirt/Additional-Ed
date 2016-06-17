#include <iostream>
#include <numeric>
#include <cmath>
#include <limits>
#include <regex>
#include <map>
#include "CalculatorUI.h"
using namespace std;

int main()
{
    Calculator calculator;
    CalculatorUI ui(calculator, cin, cout);
    ui.Exec();
    return 0;
}