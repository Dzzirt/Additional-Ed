#pragma once

#include "IBeverage.h"

// Базовая реализация напитка, предоставляющая его описание
class CBeverage : public IBeverage
{
public:
	CBeverage(const std::string & description)
		:m_description(description)
	{}

	std::string GetDescription()const override final
	{
		return m_description;
	}
private:
	std::string m_description;
};

// Кофе
class CCoffee : public CBeverage
{
public:
	CCoffee(const std::string& description = "Coffee")
		:CBeverage(description) 
	{}

	double GetCost() const override 
	{
		return 60; 
	}
};

enum class PortionType
{
	Standart,
	Double
};

// Капуччино
class CCapuccino : public CCoffee
{
public:
	CCapuccino(PortionType type = PortionType::Standart) 
		:CCoffee(m_type == PortionType::Standart ? "Capuccino" : "Double Capuccino")
		, m_type(type)
	{}

	double GetCost() const override 
	{
		return m_type == PortionType::Standart ? 80 : 120;
	}
private:
	PortionType m_type;
};

// Латте
class CLatte : public CCoffee
{
public:
	CLatte(PortionType type = PortionType::Standart)
		:m_type(type), CCoffee(m_type == PortionType::Standart ? "Latte" : "Double Latte")
	{
	}

	double GetCost() const override 
	{
		return m_type == PortionType::Standart ? 90 : 130; 
	}
private:
	PortionType m_type;
};

enum class TeaType
{
	Red,
	Green,
	Black,
	Ceylonese
};

// Чай
class CTea : public IBeverage
{
public:
	CTea(TeaType type = TeaType::Black) : m_type(type) {}

	double GetCost() const override 
	{
		return 30; 
	}

	std::string GetDescription()const override final
	{
		switch (m_type)
		{
		case TeaType::Red:
			return "Red Tea";
			break;
		case TeaType::Green:
			return "Green Tea";
			break;
		case TeaType::Black:
			return "Black Tea";
			break;
		case TeaType::Ceylonese:
			return "Ceylonese Tea";
			break;
		}
		return "Unknown Tea";
	}

private:
	TeaType m_type;
};

enum class PortionSize
{
	Small,
	Average,
	Lagre
};
// Молочный коктейль
class CMilkshake : public IBeverage
{
public:
	CMilkshake(PortionSize size = PortionSize::Small) 
		:m_size(size)
	{}

	double GetCost() const override 
	{ 
		switch (m_size)
		{
		case PortionSize::Small:
			return 50;
			break;
		case PortionSize::Average:
			return 60;
			break;
		case PortionSize::Lagre:
			return 80;
			break;
		default:
			return 0;
			break;
		}
	}

	std::string GetDescription()const override final
	{
		switch (m_size)
		{
		case PortionSize::Small:
			return "Small Milkshake";
			break;
		case PortionSize::Average:
			return "Average Milkshake";
			break;
		case PortionSize::Lagre:
			return "Large Milkshake";
			break;
		default:
			return "Unknown MilkShake";
			break;
		}
	}
private:
	PortionSize m_size;
};
