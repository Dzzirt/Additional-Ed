#pragma once
#include "boost/signals2/connection.hpp"
class IButtonClickObserver
{
public:
	virtual void UpdateOnButtonClick(const std::string & buttonName) = 0;

	virtual boost::signals2::connection& GetButtonClickConnection() = 0;
};
