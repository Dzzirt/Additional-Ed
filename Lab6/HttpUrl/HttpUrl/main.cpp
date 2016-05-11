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
		std::cin >> url;
		auto parser = CHttpUrl(url);
		std::cout << CHttpUrl::ToString(parser.GetProtocol()) << std::endl;
		std::cout << parser.GetDomain() << std::endl;
		std::cout << parser.GetPort() << std::endl;
		std::cout << parser.GetDocument() << std::endl;
	}
    return 0;
}

