#include "stdafx.h"
#include "MyString.h"


CMyString::CMyString()
{
	m_first = CreateString(0);
	m_length = 0;
}

CMyString::CMyString(std::string const& stlString)
{
	auto len = stlString.size();
	m_first = CreateString(len);
	m_length = len;
	memcpy(m_first, stlString.c_str(), m_length);
}

CMyString::CMyString(const char * pString)
{
	if (pString == nullptr)
	{
		throw std::invalid_argument("Can't create string from nullptr");
	}
	auto len = strlen(pString);
	m_first = CreateString(len);
	m_length = len;
	memcpy(m_first, pString, m_length);
}

CMyString::CMyString(const char * pString, size_t length)
{
	if (pString == nullptr)
	{
		throw std::invalid_argument("Can't create string from nullptr");
	}
	m_first = CreateString(length);
	m_length = length;
	memcpy(m_first, pString, m_length);
}

CMyString::CMyString(CMyString const& other)
{
	auto len = other.GetLength();
	m_first = CreateString(len);
	m_length = len;
	memcpy(m_first, other.GetStringData(), m_length);
}

CMyString::CMyString(CMyString && other)
	: m_first(other.m_first)
	, m_length(other.m_length)
{
	other.m_first = CreateString(0);
	other.m_length = 0;
}


char * CMyString::CreateString(size_t length)
{
	char * tmp = new char[length + 1];
	tmp[length] = '\0';
	return tmp;
}

size_t CMyString::GetLength() const
{
	return m_length;
}

const char* CMyString::GetStringData() const
{
	return m_first;
}

CMyString const CMyString::SubString(size_t start, size_t length /*= SIZE_MAX*/) const
{
	if (start > m_length)
	{
		throw std::out_of_range("Start pos should be less than string length");
	}
	if (start == m_length)
	{
		return CMyString();
	}
	else if (m_length < start + length)
	{
		length = m_length - start;
	}
	return CMyString(m_first + start, length);
}

void CMyString::Clear()
{
	auto tmpPtr = CreateString(0);
	delete[] m_first;
	m_first = tmpPtr;
	m_length = 0;
}

CMyString & CMyString::operator+=(CMyString const & other)
{
	if (other.GetLength() != 0)
	{
		auto newData = CreateString(m_length + other.GetLength());
		memcpy(newData, m_first, m_length);
		memcpy(newData + m_length, other.GetStringData(), other.GetLength());
		delete[] m_first;
		m_first = newData;
		m_length += other.GetLength();
	}
	return *this;
}

bool CMyString::operator!=(CMyString const & other) const
{
	return !(*this == other);
}

bool CMyString::operator==(CMyString const & other) const
{
	if (other.GetLength() != m_length)
	{
		return false;
	}
	return memcmp(m_first, other.GetStringData(), m_length) == 0;
}

CMyString & CMyString::operator=(CMyString && other)
{
	if (this != &other)
	{
		std::swap(m_first, other.m_first);
		std::swap(m_length, other.m_length);
		delete[] other.m_first;
		other.m_first = CreateString(0);
		other.m_length = 0;
	}
	return *this;
}

CMyString & CMyString::operator=(CMyString const & other)
{
	if (this != &other)
	{
		auto otherLen = other.GetLength();
		auto tempPtr = CreateString(otherLen);
		delete[] m_first;
		m_first = tempPtr;
		m_length = otherLen;
		memcpy(m_first, other.GetStringData(), otherLen);
	}
	return *this;
}


bool CMyString::operator<(CMyString const & other) const
{
	if (m_length < other.GetLength())
	{
		return true;
	}
	else if (m_length > other.GetLength())
	{
		return false;
	}
	auto res = memcmp(m_first, other.GetStringData(), m_length);
	if(res == 1 || res == 0)
	{
		return false;
	}
	return true;
}

bool CMyString::operator>(CMyString const & other) const
{
	if (memcmp(m_first, other.GetStringData(), m_length) == 0)
	{
		return false;
	}
	return !(*this < other);
}

bool CMyString::operator>=(CMyString const & other) const
{
	return !(*this < other);
}

bool CMyString::operator<=(CMyString const & other) const
{
	return !(*this > other);
}

char & CMyString::operator[](size_t pos)
{
	return m_first[pos];
}

char const& CMyString::operator[](size_t pos) const
{
	return m_first[pos];
}

CMyString::~CMyString()
{
	delete[] m_first;
}


std::istream & operator >> (std::istream & strm, CMyString & str)
{
	std::string tmp;
	strm >> tmp;
	str += tmp;
	return strm;
}

std::ostream & operator<<(std::ostream & strm, CMyString const& str)
{
	strm << str.GetStringData();
	return strm;
}

CMyString const operator+(CMyString const & lhs, CMyString const & rhs)
{
	auto res = lhs;
	return res += rhs;
}
