//
// Created by nikita on 13.06.16.
//

#include "CFunction.h"

CFunction::CFunction(std::function<double()> const &val)
    :m_value(val()), m_func(val)
{

}
void CFunction::Update()
{
    m_value = m_func();
}
double CFunction::operator()()
{
    return m_value;
}





