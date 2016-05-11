#pragma once

enum Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
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
	static std::vector<std::string> ParseUrl(std::string const& url);
	static void Validate(std::vector<std::string> const& urlParts);
	void Initialize(std::vector<std::string> const& urlParts);

	std::string m_domain;
	std::string m_document;
	unsigned short m_port;
	Protocol m_protocol;
};

