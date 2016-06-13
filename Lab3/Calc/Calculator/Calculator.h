//
// Created by nikita on 07.06.16.
//

#include <boost/variant.hpp>
#include <regex>
#include <map>
#include "Value.h"

enum class Operation
{
    Division,
    Multiplication,
    Addition,
    Subtraction
};

class Calculator
{
public:
    void AssignVariableValue(std::string const& id, std::string const& value);
    void AddVariable(std::string const& name);
    void AddFunction(std::string const &id, std::string const &values);
    std::map<std::string, Value*> GetFunctions();
    std::map<std::string, Value*> GetVariables();
    double GetDoubleValue(std::string const &name);
private:
    std::map<std::string, std::unique_ptr<Value>> m_allValues;
    std::map<std::string, Value*> m_vars;
    std::map<std::string, Value*> m_functions;
    const std::regex IdRegex = std::regex("[a-zA-Z_][a-zA-Z0-9_]*");
    bool IsValid(const std::string &id) const;
    bool IsAlreadyDeclared(const std::string &id);
    std::vector<std::string> ParseValue(std::string const& value) const;
    std::function<double()> GetValue(const std::string &value) const;
    bool IsFunction(const std::string &basic_string);
};