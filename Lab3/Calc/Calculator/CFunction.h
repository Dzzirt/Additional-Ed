//
// Created by nikita on 13.06.16.
//

#include <functional>
class CFunction
{
public:
    CFunction(std::function<double ()> const& val);
    void Update();
    double operator()();
private:
    double m_value;
    std::function<double ()> m_func;
};

