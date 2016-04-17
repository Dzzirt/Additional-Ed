#pragma once
#include <limits>
#include <iostream>

class CStatistic
{
public:
	CStatistic();
	void Update(double value);
	double GetMax()const;
	double GetMin()const;
	double GetAverage()const;
	void PrintStats(std::string const& physicalQuantity)const;
private:
	double m_sum;
	double m_count;
	double m_max;
	double m_min;

};

