#include "Statistic.h"

CStatistic::CStatistic()
	:m_sum(0), m_count(1),
	m_max(-std::numeric_limits<double>::infinity()),
	m_min(std::numeric_limits<double>::infinity())
{

}

void CStatistic::Update(double value)
{
	m_sum += value;
	m_count++;

	if (value < m_min)
	{
		m_min = value;
	}
	if (value > m_max)
	{
		m_max = value;
	}
};
double CStatistic::GetMax()const
{
	return m_max;
};
double CStatistic::GetMin()const
{
	return m_min;
};
double CStatistic::GetAverage()const
{
	return m_sum / m_count;
};

void CStatistic::PrintStats(std::string const& physicalQuantity)const
{
	std::cout << "Max " << physicalQuantity.c_str() << ":" << GetMax() << std::endl;
	std::cout << "Min " << physicalQuantity.c_str() << ":" << GetMin() << std::endl;
	std::cout << "Average " << physicalQuantity.c_str() << ":" << GetAverage() << std::endl;
	std::cout << "----------------" << std::endl;
}