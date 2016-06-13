//
// Created by nikita on 08.06.16.
//
#pragma once
#include <functional>
#include <boost/signals2.hpp>

class Value
{
public:
    Value(std::function<double ()> const& val);
    double operator()();
    void Notify();
    void Update();
    void SetHandler(std::function<double ()> const& val);
    boost::signals2::signal<void()> m_signal;
private:
    std::function<double ()> m_func;
    double m_value;

};

