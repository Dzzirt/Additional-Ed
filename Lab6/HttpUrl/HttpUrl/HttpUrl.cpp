#include "stdafx.h"
#include "HttpUrl.h"
#include "UrlParsingError.h"

enum ParsingState
{
	PROTOCOL_,
	SPECIAL_SYMBOLS_,
	DOMAIN_,
	PORT_,
	DOCUMENT_
};

CHttpUrl::CHttpUrl(std::string const& url)
{
	if (url.empty())
	{
		throw CUrlParsingError("Input URL is empty");
	}
	Initialize(ParseUrl(url));
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document,
	Protocol protocol , unsigned short port) : m_protocol(protocol), m_port(port), m_document(document)
{
	if (domain.find_first_of(" \t") != std::string::npos)
	{
		throw std::invalid_argument("Domain can't contain a whitespace characters");
	}
	if (domain.empty())
	{
		throw std::invalid_argument("Domain shouldn't be empty");
	}
	if (m_document[0] != '/' && !m_document.empty())
	{
		m_document.insert(0, std::string("/"));
	}
	m_domain = domain;
}

void CHttpUrl::Initialize(std::vector<std::string> const& urlParts)
{
	auto protocol = urlParts[PROTOCOL_];
	if (protocol == "http")
	{
		m_protocol = HTTP;
	}
	else
	{
		m_protocol = HTTPS;
	}
	m_domain = urlParts[DOMAIN_];
	auto port = urlParts[PORT_];
	if (port.empty())
	{
		m_protocol == HTTP ? m_port = 80 : m_port = 443;
	}
	else
	{
		m_port = stoi(port);
	}
	m_document = urlParts[DOCUMENT_];
}

std::string CHttpUrl::GetURL() const
{
	std::string portOutput = ":" + std::to_string(m_port);
	if ((m_protocol == HTTP && m_port == 80) || (m_protocol == HTTPS && m_port == 443))
	{
		portOutput.clear();
	}
	return ToString(m_protocol) + "://" + m_domain + portOutput + m_document;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}


std::vector<std::string> CHttpUrl::ParseUrl(std::string const& url)
{
	std::vector<std::string> urlParts = {"", "", "", "", ""};

	ParsingState state = PROTOCOL_;
	for (size_t i = 0; i < url.length(); i++)
	{
		if (state == PROTOCOL_)
		{
			if (url[i] == ':')
			{

				urlParts[SPECIAL_SYMBOLS_] += url[i];
				state = SPECIAL_SYMBOLS_;
			}
			else
			{
				urlParts[PROTOCOL_] += url[i];
			}
		}
		else if (state == SPECIAL_SYMBOLS_)
		{
			if (url[i] != '/')
			{
				state = DOMAIN_;
				urlParts[DOMAIN_] += url[i];
			}
			else
			{
				urlParts[SPECIAL_SYMBOLS_] += url[i];
			}
		}
		else if (state == DOMAIN_)
		{
			if (url[i] == ':')
			{
				state = PORT_;
			}
			else if (url[i] == '/')
			{
				state = DOCUMENT_;
				urlParts[DOCUMENT_] += '/';
			}
			else if (i == url.size() - 1)
			{
				state = DOCUMENT_;
				urlParts[DOMAIN_] += url[i];
			}
			else
			{
				urlParts[DOMAIN_] += url[i];
			}
		}
		else if (state == PORT_)
		{
			if (url[i] == '/')
			{
				state = DOCUMENT_;
				urlParts[DOCUMENT_] += '/';
			}
			else if (i == url.size() - 1)
			{
				state = DOCUMENT_;
				urlParts[PORT_] += url[i];
			}
			else
			{
				urlParts[PORT_] += url[i];
			}
		}
		else
		{
			urlParts[DOCUMENT_] += url[i];
		}
	}
	Validate(urlParts);
	return urlParts;
}

void CHttpUrl::Validate(std::vector<std::string> const& urlParts)
{
	std::string specSymb = urlParts[SPECIAL_SYMBOLS_];
	std::string protocol = urlParts[PROTOCOL_];
	std::string domain = urlParts[DOMAIN_];
	std::string port = urlParts[PORT_];
	std::string document = urlParts[DOCUMENT_];

	if (protocol != "http" && protocol != "https")
	{
		throw CUrlParsingError("Incorrect protocol");
	}
	if (specSymb != "://")
	{
		throw CUrlParsingError("Incorrect special symbols after protocol");
	}
	if (domain.find_first_of(" \t") != std::string::npos)
	{
		throw CUrlParsingError("Domain can't contain a whitespace characters");
	}
	if (domain.empty())
	{
		throw CUrlParsingError("Domain shouldn't be empty");
	}
	if (!port.empty())
	{
		if (port.find_first_not_of("0123456789") != std::string::npos)
		{
			throw CUrlParsingError("Port should be digit value");
		}
		if (stoi(port) > unsigned short(-1))
		{
			throw CUrlParsingError("Port must be the less than 65535");
		}
	}
}

std::string CHttpUrl::ToString(Protocol protocol)
{
	if (protocol == HTTP)
	{
		return "http";
	}
	else
	{
		return "https";
	}
}
