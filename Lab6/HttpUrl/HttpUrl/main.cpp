// HttpUrl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UrlParsingError.h"
#include "HttpUrl.h"

int main()
{
	while (!std::cin.fail() && !std::cin.eof())
	{
		std::string url;
		std::getline(std::cin, url);
		try
		{
			auto parser = CHttpUrl(url);
			std::cout << CHttpUrl::ToString(parser.GetProtocol()) << std::endl;
			std::cout << parser.GetDomain() << std::endl;
			std::cout << parser.GetPort() << std::endl;
			std::cout << parser.GetDocument() << std::endl;
		}
		catch (std::exception const& e)
		{
			std::cout << e.what() << std::endl;
			return -1;
		}
	}
    return 0;
}

