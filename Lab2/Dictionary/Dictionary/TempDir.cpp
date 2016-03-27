#include "stdafx.h"
#include "TempDir.h"
#include <iostream>
#include "boost/algorithm/string.hpp"
#include <vector>

using namespace boost::filesystem;
using namespace std;

CTempDir::CTempDir()
{
	m_path = unique_path();
	create_directories(m_path);
}


CTempDir::~CTempDir()
{
	remove_all(m_path);
}

std::string CTempDir::MakeCopyOfFile(std::string const& filename)
{
	path file(filename);
	vector<string> splittedPath;
	boost::split(splittedPath, filename, bind2nd(equal_to<char>(), '/'));
	std::string name = splittedPath[splittedPath.size() - 1];
	path to(m_path.string() + "/" + name);
	copy_file(file, to);
	return to.string();
}

std::string CTempDir::GetPath()
{
	return m_path.string();
}
