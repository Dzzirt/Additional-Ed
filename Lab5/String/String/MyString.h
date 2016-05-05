#pragma once
#include <string.h>

class CMyString
{
public:
	CMyString();
	CMyString(const char * pString);
	CMyString(const char * pString, size_t length);
	CMyString(CMyString const& other);
	CMyString(CMyString && other);
	CMyString(std::string const& stlString);
	size_t GetLength()const;
	const char* GetStringData()const;
	CMyString const SubString(size_t start, size_t length = SIZE_MAX)const;
	void Clear();

	CMyString & operator=(CMyString const & other);
	CMyString & operator=(CMyString && other);
	bool operator==(CMyString const & other)const;
	bool operator!=(CMyString const & other)const;
	bool operator<(CMyString const & other)const;
	bool operator>(CMyString const & other)const;
	bool operator<=(CMyString const & other)const;
	bool operator>=(CMyString const & other)const;
	char & operator[](size_t pos);
	char const& operator[](size_t pos) const;

	CMyString & operator+=(CMyString const & other);

	~CMyString();
private:
	char * CreateString(size_t length);

	char * m_first;
	size_t m_length;
};

std::istream & operator>> (std::istream & strm, CMyString & str);
std::ostream & operator<< (std::ostream & strm, CMyString const& str);

CMyString const operator+(CMyString const & lhs, CMyString const & rhs);
/*
CMyString const& operator+(std::string const & lhs, CMyString const & rhs);
CMyString operator+(const char * lhs, CMyString const & rhs);*/

