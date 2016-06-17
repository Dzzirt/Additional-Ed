//
// Created by nikita on 07.06.16.
//
#include <boost/function.hpp>
#include <map>
#include "Calculator.h"

class CalculatorUI
{
public:
    CalculatorUI(Calculator & calc, std::istream & in, std::ostream & out);
    void Exec();
private:
    Calculator &m_calc;
    std::istream &m_in;
    std::ostream &m_out;
    std::map<std::string, std::function<void(std::string)>> m_actionList;
    void AddVariable(std::string const& cmd);
    void AddVariableOnFly(std::string const& cmd);
    void AddFunction(std::string const& cmd);
    bool HandleCommand();
    void Print(std::string const& cmd);
    void PrintFunctions(std::string const& cmd);
    void PrintVariables(std::string const& cmd);
};

