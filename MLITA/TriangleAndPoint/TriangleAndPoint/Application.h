#pragma once
#include "TriangleOwnerPointDefiner.h"

class CApplication
{
public:
	CApplication() = delete;
	CApplication(std::string const& input);
	void WriteResult(std::string const& output);
	~CApplication();
private:
	CTriangleOwnerPointDefiner ReadInput(std::string const& input);
	CTriangleOwnerPointDefiner m_definer;
};

