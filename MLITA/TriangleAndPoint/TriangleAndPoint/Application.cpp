#include "stdafx.h"
#include "Application.h"

using namespace std;

CApplication::CApplication(std::string const& input)
	:m_definer(ReadInput(input))
{
	
}

CTriangleOwnerPointDefiner CApplication::ReadInput(std::string const& input)
{
	ifstream in(input);
	double x;
	double y;
	in >> x >> y;
	Point freePoint = { x, y };
	Triangle triangle;
	for (size_t i = 0; i < 3; i++)
	{
		in >> x >> y;
		triangle[i] = { x, y };
	}
	return { triangle, freePoint };
}

void CApplication::WriteResult(std::string const& output)
{
	ofstream out(output);
	m_definer.IsTriangleBelongsToPoint() ? out << "In" << endl : out << "Out" << endl;
	out.close();
}

CApplication::~CApplication()
{
}