//
// Created by nikita on 11.06.16.
//

#include "Value.h"

double Value::operator()()
{
    return m_value;
}

Value::Value(std::function<double()> const &val)
    :m_func(val), m_value(val())
{
}
void Value::Notify()
{
    m_signal();
}
void Value::Update()
{
    m_value = m_func();
    Notify();
}
void Value::SetHandler(std::function<double ()> const& val)
{
    m_func = val;
    Update();
}












