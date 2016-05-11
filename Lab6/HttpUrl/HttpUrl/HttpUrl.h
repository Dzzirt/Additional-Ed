#pragma once

enum Protocol
{
	HTTP,
	HTTPS
};

typedef std::vector<std::string> UrlParts;

class CHttpUrl
{
public:
	static const unsigned short DefaultHttpPort = 80;
	static const unsigned short DefaultHttpsPort = 443;

	CHttpUrl() = delete;
	CHttpUrl(std::string const& url);
	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol = HTTP,
		unsigned short port = 80);
	std::string GetURL()const;
	std::string GetDomain()const;
	std::string GetDocument()const;
	Protocol GetProtocol()const;
	unsigned short GetPort()const;
	static std::string ToString(Protocol protocol);
private:
	static UrlParts ParseUrl(std::string const& url);
	static void Validate(UrlParts const& urlParts);
	void Initialize(UrlParts const& urlParts);

	std::string m_domain;
	std::string m_document;
	unsigned short m_port;
	Protocol m_protocol;
};

