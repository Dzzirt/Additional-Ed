//
// Created by nikita on 07.06.16.
//
#include "stdafx.h"
#include "Calculator.h"
#include <iomanip>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

using namespace std;


void Calculator::AddVariable(string const &id)
{
    if (!IsValid(id))
    {
        throw invalid_argument("Incorrect identifier format");
    }
    if (IsAlreadyDeclared(id))
    {
        throw invalid_argument("Identifier is already declared");
    }
    unique_ptr<Value> val = make_unique<Value>([=]{ return numeric_limits<double>::quiet_NaN(); });
    m_vars.emplace(id, val.get());
    m_allValues.emplace(id, move(val));
}


void Calculator::AddFunction(std::string const &id, std::string const &value)
{
    if (!IsValid(id))
    {
        throw std::invalid_argument("Incorrect identifier format");
    }
    if (IsAlreadyDeclared(id))
    {
        throw std::invalid_argument("Identifier is already declared");
    }
    auto values = ParseValue(value);
    if (values.size() > 1 && IsAlreadyDeclared(values[0]) && IsAlreadyDeclared(values[1]))
    {
        function<double()> endValue = GetValue(value);
        auto func = make_unique<Value>(endValue);
        m_allValues.at(values[0])->m_signal.connect(boost::bind(&Value::Update, &*func));
        m_allValues.at(values[1])->m_signal.connect(boost::bind(&Value::Update, &*func));
        m_functions.emplace(id, func.get());
        m_allValues.emplace(id, move(func));
    }
    else if (values.size() == 1 && IsAlreadyDeclared(values[0]))
    {
        auto func = make_unique<Value>([=]{ return (*m_allValues.at(values[0]))();});
        m_allValues.at(values[0])->m_signal.connect(boost::bind(&Value::Update, &*func));
        m_functions.emplace(id, func.get());
        m_allValues.emplace(id, move(func));
    }
    else
    {
        throw std::invalid_argument("Cannot assign value to non declared identifier");
    }


}
function<double()> Calculator::GetValue(const std::string &value) const
{

    auto splitted = ParseValue(value);
    function<double ()> f;
    if (value.find("/") != string::npos)
    {
        f = [=]{
            return (*m_allValues.at(splitted[0]))() / (*m_allValues.at(splitted[1]))();
        };
    }
    else if (value.find("*") != string::npos)
    {
        f = [=]{
            return (*m_allValues.at(splitted[0]))() * (*m_allValues.at(splitted[1]))();
        };
    }
    else if (value.find("+") != string::npos)
    {
        f = [=]{
            return (*m_allValues.at(splitted[0]))() + (*m_allValues.at(splitted[1]))();
        };
    }
    else if (value.find("-") != string::npos)
    {
        f = [=]{
            return (*m_allValues.at(splitted[0]))() - (*m_allValues.at(splitted[1]))();
        };
    }
    return f;
}

double Calculator::GetDoubleValue(std::string const &id)
{
    double d = (*m_allValues.at(id))();
    return d;
}
bool Calculator::IsValid(const std::string &id) const
{
    return std::regex_match(id, IdRegex);
}

bool Calculator::IsAlreadyDeclared(std::string const& id)
{
    return m_allValues.find(id) != m_allValues.end();
}

std::vector<std::string> Calculator::ParseValue(std::string const& value) const
{
    auto str = value;
    vector<string> splitted;
    boost::split(splitted, str, boost::is_any_of("+-/*"));
    return splitted;
}
void Calculator::AssignVariableValue(std::string const &id, std::string const &value)
{
    if (!IsValid(id))
    {
        throw std::invalid_argument("Incorrect identifier format");
    }
    if (IsFunction(id))
    {
        throw invalid_argument("Cannot reassign function");
    }
    if (!IsAlreadyDeclared(id))
    {
        AddVariable(id);
    }
    stringstream ss(value);
    double dVal;
    if (value.empty())
    {
        auto handler = [=]{ return numeric_limits<double>::quiet_NaN(); };
        m_vars.at(id)->SetHandler(handler);
        m_allValues.at(id)->SetHandler(handler);
    }
    else if (ss >> dVal)
    {
        auto handler =  [=]{
            return dVal;
        };
        m_vars.at(id)->SetHandler(handler);
        m_allValues.at(id)->SetHandler(handler);

    }
    else if (IsAlreadyDeclared(value))
    {
        auto constVal = (*m_allValues.at(value))();
        auto handler = [=]{
            return constVal;
        };
        m_vars.at(id)->SetHandler(handler);
        m_allValues.at(id)->SetHandler(handler);

    }
    else
    {
        throw std::invalid_argument("Cannot assign non declared identifier to variable");
    }
}

bool Calculator::IsFunction(const std::string & id)
{
    return m_functions.find(id) != m_functions.end();
}
std::map<std::string, Value*> Calculator::GetVariables()
{
    return m_vars;
}
std::map<std::string, Value*> Calculator::GetFunctions()
{
    return m_functions;
}