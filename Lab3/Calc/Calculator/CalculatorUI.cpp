//
// Created by nikita on 07.06.16.
//

#include <iostream>
#include "CalculatorUI.h"
#include <boost/algorithm/string.hpp>
#include <vector>
#include <iomanip>
using namespace std;
using namespace placeholders;

CalculatorUI::CalculatorUI(Calculator &calc, std::istream &in, std::ostream &out)
    : m_calc(calc), m_in(in), m_out(out), m_actionList(
    {
        {"var", bind(&CalculatorUI::AddVariable, this, std::placeholders::_1)},
        {"let", bind(&CalculatorUI::AddVariableOnFly, this, std::placeholders::_1)},
        {"fn", bind(&CalculatorUI::AddFunction, this, std::placeholders::_1)},
        {"print", bind(&CalculatorUI::Print, this, std::placeholders::_1)},
        {"printvars", bind(&CalculatorUI::PrintVariables, this, std::placeholders::_1)},
        {"printfnc", bind(&CalculatorUI::PrintFunctions, this, std::placeholders::_1)}
    }
)
{

}

void CalculatorUI::Exec()
{
    while (!cin.eof() && !cin.fail())
    {
        if (!HandleCommand())
        {
            cout << "Unknown command!" << endl;
        }
    }
}

bool CalculatorUI::HandleCommand()
{
    string line;
    getline(m_in, line);
    vector<string> splitted;
    boost::split(splitted, line, ::isspace);
    auto it = m_actionList.find(splitted[0]);
    if (it != m_actionList.end())
    {
        std::string s;
        s = accumulate(begin(splitted) + 1, end(splitted), s);
        it->second(s);
        return true;
    }
    return false;
}

void CalculatorUI::AddVariable(std::string const& cmd)
{
    m_calc.AddVariable(cmd);
}

void CalculatorUI::AddVariableOnFly(std::string const& cmd)
{
    std::vector<string> byEqualSign;
    boost::split(byEqualSign, cmd, boost::is_any_of("="));
    m_calc.AssignVariableValue(byEqualSign[0], byEqualSign[1]);
}

void CalculatorUI::AddFunction(std::string const& cmd)
{
    std::vector<string> byEqualSign;
    boost::split(byEqualSign, cmd, boost::is_any_of("="));
    m_calc.AddFunction(byEqualSign[0], byEqualSign[1]);
}

void CalculatorUI::Print(std::string const& cmd)
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << std::setprecision(2) << m_calc.GetDoubleValue(cmd) << endl;
}

void CalculatorUI::PrintFunctions(std::string const& cmd)
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    for (auto const& func : m_calc.GetFunctions())
    {
        cout << func.first << ":" << std::setprecision(2) << (*func.second)() << endl;
    }

}

void CalculatorUI::PrintVariables(std::string const& cmd)
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    for (auto const& func : m_calc.GetVariables())
    {
        cout << func.first << ":" << std::setprecision(2) << (*func.second)() << endl;
    }
}





