#pragma once
#include <boost/filesystem.hpp>

class CTempDir
{
public:
	CTempDir();
	~CTempDir();
	std::string MakeCopyOfFile(std::string const& filename);
	std::string GetPath();
private:
	boost::filesystem::path m_path;
};

