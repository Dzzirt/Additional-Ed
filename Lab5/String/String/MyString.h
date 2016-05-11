#pragma once
#include <string.h>
#include "StringIterator.h"


class CMyString
{
public:
	typedef CStringIterator<char> iterator;
	typedef CStringIterator<const char> constIterator;

	CMyString();
	CMyString(const char * pString);
	CMyString(const char * pString, size_t length);
	CMyString(CMyString const& other);
	CMyString(CMyString && other);
	CMyString(std::string const& stlString);
	size_t GetLength()const;
	const char* GetStringData()const;
	CMyString SubString(size_t start, size_t length = SIZE_MAX)const;//
	void Clear();

	iterator begin();
	iterator end();
	constIterator begin() const;
	constIterator end() const;

	iterator rbegin();
	iterator rend();
	constIterator rbegin() const;
	constIterator rend() const;

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

	friend CMyString operator+(CMyString const & lhs, CMyString const & rhs);
	friend CMyString operator+(std::string const & lhs, CMyString const & rhs);
	friend CMyString operator+(const char * lhs, CMyString const & rhs);
	~CMyString();
private:
	static int Compare(CMyString const&  lhs, CMyString const&  rhs);
	static void SafeDelete(char * pString);
	static char * CreateString(size_t length);
	CMyString(size_t len);
	static char m_emptyStr[];
	char * m_first;
	size_t m_length;

};

std::istream & operator>> (std::istream & strm, CMyString & str);
std::ostream & operator<< (std::ostream & strm, CMyString const& str);



