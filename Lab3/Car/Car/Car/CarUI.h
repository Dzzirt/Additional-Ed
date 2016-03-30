#pragma once
#include "Car.h"
#include <boost/noncopyable.hpp>
#include "CarExceptions.h"
class CCarUI : boost::noncopyable
{
public:
	CCarUI(CCar & car, std::istream & input, std::ostream & output);
	void Exec();
private:
	void TurnOnEngine(std::istream & args);
	void TurnOffEngine(std::istream & args);
	void SetSpeed(std::istream & args);
	void SetGear(std::istream & args);
	void GetInfo(std::istream & args);
	void PrintHelp(std::istream & args);
	bool HandleCommand();
private:
	typedef std::map<std::string, std::function<void(std::istream & args)>> ActionMap;

	CCar & m_car;
	std::istream & m_input;
	std::ostream & m_output;

	const ActionMap m_actionMap;
};

